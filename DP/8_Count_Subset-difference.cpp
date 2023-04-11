#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Subset_Sum(int** t, int arr[], int n, int sum){
    // t[0][0] = 1;
    for(int i=0; i<n+1; i++){
        t[i][0] = 1;
    }
    for(int i=1; i<sum+1; i++){
        t[0][i] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    // int arr[] = {1, 1, 2, 3};
    int arr[] = {0, 0, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(auto &i : arr){
        sum += i;
    }
    int **t;
    t = new int*[n+1];
    for(int i=0; i<=n; i++){
        t[i] = new int[sum+1];
    }
    int diff=1;
    /*
    s1 + s2 = sum;
    s1 - s2 = diff;
    s1 = (sum + diff)/2;
    */
   int a = (sum+diff)/2;
   int x = Subset_Sum(t, arr, n, a);
   cout<<"The number of possible subset is "<<x<<endl;
}