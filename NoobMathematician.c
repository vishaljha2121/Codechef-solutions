//
//  main.c
//  Contest
//
//  Created by Vishal Jha on 28/10/20.
//
#define ll long long
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void merge_sort(int a[],  int l,  int h){
    ll int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, h);
        mergeHalves(a, l, mid, h);
    }
}

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

int main() {
    int T;
    scanf("%d",&T);
    while (T != 0) {
        char *a;
        a = inputString(stdin, 10);
//        printf("%s\n",a);
        
        int i=0, len = strlen(a);
        char b[len];
        int j=0;
        for(i=0;i<len;i++){
            if(a[i]!='+'){
                b[j] = a[i];
                j++;
            }
        }
        ll int len_b = strlen(b);
//        printf("%s\n", b);
        merge_sort(b, 0, len_b);
        
        T--;
    }
    return 0;
}
