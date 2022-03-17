#include "ExactNumber.hpp"

int ExactNumber::gcd_recursive(int a, int b) {
  if (b)
    return gcd_recursive(b, a % b);
  else
    return a;
}

void ExactNumber::short_fraction() {
  int gcd = ExactNumber::gcd_recursive(numerator, denominator);

  numerator /= gcd;
  denominator /= gcd;

  if (numerator > 0 && denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }
}

ExactNumber::ExactNumber(long numerator, long denominator)
    : numerator(numerator), denominator(denominator) {
  if (denominator == 0)
    throw std::invalid_argument("Denominator cannot be zero.");
  short_fraction();
}

ExactNumber ExactNumber::operator+(const ExactNumber num) const {
  return ExactNumber((numerator * num.denominator) +
                         (num.numerator * denominator),
                     denominator * num.denominator);
}

ExactNumber ExactNumber::operator-(const ExactNumber num) const {
  return ExactNumber((numerator * num.denominator) -
                         (num.numerator * denominator),
                     denominator * num.denominator);
}

ExactNumber ExactNumber::operator*(const ExactNumber num) const {
  return ExactNumber(numerator * num.numerator, denominator * num.denominator);
}

ExactNumber ExactNumber::operator/(const ExactNumber num) const {
  return ExactNumber(numerator * num.denominator, denominator * num.numerator);
}

bool ExactNumber::operator==(const ExactNumber num) const {
  return ((numerator == num.numerator) && (denominator == num.denominator));
}

bool ExactNumber::operator<=(const ExactNumber num) const {
  return (numerator * num.denominator) <= (num.numerator * denominator);
}

bool ExactNumber::operator>=(const ExactNumber num) const {
  return num <= *this;
}

bool ExactNumber::operator>(const ExactNumber num) const {
  return !(*this <= num);
}

bool ExactNumber::operator<(const ExactNumber num) const {
  return !(num <= *this);
}

bool ExactNumber::operator!=(const ExactNumber num) const {
  return !(*this == num);
}

std::ostream &operator<<(std::ostream &os, ExactNumber num) {
  if (num.numerator == 0) {
    os << 0;
    return os;
  }
  os << num.numerator;
  if (num.denominator != 1)
    os << '/' << num.denominator;
  return os;
}