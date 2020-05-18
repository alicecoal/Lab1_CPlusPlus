object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Task2'
  ClientHeight = 412
  ClientWidth = 669
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 8
    Width = 393
    Height = 405
    OnMouseDown = Image1MouseDown
  end
  object Label2: TLabel
    Left = 399
    Top = 31
    Width = 32
    Height = 13
    Caption = 'Vertex'
  end
  object Label3: TLabel
    Left = 415
    Top = 247
    Width = 10
    Height = 13
    Caption = 'P:'
  end
  object Label4: TLabel
    Left = 415
    Top = 278
    Width = 10
    Height = 13
    Caption = 'S:'
  end
  object Label5: TLabel
    Left = 523
    Top = 247
    Width = 34
    Height = 13
    Caption = 'Xmass:'
  end
  object Label6: TLabel
    Left = 524
    Top = 278
    Width = 34
    Height = 13
    Caption = 'Ymass:'
  end
  object Label7: TLabel
    Left = 411
    Top = 345
    Width = 31
    Height = 13
    Caption = 'Angle:'
  end
  object Label9: TLabel
    Left = 524
    Top = 31
    Width = 35
    Height = 13
    Caption = 'Radius '
  end
  object Label1: TLabel
    Left = 411
    Top = 61
    Width = 20
    Height = 13
    Caption = 'Side'
  end
  object Label8: TLabel
    Left = 486
    Top = 209
    Width = 71
    Height = 13
    Caption = 'Characteristics'
  end
  object Label10: TLabel
    Left = 563
    Top = 228
    Width = 60
    Height = 13
    Caption = 'Mass Centre'
  end
  object Label11: TLabel
    Left = 437
    Top = 228
    Width = 52
    Height = 13
    Caption = '( in pixels )'
  end
  object Label12: TLabel
    Left = 425
    Top = 320
    Width = 66
    Height = 13
    Caption = 'Change angel'
  end
  object Label13: TLabel
    Left = 399
    Top = 114
    Width = 245
    Height = 13
    Caption = '1. To draw an arbitrary shape, click consecutevely '
  end
  object Label14: TLabel
    Left = 399
    Top = 133
    Width = 258
    Height = 13
    Caption = 'on the field and then click on the first point to close it.'
  end
  object Label15: TLabel
    Left = 399
    Top = 152
    Width = 258
    Height = 13
    Caption = '2. To move the center of mass, click on it and then on'
  end
  object Label16: TLabel
    Left = 399
    Top = 171
    Width = 244
    Height = 13
    Caption = 'the point of the field to which you want to move it.'
  end
  object Label17: TLabel
    Left = 399
    Top = 190
    Width = 252
    Height = 13
    Caption = '3. To change the scale turn the wheel of the mouse.'
  end
  object Vertex: TEdit
    Left = 437
    Top = 31
    Width = 65
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 508
    Top = 83
    Width = 75
    Height = 25
    Caption = 'Build'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ClearAll: TButton
    Left = 565
    Top = 366
    Width = 75
    Height = 25
    Caption = 'ClearAll'
    TabOrder = 2
    OnClick = ClearAllClick
  end
  object ListBox1: TListBox
    Left = 431
    Top = 247
    Width = 70
    Height = 25
    ItemHeight = 13
    TabOrder = 3
  end
  object ListBox2: TListBox
    Left = 431
    Top = 278
    Width = 71
    Height = 25
    ItemHeight = 13
    TabOrder = 4
  end
  object ListBox3: TListBox
    Left = 563
    Top = 247
    Width = 71
    Height = 25
    ItemHeight = 13
    TabOrder = 5
  end
  object ListBox4: TListBox
    Left = 564
    Top = 278
    Width = 70
    Height = 25
    ItemHeight = 13
    TabOrder = 6
  end
  object Angle: TEdit
    Left = 448
    Top = 339
    Width = 73
    Height = 21
    DoubleBuffered = False
    ParentDoubleBuffered = False
    TabOrder = 7
  end
  object Button2: TButton
    Left = 446
    Top = 366
    Width = 75
    Height = 25
    Caption = 'Rotate'
    TabOrder = 8
    OnClick = Button2Click
  end
  object Radius: TEdit
    Left = 565
    Top = 31
    Width = 65
    Height = 21
    TabOrder = 9
  end
  object RightPolygon: TRadioButton
    Left = 425
    Top = 8
    Width = 82
    Height = 17
    Caption = 'RightPolygon'
    TabOrder = 10
    OnClick = RightPolygonClick
  end
  object Circle: TRadioButton
    Left = 564
    Top = 8
    Width = 50
    Height = 17
    Caption = 'Circle'
    TabOrder = 11
    OnClick = CircleClick
  end
  object Side: TEdit
    Left = 437
    Top = 58
    Width = 65
    Height = 21
    TabOrder = 12
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 592
    Top = 320
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 552
    Top = 320
  end
end
