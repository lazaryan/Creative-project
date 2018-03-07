unit About;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls;

type
  TAboutBox = class(TForm)
    Bavel3: TBevel;
    Panel1: TPanel;
    Bevel2: TBevel;
    ProgramIcon: TImage;
    ProductName: TLabel;
    Version: TLabel;
    Bevel3: TBevel;
    Label1: TLabel;
    Label3: TLabel;
    Label6: TLabel;
    Label5: TLabel;
    LoadingLbl: TLabel;
    OKButton: TButton;
    Bevel1: TBevel;
    Bevel4: TBevel;
    Label2: TLabel;
    Bevel5: TBevel;
    procedure OKButtonClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  AboutBox: TAboutBox;

implementation

{$R *.DFM}

procedure TAboutBox.OKButtonClick(Sender: TObject);
begin
 close;
end;

end.

