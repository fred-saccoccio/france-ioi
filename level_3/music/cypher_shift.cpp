#include <bits/stdc++.h>
using namespace std;

int getShift(int page)
{
  int retVal = 0;
  if(page%2 == 0)
  {
    // 3 * X if X is even
    retVal = 3 * page;
  }
  else
  {
    // - 5 * X if X is odd
    retVal = -5 * page;
  }

  return retVal;
}

char decode(char c, int shift)
{
  char retVal = '¤';
  if(isalpha(c))
  {
    bool isUpper = false;
    if(isupper(c))
    {
      c = tolower(c);
      isUpper = true;
    }
    
    int offset = c - 'a';
    offset = (((offset - shift) % 26) + 26) % 26;
    retVal = 'a' + offset;

    if(isUpper)
    {
      retVal = toupper(retVal);
    }
  }
  else
  {
    retVal = c;
  }

  return retVal;
}

int main()
{
  int nbPages;
  cin >> nbPages;
  cin.ignore();

  int pageNumber = 2;
  for(int i = 0; i < nbPages; i++)
  {
    string page;
    getline(cin, page);
    
    for(int j = 0; j < page.length(); j++)
    {
      cout << decode(page[j], getShift(pageNumber));
    }
    cout << endl;
    pageNumber++;
  }
  
  return 0;
}
