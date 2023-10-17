// DS队列----银行单队列多窗口模拟
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Customer {
  int arriveTime;
  int processTime;
  int is_VIP;
};

int main() {
  int N;
  cin >> N;
  vector<Customer> customers(N);
  for (int i = 0; i < N; i++) {
    cin >> customers[i].arriveTime >> customers[i].processTime >> customers[i].is_VIP;
  }
  int K;
  cin >> K;
  int VIP;
  cin >> VIP;

  priority_queue<int, vector<int>, greater<>> windows;
  for (int i = 0; i < K; i++) {
    windows.push(0);
  }

  int totalWaitTime = 0;
  int maxWaitTime = 0;
  int lastFinishTime = 0;

  for (const Customer &customer : customers) {
    int earliestFreeTime = windows.top();
    windows.pop();
    int waitTime = max(0, earliestFreeTime - customer.arriveTime);
    totalWaitTime += waitTime;
    maxWaitTime = max(maxWaitTime, waitTime);
    int finishTime = max(earliestFreeTime, customer.arriveTime) + customer.processTime;
    lastFinishTime = max(lastFinishTime, finishTime);
    windows.push(finishTime);
  }

  double averageWaitTime = (double) totalWaitTime / N;
  printf("%.1f %d %d\n", averageWaitTime, maxWaitTime, lastFinishTime);

  return 0;
}
