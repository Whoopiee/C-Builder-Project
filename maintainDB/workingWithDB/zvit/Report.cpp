//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Report.h"
#include "addingDB.h"
#include "DataModule.h"
#include "mainForm.h"
#include <string>
#include <vector>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepForm *repForm;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TrepForm::TrepForm(TComponent* Owner)
	: TForm(Owner)
{

}

int * dateArray(String date)
{
   string middleDate = AnsiString(date).c_str();
   static int arr[3];

   int year, month, day, completeString;
   arr[0] = stoi(middleDate.substr(0,2));
   arr[1] = stoi(middleDate.substr(3,2));
   arr[2] = stoi(middleDate.substr(6,4));

   return arr;
}

//---------------------------------------------------------------------------
void __fastcall TrepForm::Button1Click(TObject *Sender)
{
	//checking for the wanted records
	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("select count(1) as cnt from oblik where dateOfConn between '"+(AddFormm->convertDate(DateToStr(DatePicker1->Date)))+"' and '"+(AddFormm->convertDate(DateToStr(DatePicker2->Date)))+"'");
	DataModule1->OutputOblikQuery->Open();
	if(DataModule1->OutputOblikQuery->FieldByName("cnt")->AsInteger>0)
	{

		DBGrid2->Visible = true;
		Label4->Visible = true;

		DataModule1->reportQuery->Close();
		DataModule1->reportQuery->SQL->Clear();
		DataModule1->reportQuery->SQL->Add("select count(1) as num, tariff.nameT as test from oblik, tariff where (oblik.idT = tariff.idT) and (oblik.dateOfConn between '"+(AddFormm->convertDate(DateToStr(DatePicker1->Date)))+"' and '"+(AddFormm->convertDate(DateToStr(DatePicker2->Date)))+"') group by tariff.nameT");
		DataModule1->reportQuery->Open();
		DataModule1->reportQuery->First();
		Memo1->Clear();
		Memo1->Lines->Add("<table><tr><th> Звіт по тарифам в період між "+(DateToStr(DatePicker1->Date))+" та "+(DateToStr(DatePicker2->Date))+" </th></tr>");
		Memo1->Lines->Add("<tr><td><b>Кількість</b></td>  <td><b>Назва тарифу</b></td></tr>");
		while(!DataModule1->reportQuery->Eof)
		{
			 Memo1->Lines->Add("<tr><td>"+DataModule1->reportQuery->FieldByName("num")->AsString+"</td> <td> "+DataModule1->reportQuery->FieldByName("test")->AsString+"</td></tr>");
			 DataModule1->reportQuery->Next();
		}
		Memo1->Lines->Add("</table>");
		if(SaveDialog1->Execute())
		{
			Memo1->Lines->SaveToFile(SaveDialog1->FileName);
			WebBrowser1->Navigate(ExpandFileName(ExtractFilePath(ParamStr(0))) + "report.html");
		}
		else {
			ShowMessage("Звіт не сформовано");
		}
	}
	else{
	  	ShowMessage("В даний період не було записів!");
		DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("select * from oblik");
		DataModule1->EditQuery->Open();

		DBGrid2->Visible = false;
        Label4->Visible = false;
    }
	//OpenDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TrepForm::closeBtnClick(TObject *Sender)
{
  mainFormm->Enabled = true;
  repForm->Hide();
  repForm->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TrepForm::Button2Click(TObject *Sender)
{
	DataModule1->OutputOblikQuery->Close();
	DataModule1->OutputOblikQuery->SQL->Clear();
	DataModule1->OutputOblikQuery->SQL->Add("select count(1) as cnt from oblik where dateOfConn between '"+(AddFormm->convertDate(DateToStr(DatePicker1->Date)))+"' and '"+(AddFormm->convertDate(DateToStr(DatePicker2->Date)))+"'");
	DataModule1->OutputOblikQuery->Open();
	if(DataModule1->OutputOblikQuery->FieldByName("cnt")->AsInteger>0)
	{
        DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("select * from oblik where dateOfConn between '"+(AddFormm->convertDate(DateToStr(DatePicker1->Date)))+"' and '"+(AddFormm->convertDate(DateToStr(DatePicker2->Date)))+"'");
		DataModule1->EditQuery->Open();

		DBGrid2->Visible = true;
		Label4->Visible = true;

		DataModule1->reportQuery->Close();
		DataModule1->reportQuery->SQL->Clear();
		DataModule1->reportQuery->SQL->Add("select count(1) as num, tariff.nameT as test from oblik, tariff where (oblik.idT = tariff.idT) and (oblik.dateOfConn between '"+(AddFormm->convertDate(DateToStr(DatePicker1->Date)))+"' and '"+(AddFormm->convertDate(DateToStr(DatePicker2->Date)))+"') group by tariff.nameT");
		DataModule1->reportQuery->Open();
	}
	else
	{
	  ShowMessage("В даний період не було записів!");
	  DataModule1->EditQuery->Close();
	  DataModule1->EditQuery->SQL->Clear();
	  DataModule1->EditQuery->SQL->Add("select * from oblik");
	  DataModule1->EditQuery->Open();

	  DBGrid2->Visible = false;
	  Label4->Visible = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepForm::FormShow(TObject *Sender)
{
		DBGrid2->Visible = false;
		Label4->Visible = false;

        DataModule1->EditQuery->Close();
		DataModule1->EditQuery->SQL->Clear();
		DataModule1->EditQuery->SQL->Add("select * from oblik");
		DataModule1->EditQuery->Open();
}
//---------------------------------------------------------------------------


