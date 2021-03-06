#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#define scaleAQI  1
#include <QWidget>
#include <QtCharts>


namespace Ui {
class mainWidget;
}

//QT_CHARTS_BEGIN_NAMESPACE
//class QLineSeries;
//class QValueAxis;
//class QCharts;
//QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class dataWorker;
class QDateTime;

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

protected:
    void resetChart(const QString &title);
    void initComboMonth();
    void initComboCity();    
    void addLineSeries(QChart* chart, const QString &seriesName, const QColor color, const int lineWidth=1,const int minY=-5,const int maxY=40);      // 向Chart中添加序列（Series）
    void connectMarkers();          // 连接序列中所有Legend中Marker的信号与槽



private slots:
    void handleMarkerClicked();
    void on_btnStart_clicked();
    void updateDataChart(QList<QDateTime> date, QList<qreal> lineOne, QList<qreal> lineTwo);
    void on_cbShowPoint_clicked();
    void on_btnLegendAlign_clicked();
    void on_cbLegendBold_clicked();
    void on_cbLegendItalic_clicked();
    void on_rbSearchTemp_clicked();
    void on_rbSearchAQI_clicked();
    void on_dataError(QString error);

private:
    Ui::mainWidget *ui;
    dataWorker* worker;
    QStringList citypinyin,cities;


};

#endif // MAINWIDGET_H
