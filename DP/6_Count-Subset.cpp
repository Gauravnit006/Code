#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Iterative method
int Count_Subset(int arr[], int n, int sum){
    int t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    // for (int i = 0; i <= n; i++)
    //     t[i][0] = true;
 
    
    // for (int i = 1; i <= sum; i++)
    //     t[0][i] = false;
    for(int i=1; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int RCount_Subset(int arr[], int n, int sum){
    if(sum==0) return 1;
    if(n==0) return 0;

    if(arr[n-1]<=sum){
        return RCount_Subset(arr, n-1, sum-arr[n-1]) + RCount_Subset(arr, n-1, sum);
    }
    else{
        return RCount_Subset(arr, n-1, sum);
    }
    return 0;
}

int main(){

    int arr[6] = {2, 3, 5, 6, 8, 10};
    // int arr[] = {0, 0, 0, 0, 0, 0, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=10;
    // int sum = 1;
    // cout<<Subset_Sum(arr, n, sum)<<endl;
    cout<<"Iterative method : ";
    int x = Count_Subset(arr, n, sum);
    cout<<x<<endl;

    // cout<<"Recursive method : ";
    // int y = RCount_Subset(arr, n, sum);
    // cout<<y<<endl;
    

    // return 0;
}