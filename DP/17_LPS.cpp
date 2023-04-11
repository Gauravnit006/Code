#include<bits/stdc++.h>
using namespace std;

int LPS(string s){
    int n = s.size();
    string p = s;
    reverse(p.begin(), p.end());
    vector<vector<int>> t(n+1, vector<int>(n+1, 0));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1] == p[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][n];
}

int main(){

    string str = "agbcba";
    // LPS = LCS

    int x = LPS(str);
    cout<<"Longest palindromic sequence : "<<x<<endl;

    return 0;
}