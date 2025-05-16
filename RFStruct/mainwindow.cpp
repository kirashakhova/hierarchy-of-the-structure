#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
double haversineDistance(double lat1, double lon1, double lat2, double lon2);

struct coords
{
    double lat1;
    double lat2;
    double lon1;
    double lon2;
    bool set1=false;
    bool set2=false;
    QString name1="";
    QString name2="";
};
bool typeDel=false;
coords cor;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Создание и подключение модели
    QStringList headers = {"Российская Федерация"};
    mainModel = new LegoTreeModel(headers);
    ui->treeView->setModel(mainModel);
    ui->stackedWidget->setCurrentIndex(0);
    ui->upButton->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//При выборе элемента надо поменять все надписи и вывести его дополнительные данные
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString type="";
     ui->label_photo->clear();
    QList<QVariant> itemData=mainModel->data(index,Qt::UserRole).toList();
    if(itemData[4].toString()=="STATE")
    {
        type+="Область: ";
    }
    else if(itemData[4].toString()=="SITY")
    {
        type+="Город: ";
    }
    else if(itemData[4].toString()=="VILLAGE")
    {
       type+="Поселок: ";
    }
    type = type+itemData[0].toString()+"\nОписание: "+itemData[1].toString()+"\nКоординаты: "+itemData[2].toString()+"° с.ш.; "+
            itemData[3].toString()+"° в.д.";
    ui->label->setText(type);
    if(itemData.size() > 5)
        ui->label_photo->setPixmap(itemData[5].value<QPixmap>());

}

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Функция для вычисления расстояния между двумя точками
double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double EARTH_RADIUS_KM = 6371.0;

    // Перевод координат в радианы
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    // Разница между координатами
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    // Формула хаверсинуса
    double a = std::pow(std::sin(dLat / 2), 2) +
               std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dLon / 2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    // Расстояние
    return EARTH_RADIUS_KM * c;
}

//Добавление элемента
void MainWindow::on_addButton_clicked()
{
    if(ui->treeView->selectionModel()->selectedIndexes().count()>0)
    {
        //auto просто для скорости - это индекс выбранного элемента
        auto index= ui->treeView->selectionModel()->currentIndex();
        //Получение всех данных
        QList<QVariant> itemData=mainModel->data(index,Qt::UserRole).toList();

        if(itemData[4].toString()=="STATE")
        {
            //Добавляется пустая строка и получается её индекс
            //Строка добавляется в начало списка детей
            mainModel->insertRow(0,index);
            index=mainModel->index(0,0,index);

            Sity newItem;
            newItem.name = ui->name->text();
            newItem.description = ui->description->text();
            newItem.latitude = ui->latitude->text().toDouble();
            newItem.longitude = ui->longtitude->text().toDouble();
            //Данные заносятся в модель
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
            mainModel->setData(index,itemData);
        }
        else
            if(itemData[4].toString()=="SITY")
            {
                mainModel->insertRow(0,index);
                index=mainModel->index(0,0,index);
                Village newItem;
                newItem.name = ui->name->text();
                newItem.description = ui->description->text();
                newItem.latitude = ui->latitude->text().toDouble();
                newItem.longitude = ui->longtitude->text().toDouble();
                //Данные заносятся в модель
                itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
                mainModel->setData(index,itemData);
            }
    }
    else
    {
        //Если ничего не выбрано - добавляется State
        State newItem;
        newItem.name = ui->name->text();
        newItem.description = ui->description->text();
        newItem.latitude = ui->latitude->text().toDouble();
        newItem.longitude = ui->longtitude->text().toDouble();
        QList<QVariant> itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
        mainModel->insertRow(mainModel->rowCount());
        mainModel->setData(mainModel->index(mainModel->rowCount()-1,0),itemData);
    }
    //Сбрасывается выделение и устанавливаются нужные надписи для красоты
    ui->treeView->clearSelection();
    ui->label->setText(" ");
    ui->name->setText("");
    ui->description->setText("");
    ui->latitude->setText("");
    ui->longtitude->setText("");
}

