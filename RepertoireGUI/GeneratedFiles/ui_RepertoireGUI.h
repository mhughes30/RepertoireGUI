/********************************************************************************
** Form generated from reading UI file 'RepertoireGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPERTOIREGUI_H
#define UI_REPERTOIREGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RepertoireGUIClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelSongTable;
    QTableWidget *songTableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonDelete;
    QPushButton *buttonSaveToFile;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSongSize;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelCompoition;
    QTextEdit *textEditComposition;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelYear;
    QSpinBox *spinBoxYear;
    QVBoxLayout *verticalLayout_7;
    QLabel *labelComposer;
    QTextEdit *textEditComposer;
    QVBoxLayout *verticalLayout_12;
    QLabel *labelDuration;
    QTimeEdit *timeEditDuration;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelInstrument;
    QComboBox *boxInstrument;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelInstrumentation;
    QComboBox *boxInstrumentation;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelGenre;
    QComboBox *boxGenre;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelGuitarTune;
    QComboBox *boxGuitarTuning;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelGuitarCapo;
    QComboBox *boxGuitarCapo;
    QVBoxLayout *verticalLayout_11;
    QPushButton *buttonAdd;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonSave;

    void setupUi(QWidget *RepertoireGUIClass)
    {
        if (RepertoireGUIClass->objectName().isEmpty())
            RepertoireGUIClass->setObjectName(QStringLiteral("RepertoireGUIClass"));
        RepertoireGUIClass->resize(1063, 621);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RepertoireGUIClass->sizePolicy().hasHeightForWidth());
        RepertoireGUIClass->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(RepertoireGUIClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 0, 961, 451));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelSongTable = new QLabel(layoutWidget);
        labelSongTable->setObjectName(QStringLiteral("labelSongTable"));
        labelSongTable->setMidLineWidth(-1);
        labelSongTable->setTextFormat(Qt::RichText);
        labelSongTable->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelSongTable);

        songTableWidget = new QTableWidget(layoutWidget);
        songTableWidget->setObjectName(QStringLiteral("songTableWidget"));
        QFont font;
        font.setPointSize(10);
        songTableWidget->setFont(font);
        songTableWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 249, 215);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(192, 239, 255);"));
        songTableWidget->setSortingEnabled(true);
        songTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        songTableWidget->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout->addWidget(songTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonDelete = new QPushButton(layoutWidget);
        buttonDelete->setObjectName(QStringLiteral("buttonDelete"));
        buttonDelete->setMinimumSize(QSize(101, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        buttonDelete->setFont(font1);

        horizontalLayout->addWidget(buttonDelete);

        buttonSaveToFile = new QPushButton(layoutWidget);
        buttonSaveToFile->setObjectName(QStringLiteral("buttonSaveToFile"));
        buttonSaveToFile->setMinimumSize(QSize(101, 31));
        buttonSaveToFile->setFont(font1);

        horizontalLayout->addWidget(buttonSaveToFile);

        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelSongSize = new QLabel(layoutWidget);
        labelSongSize->setObjectName(QStringLiteral("labelSongSize"));
        labelSongSize->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(labelSongSize);

        horizontalSpacer_2 = new QSpacerItem(708, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(RepertoireGUIClass);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 450, 961, 16));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(4);
        line->setFrameShape(QFrame::HLine);
        layoutWidget1 = new QWidget(RepertoireGUIClass);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 470, 861, 101));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        labelCompoition = new QLabel(layoutWidget1);
        labelCompoition->setObjectName(QStringLiteral("labelCompoition"));

        verticalLayout_8->addWidget(labelCompoition);

        textEditComposition = new QTextEdit(layoutWidget1);
        textEditComposition->setObjectName(QStringLiteral("textEditComposition"));
        QFont font2;
        font2.setPointSize(9);
        textEditComposition->setFont(font2);

        verticalLayout_8->addWidget(textEditComposition);


        gridLayout->addLayout(verticalLayout_8, 0, 1, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        labelYear = new QLabel(layoutWidget1);
        labelYear->setObjectName(QStringLiteral("labelYear"));

        verticalLayout_9->addWidget(labelYear);

        spinBoxYear = new QSpinBox(layoutWidget1);
        spinBoxYear->setObjectName(QStringLiteral("spinBoxYear"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxYear->sizePolicy().hasHeightForWidth());
        spinBoxYear->setSizePolicy(sizePolicy1);
        spinBoxYear->setMinimumSize(QSize(89, 26));
        spinBoxYear->setMaximumSize(QSize(16777215, 26));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        spinBoxYear->setFont(font3);
        spinBoxYear->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(spinBoxYear);


        gridLayout->addLayout(verticalLayout_9, 0, 3, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        labelComposer = new QLabel(layoutWidget1);
        labelComposer->setObjectName(QStringLiteral("labelComposer"));

        verticalLayout_7->addWidget(labelComposer);

        textEditComposer = new QTextEdit(layoutWidget1);
        textEditComposer->setObjectName(QStringLiteral("textEditComposer"));
        textEditComposer->setFont(font2);

        verticalLayout_7->addWidget(textEditComposer);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        labelDuration = new QLabel(layoutWidget1);
        labelDuration->setObjectName(QStringLiteral("labelDuration"));

        verticalLayout_12->addWidget(labelDuration);

        timeEditDuration = new QTimeEdit(layoutWidget1);
        timeEditDuration->setObjectName(QStringLiteral("timeEditDuration"));
        timeEditDuration->setMinimumSize(QSize(89, 26));
        timeEditDuration->setFont(font3);
        timeEditDuration->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(timeEditDuration);


        gridLayout->addLayout(verticalLayout_12, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelInstrument = new QLabel(layoutWidget1);
        labelInstrument->setObjectName(QStringLiteral("labelInstrument"));
        labelInstrument->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelInstrument);

        boxInstrument = new QComboBox(layoutWidget1);
        boxInstrument->setObjectName(QStringLiteral("boxInstrument"));

        verticalLayout_2->addWidget(boxInstrument);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelInstrumentation = new QLabel(layoutWidget1);
        labelInstrumentation->setObjectName(QStringLiteral("labelInstrumentation"));
        labelInstrumentation->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelInstrumentation);

        boxInstrumentation = new QComboBox(layoutWidget1);
        boxInstrumentation->setObjectName(QStringLiteral("boxInstrumentation"));

        verticalLayout_3->addWidget(boxInstrumentation);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelGenre = new QLabel(layoutWidget1);
        labelGenre->setObjectName(QStringLiteral("labelGenre"));
        labelGenre->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelGenre);

        boxGenre = new QComboBox(layoutWidget1);
        boxGenre->setObjectName(QStringLiteral("boxGenre"));

        verticalLayout_4->addWidget(boxGenre);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        labelGuitarTune = new QLabel(layoutWidget1);
        labelGuitarTune->setObjectName(QStringLiteral("labelGuitarTune"));
        labelGuitarTune->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelGuitarTune);

        boxGuitarTuning = new QComboBox(layoutWidget1);
        boxGuitarTuning->setObjectName(QStringLiteral("boxGuitarTuning"));

        verticalLayout_5->addWidget(boxGuitarTuning);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        labelGuitarCapo = new QLabel(layoutWidget1);
        labelGuitarCapo->setObjectName(QStringLiteral("labelGuitarCapo"));
        labelGuitarCapo->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(labelGuitarCapo);

        boxGuitarCapo = new QComboBox(layoutWidget1);
        boxGuitarCapo->setObjectName(QStringLiteral("boxGuitarCapo"));

        verticalLayout_6->addWidget(boxGuitarCapo);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_10->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        buttonAdd = new QPushButton(layoutWidget1);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));
        buttonAdd->setMinimumSize(QSize(101, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        buttonAdd->setFont(font4);

        verticalLayout_11->addWidget(buttonAdd);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);

        buttonSave = new QPushButton(layoutWidget1);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));
        buttonSave->setMinimumSize(QSize(101, 41));
        buttonSave->setFont(font4);

        verticalLayout_11->addWidget(buttonSave);


        horizontalLayout_3->addLayout(verticalLayout_11);


        retranslateUi(RepertoireGUIClass);

        QMetaObject::connectSlotsByName(RepertoireGUIClass);
    } // setupUi

    void retranslateUi(QWidget *RepertoireGUIClass)
    {
        RepertoireGUIClass->setWindowTitle(QApplication::translate("RepertoireGUIClass", "Repertoire Manager ", Q_NULLPTR));
        labelSongTable->setText(QApplication::translate("RepertoireGUIClass", "Full Repertoire", Q_NULLPTR));
        buttonDelete->setText(QApplication::translate("RepertoireGUIClass", "Delete Song", Q_NULLPTR));
        buttonSaveToFile->setText(QApplication::translate("RepertoireGUIClass", "Save File", Q_NULLPTR));
        labelSongSize->setText(QString());
        labelCompoition->setText(QApplication::translate("RepertoireGUIClass", "Composition", Q_NULLPTR));
        labelYear->setText(QApplication::translate("RepertoireGUIClass", "Year", Q_NULLPTR));
        labelComposer->setText(QApplication::translate("RepertoireGUIClass", "Composer", Q_NULLPTR));
        labelDuration->setText(QApplication::translate("RepertoireGUIClass", "Duration", Q_NULLPTR));
        timeEditDuration->setDisplayFormat(QApplication::translate("RepertoireGUIClass", "mm:ss", Q_NULLPTR));
        labelInstrument->setText(QApplication::translate("RepertoireGUIClass", "Instrument", Q_NULLPTR));
        labelInstrumentation->setText(QApplication::translate("RepertoireGUIClass", "Instrumentation", Q_NULLPTR));
        labelGenre->setText(QApplication::translate("RepertoireGUIClass", "Genre", Q_NULLPTR));
        labelGuitarTune->setText(QApplication::translate("RepertoireGUIClass", "Guitar Tuning", Q_NULLPTR));
        labelGuitarCapo->setText(QApplication::translate("RepertoireGUIClass", "Guitar Capo", Q_NULLPTR));
        buttonAdd->setText(QApplication::translate("RepertoireGUIClass", "Add Song", Q_NULLPTR));
        buttonSave->setText(QApplication::translate("RepertoireGUIClass", "Save List", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RepertoireGUIClass: public Ui_RepertoireGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPERTOIREGUI_H
