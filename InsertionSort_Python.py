"""Algorithm of Insertion Sort:
Array is divided into two parts, sorted subarray and unsorted subarray
Now we traverse through unsorted subarray and put elements of it into sorted subarray in its right position


Arguments:
Input Array to be sorted

Returns: void
Sorts the Initial Array
"""

def insertionSort(arr):
    #Declaration of variables to be used
    key = 0
    j = 0
    #Traverse through every element in array which acts as key which needs to be put in its proper position
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        #Till element at pointer j is greater than key push the elements by 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        #Now when elements previous to key are all smaller than key, j + 1 is the right position to put key
        arr[j + 1] = key

arr = [17,11,5,9,8,35,4]
print(arr)
insertionSort(arr)
print(arr)