void MainWindow::on_delete_2_clicked()
{
    if(ui->treeView->selectionModel()->selectedIndexes().count()>0)
    {
        auto index= ui->treeView->selectionModel()->currentIndex();
        mainModel->removeRow(index.row(),index.parent());
    }
    //Не забыть сбросить выбор!
    ui->treeView->clearSelection();

    ui->label->setText("");
    ui->name->setText("");
    ui->description->setText("");
    ui->latitude->setText("");
    ui->longtitude->setText("");
}

void MainWindow::on_upButton_clicked()
{
    if (ui->treeView->selectionModel()->selectedIndexes().count() > 0) {
        auto index = ui->treeView->selectionModel()->currentIndex();
        QList<QVariant> itemData = mainModel->data(index, Qt::UserRole).toList();

        if (itemData[4].toString() == "VILLAGE") {
            qDebug()<<itemData[4].toString();
            // Получаем родителя (область)
            QModelIndex parentIndex = index.parent();
            if (parentIndex.isValid()) {
                // Добавляем новый город к области
                mainModel->insertRow(0, parentIndex);
                QModelIndex newCityIndex = mainModel->index(0, 0, parentIndex);

                // Создаем новый город с данными деревни
                Sity newItem;
                newItem.name = itemData[0].toString();
                newItem.description = itemData[1].toString();
                newItem.latitude = itemData[2].toDouble();
                newItem.longitude = itemData[3].toDouble();

                // Заносим данные в модель
                QList<QVariant> newItemData = {newItem.name, newItem.description, newItem.latitude, newItem.longitude, newItem.type};
                mainModel->setData(newCityIndex, newItemData);

                // Удаляем деревню
                mainModel->removeRow(index.row(), parentIndex);
            }
        } else if (itemData[4].toString() == "SITY") {
            qDebug()<<itemData[4].toString();
            QModelIndex parentIndex = index.parent();
            if (parentIndex.isValid()) {
                // Добавляем новую область на уровень текущего родителя города
                QModelIndex grandParentIndex = parentIndex.parent();
                mainModel->insertRow(0, grandParentIndex);
                QModelIndex newRegionIndex = mainModel->index(0, 0, grandParentIndex);

                // Создаем новую область с данными города
                State newItem;
                newItem.name = itemData[0].toString();
                newItem.description = itemData[1].toString();
                newItem.latitude = itemData[2].toDouble();
                newItem.longitude = itemData[3].toDouble();

                // Заносим данные в модель
                QList<QVariant> newItemData = {newItem.name, newItem.description, newItem.latitude, newItem.longitude, newItem.type};
                mainModel->setData(newRegionIndex, newItemData);

                // Удаляем город
                mainModel->removeRow(index.row(), parentIndex);
            }
        } else {
            // Если выбран элемент - область, ничего не делаем
            //qDebug() << "Выбрана область. Никаких действий не требуется.";
        }
    }
    ui->treeView->clearSelection();

}

void MainWindow::on_Model_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Tree_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addToList_clicked()
{
    if(ui->treeView->selectionModel()->selectedIndexes().count()>0)
    {
        auto index= ui->treeView->selectionModel()->currentIndex();
        QList<QVariant> itemData=mainModel->data(index,Qt::UserRole).toList();
        if(!cor.set1){
            cor.lat1=itemData[2].toDouble();
            cor.lon1=itemData[3].toDouble();
            cor.set1=true;
            cor.name1 = itemData[0].toString()+" и ";
        }
        else{
            cor.lat2=itemData[2].toDouble();
            cor.lon2=itemData[3].toDouble();
            cor.name2 = itemData[0].toString();
            cor.set2=true;
        }
     ui->info->setText(cor.name1+cor.name2);

    }
    //Не забыть сбросить выбор!
    ui->treeView->clearSelection();

}

void MainWindow::on_clear_clicked()
{
    cor.set1=false;
    cor.set2=false;
    ui->info->setText("");
}

