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

  /**
   * @brief Process numeric operation of ExactNumber or integer.
   *
   * @param left left element of numeric operation
   * @param right right element of numeric operation
   * @param opt operator of numeric operation
   * @return ExactNumber solition of numeric operation
   */
  ExactNumber processNumericOperators(std::string left, std::string right,
                                      std::string opt);

  /**
   * @brief  Process logical operation of ExactNumber or integer.
   *
   * @param left left element of logical operation
   * @param right right element of logical operation
   * @param opt operator of logical operation
   * @return bool solution of logical operation
   */
  bool processLogicOperators(std::string left, std::string right,
                             std::string opt);

  /**
   * @brief Process line and print output to cout.
   *
   * @param line is line for procession
   */
  void processLine(std::string &line);

public:
  /**
   * @brief This method starts calculator.
   *
   */
  void start();
};