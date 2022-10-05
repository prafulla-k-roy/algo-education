import java.util.Arrays;

public class QuickSort_Java {

    /*QuickSort Algorithm:
     It uses recursive method to sort an array with O(nlogn) time complexity
     An element is chosen as pivot point and all smaller elements are put before pivot element all greater elements than pivot element
     Then the array is divided using partition method and using recursion same approach is used in other subarrays and 
     similarly all elements act as pivot and then array is sorted

     Arguments:
     Initial Array, low: initial index of array, high: last index of array

     Returns: void
     Sort the initial Array
     */

    public static int partition(int [] arr, int low, int high)
    {
        //Declaration of variables to be used
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        int temp;
        //Pointer i will find an element greater than pivot element
        //Pointer j will find an element smaller than or equal to pivot element
        do {
            while (i < arr.length && arr[i] <= pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }
            //If pointer i goes ahead of j then swap element at i and j
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);

        // Swap A[low] and A[j]
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }

    public static void quickSort(int [] arr, int low, int high) {
        int partitionIndex; // Index of pivot after partition
        //Using recursive call initial array is sorted

        if (low < high) {
            partitionIndex = partition(arr, low, high); 
            quickSort(arr, low, partitionIndex - 1);  // sort left subarray 
            quickSort(arr, partitionIndex + 1, high); // sort right subarray
        }
    }

    public static void main(String[] args) {
        int [] arr = {9, 4, 4, 8, 7, 5, 6};
        System.out.println(Arrays.toString(arr));
        quickSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }
}