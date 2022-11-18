//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "maintain.h"
#include "mainForm.h"
#include "addingDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmaintainForm *maintainForm;
//---------------------------------------------------------------------------
__fastcall TmaintainForm::TmaintainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TmaintainForm::backButtonClick(TObject *Sender)
{
	mainFormm->Show();
	maintainForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TmaintainForm::updButtonClick(TObject *Sender)
{
	maintainForm->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TmaintainForm::closeBtnClick(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------

void __fastcall TmaintainForm::addButtonClick(TObject *Sender)
{
    addDB->Show();
	maintainForm->Hide();
}
//---------------------------------------------------------------------------

