#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NODE
{
    int data;
    struct NODE* next;
};
struct NODE* createNewNode(int data)
{
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void pushfront(struct NODE** head,int data)
{
    struct NODE* temp = *head;
    *head = createNewNode(data);
    (*head)->next = temp;
}
void printList(struct NODE* head)
{
    printf("Danh sach la: ");
    if( head == NULL){
        printf("NULL");
        return;
    }
    while (head != NULL ){
        printf("%d ",head->data);
        head = head->next;
    }
}
void insertAfter(struct NODE* head,int data, int index, int insert)
{
    struct NODE* tmp = head;
    int inD;
    while(tmp != NULL && inD != index){
        tmp = tmp->next;
        inD++;
    }
    if(tmp == NULL || tmp->data != data){
        printf("Nhap sai vi tri\n");
        return;
    }
    struct NODE* newNode = createNewNode(insert);
    newNode->next = tmp->next;
    tmp->next = newNode;
}
bool foundKey(struct NODE* head, int key)
{
    int count = 0;
    struct NODE* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            count++;
        }
        temp = temp->next;
    }

    if(count != 0){
        printf("Co %d key %d tai cac vi tri: ", count, key);
        int index = 0;
        temp = head;
        while(temp != NULL){
            if(temp->data == key){
                printf("%d ",index);
            }
            temp = temp->next;
            index++;
        }
    } else {
        return false;
    }
    return true;
}
void deleteKey(struct NODE** head, int data, int index)
{
    struct NODE* tmp = *head,*prev;
    if(index == 0){
        *head = (*head)->next;
        free(tmp);
        return;
    }
    int inD;
    while(tmp != NULL && inD != index){
        prev = tmp;
        tmp = tmp->next;
        inD++;
    }
    if(tmp == NULL || tmp->data != data){
        printf("Nhap sai vi tri\n");
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}
void changeKey(struct NODE* head, int data, int index, int change)
{
    struct NODE* tmp = head;
    int inD;
    while(tmp != NULL && inD != index){
        tmp = tmp->next;
        inD++;
    }
    if(tmp == NULL || tmp->data != data){
        printf("Nhap sai vi tri\n");
        return;
    }
    tmp->data = change;
}
int main()
{
    struct NODE* head = NULL;
    int n, data, index, newData;
    printf("Nhap so phan tu: ");scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        pushfront(&head, data);
    }
    printList(head);        
    //Tìm kiếm phần tử key
    printf("\nNhap gia tri muon tim: ");
    scanf("%d", &data);
    if(!foundKey(head, data)){
        printf("Khong tim thay %d\n", data);
    }
    //Thêm 1 phân tử vào vị trí bất kì
    printf("\nDu lieu ban muon them la: ");   scanf("%d",&newData);
    if(n != 0){
        printf("Ban muon them o dau?(1:Y, 0:N): ");
        scanf("%d",&index);
        if(index){
            pushfront(&head, data);
        } else {
            printf("\nBan muon chen vao sau nut co gia tri nao: ");  
            scanf("%d",&data);
            if(!foundKey(head, data)){
                printf("Khong tim thay %d", data);
            } else {
                printf("\nBan muon them sau vi tri nao: ");
                scanf("%d", &index);
                insertAfter(head, data, index, newData);
            }
        }
    } else {
        pushfront(&head, data);
    }
    printList(head);
    // Xóa phân tử có giá trị key
    if(head != NULL){
        printf("\nNhap gia tri muon xoa: ");
        scanf("%d", &data);
        if(!foundKey(head, data)){
            printf("Khong tim thay %d\n", data);
        } else {
            printf("\nBan muon xoa vi tri nao: ");
            scanf("%d", &index);
            deleteKey(&head, data, index);
        }
        printList(head);
    }
    // Sửa giá trị 1 key
    if(head != NULL){
        printf("\nNhap gia tri muon sua: ");
        scanf("%d", &data);
        if(!foundKey(head, data)){
            printf("Khong tim thay %d\n", data);
        } else {
            printf("\nBan muon sua vi tri nao: ");
            scanf("%d", &index);
            printf("Ban muon sua thanh gi: ");
            scanf("%d", &newData);
            changeKey(head, data, index, newData);
        }
        printList(head);
    }
}

