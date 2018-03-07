program KursProject;

uses
  Forms,
  KursUnit in 'KursUnit.pas' {MainForm},
  PropertDlg in 'PropertDlg.pas' {PropertiasDlg},
  About in 'About.pas' {AboutBox};

{$R *.RES}

begin
  AboutBox := TAboutBox.Create(Application);
//  AboutBox.BorderIcons.Clear;
  AboutBox.Visible := true;   //  This label 'Loading...' we need only in Splash mode
  AboutBox.OKButton.Visible  := false;  //  This OK button we need only in About mode
  AboutBox.LoadingLbl.Visible := true;   //  This label 'Loading...' we need only in Splash mode
  AboutBox.Height:=185;
 // AboutBox->LoadingLbl->Caption = "Loading...";
 // AboutBox->Caption = "About MapScan 2.0";
  AboutBox.BorderStyle := bsNone;

  AboutBox.Show;
  AboutBox.Update;

    Application.Initialize;
    Application.CreateForm(TMainForm, MainForm);
    Application.CreateForm(TPropertiasDlg, PropertiasDlg);
   AboutBox.Hide;
   AboutBox.Free;
  Application.CreateForm(TAboutBox, AboutBox);
  Application.Run;

end.
