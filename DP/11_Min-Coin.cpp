#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Min_Coin(int coin[], int sum, int n){
    int dp[n+1][sum+1];
    for(int i=1; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<sum+1; i++){
        dp[0][i] = INT_MAX-1;
    }
    for(int i=1; i<sum+1; i++){
        if(i%coin[0] != 0){
            dp[1][i] = INT_MAX-1;
        }
        else{
            dp[1][i] = i/(coin[0]);
        }
    }
    for(int i=2; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coin[i-1]<=j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i-1]]+1);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int coin[] = {1, 2, 3};
    int n = sizeof(coin)/sizeof(coin[0]);
    int sum = 5;
    int x = Min_Coin(coin, sum, n);
    cout<<x<<endl;

    return 0;
}