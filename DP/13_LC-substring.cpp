#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int T_LCSString(int **t, string s, string p, int n, int m){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i ==0 || j ==0){
                t[i][j] = 0;
            }
        }
    }
    int len = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s[i-1] == p[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                len = max(len, t[i][j]);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    return len;
}

int R_LCSString(string s, string p, int n, int m, int count){
    if(n==0 || m==0){
        return 0;
    }
    if(s[n-1]==p[m-1]){
        count =  1 + R_LCSString(s, p, n-1, m-1, count);
    }
    else{
        count = max(R_LCSString(s, p, n, m-1, count), R_LCSString(s, p, n-1, m, count));
    }
    return count;
}

int main(){
    string str1 = "abcdxyz";
    string str2 = "xyzabcd";
    int n = str1.size();
    int m = str2.size();
    int **t;
    t = new int*[n+1];
    for(int i=0; i<n+1; i++){
        t[i] = new int[m+1];
    }
    int x = T_LCSString(t, str1, str2, n, m);
    cout<<x<<endl;
    x = R_LCSString(str1, str2, n, m, 0);
    cout<<x<<endl;
    return 0;
}