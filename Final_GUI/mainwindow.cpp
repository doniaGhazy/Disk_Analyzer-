//headers
#include "aboutdialog.h"
#include "exit_dialog.h"
#include "mainwindow.h"
#include "select_dir.h"
#include "ui_mainwindow.h"

//Qt environment includes
#include <QApplication>
#include <QBrush>
#include <QBrushData>
#include <QCloseEvent>
#include <QDebug>
#include <QFileDialog>
#include <QLegend>
#include <QMessageBox>
#include <QProgressBar>
#include <QStyle>
#include <QTableWidget>
#include <QTimer>

//BackEnd includes
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

QPieSeries* series = new QPieSeries();
node_t* grand_parent_ptr;
QTreeWidgetItem* Q_ptr;
int count = 0;

// This function sets up the main window of the GUI and the texts of the columns of the QTreeWidget
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMainWindow();
    ui->directoryTree->setColumnCount(5);
    ui->directoryTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    if(QTreeWidgetItem* header = ui->directoryTree->headerItem())
    {
        header->setText(0, "Name");
        header->setText(1, "Size");
        header->setText(2, "Usage Percentage");
        header->setText(3, "Usage Bar");
        header->setText(4, "Last Modified");
    }
    else
    {
        ui->directoryTree->setHeaderLabel("Name");
        ui->directoryTree->setHeaderLabel("Size");
        ui->directoryTree->setHeaderLabel("Usage Percentage");
        ui->directoryTree->setHeaderLabel("Usage Bar");
        ui->directoryTree->setHeaderLabel("Last Modified");
    }
    frame = ui->chartFrame;
}

// This function returns the size of an entry (a path)
long long MainWindow::get_size(const char* entry)
{
    struct stat entry_stat;
    stat(entry, &entry_stat);
    return (long long)(entry_stat.st_size);
}

// This function swaps two nodes if the first is smaller than the second
void MainWindow::cmp_nodes(node_t* ptr_1, node_t* ptr_2)
{
    node_t swap;
    if(ptr_1->size < ptr_2->size)
    {
        swap = *ptr_1;
        *ptr_1 = *ptr_2;
        *ptr_2 = swap;
    }
    return;
}

// This function utilizes the cmp_nodes() function to sort the children nodes of a given parent node in an ascending order
void MainWindow::bubble_sort(long long size, node_t* parent)
{
    for (int x_idx = 0; x_idx < size; x_idx++)
        for (int y_idx = 0; y_idx < size - 1; y_idx++)
            cmp_nodes((node_t*)parent->sub_array[y_idx], (node_t*)parent->sub_array[y_idx+1]);
}

// This function returns the number of subdirectories/files a given directory has
int MainWindow::dir_entry_count(const char* directory)
{
    DIR* dir_handle = opendir(directory);
    if (dir_handle == NULL) //cannot open directory
    {
        printf("Cannot open directory \"%s\"\n", directory);
        return -1;
    }
    int count = 0;
    struct dirent* file_dirent;
    char* entry_name;
    while ((file_dirent = readdir(dir_handle)) != NULL)
    {
        entry_name = file_dirent->d_name;
        // The "." directory refers to the same directory and the ".." directory refers to the parent directory
        // Thus, both should not count towards the count of the files of the current directory
        if (strcmp(file_dirent->d_name, ".") != 0 && strcmp(file_dirent->d_name, "..") != 0 && strlen(entry_name) > 0)
            count++;
    }
    closedir(dir_handle);
    return count;
}

