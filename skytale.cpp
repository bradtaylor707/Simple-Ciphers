#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  // get cipher
  string cipherText = "";
  int block = 5;
  cout << "Enter cipherText (lower case, no space): " << endl;
  cin >> cipherText;

  // block size
  cout << "How much for block? " << endl;
  cin >> block;

  // length of cipher
  int cipherLength = cipherText.length ();

  // copy to c str
  char * cText = new char [cipherLength + 1];
  strcpy (cText, cipherText.c_str());

  // do letters length / block
  for (int i = 0; i < cipherLength / block; i++)
    for (int j = i; j < cipherLength; j += (block-1)) // add 1 less than block and write
      cout << cText[j];


  delete [] cText;
  cout << endl;
  return 0;
}
