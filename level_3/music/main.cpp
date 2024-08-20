#include <iostream>
#include <cstring>
using namespace std;
char entree[501];
int main()
{
   cin >> entree;
   int nbLettres = (int)strlen(entree);
   int nbDoublons = -1;
   while(nbDoublons != 0)
   {
      int iIn = 0, iOut = 0;
      nbDoublons = 0;
      while(iIn < nbLettres)
      {
         if (iIn < nbLettres - 1 && entree[iIn] == entree[iIn+1])
         {
            iIn = iIn + 2;
            nbDoublons = nbDoublons + 1;
         }
         else
         {
            entree[iOut] = entree[iIn];
            iIn = iIn + 1;
            iOut = iOut + 1;
         }
      }
      nbLettres = nbLettres - 2 * nbDoublons;
   }
   for (int pos = 0; pos < nbLettres; pos++)
      cout << entree[pos];  
}