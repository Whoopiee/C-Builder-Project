//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "addingDB.h"
#include "mainForm.h"
#include "DataModule.h"
#include <string>
#include <algorithm>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TAddFormm *AddFormm;
//---------------------------------------------------------------------------
__fastcall TAddFormm::TAddFormm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

AnsiString singleQuote(AnsiString str, const string& from, const string &to)
{
  string Sstr = AnsiString(str).c_str();
size_t start_pos = 0;
	while((start_pos = Sstr.find(from, start_pos)) != std::string::npos) {
		Sstr.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}

	AnsiString complStr = Sstr.c_str();
    return complStr;
}

AnsiString TAddFormm::convertDate(String date){

	string middleDate = AnsiString(date).c_str();
 int pos = 0;
 string year, month, day, completeString;
   day = middleDate.substr(0,2);
   month = middleDate.substr(3,2);
   year = middleDate.substr(6,4);
	completeString = ""+year+"-"+month+"-"+day+"";
AnsiString newDate = completeString.c_str();
  return newDate;
}

void __fastcall TAddFormm::closeBtnClick(TObject *Sender)
{
  mainFormm->Enabled = true;
  AddFormm->Hide();
  AddFormm->Enabled = false;
}

void __fastcall TAddFormm::Button1Click(TObject *Sender)
{
	AnsiString lastClient, lastOblik, test;

	if(MaskEdit1->Text == "(   )       ")
	{
		ShowMessage("Не введено номер телефона!");
	}else if(MaskEdit1->Text != "(   )       ")
	{
		//check for existing number
		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->Close();
		DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from oblik where phoneNum = '"+MaskEdit1->Text+"'");
		DataModule1->FindLastClientQuery->Open();

		if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >= 1)
		{
			ShowMessage("Користувач з даним номером телефону існує, перейдіть до вкладки Ведення - Редагування");
		}
		else
		{
			if(ComboBox1->ItemIndex == -1)
			{
				ShowMessage("Не обрано тариф!");
			}else
		{

		switch(RadioGroup1->ItemIndex){

		case 0:

			if(Edit1->Text == ""){ShowMessage("Введіть Прізвище"); break;}
		else if(Edit2->Text == ""){ShowMessage("Введіть Ім'я");break;}
		else if(Edit3->Text == ""){ShowMessage("Введіть По батькові");break;}
		else if(MaskEdit2->Text == "         "){ShowMessage("Введіть Номер паспорта");break;}
		else
		{
			DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from client where passpData = '"+(MaskEdit2->Text)+"'");
			DataModule1->FindLastClientQuery->Open();

		   if(DataModule1->FindLastClientQuery->FieldByName("cnt")->AsInteger >= 1){
            ShowMessage("Клієнт з таким номером паспорта вже існує!");
		   }
		   else{


			  //create client
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO client (idCl, surName, name, patr, passpData) VALUES ('0',  '"+(singleQuote(Edit1->Text, string("'"), string("''")))+"', '"+(singleQuote(Edit2->Text, string("'"), string("''")))+"',  '"+(singleQuote(Edit3->Text, string("'"), string("''")))+"',  '"+MaskEdit2->Text+"')");
			DataModule1->FindLastClientQuery->ExecSQL();

			//find id of last inserted client
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT idCl as last FROM client ORDER BY idCl DESC LIMIT 1");
			DataModule1->FindLastClientQuery->Open();
			lastClient = DataModule1->FindLastClientQuery->FieldByName("last")->Value;

			//create oblik
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO oblik (idObl, phoneNum, subsContrFlag, dateOfConn, idT, idCl) VALUES ('0',  '"+MaskEdit1->Text+"', '"+RadioGroup1->ItemIndex+"',  '"+convertDate(DateToStr(MonthCalendar1->Date))+"',  '"+(ComboBox1->ItemIndex+1)+"', '"+lastClient+"')");
			DataModule1->FindLastClientQuery->ExecSQL();

			//insert services
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT idObl as last FROM oblik ORDER BY idObl DESC LIMIT 1");
			DataModule1->FindLastClientQuery->Open();
			lastOblik = DataModule1->FindLastClientQuery->FieldByName("last")->Value;

			for(int i = 0; i<CheckListBox1->Items->Count; i++)
			{
				if(CheckListBox1->Checked[i] == true)
				{
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO oblikserv (idObl, idServ) VALUES ('"+lastOblik+"', '"+(i+1)+"')");
					DataModule1-> FindLastClientQuery->ExecSQL();
				}
			}
            ShowMessage("Додавання успішне!");
            }
		break;
		}
		case 1:


			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO oblik (idObl, phoneNum, subsContrFlag, dateOfConn, idT, idCl) VALUES ('0',  '"+MaskEdit1->Text+"', "+RadioGroup1->ItemIndex+",  '"+convertDate(DateToStr(MonthCalendar1->Date))+"',  '"+(ComboBox1->ItemIndex+1)+"', NULL)");
			DataModule1->FindLastClientQuery->ExecSQL();

			//insert services
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT idObl as last FROM oblik ORDER BY idObl DESC LIMIT 1");
			DataModule1->FindLastClientQuery->Open();
			lastOblik = DataModule1->FindLastClientQuery->FieldByName("last")->Value;
			for(int i = 0; i<CheckListBox1->Items->Count; i++)
			{
				if(CheckListBox1->Checked[i] == true)
				{
				DataModule1->FindLastClientQuery->SQL->Clear();
				DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO oblikserv (idObl, idServ) VALUES ('"+lastOblik+"', '"+(i+1)+"')");
				DataModule1->FindLastClientQuery->ExecSQL();
				}
			}
             ShowMessage("Додавання успішне!");
		break;

		default:
			ShowMessage("Не обрано Контракт чи Передплата!");
		break;

		}
	}
		}
	}

//---------------------------------------------------------------------------
}



