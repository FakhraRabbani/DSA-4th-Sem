/*
#include"iostream"
#include"fstream"
#include"string"

using namespace std;

//Number of occurrences of particular word in each line of text in file
void countWordOccurrences(const string& fileName, const string& searchWord)
{
	ifstream inf(fileName);

	if (!inf)
	{
		cerr << "File opening Failed" << endl;
		//exit(0);
	}

	string reqWord;

	//Read required/search word from file
	getline(inf, reqWord);

	cout << "Word " << reqWord << " has occurrences of: " << endl;

	string line;

	int lineNo = 1;

	while (getline(inf, line))
	{
		int count = 0;
		int position = 0;

		while ((position = line.find(reqWord, position)) != string::npos)
		{
			count++;
			position += reqWord.length();

		}

		cout << "Line No: " << lineNo << ", Occurrences: " << count << endl;
		lineNo++;
	}

	inf.close();
}

int main()
{
	string fileName = "input3.txt";
	string searchWord = "the";


	countWordOccurrences(fileName, searchWord);


	return 0;
}*/