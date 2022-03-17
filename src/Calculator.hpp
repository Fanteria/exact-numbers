#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "ExactNumber.hpp"

class Calculator {
  std::map<std::string, ExactNumber> variables;
  const std::string delimiter = " ";
  const std::set<std::string> numOperators = {"+", "-", "/", "*"};
  const std::set<std::string> logOperators = {"==", "!=", ">", ">=", "<", "<="};

  ExactNumber processNumericOperators(std::string left, std::string right,
                                      std::string opt);

  bool processLogicOperators(std::string left, std::string right,
                             std::string opt);

  void processLine(std::string &line);

public:
  void start();
};