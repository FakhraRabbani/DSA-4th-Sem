#include"iostream"

using namespace std;

const int maxSize = 10;
int A[maxSize];
int curSize = 0;
int C[maxSize] = { 2, 4, 3, 7, 6, 1, 5, 0, 9, 8 };
int curSize_C = maxSize;

//Left kid
int left(int val)
{
	return (2 * val + 1);
}

//Right kid
int right(int val)
{
	return (2 * val + 2);
}

//Parent
int parent(int val)
{
	return (val - 1) / 2;
}

void heapInsert(int val)
{
	if (curSize != maxSize)
	{
		A[curSize] = val;

		//Index of new item
		int new_pos = curSize;

		curSize++;

		while ((new_pos != 0) && (A[new_pos] > A[parent(new_pos)]))
		{
			swap(A[new_pos], A[parent(new_pos)]);
			new_pos = parent(new_pos);
		}
	}
}

void maxHeapify(int* B, int i)
{
	int left_i = left(i);
	int right_i = right(i);
	int largest = i;

	if (B[left_i] > B[largest] && left_i < 10)
	{
		largest = left_i;
	}
	if (B[right_i] > B[largest] && right_i < 10)
	{
		largest = right_i;
	}

	if(i != largest)
	{
		swap(B[largest], B[i]);
		maxHeapify(B, largest);
	}
	
}

void buildMaxheap(int C[])
{
	
	for(int i = (curSize / 2) - 1; i >= 0; i--)
		maxHeapify(C, i);
}

//deletion of root
int getMax()
{
	int max = C[0];
	C[0] = C[--curSize];

	maxHeapify(C, 0);
	return max;
}

int main()
{
	heapInsert(6);
	heapInsert(8);
	heapInsert(1);
	heapInsert(4);
	heapInsert(7);
	heapInsert(3);
	heapInsert(5);
	heapInsert(0);
	heapInsert(9);
	heapInsert(2);
	heapInsert(6);

	for (int i = 0; i < maxSize; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl << endl;


	int B[10] = { 8, 5, 4, 9, 6, 1, 3, 0, 7, 2 };
	maxHeapify(B, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl << endl;

	buildMaxheap(C);

	for (int i = 0; i < 10; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl << endl;
	

	buildMaxheap

	return 0;
}