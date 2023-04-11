#include<bits/stdc++.h>
using namespace std;

int N_Element_Sum(int arr[], int n, int p){
    int x=0, y=0;
    for(int i=0; i<p; i++){
        x += arr[i];
        if(i>=n){
            x -= arr[i-n];
            y = max(x, y);
            // arr[i] += arr[i-1];
            // x = max(x, arr[i]);
        }
    }
    return y;
}

int Element_Sum(int arr[], int n, int p){
    int i=0, j=0;
    int sum=0;
    int x = INT_MIN;
    while(j<p){
        sum += arr[j];
        if(j-i+1<n){
            j++;
        }
        else if(j-i+1==n){
            if(i>0){
                sum -= arr[i-1];
            }
            x = max(sum, x);
            i++;
            j++;
        }
    }
    return x;
}

int main(){

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[] = {2, 3, 5, 2, 9, 7, 1};
    int p = sizeof(arr)/sizeof(arr[0]);
    int x = Element_Sum(arr, n, p);
    cout<<x<<endl;

    return 0;
}