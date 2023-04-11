#include<bits/stdc++.h>
using namespace std;

int Without_Repeating(string arr, int n){
    int mx=-1;
    int i=0, j=0;
    unordered_map<char, int> m;
    while(j<n){
        m[arr[j]]++;
        if(m.size()==j-i+1){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(m.size()<j-i+1){
            while (m.size()<j-i+1)
            {
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){

    string arr = "fwweacfc";
    int k=3;
    int n=arr.size();
    int ans = Without_Repeating(arr, n);
    cout<<ans<<endl;

    return 0;
}