#include"iostream"

using namespace std;

template <class T>
class Queue
{
private:

	//data members
	T* data; //array of items to be allocated dynamically as per MAX_SIZE
	int front; //front index
	int rear; //rear index
	const int MAX_SIZE; //maximum capacity of queue

public:

	//constructor
	Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		this->front = -1;
		this->rear = -1;
	}

	//destructor
	~Queue()
	{
		delete[] data;
	}

	//queue manipulation operations
	void enQueue(const T newItem) //add an element to the rear of queue
	{
		if ((rear + 1) % MAX_SIZE != front) // If not full
		{
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
			if (front == -1) //For first element
			{
				front = rear;
			}
		}
		else
		{
			cout << "Queue is already full" << endl;
		}	
	}

	void deQueue() //delete element at the front of queue
	{
		if (front == -1 && rear == -1) // Empty already
		{
			cout << "Queue is already empty" << endl;
		}
		else if (front == rear) //Only one value left in queue
		{
			front = rear = -1; //Make queue empty
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}

	void clear() //clear the queue
	{
		if (front == -1 && rear == -1) // Empty already
		{
			cout << "Queue is already empty" << endl;
		}
		else
		{
			front = rear = -1;
		}
	}

	//queue accessors
	T getFront() const //return element at the front
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			return data[front];
		}
		
	}

	T getRear() const //return element at the rear
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			return data[rear];
		}
		
	}

	//queue status operations
	bool isEmpty() const //is queue empty?
	{
		return (front == -1 && rear == -1);
	}

	bool isFull() const //is queue full?
	{
		return ((rear + 1) % MAX_SIZE == front);
	}

	//outputs the data in queue. If the queue is empty, outputs “Empty Queue”.
	void showStructure() const
	{
		if (!isEmpty())
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
		else
		{
			cout << "Empty Queue" << endl;
		}
		
	}

};

int main()
{
	Queue<float> queue;

	queue.enQueue(5.0);
	queue.enQueue(6.5);
	queue.showStructure();

	queue.enQueue(-3.0);
	queue.enQueue(-8.0);
	queue.showStructure();

	queue.deQueue();
	queue.deQueue();
	queue.showStructure();


	cout << queue.isEmpty() << endl;

	cout << "data[rear]" << queue.getRear() << endl;
	cout << "data[front]" << queue.getFront() << endl;

	queue.clear();
	cout << queue.isEmpty() << endl;

	cout << "data[rear]" << queue.getRear() << endl;
	cout << "data[front]" << queue.getFront() << endl;
	queue.showStructure();

	return 0;

}