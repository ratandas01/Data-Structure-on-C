#include<stdio.h>
#define max 20

int stack[max], top = -1;

void push(){
    int value;
    if(top == max -1){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &value);
    stack[++top] = value;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Element popped: %d\n", stack[top--]);
}

void peek(){
    if(top == -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

int main(){
    int option;
    while(1){
        printf("\n========= STACK MENU ==========\n");
        printf("1.Push Element\n");
        printf("2.Pop Element\n");
        printf("3.Peek Element\n");
        printf("4.Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf("Program Terminated Successfuly\n"); return 0;
            default: printf("Invalid choice ! Try Again\n");
        }
    }

    return 0;
}