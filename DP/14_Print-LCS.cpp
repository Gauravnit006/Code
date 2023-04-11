#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

void LCS(int **t, string s, string p, int m, int n){
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1] == p[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
}

string Print_LCS(int **t, string s, string p, int m, int n){
    LCS(t, s, p, m, n);
    int i=m, j=n;
    string str = "";
    while(i>0 && j>0){
        if(s[i-1] == p[j-1]){
            str.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                j--;
            }
            else {
                i--;
            }
        }
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    string str1 = "abcdxyze";
    string str2 = "xyzabcde";
    int m = str1.size();
    int n = str2.size();
    int **t;
    t = new int*[m+1];
    for(int i=0; i<m+1; i++){
        t[i] = new int[n+1];
    }
    string s = Print_LCS(t, str1, str2, m, n);
    cout<<s<<endl;
    delete t;
}