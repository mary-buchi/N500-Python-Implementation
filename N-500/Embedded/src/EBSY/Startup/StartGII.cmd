REM @echo off
REM Decription
REM This script checks, if there are any files left from a previous update in the
REM "OLD" Directory and copies them back to the CURRENT directory. This happens, when
REM the Program could onot successful start, so the previous version is taken again.
REM After successful start, the files in the OLD directory will be deleted.
REM After this task, the script exits
REM Otherwise if they are Files in the NEW Directory, the CURRENT Files will be copied
REM in the OLD directory (in case of a failure see above), and the files in the NEW 
REM directory will be copied to the CURRENT directory
REM
REM
REM Setup directories
REM -----------------
SET CURR_DIR=GIISW
SET OLD_DIR=GIISWOld
SET NEW_DIR=GIISWNew
SET WINCE_DIR=WINCE
SET FTC=FTC.dmy
SET REBOOT=GIISW\startup -Reboot
SET KERNEL=nk.ram
REM
REM Set Base Directory
REM ------------------
cd "\Hard Disk"
REM
REM Check, if there is a new kernel and activate it
REM First save the current kernel
REM -----------------------------------------------
REM if not exist %NEW_DIR%\NK.RAM goto noNewNK
REM    %REBOOT% ***Would be ok, if this is a cold boot 
REM :noNewNK
REM
REM If there are still components in OLD_DIR, re-activate them
REM ----------------------------------------------------------
if not exist %OLD_DIR%\%FTC% goto noOldFiles
    copy  %OLD_DIR%\*.* %CURR_DIR%
    rmdir %OLD_DIR% /S /Q
:noOldFiles
REM
REM If new components exists, save them to OLD_DIR and move NEW_DIR to CURR_DIR
REM ---------------------------------------------------------------------------
if not exist %NEW_DIR%\%FTC% goto noNewFiles
    mkdir %OLD_DIR%
    copy  %CURR_DIR%\*.* %OLD_DIR%
    copy  %NEW_DIR%\*.*  %CURR_DIR%
    rmdir %NEW_DIR% /S /Q
:noNewFiles
REM
REM
REM
REM Copy Files to Windows RAM directory
REM -----------------------------------
copy %CURR_DIR%\*.* \windows
cd \windows
REM
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
REM !!!! For development: Start active sync !!!
start .\repllog.exe /remote
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
REM
REM
REM Start Application
start .\geminiII.exe
REM
REM
REM Exit startup file
