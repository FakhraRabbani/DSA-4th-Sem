
#include"iostream"
#include"fstream"
#include"string"
#include"stdio.h"
#include"cstdio"

using namespace std;

class Student
{
	int id;
	float marks;

	friend istream& operator >> (istream &, Student&);

	friend ostream& operator << (ostream&, const Student&);

public:

	Student(int id = 0, float marks = 0.0f) {
		this->id = id;
		this->marks = marks;
	}

	//Add Students
	void addStudent(ofstream *outf) {


		if (outf) {
			outf ->write(reinterpret_cast<char*>(this), sizeof(Student));
			cout << "Student Data added successfully" << endl;
		}
		else
		{
			cout << "Student Data did not add successfully" << endl;
		}
		
	}

	//Display Students
	static void displayAllStudent(ifstream *inf) {

		if (!inf) {
			cerr << "Error in opening file" << endl;
			exit(0);
		}

		Student temp;

		inf->read(reinterpret_cast<char*>(&temp), sizeof(temp));

		while (!inf -> eof()) {

			cout << temp;
			inf -> read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
		
	}

	//Find Students
	bool findStudent(ifstream *inf) {

		if (!inf) {
			cerr << "Failed to open file" << endl;
			exit(0);
		}

		Student temp;

		while (!inf->eof()) {

			inf->read(reinterpret_cast<char*>(&temp), sizeof(temp));

			if (this->id == temp.id && this->marks == temp.marks) {
				return true;
			}			
		}

		return false;
		
	}

	//Delete Students
	void deleteStudent(ifstream* inf) {
		
		Student tempStudent;

		ofstream temp("temp.dat", ios::binary);

		if (!temp) {
			cerr << "Failed to open file" << endl;
			exit(0);
		}

		cout << "Successfull" << endl;


		while (!inf->eof()) {
			inf->read(reinterpret_cast<char*>(&tempStudent), sizeof(temp));

			if (tempStudent.id == this->id && tempStudent.marks == this->marks) {
				continue;
			}

		 temp.write(reinterpret_cast<char*>(&tempStudent), sizeof(temp));

		}

		temp.close();
		inf->close();

		remove("check.dat");
		rename("temp.dat", "check.dat");

	  
	}
};

istream& operator >> (istream& cin, Student& std) {

	cout << "Enter student id: ";
	cin >> std.id;

	cout << "Enter std marks: ";
	cin >> std.marks;

	return cin;
}

ostream& operator << (ostream&, const Student& std) {

	cout << "Id: " << std.id << "\t" << "Std marks: " << std.marks << endl;
	return cout;
}

int main() {

	ofstream file("student.dat");

	Student obj1(1, 1.1f), obj2(2, 2.2), obj3(3, 3.3), temp;

	ofstream outf("check.dat", ios::binary);

	if (!outf) {
		cout << "File creation failed" << endl;
		exit(0);
	}

	cout << "File successfully created" << endl;

	obj1.addStudent(&outf);
	obj2.addStudent(&outf);
	obj3.addStudent(&outf);

	outf.close();

	ifstream inf("check.dat", ios::binary);

	if (!inf) {
		cout << "File opening failed" << endl;
		exit(0);
	}

	cout << "File successfully opened" << endl;

	cout << "Status(Found / Not Found): " << temp.findStudent(&inf) << endl;

	inf.close();

	ifstream inf1("check.dat", ios::binary);

	if (!inf1) {
		cout << "File opening failed" << endl;
		exit(0);
	}

	cout << "File successfully opened" << endl;

	Student::displayAllStudent(&inf1);

	inf1.close();

	return 0;

}
