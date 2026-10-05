#include <stdio.h>

int isValid(char s[]){
    char stack[10000];
    int top =-1;
    char ch,tch;
    for(int i =0;s[i] != '\0';i++){
        ch = s[i];
        if(ch =='(' || ch =='{' || ch =='['){
            stack[++top] = ch;
        }
        else{
            if(top == -1){
                return 0;
            }
            tch = stack[top--];
            if(ch == ')' && tch != '('){
                return 0;
            }
            if(ch == ']' && tch != '['){
                return 0;
            }
            if(ch == '}' && tch != '{'){
                return 0;
            }
        }
    }
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char s[10000];
    printf("enter a pattern");
    scanf("%s", s);
    int a;
    a = isValid(s);
    if(a == 1){
        printf("true");
    }
    else{
        printf("false");
    }



}
