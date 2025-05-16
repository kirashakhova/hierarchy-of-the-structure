#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>
#include <QPixmap>

//Структуры, которые описывают данные
//Можно и без них, но так проще запомнить
//Конструктор
//Область
struct State
{
    QString name;
    QString description;
    double latitude;
    double longitude;
    QPixmap picture;
    QString type="STATE";
};

//Город
struct Sity
{
    QString name;
    QString description;
    double latitude;
    double longitude;
    QPixmap picture;
    QString type="SITY";
};


//Поселок
struct Village
{
    QString name;
    QString description;
    double latitude;
    double longitude;
    QPixmap picture;
    QString type="VILLAGE";
};

//Класс, описывающий элемент иерархии. Достаточно универсальный
class TreeItem
{
public:
    //Конструктор и деструктор
    explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = nullptr);
    ~TreeItem();

    //Добавление и удаление дочерних элементов (сразу пачкой)
    bool insertChildren(int position, int count);
    bool removeChildren(int position, int count);

    //Данные методы понадобятся в первую очередь для сериализации и десериализации
    //Получение доступа к дочернему элементу по его номеру
    TreeItem *child(int row);
    //Число детей
    int childCount() const;
    //Номер элемента среди детей родителя
    int row() const;
    //Получение родителя
    TreeItem *parent();

    //Получение и заполнение данных. Два варианта - конкретной части данных и всех сразу
    QVariant data(int index) const;
    QList<QVariant> data() const;
    bool setData(int index, const QVariant &value);
    bool setData(const QList<QVariant> &value);



private:
    //Список детей
    QList<TreeItem *> m_childItems;
    //Данные в виде списка полей
    QList<QVariant> m_itemData;
    //Родитель
    TreeItem *m_parentItem;
};

#endif // TREEITEM_H
