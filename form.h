#ifndef FORM_H
#define FORM_H
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QTreeWidget>
#include <QSqlQuery>

class DataBaseManager;
class Form
{
public:
    Form(DataBaseManager *dataBaseManager = nullptr);

protected:
    enum indexes
    {
      inputRowIndex = 1,
      idColumnIndex = 0,
      headerRowIndex = 0
    };


    QString tableName;

    virtual QStringList getColumnNames     (QString tabName);
    virtual void        fillTableWidget    (QTableWidget *widget, int columns);
    virtual bool        tableRowNotEmpty   (const QTableWidget *widget, int row);
    virtual void        initHeader         (QTableWidget *widget, QStringList columns);
    virtual void        clearInputRow      (QTableWidget *widget);
    virtual void        addRow             (QTableWidget *widget, int id);
    virtual void        removeElementById  (QTableWidget *widget, int id);
    virtual bool        removeElementFromBd(int id);
    virtual void        fillTreeWidget     (QTreeWidget *widget, int columns);

    virtual void        fillChildrens      (QTreeWidgetItem *item, QSqlQuery query, int columns);
    virtual void        updateQTree        (QTreeWidget *widget, int columns);

    virtual void        removeElementFromQTree(QTreeWidget *widget, int id, int columns);

    virtual void        newRoot             (int removedId);

    void showMessage(QString text);

    virtual void insertRow() = 0;

    virtual bool isUniqueId(QString tableName, int Id);
    DataBaseManager *dataBaseManager;


private:

};

#endif // FORM_H
