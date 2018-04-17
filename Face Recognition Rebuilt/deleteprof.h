#ifndef DELETEPROF_H
#define DELETEPROF_H

#include <QDialog>

namespace Ui {
class DeleteProf;
}

class DeleteProf : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteProf(QWidget *parent = 0);
    ~DeleteProf();

private slots:
    void on_cmdFindID_clicked();

    void on_cmdDelete_clicked();

private:
    Ui::DeleteProf *ui;
};

#endif // DELETEPROF_H
