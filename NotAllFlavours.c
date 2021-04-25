//
//  main.c
//  Not all flavours
//
//  Created by Vishal Jha on 31/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T =0,max,c;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d %d",&n,&k);
        int A[n];
        for(int i=0;i<n;i++){
            scanf("%d",&A[i]);
        }
        max=0;
        c=0;
        for(int i=0;i<=k;++i){
            c=0;
            for(int j =0;j<n;++j){
                if(A[j]==i){
                    if(c>max){
                        max=c;
                    }
                    c=0;
                }else{
                    c++;
                }
            }
            if(c>max){
                max=c;
            }
            if(max==n){
                break;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
