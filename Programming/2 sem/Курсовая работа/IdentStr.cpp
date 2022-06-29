#include <iostream>
#include <string.h>
#include "IdentStr.h"
#include "String.h"
using namespace std;

IdentStr::IdentStr(int val) : String(val)
{
	cout << "IdentStr::IdentStr(int val) " << endl;
}

IdentStr::IdentStr(char ch) : String(ch)
{
	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z'))) {
		cout << "Bad symbol; pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	cout << "IdentStr::IdentStr(char ch) " << endl;
};

IdentStr::IdentStr(const char* str) : String(str)
{
	const char* keyword[] = { "alignas","alignof", "and", "and_eq", "asm", "auto","bitand","bitor","bool","break","case","catch","char","char16_t","char32_t","class","compl","const","constexpr","const_cast","continue","decltype","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_assert","static_cast","struct","switch","template","this","thread_local","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor","xor_eq" };

	for (int i = 0; i < 84; i++) {
		if (strcmp(pCh, keyword[i]) == 0)
		{
			cout << "Bad string pCh = " << pCh << endl;
			if (pCh)delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z')))
	{
		cout << "Bad symbol: pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}

	for (int i = 1; i < len; i++)
	{
		if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
		{
			cout << "Bad string: pCh[" << i << "] = " << pCh[i] << endl;
			if (pCh)
				delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}

	cout << "IdentStr::IdentStr(const char* str) " << endl;
};

IdentStr::IdentStr(const IdentStr& from) : String(from)
{
	cout << "IdentStr::IdentStr(const IdentStr& from) " << endl;
};

IdentStr::~IdentStr()
{
	cout << "IdentStr::~IdentStr()" << endl;
};

IdentStr& IdentStr:: operator=(const IdentStr& S)
{
	if (&S != this)
	{
		delete[] pCh;
		len = strlen(S.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, S.pCh);
		cout << "IdentStr& IdentStr:: operator = " << endl;
		return *this;
	}
};

char& IdentStr:: operator [] (int index)
{
	if (index >= 0 && index < len)
	{
		cout << "char& IdentStr:: operator [] " << endl;
		return pCh[index];
	}

	return pCh[0];
}

IdentStr IdentStr:: operator~()
{
	int i, j;
	char tmp;

	for (i = 0, j = len - 1; i < len / 2; i++, j--)
	{
		tmp = pCh[i];
		pCh[i] = pCh[j];
		pCh[j] = tmp;
	}

	const char* keyword[] = { "alignas","alignof","and","and_eq", "asm", "auto","bitand","bitor","bool","break","case","catch","char","char16_t","char32_t","class","compl","const","constexpr","const_cast","continue","decltype","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_assert","static_cast","struct","switch","template","this","thread_local","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor","xor_eq" };

	for (int i = 0; i < 84; i++)
	{
		if (strcmp(pCh, keyword[i]) == 0)
		{
			cout << "Bad string pCh = " << pCh << endl;
			if (pCh)
				delete[]pCh;

			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return *this;
		}
	}

	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z')))
	{
		cout << "Bad symbol: pCh[0] = " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return *this;
	}
	cout << "IdentStr IdentStr:: operator~()" << endl;
	return *this;
}

IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)
{
	IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = pobj1.pCh[j++]);
	i--;
	j = 0;
	while (tmp.pCh[i++] = pobj2.pCh[j++]);
	cout << "IdentStr operator + [const IdentStr]" << endl;
	return tmp;
}

IdentStr operator + (const IdentStr& pobj1, const char* pobj2)
{
	IdentStr tmp1(pobj2);
	IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = pobj1.pCh[j++]);
	i--;
	j = 0;
	while (tmp.pCh[i++] = tmp1.pCh[j++]);

	cout << "IdentStr operator + (const IdentStr&, const char*)" << endl;
	return tmp;
}
IdentStr operator + (const char* pobj1, const IdentStr& pobj2)
{
	IdentStr tmp2(pobj1);
	IdentStr tmp(pobj2.GetLen() + tmp2.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = tmp2.pCh[j++]);
	i--;
	j = 0;
	while (tmp.pCh[i++] = pobj2.pCh[j++]);

	cout << "IdentStr operator + (const IdentStr&, const char*)" << endl;
	return tmp;
}