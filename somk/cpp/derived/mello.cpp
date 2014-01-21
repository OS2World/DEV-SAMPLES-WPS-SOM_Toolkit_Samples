//
//   COMPONENT_NAME: somx
//
//   ORIGINS: 27
//
//
//   25H7912  (C)  COPYRIGHT International Business Machines Corp. 1992,1996
//   All Rights Reserved
//   Licensed Materials - Property of IBM
//   US Government Users Restricted Rights - Use, duplication or
//   disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
//

#ifndef lint
static char *sccsid = "@(#) 1.3 src/somples.os2/somk/cpp/derived/mello.cpp, somk.tst, som3.0 12/13/96 11:27:26 [12/24/96 07:41:06]";
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

#define Mello_Class_Source
#include "mello.xih"
#include <stdio.h>

/*
 * -- Original Instance Data (this is a comment -- actual defn in mello.xih)
 */
/*
typedef struct {
	char* msg;
} MelloData;
*/

/*
 * -- Method Procedures for Mello
 */

SOM_Scope string SOMLINK mello_(Mello *somSelf)
{
    MelloData *somThis = MelloGetData(somSelf);
    MelloMethodDebug("Mello","mello");

    return somSelf->_get_msg();

}

SOM_Scope void  SOMLINK somInit(Mello *somSelf)
{
    MelloData *somThis = MelloGetData(somSelf);
    MelloMethodDebug("Mello","somInit");

    somSelf->_set_msg("Mello World");
    parent_SOMObject_somInit(somSelf);
}

SOM_Scope Mello*  SOMLINK MelloCreate(M_Mello *somSelf,
		char* msg)
{
    /* M_MelloData *somThis = M_MelloGetData(somSelf); */
    M_MelloMethodDebug("M_Mello","MelloCreate");

    Mello *mello = somSelf->somNew();
    mello->_set_msg(msg);
    return (mello);

}
