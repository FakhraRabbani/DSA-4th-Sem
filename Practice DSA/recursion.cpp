#include"iostream"
#include"string"

using namespace std;

//1.
void print(int n)
{
	cout << n << " ";

	if (n > 1)
		{
			print(n - 1);
	}
}

//2.
int sum(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return sum(n - 1) + n * n;

}


//3.
// 1 + a + a^2 + ... + a^n // Sum of geometric series
double sum(double a, int n)
{
	if (n == 0)
		return 1;
	return 1 + a * sum(a, n - 1);
}


//4.
//Recursive implementation of fibonacci sequence.
//Fibonacci sequence is series of nos where each no is sum of preceding two numbers
//fib(0) = 0
//fib(1) = 1
//fib(2) = fib(1) + fib(0) = 1 + 0 = 1
//fib(3) = fib(2) + fib(1) = 1 + 1 = 2
//fib(4) = fib(3) + fib(2) = 2 + 1 = 3
int fib(int n) 
{
	if (n < 2)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}


//5.
//The function essentially computes the sum of the first n even numbers starting from 2 (2 * 1) up to 2 * n.
//For instance :
//f(3) = 2 + 4 + 6 = 12
//f(4) = 2 + 4 + 6 + 8 = 20

int f(int n)
{
	if (n == 0)
		return 0;
	return f(n - 1) + 2 * n;
}


//6.
//This function uses recursion and performs arithmetic operations on the input parameters.
int f(int a, int b)
{
	if (a <= 0)
		return b;
	else
	{
		int temp = f(a - 2, b * 2);
		temp = temp - a;
		cout << temp << " ";
		return temp;
	}
}


//7.
//Reverse a string
void reverseString(string& str, int start, int end)
{
	if (end < start)
		return;

	cout << str[end];
	reverseString(str, start, end - 1);
}


//
void reverseString2(string& str, int start, int end) {
	if (start > end) {
		return; // Base case: when start meets or exceeds end, stop recursion
	}

	// Swap characters at start and end indices
	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;

	// Recursive call with updated indices
	reverseString2(str, start + 1, end - 1);
}

//

void reverseString3(string& str, int start, int end) {
	if (start >= end) {
		return; // Base case: If start is greater than or equal to end, stop recursion
	}

	// Swap characters at start and end indices
	swap(str[start], str[end]);

	// Recursively call reverseString with updated start and end indices
	reverseString3(str, start + 1, end - 1);
}

int main()
{
	cout << fib(4) << endl;  //3
	cout << sum(2, 3) << endl; //15
	cout << sum(3) << endl; //14
	print(5); //5 4 3 2 1

	cout << endl << f(4) << endl;  //20
	cout << f(5, 4) << endl;  //31 28 23 23

	string name = "Fakhra";
	reverseString(name, 0, 5);

	cout << endl;
	reverseString2(name, 0, 5);
	cout << name << endl;

	string name3 = "sara";
	reverseString3(name3, 0, 3);
	cout << name3 << endl;

	return 0;
}
