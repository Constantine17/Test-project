#include <iostream>
#include <string>

using namespace std;


class Matrix
{
private:
	int size;
	double **matrix;
public:

	Matrix(int s)
	{
		size = s;
		matrix = new double * [s];
		for (int i = 0; i < size; i++) matrix[i]=new double[s];
	}

	//~Matrix();

	void set_rand()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = rand() % 100 + 0;
	}

	void set()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> matrix[i][j] ;
	}

	void get()
	{

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			cout << matrix[i][j]<< "	";
		cout << endl;
		}
	}
};




int main()
{
	setlocale(0, "");


	Matrix mat(5);
	//mat.set();
	mat.set_rand();
	mat.get();


	system("pause");
	return 0;
}