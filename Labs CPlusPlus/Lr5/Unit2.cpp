//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit2.h"

void List :: Add(int a)
{
	Node *temp =  new Node();
	temp->numbers = a;
	temp->next = NULL;
	temp->prev = tail;
	if(tail)
	{
		tail->next = temp;
	}
	tail = temp;
	if(!head)
	{
		head = temp;
	}
	size++;
	current++;
}

int List :: GetMax()
{
	Node* ptr=head;
	int Max=-1000000;
	int i=0;
	while(ptr!=NULL)
	{
		if(ptr->numbers>Max)
		{
			Max=ptr->numbers;
			indexMax=i;
		}
		i++;
		ptr=ptr->next;
	}
	return Max;
}
int List :: GetMin()
{
	Node* ptr=head;
	int Min=1000000;
	int i=0;
	while(ptr!=NULL)
	{
		if(ptr->numbers<Min)
		{
			Min=ptr->numbers;
			indexMin=i;
		}
		i++;
		ptr=ptr->next;
	}
	return Min;
}
void List :: DeleteQueue()
{
	while(head)
	{
		Node *temp = head->next;
		delete temp;
		head = temp;
	}
	size=0;
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
