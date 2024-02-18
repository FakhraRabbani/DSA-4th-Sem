#include "iostream"
using namespace std;

template <class T>
class Stack
{
private:
	T* data;
	int top;
	const int MAX_SIZE;

public:
	Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		top = -1;
	}

	~Stack()
	{
		delete[] data;
	}

	void push(const T newItem) 
	{
		if (top < MAX_SIZE - 1)
		{
			data[++top] = newItem;
		}
		else
		{
			cout << "Stack is full!!!" << endl;
		}
	}

	void pop()
	{
		if (top >= 0)
		{
			top--;
		}
		else
		{
			cout << "Stack is already empty. Cannot pop." << endl;
		}
	}

	void clear()
	{
		top = -1;
	}

	T getTop() const
	{
		if (top >= 0)
		{
			return data[top];
		}
		else
		{
			cout << "Stack is empty." << endl;
			exit(-1);
		}
	}

	bool isEmpty() const
	{
		return top == -1;
	}

	bool isFull() const
	{
		return top == MAX_SIZE - 1;
	}

	void showStructure() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			cout << "top --> ";
			for (int i = top; i >= 0; i--)
			{
				cout << data[i] << endl;
				cout << "\t";
			}
			cout << "-------------------" << endl;
		}
	}
};

int main()
{
	Stack <double> stack(5);

	stack.push(5.0);
	stack.push(6.5);
	stack.showStructure();

	cout << endl;

	stack.push(-3.0);
	stack.push(-8.0);
	stack.showStructure();

	stack.pop();
	stack.pop();
	stack.showStructure();

	return 0;
}