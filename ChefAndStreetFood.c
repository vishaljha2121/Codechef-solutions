//
//  main.c
//  Chef and street food
//
//  Created by Vishal Jha on 29/10/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    // your code goes here
    int x;
    scanf("%d",&x);
    while(x>0){
        int n, mx=0;
        scanf("%d",&n);
        while(n>0){
            int s,p,v;
            scanf("%d",&s);
            scanf("%d",&p);
            scanf("%d",&v);
            int a=p/(s+1);
            int b=v*a;
            if(mx<b){
                mx=b;
            }
            n--;
        }
        printf("%d\n",mx);
        x--;
    }
    
    return 0;
}

