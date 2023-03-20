#include<iostream>
using namespace std;

int f(int arr[], int n){
    int leftproduct = 1;
    int rightproduct = 1;

    int maxelt = -1;
    int idx = -1;
    for(int i=0; i<n; i++){
        if(maxelt < arr[i]){
            maxelt = arr[i];
            idx = i;
        }
        else if(maxelt == arr[i]){
            idx = i;
        }
    }
  
    leftproduct *= maxelt;

    for(int i=0; i<n; i++){
        if(arr[i] == maxelt && i==idx){
            continue;
        }
        else{
            rightproduct *= arr[i];
        }
    }
    cout<<rightproduct<<endl;

    if(rightproduct == leftproduct){
        return idx;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Array is:";
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
  
    cout<<endl;

    int x = f(arr, n);
    cout<<"Index is:"<<x;
    return 0;
}

// Approach: Pick the largest element and then find product of remaining elements. If equal then, return index of largest element; else return -1.
// TC - o(n)  SC - o(1)
