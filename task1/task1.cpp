//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "task1.h"
#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Ttask1Form *task1Form;
//---------------------------------------------------------------------------
__fastcall Ttask1Form::Ttask1Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Ttask1Form::backButtonClick(TObject *Sender)
{
	task1Form->Hide();
	mainFormm->Show();
}
//---------------------------------------------------------------------------
void __fastcall Ttask1Form::closeBtnClick(TObject *Sender)
{
	task1Form->Close();
}
//---------------------------------------------------------------------------
