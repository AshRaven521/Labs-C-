//---------------------------------------------------------------------------

#ifndef QueueActionsH
#define QueueActionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TListBox *ListBox3;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label10;
	TButton *Button3;
	TEdit *Edit3;
	TButton *Button4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void PrintEdit();
	void PrintEdit2();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
