#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// định nghĩa 1 nút trong danh sách liên kết biểu diễn đa thức bậc n 
struct Node
{
	double heSo;
	int soMu;
	struct Node* next;
};

//hàm cấp phát động một nút mới của danh sách và gán giá trị khởi tạo cho nút
struct Node* createNewNode(double heSo, int soMu)
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->heSo = heSo;
	p->soMu = soMu;
	p->next = NULL;
	return p;
}

//Hàm nhập vào một đa thức bậc n với số mũ giảm dần
struct Node* readData()
{
	struct Node* head = NULL, * p, * last=NULL;
	double heSo;
	int soMu, nElement;
    printf("Nhap so ptu: ");
	// doc vao so luong phan tu cua da thuc
	scanf("%d", &nElement);

	// doc vao tung phan tu
	for(int i=0;i< nElement; i++){
		scanf("%lf", &heSo);
		scanf("%d", &soMu);
		if (head == NULL) { // nếu đang rỗng thì thêm vào đầu
			head = createNewNode(heSo, soMu);
			last = head;
		}
		else { // ngược lại thêm vào cuối
			p = createNewNode(heSo, soMu);
			last->next = p;
			last = p;
		}
	}
	return head;
}

//In đa thức bậc n hiện có
void printData(struct Node* head)
{
	int n = 0;
	while (head != NULL) {
		if (n > 0 && head->heSo > 0) {
			printf(" +");
		}

		if (head->soMu > 1) {
			if(head->heSo!=1){
				printf(" %.2lf * x^%d", head->heSo, head->soMu);
			}
			else{
				printf("x^%d", head->soMu);
			}
		}
		else if (head->soMu == 1) {
			if (head->heSo != 1){
				printf(" %.2lf * x", head->heSo);
			}
			else {
				printf("x");
			}
		}
		else {
			printf(" %.2lf", head->heSo);
		}
		head = head->next;
		n++;
	}
	printf("\n");
}

//Hàm giải phóng bộ nhớ của đa thức
void freePolynomial(struct Node** head)
{
	struct Node* curNode = NULL;
	while (*head != NULL)
	{
		curNode = *head;
		*head = (*head)->next;
		free(curNode);
	}
}

//Hàm tính và trả về giá trị của biểu thức ứng với giá trị của x
double calculatePolynomialValue(struct Node* head, double x)
{
	double result = 0;
	while(head != NULL){
		result += head->heSo * pow(x, (double)head->soMu);
		head = head->next;
	}
	return result;
}

struct Node* addPolynomial(struct Node* first, struct Node* second)
{
	struct Node* addPolynomial;
	struct Node* temp;
	struct Node* last;
	int isFirst = 1;
	while(first != NULL && second != NULL){
		if(first->soMu > second->soMu){
			temp = createNewNode(first->heSo, first->soMu);
			first = first->next;
		} else if(first->soMu < second->soMu){
			temp = createNewNode(second->heSo, second->soMu);
			second = second->next;
		} else {
			if(first->heSo + second->heSo != 0){
				temp = createNewNode(first->heSo + second->heSo, first->soMu);
			}
			first = first->next;
			second = second->next;
		}
		if(isFirst){
			addPolynomial = temp;
			last = temp;
            isFirst = 0;
		} else {
			last->next = temp;
			last = temp;
		}
	}
	if(first == NULL){
		while(second != NULL){
			temp = createNewNode(second->heSo, second->soMu);
			if(isFirst){
				addPolynomial = temp;
				last = temp;
				isFirst = 0;
			} else {
				last->next = temp;
				last = temp;
			}
			second = second->next;
		}
	} else if(second == NULL){
		while(first != NULL){
			temp = createNewNode(first->heSo, first->soMu);
			if(isFirst){
				addPolynomial = temp;
				last = temp;
				isFirst = 0;
			} else {
				last->next = temp;
				last = temp;
			}
			first = first->next;
		}
	}
	return addPolynomial;
}

