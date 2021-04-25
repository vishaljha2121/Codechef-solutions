//
//  main.c
//  Reverse the number
//
//  Created by Vishal Jha on 28/10/20.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int T = 0,i=0,k,t,j;
    scanf("%d", &T);
    char A[T][1000000];
    for(i=0;i<T;i++){
        scanf("%s", &A[i]);
    }
    for(i=0;i<T;i++){
        t = strlen(A[i])-1;
        for(k=t;k>=0;k--){
            if(A[i][k]=='0'){
                continue;
            }else{
                for(j=k;j>=0;j--){
                    printf("%c",A[i][j]);
                }printf("\n");
                break;
            }
        }
    }
    
    return 0;
}
