#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  map<string, int> served;

  ifstream file("names.txt");
  ofstream output("outputb.txt");
  string index;

  while(!file.eof())
  {
    getline(file, index);
    served[index]++;
  }
  file.close();

  for(auto e:served)
  {
    output << e.second << ' ' << e.first << endl;
  }
  output.close();

  int sum = 0;
  for(auto e:served)
  {
    sum += e.second;
  }
  cout << "Average number of times served (per person): " << (double)sum/served.size() << endl;
  return 0;
}
