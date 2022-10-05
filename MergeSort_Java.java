import java.util.Arrays;

public class MergeSort_Java {

    /*Merge Sort Algorithm:
     It uses divide and conquer method to combine two sorted arrays or subarrays to single sorted array using recursion.
     every element from both array is checked and smaller element is added to a new array and hence a sorted array is formed

     Arguments:
     Input Array, mid: the index which divides two sorted subarrays, low: initial index of first subarry, high: index of last element

     Returns: void
     Sorts the initial array
     */

    public static void merge(int [] arr, int mid, int low, int high) {
        //Declaration of variables to be used
        int i, j, k;
        int [] newArr = new int[arr.length];
        i = low;
        j = mid + 1;
        k = low;
        // Traverse through every element in both subarrays
        while (i <= mid && j <= high) {
            //Compare elements of both subarrays and smaller element gets added to new array
            if (arr[i] < arr[j]) {
                newArr[k] = arr[i];
                i++;
                k++;
            } else {
                newArr[k] = arr[j];
                j++;
                k++;
            }
        }
        //Since loop is taken for subarray of smaller length, the rest of the elements are added separately
        while (i <= mid) {
            newArr[k] = arr[i];
            k++;
            i++;
        }
        while (j <= high) {
            newArr[k] = arr[j];
            k++;
            j++;
        }
        //Now the new array is being copied to intial array
        for (int x = low; x <= high; x++) {
            arr[x] = newArr[x];
        }
        
    }
    
    public static void mergeSort(int [] arr, int low, int high){
        //Using recursive call merge method is being called till low is less than high
        int mid; 
        if(low < high) {
            mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, mid, low, high);
        }
    }

    public static void main(String[] args) {
        int [] arr = {9, 1, 4, 14, 4, 15, 6};
        System.out.println(Arrays.toString(arr));
        mergeSort(arr, 0, 6);
        System.out.println(Arrays.toString(arr));
    }
}
