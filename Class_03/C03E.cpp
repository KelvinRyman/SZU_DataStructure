#include <bits/stdc++.h>
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
  stack<char> operators;
  stack<double> operands;

  string str = exp;
  while (!str.empty()) {
    if ((str[0] >= '0' && str[0] <= '9') || str[0] == '.') {
      // 当字符为数字或者浮点数的时候，将其压入操作数栈
      string num = "";
      while ((str[0] >= '0' && str[0] <= '9') || str[0] == '.') {
        num += str[0];
        str.erase(0, 1);
      }

      char *endPtr;
      operands.push(strtod(num.c_str(), &endPtr));

      if (*endPtr != '\0') {
        cerr << "error of strtod\n";
        return -1;
      }

    } else if (operators.empty()) {
      // 当操作符栈为空的时候，将操作符压入操作符栈
      operators.push(str[0]);
      str.erase(0, 1);

    } else {
      int operator_1, operator_2;
      for (int i = 0; i < 7; ++i) {
        if (OPERATOR_SET[i] == operators.top()) {
          operator_1 = i;
          break;
        }
      }
      for (int i = 0; i < 7; ++i) {
        if (OPERATOR_SET[i] == str[0]) {
          operator_2 = i;
          break;
        }
      }

      if (PRIOR[operator_1][operator_2] == '<') {
        operators.push(str[0]);
        str.erase(0, 1);
      } else if (PRIOR[operator_1][operator_2] == '>') {
        double operand_2 = operands.top();
        operands.pop();
        double operand_1 = operands.top();
        operands.pop();
        operands.push(calculate(operand_1, operand_2, operators.top()));
        operators.pop();
      } else {
        str.erase(0, 1);
        operators.pop();
      }
    }
  }
  return operands.top();
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Expression exp;
    cout << fixed << setprecision(4) << exp.evaluateExpression() << '\n';
  }
  return 0;
}