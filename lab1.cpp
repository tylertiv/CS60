#include<iostream>
#include<string>
using namespace std;

struct Time //military time, no am/pm
{
  int hour;
  int minute;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    //std::cout << ret.hour << ':' << ret.minute << '\n';
    return ret;
}

class Carpool
{
public:
  string names[5];
  int num;
  Time arrive;

  void printNames()
  {
    for(int i = 0; i < num; i++)
    {
      cout << names[i] << endl;
    }
  }

  Carpool combineCarpool(Carpool car1, Carpool car2)
  {
    Carpool combo;

    combo.num = 0;
    if(car1.num + car2.num <= 5)
    {
      combo.num = car1.num + car2.num;
      combo.arrive = earlier(car1.arrive, car2.arrive);

      for (int i = 0; i < car1.num; i++)
      {
        combo.names[i] = car1.names[i];
      }
      for (int i = 0; i < car2.num; i++)
      {
        combo.names[i + car1.num] = car2.names[i];
      }
    }

    return combo;
  }
};



int main()
{
  Carpool combo, c1, c2;
  Time t1, t2;

  t1.hour = 8;
  t1.minute = 30;

  t2.hour = 9;
  t2.minute = 00;

  c1.num = 2;
  c1.arrive = t1;
  c1.names[0] = "Bob";
  c1.names[1] = "Jim";

  c2.num = 3;
  c2.arrive = t2;
  c2.names[0] = "Sally";
  c2.names[1] = "Tyler";
  c2.names[2] = "Matthew";

  combo = combo.combineCarpool(c1, c2);

  std::cout << "Number of passengers:" << combo.num << '\n';

  std::cout << "Names:" << '\n' << '\n';
  combo.printNames();

  std::cout << "Arrival time: " << combo.arrive.hour << ':' << combo.arrive.minute << '\n';
  return 0;
}
