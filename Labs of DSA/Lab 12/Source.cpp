#include "iostream"

using namespace std;


class Student
{
	friend class StudentMaxHeap;
private:
	double cgpa;	/**Student’s CGPA*/
	int rollNo;		/**Student’s roll number*/

public:
	Student(int rollNo, double cgpa) : rollNo(rollNo), cgpa(cgpa) {}
	Student() {}
};

/**Manages an array of students arranged like a Max Heap.*/
class StudentMaxHeap
{
private:
	Student* arr;				/**Array of students which, arranged like a Max Heap*/
	int curSize;				/**Current number of students present in the heap*/
	int maxSize;				/**Maximum number of students that can be present in heap*/

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

public:
	/**Constructor*/
	StudentMaxHeap(int size) : curSize(0), maxSize(size)
	{
		arr = new Student[maxSize];
	}

	/**Destructor*/
	~StudentMaxHeap()
	{
		delete[] arr;
	}

	bool isEmpty()			/**Checks whether the heap is empty or not*/
	{
		return curSize == 0;
	}

	bool isFull()				/**Checks whether the heap is full or not*/
	{
		return curSize == maxSize;
	}

	bool insert(int rollNo, double cgpa)
	{
		if (isFull())
		{
			return false;
		}

		int i = curSize;
		arr[i] = Student(rollNo, cgpa);
		curSize++;

		while (i > 0 && (arr[parent(i)].cgpa < arr[i].cgpa || (arr[parent(i)].cgpa == arr[i].cgpa && arr[parent(i)].rollNo > arr[i].rollNo)))
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}

		return true;
	}

	bool remove(int& rollNo, double& cgpa)
	{
		if (isEmpty())
		{
			return false;
		}

		rollNo = arr[0].rollNo;
		cgpa = arr[0].cgpa;

		arr[0] = arr[curSize - 1];
		curSize--;

		int i = 0;
		while (true)
		{
			int maxIndex = i;
			int l = left(i);
			int r = right(i);

			if (l < curSize && (arr[l].cgpa > arr[maxIndex].cgpa || (arr[l].cgpa == arr[maxIndex].cgpa && arr[l].rollNo < arr[maxIndex].rollNo)))
			{
				maxIndex = l;
			}

			if (r < curSize && (arr[r].cgpa > arr[maxIndex].cgpa || (arr[r].cgpa == arr[maxIndex].cgpa && arr[r].rollNo < arr[maxIndex].rollNo)))
			{
				maxIndex = r;
			}

			if (i != maxIndex)
			{
				swap(arr[i], arr[maxIndex]);
				i = maxIndex;
			}
			else
			{
				break;
			}
		}

		return true;
	}

	void displayStudentList()
	{
		for (int i = 0; i < curSize; i++)
		{
			cout << "Roll No: " << arr[i].rollNo << ", CGPA: " << arr[i].cgpa << endl;
		}
	}

	void levelOrder()
	{
		int h = 0;
		int temp = curSize;
		while (temp >>= 1)
		{
			++h;
		}

		int maxSpaces = (1 << (h + 1));

		for (int i = 0; i < curSize; i++)
		{
			int spaces = maxSpaces >> (i + 1);
			for (int j = 0; j < spaces; j++)
			{
				cout << " ";
			}

			cout << arr[i].cgpa;

			if (i + 1 < curSize && ((i + 2) & (i + 1)) == 0)
			{
				cout << endl;
			}
		}

		cout << endl;
	}
};


void menu()
{
	StudentMaxHeap maxHeap(10); // assuming a maximum capacity of 10 students

	while (true)
	{
		cout << "1. Insert a new student\n"
			"2. Remove (and display) the student with the Max CGPA\n"
			"3. Display the list of students (Descending order of CGPA)\n"
			"4. Display the list of students (Level-order traversal)\n"
			"5. Exit\n"
			"Enter your choice: ";

		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			int rollNo;
			double cgpa;
			cout << "Enter Roll No: ";
			cin >> rollNo;
			cout << "Enter CGPA: ";
			cin >> cgpa;

			if (maxHeap.insert(rollNo, cgpa))
			{
				cout << "Student inserted successfully!\n";
			}
			else
			{
				cout << "Heap is full. Student insertion failed.\n";
			}
			break;
		}
		case 2: {
			int rollNo;
			double cgpa;

			if (maxHeap.remove(rollNo, cgpa))
			{
				cout << "Removed student: Roll No: " << rollNo << ", CGPA: " << cgpa << std::endl;
			}
			else
			{
				cout << "Heap is empty. No student to remove.\n";
			}
			break;
		}
		case 3:
			cout << "List of students (Descending order of CGPA):\n";
			maxHeap.displayStudentList();
			break;
		case 4:
			cout << "Level order traversal:\n";
			maxHeap.levelOrder();
			break;
		case 5:
			cout << "Exiting...\n";
			return;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	}
}

int main() {
	menu();
	return 0;
}