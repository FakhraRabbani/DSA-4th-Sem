#include"iostream"

using namespace std;

struct Point3D
{
	float x, y, z;
};

class PointList
{
	Point3D* ptr;
	int maxSize;
	int curSize;
	int cursor ;

public:

	//Constructor
	PointList(int maxSize)
	{
		this->maxSize = maxSize;
		ptr = new Point3D[maxSize];
		curSize = 0;
		cursor = -1;
	}

	//Destructor
	~PointList()
	{
		delete[] ptr;
	}

	//isEmpty()
	bool isEmpty()
	{
		if (curSize == 0)
			return true;
		return false;
	}

	//isFull()
	bool isFull()
	{
		if (curSize == maxSize)
			return true;
		return false;
	}

	//Insert newPoint to list
	/*
	void insert(Point3D newPoint)
	{
		if (!isEmpty)
		{
			for (int i = curSize; i > cursor + 1; i--)
			//for(int i = cursor; i < curSize; i++)
			{
				ptr[i] = ptr[i - 1];
			}
		}

		ptr[++cursor] = newPoint;
		curSize++;
	}*/

	void insert(Point3D newPoint)
	{
		if (!isFull())
		{
			if (!isEmpty())
			{
				ptr[curSize] = newPoint;
			}
			else
			{
				ptr[0] = newPoint;
			}
			curSize++;
			cursor = curSize - 1;
		}
					
	}

	//showStructure
	void showStructure()
	{
		if (isEmpty())
		{
			cout << "Empty List" << endl;
		}
		else
		{
			for (int i = 0; i < curSize; i++)
			{
				cout << "x: " << ptr[i].x << "y: " << ptr[i].y << "z: " << ptr[i].z << endl;
			}
		}
	}

	//getCursor
	Point3D getCursor() {
		if (isEmpty())
		{
			cout << "Error!! List is empty!!!" << endl;
			return { -1, -1, -1 };
		}
		else
		{
			return ptr[cursor];
		}

	}

	//Goto Beginning
	void gotoBeginning()
	{
		if (!isEmpty())
		{
			cursor = 0;
		}
	}

	//Goto End
	void gotoEnd()
	{
		if (!isEmpty())
		{
			cursor = curSize - 1;
		}
	}

	//Goto Next
	bool gotoNext()
	{
		if (!isEmpty() && cursor != curSize - 1)
		{
				cursor++;
				return true;
		}
		else
		{
			return false;
		}
		
	}

	//Goto Prior
	bool gotoPrior()
	{
		if (!isEmpty() && cursor > 0)
		{
			cursor--;
			return true;
		}
		else
		{
			return false;
		}
		
	}

	//Clear List
	void clear()
	{
		curSize = 0;
		cursor = -1;
	}

	//Replace List
	bool replace(Point3D newPoint)
	{
		if (!isEmpty() && cursor >= 0 && cursor < curSize)
		{
			ptr[cursor] = newPoint;
			return true;
		}
		else
		{
			return false;
		}
	}

	//Remove Data
	void remove()
	{
		if (!isEmpty() && cursor >= 0 && cursor < curSize)
		{
			for (int i = cursor; i < curSize - 1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			curSize--;

			if (cursor == curSize)
			{
				cursor = 0;
			}
		}
	}
};

int main()
{
	Point3D p1{ 1.1, 1.2, 1.3 };
	Point3D p2{ 2.1, 2.2, 2.3 };
	Point3D p3{ 3.1, 3.2, 3.3 };

	PointList point(6);
	cout << "point is empty: " << point.isEmpty() << endl;
	cout << "point is full: " << point.isFull() << endl;

	point.insert(p1);
	point.showStructure();

	cout << point.replace(p2) << endl;
	point.showStructure();

	point.clear();
	point.showStructure();

	point.insert(p3);
	point.showStructure();
	
	point.remove();
	point.showStructure();

	cout << point.getCursor().x << endl ;

	point.insert(p3);
	cout << point.getCursor().y << endl;

	Point3D cursorPoint = point.getCursor();
	cout << cursorPoint.x << " " << cursorPoint.y << " " << cursorPoint.z << endl;

	

	return 0;
}