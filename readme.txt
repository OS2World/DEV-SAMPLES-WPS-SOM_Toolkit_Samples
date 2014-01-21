# 
#   COMPONENT_NAME: somx 
# 
#   ORIGINS: 27 
# 
# 
#    25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996 
#   All Rights Reserved 
#   Licensed Materials - Property of IBM 
#   US Government Users Restricted Rights - Use, duplication or 
#   disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
# 
#   @(#) 1.4 src/somples.os2/readme, somples, som3.0, s309651d 12/19/96 18:05:32 [12/24/96 08:46:25]
 
/* 
 * 
 * DISCLAIMER OF WARRANTIES. 
 * The following [enclosed] code is sample code created by IBM 
 * Corporation. This sample code is not part of any standard or IBM 
 * product and is provided to you solely for the purpose of assisting 
 * you in the development of your applications.  The code is provided 
 * "AS IS". IBM MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
 * NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE, REGARDING THE FUNCTION OR PERFORMANCE OF 
 * THIS CODE.  IBM shall not be liable for any damages arising out of 
 * your use of the sample code, even if they have been advised of the 
 * possibility of such damages. 
 * 
 * DISTRIBUTION. 
 * This sample code can be freely distributed, copied, altered, and 
 * incorporated into other software, provided that it bears the above 
 * Copyright notice and DISCLAIMER intact. 
 */ 
 
 
SOMobjects Toolkit Samples 
-------------------------- 
 
The samples contained in the subdirectories of this directory are: 
 
somd  - the Distributed SOM Framework 
somi  - the SOM Interface Repository Framework 
somk  - the SOM Run-time Kernel 
somu  - the SOM Metaclass Framework 
 
Refer to the readme files in each sample subdirectory for more 
information. 
 
To build the samples you must first set up your environment for SOM. 
  -  Update your configuration file and run the "som_cfg" utility 
     to configure the Naming Service, if you have not already done so. 
  -  Make sure the environment variable SMADDSTAR is unset. 
  -  Generate header files.  If you want to build the C samples, 
     issue the somcorba command to generate the .h files.  If you 
     want to build the C++ samples, issue the somxh command to 
     generate the .xh files.
For more information, see Chapter 2, "Configuration and Setup", 
in the "SOMobjects Developer Toolkit Programmer's Guide, Volume I". 
 
Before building the samples in the somd directory, make sure that the
DSOM daemon is running.  This is because the makefiles for the somd samples 
register the sample servers and classes in the Name Service. Starting 
the DSOM daemon is described in the DSOM section below.

To build all of the samples, run "nmake all" from this directory. 
To build just the C samples, enter "nmake c".  To build just the C++ 
samples, enter "nmake cpp".  To clean up all the sample directories,
enter "nmake clean".

Make sure that you run "nmake clean" before you build any samples to avoid
using old files such as som.ir. Note that it is also necessary to have the
DSOM daemon running at this point to deregister the sample servers.
Also, refer to the readme files contained in the subdirectories for more 
information and prerequisites for the sample programs.
 
DSOM Sample Specifics: 
---------------------- 
Samples in the somd directory require that you start the DSOM daemon, somdd. 
Because the samples build DSOM servers, dynamically loadable libraries and  
Interface Repository data into the current directory, you must start somdd  
and any DSOM servers from the directory in which the sample was built. 
 
To start somdd, enter: 
 
   start /c /f somdd  
and wait for it to issue the "SOMDD - Ready" message. 
 
Before you execute the first sample, and as you move from one DSOM sample  
to the next, you must terminate the DSOM daemon and the DSOM servers that  
are running for the first sample and restart them from the next sample's  
directory. 
 
To stop DSOM servers and the DSOM daemon, press Ctrl/Esc to bring up 
the task list, select the task with the right mouse button, then select 
close with the left mouse button.  You can also press Ctrl-c in a 
window running a DSOM server or the DSOM daemon.
 
