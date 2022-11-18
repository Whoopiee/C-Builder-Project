//---------------------------------------------------------------------------

#ifndef showDBH
#define showDBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TviewDB : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TDBGrid *DBGrid3;
	TButton *closeBtn;
	TMainMenu *MainMenu1;
	TMenuItem *test1;
	TMenuItem *N1;
	TLabel *Label5;
	TDBGrid *DBGrid4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall closeBtnClick(TObject *Sender);
	void __fastcall test1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall DBGrid3TitleClick(TColumn *Column);
	void __fastcall DBGrid2TitleClick(TColumn *Column);
	void __fastcall DBGrid4TitleClick(TColumn *Column);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TviewDB(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TviewDB *viewDB;
//---------------------------------------------------------------------------
#endif
