object viewDB: TviewDB
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1055#1077#1088#1077#1075#1083#1103#1076' '#1076#1072#1085#1080#1093
  ClientHeight = 746
  ClientWidth = 894
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 46
    Top = 30
    Width = 47
    Height = 23
    Caption = #1054#1073#1083#1110#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 46
    Top = 358
    Width = 71
    Height = 23
    Caption = #1055#1086#1089#1083#1091#1075#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 391
    Top = 30
    Width = 55
    Height = 23
    Caption = #1050#1083#1110#1108#1085#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 46
    Top = 551
    Width = 57
    Height = 23
    Caption = #1058#1072#1088#1080#1092
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 32
    Top = 59
    Width = 337
    Height = 264
    DataSource = DataModule1.showMainDB
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'idObl'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'phoneNum'
        Title.Caption = #1053#1086#1084#1077#1088
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'subsContrFlag'
        Title.Caption = #1050#1086#1085#1090#1088#1072#1082#1090
        Width = 53
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'dateOfConn'
        Title.Caption = #1044#1072#1090#1072' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'idT'
        Title.Caption = #1058#1072#1088#1080#1092
        Width = 36
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'idCl'
        Title.Caption = #1050#1083#1110#1108#1085#1090
        Width = 36
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 32
    Top = 387
    Width = 546
    Height = 158
    DataSource = DataModule1.showServices
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnTitleClick = DBGrid2TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'idServ'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'nameServ'
        Title.Caption = #1053#1072#1079#1074#1072' '#1087#1086#1089#1083#1091#1075#1080
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'priceServ'
        Title.Caption = #1062#1110#1085#1072
        Width = 40
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'description'
        Title.Caption = #1054#1087#1080#1089
        Visible = True
      end>
  end
  object DBGrid3: TDBGrid
    Left = 375
    Top = 59
    Width = 424
    Height = 264
    DataSource = DataModule1.showClient
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnTitleClick = DBGrid3TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'idCl'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'surName'
        Title.Caption = #1055#1088#1110#1079#1074#1080#1097#1077
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'name'
        Title.Caption = #1030#1084#39#1103
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'patr'
        Title.Caption = #1055#1086' '#1073#1072#1090#1100#1082#1086#1074#1110
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'passpData'
        Title.Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1072
        Visible = True
      end>
  end
  object closeBtn: TButton
    Left = 824
    Top = 24
    Width = 41
    Height = 39
    Caption = 'X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = closeBtnClick
  end
  object DBGrid4: TDBGrid
    Left = 32
    Top = 580
    Width = 546
    Height = 158
    DataSource = DataModule1.showTariff
    ReadOnly = True
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnTitleClick = DBGrid4TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'idT'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'nameT'
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1079#1074#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'priceT'
        Title.Alignment = taCenter
        Title.Caption = #1062#1110#1085#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'numOfGB'
        Title.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1043#1041
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'numOfSMS'
        Title.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1057#1052#1057
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'UAPhoneMin'
        Title.Caption = #1061#1074#1080#1083#1080#1085' '#1087#1086' '#1059#1082#1088#1072#1111#1085#1110
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'fgnPhoneMin'
        Title.Caption = #1061#1074#1080#1083#1080#1085' '#1079#1072' '#1082#1086#1088#1076#1086#1085
        Visible = True
      end>
  end
  object MainMenu1: TMainMenu
    Left = 808
    Top = 680
    object test1: TMenuItem
      Caption = #1055#1086#1096#1091#1082' '#1086#1073#1083#1110#1082#1091
      OnClick = test1Click
    end
    object N1: TMenuItem
      Caption = #1055#1086#1096#1091#1082' '#1082#1083#1110#1108#1085#1090#1072
      OnClick = N1Click
    end
  end
end
