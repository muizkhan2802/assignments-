#include <iostream>
using namespace std;
class Matrix {
	int numRows;
	int numCols;
	int** matrix;
public:
	Matrix()
	{
		cout << "default cons called" << endl;
	}
	Matrix(int numRows, int numCols)
	{
		this->numRows = numRows;
		this->numCols = numCols;	//cout<<"cons called"<<endl;
		matrix = new int* [numRows];
		for (int i = 0; i < numRows; i++) {
			*(matrix + i) = new int[numCols];
		}
	}

	~Matrix()
	{
		for (int i = 0; i < numRows; i++)
		{
			delete[] * (matrix + i);
		}

		delete[]matrix;
		matrix = 0;
	}

	int getNumRows()
	{
		return numRows;
	}

	int getNumCols()
	{
		return numCols;
	}

	//operator overloading format:--> returnType operator symbol (arguments)
	//unary minus
	//negates all values of the matrix.
	void operator-()
	{
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				matrix[i][j] *= -1;
			}
		}
	}

	Matrix operator+ (Matrix obj)
	{
		//first off, the number of rows and columns should be equal in both
		// matrices so that addition can take place. This should be condition.
		//if (numRows == obj.numRows && numCols == obj.numCols) {
		Matrix temp(numRows, numCols);
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
			}
		}
		return temp;
		//}
		//else {
			//Matrix temp;
		//	cout << "The order of the matrices is not equal thus addition not possible" << endl;
			//return temp;
		//}
	}

	Matrix operator-(Matrix& obj)
	{
		//first off, the number of rows and columns should be equal in both
		// matrices so that subtraction can take place. This should be condition.

	//	if (numRows == obj.numRows && numCols == obj.numCols) {
		Matrix temp(numRows, numCols);
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				temp.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
			}
		}
		return temp;
		//	}

		//	else {
			//	cout << "The order of the matrices is not equal thus subtraction NOT POSSIBLE" << endl;
		//	}
	}

	Matrix operator*(Matrix& obj) {
		int sum = 0;
		Matrix temp(numRows, obj.numCols);
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				sum = 0;
				for (int k = 0; k < numCols; k++) {
					sum += (matrix[i][k] * obj.matrix[k][j]);
				}
				temp.matrix[i][j] = sum;
			}
		}
		return temp;
	}

	int* operator[] (int n)  //remember format. int n is necessary.
	{
		return matrix[n];
	}

	void operator=(const Matrix& o)
	{
		numRows = o.numRows;
		numCols = o.numCols;

		matrix = new int* [numRows];
		for (int i = 0; i < numRows; i++) {
			*(matrix + i) = new int[numCols];
			for (int j = 0; j < numCols; j++) {
				matrix[i][j] = o.matrix[i][j];
			}
		}
		cout << "Assignment operator called" << endl;
	}

	Matrix(const Matrix& m) {
		numRows = m.numRows;
		numCols = m.numCols;

		matrix = new int* [numRows];
		for (int i = 0; i < numRows; i++) {
			*(matrix + i) = new int[numCols];
			for (int j = 0; j < numCols; j++) {
				matrix[i][j] = m.matrix[i][j];
			}

		}
		cout << "deep copy constructor called" << endl;
	}



	friend istream& operator >>(istream& cin, Matrix& m); //insertion
	friend ostream& operator <<(ostream& cout, Matrix& m); //extraction
};

ostream& operator<< (ostream& cout, Matrix& obj)
{
	int rows = obj.getNumRows();
	int cols = obj.getNumCols();
	cout << "prints the matrix" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << obj.matrix[i][j] << " ";
		}
		cout << endl;
	}
	return cout;
}

istream& operator >>(istream& cin, Matrix& obj)
{
	cout << "input values into matrix" << endl;
	int rows = obj.getNumRows();
	int cols = obj.getNumCols();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> obj.matrix[i][j];
		}
	}
	return cin;
}


int main()
{
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	cin >> m1;
	cout << m1;
	cin >> m2;
	cout << m2;
	Matrix m3 = m1 + m2;
	cout << m3;
	Matrix m4 = m1 * m2;
	cout << m4;


	system("pause");
	return 0;
}