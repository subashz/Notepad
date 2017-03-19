#include "gotodialog.h"
#include "notepad.h"
#include "ui_notepad.h"
#include <QFontDialog>
#include <QFileDialog>
#include <QFile>
#include <qDebug>
#include <QTextStream>
#include <QString>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);

    LineNumber = new QLabel(this);
    ui->statusBar->addPermanentWidget(LineNumber);

    // defaults
    ui->plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
    ui->plainTextEdit->setFont(QFont("Consolas",11));
    QWidget::setWindowTitle("Untitled - Notepad");
    LineNumber->setText("Ln 1, Col 1");
    // Default file value
    main_file="";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
   main_file="";
   ui->plainTextEdit->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    read_file();
}

void MainWindow::on_actionFont_triggered()
{
    ui->plainTextEdit->setFont(QFontDialog::getFont(0,ui->plainTextEdit->font()));
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionSave_triggered()
{
    if(main_file.isEmpty())
      save_file(true);
    else
        save_file(false);
}

// state = true.. if you want for prompt , else no if you want to save to existing file
void MainWindow::save_file(bool state)
{
    QString file_Name;
    if(state)
    {
      file_Name = QFileDialog::getSaveFileName(this, tr("Save As"),NULL,tr("Text files (*.txt)"));
      main_file=file_Name;
    }
    else
        file_Name=main_file;
    QFile mfile(file_Name);
    if(mfile.open(QFile::WriteOnly|QFile::Text))
    {
        QTextStream in(&mfile);
        in << ui->plainTextEdit->toPlainText();
    }
    mfile.flush();
    mfile.close();
    QWidget::setWindowTitle(file_Name);

}

void MainWindow::read_file()
{
    QString file_Name = QFileDialog::getOpenFileName(this, tr("Open"),NULL,tr("Text files (*.txt)"));
    main_file=file_Name;
    QWidget::setWindowTitle(file_Name);
    QFile mfile(file_Name);
    if(mfile.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream in(&mfile);
        QString line=in.readAll();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText(line);
    }
}

void MainWindow::on_actionSave_As_triggered()
{
  save_file(true);
}

void MainWindow::on_actionPaste_triggered()
{
   ui->plainTextEdit->paste();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
   ui->plainTextEdit->cut();
}

void MainWindow::on_actionDelete_triggered()
{
    QTextCursor curs=ui->plainTextEdit->textCursor();
    if(curs.hasSelection())
        qDebug() << "There is selection";
    else
        qDebug() << "There is no selection";
    //curs.removeSelectedText();
    //qDebug() <<"Anchor : " << curs.anchor();
    //qDebug() <<"Position pos: "<< curs.position();
    //qDebug() << "Selection star: "<<curs.selectionStart();
    //qDebug() << "Select End: " << curs.selectionEnd();
    ui->plainTextEdit->moveCursor(QTextCursor::Up);
}

void MainWindow::on_actionWord_Wrap_toggled(bool checked)
{
   if(checked)
   {
       ui->plainTextEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
   }
   else
   {
        ui->plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
   }
}

void MainWindow::on_actionUndo_triggered()
{
   ui->plainTextEdit->undo();
}

void MainWindow::on_plainTextEdit_cursorPositionChanged()
{
    QTextCursor curPos = ui->plainTextEdit->textCursor();
    int row=curPos.blockNumber();
    int col=curPos.positionInBlock();
    LineNumber->setText("Ln "+QString::number(row+1)+", Col "+QString::number(col+1));

}

void MainWindow::on_actionStatus_Bar_toggled(bool toogle)
{
    if(toogle)
        ui->statusBar->show();
    else
       ui->statusBar->hide();
}

void MainWindow::on_actionGo_To_triggered()
{
   GotoDialog myDialog;
   myDialog.setModal(true);
   myDialog.exec();
}

void MainWindow::on_actionSelect_All_triggered()
{
   ui->plainTextEdit->selectAll();
}
