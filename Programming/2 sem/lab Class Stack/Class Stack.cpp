#include <iostream>
#include <fstream>

using namespace std;

class IntStack
{
	const int size;
	int top;
	int* v;
public:
	IntStack(int = 20);
	IntStack(const IntStack&);
	~IntStack();
	int Top(void)const { return v[top]; }
	void Push(int);
	int Pop(void);
};
IntStack::IntStack(int val) : size(val)
{
	if (val <= 0)
	{
		cout << "cock size!" << endl;
		return;
	}
	else
	{
		v = new int[size];
		top = -1;
		cout << "IntStack::IntStack(int val) : size(val)" << endl;
	}
}
IntStack::IntStack(const IntStack& from) :size(from.size)
{
	v = new int[size];
	for (int i = 0; i < size; i++)
		v[i] = from.v[i];
	top = from.top;
	cout << "IntStack::IntStack(const IntStack& from) :size(from.size)" << endl;
}
IntStack::~IntStack()
{
	delete[]v;
	cout << "IntStack::~IntStack()" << endl;
}
void IntStack::Push(int num)
{
	if (top + 1 < size)
		v[++top] = num;
	else
		cout << "Stack is full!" << endl;
}
int IntStack::Pop(void)
{
	if (top >= 0)
		return v[top--];
	else
		cout << "Stack is Empty!" << endl;
}

int main()
{
	IntStack obj(100);
	IntStack obj1 = obj;
	obj1.Push(-32768);
	cout << obj1.Top() << endl;
}