#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main ()
{
  vector <char> alphabet;
  for (int i = 97; i < 123 ; i++)
    alphabet.push_back ((char) i);

  int shamnt = 0;
  cout << "shamnt? " << endl;
  cin >> shamnt;

  vector <char> shiftAlphabet;

  for (int i = 97 + shamnt; i < 123 + shamnt; i++)
    {
      if (i > 122)
	shiftAlphabet.push_back ((char) i - 26);
      else
	shiftAlphabet.push_back ((char) i);
    }

  string cipherText;
  cout << "text to decipher (lower, no space): ";
  cin >> cipherText;

  for (int i = 0; i < cipherText.length (); i++)
    for (int j = 0; j < shiftAlphabet.size (); j++)
      if (cipherText[i] == shiftAlphabet[j])
	cout << alphabet[j];

	    
  cout << endl;

  return 0;

}
