/* 
 *   COMPONENT_NAME: somx 
 * 
 *   ORIGINS: 27 
 * 
 * 
 *   25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996   
 *   All Rights Reserved 
 *   Licensed Materials - Property of IBM 
 *   US Government Users Restricted Rights - Use, duplication or 
 *   disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
 */ 
 
#ifndef lint 
static char *sccsid = "@(#) 1.2 src/somples.os2/somu/c/fb/comptest.c, somples.somu, som3.0 12/17/96 19:33:24 [12/24/96 07:55:19]";
#endif 
 
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
 
#include <stdio.h> 
#include <string.h> 
#include <assert.h> 
#include <fb_1.h> 
#include <fb_2.h> 
#include <fb_3.h> 
#include <fb_4.h> 
 
 
/****************************************************************************** 
 *          Globals 
 ******************************************************************************/ 
 
int     delay = 0; 
FB_1    dog1; 
FB_2    dog2; 
FB_3    dog3; 
FB_4    dog4; 
char*   progname;        /* name with which this program is called */ 
 
/****************************************************************************** 
 *          Functions 
 ******************************************************************************/ 
void usage_exit() { fprintf( stderr, "Usage: %s -d[n]\n", progname ); exit(1); } 
 
int main( int argc, char *argv[] ) 
{ 
    progname = argv[0]; 
    while ( --argc > 0 && (*++argv)[0] == '-' ) { 
	char    c; 
	switch ( c = (*argv)[1] ) { 
 
	  case 's': 
	    delay = atoi( argv[0]+2 ); 
	    break; 
	  case '?': 
	    usage_exit(); 
	    break; 
	  default: 
	    fprintf( stderr, "%s: illegal option %c\n", progname, c ); 
	    usage_exit();  }} 
 
    printf( "\n--------METHOD1------------------------------------------\n\n" ); 
    dog1 = FB_1New(); 
    printf( "\n" ); 
    _dogActivity( dog1 ); 
    printf( "\n--------METHOD2------------------------------------------\n\n" ); 
 
    dog2 = FB_2New(); 
    printf( "\n" ); 
    _dogActivity( dog2 ); 
    printf( "\n--------METHOD3------------------------------------------\n\n" ); 
 
    dog3 = FB_3New(); 
    printf( "\n" ); 
    _dogActivity( dog3 ); 
    printf( "\n--------METHOD4------------------------------------------\n\n" ); 
 
    dog4 = FB_4New(); 
    printf( "\n" ); 
    _dogActivity( dog4 ); 
 
 
    printf( "\n\n" ); 
    exit(0); 
} 
