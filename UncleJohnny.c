//
//  main.c
//  Uncle Johny
//
//  Created by Vishal Jha on 25/10/20.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T=0;
    scanf("%d", &T);
    while(T != 0){
        int n,pos;
        scanf("%d", &n);
        int A[n],k,i=0;
        for(i=0;i<n;i++){
            scanf("%d", &A[i]);
        }
        scanf("%d", &k);
        int UJ,j=0,temp;
        UJ = A[k-1];
        
        //sorting
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(A[j]>A[j+1]){
                    //swaping
                    temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
        //finding UJ
        for(i=0;i<n;i++){
            if (A[i]==UJ) {
                pos = i + 1;
                printf("%d", pos);
            }
        }
        
        --T;
    }
    return 0;
}
