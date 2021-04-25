//
//  main.c
//  chef in queue
//
//  Created by Vishal Jha on 31/10/20.
//

#include <stdio.h>
#define m 1000000007
int main(int argc, const char * argv[]) {
    long long int n,k; //k:seniority
    scanf("%lld %lld",&n,&k);
    long long int a[n]; //queue if chefs
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    int s[n];
    int top =-1;
    long long int f=1;
    for(int i=n-1;i>=0;--i){
        while((top!=-1)&&(a[s[top]]>=a[i])){
            --top;
        }
        if((top!=-1)&&(a[s[top]]<a[i])){
            f=(f%m*(s[top]-i+1))%m;
        }
        ++top;
        s[top]=i;
    }
    printf("%lld\n",f);
    return 0;
}
