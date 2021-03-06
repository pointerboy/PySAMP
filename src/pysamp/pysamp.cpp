#include "pysamp.h"

PyGamemode* PySAMP::gamemode = 0;


void PySAMP::load()
{
	PySAMP::gamemode = new PyGamemode(PYTHON_PATH);

	if (!PyEval_ThreadsInitialized()) 
	{
		PyEval_InitThreads();
	}
}

void PySAMP::unload()
{
	delete PySAMP::gamemode;
}

bool PySAMP::callback(const char * name, PyObject * pArgs)
{
	//if gamemode exists forward to callback
	if(PySAMP::gamemode != NULL)
		return PySAMP::gamemode->callback(name, pArgs);
	return 0;
}
