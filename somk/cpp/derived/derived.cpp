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
static char *sccsid = "@(#) 1.3 src/somples.os2/somk/cpp/derived/derived.cpp, somk.tst, som3.0 12/13/96 11:27:16 [12/24/96 07:41:05]";
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

#define Test_Class_Source
#include <derived.xih>

/*
 * -- Original Instance Data (this is a comment -- actual defn in test.xih)
 */
/*
typedef void TestData;
*/

/*
 * -- Method Procedures for Test
 */

SOM_Scope void  SOMLINK somInit(Test *somSelf)
{
    /* TestData *somThis = TestGetData(somSelf); */
    TestMethodDebug("Test","somInit");

    parent_Hello_somInit(somSelf);
    parent_Mello_somInit(somSelf);
}
