#include <iostream>;
#include <math.h>;
#include <string>;
using namespace std;
const int arrSize = 10;
typedef int dataType;

typedef struct linkstack {
	dataType low;
	dataType hig;
	struct linkstack* next;
} stk, * LinkStk;

LinkStk InitLinkStatck() {
	LinkStk tem = (linkstack*)malloc(sizeof(linkstack));
	tem->next = NULL;

	return tem;
}

void pushStk(LinkStk stk, dataType low, dataType hig) {
	LinkStk tem = new linkstack;
	tem->low = low;
	tem->low = hig;

	tem->next = stk->next;
	stk->next = tem;
}

void popStk(LinkStk stk) {
	LinkStk tem = stk->next;
	stk->next = tem->next;
	free(tem);
}

int find(int(&arr)[arrSize], int k) {
	int cunt = 0;
	int low = 1;
	int hig = arrSize;
	int mid = floor((low + hig) / 2);

	while (true)
	{
		cunt++;
		if (low == hig) {
			if (low == k) {
				cout << "找到位置：" << low << endl;
				return low;
			}
			else {
				cout << "找不到位置：" << endl;
				return -1;
			}
		}
		if (arr[mid - 1] == k) {
			cout << "找到位置：" << mid << endl;
			return mid;
		}
		else if (arr[mid - 1] > k) {
			hig = mid - 1;
			mid = floor((low + hig) / 2);
		}
		else {
			low = mid + 1;
			mid = floor((low + hig) / 2);
		}
		if (cunt > 100) {
			cout << "死循环" << endl;
			return -1;
		}
	}
}

int main() {
	int arr[arrSize] = { 1,2,3,4,5,6,7,8,9,10 };
	int k;
	while (cin >> k) {
		int res = find(arr, k);
		cout << res << endl;
	}
	return 0;
}