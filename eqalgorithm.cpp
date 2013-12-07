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
    QAudioFormat format;
    this->fftOutput = new QAudioBuffer(fftInput, format.codec(), 0);
}

void EQAlgorithm::execute()
{
    if (this->in || this->out != NULL)
    {
        return;
    }
    this->in = this->fftInput.toDouble(), (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 44100);
    this->out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 44100);
    this->p = fftw_plan_dft_1d(format.sampleRate(), in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(this->p);
}
