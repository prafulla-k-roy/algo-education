// C++ implementation of iterative Counting Sort Algorithm
#include <bits/stdc++.h>

using namespace std;

/* 
Function to perform Counting Sort
The function takes one argument:
1. vector (linear homogeneous contiguous data-type, similar to array) of integer, the data to sort from.
And returns: 
1. void
*/

void countingSort(vector<int> &vet) {
  // maxValue represents the maximum element found on the array to sort
  // we initialize it with INT_MIN
  int maxValue = INT_MIN;

  // we are finding the greater value on the array to know the maximum range of it
  for(int i = 0; i < vet.size(); i++) {
    maxValue = max(maxValue, vet[i]);
  }

  // counter will count the occurence of every number on the input array
  // since we found the maxValue, we know what is the greater value is, so the size of maxValue+1
  vector<int> counter(maxValue+1);

  // here we are counting every occurrence of each element on the input array
  for(int i = 0; i < vet.size(); i++) {
    counter[vet[i]]++;
  }

  // pos is the position of insertion on the input array
  int pos = 0;
  // here we iterate through every number up to the highest value
  // each value of i represents a possible number to be inserted
  for(int i = 0; i <= maxValue; i++) {
    // if number i was counted by our counter vector, then we should insert it on the array at position pos
    // until the counter is equal to zero
    while(counter[i]--) {
      vet[pos++] = i;
    }
  }
}

void printArray(vector<int> vet) {
  for(int i = 0; i < vet.size(); i++) {
    cout << vet[i] << " ";
  }

  cout << endl;
}

int main() {
  vector<int> vet = { 5, 10, 8, 9, 1, 6, 3, 2, 4 };

  cout << "Initial array: ";
  printArray(vet);

  countingSort(vet);

  cout << "Array after Counting Sort: ";
  printArray(vet);

  return 0;
}