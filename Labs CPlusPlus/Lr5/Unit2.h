//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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

//---------------------------------------------------------------------------
#endif
