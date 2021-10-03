#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
private:
  int *array = nullptr;
  int size = 0;
  int capacity = 0;

public:
  Vector(int size) : size(size)
  {
    if (size < 0)
    {
      size = 1;
    }
    capacity = size + 10;
    array = new int[capacity];
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << array[i] << endl;
    }
  }

  int get(int indx)
  {
    assert(0 <= indx < size);
    return array[indx];
  }

  void set(int indx, int value)
  {
    assert(0 <= indx < size);
    array[indx] = value;
  }

  void expand_capacity()
  {
    capacity *= 2;
    int *temp = new int[capacity];
    for (int i = 0; i < size; i++)
    {
      temp[i] = array[i];
    }
    swap(array, temp);
    delete[] temp;
  }

  void push_back(int value)
  {
    if (size == capacity)
    {
      expand_capacity();
    }
    else
    {
      array[size + 1] = value;
      size++;
    }
  }

  void insert(int indx, int value)
  {
    if (capacity == size)
    {
      expand_capacity();
    }
    else
    {
      for (int i = size - 1; i >= indx; i--)
      {
        array[i + 1] = array[i];
      }
      array[indx] = value;
      size++;
    }
  }

  void rightRotation(int steps)
  {
    int temp = 0;
    for (int i = 0; i < steps; i++)
    {
      temp = array[size - 1];
      for (int i = size - 1; i >= 0; i--)
      {
        array[i] = array[i - 1];
      }
      array[0] = temp;
    }
  }

  void leftRotation(int steps)
  {
    int temp = 0;
    for (int i = 0; i < steps; i++)
    {
      temp = array[0];
      for (int i = 0; i < size - 1; i++)
      {
        array[i] = array[i + 1];
      }
      array[size - 1] = temp;
    }
  }

  void pop(int indx)
  {
    for (int i = indx; i < size; i++)
    {
      array[i] = array[i + 1];
    }
    size--;
  }

  int transpositionSearch(int value)
  {
    for (int i = 0; i < size; i++)
    {
      if (array[i] == value)
      {
        if (i == 0)
        {
          return 0;
        }
        else
        {
          swap(array[i], array[i - 1]);
          return i - 1;
        }
      }
    }
  }
};

int main()
{
  Vector myVector(5);
  int value;
  for (int i = 0; i < 5; i++)
  {
    cin >> value;
    myVector.set(i, value);
  }
  cout<<myVector.transpositionSearch(3)<<endl;
 
}