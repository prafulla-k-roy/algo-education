import java.util.Arrays;

public class InsertionSort_Java {

    /*Algorithm of Insertion Sort:
      Array is divided into two parts, sorted subarray and unsorted subarray
      Now we traverse through unsorted subarray and put elements of it into sorted subarray in its right position
     */

    /*Arguments:
      Input Array to be sorted

      Returns: void
      Sorts the Initial Array
     */

    public static void insertionSort(int [] arr){
        //Declaration of variables to be used
        int key, j;
        //Traverse through every element in array which acts as key which needs to be put in its proper position
        for (int i = 1; i < arr.length; i++) {
            key = arr[i];
            j = i - 1;
            //Till element at pointer j is greater than key push the elements by 1
            while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            //Now when elements previous to key are all smaller than key, j + 1 is the right position to put key
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int [] arr = {17,11,5,9,8,35,4};
        System.out.println(Arrays.toString(arr));
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
