//
//  main.c
//  Racing Horses
//
//  Created by Vishal Jha on 25/10/20.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int T = 0, i,j;
    scanf("%d", &T);
    int N;
    while (T != 0) {
        scanf("%d", &N);
        int s[N], min;
        for (i = 0;i<N;i++){
            scanf("%d", &s[i]);
        }
        min = (int)abs(s[0]-s[1]);
        for(i=0; i<N;i++){
            for(j=0;(j<N)&&(i!=j);j++){
                if (abs(s[i]-s[j])<=min) {
                    min = abs(s[i]-s[j]);
                }
            }
        }
        --T;
        printf("%d\n",min);
    }
    return 0;
}
