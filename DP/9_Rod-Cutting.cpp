#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Rod_Cut(int price[], int n, int size){
    if(n==0 || size==0) return 0;
    if(n<=size){
        return max(price[n-1] + Rod_Cut(price, n, size-n), Rod_Cut(price, n-1, size));
    }
    else{
        return Rod_Cut(price, n-1, size);
    }
}

int IRod_Cut(int price[], int n, int length){
    int t[n+1][length+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<length+1; j++){
            if(i==0) t[i][j] = 0;
            if(j == 0) t[i][j] = 0;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<length+1; j++){
            if(i<=j){
                t[i][j] = max(price[i-1] + t[i][j-i], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][length];
}

int main(){
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(price)/sizeof(price[0]);
    // int x = Rod_Cut(price, size, size);
    int x = IRod_Cut(price, size, size);
    cout<<x<<endl;

}