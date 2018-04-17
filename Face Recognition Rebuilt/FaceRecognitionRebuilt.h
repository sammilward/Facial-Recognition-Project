#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FaceRecognitionRebuilt.h"

class FaceRecognitionRebuilt : public QMainWindow
{
	Q_OBJECT

public:
	FaceRecognitionRebuilt(QWidget *parent = Q_NULLPTR);

private:
	Ui::FaceRecognitionRebuiltClass ui;
};
