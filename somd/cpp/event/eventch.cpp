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
static char *sccsid = "@(#) 1.6.1.1 src/somples.os2/somd/cpp/event/eventch.cpp, somples.somd, som3.0 12/6/96 13:33:46 [12/24/96 07:55:02]"; 
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
 
#define SOM_Module_eventch_Source 
#include "eventcom.xih" 
#include "eventch.xih" 
 
 
SOM_Scope EventComm_EventConnection * 
    SOMLINK EventChannelAdmin_ConsumerAdminadd_push_consumer 
				  (EventChannelAdmin_ConsumerAdmin *somSelf, 
				   Environment *ev, 
				   EventComm_Consumer *c) 
{ 
    /* EventChannelAdmin_ConsumerAdminData *somThis = EventChannelAdmin_ConsumerAdminGetData(somSelf); */ 
    EventComm_EventConnection * evcon = new EventComm_EventConnection; 
 
    EventChannelAdmin_ConsumerAdminMethodDebug("EventChannelAdmin_ConsumerAdmin", 
	 "EventChannelAdmin_ConsumerAdminadd_push_consumer"); 
 
    c->_set_ev_con(ev, evcon); 
 
    /* Return statement to be customized: */ 
    return (evcon); 
} 
 
 
SOM_Scope EventComm_Supplier * 
	       SOMLINK EventChannelAdmin_ConsumerAdminadd_pull_consumer 
			(EventChannelAdmin_ConsumerAdmin *somSelf, 
			 Environment *ev, 
			 EventComm_EventConnection *d) 
{ 
    EventComm_Supplier  *supp; 
    /* EventChannelAdmin_ConsumerAdminData *somThis = EventChannelAdmin_ConsumerAdminGetData(somSelf); */ 
    EventChannelAdmin_ConsumerAdminMethodDebug("EventChannelAdmin_ConsumerAdmin", 
	 "EventChannelAdmin_ConsumerAdminadd_pull_consumer"); 
 
    supp = new EventComm_Supplier; 
    supp->_set_ev_con(ev, d); 
 
    /* Return statement to be customized: */ 
    return (supp); 
} 
 
 
SOM_Scope EventComm_EventConnection * 
		  SOMLINK EventChannelAdmin_SupplierAdminadd_pull_supplier 
		       (EventChannelAdmin_SupplierAdmin *somSelf, 
			Environment *ev, 
			EventComm_Supplier *s) 
{ 
 
    /* EventChannelAdmin_SupplierAdminData *somThis = EventChannelAdmin_SupplierAdminGetData(somSelf); */ 
    EventComm_EventConnection *evcon = new EventComm_EventConnection; 
 
    EventChannelAdmin_SupplierAdminMethodDebug("EventChannelAdmin_SupplierAdmin", 
	 "EventChannelAdmin_Sup plierAdminadd_pull_supplier"); 
 
    s->_set_ev_con(ev, evcon); 
 
    /* Return statement to be customized: */ 
    return (evcon); 
} 
 
 
SOM_Scope EventComm_Consumer * 
	  SOMLINK EventChannelAdmin_SupplierAdminadd_push_supplier 
			(EventChannelAdmin_SupplierAdmin *somSelf, 
			 Environment *ev, 
			 EventComm_EventConnection *d) 
{ 
    EventComm_Consumer *cons; 
 
    /* EventChannelAdmin_SupplierAdminData *somThis = EventChannelAdmin_SupplierAdminGetData(somSelf); */ 
    EventChannelAdmin_SupplierAdminMethodDebug("EventChannelAdmin_SupplierAdmin", 
	 "EventChannelAdmin_SupplierAdminadd_push_supplier"); 
 
    cons = new EventComm_Consumer; 
    cons->_set_ev_con(ev, d); 
 
    /* Return statement to be customized: */ 
    return (cons); 
} 
 
 
SOM_Scope EventChannelAdmin_ConsumerAdmin * 
	     SOMLINK EventChannelAdmin_EventChannelfor_consumers 
		       (EventChannelAdmin_EventChannel *somSelf, 
			Environment *ev) 
{ 
    EventChannelAdmin_EventChannelData *somThis = EventChannelAdmin_EventChannelGetData(somSelf); 
    EventChannelAdmin_EventChannelMethodDebug("EventChannelAdmin_EventChannel", 
	 "EventChannelAdmin_EventChannelfor_consumers"); 
 
    if (somThis->cons_admin == (EventChannelAdmin_ConsumerAdmin *)0) 
    { 
      somThis->cons_admin = new EventChannelAdmin_ConsumerAdmin; 
    } 
 
    return (somThis->cons_admin); 
} 
 
 
SOM_Scope EventChannelAdmin_SupplierAdmin * 
	       SOMLINK EventChannelAdmin_EventChannelfor_suppliers 
		     (EventChannelAdmin_EventChannel *somSelf, 
		      Environment *ev) 
{ 
    EventChannelAdmin_EventChannelData *somThis = EventChannelAdmin_EventChannelGetData(somSelf); 
    EventChannelAdmin_EventChannelMethodDebug("EventChannelAdmin_EventChannel", 
	 "EventChannelAdmin_EventChannelfor_suppliers"); 
 
    if (somThis->supp_admin == (EventChannelAdmin_SupplierAdmin *)0) 
    { 
       somThis->supp_admin = new EventChannelAdmin_SupplierAdmin; 
    } 
 
    return somThis->supp_admin; 
} 
 
 
SOM_Scope void  SOMLINK EventChannelAdmin_EventChanneldestroy 
	      (EventChannelAdmin_EventChannel *somSelf, 
	       Environment *ev) 
{ 
    EventChannelAdmin_EventChannelData *somThis = EventChannelAdmin_EventChannelGetData(somSelf); 
    EventChannelAdmin_EventChannelMethodDebug("EventChannelAdmin_EventChannel", 
	 "EventChannelAdmin_EventChanneldestroy"); 
 
    somThis->supp_admin->somFree(); 
    somThis->cons_admin->somFree(); 
    somSelf->somFree(); 
} 
 
