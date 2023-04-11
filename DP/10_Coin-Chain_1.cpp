#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Coin_Chain1(int coin[], int n, int sum){
    int dp[n+1][sum+1];
    dp[0][0] = 1;
    for(int i=1; i<n+1; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<sum+1; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coin[i-1]<=j){
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int RCoin_Chain1(int coin[], int n, int sum){
    if(sum==0) return 1;
    if(n==0) return 0;
    if(coin[n-1]<=sum){
        return RCoin_Chain1(coin, n-1, sum) + RCoin_Chain1(coin, n, sum-coin[n-1]);
    }
    else{
        return RCoin_Chain1(coin, n-1, sum);
    }
    
}

int main(){
    int coin[] = {1, 2, 3};
    int n = sizeof(coin)/sizeof(coin[0]);
    int sum = 5;
    // int x = Coin_Chain1(coin, n, sum);
    int x = Coin_Chain1(coin, n, sum);
    cout<<x<<endl;
}