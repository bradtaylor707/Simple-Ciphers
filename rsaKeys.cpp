#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// prototypes here
void generateKeys (int p, int q, vector <int> & keyPairs);
void writeKeys (int p, int q, vector <int> & kPairs);

const int PRIMES[17] = {23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main ()
{
  vector <int> keyPairs;
  int pe = 0; int qe = 0;

  cout << "Enter p q or 0 0 for primes 23 - 97" << endl;

  cin >> pe >> qe;

  
  if (pe == 0 && qe == 0)
    // p and q go through primes
    for (int p = 0; p < 17; p++)
      for (int q = 0; q < 17; q++) {
	generateKeys (PRIMES[p], PRIMES[q], keyPairs);
	writeKeys (PRIMES[p], PRIMES[q], keyPairs);
      }
  
  else {
    generateKeys (pe, qe, keyPairs);
    writeKeys (pe, qe, keyPairs);
  }
  
  return 0;
}

void generateKeys (int p, int q, vector <int> & keyPairs)
{
  int N = p * q;
  int n = (p-1) * (q-1);
  int e, d;
  
  // do each e compute d 
  for (e = 1; e < (n / 2); e += 2)
    {
      d = 0;
      int count = -1;
      
      while (true)
	{
	  count++;
	  if ( ((1 + (count * n)) % e) == 0 ) 
	    {
	      d = (1 + (count * n)) / e;
	      break;
	    }
	}
      if (d < 0)
	d = 0;

      keyPairs.push_back (e);
      keyPairs.push_back (d);
      
    }
}

void writeKeys (int p, int q, vector <int> & kPairs)
{

  cout << "--------------------------------------------------------------------------------------\n" << endl;  
  cout << "p=" << p << ", q=" << q << ", n=" << (p-1)*(q-1) << endl << endl;

  cout << "(e,d) = ";

  for (int i = 0; i < kPairs.size (); i+=2)
    if (kPairs[i+1] != 0)
      cout << '(' << kPairs[i] << ',' << kPairs[i+1] << "), ";
  cout << endl << endl;
  
  kPairs.clear ();
}


