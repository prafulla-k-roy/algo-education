// Implementation of iterative Binary Search in Java

class BinarySearch {
	// Binary Search is an algorithm based on divide and conquer method of problem solving
	
	// The function takes arguments:
  // 1. array of integer, the data to search from.
  // 2. integer element that is to be searched
	
	// Returns index of x if it is present in arr[],
	// else return -1
	
	// Note: The array needs to be sorted.
	int binarySearch (int arr[], int x) {
		int low = 0, high = arr.length - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (arr[mid] == x)
			  // If element to find is present at middle index, we return the mid value
				return mid;
			
			else if (arr[mid] < x)
			  // If middle element is smaller than element to find, we can eliminate all the elements smaller than mid
		    // So, we update low to element next to mid
        low = mid + 1;

			else if (arr[mid] > x)
			  // If middle element is greater than element to find, we can eliminate all the elements greater than mid
		    // So, we update high to element before mid
				high = mid - 1;
		}

		// if we reach here, then element was
		// not present
		return -1;
	}

	// Driver method to test above
	public static void main(String args[])
	{
		BinarySearch ob = new BinarySearch();
		int arr[] = { 2, 3, 4, 10, 40 };
		int n = arr.length;
		int x = 10;
		int result = ob.binarySearch(arr, x);
		if (result == -1)
			System.out.println("Element not present");
		else
			System.out.println("Element found at " + "index " + result);
	}
}
