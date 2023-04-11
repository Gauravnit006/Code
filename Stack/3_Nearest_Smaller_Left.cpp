#include<bits/stdc++.h>
using namespace std;

void NSL(int arr[], int n){
    stack<int> st;
    int t;
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            t=arr[i];
            arr[i] = st.top();
            st.push(t);
        }
        else{
            st.push(arr[i]);
            arr[i]=-1;
        }
    }
    return;
}

int main(){

    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    NSL(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}