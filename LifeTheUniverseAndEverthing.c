//
//  main.c
//  Life, the Universe and Everything
//
//  Created by Vishal Jha on 24/10/20.
//

#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    
    while (0<=number && number <100) {
        if (number == 42) {
            break;
        }
        printf("%d\n", number);
        scanf("%d", &number);
    }

    return 0;
}
