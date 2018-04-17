/********************************************************************************
** Form generated from reading UI file 'findprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPROFILE_H
#define UI_FINDPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindProfile
{
public:
    QLabel *lblCourseText;
    QLabel *lblGenderText;
    QLabel *lblCourse;
    QLabel *lblStudentNoText;
    QLabel *lblName;
    QLabel *lblStudentNo;
    QPushButton *cmdFindProfile;
    QLabel *lblGender;
    QLabel *lblNameText;
    QLabel *lblDOB;
    QLabel *lblDOBtext;
    QLabel *label;
    QLineEdit *txtIDNoFind;
    QPushButton *cmdFindAnother;
    QPushButton *cmdUseFaceRec;
    QLabel *lblImagDisplay;

    void setupUi(QDialog *FindProfile)
    {
        if (FindProfile->objectName().isEmpty())
            FindProfile->setObjectName(QStringLiteral("FindProfile"));
        FindProfile->resize(472, 300);
        lblCourseText = new QLabel(FindProfile);
        lblCourseText->setObjectName(QStringLiteral("lblCourseText"));
        lblCourseText->setGeometry(QRect(20, 150, 251, 21));
        lblGenderText = new QLabel(FindProfile);
        lblGenderText->setObjectName(QStringLiteral("lblGenderText"));
        lblGenderText->setGeometry(QRect(20, 90, 251, 21));
        lblCourse = new QLabel(FindProfile);
        lblCourse->setObjectName(QStringLiteral("lblCourse"));
        lblCourse->setGeometry(QRect(20, 140, 71, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblCourse->setFont(font);
        lblStudentNoText = new QLabel(FindProfile);
        lblStudentNoText->setObjectName(QStringLiteral("lblStudentNoText"));
        lblStudentNoText->setGeometry(QRect(20, 120, 251, 21));
        lblName = new QLabel(FindProfile);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(20, 20, 47, 13));
        lblName->setFont(font);
        lblStudentNo = new QLabel(FindProfile);
        lblStudentNo->setObjectName(QStringLiteral("lblStudentNo"));
        lblStudentNo->setGeometry(QRect(20, 110, 71, 16));
        lblStudentNo->setFont(font);
        cmdFindProfile = new QPushButton(FindProfile);
        cmdFindProfile->setObjectName(QStringLiteral("cmdFindProfile"));
        cmdFindProfile->setGeometry(QRect(90, 250, 71, 23));
        lblGender = new QLabel(FindProfile);
        lblGender->setObjectName(QStringLiteral("lblGender"));
        lblGender->setGeometry(QRect(20, 80, 47, 13));
        lblGender->setFont(font);
        lblNameText = new QLabel(FindProfile);
        lblNameText->setObjectName(QStringLiteral("lblNameText"));
        lblNameText->setGeometry(QRect(20, 30, 251, 21));
        lblDOB = new QLabel(FindProfile);
        lblDOB->setObjectName(QStringLiteral("lblDOB"));
        lblDOB->setGeometry(QRect(20, 50, 47, 13));
        lblDOB->setFont(font);
        lblDOB->setFrameShape(QFrame::NoFrame);
        lblDOBtext = new QLabel(FindProfile);
        lblDOBtext->setObjectName(QStringLiteral("lblDOBtext"));
        lblDOBtext->setGeometry(QRect(20, 60, 251, 21));
        label = new QLabel(FindProfile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 230, 351, 16));
        txtIDNoFind = new QLineEdit(FindProfile);
        txtIDNoFind->setObjectName(QStringLiteral("txtIDNoFind"));
        txtIDNoFind->setGeometry(QRect(10, 250, 71, 20));
        txtIDNoFind->setMaxLength(4);
        cmdFindAnother = new QPushButton(FindProfile);
        cmdFindAnother->setObjectName(QStringLiteral("cmdFindAnother"));
        cmdFindAnother->setGeometry(QRect(330, 250, 111, 23));
        cmdUseFaceRec = new QPushButton(FindProfile);
        cmdUseFaceRec->setObjectName(QStringLiteral("cmdUseFaceRec"));
        cmdUseFaceRec->setGeometry(QRect(20, 190, 421, 23));
        lblImagDisplay = new QLabel(FindProfile);
        lblImagDisplay->setObjectName(QStringLiteral("lblImagDisplay"));
        lblImagDisplay->setGeometry(QRect(290, 40, 151, 121));

        retranslateUi(FindProfile);

        QMetaObject::connectSlotsByName(FindProfile);
    } // setupUi

    void retranslateUi(QDialog *FindProfile)
    {
        FindProfile->setWindowTitle(QApplication::translate("FindProfile", "Dialog", Q_NULLPTR));
        lblCourseText->setText(QString());
        lblGenderText->setText(QString());
        lblCourse->setText(QApplication::translate("FindProfile", "Course:", Q_NULLPTR));
        lblStudentNoText->setText(QString());
        lblName->setText(QApplication::translate("FindProfile", "Name:", Q_NULLPTR));
        lblStudentNo->setText(QApplication::translate("FindProfile", "Student No:", Q_NULLPTR));
        cmdFindProfile->setText(QApplication::translate("FindProfile", "Find Profile", Q_NULLPTR));
        lblGender->setText(QApplication::translate("FindProfile", "Gender:", Q_NULLPTR));
        lblNameText->setText(QString());
        lblDOB->setText(QApplication::translate("FindProfile", "DOB:", Q_NULLPTR));
        lblDOBtext->setText(QString());
        label->setText(QApplication::translate("FindProfile", "If face recognition does not work. Please enter users ID number: ", Q_NULLPTR));
        cmdFindAnother->setText(QApplication::translate("FindProfile", "Find Another Profile", Q_NULLPTR));
        cmdUseFaceRec->setText(QApplication::translate("FindProfile", "Use Face Recognition", Q_NULLPTR));
        lblImagDisplay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FindProfile: public Ui_FindProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPROFILE_H
