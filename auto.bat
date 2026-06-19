@echo off
:menu
cls
echo "enter the exp number"
echo 0. Exit
echo.
set /p exp=Enter Experiment Number: 

if "%exp%"=="0" exit
if "%exp%"=="1" goto p1
if "%exp%"=="2" goto p2
if "%exp%"=="3" goto p3
if "%exp%"=="4" goto p4
if "%exp%"=="5" goto p5
if "%exp%"=="6" goto p6
if "%exp%"=="7" goto p7
if "%exp%"=="8" goto p8
if "%exp%"=="9" goto p9
if "%exp%"=="10" goto p10
if "%exp%"=="11" goto p11
if "%exp%"=="12" goto p12

echo Invalid number!
pause
goto menu

:p1
cls
echo Experiment 1
echo =========================
echo.
echo ==================================
echo program1.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program1.cpp.cpp
echo.
pause
goto menu

:p2
cls
echo Experiment 2
echo =========================
echo.
echo ==================================
echo program2.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program2.cpp.cpp
echo.
pause
goto menu

:p3
cls
echo Experiment 3
echo =========================
echo.
echo ==================================
echo program3.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program3.cpp.cpp
echo.
pause
goto menu

:p4
cls
echo Experiment 4
echo =========================
echo.
echo ==================================
echo program4.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program4.cpp.cpp
echo.
pause
goto menu

:p5
cls
echo Experiment 5
echo =========================
echo.
echo ==================================
echo program5.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program5.cpp.cpp
echo.
pause
goto menu

:p6
cls
echo Experiment 6
echo =========================
echo.
echo ==================================
echo program6.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program6.cpp.cpp
echo.
pause
goto menu

:p7
cls
echo Experiment 7
echo =========================
echo.
echo ==================================
echo program7.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program7.cpp.cpp
echo.
pause
goto menu

:p8
cls
echo Experiment 8
echo =========================
echo.
echo ==================================
echo program8.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program8.cpp.cpp
echo.
pause
goto menu

:p9
cls
echo Experiment 9
echo =========================
echo.
echo ==================================
echo program9.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program9.cpp.cpp
echo.
pause
goto menu

:p10
cls
echo Experiment 10
echo =========================
echo.
echo ==================================
echo program10.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program10.cpp.cpp
echo.
pause
goto menu

:p11
cls
echo Experiment 11
echo =========================
echo.
echo ==================================
echo program11.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program11.cpp.cpp
echo.
pause
goto menu

:p12
cls
echo Experiment 12
echo =========================
echo.
echo ==================================
echo program12.cpp
echo ==================================
curl -L https://raw.githubusercontent.com/suhas-yadav756/network/main/program12.cpp.cpp
echo.
pause
goto menu