#ifndef ITEMSFORM_H
#define ITEMSFORM_H

#include <QDialog>
#include "form.h"

class DataBaseManager;
namespace Ui {
class ItemsForm;
}

class ItemsForm : public QDialog, public Form
{
    Q_OBJECT

public:
    explicit ItemsForm( DataBaseManager *dataBaseManager = nullptr, QWidget *parent = nullptr);
    ~ItemsForm();

    void insertRow() override;

private:
    Ui::ItemsForm *ui;
};

#endif // ITEMSFORM_H
