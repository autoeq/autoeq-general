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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QAudioDecoder>
#include <QAudioDeviceInfo>
#include <QMessageBox>
#include <QAudioBuffer>
#include <QByteArray>
#include "aboutform.h"
#include "analysingdialog.h"

namespace Ui
{
    class MainWindow;
}
namespace AutoEQ {
    class AboutForm;
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();
            QStringList fileNames;
        private slots:
            void on_actionAbout_triggered();
            void on_actionAbout_Qt_triggered();
            void on_actionSave_triggered();
            void on_actionSave_as_triggered();
            void on_actionLoad_triggered();
        private:
            AboutForm *fAbout;
            AnalysingDialog *fAnalyse;
            Ui::MainWindow *ui;
    };
}


#endif // MAINWINDOW_H
