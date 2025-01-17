//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TreeAction.h"
#include "TreeCreation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TreeCalculation tree;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	StringGrid1->ColWidths[0] = 100;
	StringGrid1->ColWidths[1] = 100;
	StringGrid1->Cells[0][0] = "�������� �����";
	StringGrid1->Cells[1][0] = "CVC ���";
	StringGrid1->Cells[0][1] = "�������������";
	StringGrid1->Cells[0][2] = "�����-����";
	StringGrid1->Cells[0][3] = "���������������";
	StringGrid1->Cells[0][4] = "������������";
	StringGrid1->Cells[1][1] = "324";
	StringGrid1->Cells[1][2] = "851";
	StringGrid1->Cells[1][3] = "856";
	StringGrid1->Cells[1][4] = "027";
	Memo1->Clear();

	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//�������������� ������� ������
	tree.TreeClear(tree.root);
	//�.� ��������� ���������,�� ��� ���� ��������� �����-���� ��������
	tree.root = NULL;

	AnsiString str ;
	int code;
	for(int i=1; i<StringGrid1->RowCount; i++)
	{
		if(!StringGrid1->Cells[0][i].IsEmpty())
		{
			str = StringGrid1->Cells[0][i];
			std::string strStr = str.c_str();
			str = StringGrid1->Cells[1][i];
			code = StrToInt(str);
			tree.root=tree.TreeAdd(tree.root,strStr,code);
		}

	}
	tree.ShowTree(TreeView1);
	//��� ���������� ������� ����������� ������ � TreeView
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int count = 1;
	int level = 0;
	int sum=0;
	while (count != 0)
	{
		count = tree.CountOnLevel(tree.root, level);
		if (count > 0)
		{
			sum=sum+count;
		}
		level++;
	}
	Memo1->Lines->Add("���������� �������� �� ���� �������: " + IntToStr(sum));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Lines->Add("������ �����: ");
	tree.DirectBypass(Memo1,tree.root);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Add("�������� �����: ");
	tree.BackwardBypass(Memo1,tree.root);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Memo1->Lines->Add("����� � ������� ����������� �����: ");
	tree.KeyBypass(Memo1,tree.root);
	Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	AnsiString ansi = Edit1->Text;
	std::string name = (ansi.c_str());
	AnsiString ansip = Edit2->Text;;
	int code = StrToInt(ansip);

	if(code <99 || code>999)
	{
		ShowMessage("������� ���������� CVC ���, ��� �� ���������� �����(��� �����)!");
	}
	else
	{
		tree.root=tree.TreeAdd(tree.root,name,code);

		tree.ShowTree(TreeView1);
		TreeView1->FullExpand();

		StringGrid1->RowCount++;
		StringGrid1->Cells[0][StringGrid1->RowCount-1] = Edit1->Text;
		StringGrid1->Cells[1][StringGrid1->RowCount-1] = Edit2->Text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	try
	{
		if(!tree.root)
		{
		  return;
		}
		else
		{
			int numer = StrToInt(Edit2->Text);

			AnsiString str = tree.GetBank(numer);
			tree.DeleteNode(numer);
			tree.ShowTree(TreeView1);
			Memo1->Lines->Add("���� �������");
			Memo1->Lines->Add("�������� �����: " + str);
			Memo1->Lines->Add("CVC ���: " + IntToStr(numer));
			Memo1->Lines->Add("\n");
			for(int i = 1, j = 1; i < StringGrid1->RowCount; i++)
			{
				if(StringGrid1->Cells[1][i] != numer)
				{
					StringGrid1->Cells[0][j] = StringGrid1->Cells[0][i];
					StringGrid1->Cells[1][j] = StringGrid1->Cells[1][i];
					j++;
				}
			}
			StringGrid1->RowCount--;
			Edit1->Text = "";
			Edit2->Text = "";
		}
	}
	catch(...)
	{
		Edit2->Text = "";
		ShowMessage("������������ CVC ���");
	}
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	try
	{
	  if(!tree.root)
	  {
		return;
	  }
	  else
	  {
		int numer = StrToInt(Edit2->Text);
		if(numer > 99 && numer < 1000)
		{
			AnsiString str = tree.GetBank(numer);
			if(str != "")
			{
				Memo1->Lines->Add("���� �������: ");
				Memo1->Lines->Add("�������� �����: " + str);
				Memo1->Lines->Add("CVC ���: " + IntToStr(numer));
				Memo1->Lines->Add("\n");
			}
			else
			{
				Memo1->Lines->Add("���� �� �������");
				Memo1->Lines->Add("\n");
			}
		}
		else
		{
			Edit2->Text = "";
			ShowMessage("������������ CVC ���");
		}
	  }
	}
	catch(...)
	{
		Edit2->Text = "";
		ShowMessage("������������ CVC ���");
	}
}
//---------------------------------------------------------------------------

