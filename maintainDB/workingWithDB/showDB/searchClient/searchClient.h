//---------------------------------------------------------------------------

#ifndef searchClientH
#define searchClientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TsearchClientForm : public TForm
{
__published:	// IDE-managed Components
	TButton *closeBtn;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *Label6;
	TEdit *Edit1;
	TButton *Button2;
	TLabel *Label4;
	TDBGrid *DBGrid6;
	TMaskEdit *MaskEdit2;
	TLabel *Label8;
	TButton *Button1;
	TLabel *Label1;
	TDBGrid *DBGrid3;
	TLabel *Label7;
	TDBGrid *DBGrid5;
	TLabel *Label9;
	TDBGrid *DBGrid7;
	TLabel *Label10;
	TDBGrid *DBGrid8;
	TButton *Button3;
	TButton *Button4;
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TsearchClientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TsearchClientForm *searchClientForm;
//---------------------------------------------------------------------------
#endif
