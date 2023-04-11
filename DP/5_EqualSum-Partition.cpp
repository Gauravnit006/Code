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

bool EqualSum_Part(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum%2 != 0) return false;
    else if (sum%2 ==0) return Subset_Sum(arr, n, sum/2);
    return 0;
}

int main(){

    // int arr[5] = {2, 3, 7, 8, 10};
    int arr[4] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<Subset_Sum(arr, n, sum)<<endl;
    cout<<"Iterative method : ";
    if(EqualSum_Part(arr, n)==true) cout<<"True";
    else if(EqualSum_Part(arr, n)==false) cout<<"False";
    cout<<endl;
    

    // return 0;
}