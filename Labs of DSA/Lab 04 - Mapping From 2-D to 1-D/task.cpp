#include "iostream"

using namespace std;

class Matrix
{
	int* p;
	int rows;
	int cols;

public:

	//Constructor
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;

		p = new int[rows * cols]();
	}

	//Destuctor
	~Matrix()
	{
		if(p == NULL)
			delete[] p;
	}

	//Getting element stored at ith row and j column
	int get(int i, int j)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			cout << "Index out of bounds" << endl;
		}
		else
		{
			return p[i * cols + j];
		}
	}

	//Setting value stored at ith row and jth column
	void set(int i, int j, int v)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			cout << "Index out of bounds" << endl;
		}
		else
		{
			p[i * cols + j] = v;
		}
	}

	//Printing matrix on screen in 2-D form
	void print()
	{		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
			{
				cout << p[i * cols + j] << " ";
			}
			cout << endl;
		}
			
	}

	//Transpose of matrix
	void transpose()
	{
		Matrix transposeMatrix(cols, rows);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				transposeMatrix.p[j * rows + i] = p[i * cols + j];
			}
		}
		
		*this = transposeMatrix;
	}

	//Display elements of sub-matrix
	void printSubMatrix(int r1, int r2, int c1, int c2)
	{
		if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows || c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols)
		{
			cout << "Error!! Invalid range!";
		}
		else
		{
			for (int i = r1; i <= r2; i++) {
				for (int j = c1; j <= c2; j++) {
					cout << p[i * cols + j] << " ";
				}
				cout << endl;
					
			}
				

		}

	}

	//Set first n rows and columns to zero
	void makeEmpty(int n)
	{ /*
		//if(n <=0 || n > min(rows, cols)
		if (n > 0 && n < rows )
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					p[i * cols + j] = 0;
				}				
		}
		else
		{
			cout << "Invalid n" << endl;			
		}		*/

		if (n <= rows && n <= cols)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					p[i * cols + j] = 0;
				}
		}
		else
		{
			cout << "Invalid n" << endl;
		}
	}

	//Adding Matrix
	void add(Matrix first, Matrix second)
	{
		if (first.rows != second.rows || first.cols != second.cols || first.rows != this->rows || first.cols != this->cols )
		{
			cout << " These matrices cant be added due to change in dimesnions of both matrices" << endl;
		}
		else
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
				  p[i * cols + j] = first.p[i * cols + j] + second.p[i * cols + j];
		}
	}
};

int main()
{
	Matrix A(4, 5);
	//cout << "A: ";
	//A.print();
	cout << endl;
	A.set(0, 0, 1);

	cout << "A: " << endl;
	A.print();
	cout << endl;

	//Matrix B(5, 4);
	Matrix C(4, 5);
	//C.add(A, B);

	Matrix D(4, 5);
	D.set(0, 0, 5);
	D.set(1, 2, 6);
	cout << "D: " << endl;
	D.print();
	cout << endl;
	C.add(A, D);
	cout << "C: " << endl;
	C.print();
	cout << endl;

	cout << "Sub-Matrix of D: ";
	D.printSubMatrix(1, 2, 2, 3);
	cout << endl;

	C.transpose();
	cout << "Transpose of C: " << endl;
	C.print();
	cout << endl;

	cout << "Making specific rows null : " << endl;
	C.makeEmpty(2);
	C.print();

	//D.makeEmpty(3);
	//D.print();

	cout << "Value at row 0 and column 0 in A:" << A.get(0, 0) << endl;
	

	return 0;
}