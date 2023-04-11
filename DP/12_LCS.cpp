#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int R_LCS(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1+R_LCS(x, y, n-1, m-1);
    }
    else{
        return max(R_LCS(x, y, n, m-1), R_LCS(x, y, n-1, m));
    }
    return 0;
}

int M_LCS(int** t, string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(x[n-1] == y[m-1]){
        t[n][m] = 1 + M_LCS(t, x, y, n-1, m-1);
    }
    else{
        t[n][m] = max(M_LCS(t, x, y, n, m-1), M_LCS(t, x, y, n-1, m));
    }
    return t[n][m];
}

int T_LCS(string x, string y, int n, int m){
    int t[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0) t[i][j] = 0;
            if(j==0) t[i][j] = 0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][m];
}

int main(){
    string str1 = "abcdh";
    string str2 = "abedfhr";
    int n = str1.size();
    int m = str2.size();
    // int p = R_LCS(str1, str2, n, m);
    // cout<<p<<endl;

    // int **t;
    // t = new int*[n+1];
    // for(int i=0; i<=n; i++){
    //     t[i] = new int[m+1];
    //     for(int j=0; j<=m; j++){
    //         t[i][j] = -1;
    //     }
    // }
    // memset(t, -1, sizeof(t));
    // memset(t, -1, sizeof(int) * (n+1) * (m+1));

    // int q = M_LCS(t, str1, str2, n, m);
    // cout<<q<<endl;

    int r = T_LCS(str1, str2, n, m);
    cout<<r<<endl;

    return 0;

}

