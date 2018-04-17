// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//Including all libaries
#pragma once
#include "Class_Functions.h"
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\face.hpp"

using namespace cv;
using namespace cv::face;
using namespace std;
using std::max;

//CONSTANTS
const int PICAMOUNT = 10;
const string ADDRESS = "..\\images\\";
const int IDAMOUNT = 10;
const string CSVNAME = "directory.csv";
const string PROFILE_TXT_FILENAME = "Profiles.txt";
const String WINDOW_NAME = "Video Feed";
const String RECOGNISER_FILENAME = "model.yaml";
const String CASCADE_LOCATION = "C:\\opencv\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml";
const int DEVICE_ID = 1;

//Function declerations, Change data types at any points
//Load a specific students details from the database
void NewProfile(vector<Profile*> Profiles, int ID, string name, string DOB, bool isMale, string N_number, string course);
//void LoadProfile(int ID, Mat ProfilePhoto);
//void FetchStudentsDetails();
//Creation of files and folders
void CreateCSV(int ID);
void UpdateCSV(int ID);
void CreateFolder(int ID);
void CreateRootFolder();
void ReadCSVDir(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);
string ReadProfile(int ID);
fstream& GotoLine(fstream& file, int ID);
//void StartTrainer(vector<Mat>& images, vector<int>& IDLabels);
vector<String> FindSavingPicDir(vector<String>& ImageFilePath, int ID);
int CallVideoRecogniser(vector<Mat>& imagepaths, vector<int>& IDLabels, vector<String>& ImageFilePath);

//Fetch from the text file the pointers to the linked list
vector<Profile*> Profiles;
//Vecotrs for holding images and the labels
vector<Mat> images;
vector<int> IDLabels;
vector<String> ImageFilePaths;


void CreateCSV(int ID) {
	ofstream writer(CSVNAME);
	string FilePath;
	string FileName;
	ostringstream oss_1;
	string Folder;
	string BaseFileName;
	oss_1 << ID;
	Folder = oss_1.str();
	FileName = oss_1.str();
	FileName.append(".jpg;");
	FilePath = ADDRESS;
	FilePath.append(Folder);
	FilePath.append("\\");
	//Picture Numberer
	for (int i = 0; i < PICAMOUNT; i++) {
		FileName = "";
		ostringstream oss;
		oss << i;
		FileName = oss.str();
		FileName.append(".jpg;");
		writer << FilePath << FileName << Folder << endl;
	}
	writer.close();
	cout << "CSV CREATED" << endl;
}
void UpdateCSV(int ID) {
	//Folder Structure: ID/picture_number(possibly ID?).jpg;ID
	ofstream writer(CSVNAME, ios::app);
	string FilePath;
	string FileName;
	ostringstream oss_1;
	string Folder;
	string BaseFileName;
	oss_1 << ID;
	Folder = oss_1.str();
	FilePath = ADDRESS;
	FilePath.append(Folder);
	FilePath.append("\\");
	//Picture Numberer
	for (int i = 0; i < PICAMOUNT; i++) {
		FileName = "";
		ostringstream oss;
		oss << i;
		FileName = oss.str();
		FileName.append(".jpg;");
		writer << FilePath << FileName << Folder << endl;
	}
	writer.close();
}


void CreateRootFolder() {
#ifdef _UNICODE
	typedef wchar_t TCHAR;
#else
	typedef char TCHAR;
#endif // _UNICODE
	typedef const TCHAR* LPCTSTR;
	string FolderName;
	FolderName = "..\\images";
	LPCSTR PtrFinDir;
	PtrFinDir = FolderName.c_str();
	CreateDirectoryA(PtrFinDir, NULL);
}

void CreateFolder(int ID) {
#ifdef _UNICODE
	typedef wchar_t TCHAR;
#else
	typedef char TCHAR;
#endif // _UNICODE
	typedef const TCHAR* LPCTSTR;
	ostringstream oss_2;
	oss_2 << ID;
	string FolderName;
	FolderName = "..\\images\\";
	string FinDir;
	FinDir = FolderName.append(oss_2.str());
	LPCSTR PtrFinDir;
	PtrFinDir = FinDir.c_str();
	CreateDirectoryA(PtrFinDir, NULL);
}

void SaveImageToFolder(string FilePath, Mat ImageToSave)
{
	imwrite(FilePath, ImageToSave);
}

string ReadProfile(int id) {
	int ID;
	string name;
	string DOB;
	bool isMale;
	string N_number;
	string course;
	fstream reader(PROFILE_TXT_FILENAME, ios::app);
	GotoLine(reader, id);
	reader >> ID >> name >> DOB >> isMale >> N_number >> course;
	cout << ID << name << DOB << boolalpha << isMale << endl;
	cout << N_number << course << endl;
	return name;
}
fstream& GotoLine(fstream& file, int ID) {
	file.seekg(ios::beg);
	for (int i = 0; i < ID; i++) {
		file.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}
	return file;
}

void NewProfile(vector<Profile*> Profiles, int ID, string name, string DOB, bool isMale, string N_number, string course) {
	Profiles.push_back(new Profile(ID, name, DOB, isMale, N_number, course));
}

void ReadCSVDir(vector<Mat>& images, vector<int>& IDLabels, vector<String>& ImageFilePath) {
	ifstream file(CSVNAME, ifstream::in);
	string line, path, profileID;
	char separator = ';';
	while (getline(file, line)) {
		stringstream PathSeperator(line);
		getline(PathSeperator, path, separator);
		getline(PathSeperator, profileID);
		if (!path.empty() && !profileID.empty()) {
			images.push_back(imread(path, 0));
			ImageFilePath.push_back(path);
			IDLabels.push_back(atoi(profileID.c_str()));
		}
	}
}

vector<String> FindSavingPicDir(vector<String>& ImageFilePath, int ID) {
	vector<String> SavingDir;
	for (int i = 0; i < PICAMOUNT; i++) {
		SavingDir.push_back(ImageFilePath[i + (ID*PICAMOUNT)]);
	}
	return SavingDir;
}

void StartTrainer(vector<Mat>& images, vector<int>& IDLabels) {
	// Create a FaceRecognizer and train it on the given images:
	cv::Ptr<cv::face::FaceRecognizer> model = cv::face::createFisherFaceRecognizer();
	model->train(images, IDLabels);
	model->save(RECOGNISER_FILENAME);
}

