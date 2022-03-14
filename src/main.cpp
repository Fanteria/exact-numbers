#include <cstdlib>
#include <iostream>
#include <vector>

class LargeNumber {
  bool positive;
  std::vector<unsigned long> number;

public:
  LargeNumber(long num) : number() {
    positive = (num >= 0);
    number.push_back(std::abs(num));
  }
};

class ExactNumber {
  LargeNumber numerator;   // citatel
  LargeNumber denominator; // jmenovatel
  LargeNumber exponent;

public:
  ExactNumber(long numerator, long denominator = 1, long exponent = 0)
      : numerator(numerator), denominator(denominator), exponent(exponent) {}
};

int main() { return 0; }