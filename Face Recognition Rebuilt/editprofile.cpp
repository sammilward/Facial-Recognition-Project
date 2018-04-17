#include "editprofile.h"
#include "ui_editprofile.h"
#include "QMessageBox"
#include <fstream>
#include <iostream>
#include <sstream>
#include "qmessagebox.h"
#include <stdio.h>

using namespace std;

EditProfile::EditProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfile)
{
    ui->setupUi(this);
}

EditProfile::~EditProfile()
{
    delete ui;
}


void EditProfile::on_cmdFindID_clicked()
{
    // if statement for no ID number existing or left blank.
	ui->txtEditName->setText("");
	ui->txtDOBEdit->setText("");
	ui->txtEditStudentNo->setText("");
	ui->txtEditCourseTitle->setText("");
	ui->RBEditMale->setAutoExclusive(false);
	ui->RBEditFemale->setAutoExclusive(false);
	ui->RBEditMale->setChecked(false);
	ui->RBEditFemale->setChecked(false);
	ui->RBEditMale->setAutoExclusive(true);
	ui->RBEditFemale->setAutoExclusive(true);

    string Textline, IDNo, Delim = "*";
	bool FoundProfile = false;
    if (ui->txtIDNoEdit->text().length() == 0)
    {
        //Error message, enter a number to find profile
    }
    //capture entering letters instead of numbers
    else
    {
        fstream Profiles("Profiles.txt");
        while (getline(Profiles, Textline))
        {

			IDNo = Textline.substr(0, Textline.find(Delim));
			Textline.erase(0, Textline.find(Delim) + Delim.length());

            /*istringstream Split(Textline);
            Split >> IDNo;*/

            if (QString::fromStdString(IDNo) == ui->txtIDNoEdit->text())
            {
				FoundProfile = true;
				string Name = Textline.substr(0, Textline.find(Delim));
				Textline.erase(0, Textline.find(Delim) + Delim.length());
				string DOB = Textline.substr(0, Textline.find(Delim));
				Textline.erase(0, Textline.find(Delim) + Delim.length());
				string Gender = Textline.substr(0, Textline.find(Delim));
				Textline.erase(0, Textline.find(Delim) + Delim.length());
				string StudentNo = Textline.substr(0, Textline.find(Delim));
				Textline.erase(0, Textline.find(Delim) + Delim.length());
				string CourseTitle = Textline.substr(0, Textline.find(Delim));

               /* Split >> Name;
                Split >> DOB;
                Split >> Gender;
                Split >> StudentNo;
                Split >> CourseTitle;*/

                ui->txtEditName->setText(QString::fromStdString(Name));
                ui->txtDOBEdit->setText(QString::fromStdString(DOB));
                ui->txtEditStudentNo->setText(QString::fromStdString(StudentNo));
                ui->txtEditCourseTitle->setText(QString::fromStdString(CourseTitle));

				if (Gender == "1")
				{
					ui->RBEditMale->setChecked(true);
				}
				else if (Gender == "0")
				{
					ui->RBEditFemale->setChecked(true);
				}
            }

			//add radio button changes
			

        }
		Profiles.close();
		if (FoundProfile == false)
		{
			QMessageBox::information(this, "Error", "Profile not found in file.");
		}
    }

    //if valid number, search text file. Fetch info to array. Set txts to users info.

    //Find profile infromation and display it on the lbls

    //File Reading Stuff
    //Find Correct line using ID number and comparison

    //ui->txtEditName->setText(Name);
    //ui->txtDOBEdit->setText(DOB);

    //if (Gender == "1")
    //{
    //ui->RBEditMale->setChecked(true);
    //}

    //else (Gender == "0")
    //{
    //ui->RBEditFemale->setChecked(true);
    //}


    //ui->txtEditStudentNo->setText(StudentNo);
    //ui->txtEditCourseTitle->setText(CourseTitle);

}

void EditProfile::on_cmdSave_clicked()
{
    //Take information from txts, save to array. Save array with spacing to text file
    //Message box to confirm
    //Sort Textfile
    //Clear txts

	//Get info from form
    QString ID = ui->txtIDNoEdit->text();
    QString Name = ui->txtEditName->text();
    QString DOB = ui->txtDOBEdit->text();
    QString isMale;
    if (ui->RBEditMale->isChecked())
    {
        isMale = "1";
    }
    if (ui->RBEditFemale->isChecked())
    {
        isMale = "0";
    }
    QString StudentNo = ui->txtEditStudentNo->text();
    QString CourseTitle = ui->txtEditCourseTitle->text();
    
	//Create a text line to write to new file
    QString LineToWrite = ID + "*" + Name + "*" + DOB + "*" + isMale + "*" + StudentNo + "*" + CourseTitle;

	string  IDToEdit = ui->txtIDNoEdit->text().toLocal8Bit().constData();
	string Textline, IDNo, Delim = "*";
	bool FoundProfile = false;
	ifstream ReadProfiles("Profiles.txt");
	ofstream WriteProfiles("NewProfiles.txt");

	while (getline(ReadProfiles, Textline))
	{
		//Loop through the original file, copying all the profile information, apart from the profile
		//to be edited
		IDNo = Textline.substr(0, Textline.find(Delim));
		if (IDNo != IDToEdit)
		{
			WriteProfiles << Textline << "\n";
		}
		else if (IDNo == IDToEdit)
		{
			FoundProfile = true;
			WriteProfiles << LineToWrite.toUtf8().constData() << "\n";
		}

	}
	//Close Files
	ReadProfiles.close();
	WriteProfiles.close();
	
	//Remove orignial file, then rename the new file to the orignial name
	std::remove("Profiles.txt");
	std::rename("NewProfiles.txt", "Profiles.txt");
    
	//Clear the form
    ui->txtIDNoEdit->setText("");
    ui->txtEditName->setText("");
    ui->txtDOBEdit->setText("");
    ui->txtEditStudentNo->setText("");
    ui->txtEditCourseTitle->setText("");
    ui->RBEditMale->setAutoExclusive(false);
    ui->RBEditFemale->setAutoExclusive(false);
    ui->RBEditMale->setChecked(false);
    ui->RBEditFemale->setChecked(false);
    ui->RBEditMale->setAutoExclusive(true);
    ui->RBEditFemale->setAutoExclusive(true);

	//Display message box 
    QMessageBox::information(this, "Alert", "Profile has been edited");
}

