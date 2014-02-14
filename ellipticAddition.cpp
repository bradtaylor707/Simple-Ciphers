#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void case1 (double x1, double y1, double x2, double y2, double & x3, double & y3);
void case3 (double x1, double y1, double x2, double y2, int b, double & x3, double & y3);

int main ()
{

  bool dooo = true;
  int again;
  int b; int c;
  cout << "enter y^2 = x^3 + b*x + c   b and c: ";
  cin >> b >> c;

  double x3; double y3;

  double p1x; double p1y;
  cout << "enter p1 coord: ";
  cin >> p1x >> p1y;
 
  double p2x; double p2y;
  while (dooo)
    {
      cout << "enter p2 coord: ";
      cin >> p2x >> p2y;
      
      // case 1      
      if (p1x != p2x)
	case1 (p1x, p1y, p2x, p2y, x3, y3);

      // case 2
      else if ((p1x == p2x) && p1y != p2y)
	cout << "\ncase2\nP3 is point at infinity\n";
      
      // case 3
      else if ((p1x == p2x) && (p1y = p2y) && (p1y != 0) && (p2y != 0))
	case3 (p1x, p1y, p2x, p2y, b, x3, y3);
      
      // case 4
      else 
	cout << "\ncase4\nP3 is point at infinity\n";

      cout << "\nAgain? with P1 = new P3  (0 for no): ";
      cin >> again; 

      if (!again)
	dooo = false;

      if (dooo) {
	p1x = x3;
	p1y = y3;
      }

    }


  return 0;
}



void case1 (double x1, double y1, double x2, double y2, double &x3, double &y3)
{
  cout << "\ncase1\n";
  double lambda = (y2 - y1) / (x2 - x1);
  x3 = ((lambda) * (lambda)) - x1 - x2;
  y3 = (lambda) * (x2 - x3) - y2;

  
  cout << "P3x:" << x3 << "  P3y:" << y3 << endl;

}

void case3 (double x1, double y1, double x2, double y2, int b, double &x3, double &y3)
{
  cout << "\ncase3\n";
  double lambda = (3.0 * ((x1) * (x1)) + b) / (2.0 * y1);
  x3 = ((lambda) * (lambda)) - (2.0 * x1);
  y3 = (lambda) * (x1 - x3) - y1;


  cout << "P3x:" << x3 << "  P3y:" << y3 << endl;
}


