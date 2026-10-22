#include <iostream>
#include <functional>
#include <string>
#include "heap.h"
using namespace std;

int main() {

  Heap<int> minHeap;

  minHeap.push(16);
  minHeap.push(4);
  minHeap.push(30);
  minHeap.push(9);
  minHeap.push(3);

  cout << "Order: ";

  while (!minHeap.empty()) {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }

  cout << endl;

  Heap<int, greater<int>> maxHeap(3);

  maxHeap.push(17);
  maxHeap.push(5);
  maxHeap.push(30);
  maxHeap.push(9);
  maxHeap.push(3);

  while (!maxHeap.empty()) {
    cout << maxHeap.top() << " ";
    maxHeap.pop();
  }

  cout << endl;

  try {
    maxHeap.pop();
  }
  catch (const underflow_error& error) {
    cout << "Exception caught: " << error.what() << endl;
  }

  return 0;
  
}