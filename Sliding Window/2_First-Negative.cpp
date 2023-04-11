#include<bits/stdc++.h>
using namespace std;

// Brute force
vector<int> First_Negative(int arr[], int n, int k, vector<int> &v){
    int i=0, j=0, t;
    while(j<n){
        if(j-i+1==k) break;
        j++;
    }
    int flag=0;
    while(j<n){
        t=i;
        flag = 0;
        while(t<=j){
            if(arr[t]<0){
                flag = 1;
                v.push_back(arr[t]);
                break;
            }
            t++;
        }
        if(flag ==0) v.push_back(0);
        i++;
        j++;
    }
    return v;
}

// Sliding window
vector<int> Y_First_Negative(int arr[], int n, int k, vector<int> &v){
    int i=0, j=0, t;
    queue<int> q;
    while(j<n){
        if(arr[j]<0) q.push(arr[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1 == k){
            if(q.size() == 0) v.push_back(0);
            else{
                v.push_back(q.front());
            }
            if(arr[i]<0) q.pop();
            i++;
            j++;
        }
    }
    return v;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> v;
    Y_First_Negative(arr, n, k, v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}