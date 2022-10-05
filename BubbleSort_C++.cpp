// C++ implementation of iterative Bubble Sort Algorithm
#include <bits/stdc++.h>

using namespace std;

/* 
Function to perform Bubble Sort

The function takes one argument:
1. vector (linear homogeneous contiguous data-type, similar to array) of integer, the data to sort from.

And returns: 
1. void
*/

void bubbleSort(vector<int> &vet) {
  // n is the variable that contains the size of the vector
  // swaped represents if a swap has occurred on the iteration
  int n = vet.size();
  bool swaped;

  for(int i = 0; i < n-1; i++) {
    swaped = false;
    // The last i elements are already in place, so we don't need to check them again
    for(int j = 0; j < n-i-1; j++) {
      // Check if actual element(vet[j]) is greater then the next element(vet[j+1])
      if(vet[j] > vet[j+1]) {
        // If greater, then swap the two elements
        swap(vet[j], vet[j+1]);
        swaped = true;
      }
    }

     // If no two elements were swapped by the inner loop, then we know the array is already sorted
     // so we break the loop
    if(!swaped)
      return;
  }
}

void printArray(vector<int> vet) {
  for(int i = 0; i < vet.size(); i++) {
    cout << vet[i] << " ";
  }

  cout << endl;
}

int main() {
  vector<int> vet = { 1, 3, 4, 5, 6, 10, 8, 9 };

  cout << "Initial array: ";
  printArray(vet);

  bubbleSort(vet);

  cout << "Array after Bubble Sorting: ";
  printArray(vet);

  return 0;
}
