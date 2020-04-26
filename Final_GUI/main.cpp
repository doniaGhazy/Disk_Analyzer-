#include "mainwindow.h"
#include <QApplication>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/new/prefix1/Icons/Main_icon.svg")); //setting application icon
    MainWindow w;
    w.backMain((char*)"/"); //analyzing the root directory
    QChart* chart = new QChart();
    chart->addSeries(w.myseries);
    chart->setTitle("Directory Analysis");
    chart->legend()->setAlignment(Qt::AlignRight);
    QChartView* view = new QChartView(chart);
    view->setRubberBand(QChartView::HorizontalRubberBand);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setParent(w.frame);
    w.show();
    return a.exec();
}
