//
//  main.c
//  Stupid machine
//
//  Created by Vishal Jha on 30/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T =0;
    scanf("%d", &T);
    while(T--){
        long long int n,min,sum=0;
        scanf("%lld",&n);
        long long int a[n],b[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            b[i]=0;
        }
        min = a[0];
        for(int i=0;i<n;i++){
            if(a[i]<min){
                min = a[i];
                b[i] = min;
            }else{
                b[i] = min;
            }
        }
        for (int i =0; i<n; i++) {
            sum += b[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
