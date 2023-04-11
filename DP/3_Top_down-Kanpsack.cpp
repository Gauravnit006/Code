#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int static t[102][1002];
// memset(t, -1, sizeof(t));

int KnapSack(int wt[], int val[], int w, int n){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0) t[i][j] = 0;
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){
    int wt[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    memset(t, -1, sizeof(t));
    int n = sizeof(wt)/sizeof(wt[0]);
    int w=50;
    int x=KnapSack(wt, val, w, n);
    cout<<x<<endl;
    return 0;
}