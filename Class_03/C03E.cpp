#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int OK = 0;
const int ERROR = -1;
const int OVERFLOW = -1;
const int OPSETSIZE = 7;
typedef int Status;

class EX_Calculate {
 private:
  const char Prior[7][7] = {
      {'>', '>', '<', '<', '<', '>', '>'},
      {'>', '>', '<', '<', '<', '>', '>'},
      {'>', '>', '>', '>', '<', '>', '>'},
      {'>', '>', '>', '>', '<', '>', '>'},
      {'<', '<', '<', '<', '<', '=', ' '},
      {'>', '>', '>', '>', ' ', '>', '>'},
      {'<', '<', '<', '<', '<', ' ', '='}
  };
  const char Opset[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#'};
 public:
  float Operate(float a, unsigned char theta, float b);
  Status In(char Test, char *TesOp);
  char precede(char Aop, char Bop);
};

int main() {

}