//#include "iostream"
//#include "fstream"
//#include "string"
//#include "stack"
//
//using namespace std;
//
//bool delimitersOk(const string& expression)
//{
//	stack<char> one;
//
//	for (int i = 0; i < expression.length(); i++)
//	{
//		char ch = expression[i];
//
//		if (ch == '(')
//		{
//			one.push(ch);
//		}
//		else if (ch == ')')
//		{
//			if (one.empty() || one.top() != '(')
//			{
//				return false;
//			}
//			else
//			{
//				one.pop();
//			}
//		}
//		else if (ch == '}')
//		{
//			if (one.empty() || one.top() != '{')
//			{
//				return false;
//			}
//			else
//			{
//				one.pop();
//			}
//		}
//		else if (ch == ']')
//		{
//			if (one.empty() || one.top() != '[')
//			{
//				return false;
//			}
//			else
//			{
//				one.pop();
//			}
//		}
//	}
//
//	return one.empty();
//}
//
//
//
//
//int main()
//{
//	string str;
//	ifstream inputFile("input.txt");
//	
//	if (!inputFile)
//	{
//		cerr << "Error: file could not be opened" << endl;
//		exit(1);
//	}
//
//	int size;
//
//	inputFile >> size;
//
//	getline(inputFile, str);
//	for (int i = 0; i < size; i++)
//	{
//		getline(inputFile, str);
//		if (delimitersOk(str))
//		{
//			cout << "Valid" << endl;
//		}
//		else
//		{
//			cout << "Invalid" << endl;
//		}
//	}
//	inputFile.close();
//
//	return 0;
//}