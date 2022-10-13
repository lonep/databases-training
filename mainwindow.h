#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class DataBaseManager;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showItemsForm();
    void showCategoryForm();
    void showMeasureUnitsForm();
    void showDocument();

private:
    Ui::MainWindow *ui;
    DataBaseManager *dataBaseManager;
};
#endif // MAINWINDOW_H
