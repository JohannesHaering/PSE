#include "TrainingRenderer.hpp"
#include <QPixmap>
#include <QtCharts/QSplineSeries>
#include <QtCharts>
TrainingRenderer::TrainingRenderer()
{

}
QPixmap TrainingRenderer::drawGraphic(std::vector<float> pointsArrayTest, std::vector<float> pointsArrayTraining){
    QSplineSeries *series = new QSplineSeries();
    series->setName("Test Accuracy");
    int width = 1000;
    int i = 0;
    QSplineSeries *seriesTraining = new QSplineSeries();
    seriesTraining->setName("Training Accuracy");
    seriesTraining->setColor(Qt::green);
    series->setColor(Qt::red);
    for(std::vector<float>::iterator it = pointsArrayTest.begin(); it != pointsArrayTest.end(); ++it) {
        i++;
        QPoint point(i*(width/(pointsArrayTest.size() + 1)),*it * 100);
        series->append(point);
    }
    int j = 0;
    for(std::vector<float>::iterator it = pointsArrayTraining.begin(); it != pointsArrayTraining.end(); ++it) {
        j++;
        QPoint point(j*(width/(pointsArrayTraining.size() + 1)), *it * 100);
        seriesTraining->append(point);
    }
    QChartView* chartView = new QChartView();
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(seriesTraining);
    chart->setTitle("Learning Progress");
    chart->legend()->setVisible(true);
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(0,width);
    chart->addAxis(axisX, Qt::AlignBottom);
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    chartView->setChart(chart);
    QPixmap p(chartView->size());
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->QWidget::render(&p);
    return p;
}
