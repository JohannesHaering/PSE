#include "classificationresultrenderer.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include "classprobability.h"
#include <QPixmap>
#include "classificationresult.h"
#include <QtCharts/QChartView>
#include <QMainWindow>
#include <QMessageBox>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
ClassificationResultRenderer::ClassificationResultRenderer()
{

}
QPixmap ClassificationResultRenderer::drawGraphic(ClassificationResult result){
    QChartView* chartView = new QChartView;
    QBarSeries series;
    QStringList categories;
    QChart *chart = new QChart();
    QBarSet *barSet = new QBarSet("");
    std::list<ClassProbability> probList = result.getProbabilities();
    for (std::list<ClassProbability>::iterator it = probList.begin(); it != probList.end(); ++it){
        *barSet<<it->getProbability();
        categories<<QString::fromStdString(it->getClassName());
    }
    series.append(barSet);
    chart->addSeries(&series);
    chart->setTitle("Probabilities");
    QColor color(Qt::GlobalColor::darkCyan);
    barSet->setColor(color);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series.attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series.attachAxis(axisY);
    chartView->setChart(chart);
    chart->legend()->setVisible(false);
    QPixmap p(chartView->size());
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->QWidget::render(&p);
    return p;
}
