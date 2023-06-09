#include<bits/stdc++.h>
using namespace std;

int Subarray_Sum(int arr[], int n, int k){
    long sum=0;
    int mx=0;
    int i=0, j=0;
    while(j<n){
        sum += arr[j];
        if(sum<k){
            j++;
        }
        else if(sum==k){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(sum>k){
            while(sum>k){
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){

    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    int ans = Subarray_Sum(arr, n, k);
    cout<<ans<<endl;

    return 0;
}