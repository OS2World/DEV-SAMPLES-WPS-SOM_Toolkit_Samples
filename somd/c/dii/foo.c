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
static char *sccsid = "@(#) 2.7.1.1 src/somples.os2/somd/c/dii/foo.c, somples.somd, som3.0 12/2/96 17:44:58 [12/24/96 07:40:51]";
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


#define Foo_Class_Source

#include <somdtype.h>
#include "foo.ih"

SOM_Scope string  SOMLINK method1(Foo somSelf, Environment *ev,
                                  string *a, long *b, _IDL_SEQUENCE_octet *c)
{
    /* FooData *somThis = FooGetData(somSelf); */
    FooMethodDebug("Foo","method1");

    /* set return value for out string parameter */
    *a = "abc";

    /* set return value for inout long parameter */
    *b =  c->_maximum + *b;

    /* return results */
    return("method1 completed");
}
