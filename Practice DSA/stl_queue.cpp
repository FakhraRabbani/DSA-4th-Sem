#include"iostream"
#include"queue"

using namespace std;

int main()
{
	queue<int>q1;

	cout << q1.size() << endl; //0

	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << q1.size() << endl; //3
	cout << "Front: " << q1.front() << endl; //1
	cout << "Rear: " << q1.back() << endl; //3

	q1.pop();

	cout << q1.size() << endl; //2
	cout << "Front: " << q1.front() << endl; //2
	cout << "Rear: " << q1.back() << endl; //3

	q1.pop();
	q1.pop();

	cout << q1.size() << endl; //0
	cout << q1.empty() << endl; //1

	//q1.pop();  //Prgrm crash
	//cout << "Front: " << q1.front() << endl; //Prgrm crash
	//cout << "Rear: " << q1.back() << endl;   //Prgrm crash

	//Before pop or getting front and back(rear), check if queue is empty or not and dont pop or get front, back if it is empty otherwise prgrm will crash

	return 0;
}