#include<stdio.h>
#define MAX 3
int stack[MAX];
int top =-1;
void push(){
    int value;
    if(top == MAX -1){
        printf("stack overflow\n");
    }
    else{

        printf("enter a value to push\n");
        scanf("%d",&value);
        top++;
        stack[top] = value;
    }
}
int pop(){
    int value;
    if(top == -1){
        printf("Stack underflow\n");
    }
    else{
        value = stack[top];
        top --;
    }
    return value;
}
void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        for(int i = top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("Enter choice based on operation\n 1-push, 2-pop, 3-display, 4-exit :\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                break;
            case 2: printf("%d\n",pop());
                break;
            case 3: display();
                break;
            case 4: return 0;
                break;
            default :
                printf("Not a valid choice\n");
                break;
        }
    }
    return 0;

}














