/*
   This file is part of AutoEQ.

   AutoEQ is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   AutoEQ is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with AutoEQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

// THIS PROJECT IS CURRENTLY STILL IN PLANNING PHASE, BUT NEARING TO IMPLEMENTATION

using namespace AutoEQ;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_4->setText("--:--");
    this->fAbout = NULL;
    this->fAnalyse = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->fAbout;
    delete this->fAnalyse;
}

void MainWindow::on_actionAbout_triggered()
{
    if (this->fAbout != NULL)
    {
        return;
    }
    this->fAbout = new AboutForm(this);
    this->fAbout->show();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_actionLoad_triggered()
{
    QFileDialog dialog = new QFileDialog(this, tr("Load a file to equalise..."), QDir::homePath(), tr("Audio files, *.wav, *.ogg, *.flac, *.aiff, *.mfa"));
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        if (fileNames.length() > 1)
        {
            QMessageBox *box = new QMessageBox(this);
            box->setWindowTitle("Cannot perform action");
            box->setText("You can't select more than one file!");
            box->setAttribute(Qt::WA_DeleteOnClose);
            return;
        }
        dialog.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{

}
