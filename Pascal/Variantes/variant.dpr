program variant;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   MyInput : Variant;

begin
 MyInput := 3.5555;
 WriteLn(#9,MyInput,#13#10);
 MyInput :='Hello, my name is Dan';
 WriteLn(#9,MyInput);
 ReadLn
  { TODO -oUser -cConsole Main : Insert code here }
end.
 