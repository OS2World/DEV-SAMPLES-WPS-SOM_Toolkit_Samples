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
static char *sccsid = "@(#) 1.1 src/somples.os2/somk/c/tp/helper.c, somples.somk, som3.0 12/2/96 13:54:23 [12/24/96 07:41:00]";
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
 * This class is adapted from the book
 *   Class Construction in C and C++, Object Oriented Fundamentals
 *   by Roger Sessions, Copyright (c) 1992 Prentice Hall.
 * Reprinted with permission.
 */

/* File: helper.c */

#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

/* ************************************************************ */
void shouldHaveOverridden(SOMObject thisObject, string methodName)
{
    string class = _somGetClassName(thisObject);

    printf("RUN TIME ERROR\n");
    printf("method: %s invoked on object of class: %s\n", methodName, class);
    printf("%s MUST override %s, and has not.\n", class, methodName);
    exit(1);
}
