//
//  main.c
//  Factorial
//
//  Created by Vishal Jha on 24/10/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int T = 0;
    scanf("%d", &T);
    while (T != 0) {
        int noOfZeros = 0;
        long long number = 0;
        scanf("%d", &number);
        while (number > 0) {
            number = number / 5;
            noOfZeros += number;
        }
        printf("%d\n", noOfZeros);
        --T;
    }
    return 0;
}
