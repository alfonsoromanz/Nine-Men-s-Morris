/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    QPushButton *play;
    QComboBox *whitePlayerVirtuality;
    QComboBox *blackPlayerVirtuality;
    QSpinBox *whitePlayerDeep;
    QSpinBox *blackPlayerDeep;
    QSpinBox *whitePlayerHeuristic;
    QSpinBox *blackPlayerHeuristic;
    QLabel *label;
    QComboBox *starterPlayer;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 600);
        MainMenu->setStyleSheet(QStringLiteral("background-image:url(\":/main_menu_background.png\");"));
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(700, 560, 75, 23));
        play->setStyleSheet(QStringLiteral("background:auto;"));
        play->setAutoDefault(false);
        play->setDefault(true);
        play->setFlat(false);
        whitePlayerVirtuality = new QComboBox(centralWidget);
        whitePlayerVirtuality->setObjectName(QStringLiteral("whitePlayerVirtuality"));
        whitePlayerVirtuality->setGeometry(QRect(480, 390, 171, 22));
        whitePlayerVirtuality->setStyleSheet(QStringLiteral("background:auto;"));
        blackPlayerVirtuality = new QComboBox(centralWidget);
        blackPlayerVirtuality->setObjectName(QStringLiteral("blackPlayerVirtuality"));
        blackPlayerVirtuality->setGeometry(QRect(480, 510, 171, 22));
        blackPlayerVirtuality->setStyleSheet(QStringLiteral("background:auto;"));
        whitePlayerDeep = new QSpinBox(centralWidget);
        whitePlayerDeep->setObjectName(QStringLiteral("whitePlayerDeep"));
        whitePlayerDeep->setGeometry(QRect(730, 390, 42, 22));
        whitePlayerDeep->setStyleSheet(QStringLiteral("background:auto;"));
        whitePlayerDeep->setMinimum(1);
        whitePlayerDeep->setMaximum(6);
        whitePlayerDeep->setValue(1);
        blackPlayerDeep = new QSpinBox(centralWidget);
        blackPlayerDeep->setObjectName(QStringLiteral("blackPlayerDeep"));
        blackPlayerDeep->setGeometry(QRect(730, 510, 42, 22));
        blackPlayerDeep->setStyleSheet(QStringLiteral("background:auto;"));
        blackPlayerDeep->setMinimum(1);
        blackPlayerDeep->setMaximum(6);
        blackPlayerDeep->setSingleStep(1);
        blackPlayerDeep->setValue(1);
        whitePlayerHeuristic = new QSpinBox(centralWidget);
        whitePlayerHeuristic->setObjectName(QStringLiteral("whitePlayerHeuristic"));
        whitePlayerHeuristic->setGeometry(QRect(670, 390, 42, 22));
        whitePlayerHeuristic->setStyleSheet(QStringLiteral("background:auto;"));
        whitePlayerHeuristic->setMinimum(1);
        whitePlayerHeuristic->setMaximum(3);
        blackPlayerHeuristic = new QSpinBox(centralWidget);
        blackPlayerHeuristic->setObjectName(QStringLiteral("blackPlayerHeuristic"));
        blackPlayerHeuristic->setGeometry(QRect(670, 510, 42, 22));
        blackPlayerHeuristic->setStyleSheet(QStringLiteral("background:auto;"));
        blackPlayerHeuristic->setMinimum(1);
        blackPlayerHeuristic->setMaximum(3);
        blackPlayerHeuristic->setValue(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 564, 46, 13));
        starterPlayer = new QComboBox(centralWidget);
        starterPlayer->setObjectName(QStringLiteral("starterPlayer"));
        starterPlayer->setGeometry(QRect(500, 560, 171, 22));
        starterPlayer->setStyleSheet(QStringLiteral("background:auto;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 370, 81, 16));
        QFont font;
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 370, 51, 16));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(730, 370, 61, 16));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 490, 81, 16));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setFrameShadow(QFrame::Plain);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(670, 490, 51, 16));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setFrameShadow(QFrame::Plain);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(730, 490, 61, 16));
        label_7->setFont(font);
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setFrameShadow(QFrame::Plain);
        MainMenu->setCentralWidget(centralWidget);

        retranslateUi(MainMenu);

        whitePlayerVirtuality->setCurrentIndex(0);
        blackPlayerVirtuality->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", 0));
        play->setText(QApplication::translate("MainMenu", "Jugar", 0));
        whitePlayerVirtuality->clear();
        whitePlayerVirtuality->insertItems(0, QStringList()
         << QApplication::translate("MainMenu", "Humano", 0)
         << QApplication::translate("MainMenu", "Virtual", 0)
        );
        blackPlayerVirtuality->clear();
        blackPlayerVirtuality->insertItems(0, QStringList()
         << QApplication::translate("MainMenu", "Humano", 0)
         << QApplication::translate("MainMenu", "Virtual", 0)
        );
        blackPlayerVirtuality->setCurrentText(QApplication::translate("MainMenu", "Virtual", 0));
        label->setText(QApplication::translate("MainMenu", "Empieza:", 0));
        starterPlayer->clear();
        starterPlayer->insertItems(0, QStringList()
         << QApplication::translate("MainMenu", "Blanco", 0)
         << QApplication::translate("MainMenu", "Fucsia", 0)
        );
        starterPlayer->setCurrentText(QApplication::translate("MainMenu", "Blanco", 0));
        label_2->setText(QApplication::translate("MainMenu", "Tipo de jugador", 0));
        label_3->setText(QApplication::translate("MainMenu", "Heur\303\255stica", 0));
        label_4->setText(QApplication::translate("MainMenu", "Profundidad", 0));
        label_5->setText(QApplication::translate("MainMenu", "Tipo de jugador", 0));
        label_6->setText(QApplication::translate("MainMenu", "Heur\303\255stica", 0));
        label_7->setText(QApplication::translate("MainMenu", "Profundidad", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
