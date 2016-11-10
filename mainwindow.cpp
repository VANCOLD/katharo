#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newrule->hide();

    pSettings = addTreeRoot("Settings","");
    pAdd = addTreeRoot("Add new rule...", "");
    pGroup = addTreeRoot("Add new group...","");

    addTreeRoot("",""); // Spacer
    addTreeRoot("",""); // Spacer


}

MainWindow::~MainWindow()
{
    delete ui;
}

QTreeWidgetItem *MainWindow::addTreeRoot(QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->maintree);

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    //addTreeChild(treeItem, name + "A", "Child_first");
    //addTreeChild(treeItem, name + "B", "Child_second");

    return treeItem;
}

QTreeWidgetItem *MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);

    return treeItem;
}


void MainWindow::on_maintree_itemClicked(QTreeWidgetItem *item, int column)
{
    /* Hide all windows */
    ui->newrule->hide();


    if (item == pAdd) {

        ui->newrule->show();
    }
}
