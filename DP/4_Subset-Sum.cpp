#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Iterative method
bool Subset_Sum(int arr[], int n, int sum){
    bool t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    // for (int i = 0; i <= n; i++)
    //     t[i][0] = true;
 
    
    // for (int i = 1; i <= sum; i++)
    //     t[0][i] = false;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool RSubset_Sum(int arr[], int n, int sum){
    if(sum==0) return true;
    if(n==0) return false;

    if(arr[n-1]<=sum){
        return RSubset_Sum(arr, n-1, sum-arr[n-1]) || RSubset_Sum(arr, n-1, sum);
    }
    else{
        return RSubset_Sum(arr, n-1, sum);
    }
}

int main(){

    int arr[5] = {2, 3, 7, 8, 10};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=14;
    // cout<<Subset_Sum(arr, n, sum)<<endl;
    cout<<"Iterative method : ";
    if(Subset_Sum(arr, n, sum)==true) cout<<"True";
    else if(Subset_Sum(arr, n, sum)==false) cout<<"False";
    cout<<endl;
    cout<<"Recursive method : ";
    if(RSubset_Sum(arr, n, sum)==true) cout<<"True";
    else if(RSubset_Sum(arr, n, sum)==false) cout<<"False";

    // return 0;
}