//
//  main.c
//  Matched brackets
//
//  Created by Vishal Jha on 30/10/20.
//

#include <stdio.h>
#define ll long long

int main(int argc, const char * argv[]) {
    ll int n=0,i=0,j=0,dp,l=0,lp=0,flp,max=0,ml=0;
    scanf("%lld",&n);
    int t=0;
    for(j=0;j<n;j++)
        {
            scanf("%d",&t);
            if(t==1)
            {
                i++;
                if(max<i)
                {
                 max=i;
                 dp=j;
                }
            }
            else
            {
                i--;
            }
            l++;
            if(!i)
            {
                if(ml<l)
                {
                 ml=l;
                 flp=lp;
                }
                 l=0;
                lp=j+1;
            }
        }
        printf("%lld %lld %lld %lld",max,dp+1,ml,flp+1);
    return 0;
}
