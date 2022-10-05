// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream> //c++ library
using namespace std;

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver's code
int main(void)
{
    int arr[] = {2, 3, 4, 10, 40, -2, 0, 5}; // This is initializaton of array during declaration of an array.
    int x = 10;                              // Element of be search.
    int N = sizeof(arr) / sizeof(arr[0]);    // This line give size of array ,that store in ' N '

    // Function call
    int result = search(arr, N, x);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is  present at index array"
             << "  " << result;

    return 0;
}
