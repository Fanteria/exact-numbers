#include "Calculator.hpp"
#include <stdexcept>

using std::cout, std::endl;
using std::invalid_argument;
using std::pair, std::vector;
using std::string;

ExactNumber Calculator::processNumericOperators(string left, string right,
                                                string opt) {
  // Get ExactNumbers from strings
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
    throw invalid_argument("Unknow operator.");
}

bool Calculator::processLogicOperators(string left, string right, string opt) {
  // Get ExactNumbers from strings
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
    throw std::invalid_argument("Unknow operator.");
}

void Calculator::processLine(string &line) {
  size_t pos;
  vector<string> words;

  // Split line to words
  while ((pos = line.find(delimiter)) != string::npos) {
    words.push_back(line.substr(0, pos));
    line.erase(0, pos + delimiter.length());
  }

  if (!line.empty())
    words.push_back(line);

  // Check number of words
  if (words.size() < 3) {
    cout << "Too many arguments." << endl;
    return;
  }

  string opt = words[1];
  // First operator is =
  if (opt == "=") {
    if (words.size() == 3) {
      variables.insert(pair<std::string, ExactNumber>(
          words[0], ExactNumber(stoi(words[2]))));
    } else if (words.size() == 5) {
      variables.insert(std::pair<std::string, ExactNumber>(
          words[0], processNumericOperators(words[2], words[4], words[3])));
    } else {
      cout << "Wrong number of arguments for =.\n";
    }
    // Operator is in numeric operators
  } else if (numOperators.count(opt)) {
    cout << "Result: ";
    cout << processNumericOperators(words[0], words[2], words[1]);
    cout << "\n";
    // Operator is in logic operators
  } else if (logOperators.count(opt)) {
    cout << ((processLogicOperators(words[0], words[2], words[1])) ? "True"
                                                                   : "False");
    cout << "\n";
  } else {
    cout << "Unknow operator.\n";
  }
}

void Calculator::start() {
  string line;

  cout << "What do you want to do?" << endl;
  while (std::getline(std::cin, line)) {
    if (line == "exit")
      break;

    // Try process lines and catch exceptions
    try {
      processLine(line);
    } catch (const invalid_argument &e) {
      cout << "Error: " << e.what() << "\n";
    }

    cout << "----------------------------------\n";
    if (!variables.empty()) {
      cout << "Stored variables:\n";
      for (auto const &var : variables)
        cout << var.first << " = " << var.second << '\n';
    }
    cout << "What do you want to do?" << endl;
  }
}
