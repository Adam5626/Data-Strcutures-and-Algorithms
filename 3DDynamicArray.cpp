//============================================================================
// Name        : Dynamic array3D.
// Author      : Muhammad Adam Ch.
// Version     : 1.0.
// Copyright   : Your copyright notice.
// Description : 3D Dynamic Array Class with functions fill() and display().
//============================================================================

#include <iostream> //using preprocessor directive to include iostream library
using namespace std;

class array3D //Class of 3D array
{
private:
  char ***matrix; // a character pointer to a pointer to a pointer
  int rows = 0;
  int cols = 0;
  int sheets = 0;

public:
  array3D(int sheets, int rows, int cols) //Constructor
  {

    this->sheets = sheets;
    this->rows = rows;
    this->cols = cols;

    // Creation Of a 3D array

    matrix = new char **[sheets];
    for (int i = 0; i < sheets; i++)
    {
      matrix[i] = new char *[rows];
      for (int j = 0; j < rows; j++)
      {
        matrix[i][j] = new char[cols];
      }
    }
  }

  void fill() //Function to fill data in the array.
  {
    for (int i = 0; i < sheets; i++)
    {
      cout << "Sheet # " << i + 1 << endl;
      for (int j = 0; j < rows; j++)
      {
        for (int k = 0; k < cols; k++)
        {
          cout << "Enter Value for row# " << j + 1 << " col # " << k + 1 << endl;
          cin >> matrix[i][j][k];
        }
      }
    }
  }

  void display() //Function to display elememts of array.
  {
    for (int i = 0; i < sheets; i++)
    {
      cout << "Sheet # " << i + 1 << endl;
      for (int j = 0; j < rows; j++)
      {
        for (int k = 0; k < cols; k++)
        {
          cout << matrix[i][j][k] << " ";
        }
        cout << endl;
      }
      cout << endl
           << endl;
    }
  }

  ~array3D() //Destructor for clearing the memory dynamic arrays.
  {
    for (int i = 0; i < sheets; i++)
    {
      for (int j = 0; j < rows; j++)
      {
        delete[] matrix[i][j];
      }
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr; //Assigning nullptr to matrix pointer.
  }
};

int main()
{
  int rows = 0;
  int cols = 0;
  int sheets = 0;

  cout << "Enter no of sheets\n";
  cin >> sheets;
  cout << "Enter number of rows\n";
  cin >> rows;
  cout << "Enter number of columns\n";
  cin >> cols;

  array3D myArray(sheets, rows, cols);

  myArray.fill();
  myArray.display();

  return 0;
}
