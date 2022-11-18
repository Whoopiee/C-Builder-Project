//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "searchOblik.h"
#include "showDB.h"
#include "DataModule.h"
#include <string>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsearchOblForm *searchOblForm;
//---------------------------------------------------------------------------
__fastcall TsearchOblForm::TsearchOblForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TsearchOblForm::Button2Click(TObject *Sender)
{
    	AnsiString  clientCheck;
	AnsiString oblikId, servId;

	//check for existing phone number
	if(MaskEdit1->Text == "(   )       ")ShowMessage("Номер телефону не введено");
	else{

		DataModule1->FindLastClientQuery->Close();
		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from oblik where phoneNum = '"+MaskEdit1->Text+"'");
		DataModule1->FindLastClientQuery->Open();

		if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >= 1)
		{
			DataModule1->showQuery->Close();
			DataModule1->showQuery->SQL->Clear();
			DataModule1->showQuery->SQL->Add("SELECT * from oblik where phoneNum = '"+MaskEdit1->Text+"'");
			DataModule1->showQuery->Open();

            DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT idCl from oblik where phoneNum = '"+MaskEdit1->Text+"'");
			DataModule1->FindLastClientQuery->Open();

			clientCheck = DataModule1->FindLastClientQuery->FieldByName("idCL")->AsString;

			if(clientCheck !="")
			{
            	Label4->Visible = true;
				DBGrid3->Visible = true;
				DataModule1->showClientQuery->Close();
				DataModule1->showClientQuery->SQL->Clear();
				DataModule1->showClientQuery->SQL->Add("SELECT * from client where idCl = '"+clientCheck+"'");
				DataModule1->showClientQuery->Open();
			}
			else
			{
				Label4->Visible = false;
				DBGrid3->Visible = false;
            }

			//search for id of selected user
			DataModule1->OutputOblikQuery->Close();
			DataModule1->OutputOblikQuery->SQL->Clear();
			DataModule1->OutputOblikQuery->SQL->Add("SELECT idObl from oblik where phoneNum = '"+MaskEdit1->Text+"'");
			DataModule1->OutputOblikQuery->Open();
			oblikId = DataModule1->OutputOblikQuery->FieldByName("idObl")->Value;

            //search for services
			DataModule1->OutputOblikQuery->Close();
			DataModule1->OutputOblikQuery->SQL->Clear();
			DataModule1->OutputOblikQuery->SQL->Add("SELECT count(1) as cnt from oblikserv where idObl = '"+oblikId+"'");
			DataModule1->OutputOblikQuery->Open();

			if(DataModule1->OutputOblikQuery->FieldByName("cnt")->Value >= 1)
			{
				DBGrid2->Visible = true;
				Label3->Visible = true;
				DataModule1->showServ->Close();
				DataModule1->showServ->SQL->Clear();
				DataModule1->showServ->SQL->Add("select * from services where idServ in (select idServ from oblikserv where idObl= '"+oblikId+"')");
				DataModule1->showServ->Open();
			 }else{
				Label3->Visible = false;
				DBGrid2->Visible = false;
			 }

			DataModule1->OutputOblikQuery->Close();
			DataModule1->OutputOblikQuery->SQL->Clear();
			DataModule1->OutputOblikQuery->SQL->Add("select idT from oblik where idObl = '"+oblikId+"'");
			DataModule1->OutputOblikQuery->Open();

			Label5->Visible = true;
			DBGrid4->Visible = true;

			DataModule1->tarifQuery->Close();
			DataModule1->tarifQuery->SQL->Clear();
			DataModule1->tarifQuery->SQL->Add("select * from tariff where idT = '"+(DataModule1->OutputOblikQuery->FieldByName("idT")->AsString)+"'");
			DataModule1->tarifQuery->Open();

		}else{
			ShowMessage("Такого номера немає у базі даних!");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TsearchOblForm::closeBtnClick(TObject *Sender)
{
	viewDB->Enabled = true;
	searchOblForm->Hide();
	searchOblForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TsearchOblForm::FormShow(TObject *Sender)
{
	MaskEdit1->Clear();
	Label4->Visible = false;
	DBGrid3->Visible = false;
	Label5->Visible = false;
	DBGrid4->Visible = false;
	Label3->Visible = false;
	DBGrid2->Visible = false;

	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("SELECT * from services");
	DataModule1->EditQuery->Open();

	DataModule1->showQuery->Close();
	DataModule1->showQuery->SQL->Clear();
	DataModule1->showQuery->SQL->Add("SELECT * from oblik");
	DataModule1->showQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TsearchOblForm::Button1Click(TObject *Sender)
{
	MaskEdit1->Clear();

	Label4->Visible = false;
	DBGrid3->Visible = false;
	Label5->Visible = false;
	DBGrid4->Visible = false;
	Label3->Visible = false;
	DBGrid2->Visible = false;

	DataModule1->showQuery->Close();
	DataModule1->showQuery->SQL->Clear();
	DataModule1->showQuery->SQL->Add("SELECT * from oblik");
	DataModule1->showQuery->Open();
}
//---------------------------------------------------------------------------