struct Node* subtractPolynomial(struct Node* first, struct Node* second)
{
	struct Node* subtractPolynomial;
	struct Node* temp;
	struct Node* last;
	int isFirst = 1;
	while(first != NULL && second != NULL){
		if(first->soMu > second->soMu){
			temp = createNewNode(first->heSo, first->soMu);
			first = first->next;
		} else if(first->soMu < second->soMu){
			temp = createNewNode(-second->heSo, second->soMu);
			second = second->next;
		} else {
			if(first->heSo - second->heSo != 0){
				temp = createNewNode(first->heSo - second->heSo, first->soMu);
			}
			first = first->next;
			second = second->next;
		}
		if(isFirst){
			subtractPolynomial = temp;
			last = temp;
            isFirst = 0;
		} else {
			last->next = temp;
			last = temp;
		}
	}
	if(first == NULL){
		while(second != NULL){
			temp = createNewNode(-second->heSo, second->soMu);
			if(isFirst){
				subtractPolynomial = temp;
				last = temp;
    	        isFirst = 0;
			} else {
				last->next = temp;
				last = temp;
			}
			second = second->next;
		}
	} else if(second == NULL){
		while(first != NULL){
			temp = createNewNode(first->heSo, first->soMu);
			if(isFirst){
				subtractPolynomial = temp;
				last = temp;
    	        isFirst = 0;
			} else {
				last->next = temp;
				last = temp;
			}
			first = first->next;
		}
	}
	return subtractPolynomial;
}

struct Node* multiplyPolynomialWithNode(struct Node* head, struct Node* multiplier)
{
	struct Node* multiplyPolynomialWithNode;
    struct Node* temp;
    struct Node* p;
    int isFirst = 1;
    while(head != NULL){
        temp = createNewNode(head->heSo * multiplier->heSo, head->soMu + multiplier->soMu);
		head = head->next;
        if(isFirst){
            multiplyPolynomialWithNode = temp;
            p = multiplyPolynomialWithNode;
            isFirst = 0;
        } else {
            p->next = temp;
            p = temp;
        }
    }
	return multiplyPolynomialWithNode;
}

struct Node* multiplyTwoPolynomial(struct Node* first, struct Node* second)
{
	struct Node* multiplyTwoPolynomial = NULL;
	struct Node* temp;
	while(second != NULL){
		double heso = second->heSo;
		int somu = second->soMu;
		struct Node* multiplier = createNewNode(heso, somu);
		temp = multiplyPolynomialWithNode(first, multiplier);
		multiplyTwoPolynomial = addPolynomial(multiplyTwoPolynomial, temp);
		second = second->next;
	}
	return multiplyTwoPolynomial;
}

int main()
{
	struct Node *hPoly1=NULL, *hPoly2=NULL, *hPoly3, *aNode;
	double x, heSo;
	int soMu;
    printf("Nhap da thuc 1: ");
	    hPoly1 = readData();
    printf("Nhap da thuc 2: ");
	    hPoly2 = readData();
    printf("Da thuc 1 la: ");
		printData(hPoly1);
    printf("Da thuc 2 la: ");
		printData(hPoly2);
    printf("x = 2.25\n"); x = 2.25;

    printf("Da thuc 1 = %.2lf", calculatePolynomialValue(hPoly1, x));
    printf("\nDa thuc 2 = %.2lf", calculatePolynomialValue(hPoly2, x));

    printf("\nTong 2 da thuc la: ");
        hPoly3 = addPolynomial(hPoly1, hPoly2);
        printData(hPoly3);
        freePolynomial(&hPoly3);
    printf("\nHieu 2 da thuc la: ");
        hPoly3 = subtractPolynomial(hPoly1, hPoly2);
		printData(hPoly3);
        freePolynomial(&hPoly3);
    printf("\nTich 2 da thuc la: ");
		hPoly3 = multiplyTwoPolynomial(hPoly1, hPoly2);
		printData(hPoly3);
		freePolynomial(&hPoly3);

	freePolynomial(&hPoly1);
	freePolynomial(&hPoly2);
	return 0;
}