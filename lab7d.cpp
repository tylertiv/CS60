#include <iostream>

using namespace std;

int salary(int n);

int main()
{
  for(int i = 0; i <= 6; i++)
  {
    cout << "Salary for year #" << i << "(in thousands): " << salary(i) << endl;
  }
  return 0;
}

int salary(int n)
{
  if(n == 0)
    return 50;
  else
    return (1.1 * salary(n-1) + 5);
}
