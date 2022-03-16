#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

class ExactNumber {
  int numerator;   // citatel
  int denominator; // jmenovatel

  static int gcd_recursive(int a, int b) {
    if (b)
      return gcd_recursive(b, a % b);
    else
      return a;
  }

  void short_fraction() {
    int gcd = ExactNumber::gcd_recursive(numerator, denominator);
    if (gcd == 1)
      return;
    numerator /= gcd;
    denominator /= gcd;

    // TODO 1/-3 is ugly
  }

public:
  ExactNumber(long numerator = 0, long denominator = 1)
      : numerator(numerator), denominator(denominator) {
    if (denominator == 0)
      throw std::invalid_argument("Denominator cannot be zero.");
    short_fraction();
  }

  ExactNumber operator+(const ExactNumber num) const {
    return ExactNumber((numerator * num.denominator) +
                           (num.numerator * denominator),
                       denominator * num.denominator);
  }

  ExactNumber operator-(const ExactNumber num) const {
    return ExactNumber((numerator * num.denominator) -
                           (num.numerator * denominator),
                       denominator * num.denominator);
  }

  ExactNumber operator*(const ExactNumber num) const {
    return ExactNumber(numerator * num.numerator,
                       denominator * num.denominator);
  }

  ExactNumber operator/(const ExactNumber num) const {
    return ExactNumber(numerator * num.denominator,
                       denominator * num.numerator);
  }

  bool operator==(const ExactNumber num) const {
    return ((numerator == num.numerator) && (denominator == num.denominator));
  }

  bool operator<=(const ExactNumber num) const {
    return (numerator * num.denominator) <= (num.numerator * denominator);
  }

  bool operator>=(const ExactNumber num) const { return num <= *this; }

  bool operator>(const ExactNumber num) const { return !(*this <= num); }

  bool operator<(const ExactNumber num) const { return !(num <= *this); }

  bool operator!=(const ExactNumber num) const { return !(*this == num); }

  friend std::ostream &operator<<(std::ostream &os, ExactNumber num);
};

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

class Calculator {
  std::map<std::string, ExactNumber> variables;
  std::string delimiter = " ";
  const std::set<std::string> numOperators = {"+", "-", "/", "*"};
  const std::set<std::string> logOperators = {"==", "!=", ">", ">=", "<", "<="};

  ExactNumber processNumericOperators(std::string left, std::string right,
                                      std::string opt) {
    ExactNumber l = ((variables.count(left)) ? variables[left]
                                             : ExactNumber(std::stoi(left)));
    ExactNumber r = (variables.count(right)) ? variables[right]
                                             : ExactNumber(std::stoi(right));

    if (opt == "+")
      return l + r;
    else if (opt == "-")
      return l - r;
    else if (opt == "/")
      return l / r;
    else if (opt == "*")
      return l * r;
    else
      throw std::invalid_argument("Neznámý operátor");
  }

  bool processLogicOperators(std::string left, std::string right,
                             std::string opt) {
    ExactNumber l = ((variables.count(left)) ? variables[left]
                                             : ExactNumber(std::stoi(left)));
    ExactNumber r = (variables.count(right)) ? variables[right]
                                             : ExactNumber(std::stoi(right));
    if (opt == "==")
      return l == r;
    else if (opt == "!=")
      return l != r;
    else if (opt == ">=")
      return l >= r;
    else if (opt == "<=")
      return l <= r;
    else if (opt == ">")
      return l > r;
    else if (opt == "<")
      return l < r;
    else
      throw std::invalid_argument("Neznámý operátor");
  }

  void processLine(std::string &line) {
    size_t pos;
    std::vector<std::string> words;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      words.push_back(line.substr(0, pos));
      line.erase(0, pos + delimiter.length());
    }

    if (!line.empty())
      words.push_back(line);

    if (words.size() < 3) {
      std::cout << "Příliš málo argumentů." << std::endl;
      return;
    }

    std::string opt = words[1];
    if (opt == "=") {
      if (words.size() == 3) {
        variables.insert(std::pair<std::string, ExactNumber>(
            words[0], ExactNumber(std::stoi(words[2]))));
      } else if (words.size() == 5) {
        variables.insert(std::pair<std::string, ExactNumber>(
            words[0], processNumericOperators(words[2], words[4], words[3])));
      } else {
        std::cout << "Špatný počet argumentů pro =.\n";
      }
    } else if (numOperators.count(opt)) {
      std::cout << "Výsledek: "
                << processNumericOperators(words[0], words[2], words[1])
                << "\n";
    } else if (logOperators.count(opt)) {
      std::cout << ((processLogicOperators(words[0], words[2], words[1]))
                        ? "True"
                        : "False")
                << "\n";
    } else {
      std::cout << "Neznámý operátor.\n";
    }
  }

public:
  void start() {
    std::string line;

    std::cout << "Co chcete dělat?" << std::endl;
    while (std::getline(std::cin, line)) {
      if (line == "q")
        break;

      processLine(line);

      std::cout << "----------------------------------\n";
      if (!variables.empty()) {
        std::cout << "Uložené proměnné:\n";
        for (auto const &var : variables)
          std::cout << var.first << " = " << var.second << '\n';
      }
      std::cout << "Co chcete dělat?" << std::endl;
    }
  }
};

int main() {
  Calculator calc = Calculator();
  calc.start();
  return 0;
}