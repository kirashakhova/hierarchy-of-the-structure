/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_photo;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLineEdit *name;
    QLabel *label_description;
    QLineEdit *description;
    QLabel *label_5;
    QLineEdit *longtitude;
    QLabel *label_6;
    QLineEdit *latitude;
    QPushButton *addButton;
    QPushButton *edit;
    QPushButton *photo;
    QPushButton *delete_2;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *info;
    QSpacerItem *verticalSpacer;
    QPushButton *upButton;
    QPushButton *addToList;
    QPushButton *findDistanse;
    QPushButton *clear;
    QPushButton *Model;
    QPushButton *Tree;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));

        verticalLayout->addWidget(label_photo);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_name = new QLabel(page_3);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout_2->addWidget(label_name);

        name = new QLineEdit(page_3);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout_2->addWidget(name);

        label_description = new QLabel(page_3);
        label_description->setObjectName(QString::fromUtf8("label_description"));

        verticalLayout_2->addWidget(label_description);

        description = new QLineEdit(page_3);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout_2->addWidget(description);

        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        longtitude = new QLineEdit(page_3);
        longtitude->setObjectName(QString::fromUtf8("longtitude"));

        verticalLayout_2->addWidget(longtitude);

        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        latitude = new QLineEdit(page_3);
        latitude->setObjectName(QString::fromUtf8("latitude"));

        verticalLayout_2->addWidget(latitude);

        addButton = new QPushButton(page_3);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        edit = new QPushButton(page_3);
        edit->setObjectName(QString::fromUtf8("edit"));

        verticalLayout_2->addWidget(edit);

        photo = new QPushButton(page_3);
        photo->setObjectName(QString::fromUtf8("photo"));

        verticalLayout_2->addWidget(photo);

        delete_2 = new QPushButton(page_3);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));

        verticalLayout_2->addWidget(delete_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        info = new QLabel(page_4);
        info->setObjectName(QString::fromUtf8("info"));

        verticalLayout_3->addWidget(info);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        upButton = new QPushButton(page_4);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        verticalLayout_3->addWidget(upButton);

        addToList = new QPushButton(page_4);
        addToList->setObjectName(QString::fromUtf8("addToList"));

        verticalLayout_3->addWidget(addToList);

        findDistanse = new QPushButton(page_4);
        findDistanse->setObjectName(QString::fromUtf8("findDistanse"));

        verticalLayout_3->addWidget(findDistanse);

        clear = new QPushButton(page_4);
        clear->setObjectName(QString::fromUtf8("clear"));

        verticalLayout_3->addWidget(clear);

        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        Model = new QPushButton(centralwidget);
        Model->setObjectName(QString::fromUtf8("Model"));

        verticalLayout->addWidget(Model);

        Tree = new QPushButton(centralwidget);
        Tree->setObjectName(QString::fromUtf8("Tree"));

        verticalLayout->addWidget(Tree);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_photo->setText(QString());
        label_name->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        label_description->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\276\320\273\320\263\320\276\321\202\321\203", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\265\320\270\321\202\320\265 \321\210\320\270\321\200\320\276\321\202\321\203", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        edit->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        photo->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        delete_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        info->setText(QString());
        upButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\275\321\217\321\202\321\214 \320\262 \320\270\320\265\321\200\320\260\321\200\321\205\320\270\320\270", nullptr));
        addToList->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\273\321\217 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217", nullptr));
        findDistanse->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        clear->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\276\321\201\320\270\321\202\321\214 \320\262\321\213\320\261\320\276\321\200", nullptr));
        Model->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\274\320\276\320\264\320\265\320\273\321\214\321\216", nullptr));
        Tree->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\264\320\265\321\200\320\265\320\262\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
