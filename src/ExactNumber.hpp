#include <iostream>

class ExactNumber {
  int numerator;   // citatel
  int denominator; // jmenovatel

  /**
   * @brief Recursively count gcd.
   *
   * @param a First number
   * @param b Second number
   * @return int calculated gcd
   */
  static int gcd_recursive(int a, int b);

  /**
   * @brief Short fraction to minimal format.
   *
   */
  void short_fraction();

public:
  /**
   * @brief Construct a new Exact Number object. Default value is 0. Fraction
   * will be shorted too.
   *
   * @param numerator is numerator of fraction
   * @param denominator is denominator of fraction
   */
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