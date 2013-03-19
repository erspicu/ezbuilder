object Form1: TForm1
  Left = 456
  Top = 235
  BorderStyle = bsSingle
  Caption = 'Ezbuilder GUI'
  ClientHeight = 551
  ClientWidth = 576
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #26032#32048#26126#39636
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 360
    Width = 79
    Height = 13
    Caption = 'Batch Work List'
  end
  object Button1: TButton
    Left = 8
    Top = 160
    Width = 177
    Height = 25
    Caption = 'profile return'
    TabOrder = 0
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = 8
    Top = 32
    Width = 561
    Height = 121
    Style = lbOwnerDrawFixed
    Color = clWhite
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = #26032#32048#26126#39636
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 1
    OnDblClick = ListBox_Choose
  end
  object Button2: TButton
    Left = 200
    Top = 160
    Width = 177
    Height = 25
    Caption = 'about'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 392
    Top = 160
    Width = 177
    Height = 25
    Caption = 'exit'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 561
    Height = 21
    Enabled = False
    TabOrder = 4
    Text = 'Profile choose : '
  end
  object Memo1: TMemo
    Left = 40
    Top = 40
    Width = 401
    Height = 49
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #26032#32048#26126#39636
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    TabOrder = 5
    Visible = False
  end
  object Edit2: TEdit
    Left = 200
    Top = 216
    Width = 369
    Height = 21
    Enabled = False
    TabOrder = 6
    OnChange = Edit2Change
  end
  object Edit3: TEdit
    Left = 200
    Top = 288
    Width = 369
    Height = 21
    Enabled = False
    TabOrder = 7
    OnChange = Edit3Change
  end
  object Button4: TButton
    Left = 8
    Top = 216
    Width = 177
    Height = 25
    Caption = 'Change Input dir'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 288
    Width = 177
    Height = 25
    Caption = 'Change Output dir'
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 248
    Width = 177
    Height = 25
    Caption = 'input dir default'
    Enabled = False
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 320
    Width = 177
    Height = 25
    Caption = 'output dir default'
    Enabled = False
    TabOrder = 11
    OnClick = Button7Click
  end
  object Memo2: TMemo
    Left = 8
    Top = 376
    Width = 561
    Height = 121
    Lines.Strings = (
      '')
    ScrollBars = ssBoth
    TabOrder = 12
    OnChange = Memo2Change
  end
  object Button8: TButton
    Left = 368
    Top = 504
    Width = 177
    Height = 25
    Caption = 'Batch Start'
    Enabled = False
    TabOrder = 13
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 168
    Top = 504
    Width = 177
    Height = 25
    Caption = 'del batch work'
    TabOrder = 14
    OnClick = Button9Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 504
    Width = 113
    Height = 17
    Caption = 'Add batch work'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #26032#32048#26126#39636
    Font.Style = []
    ParentFont = False
    TabOrder = 15
  end
  object CheckBox2: TCheckBox
    Left = 8
    Top = 528
    Width = 121
    Height = 17
    Caption = 'Auto Poweroff'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #26032#32048#26126#39636
    Font.Style = []
    ParentFont = False
    TabOrder = 16
  end
  object CheckBox3: TCheckBox
    Left = 8
    Top = 192
    Width = 177
    Height = 17
    Caption = 'Force FullScreen'
    TabOrder = 17
  end
end
