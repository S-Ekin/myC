#include <iostream>;
using namespace std;
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node* next;
}Node, * LinkList;

void print_link_list(LinkList head)
{
	LinkList p, q, r, s;//q和s是当前比较的两个结点,p是q的前驱,r是s的前驱
	while (head->next != NULL)
	{
		p = q = r = head->next;//连续赋值
		s = r->next;
		while (s != NULL)
		{
			if (s->data < q->data)
			{
				p = r;
				q = s;
			}
			r = s;
			s = r->next;
		}
		printf("%d", q->data);
		if (q == head->next)
			head = q->next;
		else
			p->next = q->next;
		free(q);//释放当前值最小的结点空间
	}
}
int main() {
	return 0;
}