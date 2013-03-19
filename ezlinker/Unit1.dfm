object Form1: TForm1
  Left = 345
  Top = 238
  BorderStyle = bsSingle
  Caption = 'Ezbuilder File Linker'
  ClientHeight = 142
  ClientWidth = 554
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 75
    Height = 13
    Caption = 'File Location     '
  end
  object Edit1: TEdit
    Left = 96
    Top = 8
    Width = 441
    Height = 21
    Enabled = False
    TabOrder = 0
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 144
    Top = 40
    Width = 121
    Height = 25
    Caption = 'Build File Link'
    Enabled = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 40
    Width = 121
    Height = 25
    Caption = 'Exit'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 40
    Width = 121
    Height = 25
    Caption = 'Choose File'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 280
    Top = 40
    Width = 121
    Height = 25
    Caption = 'about ezlinker'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Memo1: TMemo
    Left = 184
    Top = 96
    Width = 121
    Height = 33
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
    Visible = False
  end
  object Button4: TButton
    Left = 8
    Top = 72
    Width = 121
    Height = 25
    Caption = 'Change MediaFile dir'
    TabOrder = 6
    OnClick = Button4Click
  end
  object Edit2: TEdit
    Left = 144
    Top = 72
    Width = 393
    Height = 21
    Enabled = False
    TabOrder = 7
    OnChange = Edit2Change
  end
  object Button6: TButton
    Left = 8
    Top = 104
    Width = 121
    Height = 25
    Caption = 'MediaFile dir default'
    Enabled = False
    TabOrder = 8
    OnClick = Button6Click
  end
  object OpenDialog1: TOpenDialog
    Left = 144
    Top = 104
  end
end
