// DS队列之银行排队
#include <queue>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  queue<int> q;
  char ws;
  int aSize = 0, bSize = 0, cSize = 0;
  for (int i = 0; i < n; i++) {
    cin >> ws;
    if (ws == 'A') aSize++;
    else if (ws == 'B') bSize++;
    else if (ws == 'C') cSize++;
    q.push(ws);
  }
  int sumA = 0, sumB = 0, sumC = 0, temp;
  for (int i = 0; i < n; ++i) {
    if (q.front() == 'A') {
      cin >> temp;
      sumA += temp;
      q.pop();
    } else if (q.front() == 'B') {
      cin >> temp;
      sumB += temp;
      q.pop();
    } else if (q.front() == 'C') {
      cin >> temp;
      sumC += temp;
      q.pop();
    }
  }

  cout << sumA / aSize << '\n' << sumB / bSize << '\n' << sumC / cSize << '\n';
  return 0;
}