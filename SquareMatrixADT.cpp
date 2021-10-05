#include <iostream>
using namespace std;

class SquareMatrix
{
private:
  int **matrix = nullptr;

public:
  int n = 0;

  SquareMatrix(int n)
  {
    this->n = n;                //1
    matrix = new int *[n];      //1                   //f(n) = 2n + 2
    for (int i = 0; i < n; i++) //n              //Upper Bound 2n + 2 <=4n
    {                           // Lower Bound 2n+2>=2n
      matrix[i] = new int[n];   //n
    }
  }

  void MakeEmpty(int n)
  {
    for (int i = 0; i < n; i++)   //n+1               //f(n) = 2n^2 + 2n + 1
    {                             //Upper Bound 2n^2 + 2n +1 <= 5n^2
      for (int j = 0; j < n; j++) // n(n+1)         //Lower Bound 2n^2 + 2n + 1 >= 2n^2
      {
        matrix[i][j] = 0; //n^2
      }
    }
  }

  void StoreValue(int i, int j, int value)
  {
    matrix[i][j] = value; //1                        f(n) = 1
  }

  void ADD(SquareMatrix &m1, SquareMatrix &m2)
  {
    if (m1.n == m2.n) //1
    {
      int size = m1.n;                 //1
      for (int i = 0; i < size; i++)   //size + 1                  //f(n) = 3n^2 + 2n + 3
      {                                //Upper Bound 8n^2
        for (int j = 0; j < size; j++) //size(size+1)            //Lower Bound 3n^2
        {
          m1.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j]; //2size^2
        }
      }
    }
    else
    {
      cout << "The order of matrices is not same\n";
    }
  }

  void Subtract(SquareMatrix &m1, SquareMatrix &m2)
  {
    if (m1.n == m2.n) //1
    {
      int size = m1.n;                 //1
      for (int i = 0; i < size; i++)   //n+1                    //f(n) = 3n^2 + 2n +1
      {                                //Upper Bound 8n^2
        for (int j = 0; j < size; j++) //n(n+1)               //Lower Bound 3n^2
        {
          m1.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j]; //2n^2
        }
      }
    }
    else
    {
      cout << "The order of matrices is not same\n";
    }
  }

  void Copy(const SquareMatrix &m)
  {
    for (int i = 0; i < n; i++)              //n+1
    {                                        //f(n) = n^2 + 2n + 1
      for (int j = 0; j < n; j++)            //n(n+1)          //Upper Bound 4n^2
      {                                      //Lower Bound n^2
        this->matrix[i][j] = m.matrix[i][j]; //n^2
      }
    }
  }

  void display()
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

  ~SquareMatrix()
  {
    for (int i = 0; i < n; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
  }
};

int main()
{
  int n = 0;
  int value = 0;
  cout << "Enter Size Of Sqaure Matrix\n";
  cin >> n;
  SquareMatrix m1(n); //Constructor
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "Enter a Value\n";
      cin >> value;
      m1.StoreValue(i, j, value); //Entering data in matrix 1
    }
  }

  SquareMatrix m2(n); // Constructor
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "Enter a Value\n";
      cin >> value;
      m2.StoreValue(i, j, value); //Entering data in matrix 2
    }
  }

  m1.ADD(m1, m2); //Adding m1 and m2
  cout << "The values after adding\n";
  cout << "Matrix 1 : \n";
  m1.display();
  cout << "Matrix 2 : \n";
  m2.display();
  cout << endl;

  m1.Subtract(m1, m2); //Subtracting m1 and m2
  cout << "The values after subtracting\n";
  cout << "Matrix 1 : \n";
  m1.display();
  cout << "Matrix 2 : \n";
  m2.display();
  cout << endl;

  m1.Copy(m2); //Copying m2 to m1;
  cout << "The values after copying : \n";
  cout << "Matrix 1 : \n";
  m1.display();
  cout << "Matrix 2 : \n";
  m2.display();
  cout << endl;

  return 0;
}