#include "iostream"
#include "fstream"
#include "string"

using namespace std;

class Student
{
	friend class StudentList;
private:
	int id;				
	string name;		
	float cgpa;			
	Student* next;	

public:
	Student(int id, string name, float cgpa, Student* next)
	{
		this->id = id;
		this->name = name;
		this->cgpa = cgpa;
		this->next = next;
	}
	void studentDetails() const
	{
		cout << "ID: " << id << endl;
		cout << "NAME: " << name <<  "\tCGPA: " << cgpa << endl;
	}
};


class StudentList
{
private:
	Student* head;			/**start of the list*/
	Student* cursor;		/**current item of the list*/

public:
	StudentList()			/**constructor*/
	{
		this->head = NULL;
		this->cursor = NULL;
	}

	~StudentList()		/**destructor*/
	{
		Student* temp = head;
		while (temp != NULL)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	void insert(const Student& newStd)
	{
		Student* newNode = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);

		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->next = cursor->next;
			cursor->next = newNode;
		}

		cursor = newNode;
	}

	void remove(int id)
	{
		if (head == NULL)
		{
			cout << "List is empty.";
		}
		else
		{
			Student* cur = head;
			Student* pre = NULL;

			// at least one is present
			// find student with specific id
			while (cur != NULL || cur->id != id)
			{
				pre = cur;
				cur = cur->next;
			}

			// when student not found
			if (cur == NULL)
			{
				cout << "Student with " << id << "not found." << endl;
			}

			// update the cursor if it points to the node being removed
			if (cursor == cur)
			{
				if (cur->next != NULL)
				{
					cur = cur->next;		// move to the next
				}
				else
				{
					cur = head;   // move to the beginning
				}
			}

			// remove the end
			if (pre == NULL)
			{
				head = cur->next;
			}
			else
			{
				pre->next = cur->next;
			}

			delete cur;
		}
	}

	void search(float cgpa) const
	{
		if (head == NULL)
		{
			cout << "List is empty." << endl;
		}
		else
		{
			Student* cur = head;
			bool found = false;

			// iteration
			while (cur != NULL)
			{
				if (cur->cgpa = cgpa)
				{
					cur->studentDetails();
					found = true;
				}
				cur = cur->next;
			}

			if (!found)
			{
				cout << "No student found with cgpa " << cgpa << endl;
			}
		}
	}

	void replace(const Student& newStd)
	{
		if (head == NULL)
		{
			cout << "List is empty." << endl;
		}

		Student* cur = head;
		bool found = false;

		while (cur != NULL) 
		{
			if (cur->id == newStd.id) 
			{
				cur->name = newStd.name;
				cur->cgpa = newStd.cgpa;
				found = true;
				cursor = cur;
				break;
			}
			cur = cur->next;
		}

		if (!found) 
		{
			insert(newStd); 
		}
	}

	bool isEmpty() const
	{
		return head == NULL;
	}

	void gotoBeginning()
	{
		cursor = head;
	}

	void gotoEnd()
	{
		if (head == NULL) 
		{
			cursor = NULL;
			return;
		}

		while (cursor->next != NULL) 
		{
			cursor = cursor->next;
		}
	}

	bool gotoNext()
	{
		if (cursor != NULL && cursor->next != NULL) 
		{
			cursor = cursor->next;
			return true;
		}
		return false;
	}

	bool gotoPrior()
	{
		if (head == NULL || cursor == head) 
		{
			return false;
		}

		Student* cur = head;
		Student* pre = NULL;

		while (cur != cursor) 
		{
			pre = cur;
			cur = cur->next;
		}

		cursor = pre;
		return true;
	}

	Student getCursor()
	{
		if (cursor != NULL) 
		{
			return *cursor;
		}
		else 
		{
			
			return Student(0, "", 0.0, NULL);
		}
	}

	void showStructure() const
	{
		if (head == NULL) 
		{
			cout << "List is empty" << endl;
		}

		Student* current = head;

		while (current != nullptr) 
		{
			current->studentDetails();
			current = current->next;
		}
	}
};


int main()
{
	ifstream inf("input.txt");

	if (!inf)
	{
		cout << "File does not exist." << endl;
		exit(0);
	}

	StudentList s1;

	int id;
	std::string name;
	float cgpa;

	while (inf >> id) 
	{
		inf.ignore();			// Ignore the semicolon
		getline(inf, name);		// Read the name
		inf >> cgpa;			// Read the cgpa

		Student newStd(id, name, cgpa, NULL);
		s1.insert(newStd);

		inf.ignore();			// Ignore the blank line
	}

	inf.close();

	s1.showStructure();
	//s1.search(3.5);
	/*studentList.remove(2);
	studentList.showStructure();
	studentList.gotoNext();
	studentList.replace(Student(4, "Aiman", 3.8, NULL));
	studentList.showStructure();*/

	return 0;
}