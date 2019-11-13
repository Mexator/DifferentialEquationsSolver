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
#include <QtWidgets/QGraphicsView>
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
    QHBoxLayout *horizontalLayout_5;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QGroupBox *InitBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *x0;
    QLineEdit *x0Edit;
    QLabel *y0;
    QLineEdit *y0Edit;
    QLabel *X;
    QLineEdit *XEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *radioBtns;
    QRadioButton *solutionsRBtn;
    QRadioButton *localErrorsRBtn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *GridBox;
    QVBoxLayout *verticalLayout;
    QLabel *GridSize;
    QLineEdit *GridCountEdit;
    QLabel *GridStep;
    QLineEdit *GridStepEdit;
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
        horizontalLayout_5 = new QHBoxLayout(ExactTab);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        graphicsView = new QGraphicsView(ExactTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_5->addWidget(graphicsView);

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
        x0 = new QLabel(InitBox);
        x0->setObjectName(QString::fromUtf8("x0"));

        horizontalLayout_2->addWidget(x0);

        x0Edit = new QLineEdit(InitBox);
        x0Edit->setObjectName(QString::fromUtf8("x0Edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(x0Edit->sizePolicy().hasHeightForWidth());
        x0Edit->setSizePolicy(sizePolicy1);
        x0Edit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(x0Edit);

        y0 = new QLabel(InitBox);
        y0->setObjectName(QString::fromUtf8("y0"));
        sizePolicy.setHeightForWidth(y0->sizePolicy().hasHeightForWidth());
        y0->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(y0);

        y0Edit = new QLineEdit(InitBox);
        y0Edit->setObjectName(QString::fromUtf8("y0Edit"));
        sizePolicy1.setHeightForWidth(y0Edit->sizePolicy().hasHeightForWidth());
        y0Edit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(y0Edit);

        X = new QLabel(InitBox);
        X->setObjectName(QString::fromUtf8("X"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(X->sizePolicy().hasHeightForWidth());
        X->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(X);

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


        horizontalLayout->addLayout(radioBtns);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        GridBox = new QGroupBox(centralwidget);
        GridBox->setObjectName(QString::fromUtf8("GridBox"));
        GridBox->setMinimumSize(QSize(200, 0));
        GridBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(GridBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        GridSize = new QLabel(GridBox);
        GridSize->setObjectName(QString::fromUtf8("GridSize"));

        verticalLayout->addWidget(GridSize);

        GridCountEdit = new QLineEdit(GridBox);
        GridCountEdit->setObjectName(QString::fromUtf8("GridCountEdit"));

        verticalLayout->addWidget(GridCountEdit);

        GridStep = new QLabel(GridBox);
        GridStep->setObjectName(QString::fromUtf8("GridStep"));

        verticalLayout->addWidget(GridStep);

        GridStepEdit = new QLineEdit(GridBox);
        GridStepEdit->setObjectName(QString::fromUtf8("GridStepEdit"));

        verticalLayout->addWidget(GridStepEdit);


        horizontalLayout->addWidget(GridBox);


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
        x0->setText(QCoreApplication::translate("MainWindow", "x0:", nullptr));
        x0Edit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        y0->setText(QCoreApplication::translate("MainWindow", "y0:", nullptr));
        y0Edit->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        X->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        XEdit->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        solutionsRBtn->setText(QCoreApplication::translate("MainWindow", "Solutions", nullptr));
        localErrorsRBtn->setText(QCoreApplication::translate("MainWindow", "Local Errors", nullptr));
        GridBox->setTitle(QCoreApplication::translate("MainWindow", "Grid settings", nullptr));
        GridSize->setText(QCoreApplication::translate("MainWindow", "Grid steps number", nullptr));
        GridCountEdit->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        GridStep->setText(QCoreApplication::translate("MainWindow", "Grid step size", nullptr));
        GridStepEdit->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
