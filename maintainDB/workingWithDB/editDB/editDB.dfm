object EditForm: TEditForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103' '#1076#1072#1085#1080#1093
  ClientHeight = 766
  ClientWidth = 737
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 24
    Width = 88
    Height = 32
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1085#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1091':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label3: TLabel
    Left = 48
    Top = 117
    Width = 92
    Height = 32
    Caption = #1042#1080#1073#1077#1088#1110#1090#1100' '#1087#1072#1082#1077#1090' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label4: TLabel
    Left = 301
    Top = 212
    Width = 154
    Height = 32
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1086#1089#1086#1073#1080#1089#1090#1110' '#1076#1072#1085#1110' '#1076#1083#1103' '#1091#1082#1083#1072#1076#1077#1085#1085#1103' '#1082#1086#1085#1090#1088#1072#1082#1090#1091
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label5: TLabel
    Left = 303
    Top = 284
    Width = 61
    Height = 16
    Caption = #1055#1088#1110#1079#1074#1080#1097#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label6: TLabel
    Left = 303
    Top = 324
    Width = 27
    Height = 16
    Caption = #1030#1084#39#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label7: TLabel
    Left = 303
    Top = 361
    Width = 55
    Height = 32
    Caption = #1055#1086' '#1073#1072#1090#1100#1082#1086#1074#1110':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label8: TLabel
    Left = 303
    Top = 407
    Width = 59
    Height = 32
    Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label10: TLabel
    Left = 47
    Top = 532
    Width = 80
    Height = 32
    Caption = #1044#1072#1090#1072' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label9: TLabel
    Left = 49
    Top = 337
    Width = 51
    Height = 16
    Caption = #1055#1086#1089#1083#1091#1075#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object Label2: TLabel
    Left = 301
    Top = 24
    Width = 164
    Height = 16
    Caption = #1044#1072#1085#1110' '#1079#1072' '#1074#1074#1077#1076#1077#1085#1080#1084' '#1085#1086#1084#1077#1088#1086#1084':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object closeBtn: TButton
    Left = 672
    Top = 12
    Width = 41
    Height = 39
    Caption = 'X'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = closeBtnClick
  end
  object MaskEdit1: TMaskEdit
    Left = 49
    Top = 69
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
    TabOrder = 1
    Text = '(   )       '
    OnExit = MaskEdit1Exit
  end
  object ComboBox1: TComboBox
    Left = 48
    Top = 158
    Width = 144
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = #1054#1073#1077#1088#1110#1090#1100' '#1090#1072#1088#1080#1092
    Visible = False
  end
  object Edit1: TEdit
    Left = 373
    Top = 281
    Width = 120
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Visible = False
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 373
    Top = 321
    Width = 120
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Visible = False
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 373
    Top = 369
    Width = 120
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Visible = False
    OnKeyPress = Edit3KeyPress
  end
  object MaskEdit3: TMaskEdit
    Left = 368
    Top = 415
    Width = 73
    Height = 24
    EditMask = '!999999999;1;_'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 9
    ParentFont = False
    TabOrder = 6
    Text = '         '
    Visible = False
  end
  object Button1: TButton
    Left = 440
    Top = 617
    Width = 129
    Height = 59
    Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Visible = False
    OnClick = Button1Click
  end
  object CheckListBox1: TCheckListBox
    Left = 47
    Top = 366
    Width = 153
    Height = 148
    Margins.Top = 10
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    IntegralHeight = True
    ParentFont = False
    TabOrder = 8
    Visible = False
  end
  object RadioGroup1: TRadioGroup
    Left = 47
    Top = 212
    Width = 154
    Height = 105
    Caption = #1050#1086#1085#1090#1088#1072#1082#1090' '#1095#1080' '#1087#1077#1088#1077#1076#1087#1083#1072#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Items.Strings = (
      #1050#1086#1085#1090#1088#1072#1082#1090
      #1055#1077#1088#1077#1076#1087#1083#1072#1090#1072)
    ParentFont = False
    TabOrder = 9
    Visible = False
    WordWrap = True
    OnClick = RadioGroup1Click
  end
  object MonthCalendar1: TMonthCalendar
    Left = 39
    Top = 570
    Width = 332
    Height = 160
    Date = 44853.000000000000000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    Visible = False
  end
  object DBGrid1: TDBGrid
    Left = 301
    Top = 43
    Width = 345
    Height = 126
    DataSource = DataModule1.EditDS
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
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
        Title.Alignment = taCenter
        Title.Caption = #1053#1086#1084#1077#1088
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'subsContrFlag'
        Title.Alignment = taCenter
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
        Title.Alignment = taCenter
        Title.Caption = #1058#1072#1088#1080#1092
        Width = 36
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
  object Button2: TButton
    Left = 191
    Top = 43
    Width = 81
    Height = 30
    Caption = #1055#1086#1096#1091#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 191
    Top = 89
    Width = 81
    Height = 32
    Caption = #1057#1073#1088#1086#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button3Click
  end
end
