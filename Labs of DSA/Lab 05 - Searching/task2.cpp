

#include"iostream"

using namespace std;

int findKthSmallest(int A[], int n, int k)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int pt = A[high];
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (A[j] <= pt)
			{
				i++;
				swap(A[i], A[j]);
			}
		}

		swap(A[i + 1], A[high]);


		if ((i + 1) == (k - 1))
		{
			return A[i + 1]; //Smallest kth no return
		}
		else if ((i + 1) < (k - 1))
		{
			low = i + 2;
		}
		else
		{
			high = i;
		}

	}


	return -1;  //Invalid
}



//int findKthSmallest(int A[], int n, int k)
//{
//	int i = 0;
//
//	for (int j = 0; j < n - 1; j++)
//	{
//		i = i + 1;
//
//		while (i > 0 && A[i] < A[i - 1])
//		{
//			swap(A[i], A[i - 1]);
//			i--;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << A[i] << " ";
//
//	return A[k - 1];
//}


int main()
{
	int A[6] = {6, 4, 1, 2, 5, 8};

	int k = 4;

	int smallestKthNumber = findKthSmallest(A, 6, k);

	cout << smallestKthNumber << endl;

	return 0;
}


