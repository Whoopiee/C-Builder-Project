//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "addingDB.h"
#include "editDB.h"
#include "mainForm.h"
#include "DataModule.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditForm *EditForm;

bool dataCheck = false;
//---------------------------------------------------------------------------
__fastcall TEditForm::TEditForm(TComponent* Owner)
	: TForm(Owner)
{
		

}
//---------------------------------------------------------------------------

void __fastcall TEditForm::closeBtnClick(TObject *Sender)
{
//closing form
  mainFormm->Enabled = true;
  EditForm->Hide();
  EditForm->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TEditForm::RadioGroup1Click(TObject *Sender)
{
//changing visible options of elements depending on Contract or Subscription
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

		MaskEdit3->Visible = true;
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

		MaskEdit3->Visible = false;

	break;
}
}
//---------------------------------------------------------------------------


void __fastcall TEditForm::Button2Click(TObject *Sender)
{

	//clear elements of the form
	ComboBox1->Items->Clear();
	CheckListBox1->Items->Clear();

	AnsiString oblikId, clientId; //id of oblik

	//add tariffs to ComboBox from DB
	DataModule1->OutputOblikQuery->Close();
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
	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("select nameServ from services");
	DataModule1->OutputOblikQuery->Open();
	DataModule1->OutputOblikQuery->First();

	while(!DataModule1->OutputOblikQuery->Eof)
	{
	 CheckListBox1->Items->Add(DataModule1->OutputOblikQuery->FieldByName("nameServ")->AsString);
	 DataModule1->OutputOblikQuery->Next();
	}

	//check for existing phone number
	DataModule1->FindLastClientQuery->SQL->Clear();
	DataModule1->FindLastClientQuery->Close();
	DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from oblik where phoneNum = '"+MaskEdit1->Text+"'");
	DataModule1->FindLastClientQuery->Open();

	if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >= 1)
	{
		Label3->Visible = true;
		Label9->Visible = true;
		Label10->Visible = true;

		MonthCalendar1->Visible = true;
		ComboBox1->Visible = true;
		RadioGroup1->Visible = true;
        CheckListBox1->Visible = true;

		Label2->Caption = "Дані за введеним номером:";

		//show all from searched phone number
		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("select * from oblik where phoneNum = '"+MaskEdit1->Text+"'");
		DataModule1->EditQuery->Open();

        //get id of selected phone number
		DataModule1->OutputOblikQuery->Close();
		DataModule1->OutputOblikQuery->SQL->Clear();
		DataModule1->OutputOblikQuery->SQL->Add("SELECT idObl from oblik where phoneNum = '"+MaskEdit1->Text+"'");
		DataModule1->OutputOblikQuery->Open();
		oblikId = DataModule1->OutputOblikQuery->FieldByName("idObl")->Value;

		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->Close();
		DataModule1->FindLastClientQuery->SQL->Add("SELECT idCl from oblik where idObl = '"+oblikId+"'");
		DataModule1->FindLastClientQuery->Open();

		clientId = DataModule1->FindLastClientQuery->FieldByName("idCl")->AsString;

		if(clientId != "")
		{
			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->Close();
			DataModule1->FindLastClientQuery->SQL->Add("SELECT * from client where idCl = '"+clientId+"'");
			DataModule1->FindLastClientQuery->Open();

			Edit1->TextHint = ""+(DataModule1->FindLastClientQuery->FieldByName("surName")->AsString)+"";
			Edit2->TextHint = ""+(DataModule1->FindLastClientQuery->FieldByName("name")->AsString)+"";
			Edit3->TextHint = ""+(DataModule1->FindLastClientQuery->FieldByName("patr")->AsString)+"";
			MaskEdit3->Text = ""+(DataModule1->FindLastClientQuery->FieldByName("passpData")->AsString)+"";
		}else
		{
		  Edit1->TextHint = "";
		  Edit2->TextHint = "";
		  Edit3->TextHint = "";
          MaskEdit3->Text = "         ";
        }

		int id; //id of service

        //find all services of that phone number and fill the CheckListBox
		DataModule1->OutputOblikQuery->Close();
		DataModule1->OutputOblikQuery->SQL->Clear();
		DataModule1->OutputOblikQuery->SQL->Add("SELECT idServ id from oblikserv where idObl = '"+oblikId+"'");
		DataModule1->OutputOblikQuery->Open();
		DataModule1->OutputOblikQuery->First();

		while(!DataModule1->OutputOblikQuery->Eof)
		{
			id = DataModule1->OutputOblikQuery->FieldByName("id")->AsInteger;
			CheckListBox1->Checked[id-1] = true;
			DataModule1->OutputOblikQuery->Next();
		}

    //change visible option if phone never exist
	}else{
		ShowMessage("Такого номеру немає у базі даних!");

        ComboBox1->Items->Clear();
		CheckListBox1->Items->Clear();

		Label3->Visible = false;
		Label9->Visible = false;

		ComboBox1->Visible = false;
		RadioGroup1->Visible = false;
		CheckListBox1->Visible = false;
        Button1->Visible = false;

		Label2->Caption = "Дані про облік:";
		MonthCalendar1->Visible = false;

		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("Select * from oblik");
		DataModule1->EditQuery->Open();

		Label4->Visible = false;
		Label5->Visible = false;
		Label6->Visible = false;
		Label7->Visible = false;
		Label8->Visible = false;
        Label10->Visible = false;

		Edit1->Visible = false;
		Edit2->Visible = false;
		Edit3->Visible = false;

		MaskEdit3->Visible = false;
    }

}
//---------------------------------------------------------------------------

