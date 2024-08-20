#include <bits/stdc++.h>
using namespace std;

bool isConsonnant(char c)
{
    bool retVal =
       (c != 'a') 
    && (c != 'e') 
    && (c != 'i') 
    && (c != 'o') 
    && (c != 'u') 
    && (c != 'y');

    return retVal; 
}

int main()
{

  for(char c = 'a'; c <= 'z'; c++)
  {
    if(isConsonnant(c))
    {
        cout << c << ' ';
    }
  }
  
  return 0;
}