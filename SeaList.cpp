/**
 * @author: SEKin 
 * @Date: 2021-08-17 10:32:07 
 * @description:  线性表
 * @Last Modified time: 2021-08-17 10:32:07 
 */
#include <iostream>
#include <string>
using namespace std;
const int MaxSize = 1000;

class DataType
{
public:
    int no;
    string name;
    DataType() = default;
    DataType(int a, string b) : no(a), name(b){};
};

class SeqList
{
    DataType data[MaxSize];
    int length;

public:
    SeqList()
    {
        length = 0;
    }
    void insert(DataType value)
    {
        if (length + 1 > MaxSize)
        {
            cout << "ERROR" << endl;
        }
        length++;
        data[length] = value;
    }
    void insert(DataType value, int index)
    {
        if (length + 1 > MaxSize || index > length + 1 || index < 1 || index > MaxSize)
        {
            cout << "ERROR" << endl;
            return;
        }

        for (size_t i = length; i >= index; i--)
        {
            data[i + 1] = data[i];
        }

        data[index] = value;
        length++;
        print();
    }
    void del(int value)
    {
        int leg = length;
        while (leg)
        {
            if (data[leg].no == value)
            {
                break;
            }
            leg--;
        }

        int index = leg;

        if (index > length || index < 1)
        {
            cout << "ERROR" << endl;
            return;
        }

        for (size_t i = index; i < length; i++)
        {
            data[i] = data[i + 1];
        }

        length--;
        print();
    }
    void print()
    {
        for (size_t i = 1; i < length + 1; i++)
        {
            cout << data[i].no << "-" << data[i].name << (i == length ? "" : " ");
        }
        cout << endl;
    }
};

int main()
{

    SeqList arr;
    int leg;
    cin >> leg;
    while (leg--)
    {

        int no;
        string name;
        cin >> no >> name;
        DataType a(no, name);
        arr.insert(a);
    }

    arr.print();

    int insertIndex, insertNo;
    string name;
    cin >> insertIndex >> insertNo >> name;
    DataType insertVal(insertNo, name);
    arr.insert(insertVal, insertIndex);

    int delNo;
    cin >> delNo;

    arr.del(delNo);

    return 0;
}