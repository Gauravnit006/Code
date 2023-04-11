#include<bits/stdc++.h>
using namespace std;

string Path_SCS(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> t(m+1, vector<int>(n+1, 0));
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int i = m, j = n;
    string s = "";
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                s.push_back(s1[i-1]);
                i--;
            }
            else{
                s.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        s.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(s2[j-1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){

    string s1 = "acbcf";
    string s2 = "abcdaf";
    string s = Path_SCS(s1, s2);
    cout<<s<<endl;

    return 0;
}