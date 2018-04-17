/********************************************************************************
** Form generated from reading UI file 'createprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROFILE_H
#define UI_CREATEPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreateProfile
{
public:
    QLabel *lblName;
    QPushButton *cmdNext;
    QLabel *lblDOB;
    QLabel *lblGender;
    QRadioButton *RBMale;
    QRadioButton *RBFemale;
    QLabel *lblStudNo;
    QLabel *lblCourseTitle;
    QLabel *lblIDNoText;
    QLabel *lblIDNo;
    QLineEdit *txtName;
    QLineEdit *txtDOB;
    QLineEdit *txtStudentNo;
    QLineEdit *txtCourseTitle;

    void setupUi(QDialog *CreateProfile)
    {
        if (CreateProfile->objectName().isEmpty())
            CreateProfile->setObjectName(QStringLiteral("CreateProfile"));
        CreateProfile->resize(243, 325);
        lblName = new QLabel(CreateProfile);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(20, 30, 201, 16));
        cmdNext = new QPushButton(CreateProfile);
        cmdNext->setObjectName(QStringLiteral("cmdNext"));
        cmdNext->setGeometry(QRect(80, 280, 75, 23));
        lblDOB = new QLabel(CreateProfile);
        lblDOB->setObjectName(QStringLiteral("lblDOB"));
        lblDOB->setGeometry(QRect(20, 80, 151, 16));
        lblGender = new QLabel(CreateProfile);
        lblGender->setObjectName(QStringLiteral("lblGender"));
        lblGender->setGeometry(QRect(20, 130, 151, 16));
        RBMale = new QRadioButton(CreateProfile);
        RBMale->setObjectName(QStringLiteral("RBMale"));
        RBMale->setGeometry(QRect(20, 150, 82, 17));
        RBFemale = new QRadioButton(CreateProfile);
        RBFemale->setObjectName(QStringLiteral("RBFemale"));
        RBFemale->setGeometry(QRect(110, 150, 82, 17));
        lblStudNo = new QLabel(CreateProfile);
        lblStudNo->setObjectName(QStringLiteral("lblStudNo"));
        lblStudNo->setGeometry(QRect(20, 170, 151, 16));
        lblCourseTitle = new QLabel(CreateProfile);
        lblCourseTitle->setObjectName(QStringLiteral("lblCourseTitle"));
        lblCourseTitle->setGeometry(QRect(20, 220, 151, 16));
        lblIDNoText = new QLabel(CreateProfile);
        lblIDNoText->setObjectName(QStringLiteral("lblIDNoText"));
        lblIDNoText->setGeometry(QRect(20, 10, 151, 16));
        lblIDNoText->setFrameShape(QFrame::NoFrame);
        lblIDNo = new QLabel(CreateProfile);
        lblIDNo->setObjectName(QStringLiteral("lblIDNo"));
        lblIDNo->setGeometry(QRect(180, 10, 151, 16));
        txtName = new QLineEdit(CreateProfile);
        txtName->setObjectName(QStringLiteral("txtName"));
        txtName->setGeometry(QRect(20, 50, 201, 20));
        txtName->setMaxLength(50);
        txtDOB = new QLineEdit(CreateProfile);
        txtDOB->setObjectName(QStringLiteral("txtDOB"));
        txtDOB->setGeometry(QRect(20, 100, 201, 20));
        txtDOB->setMaxLength(8);
        txtStudentNo = new QLineEdit(CreateProfile);
        txtStudentNo->setObjectName(QStringLiteral("txtStudentNo"));
        txtStudentNo->setGeometry(QRect(20, 190, 201, 20));
        txtStudentNo->setMaxLength(8);
        txtCourseTitle = new QLineEdit(CreateProfile);
        txtCourseTitle->setObjectName(QStringLiteral("txtCourseTitle"));
        txtCourseTitle->setGeometry(QRect(20, 240, 201, 20));
        txtCourseTitle->setMaxLength(100);

        retranslateUi(CreateProfile);

        QMetaObject::connectSlotsByName(CreateProfile);
    } // setupUi

    void retranslateUi(QDialog *CreateProfile)
    {
        CreateProfile->setWindowTitle(QApplication::translate("CreateProfile", "Dialog", Q_NULLPTR));
        lblName->setText(QApplication::translate("CreateProfile", "Enter First Name and Surename: ", Q_NULLPTR));
        cmdNext->setText(QApplication::translate("CreateProfile", "Next", Q_NULLPTR));
        lblDOB->setText(QApplication::translate("CreateProfile", "Enter DOB in format DD/MM/YY:", Q_NULLPTR));
        lblGender->setText(QApplication::translate("CreateProfile", "Enter Gender:", Q_NULLPTR));
        RBMale->setText(QApplication::translate("CreateProfile", "Male", Q_NULLPTR));
        RBFemale->setText(QApplication::translate("CreateProfile", "Female", Q_NULLPTR));
        lblStudNo->setText(QApplication::translate("CreateProfile", "Enter Student No:", Q_NULLPTR));
        lblCourseTitle->setText(QApplication::translate("CreateProfile", "Enter Course Title:", Q_NULLPTR));
        lblIDNoText->setText(QApplication::translate("CreateProfile", "Your profiles ID Number will be: ", Q_NULLPTR));
        lblIDNo->setText(QString());
        txtName->setText(QString());
        txtDOB->setText(QString());
        txtStudentNo->setText(QString());
        txtCourseTitle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateProfile: public Ui_CreateProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFILE_H
