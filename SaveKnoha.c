//
//  main.c
//  save konoha
//
//  Created by Vishal Jha on 03/11/20.
//

#include <stdio.h>

int parent(int n){
    return (n-1)/2;
}

int leftChild(int n){
    return 2*n + 1;
}

int rightChild(int n){
    return 2*n + 2;
}

void heapSwap(int* array, int x, int y){
    int temp;
    temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void shiftDown(int* array, int size, int position){
    int leftChildIndex = leftChild(position);
    int rightChildIndex = rightChild(position);
    
    if(leftChildIndex >= size && rightChildIndex >= size)
        return;
    
    int maxChildIndex = leftChildIndex;
    int maxChildValue = array[leftChildIndex];
    
    if(rightChildIndex < size){
        if(array[rightChildIndex] > maxChildValue){
            maxChildIndex = rightChildIndex;
            maxChildValue = array[rightChildIndex];
        }
    }
    
    if(array[position] < maxChildValue){
        heapSwap(array, position, maxChildIndex);
        shiftDown(array, size, maxChildIndex);
    }
}

void buildMaxHeap(int* array, int size){
    int i;
    i = (size - 1)/2;
    for(;i>=0;i--){
        shiftDown(array, size, i);
    }
}

int getMax(int* array){
    return array[0];
}

void saveKonoha(int* soldierPowers, int numberOfSoldiers, long long int pain){
    buildMaxHeap(soldierPowers, numberOfSoldiers);
    
    unsigned long long int numberOfAttacks = 0;
    while (getMax(soldierPowers) != 0 && pain > 0){
        int maxSoldierPower = getMax(soldierPowers);
        pain -= maxSoldierPower;
        numberOfAttacks++;
        soldierPowers[0] = maxSoldierPower/2;
        shiftDown(soldierPowers, numberOfSoldiers, 0);
    }
    if (pain > 0){
        printf("Evacuate\n");
    }else{
        printf("%llu\n",numberOfAttacks);
    }
}

int main() {
    int t,n;
    long long int pain;
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&n,&pain);
        
        int soldiers[n];
        for(int i=0;i<n;i++){
            scanf("%d",&soldiers[i]);
        }
        saveKonoha(soldiers, n, pain);
    }
    return 0;
}
