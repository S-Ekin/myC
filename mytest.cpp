#include <iostream>;
#include <iomanip>;
using namespace std;

typedef struct node {
	int data;
	struct node* next;
} Node, * LinkList;

// 判断单链表L 是否是递增
int list_isrising(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) { // 没有节点
		return 1;
	}

	if (p->next == NULL) { //只有一个元素
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
	//用new可以
	for (int& i : arr) {
		LinkList newNode = new node;
		newNode->next = NULL;
		newNode->data = i;
		p->next = newNode;
		p = newNode;
	}

	// 用下面的直接构造节点的方式不行
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