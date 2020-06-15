#include <string>
#include <unordered_set>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  unordered_set<string> names;

  ifstream file("names.txt");
  ofstream output("outputa.txt");
  string myString;

  while(!file.eof())
  {
    getline(file, myString);
    names.insert(myString);
  }
  file.close();

  for(auto e:names)
  {
    // cout << e << endl;
    output << e << endl;
  }
  output.close();

  cout << "Number of different people served in 2016: " << names.size() << endl;
  
  return 0;
}
