#include <iostream>
using namespace std;

class Matrix
{
private:
  int **matrix;
  int rows = 0;
  int cols = 0;

public:
  Matrix(int rows, int cols)
  {
    this->rows = rows;
    this->cols = cols;

    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new int[cols];
    }
  }

  bool isSquare()
  {
    if (this->rows == this->cols)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void populateMatrix()
  {
    for (int i = 0; i < rows; i++)
    {
      cout << "Enter rows # " << i + 1 << " : " << endl;
      for (int j = 0; j < cols; j++)
      {
        cin >> matrix[i][j];
      }
    }
  }

  int sumAll()
  {
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        sum = sum + matrix[i][j];
      }
    }
    return sum;
  }

  int sumDiagonal()
  {

    if (isSquare())
    {
      int sum = 0;
      for (int i = 0; i < rows; i++)
      {
        for (int j = 0; j < cols; j++)
        {
          if (i == j)
          {
            sum = sum + matrix[i][j];
          }
        }
      }
      return sum;
    }
    else
    {
      cout << "The matrix is not square\n";
    }
  }

  int sumUpperDiagonal()
  {

    if (isSquare())
    {
      int sum = 0;

      for (int i = 0; i < rows; i++)
      {
        for (int j = i + 1; j < cols; j++)
        {
          sum = sum + matrix[i][j];
        }
      }

      return sum;
    }
    else
    {
      cout << "The matrix is not square\n";
    }
  }

  int sumLowerDiagonal()
  {
    if (isSquare())
    {
      int sum = 0;
      for (int i = rows - 1; i > 0; i--)
      {
        for (int j = 0; j < i; j++)
        {
          sum = sum + matrix[i][j];
        }
      }

      return sum;

    }
  }

  void printMatrix()
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }

  ~Matrix()
  {
    for(int i=0;i<rows;i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
  }
};

int main()
{

  Matrix m(4, 4);
  m.populateMatrix();
  m.printMatrix();
  cout<<endl;
  cout << "The sum of all elements is : " << m.sumAll() << endl;
  cout<<endl;
  cout << "The sum of all the diagonal elements are : " << m.sumDiagonal() << endl;
  cout<<endl;
  cout << "The sum of upper diagonal elements is : " << m.sumUpperDiagonal() << endl;
  cout<<endl;
  cout<<"The sum of lower diagonal elements is : "<<m.sumLowerDiagonal()<<endl;
  cout<<endl;
  return 0;
}