#include<bits/stdc++.h>
using namespace std;

int Unique_Char(string arr, int n, int k){
    int mx=-1;
    int i=0, j=0, x;
    unordered_map<char, int> m;
    while(j<n){
        m[arr[j]]++;
        x = m.size();
        if(x<k){
            j++;
        }
        else if(x==k){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(x>k){
            while (x>k)
            {
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                    x--;
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){

    string arr = "aabacbebebe";
    int k=3;
    int n=arr.size();
    int ans = Unique_Char(arr, n, k);
    cout<<ans<<endl;

    return 0;
}