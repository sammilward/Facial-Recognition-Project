#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>

namespace Ui {
class EditProfile;
}

class EditProfile : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfile(QWidget *parent = 0);
    ~EditProfile();

private slots:
    void on_cmdFindID_clicked();

    void on_cmdSave_clicked();

private:
    Ui::EditProfile *ui;
};

#endif // EDITPROFILE_H
