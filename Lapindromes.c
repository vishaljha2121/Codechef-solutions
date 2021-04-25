//
//  main.c
//  lapindromes
//
//  Created by Vishal Jha on 28/10/20.
//

#include <stdio.h>
#include<string.h>

int main(void) {
    // your code goes here
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000];
        scanf("%s",s);
        int n,m,a[26]={0},b[26]={0};
        int l=strlen(s);
        if(l%2==0)
        {
             n=l/2;
             m=l/2;
        }
        else{
             n=l/2;
             m=l/2+1;
        }
        for(int i=0;i<n;i++)
        {
            a[s[i]-97]++;
        }
        for(int j=m;j<l;j++)
        {
            b[s[j]-97]++;
        }
        int flag=-1;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}

