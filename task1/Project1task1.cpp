//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\Unit1.cpp", startForm);
USEFORM("..\mainForm\mainForm.cpp", mainFormm);
USEFORM("..\maintainDB\maintain.cpp", maintainForm);
USEFORM("..\maintainDB\workingWithDB\addDB\addingDB.cpp", addDB);
USEFORM("..\maintainDB\workingWithDB\editDB\editDB.cpp", editForm);
USEFORM("..\maintainDB\workingWithDB\removeDB\removeDB.cpp", delForm);
USEFORM("task1.cpp", task1Form);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TstartForm), &startForm);
		Application->CreateForm(__classid(TmainFormm), &mainFormm);
		Application->CreateForm(__classid(TmaintainForm), &maintainForm);
		Application->CreateForm(__classid(TaddDB), &addDB);
		Application->CreateForm(__classid(TeditForm), &editForm);
		Application->CreateForm(__classid(TdelForm), &delForm);
		Application->CreateForm(__classid(Ttask1Form), &task1Form);
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
