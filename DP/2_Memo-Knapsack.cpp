#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int static t[102][1002];
// memset(t, -1, sizeof(t));

int KnapSack(int wt[], int val[], int w, int n){
    if(n==0 || w==0) return 0;
    if(t[n][w] != -1){
        return t[n][w];
    }
    if(wt[n-1]<=w){
        return t[n][w]=max((val[n-1]+KnapSack(wt, val, w-wt[n-1], n-1)), KnapSack(wt, val, w, n-1));
    }
    else if(wt[n-1]>w){
        return t[n][w]=KnapSack(wt, val, w, n-1);
    }
    return 0;
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