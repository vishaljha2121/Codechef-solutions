//
//  main.c
//  compilers and parser
//
//  Created by Vishal Jha on 30/10/20.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int T=0;
    scanf("%d",&T);
    while(T--){
        char s[1000000];
        scanf("%s",s);
        int l= strlen(s);
        int i =0,top=0,count=0,stack[l];
        for(i=0;i<l;i++){
            if(s[i]=='<'){
                stack[top++]=i;
            }
            else if (s[i]=='>'){
                if(top>0){
                    top--;
                    count+=2;
                }else{
                    break;
                }
            }
        }
        if (top>0) {
            count = stack[0];
        }
        printf("%d\n",count);
    }
    return 0;
}
