//
//  main.c
//  Multiple of 3
//
//  Created by Vishal Jha on 29/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T =0,a[3],s,q,rem,i;
    int d0,d1;
    scanf("%d",&T);
    while(T--){
        long long int K;
        scanf("%lld %d %d",&K,&d0,&d1);
        int sum=0;
        s = d0+d1;
        a[0] = (2*s)%10;
        a[1] = (4*s)%10;
        a[2] = (4*s)%10;
        int sub;
        sub = a[0]+a[1]+a[2]+((6*s)%10);
        if(K==2){
            sum=s;
        }
        else if(K==3){
            sum=2*s;
        }
        else{
            q=(K-3)/4;
            rem=(K-3)%4;
            sum = s+(s%10)+(q*sub);
            for(i=0;i<rem;i++){
                sum+=a[i];
            }
            
        }
        if(sum%3==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
