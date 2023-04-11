#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void Subset_Sum(bool** t, int arr[], int n, int sum){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else if(arr[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
}

int main(){
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    bool** t;
    t = new bool*[n+1];
    for(int i=0; i<n+1; i++){
        t[i] = new bool[sum+1];
    }
    Subset_Sum(t, arr, n, sum);
    vector<int> v;
    for(int i=0; i<=sum/2; i++){
        if(t[n][i] == true){
            v.push_back(i);
        }
    }
    int x = sum - 2*v[v.size()-1];
    cout<<x<<endl;
}