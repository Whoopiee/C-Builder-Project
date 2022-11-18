//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Dialogs.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TrepForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TDBGrid *DBGrid1;
	TDatePicker *DatePicker1;
	TDatePicker *DatePicker2;
	TButton *closeBtn;
	TMemo *Memo1;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TWebBrowser *WebBrowser1;
	TDBGrid *DBGrid2;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TrepForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TrepForm *repForm;
//---------------------------------------------------------------------------
#endif
