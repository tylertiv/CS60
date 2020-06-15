#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  vector<string> listServed;

  ifstream file("names.txt");
  ofstream output("outputc.txt");
  string myString;

  while(!file.eof())
  {
    getline(file, myString);
    listServed.push_back(myString);
  }
  file.close();

  for(int i = 0; i < listServed.size(); i++)
  {
    // cout << e << endl;
    output << listServed[i] << endl;
  }
  output.close();

  cout << "Number of meals served in 2016: " << listServed.size() << endl;
  return 0;
}
