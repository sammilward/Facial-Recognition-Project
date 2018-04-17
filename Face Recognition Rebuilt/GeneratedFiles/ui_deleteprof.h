/********************************************************************************
** Form generated from reading UI file 'deleteprof.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPROF_H
#define UI_DELETEPROF_H

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

class Ui_DeleteProf
{
public:
    QPushButton *cmdFindID;
    QLabel *lblEnterID;
    QLabel *lblCourseText;
    QLabel *lblNameText;
    QLabel *lblGenderText;
    QLabel *lblStudentNo;
    QLabel *lblGender;
    QLabel *lblDOB;
    QLabel *lblStudentNoText;
    QLabel *lblName;
    QLabel *lblDOBtext;
    QLabel *lblCourse;
    QPushButton *cmdDelete;
    QLineEdit *txtIDNoDelete;

    void setupUi(QDialog *DeleteProf)
    {
        if (DeleteProf->objectName().isEmpty())
            DeleteProf->setObjectName(QStringLiteral("DeleteProf"));
        DeleteProf->resize(400, 300);
        cmdFindID = new QPushButton(DeleteProf);
        cmdFindID->setObjectName(QStringLiteral("cmdFindID"));
        cmdFindID->setGeometry(QRect(250, 70, 75, 23));
        lblEnterID = new QLabel(DeleteProf);
        lblEnterID->setObjectName(QStringLiteral("lblEnterID"));
        lblEnterID->setGeometry(QRect(60, 70, 151, 16));
        lblCourseText = new QLabel(DeleteProf);
        lblCourseText->setObjectName(QStringLiteral("lblCourseText"));
        lblCourseText->setGeometry(QRect(10, 240, 251, 21));
        lblNameText = new QLabel(DeleteProf);
        lblNameText->setObjectName(QStringLiteral("lblNameText"));
        lblNameText->setGeometry(QRect(10, 120, 251, 21));
        lblGenderText = new QLabel(DeleteProf);
        lblGenderText->setObjectName(QStringLiteral("lblGenderText"));
        lblGenderText->setGeometry(QRect(10, 180, 251, 21));
        lblStudentNo = new QLabel(DeleteProf);
        lblStudentNo->setObjectName(QStringLiteral("lblStudentNo"));
        lblStudentNo->setGeometry(QRect(10, 200, 71, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblStudentNo->setFont(font);
        lblGender = new QLabel(DeleteProf);
        lblGender->setObjectName(QStringLiteral("lblGender"));
        lblGender->setGeometry(QRect(10, 170, 47, 13));
        lblGender->setFont(font);
        lblDOB = new QLabel(DeleteProf);
        lblDOB->setObjectName(QStringLiteral("lblDOB"));
        lblDOB->setGeometry(QRect(10, 140, 47, 13));
        lblDOB->setFont(font);
        lblDOB->setFrameShape(QFrame::NoFrame);
        lblStudentNoText = new QLabel(DeleteProf);
        lblStudentNoText->setObjectName(QStringLiteral("lblStudentNoText"));
        lblStudentNoText->setGeometry(QRect(10, 210, 251, 21));
        lblName = new QLabel(DeleteProf);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(10, 110, 47, 13));
        lblName->setFont(font);
        lblDOBtext = new QLabel(DeleteProf);
        lblDOBtext->setObjectName(QStringLiteral("lblDOBtext"));
        lblDOBtext->setGeometry(QRect(10, 150, 251, 21));
        lblCourse = new QLabel(DeleteProf);
        lblCourse->setObjectName(QStringLiteral("lblCourse"));
        lblCourse->setGeometry(QRect(10, 230, 71, 16));
        lblCourse->setFont(font);
        cmdDelete = new QPushButton(DeleteProf);
        cmdDelete->setObjectName(QStringLiteral("cmdDelete"));
        cmdDelete->setGeometry(QRect(250, 160, 91, 41));
        txtIDNoDelete = new QLineEdit(DeleteProf);
        txtIDNoDelete->setObjectName(QStringLiteral("txtIDNoDelete"));
        txtIDNoDelete->setGeometry(QRect(200, 70, 41, 20));
        txtIDNoDelete->setMaxLength(4);

        retranslateUi(DeleteProf);

        QMetaObject::connectSlotsByName(DeleteProf);
    } // setupUi

    void retranslateUi(QDialog *DeleteProf)
    {
        DeleteProf->setWindowTitle(QApplication::translate("DeleteProf", "Dialog", Q_NULLPTR));
        cmdFindID->setText(QApplication::translate("DeleteProf", "Find Profile", Q_NULLPTR));
        lblEnterID->setText(QApplication::translate("DeleteProf", "Enter ID of Profile to delete:", Q_NULLPTR));
        lblCourseText->setText(QString());
        lblNameText->setText(QString());
        lblGenderText->setText(QString());
        lblStudentNo->setText(QApplication::translate("DeleteProf", "Student No:", Q_NULLPTR));
        lblGender->setText(QApplication::translate("DeleteProf", "Gender:", Q_NULLPTR));
        lblDOB->setText(QApplication::translate("DeleteProf", "DOB:", Q_NULLPTR));
        lblStudentNoText->setText(QString());
        lblName->setText(QApplication::translate("DeleteProf", "Name:", Q_NULLPTR));
        lblDOBtext->setText(QString());
        lblCourse->setText(QApplication::translate("DeleteProf", "Course:", Q_NULLPTR));
        cmdDelete->setText(QApplication::translate("DeleteProf", "Confirm Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeleteProf: public Ui_DeleteProf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPROF_H
