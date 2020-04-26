#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QTreeWidgetItem>
#include <QtCharts>
#include <QChartView>
#include<QPieSeries>
#include<QPieSlice>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

typedef struct node {
    char* name, *last_modified; // date the node is last modified
    long long size_sub_dirs; // The number of sub-directories a node has, 0 indicates it is a file not a directory
    long long size; // size of the node
    void ** sub_array; // points to an array of children, and has a value of NULL if the node is not a directory
} node_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QPieSeries* myseries = new QPieSeries();
    QFrame* frame = new QFrame();
    //Backend Functions
    long long get_size(const char* entry);
    void cmp_nodes(node_t* ptr_1, node_t* ptr_2);
    void bubble_sort(long long size, node_t* parent);
    int dir_entry_count(const char* directory);
    long long listdir(const char* name, node_t* parent, QTreeWidgetItem* Q_tree_ptr);
    int backMain(char* root);
    //Frontend Functions
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void AddRoot (QTreeWidgetItem* itm, QString name, QString size);
    void create_my_tree(node_t* parent, QTreeWidgetItem* Q_tree_ptr);
    void getseries(QPieSeries* s);
    void setseries(QTreeWidgetItem*);
    char* get_mod_time(const char* entry);

private slots:
    void on_actionExit_triggered();
    void quitApp();
    void on_actionAbout_triggered();
    void on_actionAnalyze_Home_triggered();
    void on_actionAnalyze_Folder_triggered();
    void on_directoryTree_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    void setupMainWindow();
};
#endif // MAINWINDOW_H
