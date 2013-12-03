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

#include "core.h"

using namespace AutoEQ;

Core *Core::autoEQCore = NULL;

Core::Core()
{
    this->mainWin = NULL;
}

Core::~Core()
{
    delete this->mainWin;
}

void Core::init()
{
    this->mainWin = new MainWindow();
    this->mainWin->show();
}

void Core::interceptStream()
{

}
