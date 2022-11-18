object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 436
  Width = 548
  object EditDS: TDataSource
    DataSet = EditQuery
    Left = 334
    Top = 56
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Password=321321;Persist Security Info=True;Us' +
      'er ID=root;Extended Properties="DSN=PhoneProjectDB;DESCRIPTION=n' +
      'one;SERVER=localhost;UID=root;PWD=321321;DATABASE=phoneprojectmv' +
      ';PORT=3306";Initial Catalog=phoneprojectmv'
    LoginPrompt = False
    Mode = cmReadWrite
    Left = 14
    Top = 177
  end
  object FindLastClientQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      '')
    Left = 188
    Top = 12
  end
  object OutputOblikQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    Left = 188
    Top = 68
  end
  object showMainDB: TDataSource
    DataSet = showQuery
    Left = 332
    Top = 108
  end
  object ADODataSet1: TADODataSet
    Connection = ADOConnection1
    CursorType = ctStatic
    CommandText = 'select nameT from tariff'
    Parameters = <>
    Left = 100
    Top = 228
    object ADODataSet1nameT: TStringField
      FieldName = 'nameT'
      Size = 45
    end
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'tariff'
    Left = 104
    Top = 128
    object ADOTable1nameT: TStringField
      FieldName = 'nameT'
      Size = 45
    end
  end
  object EditQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from oblik ;')
    Left = 188
    Top = 124
  end
  object showQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from oblik')
    Left = 192
    Top = 184
  end
  object showClient: TDataSource
    DataSet = showClientQuery
    Left = 332
    Top = 164
  end
  object showServices: TDataSource
    DataSet = showServ
    Left = 332
    Top = 212
  end
  object showClientQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from client;')
    Left = 192
    Top = 232
  end
  object tarifQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from tariff'
      ';')
    Left = 192
    Top = 288
  end
  object showTariff: TDataSource
    DataSet = tarifQuery
    Left = 332
    Top = 268
  end
  object showServ: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from services;')
    Left = 192
    Top = 344
  end
  object reportDS: TDataSource
    DataSet = reportQuery
    Left = 332
    Top = 316
  end
  object reportQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'select count(1) as num, tariff.nameT as test from oblik, tariff ' +
        'where (oblik.idT = tariff.idT) and (oblik.dateOfConn between '#39'20' +
        '22-03-01'#39' and '#39'2022-10-30'#39') group by tariff.nameT')
    Left = 192
    Top = 400
  end
end
