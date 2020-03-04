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
// @author Mouna KAROUI
// Juillet 2019

#include "CallPython.h"

namespace artery {





void CallPython::initializePython()
{

    std::cout << "Start call python" << "\n";
    if (!Py_IsInitialized())
        {
            Py_Initialize();
        }
        // 2) Initialise python thread mechanism
        if (!PyEval_ThreadsInitialized())
        {
            PyEval_InitThreads();
            assert(PyEval_ThreadsInitialized());
        }
}





// clean python objects
void CallPython::cleanPythonObjects(PyObject* obj)
{
    if(obj!=NULL)
    {
        Py_DECREF(obj);
    }
}

void CallPython::predictDecision()
{

    PyGILState_STATE s = PyGILState_Ensure();
    PyRun_SimpleString("import sys; sys.path.append('/home/mouna1/deciderTest/predictionScripts')");

    PyObject *pName = PyUnicode_DecodeFSDefault((char*)"PredictLteTraffic");
    PyObject* pModule = PyImport_Import(pName);

    if (pModule != NULL)
    {
     /// call read data
    PyObject* pFunction;
        pFunction=PyObject_GetAttrString(pModule,(char*)"readData");
        PyObject* pArgs=PyTuple_Pack(1,PyUnicode_FromString((char*)"/home/mouna1/deciderTest/predictionScripts/Nodesprofil.csv"));

        std::cout << "Result of python script" << "\n";
        if((pFunction!=NULL)&&(pArgs!=NULL))
               {
                   PyObject* pResult = PyObject_CallObject(pFunction, pArgs);
                   if(pResult!=NULL)
                   {
                        //return result of python function as pyObject
                       std::cout << "python call is proceeding with sucess ..." << "\n";
                   }
               }
    }
    //double end=simTime().dbl();
    //scriptExecutionTime.record(end-start);
    // Clean up
    cleanPythonObjects(pModule);
    cleanPythonObjects(pName);
    PyGILState_Release(s);
}





} //namespace
