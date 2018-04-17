#include "findprofile.h"
#include "ui_findprofile.h"
#include "menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "qmessagebox.h"
#include <QImage>
#include <QPixmap>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\face.hpp"

//int VideoCap();

using namespace std;
using namespace cv;
using namespace cv::face;
vector<String> FindSavingPicDir(vector<String>& ImageFilePath, int ID);
void ReadCSVDir(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);
int CallVideoRecogniser(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);
const string CSVNAME = "directory.csv";
const String CASCADE_LOCATION = "C:\\opencv\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml";
const int DEVICE_ID = 0;
const String WINDOW_NAME = "Video Feed";
int RunRecogniser(vector<Mat>& Images, vector<int>& IDs, vector<String>& FilePaths);
vector<Mat> images_QTFind;
vector<int> IDLabels_QTFind;
vector<String> ImageFilePaths_QTFind;
vector<Mat> imagesRecogniser;
vector<int> IDLabelsRecogniser;
vector<String> ImageFilePathsRecogniser;

FindProfile::FindProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindProfile)
{
    ui->setupUi(this);
	QLabel *lblImagDisplay;
	lblImagDisplay = new QLabel(this);
	lblImagDisplay->setPixmap(QPixmap("C:\\Users\\Joe\\Source\\Repos\\FaceRecognition with QT\\Face Recognition Rebuilt\\Face Recognition Rebuilt\\logo.png").scaled(150, 300, Qt::KeepAspectRatio));
	lblImagDisplay->show();
	lblImagDisplay->setGeometry(290, 15, 300, 155);

}

FindProfile::~FindProfile()
{
    delete ui;
}


void FindProfile::on_cmdFindProfile_clicked()
{
	string Textline, IDNo, Delim = "*";
	string  IDToFind = ui->txtIDNoFind->text().toLocal8Bit().constData();
	fstream Profiles("Profiles.txt");
	//IDToFind = VideoCap();
	bool FoundProfile = false;
	while (getline(Profiles, Textline))
	{
		IDNo = Textline.substr(0, Textline.find(Delim));
		Textline.erase(0, Textline.find(Delim) + Delim.length());
		//ui->lblImagDisplay->setText(QString::fromStdString(Textline));

		//istringstream Split(Textline);
		//Split >> IDNo;

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

			/*Split >> Name;
			Split >> DOB;
			Split >> Gender;
			Split >> StudentNo;
			Split >> CourseTitle;*/

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
			//Call function to find file path
			ReadCSVDir(images_QTFind, IDLabels_QTFind, ImageFilePaths_QTFind);
			vector<String>ProfilePhotos;
			ProfilePhotos = FindSavingPicDir(ImageFilePaths_QTFind, stoi(IDToFind, nullptr, 10));
			QString FilePath = QString::fromStdString(cv::String(ProfilePhotos[0]));
			QImage ProfilesImage;
			//Find the corrext image path and load it in ProfilesImage.load(" ")
			ProfilesImage.scaled(150, 300, Qt::KeepAspectRatio);
			ProfilesImage.load(FilePath);

			//Makes a pointer to the label to display the image at
			QLabel *lblImagDisplay;
			//Takes the pointer and stores it on the heap as a new object lblImageDisplay
			lblImagDisplay = new QLabel(this);
			//Use the object to set Pixmap which attaches the appropriate image to a Qlabel
			lblImagDisplay->setPixmap(QPixmap(FilePath).scaled(150,300,Qt::KeepAspectRatio));
			//Displays the Image
			lblImagDisplay->show();
			//Positions the image.
			lblImagDisplay->setGeometry(290, 15, 300, 155);




		}
	}
	Profiles.close();
	if (FoundProfile == false)
	{
		QMessageBox::information(this, "Error", "Profile not found in file.");
		ui->lblNameText->setText("");
		ui->lblDOBtext->setText("");
		ui->lblStudentNoText->setText("");
		ui->lblGenderText->setText("");
		ui->lblCourseText->setText("");
		ui->txtIDNoFind->setText("");

	}
	


}
//CLOSE THE FILE
void FindProfile::on_cmdUseFaceRec_clicked()
{
	string Textline, IDNo, Delim = "*";
	int Prediction = 100;
	Prediction= RunRecogniser(imagesRecogniser, IDLabelsRecogniser, ImageFilePathsRecogniser);
	stringstream ss;
	ss << Prediction;
	string  IDToFind = ss.str();
	cout << IDToFind << endl;
	////HERE insert prediction ID.
	fstream Profiles("Profiles.txt");
	bool FoundProfile = false;
	while (getline(Profiles, Textline))
	{
		IDNo = Textline.substr(0, Textline.find(Delim));
		Textline.erase(0, Textline.find(Delim) + Delim.length());
		//ui->lblImagDisplay->setText(QString::fromStdString(Textline));
				
		//istringstream Split(Textline);
		//Split >> IDNo;
				
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
			//Call function to find file path
			ReadCSVDir(images_QTFind, IDLabels_QTFind, ImageFilePaths_QTFind);
			vector<String>ProfilePhotos;
			ProfilePhotos = FindSavingPicDir(ImageFilePaths_QTFind, stoi(IDToFind, nullptr, 10));
			QString FilePath = QString::fromStdString(cv::String(ProfilePhotos[0]));
			QImage ProfilesImage;
			//Find the corrext image path and load it in ProfilesImage.load(" ")
			ProfilesImage.scaled(150, 300, Qt::KeepAspectRatio);
			ProfilesImage.load(FilePath);

			//Makes a pointer to the label to display the image at
			QLabel *lblImagDisplay;
			//Takes the pointer and stores it on the heap as a new object lblImageDisplay
			lblImagDisplay = new QLabel(this);
			//Use the object to set Pixmap which attaches the appropriate image to a Qlabel
			lblImagDisplay->setPixmap(QPixmap(FilePath).scaled(150, 300, Qt::KeepAspectRatio));
			//Displays the Image
			lblImagDisplay->show();
			//Positions the image.
			lblImagDisplay->setGeometry(290, 15, 300, 155);

		}
	}
	Profiles.close();
	/*if (FoundProfile == false)
	{
		QMessageBox::information(this, "Error", "Profile not found in file.");
	}*/

}


