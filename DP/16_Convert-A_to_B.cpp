#include<bits/stdc++.h>
using namespace std;

int LCS(string s, string p, int m, int n){
    vector<vector<int>> t(m+1, vector<int>(n+1, 0));
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1] == p[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[m][n];
}

int main(){

    string str1 = "heap";
    string str2 = "pea";
    int m = str1.size();
    int n = str2.size();
    int x = LCS(str1, str2, m, n);
    cout<<"Number of deletion : "<<m-x<<endl;
    cout<<"Number of insertion : "<<n-x<<endl;

    return 0;
}