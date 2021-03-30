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
	LinkList p, q, r, s;//q��s�ǵ�ǰ�Ƚϵ��������,p��q��ǰ��,r��s��ǰ��
	while (head->next != NULL)
	{
		p = q = r = head->next;//������ֵ
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
		free(q);//�ͷŵ�ǰֵ��С�Ľ��ռ�
	}
}
int main() {
	return 0;
}