#ifndef MTABLE_H
#define MTABLE_H

#include <QWidget>
#include <QTableWidget>


class MTable : public QWidget
{
    Q_OBJECT

public:
    explicit MTable(QWidget *parent = 0);
    ~MTable();
    QStringList getTableTitle();
    QVector<QTableWidget *> getTable();

private:
    QVector<QTableWidget *> mTable;//与tab界面相对应
    QStringList tableTitle;
};

#endif // MTABLE_H
