import java.util.Arrays;

public class SelectionSort_Java {

    /*Algorithm of Insertion Sort:
      Array is divided into two parts, sorted subarray and unsorted subarray
      Now we traverse through unsorted subarray and find the minimum element and then swap with the element at end of sorted subarray
     */

    /*Arguments:
      Input Array to be sorted

      Returns: void
      Sorts the Initial Array
     */

    public static void selectionSort(int [] arr) {
        //Declaration of variables to be used
        int indexOfMin, temp;
        //Traverse through every element in array which will be swapped by minimum element
        for (int i = 0; i < arr.length - 1; i++) {
            indexOfMin = i;
            //Traverse through array after pointer i to find the minimum element
            for (int j = i+1; j < arr.length; j++) {
                if(arr[j] < arr[indexOfMin]){
                    indexOfMin = j;
                }
            }
            // Now swap the element at pointer i with the minimum element
            temp = arr[i];
            arr[i] = arr[indexOfMin];
            arr[indexOfMin] = temp;
        }
    }

    public static void main(String[] args) {
        int [] arr = {17,11,5,9,8,35,4};
        System.out.println(Arrays.toString(arr));
        selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}