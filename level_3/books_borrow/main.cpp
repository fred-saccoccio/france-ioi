#include<iostream>

using namespace std;

#define BOOKS_NUMBER 1000

int main()
{
    int books_number, days_number;
    int books_status[BOOKS_NUMBER] = { 0 };

    cin >> books_number >> days_number;
    
    for(int i = 1; i <= days_number; i++)
    {
        int customers_number;

        cin >> customers_number;

        for(int index = 0; index < BOOKS_NUMBER; index++)
        {
            books_status[index] = max(books_status[index] - 1, 0);
        }
        
        for(int j = 1; j <= customers_number; j++)
        {
            int book_index, duration;

            cin >> book_index >> duration;

            // If the book is not available
            if(books_status[book_index] > 0 )
            {
                cout << "0" << endl;
            }
            else // book available
            {
                cout << "1" << endl;
                books_status[book_index] = duration;
            }
        }
    }
}
