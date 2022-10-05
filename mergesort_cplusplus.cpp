//Merge sort is a sorting algorithm based on divide and conquer paradigm.
//In this method, we keep on diviiding our array recursively in equal halves till it can't be divided further.
//And then we start merging the individual elements in sorted manner.
//At the end we will get our sorted array.

//HEADER FILES
#include<iostream>
using namespace std;

//METHOD TO MERGE
void merge(int ar[],int lower,int mid,int higher)
{
  int i=lower, j=mid+1 ,k=lower;
  
  //creating an array 'aux' for utility
  int aux[higher+1];

 //the elements are compared from the two halves and put in the aux array in increasing order
  while (i<=mid  &&  j<=higher)
  {
      if (ar[i]<ar[j])
      {
          aux[k]=ar[i];
          k++;
          i++;
      }
      else
      {
          aux[k]=ar[j];
          k++;
          j++;
      }
  }
     //the next two loops are to make sure to include the elements left over from the above loop in aux array. 
      for( ; i<=mid ; i++)
      {
          aux[k]=ar[i];
          k++;
      }
      for( ; j<=higher ; j++)
      {
          aux[k]=ar[j];
          k++;
      }

      //COPYING BACK INTO THE ORIGINAL
      for(i=lower;i<=higher;i++)
      {
          ar[i]=aux[i];
      }
}

void mergesort(int ar[],int lower,int higher)
{
    if (lower<higher)              //MINIMUM 2 ELEMENTS BASE CONDITION
    {
        //mid point of the array is found
        int mid = (lower+higher)/2;
        //mergesort function is called recursively while dividing the array on and on till it can't be divided further
        mergesort(ar,lower,mid);
        
        mergesort(ar,mid+1,higher);

        merge(ar,lower,mid,higher);
    }
}

//DRIVER CODE
int main()
{
    //lower is for the lower index, higher for the higher index
    // these variables will be used to divide the array in equal halves
    int lower,higher,i,size;
    cout<<"Enter size of array - ";
    cin>>size;
    int ar[size];
    //taking array as input
    cout<<"enter elements into the array:"<<endl;
    for (i=0;i<size;i++)
    {
        cin>>ar[i];
    }
    lower=0;
    higher=size-1;

    mergesort(ar,lower,higher);
    cout<<endl<<endl;
    //printing the sorted array
    for (i=0;i<size;i++)
    {
        cout<<ar[i]<<" ";
    }
    
}
