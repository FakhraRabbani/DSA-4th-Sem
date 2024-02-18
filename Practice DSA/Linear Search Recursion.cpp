#include"iostream"

using namespace std;

//Working Horse
int  rLinearSearch(int A[], int index, int key)
{
	if (index < 0) //Unsuccessful Base Case
		return -1;
	else if (A[index] == key) //Successful Base Case
		return index;
	else
		return  rLinearSearch(A, index - 1, key); //Recursion Step
}

//For User
int search(int A[], int size, int key)
{
	if (size <= 0)
		return -1;

	return rLinearSearch(A, size - 1, key);
}


//Complexity : O(n)
//Works on both sorted and unsorted arrays

int main()
{
	int A1[5] = { 1, 2, 3, 4, 5 };
	int A2[6] = { 98, 66, 78, 43, 22, 44 };

	cout << search(A1, 5, 6) << endl; //-1
	cout << search(A1, 5, 2) << endl;  //1
	cout << search(A2, 6, 6) << endl;  //-1
	cout << search(A2, 6, 22) << endl; //4



	return 0;
}
