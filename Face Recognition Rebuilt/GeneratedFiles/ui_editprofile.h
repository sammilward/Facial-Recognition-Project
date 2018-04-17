/********************************************************************************
** Form generated from reading UI file 'editprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROFILE_H
#define UI_EDITPROFILE_H

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

class Ui_EditProfile
{
public:
    QLabel *lblCourseTitle;
    QLabel *lblGender;
    QRadioButton *RBEditFemale;
    QLabel *lblDOB;
    QRadioButton *RBEditMale;
    QLabel *lblStudNo;
    QPushButton *cmdSave;
    QLabel *lblName;
    QLabel *lblEnterID;
    QPushButton *cmdFindID;
    QLineEdit *txtEditName;
    QLineEdit *txtDOBEdit;
    QLineEdit *txtEditStudentNo;
    QLineEdit *txtEditCourseTitle;
    QLineEdit *txtIDNoEdit;

    void setupUi(QDialog *EditProfile)
    {
        if (EditProfile->objectName().isEmpty())
            EditProfile->setObjectName(QStringLiteral("EditProfile"));
        EditProfile->resize(295, 321);
        lblCourseTitle = new QLabel(EditProfile);
        lblCourseTitle->setObjectName(QStringLiteral("lblCourseTitle"));
        lblCourseTitle->setGeometry(QRect(20, 230, 151, 16));
        lblGender = new QLabel(EditProfile);
        lblGender->setObjectName(QStringLiteral("lblGender"));
        lblGender->setGeometry(QRect(20, 140, 151, 16));
        RBEditFemale = new QRadioButton(EditProfile);
        RBEditFemale->setObjectName(QStringLiteral("RBEditFemale"));
        RBEditFemale->setGeometry(QRect(110, 160, 82, 17));
        lblDOB = new QLabel(EditProfile);
        lblDOB->setObjectName(QStringLiteral("lblDOB"));
        lblDOB->setGeometry(QRect(20, 90, 151, 16));
        RBEditMale = new QRadioButton(EditProfile);
        RBEditMale->setObjectName(QStringLiteral("RBEditMale"));
        RBEditMale->setGeometry(QRect(20, 160, 82, 17));
        lblStudNo = new QLabel(EditProfile);
        lblStudNo->setObjectName(QStringLiteral("lblStudNo"));
        lblStudNo->setGeometry(QRect(20, 180, 151, 16));
        cmdSave = new QPushButton(EditProfile);
        cmdSave->setObjectName(QStringLiteral("cmdSave"));
        cmdSave->setGeometry(QRect(80, 290, 81, 23));
        lblName = new QLabel(EditProfile);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(20, 40, 151, 16));
        lblEnterID = new QLabel(EditProfile);
        lblEnterID->setObjectName(QStringLiteral("lblEnterID"));
        lblEnterID->setGeometry(QRect(20, 10, 151, 16));
        cmdFindID = new QPushButton(EditProfile);
        cmdFindID->setObjectName(QStringLiteral("cmdFindID"));
        cmdFindID->setGeometry(QRect(210, 10, 75, 23));
        txtEditName = new QLineEdit(EditProfile);
        txtEditName->setObjectName(QStringLiteral("txtEditName"));
        txtEditName->setGeometry(QRect(20, 60, 201, 20));
        txtEditName->setMaxLength(50);
        txtDOBEdit = new QLineEdit(EditProfile);
        txtDOBEdit->setObjectName(QStringLiteral("txtDOBEdit"));
        txtDOBEdit->setGeometry(QRect(20, 110, 201, 20));
        txtDOBEdit->setMaxLength(8);
        txtEditStudentNo = new QLineEdit(EditProfile);
        txtEditStudentNo->setObjectName(QStringLiteral("txtEditStudentNo"));
        txtEditStudentNo->setGeometry(QRect(20, 200, 201, 20));
        txtEditStudentNo->setMaxLength(8);
        txtEditCourseTitle = new QLineEdit(EditProfile);
        txtEditCourseTitle->setObjectName(QStringLiteral("txtEditCourseTitle"));
        txtEditCourseTitle->setGeometry(QRect(20, 250, 201, 20));
        txtEditCourseTitle->setMaxLength(100);
        txtIDNoEdit = new QLineEdit(EditProfile);
        txtIDNoEdit->setObjectName(QStringLiteral("txtIDNoEdit"));
        txtIDNoEdit->setGeometry(QRect(170, 10, 31, 20));
        txtIDNoEdit->setMaxLength(4);

        retranslateUi(EditProfile);

        QMetaObject::connectSlotsByName(EditProfile);
    } // setupUi

    void retranslateUi(QDialog *EditProfile)
    {
        EditProfile->setWindowTitle(QApplication::translate("EditProfile", "Dialog", Q_NULLPTR));
        lblCourseTitle->setText(QApplication::translate("EditProfile", "Change Course Title:", Q_NULLPTR));
        lblGender->setText(QApplication::translate("EditProfile", "Change Gender:", Q_NULLPTR));
        RBEditFemale->setText(QApplication::translate("EditProfile", "Female", Q_NULLPTR));
        lblDOB->setText(QApplication::translate("EditProfile", "Edit DOB, format DD/MM/YY :", Q_NULLPTR));
        RBEditMale->setText(QApplication::translate("EditProfile", "Male", Q_NULLPTR));
        lblStudNo->setText(QApplication::translate("EditProfile", "Edit Student No:", Q_NULLPTR));
        cmdSave->setText(QApplication::translate("EditProfile", "Save Changes", Q_NULLPTR));
        lblName->setText(QApplication::translate("EditProfile", "Edit Name:", Q_NULLPTR));
        lblEnterID->setText(QApplication::translate("EditProfile", "Enter ID No of Profile to Edit:", Q_NULLPTR));
        cmdFindID->setText(QApplication::translate("EditProfile", "Find Profile", Q_NULLPTR));
        txtEditName->setText(QString());
        txtDOBEdit->setInputMask(QString());
        txtDOBEdit->setText(QString());
        txtEditStudentNo->setText(QString());
        txtEditCourseTitle->setText(QString());
        txtIDNoEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditProfile: public Ui_EditProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROFILE_H
