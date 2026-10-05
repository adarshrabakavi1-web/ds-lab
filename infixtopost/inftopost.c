#include<stdio.h>
#include<ctype.h>
#define MAX 100
int top = -1;
char stack[MAX];
void push(char ch){
    stack[++top] = ch;
}
char pop(){
    return stack[top--];
}
int pref(char ch){
    if(ch == '/' || ch =='*'){
        return 2;
    }
    if(ch == '+' || ch =='-'){
        return 1;
    }
    return 0;
}
void inftoPost(char infix[],char postfix[]){
    int i =0;
    int j =0;
    char ch;
    while(infix[i] != '\0'){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(stack[top] != '('){
                postfix[j++] = pop();
            }
            pop();
        }
        else{
            while(top != -1 && stack[top] != '(' && pref(stack[top]) >= pref(ch) ){
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while(top!= -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main(){
    char infix[MAX];
    char postfix[MAX];
    printf("Enter a infix");
    scanf("%s",infix);
    inftoPost(infix,postfix);
    printf("%s",postfix);
}
