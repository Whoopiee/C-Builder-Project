object repForm: TrepForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1047#1074#1110#1090' '#1079#1072' '#1087#1077#1088#1110#1086#1076
  ClientHeight = 619
  ClientWidth = 825
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
    Left = 24
    Top = 21
    Width = 93
    Height = 16
    Caption = #1055#1086#1095#1072#1090#1082#1086#1074#1072' '#1076#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 94
    Width = 76
    Height = 16
    Caption = #1050#1110#1085#1094#1077#1074#1072' '#1076#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 392
    Top = 8
    Width = 53
    Height = 23
    Caption = #1054#1073#1083#1110#1082' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 392
    Top = 179
    Width = 167
    Height = 23
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1080' '#1087#1086#1096#1091#1082#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 224
    Top = 103
    Width = 97
    Height = 41
    Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080' '#1079#1074#1110#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    WordWrap = True
    OnClick = Button1Click
  end
  object DBGrid1: TDBGrid
    Left = 384
    Top = 40
    Width = 345
    Height = 133
    DataSource = DataModule1.EditDS
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
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
        Width = 76
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
  object DatePicker1: TDatePicker
    Left = 24
    Top = 40
    Date = 44867.000000000000000000
    DateFormat = 'dd/MM/yyyy'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    TabOrder = 2
  end
  object DatePicker2: TDatePicker
    Left = 24
    Top = 112
    Date = 44867.000000000000000000
    DateFormat = 'dd/MM/yyyy'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    TabOrder = 3
  end
  object closeBtn: TButton
    Left = 767
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
  object Memo1: TMemo
    Left = 767
    Top = 247
    Width = 58
    Height = 66
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
    Visible = False
  end
  object Button2: TButton
    Left = 224
    Top = 31
    Width = 97
    Height = 41
    Caption = #1055#1086#1096#1091#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    WordWrap = True
    OnClick = Button2Click
  end
  object WebBrowser1: TWebBrowser
    Left = 24
    Top = 163
    Width = 300
    Height = 342
    TabOrder = 7
    ControlData = {
      4C000000021F0000592300000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object DBGrid2: TDBGrid
    Left = 384
    Top = 208
    Width = 345
    Height = 120
    DataSource = DataModule1.reportDS
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'num'
        Title.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'test'
        Title.Caption = #1058#1072#1088#1080#1092
        Visible = True
      end>
  end
  object SaveDialog1: TSaveDialog
    FileName = 'report.html'
    Left = 792
    Top = 320
  end
  object OpenDialog1: TOpenDialog
    FileName = 'report.html'
    Left = 792
    Top = 360
  end
end