// Given a parent node, this function recursively builds a tree of the children nodes below it; it also returns the size of the given parent node
long long MainWindow::listdir(const char* name, node_t* parent, QTreeWidgetItem* Q_tree_ptr)
{
    char path[1024];
    int no_sub_dir;
    int counter = 0;
    // size refers to the size of the PARENT directory, it is the summation of all sizes of all entries
    long long size = 0;
    // this_file_size refers to the size of a single file, not a directory
    long long this_file_size = 0;
    // this_dir_size is the size of a CHILD directory
    long long this_dir_size = 0;
    DIR* dir;
    struct dirent* entry;
    node_t* temp_node;
    if (!(dir = opendir(name))) // check if the parent is a directory
        return 0;
    while ((entry = readdir(dir)) != NULL) // entry stores the sub-directory; each iteration for this loop, a new node is created with a sub_directory/file
    {
        //A new node is created in memory, the type cast of (node_t *) is important since malloc can return a void pointer
        temp_node = (node_t*)malloc(sizeof(node_t));
        //The c string name attribute should be allocated in the memory with its length and an additional character for the null character
        temp_node->name = (char*)malloc(strlen(entry->d_name) + 1);
        strcpy(temp_node->name, entry->d_name);
        //snprint has almost a concatenating job, it doesn't print anything on the screen, this line creates the full path (not just the name of the entry)
        snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
        if (entry->d_type == DT_DIR) //DT_DIR is the type of a directory, if d_type has this value, this node is a directory not a file
        {
            // The "." and the ".." directories are hidden recursive directories that should be ignored
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            // The number of sub_directories/files the directory has
            no_sub_dir = dir_entry_count(path);
            // The memory allocation of the array that has pointers to the children of the node
            temp_node->sub_array = (void**)malloc(sizeof(void *)*no_sub_dir);
            // setting the number of files and the last modifed time of the directory
            temp_node->size_sub_dirs= no_sub_dir;
            temp_node->last_modified = get_mod_time(path);
            // The recursive call, this call returns the size of the directory
            this_dir_size = listdir(path, temp_node, Q_tree_ptr);
            size+= this_dir_size;
        }
        else
        {
            this_file_size =get_size(path);
            size+= this_file_size; // for each file and for each directory, the size is added to the variable "size", this variable stores the total size of the parent
            temp_node->size_sub_dirs = 0; // indicates that this is a file, not a directory
            // setting the size and last modified time of the file
            temp_node->size = this_file_size;
            temp_node->last_modified = get_mod_time(path);
            temp_node->sub_array = NULL; // indicates that this is a file, not a directory
        }
        // In each iteration, the child pointer is set to point to the pointer of the temp_node
        // The (void*) is necessary since temp_node has a type of node_t * while an element in the sub-array has a type of void*
        parent->sub_array[counter] = (void*)temp_node;
        counter++;
    }
    parent->size = size; // This size is set in the end after all iterations.
    bubble_sort(parent->size_sub_dirs, parent); // The chilren array is sorted in the end after all nodes are entered successfully
    closedir(dir);
    return size;
}

// Given a parent node, this function utilizes the tree built from the listdir() function and builds the correpsonding tree on the QTreeWidget in a recursive manner
void MainWindow::create_my_tree(node_t* parent, QTreeWidgetItem* Q_tree_ptr)
{
    float percentage;
    if(parent->sub_array == NULL) // if a given parent node has no children nodes
        return;
    node_t* temp_node;
    /*
     * for a given parent node, iterate over its children nodes, and for each child node, display its name, size,
     * how much space do they take out of the parent node (both in text and in a progress bar view), and its last modified time.
    */
    for(int i = 0; i < parent->size_sub_dirs; i++)
    {
        QTreeWidgetItem* temp_qt_ptr = new QTreeWidgetItem();
        temp_node = (node_t*)parent->sub_array[i];
        temp_qt_ptr->setText(0, temp_node->name);
        long long size = temp_node->size;
        if (size < 1024)
            temp_qt_ptr->setText(1, (QString::number(size) + "B"));
        else if (size < 1024 * 1024)
        {
            size = (int)(size * 100 + .5) / float(100 * 1024);
            temp_qt_ptr->setText(1, (QString::number(size) + "KB"));
        }
        else if (size < 1024 * 1024 * 1024)
        {
            float sizef = (long long)(size + .5) / float(1024 * 1024);
            sizef = (int)(sizef * 100 + .5) / float(100);
            temp_qt_ptr->setText(1, (QString::number(sizef) + "MB"));
        }
        else
        {
            float sizef = (long long)(size + .5) / float(1024 * 1024);
            sizef /= 1024;
            sizef = (long long)(sizef * 100 + .5) / float(100);
            temp_qt_ptr->setText(1, (QString::number(sizef) + "GB"));
        }
        percentage = 100 * float(temp_node->size) / parent->size;
        percentage = (int)(percentage * 100 + .5) / float(100);
        temp_qt_ptr->setText(2, (QString::number(percentage) + "%"));
        Q_tree_ptr->addChild(temp_qt_ptr);
        QProgressBar *progressBar = new QProgressBar();
        progressBar->setValue(int(percentage + 0.5));
        progressBar->setTextVisible(true);
        ui->directoryTree->setItemWidget(temp_qt_ptr, 3, progressBar);
        temp_qt_ptr->setText(4, QString(temp_node->last_modified));
        create_my_tree(temp_node, temp_qt_ptr);
    }
}

