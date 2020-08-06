#include <stdio.h>
#include <stdlib.h>

typedef int  QElemType;
typedef struct Node
{
    QElemType data;
    struct Node *Link;
} LinkNode;
typedef struct
{
    LinkNode *front;
    LinkNode *rear;
} LinkQueue1,*LinkQueue;
void InitQueue(LinkQueue Q)
//���г�ʼ�������ͷָ��Ͷ�βָ���ΪNULL
{
    (*Q).front=(*Q).rear=NULL;
}
int EnQueue(LinkQueue Q,QElemType x)
//�����У�����Ԫ��x���뵽���еĶ�β����β��
{

    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->Link=NULL;
    if((*Q).rear==NULL)
    {
        (*Q).front=(*Q).rear=s;
    }
    else
    {
        (*Q).rear->Link=s;
        (*Q).rear=s;
    }
}
int DeQueue (LinkQueue Q,QElemType *x)
//�����У�������пգ������˶ӣ���������0�������ò���x��ֵ������
{
    if((*Q).front==NULL)
    {
        return 0;
    }
    LinkNode *p=(*Q).front;
    *x=p->data;
    (*Q).front=p->Link;
    free(p);
    if((*Q).front==NULL)
    {
        (*Q).rear=NULL;
    }
    return 1;
}
int GetFront(LinkQueue Q,QElemType *x)
//��ȡ��ͷԪ�ص�ֵ��������Ϊ�գ���������0�������ò���x��ֵ������
//�����в�Ϊ�գ���������1���Ҵ����ò���x�ɵõ��˳��Ķ�ͷԪ�ص�ֵ
{
    if((*Q).front==NULL)
    {
        return 0;
    }
    *x=(*Q).front->data;
    return 1;
}
int QueueEmpty(LinkQueue Q)
//�ж϶����Ƿ�Ϊ�գ����п���������1������������0
{
    return (*Q).front==NULL;
}
int QueueSize(LinkQueue Q)
{
    LinkNode *p=(*Q).front;
    int k=0;
    while(p!=NULL)
    {
        p=p->Link;
        k++;
    }
    return k;
}
int main()
{
    QElemType s,s1;
    LinkQueue Q=(LinkQueue)malloc(sizeof(LinkQueue1));
    InitQueue(Q);
    EnQueue(Q,10);
    EnQueue(Q,7);
    DeQueue(Q,&s);
    DeQueue(Q,&s1);
    printf("%d\n",s);
    printf("%d",s1);
    return 0;
}
