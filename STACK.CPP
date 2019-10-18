#include <iostream.h>

class Error 	{ /* ... */ };
class Underflow : public Error {};
class Overflow  : public Error {};
class HeapFail  : public Error {};
class BadSize   : public Error {};
class Empty		: public Error {};

template <class Type>
class Stack {
public:
				Stack	(int max);
				~Stack	(void)  {delete stack;}
		void    Push	(Type &val);
		void    Pop		(void);
		Type    &Top	(void);
		friend ostream& operator << (ostream&, Stack<Type>);
private:
		Type    	*stack;
		int     	top;
		const int	maxSize;
};

template <class Type>
Stack<Type>::Stack (int max) : maxSize(max)
{
	if (max <= 0)
		throw BadSize();
	if ((stack = new Type[max]) == 0)
		throw HeapFail();
	top = -1;
}

template <class Type>
void Stack<Type>::Push (Type &val)
{
	if (top+1 < maxSize)
		stack[++top] = val;
	else
		throw Overflow();
}

template <class Type>
void Stack<Type>::Pop (void)
{
	if (top >= 0)
		--top;
	else
		throw Underflow();
}

template <class Type>
Type &Stack<Type>::Top (void)
{
	if (top < 0)
    	throw Empty();
	return stack[top];
}

template <class Type>
ostream& operator << (ostream& os, Stack<Type> s)
{
	for (register i = 0; i <= s.top; ++i)
		cout << s.stack[i] << " ";
	return os;
}

int main (void)
{
	try {
		Stack<int> si(2);
		si.Pop();
		si.Push(1);
		si.Push(2);
		si.Push(3);
		cout << si << endl;
		si.Pop();
		cout << si.Top() << endl;
		cout << si << endl;
	}
	catch (Underflow)	{cout << "Stack underflow\n";}
	catch (Overflow)	{cout << "Stack overflow\n";}
	catch (HeapFail)	{cout << "Heap exhausted\n";}
	catch (BadSize)		{cout << "Bad stack size\n";}
	catch (Empty)		{cout << "Empty stack\n";}
	catch (char* msg)	{cout << msg << '\n';}
	return 0;
}

