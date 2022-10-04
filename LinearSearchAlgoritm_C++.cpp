//C++ Code Implementation of Linear Search Algorithm

#include <iostream>
#include <vector>

//LinearSearch function takes in input an array of vector and an integer X
//If X is present in arr then this function return true otherwise return false
bool LinearSearch(vector<int>arr,int X) {
    //Loop over this vector arr 
    for(auto u:arr) {
        //Check if u is equal to X
        if(u == X) {
            return true;
        }
    }
    //If X is not present in arr then return false
    return false;
}

using namespace std;

int main() {
    
    vector<int>arr = {3,4,5,6,9,-1,-6,91};

    if(LinearSearch(arr,4)) {
        cout<<"4 is present in arr\n";
    }
    else {
        cout<<"4 is not present in arr\n";
    }

    return 0;
}