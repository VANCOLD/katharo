#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_maintree_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QAction *newRule;
    QTreeWidgetItem *pGroup;
    QTreeWidgetItem *pAdd;
    QTreeWidgetItem *pSettings;

    QTreeWidgetItem *addTreeRoot(QString name, QString description);
    QTreeWidgetItem *addTreeChild(QTreeWidgetItem *parent,
                         QString name, QString description);
};

#endif // MAINWINDOW_H
