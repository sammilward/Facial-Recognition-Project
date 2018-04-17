#ifndef FINDPROFILE_H
#define FINDPROFILE_H

#include <QDialog>

namespace Ui {
class FindProfile;
}

class FindProfile : public QDialog
{
    Q_OBJECT

public:
    explicit FindProfile(QWidget *parent = 0);
    ~FindProfile();

private slots:
    void on_cmdFindProfile_clicked();

    void on_cmdFindAnother_clicked();

	void on_cmdUseFaceRec_clicked();

private:
    Ui::FindProfile *ui;
};

#endif // FINDPROFILE_H
