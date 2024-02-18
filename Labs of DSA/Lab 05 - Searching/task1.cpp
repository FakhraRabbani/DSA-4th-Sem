/*
#include"iostream"

using namespace std;

//Intersection 1

int intersection1(int A[], int B[], int C[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (A[i] == B[j])
			{
				C[count++] = A[i];
				//break;
			}
		}
	}
		
	return count;
}

//Intersection 2 

int intersection2(int A[], int B[], int C[], int n)
{
	int count = 0, i = 0, j = 0;

	while (i < n && j < n)
	{
		if (A[i] < B[j])
		{
			i++;
		}
		else if (A[i] > B[j])
		{
			j++;
		}
		else
		{
			C[count++] = A[i];
			i++;
			j++;
		}
	}

	return count;
}

int main()
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[5] = { 2, 9, 3, 1, 0 };
	int C[5];

	int count1 = intersection1(A, B, C, 5);

	//Displaying C

	for (int i = 0; i < count1; i++)
	{
		cout << C[i] << " ";
	}

	cout << endl;

	int A1[5] = { 2, 4, 6, 8, 10 };
	int B1[5] = { 1, 2, 3, 10, 5 };
	int C1[5];

	int count2 = intersection2(A1, B1, C1, 5);

	//Displaying C1

	for (int i = 0; i < count2; i++)
	{
		cout << C1[i] << " ";
	}

	cout << endl;

	return 0;
}
*/