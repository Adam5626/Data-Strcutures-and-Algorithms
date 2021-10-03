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
    capacity = size + 100;
    array = new int[capacity];
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
  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << array[i] << endl;
    }
  }

  string find(int value)
  {
    for (int i = 0; i < size; i++)
    {
      if (array[i] == value)
      {
        return "Found";
      }
    }
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
    if (capacity == value)
    {
      expand_capacity();
    }
    array[size++] = value;
  }

  void insert_element(int indx, int value)
  {
    if (capacity == size)
    {
      expand_capacity();
    }
    for (int i = size - 1; i >= indx; i--)
    {
      array[i + 1] = array[i];
    }
    array[indx] = value;
    size++;
  }
};

int main()
{
  Vector myVector(6);
  cout << "Setting values to vector\n";
  for (int i = 0; i < 6; i++)
  {
    myVector.set(i, i);
  }
  cout << "Finding a value\n";
  cout << myVector.find(4) << endl;
  cout << "Fetching a value at index\n";
  cout << myVector.get(2) << endl;
  ;

  cout << "Pushing Back Value\n";
  myVector.push_back(55);
  myVector.push_back(65);
  myVector.print();
  myVector.insert_element(0, 69);

  cout << "Printing Values\n";
  myVector.print();

  return 0;
}
