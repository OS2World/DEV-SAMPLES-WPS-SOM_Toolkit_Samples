#
#   COMPONENT_NAME: somx
#
#   ORIGINS: 27
#
#
#   25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996
#   All Rights Reserved
#   Licensed Materials - Property of IBM
#   US Government Users Restricted Rights - Use, duplication or
#   disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
#
#   @(#) 1.3 src/somples.os2/somu/c/fb/makefile, somples.somu, som3.0, s309651d 12/19/96 13:49:56 [12/24/96 08:46:20]

# DISCLAIMER OF WARRANTIES.
# The following [enclosed] code is sample code created by IBM
# Corporation. This sample code is not part of any standard or IBM
# product and is provided to you solely for the purpose of assisting
# you in the development of your applications.  The code is provided
# "AS IS". IBM MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE, REGARDING THE FUNCTION OR PERFORMANCE OF
# THIS CODE.  IBM shall not be liable for any damages arising out of
# your use of the sample code, even if they have been advised of the
# possibility of such damages.
#
# DISTRIBUTION.
# This sample code can be freely distributed, copied, altered, and
# incorporated into other software, provided that it bears the above
# Copyright notice and DISCLAIMER intact.

#   Makefile for: Fierce Barking Dog Sample

#
# This make file has settings for IBM VisualAge C++ version 3.x for OS/2
# It is may be used with the nmake program.
#

# General settings
SYS          = OS2
CC           = icc
CPPC         = icc
SC           = sc
LINKER       = ilink
IMPLIB       = implib
RM           = del
OBJ          = obj
CFLAGS       = $(EXE_CFLAGS)
CPPFLAGS     = $(EXE_CPPFLAGS)
SCFLAGS      = -S100000
TARGETS      = $(EXE_TARGET).$(EXE_EXT)
CLEANFILES   = $(TARGETS) barkobj.c bdog.c fb_1.c fb_2.c fb_3.c fb_4.c \
               fdog.c fierbark.c fierobj.c

# EXE build settings
EXE_CFLAGS   = -W0 -c -Ti+ -Q+ -Gm+ -Sm -Ss+ -I.
EXE_CPPFLAGS = -W0 -c -Ti+ -Q+ -Gm+ -Sm -I.
EXE_LFLAGS   = /nofr /exepack /packd /packc /align:4 /stack:360000 /pm:vio /noe /noi /nol /de
EXE_OBJS     = comptest.obj barking.obj dog.obj fierce.obj barkobj.obj bdog.obj \
               fb_1.obj fb_2.obj fb_3.obj fb_4.obj fdog.obj fierbark.obj fierobj.obj
EXE_SYSOBJS  =
EXE_LIBS     = somtk os2386
EXE_TARGET   = comptest
EXE_EXT      = exe
EXE_IDLS     = barking.idl barkobj.idl bdog.idl dog.idl fb_1.idl fb_2.idl fb_3.idl \
               fb_4.idl fdog.idl fierbark.idl fierce.idl fierobj.idl
EXE_CSRC     = comptest.c barking.c dog.c fierce.c barkobj.c bdog.c fb_1.c fb_2.c \
               fb_3.c fb_4.c fdog.c fierbark.c fierobj.c
EXE_CPPSRC   =

# DLL build settings
DLL_INITMOD  = sinitmod
DLL_CFLAGS   = -W0 -c -Ti+ -Q+ -Gm+ -Ge- -Sm -Ss+ -I.
DLL_CPPFLAGS = -W0 -c -Ti+ -Q+ -Gm+ -Ge- -Sm -I.
DLL_LFLAGS   = /dll /noe /stack:360000
DLL_OBJS     =   sinitmod.obj
DLL_SYSOBJS  =
DLL_LIBS     = os2386.lib somtk.lib
DLL_TARGET   = dllname
DLL_EXT      = dll
DLL_LIBEXT   = lib
DLL_DEF      = def
DLL_IDLS     =
DLL_CSRC     =
DLL_CPPSRC   =

all: $(SOMBASE)\include\somcorba.bld $(TARGETS)

# DLL target
$(DLL_TARGET).$(DLL_EXT): $(DLL_OBJS) $(DLL_TARGET).$(DLL_LIBEXT)
        $(LINKER) $(DLL_LFLAGS) $(DLL_OBJS) $(DLL_SYSOBJS) /OUT:$@ $(DLL_LIBS) $(DLL_TARGET).$(DLL_DEF)

# DLL "Import" library target
$(DLL_TARGET).$(DLL_LIBEXT): $(DLL_TARGET).$(DLL_DEF)
	$(IMPLIB) $(DLL_TARGET).$(DLL_LIBEXT) $(DLL_TARGET).$(DLL_DEF)

