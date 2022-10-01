#include<stdio.h>
#include <memory.h> 
#include<stdlib.h>
#include "list.h"

int main()
{
	pNode pHead = NULL;
	Node A;
	Node B;
	Node C;
	Node D;
	Node E;
	Node F;
	Node INS;

	INS.data.x = 0;
	A.data.x = 1;
	B.data.x = 2;
	C.data.x = 3;
	D.data.x = 4;
	E.data.x = 5;
	F.data.x = 6;

	pHead = CreatSingleList();
	AddTailList(pHead,&A);
	AddTailList(pHead,&B);
	AddTailList(pHead,&C);
	AddTailList(pHead,&D);
	AddTailList(pHead,&E);
	AddTailList(pHead,&F);
	//InsertPosList(pHead,7,&INS);
	//DeletePosList(pHead,3);	
    //printf("2----%d\n",SearchNodeList(pHead,&B,compare));
//	BubleList( pHead,compare);
	TraverseSingleList(pHead);


	return 0;
}

