//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("maintainDB\workingWithDB\showDB\searchOblik\searchOblik.cpp", searchOblForm);
USEFORM("maintainDB\workingWithDB\showDB\showDB.cpp", viewDB);
USEFORM("maintainDB\workingWithDB\showDB\searchClient\searchClient.cpp", searchClientForm);
USEFORM("DataModule.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("mainForm\mainForm.cpp", mainFormm);
USEFORM("maintainDB\workingWithDB\addDB\addingDB.cpp", AddFormm);
USEFORM("maintainDB\workingWithDB\editDB\editDB.cpp", EditForm);
USEFORM("maintainDB\workingWithDB\zvit\Report.cpp", repForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
		Application->CreateForm(__classid(TmainFormm), &mainFormm);
		Application->CreateForm(__classid(TAddFormm), &AddFormm);
		Application->CreateForm(__classid(TEditForm), &EditForm);
		Application->CreateForm(__classid(TviewDB), &viewDB);
		Application->CreateForm(__classid(TsearchOblForm), &searchOblForm);
		Application->CreateForm(__classid(TsearchClientForm), &searchClientForm);
		Application->CreateForm(__classid(TrepForm), &repForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