# DLL exports file
$(DLL_TARGET).$(DLL_DEF): $(DLL_IDLS)
	$(SC) $(SCFLAGS) -s$(DLL_DEF) -mdll=$(DLL_TARGET) $(DLL_IDLS)

# DLL SOMInitModule function
$(DLL_INITMOD).$(OBJ): $(DLL_INITMOD).c
	$(CC) $(DLL_CFLAGS) $*.c

$(DLL_INITMOD).c: $(DLL_IDLS)
	$(SC) $(SCFLAGS) -simod -mdll=$(DLL_TARGET) -mimod=$@ $(DLL_IDLS)

# EXE target
$(EXE_TARGET).$(EXE_EXT): $(EXE_OBJS)
	$(LINKER) $(EXE_LFLAGS) $(EXE_OBJS) $(EXE_SYSOBJS),$@,NUL,$(EXE_LIBS);

$(SOMBASE)\include\somcorba.bld:
    @echo This sample requires the CORBA-style C bindings
    @echo created using the somcorba command.
    @exit 1

# Build DSOM Implementation Repository
somdimpl:


# Clean up files that can be re-built
clean: cleanfiles cleanimpl

cleanfiles:
	-del *.$(OBJ) >nul 2>&1
	-del $(EXE_IDLS:.idl=.h) $(DLL_IDLS:.idl=.h) >nul 2>&1
	-del $(EXE_IDLS:.idl=.ih) $(DLL_IDLS:.idl=.ih) >nul 2>&1
	-del $(CLEANFILES) >nul 2>&1

cleanimpl:


# Suffix rules for building source files
.SUFFIXES: .$(OBJ) .c .ih .h .idl

.c.$(OBJ):
	$(CC) $(CFLAGS) $<


.idl.c:
	$(SC) $(SCFLAGS) -sc $<


.idl.ih:
	$(SC) $(SCFLAGS) -sih $<


.idl.h:
	$(SC) $(SCFLAGS) -sh $<


# Dependencies follow
comptest.obj: comptest.c dog.h fierce.h barking.h fierbark.h fdog.h bdog.h \
              fierobj.h barkobj.h fb_1.h fb_2.h fb_3.h fb_4.h

barking.obj: barking.c barking.ih barking.h

dog.obj: dog.c dog.ih dog.h

fierce.obj: fierce.c fierce.ih fierce.h

barkobj.obj: barkobj.c barkobj.ih barkobj.h barking.h

bdog.obj: bdog.c bdog.ih bdog.h dog.h barking.h

fb_1.obj: fb_1.c fb_1.ih fb_1.h dog.h fierbark.h fierce.h barking.h

fb_2.obj: fb_2.c fb_2.ih fb_2.h fdog.h dog.h fierce.h bdog.h barking.h

fb_3.obj: fb_3.c fb_3.ih fb_3.h bdog.h dog.h barking.h fierce.h

fb_4.obj: fb_4.c fb_4.ih fb_4.h fierobj.h fierce.h barkobj.h barking.h dog.h

fdog.obj: fdog.c fdog.ih fdog.h dog.h fierce.h

fierbark.obj: fierbark.c fierbark.ih fierbark.h fierce.h barking.h

fierobj.obj: fierobj.c fierobj.ih fierobj.h fierce.h

barking.ih: barking.idl
barking.h: barking.idl

barkobj.ih: barkobj.idl barking.idl
barkobj.h: barkobj.idl barking.idl

bdog.ih: bdog.idl barking.idl dog.idl
bdog.h: bdog.idl barking.idl dog.idl

dog.ih: dog.idl
dog.h: dog.idl

fb_1.ih: fb_1.idl dog.idl fierbark.idl fierce.idl barking.idl
fb_1.h: fb_1.idl dog.idl fierbark.idl fierce.idl barking.idl

fb_2.ih: fb_2.idl fdog.idl dog.idl fierce.idl bdog.idl barking.idl
fb_2.h: fb_2.idl fdog.idl dog.idl fierce.idl bdog.idl barking.idl

fb_3.ih: fb_3.idl bdog.idl barking.idl dog.idl fierce.idl
fb_3.h: fb_3.idl bdog.idl barking.idl dog.idl fierce.idl

fb_4.ih: fb_4.idl fierobj.idl fierce.idl barkobj.idl barking.idl dog.idl
fb_4.h: fb_4.idl fierobj.idl fierce.idl barkobj.idl barking.idl dog.idl

fdog.ih: fdog.idl dog.idl fierce.idl
fdog.h: fdog.idl dog.idl fierce.idl

fierbark.ih: fierbark.idl fierce.idl barking.idl
fierbark.h: fierbark.idl fierce.idl barking.idl

fierce.ih: fierce.idl
fierce.h: fierce.idl

fierobj.ih: fierobj.idl fierce.idl
fierobj.h: fierobj.idl fierce.idl
