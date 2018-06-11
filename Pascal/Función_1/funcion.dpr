program funcion;

{$APPTYPE CONSOLE}

uses
  SysUtils;

function Square(Theinput : Real):Real;

  begin
  Square := Theinput * Theinput;
  end;

  var UserInput : Real;
begin
   Write('Enter the number you want to square: ');
   readLn(UserInput);
   WriteLn(UserInput :1:2, ' squared is equal to ',Square(UserInput) :1:2);
   ReadLn
end.
 