//
//  main.c
//  penalty shoot-outs 2
//
//  Created by Vishal Jha on 29/10/20.
//

#include <stdio.h>

int main(void) {
    // your code goes here
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char str[2*n+1];
        scanf("%s",str);
        int chanceA=n;
        int chanceB=n;
        int shotA=0;
        int shotB=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                if(str[i]=='1'){
                shotA++;}
                chanceA--;
            }
            else{
                if(str[i]=='1'){
                shotB++;}
                chanceB--;
            }
            if(shotA>shotB+chanceB){
                printf("%d\n",i+1);
                break;
            }
            else if(shotB>shotA+chanceA){
                printf("%d\n",i+1);
                break;
            }
            else if(shotA==shotB && i==2*n-1){
                printf("%d\n",i+1);
                break;
            }
        }
        
    }
    return 0;
}

