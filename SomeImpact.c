//
//  main.c
//  Some Impact
//
//  Created by Vishal Jha on 25/10/20.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    while (T != 0) {
        long long n,k,m,x;
        scanf("%d %d %d %d", &n,&k,&m,&x);
        if(k==1){
            if(n==m){
                n=0;
            }else{
                n=1;
            }
        }else if(m%k>1){
                n=1;
            }else if(k==2){
                long long m1=m,m2=m,n1=0,n2=0;
                while (m1) {
                    n1+=m1%2;
                    m1/=2;
                }
                n2+=m2%2;
                m1/=2;
                while(m2){
                    x=m2%2?1:2;
                    n2+=x;
                    m2=(m2-x)/2;
                }
                if (n>=n1&&n<=n2) {
                    n=0;
                }else{
                    while(m){
                        x=m%k;
                        if (x>2) {
                            n=1;
                            break;
                        }
                        n-=x;
                        m/=k;
                    }
                }
                if (n) {
                    printf("no\n");
                }else{
                    printf("yes\n");
                }
            }
        }
        --T;
    }
    return 0;
}
