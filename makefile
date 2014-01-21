#
#   COMPONENT_NAME: somx
#
#   ORIGINS: 27
#
#
#    25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996,1996
#   All Rights Reserved
#   Licensed Materials - Property of IBM
#   US Government Users Restricted Rights - Use, duplication or
#   disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
#
#   @(#) 1.1 src/somples.os2/makefile, somples, som3.0 12/12/96 10:58:07 [12/24/96 07:40:47]


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

# Global makefile for all OS/2 SOM Samples

usage:
	@echo This makefile can build all the C and C++ SOM toolkit samples.
	@echo To build all the C and C++ samples enter "nmake all".
	@echo To build just the C samples enter "nmake c". To build just the C++
	@echo samples enter "nmake cpp". To clean up all the samples directories
	@echo enter "nmake clean".

all: c cpp

MAKE = nmake -f makefile

cpp:
	cmd /c "cd .\somk\cpp\derived   && $(MAKE)"
	cmd /c "cd .\somk\cpp\simple    && $(MAKE)"
	cmd /c "cd .\somd\cpp\stack     && $(MAKE)"
	cmd /c "cd .\somd\cpp\event     && $(MAKE)"
	cmd /c "cd .\somd\cpp\peer     	&& $(MAKE)"

c :
	cmd /c "cd .\somk\c\animals     && $(MAKE)"
	cmd /c "cd .\somk\c\tp          && $(MAKE)"
	cmd /c "cd .\somi\c\irdump      && $(MAKE)"
	cmd /c "cd .\somd\c\animal      && $(MAKE)"
	cmd /c "cd .\somd\c\dii         && $(MAKE)"
	cmd /c "cd .\somd\c\proxy       && $(MAKE)"
	cmd /c "cd .\somu\c\fb          && $(MAKE)"

clean:
	cmd /c "cd .\somk\c\animals     && $(MAKE) $@"
	cmd /c "cd .\somk\c\tp          && $(MAKE) $@"
	cmd /c "cd .\somk\cpp\derived   && $(MAKE) $@"
	cmd /c "cd .\somk\cpp\simple    && $(MAKE) $@"
	cmd /c "cd .\somd\c\animal      && $(MAKE) $@"
	cmd /c "cd .\somd\c\dii         && $(MAKE) $@"
	cmd /c "cd .\somd\c\proxy       && $(MAKE) $@"
	cmd /c "cd .\somd\cpp\event     && $(MAKE) $@"
	cmd /c "cd .\somd\cpp\stack     && $(MAKE) $@"
	cmd /c "cd .\somd\cpp\peer     	&& $(MAKE) $@"
	cmd /c "cd .\somi\c\irdump      && $(MAKE) $@"
	cmd /c "cd .\somu\c\fb          && $(MAKE) $@"
