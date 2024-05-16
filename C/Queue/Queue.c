#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct NODE
{
    int value;
    struct NODE* next;
} NODE;
int empty(NODE * front){
    if(front==NULL){
        return 1;
    } else {
        return 0;
    }
}
void enQueue(NODE **front, NODE **rear, int value){
    printf("enQueue(%d)\n", value);
    NODE * ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr == NULL){
        printf("Khong con du bo nho !\n"); 
    }
    ptr->value = value;
    ptr->next = NULL;
    if(*front == NULL)
    {
        *front = ptr;
        *rear = *front;
    } else {
        (*rear)->next = ptr;
        *rear = ptr;
    }
}
void deQueue(NODE **front)
{
    printf("deQueue()\n");
    if(empty(*front)){
        printf("Queue rong, khong the xoa ptu!!!");
    } else {
        struct NODE* temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}
int fRont(NODE * front)
{
    int value = INT_MIN;
    printf("front(): ");
    if(empty(front)){
        printf("Queue rong, khong co gia tri phan tu dau tien!!!");
        return 0;
    } else {
        value = front->value;
        return value;
    }
}
void printQueue(NODE* front)
{
    printf("Queue: ");
    if(empty(front)){
        printf("rong\n");
    }
    while(!empty(front)){
        printf("%d ", front->value);
        front = front->next;
    }
    printf("\n");
}
int main()
{
    NODE* front = NULL;
    NODE* rear = NULL;
    enQueue(&front, &rear, 10);
    enQueue(&front, &rear, 20);
    enQueue(&front, &rear, 30);
    printQueue(front);
    deQueue(&front);
    printQueue(front);
    printf("%d\n",fRont(front));
    return 0;
}