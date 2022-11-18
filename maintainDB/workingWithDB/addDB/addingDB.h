//---------------------------------------------------------------------------

#ifndef addingDBH
#define addingDBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TAddFormm : public TForm
{
__published:	// IDE-managed Components
	TMaskEdit *MaskEdit1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TLabel *Label4;
	TEdit *Edit1;
	TLabel *Label5;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TMaskEdit *MaskEdit2;
	TLabel *Label10;
	TButton *Button1;
	TButton *closeBtn;
	TCheckListBox *CheckListBox1;
	TRadioGroup *RadioGroup1;
	TMonthCalendar *MonthCalendar1;
	TLabel *Label3;
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TAddFormm(TComponent* Owner);
		AnsiString convertDate(String date); //method for converting date
};
//---------------------------------------------------------------------------
extern PACKAGE TAddFormm *AddFormm;
//---------------------------------------------------------------------------
#endif
