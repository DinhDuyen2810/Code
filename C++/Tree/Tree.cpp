#include <iostream>
#include <queue>
using namespace std;
typedef struct TREENODE
{   
    char label;
    struct TREENODE* firstChild;
    struct TREENODE* nextSibling;
} TreeNode;
// tao nut moi
TreeNode* makeNode(char label)
{
    TreeNode* newNode = new TreeNode;
    newNode->label = label;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
// chen newNode vao nut con moi nhat (phai nhat) cua nut root
TreeNode* insertNode(TreeNode* root, TreeNode* newNode)
{
    if(root == NULL){
        root = newNode;
    } else if(root->firstChild == NULL){
        root->firstChild = newNode;
    } else {
        TreeNode* rightmost = root->firstChild;
        while(rightmost->nextSibling != NULL){
            rightmost = rightmost->nextSibling;
        }
        rightmost->nextSibling = newNode;
    }
    return root;
}
// chen newNode vao nut con moi nhat (phai nhat) cua nut root, ham khong can return
void insertNode2(TreeNode** root, TreeNode* newNode)
{
    if(*root == NULL){
        *root = newNode;
    } else if((*root)->firstChild == NULL){
        (*root)->firstChild = newNode;
    } else {
        TreeNode* rightmost = (*root)->firstChild;
        while(rightmost->nextSibling != NULL){
            rightmost = rightmost->nextSibling;
        }
        rightmost->nextSibling = newNode;
    }
}
// tao va chen nut moi thanh cay con phai nhat cua nut root Chu y: root phai khac NULL
void insertNode_v2(TreeNode* root, char label)
{
    if(root == NULL){
        return;
    }
    TreeNode* newNode = makeNode(label);
    if(root->firstChild == NULL){
        root->firstChild = newNode;
    } else {
        TreeNode* rightNode = root->firstChild;
        while(rightNode->nextSibling != NULL){
            rightNode = rightNode->nextSibling;
        }
        rightNode->nextSibling = newNode;
    }
}
// tim nut p co label = c tren cay
TreeNode* son(TreeNode* root, char label)
{
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* son = Q.front();
    while (Q.size() > 0)
    {
        son = Q.front();
        Q.pop();
        if(son->label == label){
            return son;
        }
        TreeNode* temp = son->firstChild;
        while(temp != NULL){
            Q.push(temp);
            temp = temp->nextSibling;
        }
    }
    cout << "Khong tim thay nut cay co label : " << label << endl;
    return NULL;
}
// tao 1 cay mau
void makeTree(TreeNode* root)
{
    insertNode_v2(root, 'B');
    insertNode_v2(root, 'C');
    insertNode_v2(root, 'D');
    insertNode_v2(son(root, 'B'), 'E');
    insertNode_v2(son(root, 'B'), 'F');
    insertNode_v2(son(root, 'B'), 'G');
    insertNode_v2(son(root, 'C'), 'H');
    insertNode_v2(son(root, 'C'), 'I');
    insertNode_v2(son(root, 'D'), 'J');
    insertNode_v2(son(root, 'D'), 'K');
    insertNode_v2(son(root, 'F'), 'L');
    insertNode_v2(son(root, 'F'), 'M');
    insertNode_v2(son(root, 'F'), 'N');
    insertNode_v2(son(root, 'G'), 'O');
    insertNode_v2(son(root, 'H'), 'P');
    insertNode_v2(son(root, 'H'), 'Q');
    insertNode_v2(son(root, 'K'), 'R');
    insertNode_v2(son(root, 'K'), 'S');
    insertNode_v2(son(root, 'M'), 'T');
    insertNode_v2(son(root, 'M'), 'U');
    insertNode_v2(son(root, 'M'), 'V');
    insertNode_v2(son(root, 'M'), 'W');
    insertNode_v2(son(root, 'P'), 'X');
    insertNode_v2(son(root, 'Q'), 'Y');
    insertNode_v2(son(root, 'S'), 'Z');
}
// duyet cay theo muc(Queue)
void levelTraversal(TreeNode* root)
{
    if(root == NULL){
        cout << "Cay rong!";
        return;
    }
    queue<TreeNode*> Q;
    Q.push(root);
    while (Q.size() > 0)
    {
        TreeNode* temp = Q.front();
        Q.pop();
        cout << temp->label << " ";
        TreeNode* tmp = temp->firstChild;
        while(tmp != NULL){
            Q.push(tmp);
            tmp = tmp->nextSibling;
        }
    }
    cout << endl;
}
// duyet cay theo thu tu truoc
void preOrderTravesal(TreeNode* root)
{
    if(root == NULL){
        return ;
    }
    cout << root->label << " ";
    TreeNode* temp = root->firstChild;
    while(temp != NULL){
        preOrderTravesal(temp);
        temp = temp->nextSibling;
    }
}
// duyet cay theo thu tu sau
void postOrderTravesal(TreeNode* root)
{
    if(root == NULL){
        return;
    }
    TreeNode* temp = root->firstChild;
    while(temp != NULL){
        postOrderTravesal(temp);
        temp = temp->nextSibling;
    }
    cout << root->label << " ";
}
// duyet cay theo thu tu giua
void inOrderTravesal(TreeNode* root)
{
    TreeNode* temp = root;
    if(temp->firstChild == NULL){
        cout << root->label << " ";
    } else {
        TreeNode* tmp = root->firstChild;
        inOrderTravesal(tmp);
        cout << root->label << " ";
        TreeNode* tp = tmp->nextSibling;
        while(tp != NULL){
            inOrderTravesal(tp);
            tp = tp->nextSibling;
        }
    }
}
// dem so luong nut tren cay
int countNodes(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    TreeNode* temp = root->firstChild;
    while(temp != NULL){
        sum += countNodes(temp);
        temp = temp->nextSibling;
    }
    return sum + 1;
}
// dem so luong la tren cay
int countLeafs(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    TreeNode* temp = root->firstChild;
    if(temp == NULL){
        sum = 1;
    }
    while(temp != NULL){
        sum += countLeafs(temp);
        temp = temp->nextSibling;
    }
    return sum;
}
// tim nut cha cua nut p tren cay co goc la root
TreeNode* parent(TreeNode* root, TreeNode* p)
{
    if(root == NULL){
        return NULL;
    }    
    TreeNode* temp = root->firstChild;
    while(temp != NULL){
        if(temp == p){
            return root;
        }
        TreeNode* papa = parent(temp, p);
        if(papa != NULL) return papa;
        temp = temp->nextSibling;
    }
    return NULL;
}
// tinh chieu cao cua cay hoac nut bat ki
int heigh(TreeNode* root)
{
    if(root == NULL){
        return -1;
    }
    int maxh = 0;
    TreeNode* temp = root->firstChild;
    if(temp == NULL){
        return 0;
    }
    while(temp != NULL){
        int h = heigh(temp);
        if(h > maxh){
            maxh = h;
        }
        temp = temp->nextSibling;
    }
    return maxh + 1;
}
// Tim do sau nut co nhan label tren cay biet do sau cua root la d
int depth(TreeNode* root, char label, int d) 
{
    if(root == NULL){
        return -1;
    }
    if(root->label == label){
        return d;
    }
    TreeNode* temp = root->firstChild;
    while(temp != NULL){
        if (temp->label == label) return d + 1;
        int deep = depth(temp, label, d + 1);
        if(deep > 0){
            return deep;
        }
        temp = temp->nextSibling;
    }
    return -1;
}
// Tim do sau nut p tren cay biet do sau cua root la d
int depth_v2(TreeNode* root, TreeNode* p, int d)
{
    if(root == NULL){
        return -1;
    }
    if(root == p){
        return d;
    }
    TreeNode* temp = root->firstChild;
    while (temp != NULL){
        if(temp == p){
            return d + 1;
        }
        int deep = depth_v2(temp, p, d + 1);
        if(deep > 0){
            return deep;
        }
        temp = temp->nextSibling;
    }
    return -1;
}
// tinh do sau cua nut co nhan label, không de quy
int depth_v3(TreeNode* root, char label)
{
    if(root == NULL){
        return -1;
    }
    queue<TreeNode*> Q;
    queue<int> Que;
    Q.push(root);
    Que.push(0);
    while(Q.size() > 0){
        TreeNode* deep = Q.front();
        Q.pop();
        int dep = Que.front();
        Que.pop();
        if(deep->label == label){
            return dep;
        }
        TreeNode* temp = deep->firstChild;
        while(temp != NULL){
            Q.push(temp);
            Que.push(dep + 1);
            temp = temp->nextSibling;
        }
    }
    return -1;
}
//in danh sach nut con cua nut co nhan label(simple)
void children(TreeNode* p)
{
    TreeNode* temp = p->firstChild;
    if(temp == NULL){
        cout << "NULL" << endl;
        return;
    }
    while(temp != NULL){
        cout << temp->label << " ";
        temp = temp->nextSibling;
    }
    cout << endl;
} 
//in danh sach nut con cua nut co nhan label (check duoc co hay khong)
void children_v2(TreeNode* root, char label)
{
    if(root == NULL){
        cout << "Cay rong";
        return;
    }
    queue<TreeNode*> Q;
    Q.push(root);
    while(Q.size() > 0){
        TreeNode* temp = Q.front();
        Q.pop();
        if(temp->label == label){
            TreeNode* chd = temp->firstChild;
            if(chd == NULL){
                cout << "NULL" << endl;
                return;
            }
            while(chd != NULL){
                cout << chd->label << " ";
                chd = chd->nextSibling;
            }
            return;
        }
        temp = temp->firstChild;
        
        while(temp != NULL){
            Q.push(temp);
            temp = temp->nextSibling;
        }
    }
    cout << "Khong thay nut co nhan " << label;
    return;
}

int main()
{
    TreeNode* root = makeNode('A');
    makeTree(root);
    char c;
    cout << "Duyet theo mien(queue) la: ";
    levelTraversal(root);
    cout << "Duyet theo preOrder la: ";
    preOrderTravesal(root);     cout << endl;
    cout << "Duyet theo postOrder la: ";
    postOrderTravesal(root);    cout << endl;
    cout << "Duyet theo inOrder la: ";
    inOrderTravesal(root);      cout << endl;
    //-------------------------------------------------------------//
    cout << "Co tat ca " << countNodes(root) << " nut" << endl;
    cout << "Co tat ca " << countLeafs(root) << " la" << endl;
    cout << "Chieu cao cua cay la: " << heigh(root) << endl;
    //-------------------------------------------------------------//
    cout << "Nhap con muon tim cha: ";
    cin >> c;
    if(son(root, c) != NULL){
        cout << "Cha cua " << c << " la " << parent(root, son(root, c))->label << endl;
    }
    //-------------------------------------------------------------//
    cout << "Ban muon tim do sau cau nut nao : ";
    cin >> c;
    cout << "Do sau cua nut " << c << " la : " << depth(root, c, 0) << endl;
    cout << "Do sau cua nut " << c << " la : " << depth_v2(root, son(root, c), 0) << endl; 
    cout << "Do sau cua nut " << c << " la : " << depth_v3(root, c) << endl; 
    //-------------------------------------------------------------// 
    cout << "Ban muon tim do cao cua nut nao: ";
    cin >> c;
    cout << "Do cao cua nut " << c << " la : " << heigh(son(root,c)) << endl;
    //-------------------------------------------------------------// 
    cout << "Ban muon in danh sach nut con cua nut nao: ";
    cin >> c;
    cout << "Danh sach nut con cua nut " << c << " la : ";
    children(son(root, c));
    cout << "Danh sach nut con cua nut " << c << " la : ";
    children_v2(root, c);
    //-------------------------------------------------------------//
    return 0;
}