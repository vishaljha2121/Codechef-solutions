//
//  main.c
//  Infix to Postfix
//
//  Created by Vishal Jha on 30/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
}Stack;

void push(Stack* st,char ch){
    st->arr[++st->top] = ch;
}

void pop(Stack* st){
    --st->top;
}

char peek(Stack st){
    return st.arr[st.top];
}

bool isEmpty(Stack st){
    return st.top == -1;
}

bool ifOperand(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

int precedence(char ch){
    if(ch == '+' || ch == '-') {
        return 0;
    }
    else if (ch == '/' || ch == '*'){
        return 1;
    }
    else if (ch == '^') {
        return 2;
    }else{
        return 0;
    }
}

void infixToPostfix(char inputExp[], char outputExp[]){
    Stack tempStack;
    tempStack.top = -1;
    int idx = 0,i;
    for(i=0;i< strlen(inputExp);i++){
        if(ifOperand(inputExp[i])){
            outputExp[idx++] = inputExp[i];
        }else if(inputExp[i] == '('){
            push(&tempStack, inputExp[i]);
        }else if(inputExp[i] == ')'){
            while (peek(tempStack) != '(' && !isEmpty(tempStack)){
                outputExp[idx++] = peek(tempStack);
                pop(&tempStack);
            }
            pop(&tempStack);
        }
        else if (isEmpty(tempStack) || peek(tempStack) == '('){
            push(&tempStack, inputExp[i]);
        }
        else {
            while(true){
                if (isEmpty(tempStack) || peek(tempStack) == '(' || precedence(inputExp[i]) > precedence(peek(tempStack))) {
                    push(&tempStack, inputExp[i]);
                    break;
                }else if (precedence(inputExp[i]) < precedence(peek(tempStack))){
                    outputExp[idx++] = peek(tempStack);
                    pop(&tempStack);
                    continue;
                }else{
                    if (peek(tempStack) == '^'){
                        push(&tempStack, inputExp[i]);
                    }else{
                        outputExp[idx++] = peek(tempStack);
                        pop(&tempStack);
                        push(&tempStack, inputExp[i]);
                        break;
                    }
                }
            }
        }
    }
    while (!isEmpty(tempStack)) {
        outputExp[idx++] = peek(tempStack);
        pop(&tempStack);
    }
    outputExp[idx] = '\0';
}

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        char str[101], outputExp[101];
        scanf("\n%s",str);
        infixToPostfix(str, outputExp);
        printf("%s\n",outputExp);
    }
    return 0;
}
