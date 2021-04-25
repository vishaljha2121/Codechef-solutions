//
//  main.c
//  wormholes
//
//  Created by Vishal Jha on 31/10/20.
//

#include <stdio.h>
#include <stdlib.h>

int dcompare(const void* pa, const void* pb){
    const int *a = *((const int**)pa);
    const int *b = *((const int**)pb);
    if(a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}

int compare(const void* a, const void* b){
    return *((int*)a)-*((int*)b);
}

int sortaBinary(int w[],int end_time, int first, int last){
    if(first<=last){
        int this_is_it;
        int mid_index = (first + last)/2;
        this_is_it = w[mid_index];
        if(w[mid_index]>end_time){
            this_is_it = sortaBinary(w, end_time, first, mid_index-1);
        }
        else if(w[mid_index]<end_time){
            this_is_it = sortaBinary(w, end_time, mid_index+1, last);
        }
        if(this_is_it<end_time){
            this_is_it = w[mid_index];
        }
        return this_is_it;
    }else{
        return 0;
    }
}


int main(int argc, const char * argv[]) {
    int n, x, y, **con_times, *v, *w, shortest = 100002, s, t1, t2, min_start=100002, max_start=0, min_end=100002, max_end=0;
    scanf("%d %d %d",&n,&x,&y);
    con_times = (int**)malloc(n*sizeof(int*));
    v = (int*)malloc(x*sizeof(int));
    w = (int*)malloc(y*sizeof(int));
    for(int i =0;i<n;i++){
        con_times[i]=(int*)malloc(2*sizeof(int));
        scanf("%d %d",&con_times[i][0],&con_times[i][1]);
        if(min_start>con_times[i][0])
            min_start = con_times[i][0];
        if(max_start<con_times[i][0])
            max_start = con_times[i][0];
        if(min_end>con_times[i][1])
            min_end = con_times[i][1];
        if(max_end<con_times[i][1])
            max_end = con_times[i][1];
    }
    qsort(con_times, n, sizeof(con_times[0]), dcompare);
    
    int c_ssk=0,start_v,end_v,c_esk=0,start_w,end_w;
    for(int i=0;i<x;i++){
        scanf("%d",&v[i]);
        if(v[i]>max_start){
            v[i]=0;
            c_ssk++;
        }
    }
    
    qsort(v,x,sizeof(int),compare);
    start_v = c_ssk;
    for(int i=start_v;i<x;i++){
        if(v[i]>min_start){
            start_v = i-1;
            break;
        }
    }
    
    for(int i=0;i<y;i++){
        scanf("%d",&w[i]);
        if(w[i]<min_end){
            w[i]=0;
            c_esk++;
        }
    }
    
    qsort(w,y,sizeof(int),compare);
    start_w = c_esk;
    for(int i=y-1;i>=start_w;i--){
        if(w[i]<max_end){
            end_w=i;
            break;
        }
    }
    
    for(int i=x-1;i>=start_v;i--){
        if(v[i]<=w[end_w]){
            end_v=i;
            break;
        }
    }
    
    s=start_v;
    for(int i=0;i<n;i++){
        if(con_times[i][0] < v[start_v] || con_times[i][1] > w[end_w]){
            continue;
        }
        while(s<=end_v){
            if(v[s]>con_times[i][0]){
                break;
            }
            s++;
        }
        t1=v[s-1];
        t2 = sortaBinary(w, con_times[i][1], start_w, end_w);
        if(shortest>(t2-t1+1))
            shortest = t2-t1+1;
    }
    printf("%d",shortest);
    return 0;
}
