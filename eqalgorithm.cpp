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

#include "eqalgorithm.h"

using namespace AutoEQ;

EQAlgorithm::EQAlgorithm()
{
    this->input = NULL;
    this->in = NULL;
    this->out = NULL;
}

EQAlgorithm::~EQAlgorithm()
{
    fftw_destroy_plan(this->p);
    fftw_free(this->in);
    fftw_free(this->out);
}

void EQAlgorithm::gatherData()
{
    this->file = Core::autoEQCore->mainWin->fileNames;
    this->file.open(QIODevice::ReadWrite);
    this->fftInput = file.readAll();
    this->file.close();
    this->fftOutput = new QAudioBuffer(fftInput, QAudioFormat::codec(), 0)
}

fftw_execute EQAlgorithm::execute()
{
    if (this->in || this->out != NULL)
    {
        return;
    }
    this->in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * );
    this->out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 441000);
    this->p = fftw_plan_dft_1d(441000, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    return fftw_execute(this->p);
}
