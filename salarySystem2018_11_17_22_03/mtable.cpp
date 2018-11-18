#include "mtable.h"

MTable::MTable(QWidget *parent) :
    QWidget(parent)
{
    tableTitle<<"薪资总表"<<"一线员工"<<"考勤"<<"文职类"<<"绩效"<<"补助工时"<<"社保"<<"公积金";//默认表头

    //初始化表
    for(int i=0;i<tableTitle.size();i++)
    {
        QTableWidget *temp=new QTableWidget(30,20);
        temp->setEditTriggers(QAbstractItemView::NoEditTriggers);//数据不可修改
        mTable.append(temp);
    }

}

MTable::~MTable()
{
    //释放主要内存资源
    for(int i=0;i<mTable.size();i++)
    mTable.at(i)->deleteLater();

}

QStringList MTable::getTableTitle()
{
    return tableTitle;
}

QVector<QTableWidget *> MTable::getTable()
{
    return mTable;
}
