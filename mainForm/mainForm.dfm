object mainFormm: TmainFormm
  Left = 0
  Top = 231
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1043#1086#1083#1086#1074#1085#1072' '#1092#1086#1088#1084#1072
  ClientHeight = 595
  ClientWidth = 765
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 470
    Width = 197
    Height = 33
    Caption = #1057#1090#1072#1090#1091#1089' '#1089#1077#1088#1074#1077#1088#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 534
    Width = 424
    Height = 33
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1079#1072#1088#1077#1108#1089#1090#1088#1086#1074#1072#1085#1080#1093' '#1082#1083#1110#1108#1085#1090#1110#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 233
    Top = 470
    Width = 8
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 438
    Top = 534
    Width = 8
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 225
    Top = 56
    Width = 79
    Height = 32
    Caption = #1042#1110#1090#1072#1102'! '
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -27
    Font.Name = 'Vivaldi'
    Font.Style = [fsItalic]
    ParentFont = False
    WordWrap = True
  end
  object Label6: TLabel
    Left = 249
    Top = 102
    Width = 229
    Height = 224
    Caption = 
      ' '#1071#1082#1097#1086' '#1074#1080' '#1073#1072#1095#1080#1090#1077' '#1076#1072#1085#1077' '#1087#1086#1074#1110#1076#1086#1084#1083#1077#1085#1085#1103' - '#1094#1077' '#1086#1079#1085#1072#1095#1072#1108' , '#1097#1086' '#1087#1088#1086#1075#1088#1072#1084#1085#1080#1081' '#1076 +
      #1086#1076#1072#1090#1086#1082' '#1072#1074#1090#1086#1084#1072#1090#1080#1079#1086#1074#1072#1085#1086#1075#1086' '#1074#1077#1076#1077#1085#1085#1103' '#1073#1072#1079#1080' '#1076#1072#1085#1080#1093' '#1084#1086#1073#1110#1083#1100#1085#1086#1075#1086' '#1086#1087#1077#1088#1072#1090#1086#1088#1072' ' +
      #1087#1088#1072#1094#1102#1108
    Font.Charset = ANSI_CHARSET
    Font.Color = clInfoText
    Font.Height = -23
    Font.Name = 'Vivaldi'
    Font.Style = [fsItalic]
    ParentFont = False
    WordWrap = True
  end
  object Label7: TLabel
    Left = 368
    Top = 344
    Width = 137
    Height = 64
    Caption = #1044#1103#1082#1091#1102' '#1097#1086' '#1086#1073#1088#1072#1083#1080' '#1085#1072#1089'!'
    Color = cl3DLight
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Vivaldi'
    Font.Style = [fsItalic]
    ParentColor = False
    ParentFont = False
    WordWrap = True
  end
  object closeBtn: TButton
    Left = 708
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
    TabOrder = 0
    OnClick = closeBtnClick
  end
  object MainMenu1: TMainMenu
    Top = 16
    object test1: TMenuItem
      Caption = #1054#1092#1086#1088#1084#1083#1077#1085#1085#1103
      OnClick = test1Click
    end
    object test31: TMenuItem
      Caption = #1042#1077#1076#1077#1085#1085#1103
      object N1: TMenuItem
        Caption = #1055#1077#1088#1077#1075#1083#1103#1076
        OnClick = N1Click
      end
      object N2: TMenuItem
        Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103
        OnClick = N2Click
      end
    end
    object test21: TMenuItem
      Caption = #1047#1074#1110#1090
      OnClick = test21Click
    end
  end
end
