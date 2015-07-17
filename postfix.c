#include<stdio.h>
#include<ctype.h>

typedef struct{
    char ch;
}StackData;

#include "stack.h"

main(){
    int readConvert(char[]);
    void printPostfix(char[], int);
    char post[50];

    int n = readConvert(post);
    printPostfix(post, n);
}

int readConvert(char post[]){
    char getToken(void), token, c;
    int precedence(char);
    StackData temp;
    int j = 0;
    Stack S = initStack();

    printf("Type an infix expression and press Enter\n");
    token = getToken();
    while(token != '\n'){
        if(isdigit(token))post[j++] = token;
        else if(token == '('){
                    temp.ch = token;
                    push(S, temp);
                }
        else if(token == ')')
            while((c = pop(S).ch)!= '(')post[j++] = c;
        else{
            while(!empty(S) && precedence(peek(S).ch)>= precedence(token))
                post[j++] = pop(S).ch;
            temp.ch = token;
            push(S, temp);
        }
        token = getToken();
    }
    while(!empty(S))post[j++] = pop(S).ch;
    return j;//the size of the expression
}

void printPostfix(char post[], int n){
    int j;
    printf("\nThe postfix form is \n");
    for(j = 0; j < n; j++)printf("%c ", post[j]);
    printf("\n");
}

int precedence(char c){
    if(c == '(')return 0;
    if(c == '+' || c == '-')return 3;
    if(c == '*' || c == '/')return 5;
}

char getToken(){
    char ch;
    while((ch = getchar()) == ' ');//empty body
    return ch;
}
