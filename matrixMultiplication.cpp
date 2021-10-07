//=================================================================================================
// Name        : CS221 Assignment 3
// Author      : Muhammad Adam Ch
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : 2D Dynamic matrix multiplication in class.
//=================================================================================================

#include <iostream> //Using preprocessor directive to include iostream library.
using namespace std;

class matrix2D //Making class of matrix
{
private:
  double **matrix = nullptr; //A pointer to a pointer for 2D array

  int rows = 0;
  int cols = 0;

public:
  matrix2D(int rows, int cols) //Constructor
  {
    this->rows = rows;
    this->cols = cols;

    //Creation of dynamic 2D array.

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new double[cols];
    }
  }

  void fill() //Fucntion to fill the matrix.
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        cout << "Enter value for row # " << i + 1 << " column # " << j + 1 << endl;
        cin >> matrix[i][j];
      }
    }
  }

  bool multipliable(const matrix2D &m) //Function that checks if the matrices are multipliable.
  {
    if (this->cols == m.rows)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  double **matrixMultiply(matrix2D &m) //Function to multiply matrices that returns a double
  {                                    // pointer
    if (multipliable(m))
    {
      cout << "The matrices are multipliable\n";
      cout << endl;

      //Creation of the 3rd product matrix
      double **matrix = nullptr;
      int newRows = this->rows;
      int newCols = m.cols;
      matrix = new double *[newRows];
      for (int i = 0; i < newRows; i++)
      {
        matrix[i] = new double[newCols];
      }

      double sum = 0;
      int count = 0;
      int k = 0, l = 0;

      for (int i = 0; i < this->rows; i++) // loop for iterating through the first matrix
      {

        while (count < m.cols) //Loop for repeating the row elements of first matrix until all
        {                      // the 2nd matrix cols are multiplied.

          for (int j = 0; j < this->cols; j++)
          {
            sum = sum + (this->matrix[i][j] * m.matrix[j][count]);
          }

          count++;

          matrix[k][l] = sum;

          l++;

          if (l >= newCols)
          {
            if (k < newRows)
            {
              k++;
            }
            l = 0;
          }
          sum = 0;
        }

        count = 0;
      }

      return matrix;
    }
    else
    {
      cout << "The matrices are not multipliable\n";
      return nullptr; //returns nullptr if matrices are not multipliable.
    }
  }

  ~matrix2D() //Destructor
  {
    for (int i = 0; i < rows; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
  }
};

int main()
{
  int rows[1] = {};
  int cols[1] = {};

  cout << "Enter number of rows for matrix 1 \n";
  cin >> rows[0];
  cout << "Enter number of columns for matrix 1\n";
  cin >> cols[0];
  cout << "Enter number of rows for matrix 2\n";
  cin >> rows[1];
  cout << "Enter number of columns for matrix 2\n";
  cin >> cols[1];

  matrix2D m1(rows[0], cols[0]), m2(rows[1], cols[1]);

  m1.fill();
  cout << endl
       << endl;
  m2.fill();

  double **product = m1.matrixMultiply(m2);

  cout << "The product matrix is : \n";
  if (product != nullptr)
  {
    for (int i = 0; i < rows[0]; i++)
    {
      for (int j = 0; j < cols[1]; j++)
      {
        cout << product[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0; //The program ends here.
}