// This function sets the QPieSeries for a given QTreeWidgetItem (which corresponds to a node) based on its children sizes
void MainWindow::setseries(QTreeWidgetItem* Q_tree_ptr)
{
    for(int i = 0; i < Q_tree_ptr->childCount(); i++)
     {
         QTreeWidgetItem* child = new QTreeWidgetItem();
         child = Q_tree_ptr->child(i);
         QString size = child->text(2).remove(child->text(2).length()-1 ,1 );
         float size_float = size.toFloat();
         int size_int = size_float;
         series->append(child->text(0), size_int );
         count++;
     }
    QPieSlice* slice =  series->slices().first();
    if(slice->angleSpan() > 10)
        slice->setLabelVisible(true);
    slice->setLabelPosition(QPieSlice::LabelInsideNormal);
    slice->setPen((QPen(Qt::black,1)));
    slice->setBrush(Qt::yellow);
    slice->setExploded(true);
    // choice is for the choice of the color of the slices
    int choice = 4;
    for (int i = 1; i < series->count(); i++)
    {
        QPieSlice* slice = series->slices().at(i);
         if(slice->angleSpan() > 10)
             slice->setLabelVisible(true);
         slice->setLabelPosition(QPieSlice::LabelInsideNormal);
         slice->setPen((QPen(Qt::black,1)));
         slice->setBrush((Qt::GlobalColor)choice);
         choice++;
         choice = choice % 12 + 4;
    }
    myseries = series;
}

// This function returns the last modified time of an entry (a path)
char* MainWindow::get_mod_time(const char* entry)
{
    struct stat attrib;
    stat(entry, &attrib);
    char* time = new char();
    strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
    return time;
}

// For a given directory, this is the main function from which the tree of the nodes of this directory is build by calling the listdir() function,
// and its tree view is built by calling the create_my_tree() function
int MainWindow::backMain(char* root)
{
    node_t grand_parent;
    grand_parent_ptr = &grand_parent;
    ui->directoryTree->clear();
    QTreeWidgetItem* Q_tree_ptr = new QTreeWidgetItem();
    Q_ptr = Q_tree_ptr;
    int s = dir_entry_count(root); // points to the current directory
    grand_parent.size_sub_dirs = s; // As assumed above, the size_sub_dirs and the name attributes of the node msut be set before calling the function
    grand_parent.sub_array = (void**)malloc(sizeof(void *)*s);
    grand_parent.name = (char*)malloc(strlen(root)+1);
    AddRoot(Q_tree_ptr, grand_parent.name, 0);
    strcpy(grand_parent.name, root);
    long long final_size = listdir(root, &grand_parent, Q_tree_ptr);
    if (final_size < 1024)
        AddRoot(Q_tree_ptr, grand_parent.name, QString::number(final_size) + "B");
    else if(final_size < 1024 * 1024)
    {
        final_size = (int)(final_size * 100 + .5) / float(100 * 1024);
        AddRoot(Q_tree_ptr, grand_parent.name, QString::number(final_size) + "KB");
    }
    else if(final_size < 1024 * 1024 * 1024)
    {
        float sizef = (long long)(final_size + .5) / float(1024 * 1024);
        sizef = (int)(sizef * 100 + .5) / float(100);
        AddRoot(Q_tree_ptr, grand_parent.name, QString::number(sizef) + "MB");
    }
    else
    {
        float sizef = (long long)(final_size + .5) / float(1024 * 1024);
        sizef /= 1024;
        sizef = (long long)(sizef * 100 + .5) / float(100);
        AddRoot(Q_tree_ptr, grand_parent.name, QString::number(sizef) + "GB");
    }
    create_my_tree(&grand_parent, Q_tree_ptr);
    setseries(Q_tree_ptr);
    return 0;
}

