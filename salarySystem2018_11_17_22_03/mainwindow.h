#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "setting.h"
#include "mtable.h"
//主界面
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void linkTableToTab();//将table与tab连接

private slots:
    void on_setting_clicked();      //设置按键 槽
    void do_setting_close();           //关闭设置窗口
    void on_input_clicked();        //导入按键 槽

private:
    Ui::MainWindow *ui;
    // QStringList input_filename;     // 导入文件名
    QStringList input_filename;     // 导入文件名
    MTable *table;                      //表格控件
    setting *mSetting;
    QVector<QWidget *> tab_of_table;        //存储要显示的不同表格,将表格封装在qwidget中, 不同 sheet 用 QVector 存放
};

#endif // MAINWINDOW_H
