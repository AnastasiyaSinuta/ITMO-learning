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

	//объект + объект
	friend DecStr operator + (const DecStr&, const DecStr&);

	//объект + число (int)
	friend DecStr operator + (const DecStr&, const int);

	//объект – объект
	friend DecStr operator - (const DecStr&, const DecStr&);
};
#endif