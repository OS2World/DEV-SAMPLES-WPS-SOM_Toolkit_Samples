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
static char *sccsid = "@(#) 1.3 src/somples.os2/somk/cpp/derived/main.cpp, somk.tst, som3.0 12/13/96 11:27:25 [12/24/96 07:41:06]";
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

#include "derived.xh"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    Test *test = new Test;

    SOM_Test(!strcmp(test->somGetClassName(),"Test"));

    SOM_Test(test->somRespondsTo(somIdFromString("hello_")) == 1);
    SOM_Test(!strcmp(test->hello_(),"Hello World"));
    SOM_Test(test->somRespondsTo(somIdFromString("mello_")) == 1);
    SOM_Test(!strcmp(test->mello_(),"Mello World"));

    SOM_Test(test->somGetClass()->somRespondsTo(somIdFromString("HelloCreate")) == 1);
    Hello *a = ((M_Hello*) (test->somGetClass()))->HelloCreate("Hello from A");
    SOM_Test(!strcmp(a->hello_(),"Hello from A"));

    SOM_Test(test->somGetClass()->somRespondsTo(somIdFromString("MelloCreate")) == 1);
    Mello *b = ((M_Mello*) (test->somGetClass()))->MelloCreate("Mello from B");
    SOM_Test(!strcmp(b->mello_(),"Mello from B"));

    Hello *c = (Hello*) (test->somGetClass()->somNew());
    Mello *d = (Mello*) (test->somGetClass()->somNew());

    SOM_Test(!strcmp(c->hello_(),"Hello World"));
    SOM_Test(!strcmp(d->mello_(),"Mello World"));

    printf("Derived Metaclass Test Successfully Completed.\n");
    return 0;
}
