
#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

biguint::biguint()
{
  for(size_t i = 0; i < CAPACITY; i++)
  {
    data_[i] = 0;
  }
}

biguint::biguint(const std::string & s)
{
  for(size_t i = CAPACITY - 1; i >= s.length(); i--)
  {
    data_[i] = 0;
  }
  for(size_t i = 0; i < s.length(); i++)
  {
    data_[s.length() - 1 - i] = s[i] - '0';
  }
}

unsigned short biguint::operator [](std::size_t pos) const
{
  if(pos<CAPACITY)
  {
    return data_[pos];
  }
  else
  {
    return -1;
  }
}
// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);
std::ostream& operator <<(std::ostream&, const biguint&);

std::ostream& operator <<(std::ostream& out, const biguint& b)
{
  size_t i = biguint::CAPACITY - 1;
  while(b[i] == 0)
  {
    i--;
  }
  for(size_t k = i; k > 0; k--)
  {
    out << b[k];
  }
  out << b[0];
  return out;
}

void biguint::operator += (const biguint & b)
{
  for(size_t i = 0; i < CAPACITY - 1; i++)
  {
    if(data_[i] + b[i] >= 10)
    {
      data_[i + 1] += 1;
    }
    data_[i] = (data_[i] + b[i]) % 10;
  }
  if(data_[CAPACITY - 1] + b[CAPACITY - 1] < 10)
  {
    data_[CAPACITY - 1] += b[CAPACITY - 1];
  }
  else
  {
    std::cout << "Exceedes capacity of biguint" << std::endl;
  }
}

biguint operator + (const biguint & a, const biguint & b)
{
  biguint ans;
  ans += a;
  ans += b;

  return ans;
}

int main()
{
  biguint b1 = biguint();
  biguint b2("999");
  biguint b3("222");

  b2 += b3;
  std::cout << b2 << std::endl;

  return 0;
}
