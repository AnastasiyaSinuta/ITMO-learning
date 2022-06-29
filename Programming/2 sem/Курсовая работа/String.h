#ifndef __STRING__
#define __STRING__

class String
{
protected:
	int len;	//����� ������
	char* pCh;	//�����������

public:

	String(int = 0);
	String(char);
	String(const char*);

	String(const String&);	//����������� �����������
	~String();				//����������

	char* GetStr(void) const { return pCh; }
	int GetLen(void) const { return len; }
	void Show(void);			//����� ������ � � ����� �� �����
};
#endif