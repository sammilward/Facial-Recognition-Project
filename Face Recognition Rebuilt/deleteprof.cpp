#include "deleteprof.h"
#include "ui_deleteprof.h"
#include "menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "qmessagebox.h"
#include <Windows.h>
#include <stdio.h>
using namespace std;
const char* PROFILE_NAME = "Profiles.txt";
const char* NEW_PROFILE_NAME = "NewProfiles.txt";
const char* DIRECTORY_NAME = "directory.csv";
const char* NEW_DIRECTORY_NAME = "newdirectory.csv";
const string FOLDER_PATH = "..\\images\\";
DeleteProf::DeleteProf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProf)
{
    ui->setupUi(this);
}

DeleteProf::~DeleteProf()
{
    delete ui;
}

void DeleteProf::on_cmdFindID_clicked()
{
	string Textline, IDNo, Delim = "*";
	string  IDToFind = ui->txtIDNoDelete->text().toLocal8Bit().constData();
	fstream Profiles(PROFILE_NAME);
	bool FoundProfile = false;
	while (getline(Profiles, Textline))
	{
		IDNo = Textline.substr(0, Textline.find(Delim));
		Textline.erase(0, Textline.find(Delim) + Delim.length());
		
		if (IDNo == IDToFind)
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


			ui->lblNameText->setText(QString::fromStdString(Name));
			ui->lblDOBtext->setText(QString::fromStdString(DOB));
			ui->lblStudentNoText->setText(QString::fromStdString(StudentNo));
			ui->lblCourseText->setText(QString::fromStdString(CourseTitle));

			if (Gender == "1")
			{
				ui->lblGenderText->setText("Male");
			}
			else if (Gender == "0")
			{
				ui->lblGenderText->setText("Female");
			}

		}
	}
	Profiles.close();
	if (FoundProfile == false)
	{
		QMessageBox::information(this, "Error", "Profile not found in file.");
		ui->txtIDNoDelete->setText("");
		ui->lblNameText->setText("");
		ui->lblDOBtext->setText("");
		ui->lblStudentNoText->setText("");
		ui->lblCourseText->setText("");
		ui->lblGenderText->setText("");
	}

}

void DeleteProf::on_cmdDelete_clicked()
{
	string  IDToRemove = ui->txtIDNoDelete->text().toLocal8Bit().constData();
	string Textline,IDNo, Delim="*";
	bool FoundProfile = false;
	ifstream ReadProfiles(PROFILE_NAME);
	ofstream WriteProfiles(NEW_PROFILE_NAME);

	while (getline(ReadProfiles, Textline))
	{
		IDNo = Textline.substr(0, Textline.find(Delim));
		if (IDNo != IDToRemove)
		{
			WriteProfiles << Textline << "\n";
		}
		else if (IDNo == IDToRemove) {
			FoundProfile = true;
		}
	}
	ReadProfiles.close();
	WriteProfiles.close();
	std::remove(PROFILE_NAME);
	std::rename(NEW_PROFILE_NAME, PROFILE_NAME);
///////////////////////////////////////////////////////////////////////////
	ifstream ReadDirectory(DIRECTORY_NAME);
	ofstream WriteDirectory(NEW_DIRECTORY_NAME);
	string TextLineDir,Delimiter,Token;
	size_t pos;
	Delimiter = ";";
	while (getline(ReadDirectory, TextLineDir))
	{
		Token = TextLineDir;
		pos = TextLineDir.find(Delimiter);
		TextLineDir.erase(0, pos + Delimiter.length());
		IDNo = TextLineDir;
		if (IDNo != IDToRemove)
		{
			WriteDirectory << Token << "\n";
		}
		else {
			WriteDirectory << "\n";
		}
	}
	ReadDirectory.close();
	WriteDirectory.close();
	//GET THESE TO WORK
	std::remove(DIRECTORY_NAME);
	std::rename(NEW_DIRECTORY_NAME, DIRECTORY_NAME);
	//string FolderPath = FOLDER_PATH;
	//FolderPath.append(IDToRemove);
	///*FolderPath.append("\\");*/
	//cout << FolderPath << endl;
	//WINDOWS CREATES ERRORS WITH THIS THAT CAN NOT BE EXPLAINED, WORKS FOR CREATION NOT FOR DELETE. WINDOWS API ISSUE
	//LPCSTR PtrDir;
	//PtrDir = FolderPath.c_str();
	//RemoveDirectoryW(PtrDir);
	if (FoundProfile == true)
	{
		QMessageBox::information(this, "Delete", "This profile has been deleted");
		ui->txtIDNoDelete->setText("");
		ui->lblNameText->setText("");
		ui->lblDOBtext->setText("");
		ui->lblStudentNoText->setText("");
		ui->lblCourseText->setText("");
		ui->lblGenderText->setText("");
	}
	else if (FoundProfile == false)
	{
		QMessageBox::information(this, "Error", "Profile not found in file.");
		ui->txtIDNoDelete->setText("");
		ui->lblNameText->setText("");
		ui->lblDOBtext->setText("");
		ui->lblStudentNoText->setText("");
		ui->lblCourseText->setText("");
		ui->lblGenderText->setText("");
	}
    //Create new file and miss out the file specified. Delete original file. Rename new file. Close File.
    //int ID = ui->txtIDNoDelete->text();
    //Compare to all lines in text file, if not the same, copy to new file. if same, miss out.

}
