#ifndef __DECSTR__
#define __DECSTR__
#include "String.h"
class DecStr : public String
{
public:

	DecStr(int = 0);
	DecStr(const char*);
	DecStr(const DecStr&);
	~DecStr();

	DecStr& operator = (const DecStr&);

	//������ + ������
	friend DecStr operator + (const DecStr&, const DecStr&);

	//������ + ����� (int)
	friend DecStr operator + (const DecStr&, const int);

	//������ � ������
	friend DecStr operator - (const DecStr&, const DecStr&);
};
#endif