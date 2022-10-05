#include <stdio.h>
#include <stdbool.h>

bool checkSorted(int *arr, int size){
    for(int i=0;i<size-1;i++)
        if(arr[i+1] < arr[i]) return false;
    return true;
}
void shuffle(int *arr, int n){
    printf("Shuffling: \t");
    for(int i=0;i<n;i++){
        // Fun fact: Random number generation is such a fascinating topic
        srand(rand());
        int r = rand()%n;
        int temp = arr[r];
        arr[r] = arr[i];
        arr[i] = temp;
    }
}
int main(int argc, char **argv){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter %d elements\n", n);
    for(int i=0;i<n;scanf("%d", &arr[i]), i++);
    while(!checkSorted(arr, n)){
        shuffle(arr, n);
        for(int i=0;i<n;printf("%d, ", arr[i]), i++);
        printf("\n");
    }
    return 0;
}