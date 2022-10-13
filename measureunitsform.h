#ifndef MEASUREUNITSFORM_H
#define MEASUREUNITSFORM_H

#include <QDialog>
#include "form.h"

class DataBaseManager;
namespace Ui {
class MeasureUnitsForm;
}

class MeasureUnitsForm : public QDialog, public Form
{
    Q_OBJECT

public:
    explicit MeasureUnitsForm(DataBaseManager *dataBaseManager, QWidget *parent = nullptr);
    ~MeasureUnitsForm();

     void insertRow() override;

private:
    Ui::MeasureUnitsForm *ui;
    DataBaseManager *dataBaseManager;
};

#endif // MEASUREUNITSFORM_H
