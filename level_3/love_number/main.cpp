#include <iostream>

using namespace std;

int reduce_love_number(int n)
{
  int b = n;
  int acc = 0;
  while(b > 0)
  {
    acc += (b%10);
    b -= b%10;
    b /= 10; 
  }

  if(acc >= 10)
  {
    return reduce_love_number(acc);
  }
  else
  {
    return acc;
  }
}

int love_number(string s)
{
  int ret_val = 0;
  for (char &c : s)
  {
    ret_val += int(c - 'A');
  }

  if(ret_val >= 10)
  {
    ret_val = reduce_love_number(ret_val);
  }

  return ret_val;
}

int main()
{
  string name_1, name_2;
  cin >> name_1 >> name_2;

  cout << love_number(name_1) << " " << love_number(name_2) << endl;
}
