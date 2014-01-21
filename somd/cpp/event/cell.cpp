// 
//   COMPONENT_NAME: somx 
// 
//   ORIGINS: 27 
// 
// 
//    25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996 
//   All Rights Reserved 
//   Licensed Materials - Property of IBM 
//   US Government Users Restricted Rights - Use, duplication or 
//   disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
// 
#ifndef lint 
static char *sccsid = "@(#) 1.5.1.1 src/somples.os2/somd/cpp/event/cell.cpp, somples.somd, som3.0 12/6/96 13:33:39 [12/24/96 07:55:02]"; 
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
 
#define Cell_Class_Source 
#define M_Cell_Class_Source 
 
#include <stdio.h> 
 
#include <somd.xh> 
#include "cell.xih" 
 
/* 
 *Method from the IDL attribute statement: 
 *"attribute long val" 
 */ 
 
SOM_Scope void  SOMLINK _set_val(Cell *somSelf,  Environment *ev, 
				 long value) 
{ 
    CellData *somThis = CellGetData(somSelf); 
    CellMethodDebug("Cell","_set_val"); 
 
    somThis->val = value; 
    somSelf->notifyEventCh(ev); 
} 
 
 
SOM_Scope void  SOMLINK notifyEventCh(Cell *somSelf,  Environment *ev) 
{ 
    CellData *somThis = CellGetData(somSelf); 
    any event_msg; 
    static long current_value; 
 
    CellMethodDebug("Cell","notifyServers"); 
 
    current_value = somSelf->_get_val(ev); 
    somPrintf("The cell value has changed. Notifying the event channel\n"); 
    event_msg._type = TC_long; 
    event_msg._value = (void *)&current_value; 
 
    somThis->cons_if->push(ev, &event_msg); 
} 
 
 
SOM_Scope void  SOMLINK setConsumerIf(Cell *somSelf,  Environment *ev, 
				      EventComm_Consumer *consumer_if) 
{ 
    CellData *somThis = CellGetData(somSelf); 
    CellMethodDebug("Cell","setConsumerIf"); 
 
    somThis->cons_if = consumer_if; 
} 
 
