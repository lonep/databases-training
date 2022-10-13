 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"

#include <QDebug>
#include <QMessageBox>
#include "itemsform.h"
#include "measureunitsform.h"
#include "categoryform.h"
#include "document.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataBaseManager = new DataBaseManager();

    connect(ui->itemsForm, QPushButton::clicked, this, [this]()
    {
        showItemsForm();
    });

    connect(ui->categoryForm, QPushButton::clicked, this, [this]()
    {
        showCategoryForm();
    });

    connect(ui->measureForm, QPushButton::clicked, this, [this]()
    {
        showMeasureUnitsForm();
    });

    connect(ui->document, QPushButton::clicked, this, [this]()
    {
        showDocument();
    });

}

MainWindow::~MainWindow()
{
    delete dataBaseManager;
    delete ui;
}

void MainWindow::showItemsForm()
{
    ItemsForm itemsForm(dataBaseManager);

    itemsForm.exec();
}

void MainWindow::showCategoryForm()
{
    CategoryForm categoryForm(dataBaseManager);
    categoryForm.exec();
}

void MainWindow::showMeasureUnitsForm()
{
    MeasureUnitsForm measureUnitSForm(dataBaseManager);
    measureUnitSForm.exec();
}

void MainWindow::showDocument()
{
    Document document;
    document.exec();
}

