#include<iostream>

using namespace std;

int main()
{
    int letters;
    cin >> letters;

    int size = 2 * letters - 1;
    int mid_size = size / 2;

    char current_char = 'a';

    for(int line = 0; line < size; line++)
    {
        int lower_bound = min(line, size-1 - line);
        int upper_bound = max(line, size-1 - line);
        current_char = 'a';

        for(int column = 0; column < size; column++)
        {
            if(column <= lower_bound)
            {
                current_char = 'a' + column;
            }
            else if(column > upper_bound)
            {
                current_char--;
            }

            cout << current_char;
        }

        cout << endl;
    }
}
