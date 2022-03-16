#include <iostream>

class ExactNumber {
  int numerator;   // citatel
  int denominator; // jmenovatel

  static int gcd_recursive(int a, int b);

  void short_fraction();

public:
  ExactNumber(long numerator = 0, long denominator = 1);

  ExactNumber operator+(const ExactNumber num) const;

  ExactNumber operator-(const ExactNumber num) const;

  ExactNumber operator*(const ExactNumber num) const;

  ExactNumber operator/(const ExactNumber num) const;

  bool operator==(const ExactNumber num) const;

  bool operator<=(const ExactNumber num) const;

  bool operator>=(const ExactNumber num) const;

  bool operator>(const ExactNumber num) const;

  bool operator<(const ExactNumber num) const;

  bool operator!=(const ExactNumber num) const;

  friend std::ostream &operator<<(std::ostream &os, ExactNumber num);
};