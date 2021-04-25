//
//  main.c
//  Coin Flip
//
//  Created by Vishal Jha on 27/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d", &T);
    while(T != 0){
        int g, j=0,k=0;
        scanf("%d", &g);
        int i,n,q;
        for(j=0;j<g;j++){
            int count = 0;
            scanf("%d %d %d", &i,&n,&q);
            int A[n];
            if(i==1){
                for(j=0;j<n;j++){
                    A[n] = 1;
                }
                for(j=0;j<n;j++){
                    for(k=0;k<j;k++){
                        if(A[k]==1){
                            A[k] = 0;
                        }else{
                            A[k] = 1;
                        }
                    }
                }
            }else if(i==0){
                for(j=0;j<n;j++){
                    A[n] = 0;
                }
                for(j=0;j<n;j++){
                    for(k=0;k<j;k++){
                        if(A[k]==1){
                            A[k] = 0;
                        }else{
                            A[k] = 1;
                        }
                    }
                }
            }
            for(j=0;j<n;j++){
                if(A[n]==q){
                    count++;
                }
            }
            printf("%d\n", count);
        }
        --T;
    }
    return 0;
}
