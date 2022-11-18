//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "showDB.h"
#include "mainForm.h"
#include "searchOblik.h"
#include "searchClient.h"
#include "DataModule.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TviewDB *viewDB;
//---------------------------------------------------------------------------
__fastcall TviewDB::TviewDB(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::FormShow(TObject *Sender)
{

	//show all clients
	DataModule1->showClientQuery->Close();
	DataModule1->showClientQuery->SQL->Clear();
	DataModule1->showClientQuery->SQL->Add("select * from client");
	DataModule1->showClientQuery->Open();

	//show all obliks
//	DataModule1->showQuery->Close();
//	DataModule1->showQuery->SQL->Clear();
//	DataModule1->showQuery->SQL->Add("SELECT * from oblik");
//	DataModule1->showQuery->Open();

	//show all services
	DataModule1->showServ->Close();
	DataModule1->showServ->SQL->Clear();
	DataModule1->showServ->SQL->Add("SELECT * from services");
	DataModule1->showServ->Open();

	//show all tariffs
	DataModule1->tarifQuery->Close();
	DataModule1->tarifQuery->SQL->Clear();
	DataModule1->tarifQuery->SQL->Add("select * from tariff ");
	DataModule1->tarifQuery->Open();

	DataModule1->showQuery->Open();

	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();

	AnsiString text;
	text = DataModule1->showQuery->FieldByName("name")->AsString;

	ShowMessage(text);
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::closeBtnClick(TObject *Sender)
{
	//closing form
  mainFormm->Enabled = true;
  viewDB->Hide();
  viewDB->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::test1Click(TObject *Sender)
{
	viewDB->Enabled = false;
	searchOblForm->Show();
	searchOblForm->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::N1Click(TObject *Sender)
{
	viewDB->Enabled = false;
	searchClientForm->Show();
    searchClientForm->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::DBGrid1TitleClick(TColumn *Column)
{

if (DataModule1->showQuery->Active)
{
	 if ((DataModule1->showQuery->Sort.Pos(Column->FieldName) > 0) && (DataModule1->showQuery->Sort.Pos("ASC") > 0))
	  {
		DataModule1->showQuery->Sort = Column->FieldName + " DESC";
	  }
	 else
	  {
		DataModule1->showQuery->Sort = Column->FieldName + " ASC";
	  }
}


//  String Prog = "1.html";
//  ShellExecute(0, L"open", Prog.c_str(), NULL, NULL, SW_SHOW);


}
//---------------------------------------------------------------------------

void __fastcall TviewDB::DBGrid3TitleClick(TColumn *Column)
{
  if (DataModule1->showClientQuery->Active)
{
	 if ((DataModule1->showClientQuery->Sort.Pos(Column->FieldName) > 0) && (DataModule1->showClientQuery->Sort.Pos("ASC") > 0))
	  {
		DataModule1->showClientQuery->Sort = Column->FieldName + " DESC";
	  }
	 else
	  {
		DataModule1->showClientQuery->Sort = Column->FieldName + " ASC";
	  }
}
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::DBGrid2TitleClick(TColumn *Column)
{
	if (DataModule1->showServ->Active)
{
	 if ((DataModule1->showServ->Sort.Pos(Column->FieldName) > 0) && (DataModule1->showServ->Sort.Pos("ASC") > 0))
	  {
		DataModule1->showServ->Sort = Column->FieldName + " DESC";
	  }
	 else
	  {
		DataModule1->showServ->Sort = Column->FieldName + " ASC";
	  }
}
}
//---------------------------------------------------------------------------

void __fastcall TviewDB::DBGrid4TitleClick(TColumn *Column)
{
	if (DataModule1->tarifQuery->Active)
{
	 if ((DataModule1->tarifQuery->Sort.Pos(Column->FieldName) > 0) && (DataModule1->tarifQuery->Sort.Pos("ASC") > 0))
	  {
		DataModule1->tarifQuery->Sort = Column->FieldName + " DESC";
	  }
	 else
	  {
		DataModule1->tarifQuery->Sort = Column->FieldName + " ASC";
	  }
}

}
//---------------------------------------------------------------------------

void __fastcall TviewDB::FormActivate(TObject *Sender)
{
   	//show all clients
	DataModule1->showClientQuery->Close();
	DataModule1->showClientQuery->SQL->Clear();
	DataModule1->showClientQuery->SQL->Add("select * from client");
	DataModule1->showClientQuery->Open();

	//show all obliks
	DataModule1->showQuery->Close();
	DataModule1->showQuery->SQL->Clear();
	DataModule1->showQuery->SQL->Add("SELECT * from oblik");
	DataModule1->showQuery->Open();

	//show all services
	DataModule1->showServ->Close();
	DataModule1->showServ->SQL->Clear();
	DataModule1->showServ->SQL->Add("SELECT * from services");
	DataModule1->showServ->Open();

	//show all tariffs
	DataModule1->tarifQuery->Close();
	DataModule1->tarifQuery->SQL->Clear();
	DataModule1->tarifQuery->SQL->Add("select * from tariff ");
	DataModule1->tarifQuery->Open();
}
//---------------------------------------------------------------------------

