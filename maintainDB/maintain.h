//---------------------------------------------------------------------------

#ifndef maintainH
#define maintainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TmaintainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *addButton;
	TLabel *Label1;
	TButton *updButton;
	TButton *closeBtn;
	TButton *Button1;
	void __fastcall backButtonClick(TObject *Sender);
	void __fastcall updButtonClick(TObject *Sender);
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall addButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmaintainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmaintainForm *maintainForm;
//---------------------------------------------------------------------------
#endif
