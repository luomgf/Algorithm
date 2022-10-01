/*____________________________________________________
功能：C语言实现 单链表 的 增、删、改、查、排序、遍历。
时间：2013年8月3日12:48:22
作者：罗明刚
___________________________________________________*/

#include<stdio.h>
#include <memory.h> 
#include<stdlib.h>
#include <list.h>

//***********1链表创建函数***********************

pNode CreatSingleList(void)
{
	pNode pHead = NULL;

	pHead = (pNode)malloc( sizeof(Node) );
	if	(NULL == pHead)
	{
		exit(0);
	}
	memset(pHead,0,sizeof(Node));
	pHead->pNext = NULL;

	return pHead;
}

/***********2链表插入函数***********************
函数名称：InsertPosList
参    数：
			链表头结点地址		pHead			
			插入链表中位置		Pos
			插入结点地址		pVal
说	  明：
			pHead头结点不包含数据
			Pos取值： 1.....n
			Pval为插入结点地址
创建时间：	
			2013年8月17日9:25:03
作    者:	
			罗明刚
************************************************/
 int InsertPosList(pNode pHead,int Pos, pNode pVal)
 {
	pNode p =NULL;
	int i = 0;

	if(IsEmptyList(pHead))
	{
		return -1;
	}

	for(p = pHead; NULL != p->pNext && i< (Pos-1); i++,p = p->pNext );

	while(i > (Pos-1) || NULL == p->pNext )
	{
		return -1;
	}

	pNode pNew;

	if(NULL == (pNew = (pNode)malloc( sizeof(Node) )))
	{
		return -1;
	}

	memcpy(pNew,pVal,sizeof(Node));

	pNode pTemp = p->pNext;
	p->pNext = pNew;
	pNew->pNext = pTemp;

	return 0;
 }


//***********3链表遍历函数***********************

int  TraverseSingleList(pNode pHead)
{
	pNode p;

	if( IsEmptyList(pHead) )
	{
		return 0;
	}

	for(p = pHead->pNext; NULL != p; p = p->pNext)
	{
		printf("(%d)\n",p->data.x);
	}

	return 1;
}

int IsEmptyList(pNode pHead)
{
	if(NULL==pHead->pNext)
	{
		return 1;
	}

	return 0;
}
int AddTailList(pNode pHead, pNode pVal)
{
	pNode pNew = NULL;
	pNode p = NULL;

	for(p = pHead; NULL != p->pNext; p = p->pNext);
	

	pNew = (pNode)malloc( sizeof(Node) );
	if	(NULL == pNew)
	{
		exit(0);
	}
	memcpy(pNew,pVal,sizeof(Node));
	pNew->pNext = NULL;
	p->pNext = pNew;


	return 0;
}

//***********4删除元素***********************

int DeletePosList(pNode pHead,int Pos)
{
	pNode p = NULL;
	pNode pDelete = NULL;
	int i = 0;

	if( IsEmptyList(pHead) )
	{
		return 0;
	}

	for(p = pHead, i = 0; NULL != p->pNext && i<(Pos-1);p = p->pNext,i++);
	while( NULL==p->pNext&&Pos-1>i )
	{
		return 0;
	}
	pDelete = p->pNext;
	p->pNext = p->pNext->pNext;
	free(pDelete);
	pDelete = NULL;

	return 1;
}

int SearchNodeList(pNode pHead,pNode pVal,int compare(void *,void *))            //查
{
	pNode p = NULL;
	int i = 0;
	for(i = 1,p = pHead->pNext; NULL != p; i++, p = p->pNext)
	{
		if( 0==compare(p,pVal))
		{
		   return i;	
		}
	}

	return 0;
}

int compare(void * a,void * b)
{
	return  ((pNode)a )->data.x - ((pNode)b )->data.x;
}

int BubleList(pNode pHead,int compare(void *,void *))
{
	pNode p = NULL;
	pNode q = NULL;
	pNode q1 = NULL;
	pNode q2 = NULL;
	pNode t = NULL;
	int i = 0;
	int flag = 1;

	for(p = pHead;NULL!=p->pNext->pNext->pNext; p = p->pNext)
	{
		t = p;
		for(q = p->pNext; NULL != q; q = q->pNext)
		{
			if(0>compare(q,q->pNext))
			{
				q1 = q->pNext;
				q->pNext = q1->pNext;
				q1->pNext = q;
				t->pNext = q1;
				t = q1;

			} 
		}	
		//if(flag)  break;
	}


	return 1;
}
/*
------------------------------------------------
函数名称：ReversePosList
------------------------------------------------
*/
pNode ReversePosList(pNode pHead)  //链表翻转
{
	pNode p = pHead->pNext;
	pNode q = p->pNext;
	pNode t = NULL;

	if(IsEmptyList(pHead))
	{
		return NULL;
	}

	for(; NULL != q; )
	{
		t = q->pNext;  //将q节点后面的节后保存起来
		q->pNext = p;  //前面是q在p后面，现在让q在p前面实现翻转
		p = q;			//向为节点方向移动一个节点
		q = t;          //向尾节点方向移动一个节点
	}

	pHead->pNext->pNext = NULL;
	pHead->pNext = p;

	return pHead;
}


pNode sort(pNode head)
{   
	pNode p,p1,p2,p3;  
	Node h, t;   
	if (head == NULL)
		return NULL;  
	h.pNext=head;  
	p=&h;    
	while (p->pNext!=NULL) 
	{       
		p=p->pNext;   
	}  
	p=p->pNext=&t;   
	while (p!=h.pNext) 
	{       
		p3=&h;  
		p1=p3->pNext;  
		p2=p1->pNext;    
		while (p2!=p)   
		{        
			if ((p1->data.x)>(p2->data.x))  
			{         
				p1->pNext=p2->pNext;    
				p2->pNext=p1;       
				p3->pNext=p2;      
				p3=p2;            
				p2=p1->pNext;       
			} else
			{           
				p3=p1;        
				p1=p2;          
				p2=p2->pNext;   
			}       
		}     
		p=p1;  
	}   
	while (p->pNext!=&t) 
	{      
		p=p->pNext;  
	}   
	p->pNext=NULL;   
	return h.pNext;
}



