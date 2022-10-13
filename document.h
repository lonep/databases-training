#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QDialog>

namespace Ui {
class document;
}

class Document : public QDialog
{
    Q_OBJECT

public:
    explicit Document(QWidget *parent = nullptr);
    ~Document();

private:
    Ui::document *ui;
};

#endif // DOCUMENT_H
