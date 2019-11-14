/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *PlotTab;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *PlotResetBtn;
    QWidget *TableTab;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tableView;
    QWidget *ExactTab;
    QHBoxLayout *horizontalLayout;
    QGroupBox *InitBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab2;
    QLineEdit *x0Edit;
    QLabel *lab3;
    QLineEdit *y0Edit;
    QLabel *lab1;
    QLineEdit *XEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *radioBtns;
    QRadioButton *solutionsRBtn;
    QRadioButton *localErrorsRBtn;
    QRadioButton *totalErrorsRBtn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *Grid;
    QVBoxLayout *verticalLayout;
    QLabel *GridSize;
    QLineEdit *GridCountEdit;
    QLabel *GridStep;
    QLineEdit *GridStepEdit;
    QGroupBox *totalGrid;
    QVBoxLayout *verticalLayout_4;
    QLabel *GridSize_2;
    QLineEdit *totalInitSteps;
    QLabel *GridStep_2;
    QLineEdit *totalFinStep;
    QLabel *GridSize_3;
    QLineEdit *totalStep;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(970, 631);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        PlotTab = new QWidget();
        PlotTab->setObjectName(QString::fromUtf8("PlotTab"));
        horizontalLayout_3 = new QHBoxLayout(PlotTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_2 = new QGroupBox(PlotTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(150, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        PlotResetBtn = new QPushButton(groupBox_2);
        PlotResetBtn->setObjectName(QString::fromUtf8("PlotResetBtn"));

        verticalLayout_3->addWidget(PlotResetBtn);


        horizontalLayout_6->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(horizontalLayout_6);

        tabWidget->addTab(PlotTab, QString());
        TableTab = new QWidget();
        TableTab->setObjectName(QString::fromUtf8("TableTab"));
        horizontalLayout_4 = new QHBoxLayout(TableTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tableView = new QTableView(TableTab);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_4->addWidget(tableView);

        tabWidget->addTab(TableTab, QString());
        ExactTab = new QWidget();
        ExactTab->setObjectName(QString::fromUtf8("ExactTab"));
        ExactTab->setEnabled(true);
        ExactTab->setAcceptDrops(false);
        tabWidget->addTab(ExactTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        InitBox = new QGroupBox(centralwidget);
        InitBox->setObjectName(QString::fromUtf8("InitBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InitBox->sizePolicy().hasHeightForWidth());
        InitBox->setSizePolicy(sizePolicy);
        InitBox->setMaximumSize(QSize(400, 500));
        horizontalLayout_2 = new QHBoxLayout(InitBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lab2 = new QLabel(InitBox);
        lab2->setObjectName(QString::fromUtf8("lab2"));

        horizontalLayout_2->addWidget(lab2);

        x0Edit = new QLineEdit(InitBox);
        x0Edit->setObjectName(QString::fromUtf8("x0Edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(x0Edit->sizePolicy().hasHeightForWidth());
        x0Edit->setSizePolicy(sizePolicy1);
        x0Edit->setMaximumSize(QSize(200, 16777215));
        x0Edit->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(x0Edit);

        lab3 = new QLabel(InitBox);
        lab3->setObjectName(QString::fromUtf8("lab3"));
        sizePolicy.setHeightForWidth(lab3->sizePolicy().hasHeightForWidth());
        lab3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lab3);

        y0Edit = new QLineEdit(InitBox);
        y0Edit->setObjectName(QString::fromUtf8("y0Edit"));
        sizePolicy1.setHeightForWidth(y0Edit->sizePolicy().hasHeightForWidth());
        y0Edit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(y0Edit);

        lab1 = new QLabel(InitBox);
        lab1->setObjectName(QString::fromUtf8("lab1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lab1->sizePolicy().hasHeightForWidth());
        lab1->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(lab1);

        XEdit = new QLineEdit(InitBox);
        XEdit->setObjectName(QString::fromUtf8("XEdit"));
        sizePolicy1.setHeightForWidth(XEdit->sizePolicy().hasHeightForWidth());
        XEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(XEdit);


        horizontalLayout->addWidget(InitBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioBtns = new QVBoxLayout();
        radioBtns->setObjectName(QString::fromUtf8("radioBtns"));
        solutionsRBtn = new QRadioButton(centralwidget);
        solutionsRBtn->setObjectName(QString::fromUtf8("solutionsRBtn"));
        solutionsRBtn->setChecked(true);

        radioBtns->addWidget(solutionsRBtn);

        localErrorsRBtn = new QRadioButton(centralwidget);
        localErrorsRBtn->setObjectName(QString::fromUtf8("localErrorsRBtn"));

        radioBtns->addWidget(localErrorsRBtn);

        totalErrorsRBtn = new QRadioButton(centralwidget);
        totalErrorsRBtn->setObjectName(QString::fromUtf8("totalErrorsRBtn"));

        radioBtns->addWidget(totalErrorsRBtn);


        horizontalLayout->addLayout(radioBtns);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Grid = new QGroupBox(centralwidget);
        Grid->setObjectName(QString::fromUtf8("Grid"));
        Grid->setMinimumSize(QSize(200, 0));
        Grid->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(Grid);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        GridSize = new QLabel(Grid);
        GridSize->setObjectName(QString::fromUtf8("GridSize"));

        verticalLayout->addWidget(GridSize);

        GridCountEdit = new QLineEdit(Grid);
        GridCountEdit->setObjectName(QString::fromUtf8("GridCountEdit"));

        verticalLayout->addWidget(GridCountEdit);

        GridStep = new QLabel(Grid);
        GridStep->setObjectName(QString::fromUtf8("GridStep"));

        verticalLayout->addWidget(GridStep);

        GridStepEdit = new QLineEdit(Grid);
        GridStepEdit->setObjectName(QString::fromUtf8("GridStepEdit"));

        verticalLayout->addWidget(GridStepEdit);


        horizontalLayout->addWidget(Grid);

        totalGrid = new QGroupBox(centralwidget);
        totalGrid->setObjectName(QString::fromUtf8("totalGrid"));
        totalGrid->setCheckable(false);
        verticalLayout_4 = new QVBoxLayout(totalGrid);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        GridSize_2 = new QLabel(totalGrid);
        GridSize_2->setObjectName(QString::fromUtf8("GridSize_2"));

        verticalLayout_4->addWidget(GridSize_2);

        totalInitSteps = new QLineEdit(totalGrid);
        totalInitSteps->setObjectName(QString::fromUtf8("totalInitSteps"));

        verticalLayout_4->addWidget(totalInitSteps);

        GridStep_2 = new QLabel(totalGrid);
        GridStep_2->setObjectName(QString::fromUtf8("GridStep_2"));

        verticalLayout_4->addWidget(GridStep_2);

        totalFinStep = new QLineEdit(totalGrid);
        totalFinStep->setObjectName(QString::fromUtf8("totalFinStep"));

        verticalLayout_4->addWidget(totalFinStep);

        GridSize_3 = new QLabel(totalGrid);
        GridSize_3->setObjectName(QString::fromUtf8("GridSize_3"));

        verticalLayout_4->addWidget(GridSize_3);

        totalStep = new QLineEdit(totalGrid);
        totalStep->setObjectName(QString::fromUtf8("totalStep"));

        verticalLayout_4->addWidget(totalStep);


        horizontalLayout->addWidget(totalGrid);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 970, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Plots", nullptr));
        PlotResetBtn->setText(QCoreApplication::translate("MainWindow", "Reset View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PlotTab), QCoreApplication::translate("MainWindow", "Plot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TableTab), QCoreApplication::translate("MainWindow", "Table", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ExactTab), QCoreApplication::translate("MainWindow", "Exact Solution", nullptr));
        InitBox->setTitle(QCoreApplication::translate("MainWindow", "Initial conditions", nullptr));
        lab2->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        x0Edit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lab3->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        y0Edit->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        lab1->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        XEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        solutionsRBtn->setText(QCoreApplication::translate("MainWindow", "Solutions", nullptr));
        localErrorsRBtn->setText(QCoreApplication::translate("MainWindow", "Local Errors", nullptr));
        totalErrorsRBtn->setText(QCoreApplication::translate("MainWindow", "Total Errors", nullptr));
        Grid->setTitle(QCoreApplication::translate("MainWindow", "Grid settings", nullptr));
        GridSize->setText(QCoreApplication::translate("MainWindow", "Grid steps number", nullptr));
        GridCountEdit->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        GridStep->setText(QCoreApplication::translate("MainWindow", "Grid step size", nullptr));
        GridStepEdit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        totalGrid->setTitle(QCoreApplication::translate("MainWindow", "Grid settings", nullptr));
        GridSize_2->setText(QCoreApplication::translate("MainWindow", "Initial Grid steps number", nullptr));
        totalInitSteps->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        GridStep_2->setText(QCoreApplication::translate("MainWindow", "Final Grid steps number", nullptr));
        totalFinStep->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        GridSize_3->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        totalStep->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
