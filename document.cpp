#include "document.h"
#include "ui_document.h"

Document::Document(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::document)
{
    ui->setupUi(this);
}

Document::~Document()
{
    delete ui;
}
