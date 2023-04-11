#include<bits/stdc++.h>
using namespace std;

void Next_Larger_Element(int arr[], int n){
    stack<int> st;
    int t;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]){
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
    int arr[] = {1, 3, 0, 0, 1, 2, 4};
    // int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    Next_Larger_Element(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}