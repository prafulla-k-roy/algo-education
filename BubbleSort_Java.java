import java.util.Arrays;

public class BubbleSort_Java {

    /*Algorithm of Bubble Sort:
      Check every two corresponding elements and swap them if they are not in ascending order
      Do this process until the whole array is sorted
     */

    /*Arguments:
      Input Array to be sorted

      Returns: void
      Sorts the Initial Array
     */
    public static void bubbleSort(int [] arr){
        //Temporary variable created to swap elements
        int temp = 0;
        //Traverse through every element in array
        for (int j = 0; j < arr.length; j++)
        {
            //Traverse through every element again while comparing the element to rest
            for (int i = 0; i < arr.length - 1; i++)
            {
                //If element at pointer i is less than next element then skip, else swap the elements to put in their proper position
                if (arr[i] > arr[i + 1])
                {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }

    }

    public static void main(String[] args) {
        int [] arr = {17,11,5,9,8,35,4};
        System.out.println(Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
