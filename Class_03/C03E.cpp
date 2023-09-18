#include <iostream>
#include <iomanip>
#include <stack>
#include <algorithm>
using namespace std;

class Expression {
 public:
  Expression();
  double evaluateExpression();
 private:
  static double calculate(double Operand1, double Operand2, char Operator);
  const char PRIOR[7][7] = {
      {'>', '>', '<', '<', '<', '>', '>'},
      {'>', '>', '<', '<', '<', '>', '>'},
      {'>', '>', '>', '>', '<', '>', '>'},
      {'>', '>', '>', '>', '<', '>', '>'},
      {'<', '<', '<', '<', '<', '=', ' '},
      {'>', '>', '>', '>', ' ', '>', '>'},
      {'<', '<', '<', '<', '<', ' ', '='}
  };
  const char OPERATOR_SET[7] = {'+', '-', '*', '/', '(', ')', '#'};
  string exp;
};

Expression::Expression() {
  getline(cin, exp);
}

double Expression::calculate(double Operand1, double Operand2, char Operator) {
  switch (Operator) {
    case '+' : return Operand1 + Operand2;
    case '-' : return Operand1 - Operand2;
    case '*' : return Operand1 * Operand2;
    case '/' :
      if (Operand2 != 0) {
        return Operand1 / Operand2;
      } else {
        cerr << "Division by zero.";
      }
    default: return 0;
  }
}

double Expression::evaluateExpression() {
  stack<double> Operand;
  stack<char> Operator;

  int i = 0;
  while (i < exp.length() || Operator.top() != '#') {
    if (isdigit(exp[i]) || exp[i] == '.') {
      bool isFloat = false;
      double num = 0, dec = 10;
      while (isdigit(exp[i]) || exp[i] == '.') {
        if (exp[i] == '.') {
          isFloat = true;
          i++;
        } else if (!isFloat) {
          num = num * 10 + (exp[i] - '0');
          i++;
        } else {
          num = num + (exp[i] - '0') / dec;
          dec *= 10;
          i++;
        }
      }
      Operand.push(num);

    } else if (exp[i] == ' ') {
      i++;
      continue;

    } else if (Operator.empty()) {
      Operator.push(exp[i++]);

    } else {
      switch (PRIOR[find(OPERATOR_SET, OPERATOR_SET + 7, Operator.top()) - OPERATOR_SET]
      [find(OPERATOR_SET, OPERATOR_SET + 7, exp[i]) - OPERATOR_SET]) {
        case '<':Operator.push(exp[i]);
          i++;
          break;
        case '=':Operator.pop();
          i++;
          break;
        case '>':double Operand2 = Operand.top();
          Operand.pop();
          double Operand1 = Operand.top();
          Operand.pop();
          Operand.push(calculate(Operand1, Operand2, Operator.top()));
          Operator.pop();
          break;
      }
    }
  }
  return Operand.top();
}

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    Expression exp;
    cout << fixed << setprecision(4) << exp.evaluateExpression() << '\n';
  }

  return 0;
}