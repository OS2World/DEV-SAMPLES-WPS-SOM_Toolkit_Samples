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
static char *sccsid = "@(#) 1.1 src/somples.os2/somk/cpp/simple/main.cpp, somples.somk, som3.0 12/2/96 14:11:54 [12/24/96 07:41:07]";
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
#include "simple.xh"

int main()
{
    Simple *s1 = new Simple;       // this runs somDefaultInit
    Simple *s2 = new Simple(23);   // this runs withX
    Simple *s3 = new Simple(10,3); // this runs withXandY 

    SOM_Test(42 == s1->_get_x());    /* test initial values */
    SOM_Test(24 == s2->_get_y());
    SOM_Test(13 == s3->_get_x()+s3->_get_y());
   
    delete s1;
    delete s2;
    delete s3;
    SOM_Test(0==somIsObj(s1)); // verify no longer objects

    printf("simple: test successfully completed.\n");
    return 0;
}

