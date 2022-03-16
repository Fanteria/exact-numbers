#include "Calculator.hpp"

using std::cout, std::endl;
using std::pair, std::vector;
using std::string;

ExactNumber Calculator::processNumericOperators(string left, string right,
                                                string opt) {
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

bool Calculator::processLogicOperators(string left, string right, string opt) {
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

void Calculator::processLine(string &line) {
  size_t pos;
  vector<string> words;
  while ((pos = line.find(delimiter)) != string::npos) {
    words.push_back(line.substr(0, pos));
    line.erase(0, pos + delimiter.length());
  }

  if (!line.empty())
    words.push_back(line);

  if (words.size() < 3) {
    cout << "Příliš málo argumentů." << endl;
    return;
  }

  string opt = words[1];
  if (opt == "=") {
    if (words.size() == 3) {
      variables.insert(pair<std::string, ExactNumber>(
          words[0], ExactNumber(stoi(words[2]))));
    } else if (words.size() == 5) {
      variables.insert(std::pair<std::string, ExactNumber>(
          words[0], processNumericOperators(words[2], words[4], words[3])));
    } else {
      cout << "Špatný počet argumentů pro =.\n";
    }
  } else if (numOperators.count(opt)) {
    cout << "Výsledek: "
         << processNumericOperators(words[0], words[2], words[1]) << "\n";
  } else if (logOperators.count(opt)) {
    cout << ((processLogicOperators(words[0], words[2], words[1])) ? "True"
                                                                   : "False")
         << "\n";
  } else {
    cout << "Neznámý operátor.\n";
  }
}

void Calculator::start() {
  string line;

  cout << "Co chcete dělat?" << endl;
  while (std::getline(std::cin, line)) {
    if (line == "q")
      break;

    processLine(line);

    cout << "----------------------------------\n";
    if (!variables.empty()) {
      cout << "Uložené proměnné:\n";
      for (auto const &var : variables)
        cout << var.first << " = " << var.second << '\n';
    }
    cout << "Co chcete dělat?" << endl;
  }
}