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

#ifndef EQALGORITHM_H
#define EQALGORITHM_H

#include <fftw3.h>
#include <QAudioFormat>
#include <QAudioInput>
#include <QByteArray>
#include <phonon/BackendCapabilities>
#include "core.h"
#include "mainwindow.h"
#include "analysingdialog.h"

namespace AutoEQ {

    class EQAlgorithm
    {
        public:
            EQAlgorithm();
            ~EQAlgorithm();
        private:
            fftw_execute execute();
            void gatherData();
            fftw_plan p;
            fftw_complex *in, *out;
            QAudioInput *input;
            AnalysingDialog *analyse;
            QFile file;
            QByteArray fftInput;
            QAudioBuffer fftOutput;
    };
}

#endif // EQALGORITHM_H
