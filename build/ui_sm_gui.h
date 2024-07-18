/********************************************************************************
** Form generated from reading UI file 'sm_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SM_GUI_H
#define UI_SM_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rqt_sm_gui/ratio_layouted_frame.h"

QT_BEGIN_NAMESPACE

class Ui_SMGUIInterface
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *image_layout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_4;
    rqt_sm_gui::RatioLayoutedFrame *image_frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;

    void setupUi(QWidget *SMGUIInterface)
    {
        if (SMGUIInterface->objectName().isEmpty())
            SMGUIInterface->setObjectName(QString::fromUtf8("SMGUIInterface"));
        SMGUIInterface->resize(634, 394);
        layoutWidget = new QWidget(SMGUIInterface);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 20, 391, 301));
        image_layout = new QHBoxLayout(layoutWidget);
        image_layout->setSpacing(0);
        image_layout->setObjectName(QString::fromUtf8("image_layout"));
        image_layout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 389, 299));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(1, 1, 1, 1);
        image_frame = new rqt_sm_gui::RatioLayoutedFrame(scrollAreaWidgetContents);
        image_frame->setObjectName(QString::fromUtf8("image_frame"));
        sizePolicy.setHeightForWidth(image_frame->sizePolicy().hasHeightForWidth());
        image_frame->setSizePolicy(sizePolicy);
        image_frame->setMinimumSize(QSize(80, 60));
        image_frame->setContextMenuPolicy(Qt::ActionsContextMenu);
        image_frame->setFrameShape(QFrame::NoFrame);
        image_frame->setLineWidth(1);

        horizontalLayout_4->addWidget(image_frame);

        scrollArea->setWidget(scrollAreaWidgetContents);

        image_layout->addWidget(scrollArea);

        verticalLayoutWidget = new QWidget(SMGUIInterface);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 151, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);
        radioButton_2->setAutoExclusive(true);

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(false);

        verticalLayout->addWidget(radioButton_3);

        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(false);
        radioButton->setAutoExclusive(true);

        verticalLayout->addWidget(radioButton);

        radioButton_5 = new QRadioButton(verticalLayoutWidget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setChecked(false);

        verticalLayout->addWidget(radioButton_5);

        radioButton_4 = new QRadioButton(verticalLayoutWidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        radioButton_6 = new QRadioButton(verticalLayoutWidget);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        verticalLayout->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(verticalLayoutWidget);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        verticalLayout->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(verticalLayoutWidget);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        verticalLayout->addWidget(radioButton_8);


        retranslateUi(SMGUIInterface);

        QMetaObject::connectSlotsByName(SMGUIInterface);
    } // setupUi

    void retranslateUi(QWidget *SMGUIInterface)
    {
        SMGUIInterface->setWindowTitle(QCoreApplication::translate("SMGUIInterface", "SM Interface", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SMGUIInterface", "Camera 1", nullptr));
        radioButton_3->setText(QCoreApplication::translate("SMGUIInterface", "Camera 2", nullptr));
        radioButton->setText(QCoreApplication::translate("SMGUIInterface", "Camera 3", nullptr));
        radioButton_5->setText(QCoreApplication::translate("SMGUIInterface", "Camera 4", nullptr));
        radioButton_4->setText(QCoreApplication::translate("SMGUIInterface", "Camera 5", nullptr));
        radioButton_6->setText(QCoreApplication::translate("SMGUIInterface", "Camera 6", nullptr));
        radioButton_7->setText(QCoreApplication::translate("SMGUIInterface", "Realsense colour", nullptr));
        radioButton_8->setText(QCoreApplication::translate("SMGUIInterface", "Realsense depth", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SMGUIInterface: public Ui_SMGUIInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SM_GUI_H
