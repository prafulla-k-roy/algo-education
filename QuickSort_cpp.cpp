//QUICK SORT IS A SORTING ALGORITHM BASED ON DIVIDE AND CONQUER PARADIGM.
//AN ELEMENT IS CHOSEN AS PIVOT AROUND WHICH THE ARRAY IS PARTITIONED, AND THE PIVOT ELEMENT IS
//PUT AT ITS RIGHT POSITION

//Header file
#include<iostream>
using namespace std;

//method to create a partition
//the array will be partitioned around the pivot element
//the pivot element will be put in its right position, which means all the elements to the left
//of the pivot will be smaller than it and all to the right will be larger.
int partition(int ar[],int l,int h)
{
    //the lowest index element is chosen as the pivot in this code
    int pivot=ar[l],temp;
    //i and j are used as pointers to traverse the array and swap elements to their right places
    int i=l,j=h;
    
    //the base condition
    while(i<j)
    {
        while(ar[i]<=pivot)
        i++;
        while(ar[j]>pivot)
        j--;
        //if an element is found out of its right position , it is swapped
        if(i<j)
        swap(ar[i],ar[j]);
    } 
    swap(ar[l],ar[j]);
    //pivot index is returned
    return j;
}
void quicksort(int ar[],int l,int h)
{
    int j;
    if(l<h)
    {
        //partitioning the array
        j = partition(ar,l,h);
        //sorting the left part
        quicksort(ar,l,j-1);
        //sorting the right part
        quicksort(ar,j+1,h);
    }
}
int main()
{
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    int ar[size];
    //the array is inputted
    cout<<"enter elements of array -"<<endl;
    for (int i=0;i<size;i++)
    {
        cin>>ar[i];
    }

    //'l' and 'h' are used to indicate lowest and highest indeces
    int l=0,h=6;
    //quicksort method is called
    quicksort(ar,l,h);

    //after sorting is done the sorted array is printed here
    for (int i=0;i<h+1 ; i++)
    cout<<ar[i]<<" ";
}
