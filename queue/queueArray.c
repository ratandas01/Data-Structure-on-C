#include<stdio.h>
#define max 10

int queue[max], front = -1, rear = -1;

void enqueue(){
    int value;

    if(rear == max - 1){
        printf("Queue overflow\n");
        return;
    }

    if(front == -1){
        front = 0;
    }

    printf("Enter data: ");
    scanf("%d", &value);

    queue[++rear] = value;
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        front = rear = -1;
        return;
    }

    printf("Element Dequed: %d\n",queue[front++]);
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is Empty");
        return;
    }

    for(int i = front; i <= rear; i++){
        printf("%d  ", queue[i]);
    }

    printf("\n");
}

int main(){
    int option;

    while(1){
        printf("\n============= QUEUE MENU ===============\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Program Terminated Successfully\n"); return 0;
            default: printf("Invalid choice! Try Again\n");
        }
    }

    return 0;
}