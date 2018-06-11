program junk_Demo;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var  UsersNumber : Integer;
  UsersString : String;
  procedure junk(Number:integer;Stuff:String);

  begin
        WriteLn('El numero es: ',Number);
        WriteLn('El string es: ',Stuff);
  end;

begin
  WriteLn('Enter your string: ',);
  ReadLn(UsersString);
  WriteLn('Enter your number: ');
  ReadLn(UserNumber);

end.
 