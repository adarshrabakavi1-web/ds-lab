#include<stdio.h>
#define MAX 3
int queue[MAX];
int front = -1;
int rear = -1;
void insert(){
    int val;
    if(rear == MAX - 1 ){
        printf("Queue is full\n");
        return;
    }
    printf("Enter value to enque \n");
    scanf("%d",&val);

    if(front == -1){
        front =0;
    }
    rear++;
    queue[rear] = val;

}
void remove1(){
    int val;
    if(front == -1 || front>rear){
        printf("queue is empty");
        return;
    }
    val = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
    printf("The removed element is %d\n",val);
}
void disp(){
    if(front == -1){
        printf("Queue is empty");
    }
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}
int main(){
    int choice;
    printf("1-enque,2-deque,3-display,4-exit\n");
    while(1){
        printf("Enter a choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
                break;
            case 2:remove1();
                break;
            case 3:disp();
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


