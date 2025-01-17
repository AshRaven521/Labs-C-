//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List qu1;
List qu2;
List qu3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	qu1.DeleteQueue();
	ListBox1->Clear();
	srand(time(0));
	int quantity =StrToInt(Edit1->Text);
	int rand1;
	for (int i = 0; i < quantity; i++)
	{
		rand1=rand() % 200 - 100;
		qu1.Add(rand1);
		ListBox1->Items->Add(IntToStr(i + 1) + ".  "+rand1);
	}
	Label7->Caption = qu1.GetMax();
	Label8->Caption = qu1.GetMin();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Node* ptr=qu1.head;
	int i=0;


	qu2.DeleteQueue();
	ListBox2->Clear();
	qu3.DeleteQueue();
	ListBox3->Clear();

	while(ptr!=NULL)
	{
		if(qu1.indexMax>qu1.indexMin)
		{
			if(i>qu1.indexMin && i<qu1.indexMax)
			{
				qu2.Add(ptr->numbers);
				ListBox2->Items->Add(IntToStr(ptr->numbers));
			}
			else
			{
				qu3.Add(ptr->numbers);
				ListBox3->Items->Add(IntToStr(ptr->numbers));
			}
		}
		else
		{
			if(i<qu1.indexMin && i>qu1.indexMax)
			{
				qu2.Add(ptr->numbers);
				ListBox2->Items->Add(IntToStr(ptr->numbers));
			}
			else
			{
				qu3.Add(ptr->numbers);
				ListBox3->Items->Add(IntToStr(ptr->numbers));
			}
		}

		i++;
		ptr=ptr->next;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text=10;
}
//---------------------------------------------------------------------------


