#include "form.h"
#include "databasemanager.h"
#include <QMessageBox>

Form::Form(DataBaseManager *dataBaseManager)
{

}

QStringList Form::getColumnNames(QString tableName)
{

    QStringList result;
    QSqlQuery query = dataBaseManager->sqlRequest(QString("SELECT column_name FROM user_tab_cols WHERE table_name=UPPER('%1')").arg(tableName));



    while (query.next())
        result.push_back(query.value(0).toString());

    return result;
}

bool Form::tableRowNotEmpty(const QTableWidget *widget, int row)
{
    for(int i = 0; i < widget->columnCount(); i++)
        if (!widget->item(row, i)) return false;
    return true;
}

void Form::initHeader(QTableWidget *widget, QStringList columns)
{
    widget->insertRow(indexes::headerRowIndex);

    int i = 0;
    foreach (auto it, columns)
    {
        widget->insertColumn(widget->columnCount());
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(it);
        widget->setItem(indexes::headerRowIndex, i, item);
        i++;
    }
}

void Form::clearInputRow(QTableWidget *widget)
{
    widget->removeRow(indexes::inputRowIndex);
    widget->insertRow(indexes::inputRowIndex);
}

void Form::addRow(QTableWidget *widget, int id)
{
    QSqlQuery query = dataBaseManager->sqlRequest(QString("SELECT * FROM %1 WHERE Id = '%2'").arg(tableName).arg(id));

    widget->insertRow(widget->rowCount());

    while (query.next())
    {
        for (int i = 0; i < widget->columnCount(); i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            widget->setItem(widget->rowCount() - 1, i, item);
        }
    }
}

void Form::removeElementById(QTableWidget *widget, int id)
{
    for (int i = 0; i < widget->rowCount(); i++)
    {
        if (widget->item(i, indexes::idColumnIndex)->text().toInt() == id)
        {
            widget->removeRow(i);
            break;
        }
    }
}

bool Form::removeElementFromBd(int id)
{
    QSqlQuery query = dataBaseManager->sqlRequest(QString("SELECT * FROM %1 WHERE Id = '%2'")
                                                  .arg(tableName)
                                                  .arg(id));


    while(query.next())
    {
        qDebug() << query.value(0).toString();
        if (query.value(0).toString() != "")
        {
            newRoot(id);
            dataBaseManager->sqlRequest(QString("DELETE FROM %1 WHERE Id = '%2'")
                                        .arg(tableName)
                                        .arg(id)).isValid();
                    return true;
        }
    }
    return false;

}

void Form::fillTreeWidget(QTreeWidget *widget, int columns)
{

        QSqlQuery query = dataBaseManager->sqlRequest
                (QString("SELECT * FROM %1 WHERE ParentId = '%2'").arg(tableName).arg(0));
        while(query.next())
        {
            qDebug() << query.value(1).toString();
            QTreeWidgetItem *item = new QTreeWidgetItem(widget);


            for (int i = 0; i < columns; i++)
                item->setText(i, query.value(i).toString());

            fillChildrens(item, QSqlQuery(QString("SELECT * FROM %1 WHERE ParentId = '%2'").arg(tableName).arg(query.value(0).toInt())), columns);
        }
}

void Form::fillChildrens(QTreeWidgetItem *item, QSqlQuery query, int columns)
{
    while(query.next())
    {
        QTreeWidgetItem *child = new QTreeWidgetItem();

        for (int i = 0; i < columns; i++)
            child->setText(i, query.value(i).toString());

        item->addChild(child);

        fillChildrens(child, QSqlQuery(QString("SELECT * FROM %1 WHERE ParentId = '%2'").arg(tableName).arg(query.value(0).toInt())), columns);
    }
}

void Form::updateQTree(QTreeWidget *widget, int columns)
{
    widget->clear();
    fillTreeWidget(widget, columns);
}

void Form::removeElementFromQTree(QTreeWidget *widget, int id, int columns)
{
//    for (int i = 0; i < columns; i++)

//       qDebug() << widget->findItems(QString::number(id), Qt::MatchFlag::MatchExactly, indexes::idColumnIndex).size();
    //    qDebug() << widget->currentItem()->text(1);
}

void Form::newRoot(int removedId)
{
    dataBaseManager->sqlRequest(QString("UPDATE %1 SET parentId = (SELECT parentId FROM %1 WHERE id = '%2') "
                                        "WHERE parentId = '2'").arg(tableName).arg(removedId));
}



void Form::fillTableWidget(QTableWidget *widget, int columns)
{
    QSqlQuery query = dataBaseManager->sqlRequest(QString("SELECT * FROM %1").arg(tableName));


    while (query.next())
    {

        widget->insertRow(widget->rowCount());
        for(int i = 0; i < columns; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            widget->setItem(widget->rowCount() - 1, i, item);
        }
    }
}

bool Form::isUniqueId(QString tablename, int Id)
{
    QSqlQuery query = dataBaseManager->sqlRequest(QString("SELECT * FROM %1 WHERE Id = '%2'").arg(tablename).arg(Id));

    while (query.next())
        qDebug() << query.value(0).toString();
        if (query.value(0).toString() != "")
            return false;
    return true;
}


void Form::showMessage(QString text)
{
    QMessageBox error;
    error.setText(text);
    error.exec();
}



