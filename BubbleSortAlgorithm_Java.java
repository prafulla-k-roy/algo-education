import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Java implementation of iterative Bubble Sort Algorithm
public class BubbleSort {

    /*
        Function to perform Bubble Sort
        The function takes one argument:
        1. ArrayList (linear homogeneous contiguous data-type, similar to array) of integer, the data to sort from.
        And returns:
        1. void
    */
    public static void bubbleSort(ArrayList<Integer> list) {
        // n is the variable that contains the size of the vector
        // swaped represents if a swap has occurred on the iteration
        int n = list.size();
        boolean swaped;

        for(int i = 0; i < n-1; i++) {
            swaped = false;
            // The last i elements are already in place, so we don't need to check them again
            for(int j = 0; j < n-i-1; j++) {
                // Check if actual element(list[j]) is greater than the next element(list[j+1])
                if(list.get(j) > list.get(j+1)) {
                    // If greater, then swap the two elements
                    Collections.swap(list, j, j+1);
                    swaped = true;
                }
            }

            // If no two elements were swapped by the inner loop, then we know the array is already sorted,
            // so we break the loop
            if(!swaped) {
                return;
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

        bubbleSort(list);

        System.out.println("Array after Bubble Sorting: ");
        printArray(list);
    }
}
