#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

bool delimitersOk( const string &expression ) 
{
	stack<char> one;

	for(int i = 0; i < expression.length(); i++)
	{
		if( expression[i] == '(' || expression[i] == '{' || expression[i] == '[' )
		{
			one.push(expression[i]);
		}
		else if(expression[i] == ')')
		{
			if(one.top() == '(')
			{
				one.pop();
			}
			else
			{
				return false;
			}
		}
		else if(expression[i] == '}')
		{
			if(one.top() == '{')
			{
				one.pop();
			}
			else
			{
				return false;
			}
		}
		else if(expression[i] == ']')
		{
			if(one.top() == '[')
			{
				one.pop();
			}
			else
			{
				return false;
			}
		}
	}
	
	return one.empty();
}




int main()
{

	ifstream inputfile;
	int size;
	string str;


	inputfile.open("input.txt");
	if (!inputfile)
	{ 
      cerr << "Error: file could not be opened" << endl;
      exit(1);
	}	

	inputfile >> size;

	getline(inputfile, str);
	for(int i = 0; i < size; i++)
	{
		getline(inputfile, str);
		if(delimitersOk(str))
		{
			cout << "Valid" << endl;
		}
		else 
		{
			cout << "Invalid" << endl;
		}
	}
	inputfile.close();

	return 0;
}