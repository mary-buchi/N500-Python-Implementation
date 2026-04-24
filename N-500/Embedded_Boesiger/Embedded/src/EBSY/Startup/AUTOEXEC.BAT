@REM
@REM Copyright (c) Microsoft Corporation.  All rights reserved.
@REM
@REM
@REM Use of this source code is subject to the terms of the Microsoft end-user
@REM license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
@REM If you did not accept the terms of the EULA, you are not authorized to use
@REM this source code. For a copy of the EULA, please see the LICENSE.RTF on your
@REM install media.
@REM
@echo off
verify off
PROMPT $p$g

c:
cd wince
REM rtool_c3

REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
REM !!                                               !!
REM !! MAKE SURE YOU SET THE RIGHT IRQ & IOBASE      !!
REM !! FOR YOUR NETCARD BELOW.                       !!
REM !!                                               !!
REM !! NET_IRQ can be specified in either hex or     !!
REM !! decimal digits (ie either as IRQ=E or IRQ=14).!!
REM !! A value of 0 for both NET_IRQ & NET_IOBASE    !!
REM !! means to find the first net card on the PCI   !!
REM !! bus and use that                              !!
REM !!                                               !!
REM !! NET_IOBASE must be specified in Hex digits.   !!
REM !! A value of 0 for NET_IOBASE means to auto     !!
REM !! searchfor the PCI net card using the          !!
REM !! specified IRQ value.                          !!
REM !!                                               !!
REM !! NET_IP can be set to specify a static IP      !!
REM !! address or left blank to use DHCP to obtain   !!
REM !! an IP address.  Format of set should be:      !!
REM !!      set NET_IP=:10.0.0.1                     !!
REM !!                                               !!
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

set NET_IRQ=0
set NET_IOBASE=0
set NET_IP=10.10.41.198


if "%CONFIG%" == "ITX_RAM_ROM" goto ITX_RAM_ROM
if "%CONFIG%" == "CEPC_1024" goto CEPC_1024
if "%CONFIG%" == "CLEAN" goto CLEAN


:ITX_RAM_ROM
REM #################################################################
REM     Launch LOADCEPC using a local NK.RAM image.
REM
call C:\chknk.bat
REM
REM Startup WinCE
REM -------------
loadcepc nk.ram
goto END


:CEPC_1024
REM #################################################################
REM     Set RES=/L:1024x768x8 for use with FLAT display driver.
REM
REM     Format
REM             /L:DXxDYxBPP[:PXxPY] in DECIMAL!!!!
REM

set RES=/L:1024x768x8
goto WITHRES



:WITHRES
REM #################################################################
REM     Here we actually Launch LOADCEPC using the RES, NET_IOBASE,
REM     and NET_IRQ env vars we just set above based on menu
REM     selections.

loadcepc  /e:%NET_IOBASE%:%NET_IRQ%:%NET_IP% %RES% eboot.bin
goto END


:CLEAN
cd ..
cd wince
:END

