#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    delete ui->tab;
    delete ui->tab_2;
    mSetting=new setting();             //新建自定义  setting 类型
    connect(mSetting,SIGNAL(setting_close()),this,SLOT(do_setting_close()));  

    table=new MTable();     //新建表格
    linkTableToTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::linkTableToTab()
{
    QStringList title=table->getTableTitle();           //初始化表格
    QVector<QTableWidget *> tableWidget=table->getTable();

    QWidget *temp;              
    QVBoxLayout* temp_layout;               
    for(int i=0;i<title.size();i++)
    {
        temp=new QWidget();                     
        temp_layout=new QVBoxLayout(temp);
        tab_of_table.append(temp);
        tableWidget.at(i)->setParent(temp);
        temp_layout->addWidget(tableWidget.at(i));              //设置layout
        ui->tab_m->addTab(tab_of_table.at(i),title.at(i));
    }
}

void MainWindow::on_setting_clicked()
{

    mSetting->setWindowTitle("显示设置");
    mSetting->show();
}

void MainWindow::do_setting_close()
{
    mSetting->hide();               //关闭 setting 窗口
}

void MainWindow::on_input_clicked()
{
    input_filename=QFileDialog::getOpenFileNames(this,
                    tr("Open exel"), "/home", tr("excel Files (*.xl *.xls *.xlsx *.xlm)"));
    if(!input_filename.isEmpty())
    {

    }

}
