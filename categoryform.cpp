#include "categoryform.h"
#include "ui_categoryform.h"
#include "databasemanager.h"
#include <QTreeWidget>


CategoryForm::CategoryForm(DataBaseManager *dataBaseManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryForm)
{
    ui->setupUi(this);
    tableName = "ItemCategories";

    this->dataBaseManager = dataBaseManager;
    QStringList columns = getColumnNames(tableName);


    initHeader(ui->tableWidget, columns);
    ui->tableWidget->insertRow(indexes::inputRowIndex);

    ui->treeWidget->setColumnCount(columns.size());
    ui->treeWidget->setHeaderLabels(columns);
    fillTreeWidget(ui->treeWidget, columns.size());

    connect(ui->pushButton, QPushButton::clicked, this, [this, columns]()
    {
        if(tableRowNotEmpty(ui->tableWidget, indexes::inputRowIndex))
        {
            qDebug() << "First if";
            if(isUniqueId(tableName, ui->tableWidget->item(indexes::inputRowIndex, indexes::idColumnIndex)->text().toInt()))
            {


                qDebug() << "Second if";
                insertRow();
                updateQTree(ui->treeWidget, columns.size());
                clearInputRow(ui->tableWidget);
            }
            else
                showMessage("Current id already exists");
        }
        else
        {
           showMessage("You should to fill all cells.");
        }
    });

    connect(ui->deleteButton, QPushButton::clicked, this, [this, columns]()
    {
        if (removeElementFromBd(ui->lineEdit->text().toInt()))
        {
            updateQTree(ui->treeWidget, columns.size());
//            removeElementFromQTree(ui->treeWidget, ui->lineEdit->text().toInt(), columns.size());
            ui->lineEdit->clear();
        }
        else
        {
            showMessage("This id is missing");
        }
    });





//    ui->treeWidget->

}

CategoryForm::~CategoryForm()
{
    delete ui;
}

void CategoryForm::insertRow()
{
    dataBaseManager->sqlRequest(QString("INSERT INTO %1 VALUES (%2, '%3', '%4')")
                                .arg(tableName)
                                .arg(ui->tableWidget->item(indexes::inputRowIndex, 0)->text().toInt())
                                .arg(ui->tableWidget->item(indexes::inputRowIndex, 1)->text())
                                .arg(ui->tableWidget->item(indexes::inputRowIndex, 2)->text())
                                );
}
