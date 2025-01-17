//---------------------------------------------------------------------------

#ifndef QueueCreationH
#define QueueCreationH
#include <string>
class Node
{
  public:
	int numbers;
	Node *next;//��������� �� ��������� ����
	Node *prev;
	Node()
	{
		numbers=0;
		next=NULL;
		prev=NULL;
	}
};

class List
{
   public:
	Node *head,*tail;
	int size,current,indexMax,indexMin;

	//�����������:
	List()
	{
		head=NULL;
		tail=NULL;
		size=0;
		current=-1;
		indexMax=0;
		indexMin=0;
	}

	//����������:
	~List()
	{
		if(head)
		{
			head->prev=NULL;
		}
		if(tail)
		{
			tail->next=NULL;
		}


		while (head!=NULL)          //���� �� ������ �� �����
		{
			Node *temp = head->next;   //��������� ���������� ��� �������� ������ ���������� ��������
			delete head;                //����������� ����� ������������ ������
			head = temp;                  //������ ����� �� ���������
		}
	}

	//void CreateQueue();//�������� ��������� ��� ��������� �����
	void Add(int);
	int GetNum(int);
	int GetMax();
	int GetMin();
	void DeleteQueue();
};

class Queue : public List
{
  public:
	Node* currentNode;

	Queue() : List()
	{
		currentNode = NULL;
	}

	void LoopBack();
	void SetCurrent();
	int PrintNode();
};

//---------------------------------------------------------------------------
#endif
