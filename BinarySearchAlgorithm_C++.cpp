// C++ implementation of iterative Binary Search Algorithm
#include <bits/stdc++.h>
using namespace std;

/* 
Function to perform Binary Search

The function takes arguments:
1. vector (linear homogeneous contiguous data-type, similar to array) of integer, the data to search from.
2. integer element that is to be searched

And returns: 
1. Index of element if Found
2. '-1' if not found

Note: The vector needs to be sorted.
*/
int binarySearch(vector<int> v, int To_Find) {
    // Declaration of variables to be used
	int low = 0, high = v.size() - 1;
	int mid;
	
	// This below check covers all cases, so need to check
	// for mid = low - (high - low) / 2
	while (low <= high) {
		int mid = low + (high - low) / 2;
		
		if (v[mid] == To_Find) {
		    // If middle element is equal to the element to find, we return the mid value
		    return mid;
		} else if (v[mid] < To_Find) {
		    // If middle element is smaller than element to find, we can eliminate all the elements smaller than mid
		    // So, we update low to element next to mid
			low = mid + 1;
		} else if (v[mid] > To_Find) {
			// If middle element is greater than element to find, we can eliminate all the elements greater than mid
		    // So, we update high to element before mid
			high = mid - 1;
		}
	}
	
	// If the element is not present in the vector, the while loop will end and control will reach this statement to return '-1'
	return -1;
}

int main()
{
	vector<int> v = { 1, 3, 4, 5, 6 };
	int To_Find = 1;
	cout << binarySearch(v, To_Find) << endl;
	To_Find = 6;
	cout << binarySearch(v, To_Find) << endl;
	To_Find = 10;
	cout << binarySearch(v, To_Find) << endl;
	return 0;
}
