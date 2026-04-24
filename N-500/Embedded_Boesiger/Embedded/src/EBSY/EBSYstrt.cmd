@echo off
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
REM Setup directories
REM -----------------
SET CURR_DIR=R:\BIN\TEST
SET OLD_DIR=R:\BIN\OldDLLs
SET NEW_DIR=R:\BIN\NewDLLs
REM
REM Copy OLD_DIR back, if there are any of them and exit
REM ------------------------------------------------------
if not exist %OLD_DIR% goto noOldFiles
	copy %OLD_DIR%\*.* %CURR_DIR%
	rmdir %OLD_DIR% /S /Q
    goto endBat
:noOldFiles
REM
REM Save OLD_DIR and copy new FILE_DIR if there are any of them and exit
REM --------------------------------------------------------------------
if not exist %NEW_DIR% goto noNewFiles
    mkdir %OLD_DIR%
    copy  %CURR_DIR%\*.* %OLD_DIR%/
    copy  %NEW_DIR%\*.*  %CURR_DIR%
    rmdir %NEW_DIR% /S /Q
    goto endBat
:noNewFiles
REM
:endBat