//---------------------------------------------------------------------------

#ifndef DataModuleH
#define DataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *EditDS;
	TADOConnection *ADOConnection1;
	TADOQuery *FindLastClientQuery;
	TADOQuery *OutputOblikQuery;
	TDataSource *showMainDB;
	TADODataSet *ADODataSet1;
	TADOTable *ADOTable1;
	TStringField *ADODataSet1nameT;
	TStringField *ADOTable1nameT;
	TADOQuery *EditQuery;
	TADOQuery *showQuery;
	TDataSource *showClient;
	TDataSource *showServices;
	TADOQuery *showClientQuery;
	TADOQuery *tarifQuery;
	TDataSource *showTariff;
	TADOQuery *showServ;
	TDataSource *reportDS;
	TADOQuery *reportQuery;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
