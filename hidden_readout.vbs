Set WshShell = CreateObject("WScript.Shell") 
WshShell.Run chr(34) & "C:\Users\user\Desktop\logs\read_dewar.bat" & Chr(34), 0
WshShell.Run chr(34) & "C:\Users\user\Desktop\logs\read_water.bat" & Chr(34), 0
Set WshShell = Nothing