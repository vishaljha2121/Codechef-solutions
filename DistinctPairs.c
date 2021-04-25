//
//  main.c
//  Distinct pairs
//
//  Created by Vishal Jha on 04/11/20.
//

#include <stdio.h>
#include <limits.h>

int main() {
    int n,m,i,min_index,max_index;
    long int a, max=INT_MIN, min=LONG_MAX;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%ld",&a);
        if(a>max){
            max=a;
            max_index=i;
        }
    }
    for(i=0;i<m;i++){
        scanf("%ld",&a);
        if(a<min){
            min=a;
            min_index=i;
        }
    }
    for(i=m-1;i>=0;i--){
        printf("%d %d\n",max_index,i);
    }
    for(i=n-1;i>=0;i--){
        if(i!=max_index)
            printf("%d %d\n",i,min_index);
    }
    return 0;
}
