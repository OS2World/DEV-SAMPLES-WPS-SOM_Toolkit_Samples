 
/* 
 *  This file was generated by the SOM Compiler. 
 *  Generated using: 
 *     SOM incremental update: 2.29 
 */ 
 
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
static char *sccsid = "@(#) 1.2 src/somples.os2/somu/c/fb/dog.c, somples.somu, som3.0 12/17/96 19:33:27 [12/24/96 07:55:19]";
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
 
/* 
 *  This file was generated by the SOM Compiler and Emitter Framework. 
 *  Generated using:  
 *      SOM Emitter emitctm: 2.41 
 */ 
 
#ifndef SOM_Module_dog_Source 
#define SOM_Module_dog_Source 
#endif 
 
#include <stdio.h> 
 
#define Dog_Class_Source 
#include <dog.ih> 
 
SOM_Scope void  SOMLINK dogActivity(Dog somSelf) 
{ 
    DogData *somThis = DogGetData(somSelf); 
    DogMethodDebug("Dog","dogActivity"); 
 
    printf( "The Fierce Barking Dog is doing its own thing\n" ); 
} 
 
SOM_Scope void  SOMLINK DogSet(Dog somSelf, string s) 
{ 
    DogData *somThis = DogGetData(somSelf); 
    printf( "DogSet is executing\n" ); 
    _mydata = s; 
} 
 
SOM_Scope string  SOMLINK DogGet(Dog somSelf) 
{ 
    DogData *somThis = DogGetData(somSelf); 
     
    printf( "DogGet is executing\n" ); 
    return (char*) _mydata; 
} 
 
/* 
 * The prototype for somDefaultInit was replaced by the following prototype: 
 */ 
SOM_Scope void SOMLINK somDefaultInit(Dog somSelf, som3InitCtrl* ctrl) 
{ 
    DogData *somThis; /* set in BeginInitializer */ 
    somInitCtrl globalCtrl; 
    somBooleanVector myMask; 
    DogMethodDebug("Dog","somDefaultInit"); 
    Dog_BeginInitializer_somDefaultInit; 
 
    Dog_Init_SOMObject_somDefaultInit(somSelf, ctrl); 
 
    printf( "The Fierce Barking Dog is initializing itself\n" ); 
} 
