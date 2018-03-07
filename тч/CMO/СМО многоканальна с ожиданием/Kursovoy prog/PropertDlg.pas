unit PropertDlg;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, Buttons;

type
  TPropertiasDlg = class(TForm)
    Bevel1: TBevel;
    Bevel2: TBevel;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    mEd: TEdit;
    nEd: TEdit;
    muEd: TEdit;
    LambEd: TEdit;
    Panel1: TPanel;
    CancelBitBtn: TBitBtn;
    OkBitBtn: TBitBtn;
    TMaxEd: TEdit;
    EpsEd: TEdit;
    DoverEd: TEdit;
    Edit4: TEdit;
    Label5: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Lab: TLabel;
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  PropertiasDlg: TPropertiasDlg;

implementation

uses KursUnit;

{$R *.DFM}

procedure TPropertiasDlg.FormShow(Sender: TObject);
 begin
     LambEd.Text:= FloatToStrF(MainForm.L,ffFixed,10,6);
     MuEd.Text:= FloatToStrF(MainForm.M,ffFixed,10,6);
     nEd.Text:= IntToStr(MainForm.nKanal);
     mEd.Text:= IntToStr(MainForm.DlinOch);
     TMaxEd.Text:= FloatToStrF(MainForm.MaxTime,ffFixed,10,6);
     EpsEd.Text:= FloatToStrF(MainForm.Epsilon,ffFixed,10,6);
     DoverEd.Text:=FloatToStrF(MainForm.UrDov,ffFixed,0,6);
 end;
end.
