//SELECTION SORT USING C PLUS PLUS

//Selection sort works by taking the smallest element from the array and putting it in the front repeatedly.
//After the first element is put at the beginning, it's considered sorted and the rest
//of the array is considered unsorted.
//We keep on findinf the minimum element from the unsorted part and put it in the sorted part.

//HEADER FILES
#include<iostream>
using namespace std;

//METHOD TO SORT THE ARRAY USING SELECTION SORT
void selectsort(int arr[],int size)
{
    int i,j,minindex;
    //the outer loop is to move the boundary of the unsorted part of the array one-by-one
    for(i=0;i<size-1;i++)
    {
        int minindex=i;
        //the inner loop will find the least element and swap it with the first element
        for(j=i+1;j<size;j++)
        {
            //finding the index of least element
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        //swapping
        if(minindex!=i)
        {
            //calling the in-built swap function to swap the two elements
            swap(arr[i],arr[minindex]);
        }
    }

}
//METHOD FOR PRINTING THE ARRAY
void printar(int arr[],int size)
{
    cout<<endl;
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//DRIVER CODE
int main()
{
    int size;
    cout<<"Enter size of the array: ";
    cin>>size;

    int arr[size];
    cout<<"Input elements into the array -";
    //Taking the unsorted array as input
    for (int i=0;i<size;i++)
    cin>>arr[i];

    //calling the function to sort the array
    selectsort(arr,size);
    //printing the sorted array
    printar(arr,size);
}
