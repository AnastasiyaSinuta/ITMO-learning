#include <iostream>
#include "DecStr.h"
#include "String.h"

using namespace std;

DecStr::DecStr(int val) : String(val)
{
	cout << "DecStr::DecStr(int val) " << endl;
}

DecStr::DecStr(const char* str) : String(str)
{

	if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' || pCh[0] == '+')))
	{
		cout << "Invalid symbol, pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		*pCh = '\0';
		return;
	}

	for (int i = 1; i < len; i++)
		if (!(pCh[i] >= '0' && pCh[i] <= '9'))
		{
			cout << "Invalid string: pCh[" << i << "] = " << pCh[i] << endl;
			if (pCh) delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			*pCh = '\0';
			return;
		}

	cout << "DecStr::DecStr(const char* str) " << endl;
}

DecStr::DecStr(const DecStr& from) : String(from)
{
	cout << "DecStr::DecStr(const DecStr& from) " << endl;
}

DecStr:: ~DecStr()
{
	cout << "DecStr:: ~DecStr() " << endl;
}

DecStr& DecStr:: operator = (const DecStr& DS)
{
	if (&DS != this)
	{
		delete[] pCh;
		len = strlen(DS.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, DS.pCh);
	}
	cout << "DecStr& DecStr:: operator = (const DecStr& DS)" << endl;
	return *this;
}

DecStr operator + (const DecStr& pobj1, const DecStr& pobj2)
{
	int num1, num2;
	DecStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(pobj2.GetStr());
	int A = num1 + num2;
	char* pTmpCh;
	if (tmp.len >= pobj2.len)
	{
		pTmpCh = new char[tmp.len + 1];
		_itoa_s(A, pTmpCh, tmp.len + 1, 10);
	}
	else
	{
		pTmpCh = new char[pobj2.len + 1];
		_itoa_s(A, pTmpCh, pobj2.len + 1, 10);
	}
	if (tmp.pCh) delete[] tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	return tmp;
}

DecStr operator + (const DecStr& pobj1, const int pobj2)
{
	int num1, num2;
	DecStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = pobj2;
	long long int A = static_cast<long long>(num1) + num2;
	if ((A > 2147483647) || (A < -2147483648)) {
		delete[] tmp.pCh;
		tmp.len = 0;
		tmp.pCh = new char[tmp.len + 1];
		tmp.pCh[0] = '\0';
		cout << "Bad srtoka" << endl;
		return tmp;
	}
	char* pTmpCh;
	int count = 0;
	if (num2 < 0)
	{
		count++;
		num2 *= -1;
	};

	while (num2)
	{
		count++;
		num2 /= 10;
	};

	if (tmp.len >= count)
	{
		pTmpCh = new char[tmp.len + 2];
		_itoa_s(A, pTmpCh, tmp.len + 2, 10);
	}
	else
	{
		pTmpCh = new char[count + 2];
		_itoa_s(A, pTmpCh, count + 2, 10);
	};

	if (tmp.pCh) delete[] tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	return tmp;
}

DecStr operator - (const DecStr& pobj1, const DecStr& pobj2)
{
	int num1, num2;
	DecStr tmp(pobj1);
	num1 = atoi(tmp.GetStr());
	num2 = atoi(pobj2.GetStr());
	int A = num1 - num2;
	char* pTmpCh;
	if (tmp.len >= pobj2.len)
	{
		pTmpCh = new char[tmp.len + 1];
		_itoa_s(A, pTmpCh, tmp.len + 1, 10);
	}
	else
	{
		pTmpCh = new char[pobj2.len + 1];
		_itoa_s(A, pTmpCh, pobj2.len + 1, 10);
	}
	if (tmp.pCh)
		delete[] tmp.pCh;
	tmp.pCh = pTmpCh;
	tmp.len = strlen(tmp.pCh);
	return tmp;
}