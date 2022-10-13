#ifndef CATEGORYFORM_H
#define CATEGORYFORM_H

#include <QDialog>
#include "form.h"

class DataBaseManager;
namespace Ui {
class CategoryForm;
}

class CategoryForm : public QDialog, public Form
{
    Q_OBJECT

public:
    explicit CategoryForm(DataBaseManager *dataBaseManager, QWidget *parent = nullptr);
    ~CategoryForm();

    void insertRow() override;

private:
    Ui::CategoryForm *ui;
    DataBaseManager *dataBaseManager;
};

#endif // CATEGORYFORM_H
