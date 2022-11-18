object AddFormm: TAddFormm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103' '#1076#1072#1085#1080#1093
  ClientHeight = 569
  ClientWidth = 776
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 48
    Top = 38
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
    Left = 48
    Top = 122
    Width = 92
    Height = 32
    Caption = #1042#1080#1073#1077#1088#1110#1090#1100' '#1087#1072#1082#1077#1090' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label4: TLabel
    Left = 320
    Top = 63
    Width = 154
    Height = 32
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1086#1089#1086#1073#1080#1089#1090#1110' '#1076#1072#1085#1110' '#1076#1083#1103' '#1091#1082#1083#1072#1076#1077#1085#1085#1103' '#1082#1086#1085#1090#1088#1072#1082#1090#1091
    Visible = False
    WordWrap = True
  end
  object Label5: TLabel
    Left = 320
    Top = 117
    Width = 61
    Height = 16
    Caption = #1055#1088#1110#1079#1074#1080#1097#1077':'
    Visible = False
    WordWrap = True
  end
  object Label6: TLabel
    Left = 322
    Top = 157
    Width = 27
    Height = 16
    Caption = #1030#1084#39#1103':'
    Visible = False
    WordWrap = True
  end
  object Label7: TLabel
    Left = 320
    Top = 186
    Width = 55
    Height = 32
    Caption = #1055#1086' '#1073#1072#1090#1100#1082#1086#1074#1110':'
    Visible = False
    WordWrap = True
  end
  object Label8: TLabel
    Left = 320
    Top = 234
    Width = 59
    Height = 32
    Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1072':'
    Visible = False
    WordWrap = True
  end
  object Label10: TLabel
    Left = 254
    Top = 356
    Width = 113
    Height = 16
    Caption = #1044#1072#1090#1072' '#1087#1110#1076#1082#1083#1102#1095#1077#1085#1085#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label3: TLabel
    Left = 56
    Top = 356
    Width = 51
    Height = 16
    Caption = #1055#1086#1089#1083#1091#1075#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object MaskEdit1: TMaskEdit
    Left = 48
    Top = 60
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
  object ComboBox1: TComboBox
    Left = 48
    Top = 163
    Width = 145
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = #1054#1073#1077#1088#1110#1090#1100' '#1090#1072#1088#1080#1092
  end
  object Edit1: TEdit
    Left = 392
    Top = 114
    Width = 121
    Height = 24
    TabOrder = 2
    Visible = False
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 392
    Top = 154
    Width = 121
    Height = 24
    TabOrder = 3
    Visible = False
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 392
    Top = 194
    Width = 121
    Height = 24
    TabOrder = 4
    Visible = False
    OnKeyPress = Edit3KeyPress
  end
  object MaskEdit2: TMaskEdit
    Left = 392
    Top = 242
    Width = 73
    Height = 24
    EditMask = '!999999999;1;_'
    MaxLength = 9
    TabOrder = 5
    Text = '         '
    Visible = False
  end
  object Button1: TButton
    Left = 608
    Top = 432
    Width = 121
    Height = 59
    Caption = #1044#1086#1076#1072#1090#1080
    TabOrder = 6
    OnClick = Button1Click
  end
  object closeBtn: TButton
    Left = 720
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
    TabOrder = 7
    OnClick = closeBtnClick
  end
  object CheckListBox1: TCheckListBox
    Left = 48
    Top = 385
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
  end
  object RadioGroup1: TRadioGroup
    Left = 48
    Top = 234
    Width = 145
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
    WordWrap = True
    OnClick = RadioGroup1Click
  end
  object MonthCalendar1: TMonthCalendar
    Left = 245
    Top = 385
    Width = 324
    Height = 160
    Date = 44853.000000000000000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
end
