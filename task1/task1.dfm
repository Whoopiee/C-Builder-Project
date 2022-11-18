object task1Form: Ttask1Form
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1087#1072#1082#1077#1090#1110#1074' '#1079#1072' '#1087#1077#1088#1110#1086#1076
  ClientHeight = 756
  ClientWidth = 1147
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 320
    Top = 312
    Width = 479
    Height = 23
    Caption = #1058#1088#1077#1073#1072' '#1088#1086#1079#1110#1073#1088#1072#1090#1080#1089#1103' '#1079' '#1074#1077#1076#1077#1085#1085#1103#1084' mysql '#1073#1072#1079#1080' '#1076#1072#1085#1080#1093
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object closeBtn: TButton
    Left = 1056
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
    TabOrder = 0
    OnClick = closeBtnClick
  end
  object backButton: TButton
    Left = 24
    Top = 24
    Width = 41
    Height = 39
    Caption = #55358#56340
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -35
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = backButtonClick
  end
end
