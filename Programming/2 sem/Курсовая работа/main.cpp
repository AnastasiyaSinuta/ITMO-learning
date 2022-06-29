#include <iostream>
#include "String.h"
#include "IdentStr.h"
#include "DecStr.h"

using namespace std;

extern "C" char* __stdcall fun1(int);

int main() 
{
	String obj1("ITMO");
	String obj2 = obj1;
	obj2.Show();

	IdentStr obj3("hello");
	obj3.Show();
	IdentStr obj4 = ~obj3;
	obj4.Show();
	obj4 = obj4 + (~obj3);
	obj4.Show();

	IdentStr obj5("IT");
	obj5 = "FB" + obj5;
	obj5.Show();
	obj5 = obj5 + "MO";
	obj5.Show();

	IdentStr obj6("int");
	obj6.Show();

	DecStr obj7("13357");
	DecStr obj8("-357");
	obj7 = obj7 + 3;
	DecStr obj9 = obj7 + obj8;
	obj7.Show();
	obj9.Show();

	String** pStr = new String * [6];
	pStr[0] = new String("Hello");
	pStr[1] = new IdentStr("World");
	pStr[2] = new DecStr("-5");
	pStr[3] = new IdentStr("ITMO");
	pStr[4] = new DecStr("65535");
	pStr[5] = new DecStr("&255");
	pStr[0]->Show();
	((DecStr*)pStr[4])->Show();
	delete[] pStr;
	return 0;
	cout << fun1(65535) << endl;
}