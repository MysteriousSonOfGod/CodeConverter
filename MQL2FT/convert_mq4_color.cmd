@echo off
chcp 65001

set starttime=%time: =0%
set countWin=0
set countFail=0
set countCancel=0

set currpath=%~dp0

PATH=%currpath%Tools\MinGW;%currpath%Tools\MinGW\bin;%PATH%

set compiler=%currpath%Tools\MinGW\bin\g++.exe
set make=%currpath%Tools\MinGW\bin\mingw32-make.exe
set makefile=%currpath%MQL2FT\Makefile.win
set targetpath=%currpath%StrategyDLLs
set sourcepath=%currpath%MQLFiles
set destpath=%currpath%MQL2FT\MQL\mql4.cpp
set destpathheader=%currpath%MQL2FT\MQL\mql4.h
set translator=%currpath%\Translator\Bin\Translator.exe
set AST_mode=%1

mkdir StrategyDLLs 2>nul
mkdir IndicatorDLLs 2>nul


for /F "delims=" %%P in ('dir "%sourcepath%\*.mq4" /B') do (
	call :makeDLL "%sourcepath%\%%P" "%AST_mode%"
)
goto end


:makeDLL
set /a res=countWin+countFail+countCancel+1
echo Converting DLL [97m#%res%[0m

  setlocal
  echo Build %1
  echo Name "%~n1"
  set definition=__INDICATOR
  set Cancel=%countCancel%
  set starttime=%time: =0%
  
  if "%~2" == "" (
    "%translator%" %1 "%destpath%" "%destpathheader%"
  ) else (
    "%translator%" %1 "%destpath%" "%destpathheader%" %2
  )

  if %errorlevel% == 1 (
	set definition=__STRATEGY
	goto continue
  ) else if %errorlevel% == 2 (
	set definition=__INDICATOR
	set targetpath=%currpath%IndicatorDLLs
	goto continue
  ) else if %errorlevel% == 0 (
	echo -^> Ambiguous functions calls - cannot determine script type. & echo.   [91mCompilation cancelled.[0m
  ) else if %errorlevel% == -1 (
	echo [91m-^> Compilation cancelled.[0m
  ) else (
	echo [91m-^> Critical Translation Error. Compilation cancelled.[0m
	)
  
  set /a Cancel=%countCancel%+1
  endlocal & set countCancel=%Cancel%
  goto eof
:continue
  set endtime=%time: =0%
  set /a starttime=(1%starttime:~0,2%-100)*3600000 + (1%starttime:~3,2%-100)*60000 + (1%starttime:~6,2%-100)*1000 + (1%starttime:~9,2%-100)*10
  set /a endtime=(1%endtime:~0,2%-100)*3600000 + (1%endtime:~3,2%-100)*60000 + (1%endtime:~6,2%-100)*1000 + (1%endtime:~9,2%-100)*10
  set /a elapsedtime1=%endtime%-%starttime%
  echo Translation time: [97m%elapsedtime1% ms[0m
  
  echo definition=%definition%
  cd /d "%currpath%MQL2FT"
  echo Started: %date% %time%, Build "%~n1.dll", definition=%definition% >> build.log
  echo Started: %date% %time%, Build "%~n1.dll", definition=%definition% >> buildMessages.log
  
  set starttime=%time: =0%
  echo -^> Compiling...
  set definition="%definition%"
  set iniT="__INIT_UNDEFINED"
  set deinT="__DEINIT_UNDEFINED"
  set stT="__START_UNDEFINED"
  set isStrict="MQL2FT_NOT_STRICT_MODE"
  set onTimerT="__ON_TIMER_UNDEFINED"
  set Hooking="DISABLE_HOOKING"
  set conv_debug="DISABLE_DEBUG_PRINTS"
  call "%currpath%EPTypes.bat"
  
  if "%~2" == "" (
    set conv_debug="DISABLE_DEBUG_PRINTS"
  ) else (
    set conv_debug="ENABLE_DEBUG_PRINTS"
  )
  
  "%make%" -f "%makefile%" all df=%definition% iniT=%iniT% deinT=%deinT% stT=%stT% isStrict=%isStrict% onTimerT=%onTimerT% Hooking=%Hooking% conv_debug=%conv_debug% >> build.log 2>> buildMessages.log
  set Win=%countWin%
  set Fail=%countFail%
  
  if exist "MQL2FT.dll" (
	echo [96m-^> Success![0m
	move MQL2FT.dll "%targetpath%\%~n1.dll"
	set /a Win=%countWin%+1
  ) else (
	echo [91m-^> Compilation failed.[0m
	echo Please see build.log and buildMessages.log log files in %currpath%MQL2FT for details.
	set /a Fail=%countFail%+1
  )
  cd /d "%currpath%"

  ::Show Elapsed Time
  set endtime=%time: =0%
  set /a starttime=(1%starttime:~0,2%-100)*3600000 + (1%starttime:~3,2%-100)*60000 + (1%starttime:~6,2%-100)*1000 + (1%starttime:~9,2%-100)*10
  set /a endtime=(1%endtime:~0,2%-100)*3600000 + (1%endtime:~3,2%-100)*60000 + (1%endtime:~6,2%-100)*1000 + (1%endtime:~9,2%-100)*10
  set /a elapsedtime2=%endtime%-%starttime%
  echo Compilation time: [97m%elapsedtime2% ms[0m
  set /a totaltime=%elapsedtime1%+%elapsedtime2%
  echo Total conversion time: [97m%totaltime% ms[0m
  echo [96mConverted: %Win%[0m ^| [91mFailed: %Fail%[0m ^| Canceled: %Cancel%
  echo ^<---------------------------------------------------------------------------------------^>
  echo.
  
  ::Win%& is very imprtant to prevent space from appending to Win!
  endlocal & set countWin=%Win%& set countFail=%Fail%
  goto eof
  
:end
echo [96mConverted: %countWin%[0m ^| [91mFailed: %countFail%[0m ^| Canceled: %countCancel%
echo Start Time: [97m%startTime%[0m
echo End   Time: [97m%time%[0m

set endtime=%time: =0%
set /a starttime=(1%starttime:~0,2%-100)*3600 + (1%starttime:~3,2%-100)*60 + (1%starttime:~6,2%-100)
set /a endtime=(1%endtime:~0,2%-100)*3600 + (1%endtime:~3,2%-100)*60 + (1%endtime:~6,2%-100)
set /a elapsedtime=%endtime%-%starttime%
set /a elaph=%elapsedtime%/3600
set /a elapm=(%elapsedtime% - (%elaph%*3600))/60
set /a elaps=%elapsedtime% - (%elaph%*3600) - (%elapm%*60)

if %elaph% LSS 10 set elaph=0%elaph%
if %elapm% LSS 10 set elapm=0%elapm%
if %elaps% LSS 10 set elaps=0%elaps%

echo Total Time: [97m%elaph%:%elapm%:%elaps%[0m

:endpause
::pause
:eof