void FindProfile::on_cmdFindAnother_clicked()
{
    //Set all labels to blank. Set txt number blank. Restart Face Rec?

    ui->lblNameText->setText("");
    ui->lblDOBtext->setText("");
    ui->lblStudentNoText->setText("");
    ui->lblGenderText->setText("");
    ui->lblCourseText->setText("");
	ui->txtIDNoFind->setText("");
	//resize or remove 
	QLabel *lblImagDisplay;
	lblImagDisplay = new QLabel(this);
	lblImagDisplay->setPixmap(QPixmap("C:\\Users\\Joe\\Source\\Repos\\FaceRecognition with QT\\Face Recognition Rebuilt\\Face Recognition Rebuilt\\logo.png").scaled(150, 300, Qt::KeepAspectRatio));
	lblImagDisplay->show();
	lblImagDisplay->setGeometry(290, 15, 300, 155);
	
	//Clear Label image

    //Restart Face Rec loop
}

int CallVideoRecogniser(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath)
{
	int ReturnPrediction = 13;
	double PredictionConifdence = 0.0;
	/*try {
		ReadCSVDir(imagepaths, IDLabels, ImageFilePath);
	}
	catch (cv::Exception& e) {
		cerr << "Error opening file \"" << CSVNAME << "\". Reason: " << e.msg << endl;
		exit(1);
	}*/
	cout << "CSV Read" << endl;
	int Image_Width = imagepaths[5].cols;
	int Image_Height = imagepaths[5].rows;
	cout << "Dimensions allocated" << endl;
	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
	model->train(imagepaths, IDLabels);
	cout << "Trainer Created" << endl;
	CascadeClassifier haar_cascade;
	haar_cascade.load(CASCADE_LOCATION);
	VideoCapture VideoStream(DEVICE_ID);
	if (!VideoStream.isOpened())
	{
		cerr << "Capture Device ID " << DEVICE_ID << "cannot be opened." << endl;
		return -1;
	}
	Mat frame;
	while (true) {
		VideoStream >> frame;
		Mat original = frame.clone();
		Mat gray;
		cvtColor(original, gray, CV_BGR2GRAY);
		vector< Rect_<int> > Faces;
		haar_cascade.detectMultiScale(gray, Faces);
		for (int i = 0; i < Faces.size(); i++) {
			Rect Current_face = Faces[i];
			Mat face = gray(Current_face);
			Mat ResizedFace;
			cv::resize(face, ResizedFace, Size(Image_Width, Image_Height), 1.0, 1.0, INTER_CUBIC);
			int prediction = model->predict(ResizedFace);
			ReturnPrediction = prediction;
			rectangle(original, Current_face, CV_RGB(0, 255, 0), 1);
			string box_text = format("Prediction = %d", prediction);
			int pos_x = max(Current_face.tl().x - 10, 0);
			int pos_y = max(Current_face.tl().y - 10, 0);
			putText(original, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 255, 0), 2.0);
		}
		imshow(WINDOW_NAME, original);
		//cout << "IN WHILE LOOP" << endl;
		char key = (char)waitKey(20);
		//Break on escape
		if (key == 27) {
			return ReturnPrediction;
			break;
		}
	}
	VideoStream.release();
	destroyWindow(WINDOW_NAME);
}

int RunRecogniser(vector<Mat>& Images, vector<int>& IDs, vector<String>& FilePaths) {
	ReadCSVDir(Images, IDs, FilePaths);
	int Prediction=CallVideoRecogniser(Images, IDs, FilePaths);
	return Prediction;
}