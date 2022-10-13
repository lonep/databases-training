
#include <QStringList>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "itemsform.h"
#include "ui_itemsform.h"
#include "databasemanager.h"

ItemsForm::ItemsForm(DataBaseManager *dataBaseManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemsForm)
{
    ui->setupUi(this);
    tableName = "Items";
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), ui->lineEdit)); //Set validator for remove field;

    this->dataBaseManager = dataBaseManager;
    QStringList columns = getColumnNames(tableName);
    {

        initHeader(ui->tableWidget, columns);
        initHeader(ui->tableWidget_2, columns);
        ui->tableWidget_2->insertRow(indexes::inputRowIndex);

        fillTableWidget(ui->tableWidget, columns.size());

        connect(ui->pushButton, QPushButton::clicked, this, [this, columns]()
        {
            if(tableRowNotEmpty(ui->tableWidget_2, indexes::inputRowIndex))
            {
                qDebug() << "First if";

                if (isUniqueId(tableName, ui->tableWidget_2->item(indexes::inputRowIndex, indexes::idColumnIndex)->text().toInt()))
                {
                    qDebug() << "Second if";
                    insertRow();
                    addRow(ui->tableWidget, ui->tableWidget_2->item(indexes::inputRowIndex, indexes::idColumnIndex)->text().toInt());
                    clearInputRow(ui->tableWidget_2);
                }
                else
                {
                     showMessage("Current id already exists");
                }
            }
            else
            {
               showMessage("You should to fill all cells.");
            }
        });

        connect(ui->deleteButton, QPushButton::clicked, this, [this]()
        {
            if (removeElementFromBd(ui->lineEdit->text().toInt()))
            {
                removeElementById(ui->tableWidget, ui->lineEdit->text().toInt());
                ui->lineEdit->clear();
            }
            else
            {
                showMessage("This id is missing");
            }
        });
    }
}

ItemsForm::~ItemsForm()
{
    delete ui;
}


void ItemsForm::insertRow()
{
    dataBaseManager->sqlRequest(QString("INSERT INTO %1 VALUES (%2, '%3', '%4', '%5', %6)")
                                .arg(tableName)
                                .arg(ui->tableWidget_2->item(indexes::inputRowIndex, 0)->text().toInt())
                                .arg(ui->tableWidget_2->item(indexes::inputRowIndex, 1)->text())
                                .arg(ui->tableWidget_2->item(indexes::inputRowIndex, 2)->text())
                                .arg(ui->tableWidget_2->item(indexes::inputRowIndex, 3)->text())
                                .arg(ui->tableWidget_2->item(indexes::inputRowIndex, 4)->text().toInt())
                                );
}
