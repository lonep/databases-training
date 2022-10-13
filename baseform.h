#ifndef BASEFORM_H
#define BASEFORM_H

#include <QDialog>

class DataBaseManager;
namespace Ui {
class baseForm;
}

class baseForm : public QDialog
{
    Q_OBJECT

public:
    explicit baseForm(QWidget *parent = nullptr, DataBaseManager *dataBaseManager = nullptr);
    ~baseForm();

protected:
    virtual QStringList getColumnNames(QString tableName);

    DataBaseManager *dataBaseManager;

private:
    Ui::baseForm *ui;
};

#endif // BASEFORM_H
