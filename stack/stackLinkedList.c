#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* ll;

ll top = NULL;

ll createNode(int value){
    ll newNode = (ll) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(){
    int value;
    printf("Enter data: ");
    scanf("%d", &value);
    
    ll temp = createNode(value);
    
    temp->next = top;
    top = temp;
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }

    ll temp = top;
    top = top->next;
    printf("Element popped: %d\n", temp->data);
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

int main(){
    int option;
    while(1){
        printf("\n========== STACK MENU ===========\n");
        printf("1.Push element\n");
        printf("2.Pop element\n");
        printf("3.Peek element\n");
        printf("4.Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf("Program Terminated Successfully\n"); return 0;
            default: printf("Invalid choice ! Try again\n");
        }
    }
    return 0;
}