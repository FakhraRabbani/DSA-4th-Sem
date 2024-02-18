#include"iostream"

using namespace std;

//Working Horse
int  rBinarySearch(int A[], int low, int high, int key)
{
	if (low > high) //Unsuccessful Base Case 
		return -1;
	
	int mid = low + (high - low) / 2;

	if (A[mid] == key) //Successful Base Case
		return mid;
	else if(A[mid] > key)
		return  rBinarySearch(A, low, mid - 1, key); //Recursion Step //Left half array
	else
		return  rBinarySearch(A, mid + 1, high, key); //Recursion Step  //Right half  array
}

//For User
int search(int A[], int size, int key)
{
	if (size <= 0)
		return -1;

	return rBinarySearch(A, 0, size-1, key);
}


//Complexity : O(lgn)
//Works on sorted arrays only

int main()
{
	int A1[5] = { 1, 2, 3, 4, 5 };
	

	cout << search(A1, 5, 6) << endl; //-1
	cout << search(A1, 5, 2) << endl;  //1


	return 0;
}

