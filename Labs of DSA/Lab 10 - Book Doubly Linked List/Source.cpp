#include "iostream"
#include "fstream"
#include "string"

using namespace std;

class Book
{
	friend class BookList;
private:
	int id;			 /**id of a book.*/
	string title;	 /**name of a book.*/
	float price;	 /**price of a book.*/
	Book* next;      /**address of the next available object.*/
	Book* pre;       /**address of the previous available object.*/
public:
	Book(int id, string title, float price, Book* next, Book* pre)	/**constructor*/
	{
		this->id = id;
		this->title = title;
		this->price = price;
		this->next = next;
		this->pre = pre;
	}

	void bookDetails()	 /**displays the book informaton*/
	{
		cout << "ID = " << id << "\tTITLE = " << title << "\t\tPRICE = " << price << endl;
	}
};


class BookList
{
private:
	Book* head; /**first item of the list*/
	Book* cursor; /**current item of the list*/
	Book* last; /**last item of the list*/
public:
	BookList() /**constructor*/
	{
		head = NULL;
		cursor = NULL;
		last = NULL;
	}

	~BookList() /**destructor*/
	{
		while (head != NULL)
		{
			Book* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void insert(const Book& newItem)
	{
		Book* newBook = new Book(newItem.id, newItem.title, newItem.price, NULL, NULL);

		if (head == NULL)
		{
			head = newBook;
			cursor = newBook;
			last = newBook;
		}
		else
		{
			newBook->next = cursor->next;
			newBook->pre = cursor;

			if (cursor->next != NULL)
			{
				cursor->next->pre = newBook;
			}
			else
			{
				last = newBook;
			}

			cursor->next = newBook;
			cursor = newBook;
		}
	}

	void remove()
	{
		if (head == NULL)		// empty
		{
			cout << "List is empty.." << endl;
		}
		else
		{
			Book* temp = cursor;

			// start
			if (cursor->pre != NULL)
			{
				cursor->pre->next = cursor->next;
			}
			else
			{
				head = cursor->next;
			}

			// last
			if (cursor->next != NULL)
			{
				cursor->next->pre = cursor->pre;
			}
			else
			{
				last = cursor->pre;
			}

			cursor = cursor->pre;
			delete temp;
		}
	}

	void search(string title) 
	{
		Book* current = head;
		bool found = false;

		while (current != NULL) 
		{
			if (current->title == title) 
			{
				current->bookDetails();
				found = true;
			}

			current = current->next;
		}

		if (!found) 
		{
			cout << "Book not found." << endl;
		}
	}

	void replace(const Book& newItem) 
	{
		Book* newBook = new Book(newItem.id, newItem.title, newItem.price, newItem.pre, newItem.next);

		if (head != NULL && cursor != NULL) 
		{
			cursor->id = newItem.id;
			cursor->title = newItem.title;
			cursor->price = newItem.price;
		}

		cursor = newBook;
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
		cursor = last;
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
		if (cursor != NULL && cursor->pre != NULL) 
		{
			cursor = cursor->pre;
			return true;
		}
		return false;
	}

	Book getCursor() 
	{
		if (cursor != NULL) 
		{
			return *cursor;
		}
		cout << "Cursor is not pointing to a valid book." << endl;
	}


	void showStructureForward() const
	{
		Book* current = head;
		
		if (head == NULL)
		{
			cout << "Empty List..." << endl;
		}

		while (current != NULL)
		{
			current->bookDetails();
			current = current->next;
		}
	}

	void showStructureReverse() const
	{
		if (head == NULL)
		{
			cout << "Empty List..." << endl;
		}
		else
		{
			Book* temp = last;
			while (temp != NULL)
			{
				temp->bookDetails();
				temp = temp->pre;
			}
		}
	}

};


int main()
{
	ifstream inf("input.txt");

	if (!inf)
	{
		cout << "File does not exist";
		exit(0);
	}

	BookList bookList;
	int id;
	string title;
	float price;

	while (inf >> id) 
	{
		inf.ignore();			// Ignore the newline character
		getline(inf, title);
		inf >> price;
		inf.ignore();			// Ignore the blank line

		Book newBook(id, title, price, NULL, NULL);
		bookList.insert(newBook);
	}

	Book newBook1(13, "python", 1200, NULL, NULL);
	Book newBook2(15, "java", 1300, NULL, NULL);

	//bookList.insert(newBook1);

	//bookList.gotoBeginning();

	bookList.replace(newBook1);

	bookList.showStructureForward();



	//bookList.search("Visual C");

	//bookList.remove();

	//bookList.showStructureForward();

	//bookList.showStructureReverse();

	inf.close();


	return 0;
}