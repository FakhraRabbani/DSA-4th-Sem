#include"iostream"
#include"stack"

using namespace std;

int main()
{
	stack<int>s1;

	cout << s1.empty() << endl; //1
	cout << s1.size() << endl;  //0

	s1.push(7);
	s1.push(9);
	s1.push(88);

	cout << s1.empty() << endl;  //0
	cout << s1.size() << endl;   //3

	cout << "Top: " << s1.top() << endl;  //88

	s1.pop();

	cout << s1.empty() << endl;  //0
	cout << s1.size() << endl;   //2

	cout << "Top: " << s1.top() << endl;  //9

	s1.pop();
	s1.pop();

	cout << s1.empty() << endl;  //1

	//cout << s1.top() << endl;  //Prgrm crash
	//s1.pop();   /Prgrm crash
	//Before pop or getting top, check if stack is empty or not and dont pop or get top if it is empty otherwise prgrm will crash


	return 0;
}