#include <iostream>
#include <queue>
using namespace std;
typedef struct TREENODE
{
    char label;
    struct TREENODE* leftChild;
    struct TREENODE* rightChild;
}Treenode;
// tao mot nut moi
Treenode* createNewNode(char label)
{
    Treenode* newNode = new Treenode;
    newNode->label = label;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
// tim nut co nhan label
Treenode* findNode(Treenode* root, char label)
{
    queue<Treenode*> Q;
    Q.push(root);
    while (Q.size() > 0)
    {
        Treenode* temp = Q.front();
        Q.pop();
        if(temp->label == label){
            return temp;
        }
        if(temp->leftChild != NULL){
            Q.push(temp->leftChild);
        }
        if(temp->rightChild != NULL){
            Q.push(temp->rightChild);
        }
    }
    cout << "Khong tim thay nut!";
    return NULL;
}
// tim nut co nhan label (de quy)
Treenode* findNode_v2(Treenode* root, char label)
{
    if(root == NULL){
        return NULL;
    }
    if(root->label == label){
        return root;
    }
    Treenode* temp = findNode_v2(root->leftChild, label);
    if(temp != NULL){
        return temp;
    }
    temp = findNode_v2(root->rightChild, label);
    if(findNode_v2(temp, label) != NULL){
        return temp;
    }
    return NULL;
}
// them 1 nut nhan label vao nut p(0 la trai, 1 la phai)
void insertNode(Treenode* p, char label, int isRight)
{
    Treenode* newNode = createNewNode(label);
    if(isRight){
        p->rightChild = newNode;
    } else {
        p->leftChild = newNode;
    }
}
// tao 1 cay
void makeTree(Treenode* root)
{
    insertNode(root, 'B', 0);
    insertNode(root, 'C', 1);
    insertNode(findNode(root, 'B'), 'D', 0);
    insertNode(findNode(root, 'B'), 'E', 1);
    insertNode(findNode(root, 'C'), 'F', 0);
    insertNode(findNode(root, 'C'), 'G', 1);
    insertNode(findNode(root, 'E'), 'H', 0);
    insertNode(findNode(root, 'E'), 'I', 1);
    insertNode(findNode(root, 'F'), 'J', 0);
    insertNode(findNode(root, 'F'), 'K', 1);
    insertNode(findNode(root, 'G'), 'L', 1);
    insertNode(findNode(root, 'H'), 'M', 0);
    insertNode(findNode(root, 'H'), 'N', 1);
    insertNode(findNode(root, 'I'), 'O', 0);
    insertNode(findNode(root, 'I'), 'P', 1);
    insertNode(findNode(root, 'K'), 'Q', 0);
    insertNode(findNode(root, 'K'), 'R', 1);
    insertNode(findNode(root, 'O'), 'S', 0);
    insertNode(findNode(root, 'O'), 'T', 1);
    insertNode(findNode(root, 'Q'), 'U', 0);
    insertNode(findNode(root, 'Q'), 'V', 1);
    insertNode(findNode(root, 'T'), 'W', 0);
    insertNode(findNode(root, 'T'), 'X', 1);
    insertNode(findNode(root, 'X'), 'Y', 0);
    insertNode(findNode(root, 'Y'), 'Z', 1);
}
// duyet theo muc
void levelTravesal(Treenode* root)
{
    queue<Treenode*> Q;
    Q.push(root);
    while(Q.size() > 0){
        Treenode* temp = Q.front();
        Q.pop();
        cout << temp->label << " ";
        if(temp->leftChild != NULL){
            Q.push(temp->leftChild);
        }
        if(temp->rightChild != NULL){
            Q.push(temp->rightChild);
        }
    }
    cout << endl;
}
// duyet theo thu tu truoc
void preOrderTravesal(Treenode* root)
{
    if(root == NULL){
        return;
    }
    cout << root->label << " ";
    preOrderTravesal(root->leftChild);
    preOrderTravesal(root->rightChild);
}
// duyet theo thu tu giua
void inOrderTravesal(Treenode* root)
{
        if(root == NULL){
        return;
    }
    inOrderTravesal(root->leftChild);
    cout << root->label << " ";
    inOrderTravesal(root->rightChild);
}
// duyet theo thu tu sau
void postOrderTravesal(Treenode* root)
{
        if(root == NULL){
        return;
    }
    postOrderTravesal(root->leftChild);
    postOrderTravesal(root->rightChild);
    cout << root->label << " ";
}
// dem so nut
int countNode(Treenode* root)
{
    if(root == NULL) return 0;
    return 1 + countNode(root->leftChild) + countNode(root->rightChild);
}
// dem so la
int countLeaf(Treenode* root)
{
    if(root == NULL) return 0;
    if(root->leftChild == NULL && root->rightChild == NULL){
        return 1;
    }
    return countLeaf(root->leftChild) + countLeaf(root->rightChild);
}
// chieu cao cua nut p
int height(Treenode* root)
{
    if(root == NULL) return -1;
    return 1 + ((height(root->leftChild) > height(root->rightChild)) ? height(root->leftChild) : height(root->rightChild));
}
// do sau cua nut p
int deept(Treenode* root, Treenode* p)
{
    if(root == NULL){
        return -1;
    }
    if(root == p){
        return 0;
    }
    int deep = 0;
    deep = deept(root->leftChild, p);
    if(deep >= 0){
        return deep + 1;
    }
    deep = deept(root->rightChild, p);
    if(deep >= 0){
        return deep + 1;
    }
    return -1;
}








int main(){
    Treenode* root = createNewNode('A');
    char c;
    makeTree(root);
    cout << "Duyet theo levelTravesal: ";
    levelTravesal(root);
    cout << "Duyet theo preOrderTravesal: ";
    preOrderTravesal(root);
    cout << endl;
    cout << "Duyet theo inOrderTravesal: ";
    inOrderTravesal(root);
    cout << endl;
    cout << "Duyet theo postOrderTravesal: ";
    postOrderTravesal(root);
    cout << endl;
    //-----------------------------------------------------------------------//
    cout << "So nut la: " << countNode(root) << endl;
    cout << "So la la: " << countLeaf(root) << endl;
    cout << "Chieu cao cay la: " << height(root) << endl;
    //-----------------------------------------------------------------------//
    cout << "Ban muon tim chieu cao cua nut nao: ";
    cin >> c;
    cout << "Chieu cao cua nut " << c << " la: " << height(findNode(root, c)) << endl;
    cout << "Chieu cao cua nut " << c << " la: " << height(findNode_v2(root, c)) << endl;
    //-----------------------------------------------------------------------//
    cout << "Ban muon tim so sau cua nut nao: ";
    cin >> c;
    cout << "Do sau cua nut " << c << " la: " << deept(root, findNode(root, c)) << endl;

    return 0;
}