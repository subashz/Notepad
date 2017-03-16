#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionNew_Window_triggered();

    void on_actionOpen_triggered();

    void on_actionFont_triggered();

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void save_file(bool state);

    void read_file();

    void on_actionSave_As_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionDelete_triggered();

    void on_actionWord_Wrap_toggled(bool arg1);

private:
    Ui::MainWindow *ui;
    QString main_file;
};

#endif // MAINWINDOW_H
