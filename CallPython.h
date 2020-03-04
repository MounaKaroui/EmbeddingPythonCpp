//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __ARTERY_ARTERY_IDE_CALLPYTHON_H_
#define __ARTERY_ARTERY_IDE_CALLPYTHON_H_

#include <omnetpp.h>
#include <Python.h>
#include <iostream>
#include"artery/lte/NetworkSelection/Decider.h"
#include "artery/lte/NetworkSelection/AutonomousBased/AutonomousDecider.h"

using namespace omnetpp;

namespace artery {

/**
 * TODO - Generated class
 */

class CallPython
{

    void predictDecision();
    void initializePython();
    void cleanPythonObjects(PyObject*);

    friend class Decider;
    friend class AutonomousDecider;
//    friend class DeciderWithCallPython;

};

} //namespace

#endif