void MainWindow::on_findDistanse_clicked()
{
    if(cor.set2&&cor.set1){
        double dis = haversineDistance(cor.lat1, cor.lon1, cor.lat2, cor.lon1);
        ui->info->setText(ui->info->text()+"\nРасстояние между объектами: "+QString::number(dis)+"км");
    }
}

void MainWindow::on_edit_clicked()
{
    if(ui->treeView->selectionModel()->selectedIndexes().count()>0)
    {

        //auto просто для скорости - это индекс выбранного элемента
        auto index= ui->treeView->selectionModel()->currentIndex();
        //Получение всех данных
        QList<QVariant> itemData=mainModel->data(index,Qt::UserRole).toList();
        if(!typeDel){
        ui->name->setText(itemData[0].toString());
        ui->description->setText(itemData[1].toString());
        ui->latitude->setText(itemData[2].toString());
        ui->longtitude->setText(itemData[3].toString());
        if(itemData.size() > 5)
            ui->label_photo->setPixmap(itemData[5].value<QPixmap>());
       // ui->label_photo->setPixmap(itemData[5].value<QPixmap>());
        ui->edit->setText("Сохранить изменения");
        typeDel=true;
        return;
        }
        else{
        QString type = itemData[4].toString();
        if(type== "STATE"){
            State newItem;
            newItem.name = ui->name->text();
            newItem.description = ui->description->text();
            newItem.latitude = ui->latitude->text().toDouble();
            newItem.longitude = ui->longtitude->text().toDouble();
            if(!pic.isNull()){
            newItem.picture=pic;
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type, newItem.picture};}
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
            mainModel->setData(index,itemData);
        }
        if(type== "SITY"){
            Sity newItem;
            newItem.name = ui->name->text();
            newItem.description = ui->description->text();
            newItem.latitude = ui->latitude->text().toDouble();
            newItem.longitude = ui->longtitude->text().toDouble();
            if(!pic.isNull()){
            newItem.picture=pic;
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type, newItem.picture};}
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
            mainModel->setData(index,itemData);
        }
        if(type== "VILLAGE"){
            Village newItem;
            newItem.name = ui->name->text();
            newItem.description = ui->description->text();
            newItem.latitude = ui->latitude->text().toDouble();
            newItem.longitude = ui->longtitude->text().toDouble();
            if(!pic.isNull()){
            newItem.picture=pic;
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type, newItem.picture};}
            itemData={newItem.name,newItem.description,newItem.latitude,newItem.longitude,newItem.type};
            mainModel->setData(index,itemData);
        }
    }
    ui->treeView->clearSelection();
    ui->label->setText("");
    ui->name->setText("");
    ui->description->setText("");
    ui->latitude->setText("");
    ui->longtitude->setText("");
    ui->edit->setText("Редатировать");
    typeDel=false;
    }
    ui->treeView->clearSelection();
}

void MainWindow::on_photo_clicked()
{

    if(ui->treeView->selectionModel()->selectedIndexes().count()>0)
    {
        QString path;
        path = QFileDialog::getOpenFileName(nullptr, "", "C:\\Users\\D15\\Desktop\\5 semester\\Visual prog\\fourth\\RFStruct\\pics","*.jpg");
        pic = QPixmap(path);
        ui->label->setPixmap(pic);
        ui->label->setAlignment(Qt::AlignCenter);
        //auto просто для скорости - это индекс выбранного элемента
        auto index= ui->treeView->selectionModel()->currentIndex();
        //Получение всех данных
        QList<QVariant> itemData=mainModel->data(index,Qt::UserRole).toList();
        QList<QVariant> itemDat=mainModel->data(index,Qt::UserRole).toList();

        itemData={itemDat[0].toString(),itemDat[1].toString(), itemDat[2].toDouble(),
                  itemDat[3].toDouble(), itemDat[4].toString(), pic};
        mainModel->setData(index,itemData);

    }
    ui->treeView->clearSelection();
    ui->label_photo->clear();

}

