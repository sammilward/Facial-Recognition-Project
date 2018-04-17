#include "createprofile.h"
#include "ui_createprofile.h"
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\face.hpp"
#include <QDebug>
#include "QMessageBox"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;
//void NewProfile(vector<Profile*> Profiles, int ID, string name, string DOB, bool isMale, string N_number, string course);

int FindNewIDNum();
void CreateCSV(int ID);
void UpdateCSV(int ID);
int TakePhoto(int ID, vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);
void CreateFolder(int ID);
void ReadCSVDir(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);
vector<String> FindSavingPicDir(vector<String>& ImageFilePath, int ID);

vector<Mat> images_QT;
vector<int> IDLabels_QT;
vector<String> ImageFilePaths_QT;

const String WINDOW_NAME = "Video Feed";

CreateProfile::CreateProfile(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CreateProfile)
{
	ui->setupUi(this);
	int ID = FindNewIDNum() + 1;
	ui->lblIDNo->setText(QString::number(ID));

}

CreateProfile::~CreateProfile()
{
	delete ui;
}

void CreateProfile::on_cmdNext_clicked()
{
	//Open up camera, take multiple photos. Save photos. Save text to file. Close camera. Message box. Clear text boxes

	//CHANGE THIS SO THAT IT DOES NOT DO IT FROM NUMBER OF PROFILES
	int ID = FindNewIDNum() + 1;
	//CALL CREATE FOLDER FUNCTION //PASS THE ID NUMBER
	CreateFolder(ID);
	QString Name = ui->txtName->text();
	QString DOB = ui->txtDOB->text();
	string isMale;
	if (ui->RBMale->isChecked())
	{
		isMale = "1";
	}
	if (ui->RBFemale->isChecked())
	{
		isMale = "0";
	}
	QString StudentNo = ui->txtStudentNo->text();
	QString CourseTitle = ui->txtCourseTitle->text();

	ofstream FileToWrite("Profiles.txt", ios::app);
	string LineToWrite = to_string(ID) + "*" + Name.toUtf8().constData() + "*" + DOB.toUtf8().constData() + "*" + isMale + "*" + StudentNo.toUtf8().constData() + "*" + CourseTitle.toUtf8().constData() + "\n";
	FileToWrite << LineToWrite;
	FileToWrite.close();
	UpdateCSV(ID);

	QMessageBox::information(this, "Complete", "Profile has been completed. Please Press SPACEBAR to take your photos");
	ui->txtName->setText("");
	ui->txtDOB->setText("");
	ui->txtCourseTitle->setText("");
	ui->txtStudentNo->setText("");
	ui->RBMale->setAutoExclusive(false);
	ui->RBFemale->setAutoExclusive(false);
	ui->RBMale->setChecked(false);
	ui->RBFemale->setChecked(false);
	ui->RBMale->setAutoExclusive(true);
	ui->RBFemale->setAutoExclusive(true);

	TakePhoto(ID, images_QT, IDLabels_QT, ImageFilePaths_QT);

	ID = FindNewIDNum() + 1;
	ui->lblIDNo->setText(QString::number(ID));
	//NewProfile(Profiles,  ID, Name.toUtf8().constData(), DOB.toUtf8().constData(), isMale, StudentNo.toUtf8().constData(), CourseTitle.toUtf8().constData());

	//CALL THE UPDATE CSV FUNCTION HERE //PASS THE ID NUMBER
	//Call TAKE PHOTO 
	
}

int FindNewIDNum()
{
	//Find the ID number for the newly created profile
	int IDCalculation;
	string ProfileNum, Textline, IDNo;
	fstream FileProfile("Profiles.txt");

	while (getline(FileProfile, Textline))
	{
		istringstream Split(Textline);
		//Gets the last line in the Profiles File and takes the IDNO
		Split >> IDNo;
	}
	//Converts the string to int for calculation
	IDCalculation = atoi(IDNo.c_str());
	FileProfile.close();
	return IDCalculation;
}

int TakePhoto(int ID, vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath) {
	ReadCSVDir(imagepaths, IDLabels, ImageFilePath);
	vector<String>TempDir = FindSavingPicDir(ImageFilePath, ID);
	VideoCapture stream1(0);
	if (!stream1.isOpened()) {
		cout << "cannot open camera";
	}
	Mat frame;
	int i = 0;
	char key = (char)cv::waitKey(30);
	while (true) {
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow(WINDOW_NAME, cameraFrame);
		stream1 >> frame;
		Mat original = frame.clone();
		Mat gray;
		vector< Rect_<int> > faces;
		//haar_cascade.detectMultiScale(gray, faces);
		cvtColor(original, gray, CV_BGR2GRAY);
		char key = (char)cv::waitKey(30);
		if (key == 32) {
			break;
		}
	}
	while (i < TempDir.size()) {
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow(WINDOW_NAME, cameraFrame);
		stream1 >> frame;
		Mat original = frame.clone();
		Mat gray;
		vector< Rect_<int> > faces;
		//haar_cascade.detectMultiScale(gray, faces);
		cvtColor(original, gray, CV_BGR2GRAY);
		char key = (char)cv::waitKey(30);
		string PicPath = TempDir[i];
		imwrite(PicPath, gray);
		cout << TempDir[i] << endl;
		cout << "Picture Taken" << endl;
		waitKey(1000);
		cout << i << endl;
		i++;
	}
	stream1.release();
	destroyWindow(WINDOW_NAME);
	return 0;
}
