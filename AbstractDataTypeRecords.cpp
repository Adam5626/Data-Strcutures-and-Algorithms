#include <iostream>
#include <cassert>
using namespace std;

class Record
{
private:

    int pages = 0;
    int rows = 0;
    int cols = 0;
    int noOfBooks = 0;
    string**** record;

public:
    Record(int books, int pages, int rows, int cols)
    {

        this->noOfBooks = books;
        this->pages = pages;
        this->rows = rows;
        this->cols = cols;

        record = new string ***[books];
        for (int i = 0; i < books; i++)
        {
            record[i] = new string **[pages];
        }
        for (int i = 0; i < books; i++)
        {
            for (int j = 0; j < pages; j++)
            {
                record[i][j] = new string * [rows];
            }
        }
        for (int i = 0; i < books; i++)
        {
            for (int j = 0; j < pages; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    record[i][j][k] = new string[cols];
                }
            }
        }
    }

    void push_back(int book, int page, int row, int col, string data)
    {
        assert(0 <= book <= this->noOfBooks && 0 <= page <= this->pages && 0 <= row <= this->rows && 0 <= col <= this->cols);
        *(*(*(*(record + book) + page) + row) + col) = data;

    }

    string read(int book, int page, int row, int col)
    {
        assert(0 <= book <= this->noOfBooks && 0 <= page <= this->pages && 0 <= row <= this->rows && 0 <= col <= this->cols);
         return *(*(*(*(record + book) + page) + row) + col) ;
    }

    void delete_element(int book, int page, int row, int col)
    {
        assert(0 <= book <= this->noOfBooks && 0 <= page <= this->pages && 0 <= row <= this->rows && 0 <= col <= this->cols);
        *(*(*(*(record + book) + page) + row) + col)  = "0";
    }

    ~Record()
    {
        for (int i = 0; i < noOfBooks; i++)
        {
            for (int j = 0; j < pages; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    delete[] record[i][j][k];
                }
                delete[] record[i][j];
            }
            delete[] record[i];
        }

        delete[] record;

        record = nullptr;
    }

};


int main()
{
    
  
    int books = 0;
    int pages = 0;
    int rows = 0;
    int cols = 0;

    cout << "How many books do you want to add\n";
    cin >> books;
    cout << "How many pages do you want to add\n";
    cin >> pages;
    cout << "How many rows do you want to add\n";
    cin >> rows;
    cout << "How many columns do you want\n";
    cin >> cols;

    string data;

    Record myRecord(books, pages, rows, cols);
    cout << "Entering data in the record\n";
    for (int i = 0; i < books; i++)
    {
        for (int j = 0; j < pages; j++)
        {
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < cols; l++)
                {
                    cout << "Book # " << i + 1 << " Page # " << j + 1 << " Row # " << k + 1 << " Column # " << l + 1 << endl;
                    cin >> data;
                    myRecord.push_back(i, j, k, l, data);
                }
            }
        }
    }

    cout << "Updating data\n";
    cout << "Enter book #\n";
    cin >> books;
    cout << "Enter page #\n";
    cin >> pages;
    cout << "Enter row #\n";
    cin >> rows;
    cout << "Enter col #\n";
    cin >> cols;
    cout << "Enter data\n";
    cin >> data;
    myRecord.push_back(books-1, pages-1, rows-1, cols-1, data);

    cout << "Deleting Data \n";
    cout << "Enter book #\n";
    cin >> books;
    cout << "Enter page #\n";
    cin >> pages;
    cout << "Enter row #\n";
    cin >> rows;
    cout << "Enter col #\n";
    cin >> cols;
    myRecord.delete_element(books - 1, pages - 1, rows - 1, cols - 1);

    cout << "Reading Data \n";
    cout << "Enter book #\n";
    cin >> books;
    cout << "Enter page #\n";
    cin >> pages;
    cout << "Enter row #\n";
    cin >> rows;
    cout << "Enter col #\n";
    cin >> cols;
    cout << myRecord.read(books - 1, pages - 1, rows - 1, cols - 1);


}