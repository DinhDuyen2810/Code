#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE* prev,* next;
};
struct NODE* createNewNode(int data)
{
     struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
     newNode->data = data;
     newNode->prev = NULL;
     newNode->next = NULL;
     return newNode;
}
void pushfront(struct NODE** head, int data,struct NODE** tail)
{
    struct NODE* newNode = createNewNode(data);
    if(*head == NULL){
        *tail = *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void printlist1(struct NODE* head)
{
    printf("NULL -> ");
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void printlist2(struct NODE* tail){
    printf("NULL -> ");
    while(tail != NULL){
        printf("%d <- ",tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}
void reverse(struct NODE** head, struct NODE ** tail)
{
    struct NODE* temp = *head;
    struct NODE* nextNode = NULL; 
    while(temp != NULL){
        nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode;
        temp = temp->prev;
    }
    temp = *head;
    *head = *tail;
    *tail = temp;
}
int main()
{
    struct NODE* head = NULL;
    struct NODE* tail = NULL;
    pushfront(&head,3,&tail);
    pushfront(&head,5,&tail);
    pushfront(&head,7,&tail);
    printf("Danh sach ban dau: \n");
    printlist1(head);
    printlist2(tail);
    printf("Danh sach dao nguoc: \n");
    reverse(&head,&tail);
    printlist1(head);
    printlist2(tail);
}