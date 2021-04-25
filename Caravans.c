//
//  main.c
//  Carvans
//
//  Created by Vishal Jha on 29/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T =0;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        int a[n],i=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int count = 0;
        for (i=0; i<n; i++) {
            if (a[i]>=a[i+1]) {
                count++;
                a[i] = a[i+1];
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