void __fastcall TAddFormm::RadioGroup1Click(TObject *Sender)
{

switch(RadioGroup1->ItemIndex)
{
	case 0:

		Label4->Visible = true;
		Label5->Visible = true;
		Label6->Visible = true;
		Label7->Visible = true;
		Label8->Visible = true;

		Edit1->Visible = true;
		Edit2->Visible = true;
		Edit3->Visible = true;

		MaskEdit2->Visible = true;
        break;
	case 1:

		Label4->Visible = false;
		Label5->Visible = false;
		Label6->Visible = false;
		Label7->Visible = false;
		Label8->Visible = false;

		Edit1->Visible = false;
		Edit2->Visible = false;
		Edit3->Visible = false;

		MaskEdit2->Visible = false;

	break;
}
}
//---------------------------------------------------------------------------






void __fastcall TAddFormm::FormShow(TObject *Sender)
{

//add tariffs to ComboBox from DB
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("select nameT from tariff");
	DataModule1->OutputOblikQuery->Open();
	DataModule1->OutputOblikQuery->First();

	while(!DataModule1->OutputOblikQuery->Eof)
	{
	 ComboBox1->Items->Add(DataModule1->OutputOblikQuery->FieldByName("nameT")->AsString);
	 DataModule1->OutputOblikQuery->Next();
	}

    //add services to CheckListBox from DB
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("select nameServ from services");
	DataModule1->OutputOblikQuery->Open();
	DataModule1->OutputOblikQuery->First();

	while(!DataModule1->OutputOblikQuery->Eof)
	{
	 CheckListBox1->Items->Add(DataModule1->OutputOblikQuery->FieldByName("nameServ")->AsString);
	 DataModule1->OutputOblikQuery->Next();
	}
}
//---------------------------------------------------------------------------




void __fastcall TAddFormm::FormHide(TObject *Sender)
{
ComboBox1->Items->Clear();
CheckListBox1->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TAddFormm::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	   ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------

void __fastcall TAddFormm::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	   ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------


void __fastcall TAddFormm::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	  ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------


