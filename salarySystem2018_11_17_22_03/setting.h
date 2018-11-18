#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();

private slots:
    void on_no_clicked();

private:
    Ui::setting *ui;

signals:
    void setting_close();
};

#endif // SETTING_H
