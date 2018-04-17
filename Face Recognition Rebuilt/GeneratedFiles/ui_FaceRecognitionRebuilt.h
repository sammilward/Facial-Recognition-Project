/********************************************************************************
** Form generated from reading UI file 'FaceRecognitionRebuilt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNITIONREBUILT_H
#define UI_FACERECOGNITIONREBUILT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognitionRebuiltClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FaceRecognitionRebuiltClass)
    {
        if (FaceRecognitionRebuiltClass->objectName().isEmpty())
            FaceRecognitionRebuiltClass->setObjectName(QStringLiteral("FaceRecognitionRebuiltClass"));
        FaceRecognitionRebuiltClass->resize(600, 400);
        menuBar = new QMenuBar(FaceRecognitionRebuiltClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        FaceRecognitionRebuiltClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FaceRecognitionRebuiltClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FaceRecognitionRebuiltClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FaceRecognitionRebuiltClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FaceRecognitionRebuiltClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FaceRecognitionRebuiltClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FaceRecognitionRebuiltClass->setStatusBar(statusBar);

        retranslateUi(FaceRecognitionRebuiltClass);

        QMetaObject::connectSlotsByName(FaceRecognitionRebuiltClass);
    } // setupUi

    void retranslateUi(QMainWindow *FaceRecognitionRebuiltClass)
    {
        FaceRecognitionRebuiltClass->setWindowTitle(QApplication::translate("FaceRecognitionRebuiltClass", "FaceRecognitionRebuilt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognitionRebuiltClass: public Ui_FaceRecognitionRebuiltClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNITIONREBUILT_H
