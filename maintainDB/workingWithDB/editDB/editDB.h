//---------------------------------------------------------------------------

#ifndef editDBH
#define editDBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TEditForm : public TForm
{
__published:	// IDE-managed Components
	TButton *closeBtn;
	TLabel *Label1;
	TMaskEdit *MaskEdit1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label10;
	TLabel *Label9;
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMaskEdit *MaskEdit3;
	TButton *Button1;
	TCheckListBox *CheckListBox1;
	TRadioGroup *RadioGroup1;
	TMonthCalendar *MonthCalendar1;
	TDBGrid *DBGrid1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button3;
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall MaskEdit1Exit(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditForm *EditForm;
//---------------------------------------------------------------------------
#endif
