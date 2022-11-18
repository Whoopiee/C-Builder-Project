//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModule.h"
#include "mainForm.h"
#include "addingDB.h"
#include "editDB.h"
#include "showDB.h"
#include "Report.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainFormm *mainFormm;

//flag for connection
bool connected = false;
//---------------------------------------------------------------------------
__fastcall TmainFormm::TmainFormm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

//closing form
void __fastcall TmainFormm::closeBtnClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

//check for connection
void __fastcall TmainFormm::test1Click(TObject *Sender)
{
	if(connected == false){ShowMessage("База даних не підключена!");}
	else{
		mainFormm->Enabled = false;
		AddFormm->Show();
		AddFormm->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainFormm::N1Click(TObject *Sender)
{
	if(connected == false){ShowMessage("База даних не підключена!");}
	else{
		mainFormm->Enabled = false;
		viewDB->Show();
		viewDB->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainFormm::N2Click(TObject *Sender)
{
	if(connected == false){ShowMessage("База даних не підключена!");}
	else{
		mainFormm->Enabled = false;
		EditForm->Show();
		EditForm->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainFormm::test21Click(TObject *Sender)
{
	if(connected == false){ShowMessage("База даних не підключена!");}
	else{
		mainFormm->Enabled = false;
		repForm->Show();
		repForm->Enabled = true;
    }
}
//---------------------------------------------------------------------------


//show count of clients and connection info
void __fastcall TmainFormm::FormShow(TObject *Sender)
{

	if(DataModule1->ADOConnection1->Connected == true)
	{
    	connected = true;
		Label3->Caption = "Підключено";
		Label3->Font->Color = clGreen;
		Label2->Visible = true;
		Label4->Visible = true;

		DataModule1->FindLastClientQuery->Close();
		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->SQL->Add("select count(1) as cnt from oblik");
		DataModule1->FindLastClientQuery->Open();

		Label4->Caption = DataModule1->FindLastClientQuery->FieldByName("cnt")->AsString;

	}else{
    	connected = false;
		Label3->Caption = "Не підключено";
		Label3->Font->Color = clRed;
		Label2->Visible = false;
        Label4->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainFormm::FormActivate(TObject *Sender)
{
  		DataModule1->FindLastClientQuery->Close();
		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->SQL->Add("select count(1) as cnt from oblik");
		DataModule1->FindLastClientQuery->Open();

		Label4->Caption = DataModule1->FindLastClientQuery->FieldByName("cnt")->AsString;
}
//---------------------------------------------------------------------------

