#ifndef __IDENTSTR__
#define __IDENTSTR__
#include "String.h"
class IdentStr : public String
{
public:

	IdentStr(int = 0);
	IdentStr(char);
	IdentStr(const char*);
	IdentStr(const IdentStr&);
	~IdentStr();

	//переопределение операторов
	IdentStr& operator = (const IdentStr&); //оператор присваивания 
	char& operator [] (int); 	// обращение по индексу
	IdentStr operator ~ (); 	// реверс строки

	//дружественные функции
	//сложение (конкатенация) двух объектов
	friend IdentStr operator + (const IdentStr&, const IdentStr&);
	//конкатенация си-строки и объекта
	friend IdentStr operator + (const char*, const IdentStr&);
	friend IdentStr operator + (const IdentStr&, const char*);
};
#endif