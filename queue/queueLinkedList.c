#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* ll;

ll front = NULL, rear = NULL;

ll createNode(int value){
    ll newNode = (ll) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(){
    int value;
    printf("Enter data: ");
    scanf("%d", &value);

    ll temp = createNode(value);

    if(front == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;

}

void dequeue(){
    if(front == NULL){
        printf("List is Empty\n");
        return;
    }

    ll temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    printf("Element deleted: %d\n", temp->data);
    free(temp);
}

void display(){
    if(front == NULL){
        printf("List is Empty\n");
        return;
    }

    ll run = front;
    while(run != NULL){
        printf("%d  ", run->data);
        run = run->next;
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