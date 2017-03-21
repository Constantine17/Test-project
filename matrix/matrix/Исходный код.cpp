#include <iostream>
#include <string>

using namespace std;


class Matrix
{
private:
	int size;
	double **matrix;
public:

	Matrix(int s) //constructor
	{
		size = s;
		matrix = new double * [s];
		for (int i = 0; i < size; i++) matrix[i]=new double[s];
	}

	//~Matrix(); //distructor

	void set_rand() // generation random Matrix
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = rand() % 100 + 0;
	}

	void set() // input Matrix
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> matrix[i][j] ;
	}

	void get() //input Matrix on screen
	{

		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++)
			cout << matrix[i][j]<< "	";
		cout << endl;
		}
	}

	Matrix operator + (Matrix matrix2) // sum matrix1 + matrix2
	{
		Matrix sum_matrix(size);
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				sum_matrix.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
				}
		}
		return sum_matrix;
	}

	Matrix operator += (Matrix matrix2) // +=matrix
	{
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				matrix[i][j] += matrix2.matrix[i][j] ;
			}
		}
		return 0;
	}

	Matrix operator - (Matrix matrix2) // subtraction matrix1 and matrix2
	{
		Matrix sum_matrix(size);
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				sum_matrix.matrix[i][j] = matrix[i][j] - matrix2.matrix[i][j];
			}
		}
		return sum_matrix;
	}

	Matrix operator -= (Matrix matrix2) // -=matrix
	{
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				matrix[i][j] -= matrix2.matrix[i][j];
			}
		}
		return 0;
	}
};




int main()
{
	setlocale(0, "");
	int matrix_size = 5;

	Matrix mat1(matrix_size);
	Matrix mat2(matrix_size);
	//mat.set();
	mat1.set_rand();
	mat1.get();
	cout << endl;
	mat2.set_rand();
	mat2.get();
	cout << endl;
	Matrix sum_matrix(matrix_size);
	sum_matrix = mat1 + mat2;
	sum_matrix.get();

	cout << endl;

	sum_matrix -= mat2;
	sum_matrix.get();

	system("pause");
	return 0;
}