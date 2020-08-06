#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;
typedef struct node
{
    SElemType data;
    struct node *link;
}LinkNode, * LinkStack;
LinkStack S = NULL;
void InitStack(LinkStack *S)
//��ʽջ��ʼ������ջ��ָ��Ϊ��
{
    *S=NULL;
}
int Push(LinkStack *S,SElemType *x)
//��ջ����Ԫ��x���뵽��ʽջ��ջ��������ͷ
{
    LinkStack p=(LinkStack)malloc(sizeof(LinkNode));
    p->data=x;
    p->link=*S;
    *S=p;

    return 1;
}
int Pop(LinkStack *S,SElemType *x)
//��ջ����ջ�գ���������0������x��ֵ������
//��ջ���գ���������1����ͨ�����ò���x���ر�ɾջ��Ԫ�ص�ֵ
{
    if(*S==NULL)
    {
        return 0;
    }
    LinkNode *p=*S;
    *x=p->data;
    *S=p->link;
    free(p);
    return 1;
}
int GetTop(LinkStack *S,SElemType *x)
//��ȡջ������ջ���գ�����ͨ�����ò���x����ջ��Ԫ�ص�ֵ
{
    if(S==NULL)
    {
        return 0;
    }
    *x=(*S)->data;
    return 1;
}
int StackEmpty(LinkStack *S)
//�ж�ջ�Ƿ�Ϊ�գ���ջΪ�գ���������1������������0��
{
    return *S==NULL;
}
int StackSize(LinkStack *S)
//��ջ�ĳ��ȣ�����ջԪ�ظ���
{
    LinkNode *p=*S;
    int k=0;
    while(p!=NULL)
    {
        p=p->link;
        k++;
    }
    return k;
}
int main()
{
    int x;
    LinkStack S;
    InitStack(&S);
    Push(&S,5);
    Pop(&S,&x);
    printf("%d",x);
    return 0;
}
