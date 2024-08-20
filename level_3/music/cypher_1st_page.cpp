#include <bits/stdc++.h>
using namespace std;

int main()
{
  char key[26];
  string sKey;
  cin >> sKey;
  cin.ignore();
  string cypheredPhrase;
  getline(cin, cypheredPhrase);

  for(int i = 0; i < 26; i++)
  {
    key[i] = sKey[i];
  }

  for(long unsigned int i = 0; i < cypheredPhrase.length(); i++)
  {
    char current_char = cypheredPhrase[i];
    if(isalpha(current_char)) // Check if it is a letter
    {
      if(isupper(current_char)) // Process upper case letter
      {
        current_char = tolower(current_char); // Set it to lower case
        cout << (char)toupper(key[(int)(current_char - 'a')]); // Decypher and set it back to upper case 
      }
      else // Lower case : just decypher
      {
        cout << key[(int)(current_char - 'a')];
      }
    }
    else // Not a letter
    {
      cout << current_char;
    }
  }

  cout << endl;

  return 0;
}