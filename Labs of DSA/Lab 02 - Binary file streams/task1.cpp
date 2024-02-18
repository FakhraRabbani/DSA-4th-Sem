/*
#include"iostream"
#include"fstream"
#include"string"
#include"stdio.h"

using namespace std;

void arrayToFile(const char* fileName, int* arr, int size) {

	fstream outf(fileName, ios::binary | ios::out);

	if (!outf) {
		cerr << "Error in file opening";
		exit(0);
	}

	cout << "File has been opened to write" << endl;

	outf.write(reinterpret_cast<char*>(arr), sizeof(int) * size);

	outf.close();
}

void fileToArray(const char* fileName, int* arr, int size) {

	fstream inf(fileName, ios::binary | ios::in);

	if (!inf) {
		cerr << "Error in file opening";
		exit(0);
	}

	cout << "File opened for reading" << endl;

	inf.read(reinterpret_cast<char*>(arr), sizeof(int) * size);

	inf.close();
}

int main() {

	int array[] = { 1, 2, 3, 4, 5 };

	const int size = sizeof(array) / sizeof(int);

	//Write an array to file
	arrayToFile("file.dat", array, size);
	cout << "File has been wrote" << endl;

	int newArray[size];

	//Read from file
	fileToArray("file.dat", newArray, size);
	cout << "File has been read" << endl;

	for (int i = 0; i < size; i++) {
		cout << newArray[i] << endl;
	}

	return 0;
}
*/