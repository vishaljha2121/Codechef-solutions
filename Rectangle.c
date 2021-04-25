//
//  main.c
//  rectangle
//
//  Created by Vishal Jha on 03/11/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(const void * a, const void * b){
    return (*(int*)b - *(int*)a);
}


int main() {
    int t,n,i,j,l,k;
    int A[100001];
    for(i=0;i<100000;i++){
        A[i] = 500;
    }
    A[100000] = 0;
    int x,y;
    int s[100000];
    int top = -1;
    scanf("%d",&n);
    for(k=1;k<=n;k++){
        scanf("%d %d",&x,&y);
        if(A[x]>y)
            A[x] = y;
    }
    int area = 0;
    for(i=1;i<100000;i++){
        while(top >= 0 && A[s[top]] > A[i]){
            j = A[s[top]];
            top--;
            l=0;
            if(top >= 0)
                l = s[top];
            t = (i-l)*j;
            if(t>area)
                area = t;
        }
        s[++top] = i;
    }
    printf("%d\n",area);
    return 0;
}