// This function sets the name and size of the folder chosen to be analyzed in the top row in the first two columns of the QTreeWidget
void MainWindow::AddRoot(QTreeWidgetItem* itm, QString name, QString size)
{
    itm->setText(0,name);
    itm->setText(1,size);
    ui->directoryTree->addTopLevelItem(itm);
}

// This function sets the menu bar to be not a native menubar
void MainWindow::setupMainWindow()
{
     menuBar()->setNativeMenuBar(false);
}

// This is a destructor for the main window
MainWindow::~MainWindow()
{
    delete ui;
}

// This function is triggered once the action button is pressed. It prompts a dialog to ask the user if he is sure he wants to exit or not
void MainWindow::on_actionExit_triggered()
{
    Exit_dialog* exit_ptr = new Exit_dialog(this);
    exit_ptr->setFixedSize(356,145);
    exit_ptr->exec();
}

// This function closes the application
void MainWindow::quitApp()
{
     QApplication::quit();
}

// This function is trigged when the about button is pressend; it prompts an about window that shows the names of the authors of the project
void MainWindow::on_actionAbout_triggered()
{
    aboutDialog* about_ptr = new aboutDialog(this);
    about_ptr->setFixedSize(403,315);
    about_ptr->exec();
}

// This function is triggered when the analyze home button is trigged; it analyzes the root directory
void MainWindow::on_actionAnalyze_Home_triggered()
{
    char* root = (char*)"/";
    myseries->clear();
    backMain(root);
}

// This function is triggered when the analyze folder button is triggered; it prompts the user the choose the folder to be analyzed
void MainWindow::on_actionAnalyze_Folder_triggered()
{
    myseries->clear();
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::DontUseNativeDialog, true);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    dialog.exec();
    QString qstr = dialog.directory().absolutePath();
    QByteArray ba = qstr.toLocal8Bit();
    char* directory = ba.data();
    backMain(directory);
}

// This function is prompted whenever the user selects (either by mouse or by moving up and down from the keyboard) a QTreeWidgetItem from the drawn tree on the GUI.
// The chart is at once updated to graphically view the content of the currently selected folder/file
void MainWindow::on_directoryTree_itemSelectionChanged()
{
    myseries->clear();
    QList<QTreeWidgetItem *> itemList;
    itemList = ui->directoryTree->selectedItems();
    foreach(QTreeWidgetItem *item, itemList)
    {
        if(item->childCount() != 0) // display the folder content
            setseries(item);
        else //display only the file name and size
        {
            myseries->append(item->text(0) + " with size " + item->text(1), 100);
            QPieSlice* slice =  series->slices().first();
            slice->setLabelVisible(true);
            slice->setLabelPosition(QPieSlice::LabelInsideNormal);
            slice->setPen((QPen(Qt::black,1)));
            slice->setBrush(Qt::GlobalColor::magenta);
        }
    }
}
