REM Check if a new kernel has do activate or if an old kernel should be restored
REM =============================================================================
REM Setup directories
REM -----------------
SET OLD_DIR=\GIISWOld
SET NEW_DIR=\GIISWNew
SET WINCE_DIR=\WINCE
REM
REM Check, if there is a new kernel and activate it
REM First save the current kernel
REM -------------------------------------------------
if not exist %NEW_DIR%\NK.RAM goto noNewNK
    mkdir %OLD_DIR%
    ECHO copy %WINCE_DIR%\NK.RAM %OLD_DIR%\NK.RAM
    copy      %WINCE_DIR%\NK.RAM %OLD_DIR%\NK.RAM  
    ECHO copy %NEW_DIR%\NK.RAM %WINCE_DIR%\NK.RAM
    copy      %NEW_DIR%\NK.RAM %WINCE_DIR%\NK.RAM
    del %NEW_DIR%\NK.RAM
    rmdir %NEW_DIR%
    goto noOldNK
:noNewNK
REM
REM Check, if a old kernel was saved before and move it back
REM --------------------------------------------------------
if not exist %OLD_DIR%\NK.RAM goto noOldNK
    ECHO copy %OLD_DIR%\NK.RAM %WINCE_DIR%\NK.RAM
    copy      %OLD_DIR%\NK.RAM %WINCE_DIR%\NK.RAM
    del %OLD_DIR%\NK.RAM
    rmdir %OLD_DIR%
:noOldNK
