#include <iostream>
using namespace std;
typedef struct TREENODE
{
    float data;
    int frequency;
    struct TREENODE* leftChild;
    struct TREENODE* rightChild;
}Treenode;
Treenode* createNewNode(float data) // tạo nút mới
{
    Treenode* newNode = new Treenode;
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
void insertTreeNode(Treenode* root ,float data) // thêm 1 nút vào cây
{
Treenode* newNode = createNewNode(data);
Treenode* temp = root;
while(1){
    if(temp->data == newNode->data){
        temp->frequency++;
        return;
    }
    if(temp->data > newNode->data){
        if(temp->leftChild == NULL){
            temp->leftChild = newNode;
            return;
        }
        temp = temp->leftChild;
    } else {
        if(temp->rightChild == NULL){
            temp->rightChild = newNode;
            return;
        }
        temp = temp->rightChild;
    }
}
}
void inOrderTravesal(Treenode* root) // duyệt theo thứ tự giữa
{
    if(root == NULL){
        return;
    } 
    inOrderTravesal(root->leftChild);
    cout << root->data << " ";
    inOrderTravesal(root->rightChild);
}
void makeBST(Treenode* root) // tạo cây
{
    insertTreeNode(root, 8);
    insertTreeNode(root, 10);
    insertTreeNode(root, 9);
    insertTreeNode(root, 11);
    insertTreeNode(root, 4);
    insertTreeNode(root, 6);
    insertTreeNode(root, 5);
    insertTreeNode(root, 2);
    insertTreeNode(root, 1);
    insertTreeNode(root, 3);
}
Treenode* findNode(Treenode* root, float data) // tìm nút có nhãn data ko đệ quy
{
    Treenode* temp = root;
    while(temp != NULL){
        if(temp->data == data){
            return temp;
        } else if(temp->data < data){
            temp = temp->rightChild;
        } else {
            temp = temp->leftChild;
        }
    }
    cout << "Khong tim thay " << data;
    return NULL;
}
Treenode* findNode2(Treenode* root, float data) // tìm nút có nhãn data có đệ quy
{
    if(root == NULL || root->data == data){
        return root;
    }
    Treenode* temp = findNode2(root->leftChild, data);
    if(temp != NULL){
        return temp;
    }
    return findNode2(root->rightChild, data);
}
Treenode* findDad(Treenode* root, float data) // tìm nút cha của nút p khác root
{
    Treenode* temp = root;
    while(temp != NULL){
        if((temp->leftChild != NULL && temp->leftChild->data == data) || 
           (temp->rightChild != NULL && temp->rightChild->data == data)){
            return temp;
        }
        if(temp->data > data){
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    return NULL;
}
int height(Treenode* root) // chiều cao của nút p
{
    if(root == NULL) return -1;
    return 1 + ((height(root->leftChild) > height(root->rightChild)) 
            ? height(root->leftChild) : height(root->rightChild));
}
int depth(Treenode* root, float data) // tính độ sâu của nút không đệ quy
{
    if(root == NULL){
        return -1;
    }
    int deep = 0;
    Treenode* temp = root;
    while(temp != NULL){
        if(temp->data == data){
            return deep;
        } else if(temp->data < data){
            temp = temp->rightChild;
        } else {
            temp = temp->leftChild;
        }
        deep++;
    }
    cout << "Khong co nut " << data << endl;
    return -1;
}
int depth2(Treenode* root, float data) // tính độ sâu của nút có đệ quy
{
    if(root == NULL){
        return -1;
    }
    if(root->data == data){
        return 0;
    }
    int left = depth2(root->leftChild, data);
    if(left >= 0){
        return 1 + left;
    }
    int right = depth2(root->rightChild, data);
    if(right >= 0){
        return 1 + right;
    }
    return -1;
}
int maxLeaf(Treenode* root) // tính Lá lớn nhất với cây khác rỗng
{
    Treenode* temp = root;
    while(temp->rightChild != NULL){
        temp = temp->rightChild;
    }
    cout << endl << "La lon nhat la: ";
    return temp->data;
}
bool checkAncestor(Treenode* root, Treenode* child) // kiểm tra root có là tổ tiên của child ko
{
    if(root == NULL){
        return false;
    }
    if(root == child){
        return true;
    }
    return checkAncestor(root->leftChild, child) || checkAncestor(root->rightChild, child); 
}
bool isLeaf(Treenode* p) // check có phải lá không
{
    if(p->leftChild == NULL && p->rightChild == NULL){
        return true;
    }
    return false;
}
bool isMissingChild(Treenode* p) // check có phải nút 1 con không
{
    if(p->leftChild == NULL || p->rightChild == NULL){
        return true;
    }
    return false;
}
Treenode* commonAncestor(Treenode* root, Treenode* child1, Treenode* child2) // tổ tiên chung
{
    if(checkAncestor(child1, child2) || checkAncestor(child2, child1))
    {
        Treenode* temp;
        if(checkAncestor(child1, child2)){
            temp = child1;
        } else {
            temp = child2;
        }
        Treenode* tmp = root;
        if(tmp->data == temp->data){
            cout << "Khong co to tin chung vi co mot nut la root";
            return NULL;
        }
        while(tmp->data > temp->data){
            if(tmp->leftChild->data == temp->data){
                return tmp;
            }
            tmp = tmp->leftChild;
        }
        while(tmp->data < temp->data){
            if(tmp->rightChild->data == temp->data){
                return tmp;
            }
            tmp = tmp->rightChild;
        }
    } else {
        Treenode* temp = root;
        int max = (child1->data > child2->data) ? child1->data : child2->data;
        int min = (child1->data < child2->data) ? child1->data : child2->data;
        while(temp->data < min || temp->data > max){
            if(temp->data < min){
                temp = temp->rightChild;
            }
            if(temp->data > max){
                temp = temp->leftChild;
            }
        }
        return temp;
    }
}
void removeNode1(Treenode* root, Treenode* p) // xóa nút lá hoặc con khuyết
{
    if(isLeaf(p)){
        if(findDad(root, p->data)->leftChild == p){
            findDad(root, p->data)->leftChild = NULL;
        } else {
            findDad(root, p->data)->rightChild = NULL;
        }
        delete p;
    } else {
        Treenode* tempDad = findDad(root, p->data);
        if(findDad(root, p->data)->leftChild == p){
            if(p->leftChild != NULL){
                tempDad->leftChild = p->leftChild;
            } else {
                tempDad->leftChild = p->rightChild;
            }
        } else {
            if(p->leftChild != NULL){
                tempDad->rightChild = p->leftChild;
            } else {
                tempDad->rightChild = p->rightChild;
            }
        }
        delete p;
    }
}
void removeNode(Treenode* root, Treenode* p) // xóa nút
{
    if(isLeaf(p) || isMissingChild(p)){
        removeNode1(root, p);
    } else {
        Treenode* temp = p->leftChild;
        while(temp->rightChild != NULL){
            temp = temp->rightChild;
        }
        float tmp = temp->data;
        removeNode1(p, temp);
        p->data = tmp;
    }
}

int main(){
    float name;
    Treenode* root = createNewNode(7);
    makeBST(root);
    inOrderTravesal(root);
    cout << endl;
    cout << "Nhap nut muon xoa: ";
    cin >> name; 
    removeNode(root, findNode(root, name));
    inOrderTravesal(root);
}

                                                                                                          