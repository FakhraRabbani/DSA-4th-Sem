#include"iostream"

using namespace std;

template <class T>
class Stack
{
private:

	//Data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int top; //top of the stack
	const int MAX_SIZE; //maximum capacity of the stack

public:

	//constructor
	Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
	{
		this->data = new T[MAX_SIZE];
		this->top = -1;
	}

	//destructor
	~Stack()
	{
		delete[] data;
	}

	//stack manipulation operations
	void push(const T newItem) //push a new item
	{
		if (top != (MAX_SIZE - 1)) // If not full
		{
			top = top++;
			data[top] = newItem;
		}
		else
		{
			cout << "Stack is FULL. Cant insert new item" << endl;
		}

		//if (top < MAX_SIZE - 1)
		//{
		//	data[++top] = newItem;
		//}
		//else
		//{
		//	cout << "Stack is full!!!" << endl;
		//}
	}

	void pop() //pop an item
	{
		if (top == -1)
		{
			cout << "Stack is already empty" << endl;
		}
		else
		{
			top = top - 1;
		}

		//if (top >= 0)
		//{
		//	top--;
		//}
		//else
		//{
		//	cout << "Stack is already empty. Cannot pop." << endl;
		//}
	}

	void clear() //clear the stack
	{
		if (top == -1)
		{
			cout << "Stack is already empty" << endl;
		}
		else
		{
			top = -1;
			cout << "Cleared stack" << endl;
		}
	}

	//stack accessor
	T getTop() const //return item at the top
	{
		if (top == -1)
		{
			cout << "Empty Stack" << endl;
		}
		else
		{
			return data[top];
		}

		//if (top >= 0)
		//{
		//	return data[top];
		//}
		//else
		//{
		//	cout << "Stack is empty." << endl;
		//	exit(-1);
		//}
	}

	//stack status operations
	bool isEmpty() const //is stack empty?
	{
		return(top == -1);
	}

	bool isFull() const //is stack full?
	{
		return(top == MAX_SIZE - 1);
	}

	//outputs the data in stack. If the stack is empty, outputs “Empty Stack”.
	void showStructure() const
	{
		
		//if (top == -1)
		//{
		//	cout << "Empty Stack" << endl;
		//}
		//else
		//{
		//	cout << "Top --> ";
		//	for (int i = top; i >= 0; i--)
		//	{
		//		cout << data[i] << endl;
		//		cout << "\t";
		//	}
		//	
		//}
		
		if(top == -1)
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
	Stack<int>stack(4);

	stack.push(5.0);
	stack.push(6.5);
	stack.showStructure();

	
	stack.push(-3.0);
	stack.push(-8.0);
	stack.showStructure();

	cout << stack.isFull() << endl;

	stack.pop();
	stack.pop();
	stack.showStructure();

	cout << stack.isEmpty() << endl;;
	
	stack.clear();
	cout << stack.isEmpty() << endl;;
	stack.showStructure();

	stack.pop();

	return 0;
}
