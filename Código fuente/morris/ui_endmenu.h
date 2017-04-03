/********************************************************************************
** Form generated from reading UI file 'endmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDMENU_H
#define UI_ENDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndMenu
{
public:
    QWidget *centralwidget;
    QPushButton *back;
    QPushButton *exit_button;
    QLabel *result;
    QLabel *title;

    void setupUi(QMainWindow *EndMenu)
    {
        if (EndMenu->objectName().isEmpty())
            EndMenu->setObjectName(QStringLiteral("EndMenu"));
        EndMenu->setWindowModality(Qt::NonModal);
        EndMenu->resize(800, 600);
        EndMenu->setStyleSheet(QStringLiteral("background:url(':/background.gif');"));
        centralwidget = new QWidget(EndMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 560, 81, 23));
        back->setStyleSheet(QStringLiteral("background:auto;"));
        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(700, 560, 75, 23));
        exit_button->setStyleSheet(QStringLiteral("background:auto;"));
        result = new QLabel(centralwidget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(10, 210, 771, 121));
        result->setStyleSheet(QLatin1String("font-size:48pt;\n"
"color:#fff;\n"
"font-family:\"AngryBirds\";"));
        result->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        title = new QLabel(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(140, 20, 521, 81));
        title->setStyleSheet(QLatin1String("font-size:48pt;\n"
"color:#000;\n"
"font-family:\"AngryBirds\";"));
        title->setAlignment(Qt::AlignCenter);
        EndMenu->setCentralWidget(centralwidget);

        retranslateUi(EndMenu);

        QMetaObject::connectSlotsByName(EndMenu);
    } // setupUi

    void retranslateUi(QMainWindow *EndMenu)
    {
        EndMenu->setWindowTitle(QApplication::translate("EndMenu", "EndMenu", 0));
        back->setText(QApplication::translate("EndMenu", "Volver al Men\303\272", 0));
        exit_button->setText(QApplication::translate("EndMenu", "Salir", 0));
        result->setText(QApplication::translate("EndMenu", "Ha ganado el jugador Blanco", 0));
        title->setText(QApplication::translate("EndMenu", "Nine men's Morris", 0));
    } // retranslateUi

};

namespace Ui {
    class EndMenu: public Ui_EndMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDMENU_H
