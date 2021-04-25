//
//  main.c
//  Cleaning up
//
//  Created by Vishal Jha on 25/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T = 0;
    while(--T){
        int n,m,i=0;
        scanf("%d %d", &n,&m);
        int M[m];
        for(i=0;i<n;i++){
            scanf("%d", &M[i]);
        }
        int temp[n];
        for(i=0;i<n;i++){
            temp[i] = i+1;
        }
        int j = 0, tempo,k=0;
        //sorting the array
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(M[j]>M[j+1]){
                    tempo = M[j];
                    M[j] = M[j+1];
                    M[j+1] = tempo;
                }
            }
        }
        int b[n-m];
        for(i=0;i<n;i++){
            if(temp[i]==M[j]){
                j++;
            }else{
                b[k]=temp[i];
                k++;
            }
        }
        for(i=0;i<n-m;i=i+2){
            printf("%d ",b[i]);
        }
        printf("\n");
        for(i=1;i<n-m;i=i+2){
            printf("%d ", b[i]);
        }
        printf("\n");
        
    }
    return 0;
}
