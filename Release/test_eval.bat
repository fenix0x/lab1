echo off
REM ������ ��������� ��� ����������
"eval.exe" 
IF ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����� ���������� ����������
"eval.exe" notANumber 
IF NOT ERRORLEVEL 3 GOTO err
REM ������ ��������� � ������ ������� � �������� ������ �� ����������
"eval.exe" "" 
IF NOT ERRORLEVEL 3 GOTO err
REM ������ ��������� � ����� �������� ����������
"eval.exe" -123 
IF NOT ERRORLEVEL 4 GOTO err
REM ������ ��������� � ����� ������ ����������
"eval.exe" + 
IF NOT ERRORLEVEL 4 GOTO err
REM ������ ��������� � ����� ������ � ����� ������
"eval.exe" 1 + 
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����� ������ � ����� ������
"eval.exe" - 1
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� �� ������ � ����� � ������ ������ ����������
"eval.exe" 3 - 1 /
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� �� ������ � ����� � �������� ������ ����������
"eval.exe" 3 - 1 / *
IF NOT ERRORLEVEL 3 GOTO err
REM ������ ��������� � ����� ������� ������ � ������ ������ ����������
"eval.exe" 3 - / 1
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����� ������� ������ � ������ ������ ����������
"eval.exe" 3 - 3 1
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����� ������� ������ � �������� ������ ����������
"eval.exe" 3 - / 1 +
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����� ������� ������ � �������� ������ ����������
"eval.exe" 3 - 3 1 -
IF NOT ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����������
eval.exe 13 + 7 / 8 * 3.8 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "1.txt"
IF ERRORLEVEL 1 GOTO err
REM ������ ��������� � ����������
eval.exe 1 + 1 * 5 / 3 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "2.txt"
IF ERRORLEVEL 1 GOTO err
REM ������ ��������� � �������� �� 0
eval.exe 1 + 1 * 5 / 0 
IF NOT ERRORLEVEL 5 GOTO err
ECHO Program testing succeeded : -)
EXIT
:err
ECHO Program testing failed : -(
EXIT