void __fastcall TEditForm::MaskEdit1Exit(TObject *Sender)
{
    //check for changing number while editing
	DataModule1->FindLastClientQuery->SQL->Clear();
	DataModule1->FindLastClientQuery->Close();
	DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from oblik where phoneNum = '"+MaskEdit1->Text+"'");
	DataModule1->FindLastClientQuery->Open();
	if(DataModule1->FindLastClientQuery->FieldByName("cnt")->Value >=1)
	{

		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->SQL->Add("SELECT dateOfConn as date from oblik where phoneNum = '"+MaskEdit1->Text+"'");
		DataModule1->FindLastClientQuery->Open();
		MonthCalendar1->Date = DataModule1->FindLastClientQuery->FieldByName("date")->Value;

		Label3->Visible = true;
		Label9->Visible = true;
		Label10->Visible = true;

		MonthCalendar1->Visible = true;
		ComboBox1->Visible = true;
		RadioGroup1->Visible = true;
        CheckListBox1->Visible = true;
		Button1->Visible = true;

		Label2->Caption = "Дані за введеним номером:";

	}  else{
       ShowMessage("Такого номеру немає у базі даних!");

        ComboBox1->Items->Clear();
		CheckListBox1->Items->Clear();

		Label3->Visible = false;
		Label9->Visible = false;

		ComboBox1->Visible = false;
		RadioGroup1->Visible = false;
		CheckListBox1->Visible = false;
        Button1->Visible = false;

		Label2->Caption = "Дані про облік:";

		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("Select * from oblik");
		DataModule1->EditQuery->Open();

		MonthCalendar1->Visible = false;

		Label4->Visible = false;
		Label5->Visible = false;
		Label6->Visible = false;
		Label7->Visible = false;
		Label8->Visible = false;
        Label10->Visible = false;

		Edit1->Visible = false;
		Edit2->Visible = false;
		Edit3->Visible = false;

		MaskEdit3->Visible = false;
    }
}
//---------------------------------------------------------------------------



