//---------------------------------------------------------------------------

#ifndef task1H
#define task1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class Ttask1Form : public TForm
{
__published:	// IDE-managed Components
	TButton *closeBtn;
	TButton *backButton;
	TLabel *Label2;
	void __fastcall backButtonClick(TObject *Sender);
	void __fastcall closeBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Ttask1Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Ttask1Form *task1Form;
//---------------------------------------------------------------------------
#endif
