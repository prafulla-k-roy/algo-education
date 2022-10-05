import java.util.ArrayList;
import java.util.List;

// Java implementation of iterative Counting Sort Algorithm
public class Main {

    /*
        Function to perform Counting Sort
        The function takes one argument:
        1. ArrayList (linear homogeneous contiguous data-type, similar to array) of integer, the data to sort from.
        And returns:
        1. void
    */

    public static void countingSort(ArrayList<Integer> list) {
        // maxValue represents the maximum element found on the array to sort
        // we initialize it with INT_MIN
        int maxValue = Integer.MIN_VALUE;

        // we are finding the greater value on the array to know the maximum range of it
        for(Integer elem : list) {
            maxValue = Math.max(maxValue, elem);
        }

        // counter will count the occurence of every number on the input array
        // since we found the maxValue, we know what is the greater value is, so the size of maxValue+1
        int[] counter = new int[maxValue+1];

        // here we are counting every occurrence of each element on the input array
        for(Integer elem : list) {
            counter[elem]++;
        }

        // pos is the position of insertion on the input array
        int pos = 0;
        // here we iterate through every number up to the highest value
        // each value of i represents a possible number to be inserted
        for(int i = 0; i <= maxValue; i++) {
            // if number i was counted by our counter vector, then we should insert it on the array at position pos
            // until the counter is equal to zero
            while(counter[i] > 0) {
                list.set(pos, i);
                counter[i]--;
                pos++;
            }
        }
    }

    public static void printArray(ArrayList<Integer> list) {
        for (Integer elem : list) {
            System.out.print(elem + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(
                List.of(5, 10, 8, 9, 1, 6, 3, 2, 4)
        );

        System.out.println("Initial array: ");
        printArray(list);

        countingSort(list);

        System.out.println("Array after Bubble Sorting: ");
        printArray(list);
    }
}
