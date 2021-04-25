//
//  main.c
//  Ciel and A-B Problem
//
//  Created by Vishal Jha on 25/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,c;
    scanf("%d %d", &a,&b);
    c = a-b;
    if (c%10==9) {
        c--;
    }else{
        c++;
        printf("%d\n", c);
    }
    
    printf("%d", c);
    return 0;
}