void __fastcall TEditForm::FormHide(TObject *Sender)
{
	//hide and clear elements of the form
	ComboBox1->Items->Clear();
	CheckListBox1->Items->Clear();

	MaskEdit1->Visible = true;
	Button2->Visible = true;
	Label1->Visible = true;

	Label3->Visible = false;
	Label9->Visible = false;
	Label10->Visible = false;

	ComboBox1->Visible = false;
	RadioGroup1->Visible = false;
	CheckListBox1->Visible = false;
    Button1->Visible = false;

	Label2->Caption = "Дані про облік:";
	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("Select * from oblik");
    DataModule1->EditQuery->Open();


	MonthCalendar1->Visible = false;
    Button1->Visible = false;

	Label4->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
	Label7->Visible = false;
	Label8->Visible = false;

	Edit1->Visible = false;
	Edit2->Visible = false;
	Edit3->Visible = false;

	MaskEdit3->Visible = false;

    //clear all fields
	MaskEdit1->Clear();
	RadioGroup1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	MaskEdit3->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TEditForm::Button1Click(TObject *Sender)
{
    //editing
	AnsiString oblikId, idT, clientCheck;

	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("SELECT idObl from oblik where phoneNum = '"+MaskEdit1->Text+"'");
	DataModule1->OutputOblikQuery->Open();
	oblikId = DataModule1->OutputOblikQuery->FieldByName("idObl")->Value;


	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("SELECT count(1) as cnt from oblikserv where idObl = '"+oblikId+"'");
	DataModule1->OutputOblikQuery->Open();

	if(	DataModule1->OutputOblikQuery->FieldByName("cnt")->AsInteger>0)
	{
		//delete all services of phone number
		DataModule1->OutputOblikQuery->SQL->Clear();
		DataModule1->OutputOblikQuery->SQL->Add("DELETE from oblikserv where idObl = '"+oblikId+"'");
		DataModule1->OutputOblikQuery->ExecSQL();
	}

	//add new services to that phone number
	if(CheckListBox1->Items->Count>0)
	{
		for(int i = 0; i<CheckListBox1->Items->Count; i++)
				{
					if(CheckListBox1->Checked[i] == true)
					{
						DataModule1->OutputOblikQuery->SQL->Clear();
						DataModule1->OutputOblikQuery->SQL->Add("INSERT INTO oblikserv (idObl, idServ) VALUES ('"+oblikId+"', '"+(i+1)+"')");
						DataModule1->OutputOblikQuery->ExecSQL();
					}
				}
	}

    //update date of connection
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("UPDATE oblik set dateOfConn = '"+AddFormm->convertDate(DateToStr(MonthCalendar1->Date))+"' WHERE idObl = '"+oblikId+"'");
	DataModule1->OutputOblikQuery->ExecSQL();

    //update tariff
	if(ComboBox1->ItemIndex!=-1)
	{
        idT = ComboBox1->ItemIndex+1;
		DataModule1->OutputOblikQuery->SQL->Clear();
		DataModule1->OutputOblikQuery->SQL->Add("UPDATE oblik set idT = '"+idT+"' WHERE idObl = '"+oblikId+"'");
		DataModule1->OutputOblikQuery->ExecSQL();
	}

    //find client id
	DataModule1->FindLastClientQuery->Close();
	DataModule1->FindLastClientQuery->SQL->Clear();
	DataModule1->FindLastClientQuery->SQL->Add("SELECT idCl from oblik where idObl = '"+oblikId+"'");
	DataModule1->FindLastClientQuery->Open();

	clientCheck = DataModule1->FindLastClientQuery->FieldByName("idCL")->AsString;

	switch(RadioGroup1->ItemIndex){

		case 0:
         if(clientCheck !="")
			{

				AnsiString passpData;
                bool done = true; //flag for checking passport data

				//find actual passport number of client
				DataModule1->FindLastClientQuery->Close();
				DataModule1->FindLastClientQuery->SQL->Clear();
				DataModule1->FindLastClientQuery->SQL->Add("SELECT passpData as data from client WHERE idCl = '"+clientCheck+"'");
				DataModule1->FindLastClientQuery->Open();

				passpData = DataModule1->FindLastClientQuery->FieldByName("data")->AsString;

				if(Edit1->Text != ""){
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("UPDATE client set surName = '"+Edit1->Text+"' WHERE idCl = '"+clientCheck+"'");
					DataModule1->FindLastClientQuery->ExecSQL();
					done = true;
				}

				if(Edit2->Text != ""){
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("UPDATE client set name = '"+Edit2->Text+"' WHERE idCl = '"+clientCheck+"'");
					DataModule1->FindLastClientQuery->ExecSQL();
					done = true;
				}

				if(Edit3->Text != ""){
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("UPDATE client set patr = '"+Edit3->Text+"' WHERE idCl = '"+clientCheck+"'");
					DataModule1->FindLastClientQuery->ExecSQL();
					done = true;
				}

				if(MaskEdit3->Text != "         "){
                	DataModule1->FindLastClientQuery->Close();
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from client where passpData = '"+(MaskEdit3->Text)+"'");
					DataModule1->FindLastClientQuery->Open();

				   if((DataModule1->FindLastClientQuery->FieldByName("cnt")->AsInteger >= 1) && (MaskEdit3->Text != passpData) ){
					ShowMessage("Клієнт з таким номером паспорта вже існує!");
					done = false;
				   }else{
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("UPDATE client set passpData = '"+MaskEdit3->Text+"' WHERE idCl = '"+clientCheck+"'");
					DataModule1->FindLastClientQuery->ExecSQL();
                    done = true;
                   }
				}
				if(done)ShowMessage("Редагування успішне!");
			}
			else
			{
				if(Edit1->Text == ""){ShowMessage("Введіть Прізвище");}
				else if(Edit2->Text == ""){ShowMessage("Введіть Ім'я");}
				else if(Edit3->Text == ""){ShowMessage("Введіть По батькові");}
				else if(MaskEdit3->Text == "         "){ShowMessage("Введіть Номер паспорта");}
				else
				{

                	DataModule1->FindLastClientQuery->Close();
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("SELECT count(1) as cnt from client where passpData = '"+(MaskEdit3->Text)+"'");
					DataModule1->FindLastClientQuery->Open();

				   if(DataModule1->FindLastClientQuery->FieldByName("cnt")->AsInteger >= 1){
					ShowMessage("Клієнт з таким номером паспорта вже існує!");
				   }else{

					  //create client
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("INSERT INTO client (idCl, surName, name, patr, passpData) VALUES ('0',  '"+Edit1->Text+"', '"+Edit2->Text+"',  '"+Edit3->Text+"',  '"+MaskEdit3->Text+"')");
					DataModule1->FindLastClientQuery->ExecSQL();

					//find id of last inserted client
					DataModule1->FindLastClientQuery->SQL->Clear();
					DataModule1->FindLastClientQuery->SQL->Add("SELECT idCl as last FROM client ORDER BY idCl DESC LIMIT 1");
					DataModule1->FindLastClientQuery->Open();
					//lastClient = DataModule1->FindLastClientQuery->FieldByName("last")->Value;

					DataModule1->OutputOblikQuery->SQL->Clear();
					DataModule1->OutputOblikQuery->SQL->Add("UPDATE oblik set idCl = '"+(DataModule1->FindLastClientQuery->FieldByName("last")->AsString)+"' WHERE idObl = '"+oblikId+"'");
					DataModule1->OutputOblikQuery->ExecSQL();
					ShowMessage("Редагування успішне!");
                   }

				}
			}

			DataModule1->FindLastClientQuery->SQL->Clear();
			DataModule1->FindLastClientQuery->SQL->Add("UPDATE oblik set subsContrFlag = '0' WHERE idObl = '"+oblikId+"'");
			DataModule1->FindLastClientQuery->ExecSQL();

		break;

		case 1:

        if(clientCheck !="")
			{
            	//delete client
				DataModule1->OutputOblikQuery->SQL->Clear();
				DataModule1->OutputOblikQuery->SQL->Add("DELETE from client where idCl = '"+clientCheck+"'");
				DataModule1->OutputOblikQuery->ExecSQL();
			}
		DataModule1->FindLastClientQuery->SQL->Clear();
		DataModule1->FindLastClientQuery->SQL->Add("UPDATE oblik set subsContrFlag = '1' WHERE idObl = '"+oblikId+"'");
		DataModule1->FindLastClientQuery->ExecSQL();
		 ShowMessage("Редагування успішне!");
		break;

		default:
		 ShowMessage("Редагування успішне!");
		break;
	}


	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("select * from oblik where phoneNum = '"+MaskEdit1->Text+"'");
	DataModule1->EditQuery->Open() ;
}
//---------------------------------------------------------------------------

//input check (avoid numbers)
void __fastcall TEditForm::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	   ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	   ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
if( ((Key>32) && (Key<39)) || ((Key>39)&&(Key<65)) || ((Key>90)&&(Key<97))|| ((Key>122)&&(Key<127)))
  {
	   Key = 0x0;
	   ShowMessage("Недопустимий знак!");
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditForm::Button3Click(TObject *Sender)
{
	//hide and clear elements of the form
	ComboBox1->Items->Clear();
	CheckListBox1->Items->Clear();

	MaskEdit1->Visible = true;
	Button2->Visible = true;
	Label1->Visible = true;

	Label3->Visible = false;
	Label9->Visible = false;
	Label10->Visible = false;

	ComboBox1->Visible = false;
	RadioGroup1->Visible = false;
	CheckListBox1->Visible = false;
    Button1->Visible = false;

	Label2->Caption = "Дані про облік:";
	MonthCalendar1->Visible = false;
	Button1->Visible = false;

	DataModule1->EditQuery->Close();
	DataModule1->EditQuery->SQL->Clear();
	DataModule1->EditQuery->SQL->Add("Select * from oblik");
    DataModule1->EditQuery->Open();

	Label4->Visible = false;
	Label5->Visible = false;
	Label6->Visible = false;
	Label7->Visible = false;
	Label8->Visible = false;

	Edit1->Visible = false;
	Edit2->Visible = false;
	Edit3->Visible = false;

	MaskEdit3->Visible = false;

    //clear all fields
	MaskEdit1->Clear();
	RadioGroup1->ItemIndex = -1;
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	MaskEdit3->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TEditForm::FormShow(TObject *Sender)
{
//changing visible options of fields
		MaskEdit1->Visible = true;
		Button2->Visible = true;
		Label1->Visible = true;

		Label3->Visible = false;
		Label9->Visible = false;
		Label10->Visible = false;

		ComboBox1->Visible = false;
		RadioGroup1->Visible = false;
		CheckListBox1->Visible = false;
		Button1->Visible = false;

		//output all olik data
		Label2->Caption = "Дані про облік:";
		MonthCalendar1->Visible = false;
		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("Select * from oblik");
		DataModule1->EditQuery->Open();

		Label4->Visible = false;
		Label5->Visible = false;
		Label6->Visible = false;
		Label7->Visible = false;
		Label8->Visible = false;

		Edit1->Visible = false;
		Edit2->Visible = false;
		Edit3->Visible = false;

		MaskEdit3->Visible = false;
}
//---------------------------------------------------------------------------

