#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> backwardST;
stack<string> forwardST;

string currentURL = "http://www.acm.org/";

void visit(const string& url) {
  backwardST.push(currentURL);
  currentURL = url;
  while (!forwardST.empty()) {
    forwardST.pop();
  }
  cout << currentURL << endl;
}

void back() {
  if (!backwardST.empty()) {
    forwardST.push(currentURL);
    currentURL = backwardST.top();
    backwardST.pop();
    cout << currentURL << endl;
  } else {
    cout << "Ignored" << endl;
  }
}

void forward() {
  if (!forwardST.empty()) {
    backwardST.push(currentURL);
    currentURL = forwardST.top();
    forwardST.pop();
    cout << currentURL << endl;
  } else {
    cout << "Ignored" << endl;
  }
}

int main() {
  string command;
  while (cin >> command) {
    if (command == "QUIT") {
      break;
    } else if (command == "VISIT") {
      string url;
      cin >> url;
      visit(url);
    } else if (command == "BACK") {
      back();
    } else if (command == "FORWARD") {
      forward();
    }
  }

  return 0;
}