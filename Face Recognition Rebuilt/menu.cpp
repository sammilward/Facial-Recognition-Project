#include "menu.h"
#include "ui_menu.h"
#include "findprofile.h"
#include "createprofile.h"
#include "editprofile.h"
#include "deleteprof.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);




}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_cmdFindProfile_clicked()
{
    FindProfile Find;
    Find.setModal(true);
    Find.exec();
}

void Menu::on_cmdNewProfile_clicked()
{
    CreateProfile Create;
    Create.setModal(true);
    Create.exec();

    //createprof = new CreateProfile(this);
    //createprof->show();
}

void Menu::on_cmdEdit_clicked()
{
    EditProfile EProfile;
    EProfile.setModal(true);
    EProfile.exec();
}

void Menu::on_cmdDelete_clicked()
{
    DeleteProf DProfile;
    DProfile.setModal(true);
    DProfile.exec();
}


