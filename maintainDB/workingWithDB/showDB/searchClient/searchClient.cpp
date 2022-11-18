//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "searchClient.h"
#include "showDB.h"
#include "DataModule.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsearchClientForm *searchClientForm;
//---------------------------------------------------------------------------
__fastcall TsearchClientForm::TsearchClientForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TsearchClientForm::closeBtnClick(TObject *Sender)
{
	viewDB->Enabled = true;
	searchClientForm->Hide();
	searchClientForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TsearchClientForm::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
	  {
		   Key = 0x0;
		   ShowMessage("Недопустимій знак!");
	  }
}
//---------------------------------------------------------------------------
void __fastcall TsearchClientForm::Button2Click(TObject *Sender)
{



		AnsiString idCl, idObl;

		if(Edit1->Text == "")
		{
			ShowMessage("Прізвище не введено!");
		}else
		{
			DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("Select count(1) as cnt from client where surName = '"+Edit1->Text+"'");
			DataModule1->FindLastClientQuery->Open();

			if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >= 1)
			{
				//show client info
				DataModule1->EditQuery->Close();
				DataModule1->EditQuery->SQL->Clear();
				DataModule1->EditQuery->SQL->Add("Select * from client where surName = '"+Edit1->Text+"'");
				DataModule1->EditQuery->Open();

			}else
			{
			  ShowMessage("Такого клієнта немає у базі!");

			  DataModule1->EditQuery->Close();
			  DataModule1->EditQuery->SQL->Clear();
			  DataModule1->EditQuery->SQL->Add("select * from client");
			  DataModule1->EditQuery->Open();

		}

}
}
//---------------------------------------------------------------------------
void __fastcall TsearchClientForm::FormShow(TObject *Sender)
{

	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("select * from client");
	DataModule1->EditQuery->Open();

	DBGrid8->Visible = false;
	Label10->Visible = false;
	DBGrid7->Visible = false;
	Label9->Visible = false;
	DBGrid5->Visible = false;
	Label7->Visible = false;

	MaskEdit2->Clear();
    Edit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TsearchClientForm::Button1Click(TObject *Sender)
{
  	AnsiString idCl, idObl; //oblik id and client id

		if(MaskEdit2->Text == "         ")
		{
			ShowMessage("Номер паспорта не введено!");
		}else
		{
			DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("Select count(1) as cnt from client where passpData = '"+MaskEdit2->Text+"'");
			DataModule1->FindLastClientQuery->Open();

			if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >= 1)
			{
				//show client info
				DataModule1->EditQuery->Close();
				DataModule1->EditQuery->SQL->Clear();
				DataModule1->EditQuery->SQL->Add("Select * from client where passpData = '"+MaskEdit2->Text+"'");
				DataModule1->EditQuery->Open();

				//find id of client
				DataModule1->FindLastClientQuery->Close();
				DataModule1->FindLastClientQuery->SQL->Clear();
				DataModule1->FindLastClientQuery->SQL->Add("Select idCl from client where passpData = '"+MaskEdit2->Text+"'");
				DataModule1->FindLastClientQuery->Open();
				idCl = DataModule1->FindLastClientQuery->FieldByName("idCl")->AsString;

				//show clients oblik
				DBGrid5->Visible = true;
				Label7->Visible = true;
				DataModule1->showQuery->Close();
				DataModule1->showQuery->SQL->Clear();
				DataModule1->showQuery->SQL->Add("Select * from oblik where idCl = '"+idCl+"'");
				DataModule1->showQuery->Open();

				//find oblik id
				DataModule1->OutputOblikQuery->Close();
				DataModule1->OutputOblikQuery->SQL->Clear();
				DataModule1->OutputOblikQuery->SQL->Add("SELECT idObl from oblik where idCl = '"+idCl+"'");
				DataModule1->OutputOblikQuery->Open();
				idObl = DataModule1->OutputOblikQuery->FieldByName("idObl")->Value;

				//search for services
				DataModule1->OutputOblikQuery->Close();
				DataModule1->OutputOblikQuery->SQL->Clear();
				DataModule1->OutputOblikQuery->SQL->Add("SELECT count(1) as cnt from oblikserv where idObl = '"+idObl+"'");
				DataModule1->OutputOblikQuery->Open();

				if(DataModule1->OutputOblikQuery->FieldByName("cnt")->Value >= 1)
				{
					DBGrid7->Visible = true;
					Label9->Visible = true;
					DataModule1->showServ->Close();
					DataModule1->showServ->SQL->Clear();
					DataModule1->showServ->SQL->Add("select * from services where idServ in (select idServ from oblikserv where idObl= '"+idObl+"')");
					DataModule1->showServ->Open();
				 }else{
					Label9->Visible = false;
					DBGrid7->Visible = false;
				 }

				 //search for id of tariff
				DataModule1->OutputOblikQuery->Close();
				DataModule1->OutputOblikQuery->SQL->Clear();
				DataModule1->OutputOblikQuery->SQL->Add("select idT from oblik where idObl = '"+idObl+"'");
				DataModule1->OutputOblikQuery->Open();

				Label10->Visible = true;
				DBGrid8->Visible = true;

				DataModule1->tarifQuery->Close();
				DataModule1->tarifQuery->SQL->Clear();
				DataModule1->tarifQuery->SQL->Add("select * from tariff where idT = '"+(DataModule1->OutputOblikQuery->FieldByName("idT")->AsString)+"'");
				DataModule1->tarifQuery->Open();

			}else
			{
			  ShowMessage("Такого клієнта немає у базі!");
			  DataModule1->EditQuery->Close();
			  DataModule1->EditQuery->SQL->Clear();
			  DataModule1->EditQuery->SQL->Add("select * from client");
			  DataModule1->EditQuery->Open();

			  DBGrid8->Visible = false;
			  Label10->Visible = false;
			  DBGrid7->Visible = false;
			  Label9->Visible = false;
			  DBGrid5->Visible = false;
			  Label7->Visible = false;
			}
        }
}
//---------------------------------------------------------------------------

void __fastcall TsearchClientForm::FormHide(TObject *Sender)
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



void __fastcall TsearchClientForm::PageControl1Change(TObject *Sender)
{
    	//show all clients
		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("Select * from client");
		DataModule1->EditQuery->Open();

		MaskEdit2->Clear();
		Edit1->Clear();

		DBGrid8->Visible = false;
		Label10->Visible = false;
		DBGrid7->Visible = false;
		Label9->Visible = false;
		DBGrid5->Visible = false;
		Label7->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TsearchClientForm::Button3Click(TObject *Sender)
{
	Edit1->Clear();
	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("select * from client");
	DataModule1->EditQuery->Open();
}
//---------------------------------------------------------------------------

void __fastcall TsearchClientForm::Button4Click(TObject *Sender)
{
   		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("Select * from client");
		DataModule1->EditQuery->Open();

        MaskEdit2->Clear();
		DBGrid8->Visible = false;
		Label10->Visible = false;
		DBGrid7->Visible = false;
		Label9->Visible = false;
		DBGrid5->Visible = false;
		Label7->Visible = false;
}
//---------------------------------------------------------------------------

