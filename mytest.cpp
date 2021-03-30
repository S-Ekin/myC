#include <iostream>;
#include <iomanip>;
using namespace std;

typedef struct node {
	int data;
	struct node* next;
} Node, * LinkList;

// �жϵ�����L �Ƿ��ǵ���
int list_isrising(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) { // û�нڵ�
		return 1;
	}

	if (p->next == NULL) { //ֻ��һ��Ԫ��
		return 0;
	}

	LinkList q = p->next;

	while (q) {
		if (q->data < p->data) {
			return 1;
		}
		else {
			p = q;
			q = p->next;
		}
	}
	return 0;
}

void createLinkList(LinkList L, int(&arr)[5]) {
	LinkList p = L;
	//��new����
	for (int& i : arr) {
		LinkList newNode = new node;
		newNode->next = NULL;
		newNode->data = i;
		p->next = newNode;
		p = newNode;
	}

	// �������ֱ�ӹ���ڵ�ķ�ʽ����
	//for (int& i : arr) {
	//	node newNode;
	//	newNode.next = NULL;
	//	newNode.data = i;
	//	LinkList prt = &newNode;
	//	p->next = prt;
	//	p = prt;
	//}
}
LinkList InitiateLinkList() {
	LinkList head;
	head = new node;
	head->next = NULL;
	return head;
}

LinkList createLinkByCin() {
	LinkList head;
	head = InitiateLinkList();
	LinkList p = head;
	int x;
	while (cin >> x)
	{
		p->data = x;
		p = p->next;
	}
	return head;
}

Node* createLinkList2(int arr[], int n) {

	Node* head =(Node *) malloc(sizeof(Node));

	for (int i = 0; i < n; i++) {
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = arr[i];
		p->next = head->next;
		head->next = p;
	}
	return head;

}

int main() {
	return 0;
}