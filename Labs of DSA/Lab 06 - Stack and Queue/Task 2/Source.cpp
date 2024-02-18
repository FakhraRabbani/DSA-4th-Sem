#include "iostream"
using namespace std;

template <class T>
class Queue
{
private:
	T* data;
	int front;
	int rear;
	const int MAX_SIZE;

public:
	Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		front = -1;
		rear = -1;
	}

	~Queue()
	{
		delete[] data;
	}

	void enQueue(const T newItem)
	{
		if (!isFull())
		{
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
			if (front == -1)
				front = rear;
		}
		else
		{
			cout << "Queue is full." << endl;
		}
	}

	void deQueue()
	{
		if (!isEmpty())
		{
			if (front == rear)
			{
				front = rear - 1;
			}
			else
			{
				front = (front + 1) % MAX_SIZE;
			}
		}
		else
		{
			cout << "Queue is empty." << endl;
		}
	}

	void clear()
	{
		if (isEmpty())
		{
			cout << "Queue is already empty." << endl;
		}
		else
		{
			front = -1;
			rear = -1;
			cout << "Queue is cleared";
		}
	}

	T getFront()
	{
		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}
		else
		{
			return data[this->front];
		}
	}

	T getRear()
	{
		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}
		else
		{
			return data[this->rear];
		}
	}

	bool isEmpty() const
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		return false;
	}

	bool isFull() const
	{
		if ((rear + 1) % MAX_SIZE == front)
		{
			return true;
		}
		return false;
	}

	void showStructure()
	{
		if (isEmpty())
		{
			cout << "Empty Queue" << endl;
		}
		else
		{
			cout << "Front --> ";
			for (int i = front; i < rear + 1; i++)
			{
				if (i != rear)
				{
					cout << data[i] << endl;
					cout << "          ";
				}
				else
				{
					cout << data[i] << " <-- rear";
					cout << endl;
				}
			}
		}
	}
};

int main()
{
	Queue <double> intQueue(5);

	intQueue.enQueue(5.0);
	intQueue.enQueue(6.5);
	intQueue.showStructure();

	cout << endl;
	//Queue <double> queue1(5);
	intQueue.enQueue(-3.0);
	intQueue.enQueue(-8.0);
	intQueue.showStructure();

	cout << endl;

	intQueue.deQueue();
	intQueue.deQueue();
	intQueue.showStructure();

	return 0;
}