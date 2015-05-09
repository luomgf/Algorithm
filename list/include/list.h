#ifndef _LIST_H_
#define _LIST_H_

typedef struct tagNodeData
{
	int x;
	
}NodeData;

typedef struct tagNode
{
	NodeData		 data;
	struct tagNode * pNext;
}Node, * pNode;

pNode CreatSingleList(void);
int InsertPosList(pNode pHead,int Pos, pNode pVal);				//插
int AddTailList(pNode pHead, pNode pVal);				   	//增
int DeletePosList(pNode pHead,int Pos);						//删
int SearchNodeList(pNode pHead,pNode pVal,int compare(void *,void *));		//查
int BubleList(pNode pHead,int compare(void *,void *));				//排序
pNode ReversePosList(pNode pHead);  						//链表翻转
int compare(void *,void *);							//判断比较函数
int IsEmptyList(pNode pHead);							//链表为空
int TraverseSingleList(pNode pHead);						//链表排序
pNode sort(pNode head);
#endif
