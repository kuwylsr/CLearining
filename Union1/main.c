#include <stdio.h>
#include <stdlib.h>

struct date
{
    int year;
    int month;
    int day;
};
struct marriedState
{
    struct date marryDay;
    char spouseName[20];
    int child;
};
struct divorceState
{
    struct date divorceDay;
    int child;
};
union maritalState
//����ͬһ�ڴ浥Ԫ��ÿһ˲��ֻ�ܴ������һ���������͵ĳ�Ա��Ҳ����˵ͬһʱ��ֻ��һ����Ա���������
{
    int single;
    struct marriedState married;
    struct divorceState divorce;
};
struct person
{
    char name[20];
    char sex;
    int age;
    union maritalState marital;
    int marryFlag;
};
int main()
{
    printf("Hello world!\n");
    return 0;
}
