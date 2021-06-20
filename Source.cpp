/* Jacob Jamison
20 June 2021
Project 3 Corner Grocer*/
#include <Python.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <Vector>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("python");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"python");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

//function to display menu
void displayMenu() {
	cout << " Welcome to the Corner Grocery!" << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
	cout << "Pick a number 1-4. " << endl;
	cout << endl;
	cout << "|--------------------------------------------|" << endl;
	cout << "| 1: Print Item List                         |" << endl;
	cout << "| 2: Search for item frequency               |" << endl;
	cout << "| 3: Print Histogram of items and frequency  |" << endl; 
	cout << "| 4: Quit                                    |" << endl;
	cout << "|--------------------------------------------|";
	cout << endl;
	
}

//function to turn item vector into string
string createString(vector<string> foodVector) {
	string foodString = " ";
	int i;
	for (i = 0; i < foodVector.size(); i++) {
		foodString = foodString + " " + foodVector[i];
	}
	return foodString;
}

int main()
{
	//declaring food vector
	vector<string> foodVector;
	int answer = 0;
	fstream newfile;

	//open and read file
	newfile.open("input.txt", ios::in);

	//check if file is open
	if (newfile.is_open()) {   
		string tp;

		//read file and put in string
		while (getline(newfile, tp)) { 
			foodVector.push_back(tp);
		}

		//close file
		newfile.close(); 
	}

	//run loop user selection
	while (answer != 4) {

		displayMenu();
		cin >> answer;
		if (answer == 1) {

			//calls function
			int x = callIntFunc("individualCount", createString(foodVector));

		}
		if (answer == 2) {

			//calls function
			int x = callIntFunc("searchCount", createString(foodVector));
		}
		if (answer == 3) {

			//calls function
			int x = callIntFunc("histogram", createString(foodVector));

		}
		if (answer == 4) {
			cout << "THANKS FOR STOPPING IN!" << endl;

			//exits loop
			break;
		}
	}
}