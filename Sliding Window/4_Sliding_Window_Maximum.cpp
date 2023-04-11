#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(int arr[], int k, int n){
    list<int> l;
    vector<int> ans;
    int t, i=0, j=0;
    while(j<n){
        if(l.empty()) l.push_back(arr[j]);
        else{
            while(!l.empty()){
                t=l.back();
                if(arr[j]>t){
                    l.pop_back();
                }
                else break;
            }
            l.push_back(arr[j]);
        }
        if(j-i+1<k){
            j++;
        }
        else{
            t = l.front();
            ans.push_back(t);
            if(t==arr[i]) l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

int main(){

    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> ans = maxSlidingWindow(arr, k, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}