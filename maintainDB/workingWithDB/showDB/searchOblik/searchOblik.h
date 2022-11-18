//---------------------------------------------------------------------------

#ifndef searchOblikH
#define searchOblikH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TsearchOblForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMaskEdit *MaskEdit1;
	TButton *Button2;
	TLabel *Label2;
	TDBGrid *DBGrid1;
	TLabel *Label4;
	TDBGrid *DBGrid3;
	TButton *closeBtn;
	TLabel *Label3;
	TDBGrid *DBGrid2;
	TLabel *Label5;
	TDBGrid *DBGrid4;
	TButton *Button1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TsearchOblForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TsearchOblForm *searchOblForm;
//---------------------------------------------------------------------------
#endif
