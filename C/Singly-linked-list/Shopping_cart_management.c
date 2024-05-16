#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc dữ liệu cho sản phẩm
typedef struct Item {
    char ID[12];
    int quantity;
    char insertDate[21];
    double price;
    struct Item* next;
} Item;

// Hàm để thêm một sản phẩm vào giỏ hàng
void addItem(Item** head, char ID[], int quantity, char insertDate[], double price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->ID, ID);
    newItem->quantity = quantity;
    strcpy(newItem->insertDate, insertDate);
    newItem->price = price;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    }
    else {
        Item* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

// Hàm để đọc thông tin các sản phẩm input
void readItemList(Item** head) {
    char ID[12];
    int quantity;
    char insertDate[21];
    char nextLine[100];
    double price;
    int count = 0;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);
        if (strlen(ID) == 0) continue;
        if (strcmp(ID, "-1") == 0) {
            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%lf", &price);

        count++;
        addItem(head, ID, quantity, insertDate, price);
    }
    printf("Total: %d\n", count);
}

// Hàm tính tổng tiền sản phẩm trong giỏ hàng
double checkCartTotalPrice(Item* head) {
  double sumOfMoney = 0;
  while(head != NULL){
    sumOfMoney += head->quantity * head->price;
    head = head->next;
  }
  return sumOfMoney;
}
 
// Hàm để tìm kiếm sản phẩm theo mã ID
Item* findanItemByID(Item* head, char ID[]) {
    Item* ItemByID = head;
    while (ItemByID != NULL) {
        if (strcmp(ItemByID->ID, ID) == 0) {
            return ItemByID;
        }
        ItemByID = ItemByID->next;
    }
    return NULL; 
}
 
 
// Hàm giảm số lượng 1 mã sản phẩm
// hàm trả về 1 nếu điều chỉnh thành công và 0 nếu không thành công // (ID không tìm thấy)
int reduceItemQuantityByID(Item** head, char ID[], int reduceQuantity) {
  Item* ItemByID = findanItemByID(*head, ID);
  if(ItemByID == NULL){
    return 0;
  }
  int sub = ItemByID->quantity - reduceQuantity;
  if(sub > 0){
    ItemByID->quantity = sub;
  } else {
    if(ItemByID == *head){
        *head = ItemByID->next;
    } else {
        Item* temp = *head;
        while(temp->next != ItemByID){
            temp = temp->next;
        }
        temp->next = ItemByID->next;
    }
    free(ItemByID);
  }
  return 1;
}
 

// Hàm để thêm một sản phẩm vào giỏ hàng
void addNewItem(Item** head, char ID[], int quantity, char insertDate[],  double price) {
    Item* ItemByID = findanItemByID(*head, ID);
    if(ItemByID != NULL){
        ItemByID->quantity += quantity;
    } else {
        addItem(head, ID, quantity, insertDate, price);
    }
 }

void findItemsByID(Item* head)
{
    char ID[11], nextLine[100];;
    Item* anItem = NULL;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);

        if (strcmp(ID, "-1") == 0) {
            break;
        }
        anItem = findanItemByID(head, ID);
        if (anItem == NULL) printf("Item NOT FOUND\n");
        else printf("Item's already added at %s\n", anItem->insertDate);
    }
}

void reduceItemQuantityByIDs(Item** head)
{
    char ID[12], nextLine[100];
    int reduceQuantity;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s %d", ID, &reduceQuantity);
        if (strcmp(ID, "-1") == 0) {
            break;
        }
        if (reduceItemQuantityByID(head, ID, reduceQuantity))
            printf("DONE Remove\n");
        else
            printf("ID NOT FOUND\n");
    }
}

// Hàm để đọc thông tin các sản phẩm input
void addNewItems(Item** head) {
    char ID[12];
    int quantity;
    char insertDate[21];
    char nextLine[100];
    double price;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);
        if (strlen(ID) == 0) continue;
        if (strcmp(ID, "-1") == 0) {
            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%lf", &price);

        addNewItem(head, ID, quantity, insertDate, price);
    }
}
// Hàm để test các hàm đã định nghĩa ở trên

int main() {
    Item* cartList = NULL;
    char nextCommand[100];
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?') break;
        if (strcmp(&nextCommand[2], "readCart") == 0)
            readItemList(&cartList);
        else if (strcmp(&nextCommand[2], "findItemsByID") == 0)
            findItemsByID(cartList);
        else if (strcmp(&nextCommand[2], "reduceItemQuantityByIDs") == 0)
            reduceItemQuantityByIDs(&cartList);
        else if (strcmp(&nextCommand[2], "addNewItems") == 0)
            addNewItems(&cartList);
        else if (strcmp(&nextCommand[2], "checkCartTotalPrice") == 0)
            printf("Total price: %.2lf\n", checkCartTotalPrice(cartList));
    }
    return 0;
}
/* 
? readCart
1000234001
1
2023-07-11 12:05:12
35.5
1000235002
1
2023-07-11 12:05:12
100
1000234002
5
2023-07-11 12:05:12
5.5
1001254021
3
2023-07-11 12:05:12
5.5
-1
? checkCartTotalPrice
? findItemsByID
1000234001
1000234005
-1
? reduceItemQuantityByIDs
1000235002 1
1000234002 1
-1
? findItemsByID
1000235002
-1
? checkCartTotalPrice
? addNewItems
1000234001
1
2023-07-11 12:05:12
35.5
1000235002
2
2023-07-11 12:05:12
100
1007235072
20
2023-07-11 12:05:12
3.5
-1
? checkCartTotalPrice
? findItemsByID
1000235002
-1
-1
*/
/* 
Correct output
Total: 4
Total price: 179.50
Item's already added at 2023-07-11 12:05:12
Item NOT FOUND
DONE Remove
DONE Remove
Item NOT FOUND
Total price: 74.00
Total price: 379.50
Item's already added at 2023-07-11 12:05:12
 */