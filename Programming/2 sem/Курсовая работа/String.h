#ifndef __STRING__
#define __STRING__

class String
{
protected:
	int len;	//длина строки
	char* pCh;	//копирование

public:

	String(int = 0);
	String(char);
	String(const char*);

	String(const String&);	//конструктор копирования
	~String();				//деструктор

	char* GetStr(void) const { return pCh; }
	int GetLen(void) const { return len; }
	void Show(void);			//вывод строки и её длины на экран
};
#endif