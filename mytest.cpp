#include <iostream>;
#include <iomanip>;
using namespace std;
typedef int dataType;

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

// 用数组创建单链表
Node* createLinkList2(int arr[], int n) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	for (int i = 0; i < n; i++) {
		Node* p = (Node*)malloc(sizeof(Node));
		p->data = arr[i];
		p->next = head->next;
		head->next = p;
	}
	return head;
}

// 用二叉链表做存储结构，递归遍历求二叉树高度
typedef struct btnode {
	dataType data;
	struct btnode* lchild, * rchild;
} *BinTree;

int mapTree(BinTree& tree, int h) {
	h++;
	int lH = tree->lchild != NULL ? mapTree(tree->lchild, h) : h;
	int rH = tree->rchild != NULL ? mapTree(tree->rchild, h) : h;

	return  lH > rH ? lH : rH;
}

int getHBinTree(BinTree& tree) {
	int H = mapTree(tree, 0);
	return H;
}

BinTree createBinTree() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	BinTree arrTree[sizeof(arr)];
	for (int& i : arr) {
		BinTree treeNode = new btnode;
		treeNode->data = i;
		treeNode->lchild = NULL;
		treeNode->rchild = NULL;
		arrTree[i] = treeNode;
	}

	arrTree[0]->lchild = arrTree[1];
	arrTree[0]->rchild = arrTree[2];
	arrTree[1]->lchild = arrTree[3];
	arrTree[1]->rchild = arrTree[7];
	arrTree[2]->rchild = arrTree[5];
	arrTree[3]->lchild = arrTree[4];
	arrTree[4]->rchild = arrTree[4];
	arrTree[9]->rchild = NULL;
	return arrTree[0];
}

int main_12() {
	BinTree tree = createBinTree();
	int H = getHBinTree(tree);
	cout << H;
	return 0;
}