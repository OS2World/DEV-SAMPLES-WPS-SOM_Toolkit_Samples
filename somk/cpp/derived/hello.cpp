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
static char *sccsid = "@(#) 1.3 src/somples.os2/somk/cpp/derived/hello.cpp, somk.tst, som3.0 12/13/96 11:27:20 [12/24/96 07:41:06]";
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

#define Hello_Class_Source
#include "hello.xih"
#include <stdio.h>

/*
 * -- Method Procedures for Hello
 */

/*
 *  This operation outputs the string "Hello World".
 */

SOM_Scope string SOMLINK hello_(Hello *somSelf)
{
    HelloData *somThis = HelloGetData(somSelf); 
    HelloMethodDebug("Hello","hello");

    return somSelf->_get_hellomsg();
}


/*
 * Override the inherited implementation of somInit.
 */

SOM_Scope void  SOMLINK somInit(Hello *somSelf)
{
    HelloData *somThis = HelloGetData(somSelf);
    HelloMethodDebug("Hello","somInit");

    somSelf->_set_hellomsg("Hello World");
    parent_SOMObject_somInit(somSelf);
}

SOM_Scope void  SOMLINK M_somInit(M_Hello *somSelf)
{
/*     HelloData *somThis = M_HelloGetData(somSelf); */
    HelloMethodDebug("M_Hello","somInit");

    parent_SOMClass_somInit(somSelf);
}

/*
 *  This method creates an instance of the Hello class and
 *  uses the value of "msg" to initialise it.
 */

SOM_Scope Hello*  SOMLINK M_HelloCreate(M_Hello *somSelf,
		char* msg)
{
    /* M_HelloData *somThis = M_HelloGetData(somSelf); */
    M_HelloMethodDebug("M_Hello","HelloCreate");

    Hello *hello = somSelf->somNew();
    hello->_set_hellomsg(msg);
    return (hello);
}
