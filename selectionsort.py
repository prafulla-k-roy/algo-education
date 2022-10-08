selection sort is one of the simplest algorithm. here, a smallest value among the unsorted elements of the array is selected during each pass and then it is inserted
to its appropriate position into the array. It is an in-place sorting algorithm. the array is divided into two parts, first (left side) is sorted part, and another
one (right side) is the unsorted part. Initially, the sorted part of the array is empty, and unsorted part is the whole array. 
the first smallest element is selected from the unsorted array and it is placed at the first position. similarly, second smallest element is selected and placed 
in the second position. The process continues until the array is entirely sorted.
The average and worst-case complexity of selection sort is O(n2), where n is the number of items. Due to this, it is not suitable for large data sets.

CODE:
# Selection sort in Python


def selectionSort(array, size):
   
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
         
            # to sort in descending order, change > to < in this line
            # select the minimum element in each loop
            if array[i] < array[min_idx]:
                min_idx = i
         
        # put min at the correct position
        (array[step], array[min_idx]) = (array[min_idx], array[step])


data = [-2, 45, 0, 11, -9]
size = len(data)
selectionSort(data, size)
print('Sorted Array in Ascending Order:')
print(data)
