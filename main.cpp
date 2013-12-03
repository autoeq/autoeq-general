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
#include "core.h"
#include <QApplication>

using namespace AutoEQ;

int main(int argc, char *argv[])
{
    int startCode = 0;
    QApplication a(argc, argv);
    Core::autoEQCore = new Core();
    Core::autoEQCore->init();
    startCode = a.exec();
    delete Core::autoEQCore;
    return startCode;
}
