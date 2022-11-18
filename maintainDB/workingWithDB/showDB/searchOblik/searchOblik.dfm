object searchOblForm: TsearchOblForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1055#1086#1096#1091#1082' '#1086#1073#1083#1110#1082#1086#1074#1086#1075#1086' '#1079#1072#1087#1080#1089#1091
  ClientHeight = 499
  ClientWidth = 960
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 31
    Width = 150
    Height = 16
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 107
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
  object Label4: TLabel
    Left = 16
    Top = 325
    Width = 55
    Height = 23
    Caption = #1050#1083#1110#1108#1085#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 465
    Top = 325
    Width = 71
    Height = 23
    Caption = #1055#1086#1089#1083#1091#1075#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label5: TLabel
    Left = 465
    Top = 107
    Width = 57
    Height = 23
    Caption = #1058#1072#1088#1080#1092
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object MaskEdit1: TMaskEdit
    Left = 16
    Top = 57
    Width = 111
    Height = 24
    EditMask = '!(000)0000000;1;_'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 12
    ParentFont = False
    TabOrder = 0
    Text = '(   )       '
  end
  object Button2: TButton
    Left = 168
    Top = 53
    Width = 75
    Height = 28
    Caption = #1055#1086#1096#1091#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 136
    Width = 424
    Height = 159
    DataSource = DataModule1.showMainDB
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'idObl'
        Title.Alignment = taCenter
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'phoneNum'
        Title.Alignment = taCenter
        Title.Caption = #1053#1086#1084#1077#1088
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'subsContrFlag'
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1085#1090#1088#1072#1082#1090
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'dateOfConn'
        Title.Alignment = taCenter
        Title.Caption = #1044#1072#1090#1072' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'idT'
        Title.Alignment = taCenter
        Title.Caption = #1058#1072#1088#1080#1092
        Width = 75
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'idCl'
        Title.Alignment = taCenter
        Title.Caption = #1050#1083#1110#1108#1085#1090
        Width = 36
        Visible = True
      end>
  end
  object DBGrid3: TDBGrid
    Left = 16
    Top = 354
    Width = 424
    Height = 137
    DataSource = DataModule1.showClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Visible = False
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
    Left = 911
    Top = 8
    Width = 41
    Height = 39
    Caption = 'X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = closeBtnClick
  end
  object DBGrid2: TDBGrid
    Left = 465
    Top = 354
    Width = 424
    Height = 137
    DataSource = DataModule1.showServices
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Visible = False
    Columns = <
      item
        Expanded = False
        FieldName = 'idServ'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'nameServ'
        Title.Alignment = taCenter
        Title.Caption = #1053#1072#1079#1074#1072
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'priceServ'
        Title.Alignment = taCenter
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
  object DBGrid4: TDBGrid
    Left = 465
    Top = 136
    Width = 424
    Height = 157
    DataSource = DataModule1.showTariff
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Visible = False
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
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'priceT'
        Title.Alignment = taCenter
        Title.Caption = #1062#1110#1085#1072
        Width = 40
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
  object Button1: TButton
    Left = 272
    Top = 53
    Width = 75
    Height = 28
    Caption = #1057#1073#1088#1086#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button1Click
  end
end
