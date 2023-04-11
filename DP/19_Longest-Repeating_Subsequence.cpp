#include<bits/stdc++.h>
using namespace std;

int LRS(string s, int n){
    string s1 = s;
    vector<vector<int>> t(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == s1[j-1] && i != j){
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][n];
}

int main(){
    string s = "AABEBCDD";
    int n = s.size();
    int x = LRS(s, n);
    cout<<x<<endl;
}