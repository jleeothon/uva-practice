  
#include <iostream>  
#include <iomanip>  
#include <cmath>  
  
using namespace std;  
  
#define PI 3.141592653589793  
  
int main(int ac, char *av[])  
{  
    double a, x, y, z;  
      
    while (cin >> a)  
    {  
        x = a * a * (1 - sqrt(3) + PI / 3);  
        y = a * a * (2 * sqrt(3) - 4 + PI / 3);  
        z = a * a * (4 - sqrt(3) - 2 * PI / 3);  
          
        cout.precision(3);  
        cout.setf(ios::fixed | ios::showpoint);  
        cout << x << " " << y << " " << z << endl;  
    }  
  
    return 0;  
}  