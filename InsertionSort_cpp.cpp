#include<iostream>  //header file
using namespace std;

void InsertionSort( int arr[],int n)
{   //Let us visualize the array as two parts(sorted and unsorted).
    //Take the leftmost element as sorted(single element is always sorted), and the rest of the array as unsorted part.
    //We now "INSERT" elements (one by one) from the unsorted part , and arrange them one by one in the sorted part.

    int temp;
    //Start with i=1 (not i=0 because arr[0] is the leftmost element and is sorted)
    for(int i=1;i<n;i++)
    {
        /*storing the value of element present at i^th position of the array in a temporary variable
        as we will now insert this value in the sorted part of array.*/

        temp=arr[i];
        int j=i-1;

        //Move elements of arr, that are greater than temp, to one position ahead of their current position
        while(j>-1&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        //when an element less than temp is encountered then assign the value of temp to the next index of the element.
        arr[j+1]=temp;
    }
}


int main()
{
    int  n;
    cout<<"enter the size of the array-\t";
    cin>>n;

    //declaring array of size n
    int arr[n];
    cout<<"enter elements into the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    InsertionSort(arr,n); //calling insertion sort function

    //printing sorted array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
