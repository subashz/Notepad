#ifndef GUIWINDOW_H
#define GUIWINDOW_H
#include <QtCore>
#include <QtWidgets>

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

    void on_actionUndo_triggered();

    void on_plainTextEdit_cursorPositionChanged();

    void on_actionStatus_Bar_toggled(bool arg1);

    void on_actionGo_To_triggered();

    void on_actionSelect_All_triggered();

private:
    Ui::MainWindow *ui;
    QString main_file;
    QLabel *LineNumber;
};

#endif // GUIWINDOW_H
