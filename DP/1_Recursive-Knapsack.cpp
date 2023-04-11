#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int KnapSack(int wt[], int val[], int w, int n){
    if(n==0 || w==0) return 0;
    if(wt[n-1]<=w){
        return max((val[n-1]+KnapSack(wt, val, w-wt[n-1], n-1)), KnapSack(wt, val, w, n-1));
    }
    else if(wt[n-1]>w){
        return KnapSack(wt, val, w, n-1);
    }
    return 0;
}

int main(){
    int wt[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    int n = sizeof(wt)/sizeof(wt[0]);
    int w=50;
    int x=KnapSack(wt, val, w, n);
    cout<<x<<endl;
    return 0;
}