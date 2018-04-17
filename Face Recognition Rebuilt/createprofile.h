#ifndef CREATEPROFILE_H
#define CREATEPROFILE_H

#include <QDialog>

namespace Ui {
class CreateProfile;
}

class CreateProfile : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfile(QWidget *parent = 0);
    ~CreateProfile();

private slots:
    void on_cmdNext_clicked();

private:
    Ui::CreateProfile *ui;
};

#endif // CREATEPROFILE_H
