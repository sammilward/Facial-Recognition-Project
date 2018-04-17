#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "createprofile.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_cmdFindProfile_clicked();

    void on_cmdNewProfile_clicked();

    void on_cmdEdit_clicked();

    void on_cmdDelete_clicked();


private:
    Ui::Menu *ui;
    //CreateProfile *createprof;

};

#endif // MENU_H
