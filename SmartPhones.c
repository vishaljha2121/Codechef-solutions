//
//  main.c
//  smart phones
//
//  Created by Vishal Jha on 28/10/20.
//
# define ll long long
#include <stdio.h>

void mergeHalves(ll int a[], ll int l, ll int mid, ll int h){
    ll int i=l, j=mid+1, k=l;
    ll int b[h + 1];
    
    while(i <= mid && j <= h){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
//    merging remaining of left if any
    for(;i<=mid;i++){
        b[k++] = a[i];
    }
//    merging remaining of right if any
    for(;j<=h;j++){
        b[k++] = a[j];
    }
//    copying the sorted part
    for(i = l;i<=h;i++){
        a[i] = b[i];
    }
}

void merge_sort(ll int a[], ll int l, ll int h){
    ll int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, h);
        mergeHalves(a, l, mid, h);
    }
}

int main(int argc, const char * argv[]) {
    ll int n;
    int i=0;
    scanf("%lld",&n);
    ll int a[n];
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    merge_sort(a, 0, n-1);
    ll int result=-1;
    for(i=0;i<n;i++){
        if(result<(a[i]*(n-i))){
            result = a[i]*(n-i);
        }
    }
    printf("%lld\n",result);
    return 0;
}
