//
//  main.cpp
//  Euron problem
//
//  Created by Vishal Jha on 06/11/20.
//

#include <iostream>
#include <vector>
#define vl vector<ll>
#define ll long long int
using namespace std;

ll merge(vl &arr, vl &temp, ll left, ll mid, ll right){
    ll i, j, k;
    ll inv_count = 0;
    i = left;
    j = mid;
    k = left;
    
    while((i <= mid -1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    
    for(i = left; i <= right; i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

ll mergeSort(vl &arr, vl &temp, ll left, ll right){
    ll mid, inv_count = 0;
    if(right > left){
        mid = (right + left) /2;
        
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >>n;
    vl a(n);
    for(int i =0;i<n;++i){
        cin>>a[i];
    }
    vl temp(n);
    ll ans = mergeSort(a, temp, 0, n-1);
    cout<<ans;
    
    return 0;
    
}
