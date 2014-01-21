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
static char *sccsid = "@(#) 1.1 src/somples.os2/somk/c/animals/animals.c, somples.somk, som3.0 12/2/96 14:00:45 [12/24/96 07:40:56]";
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


#define SOM_Module_animals_Source
#include <animals.ih>

#include <animals.ih>

#define BUFFER_INCREMENT_COUNT 20
#define BUFFER_INCREMENT_SIZE (BUFFER_INCREMENT_COUNT*sizeof(Animals_Animal*))

/*
 *  The name of the animal.
 */

SOM_Scope void  SOMLINK a__set_name (Animals_Animal somSelf, Environment *ev,
		string myName)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a__set_name");

    if (_name)
        SOMFree(_name);
    if (myName) {
        _name = (string) SOMMalloc(strlen(myName) + 1);
        strcpy(_name, myName);
    } else
	_name = (string) NULL;
}

/*
 *  The kind of sound that an animal makes.
 */

SOM_Scope void  SOMLINK a__set_sound (Animals_Animal somSelf, Environment *ev,
		string mySound)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a__set_sound");

    if (_sound)
        SOMFree(_sound);
    if (mySound) {
	_sound = (string) SOMMalloc(strlen(mySound) + 1);
        strcpy(_sound, mySound);
    } else
	_sound = (string) NULL;
}

/*
 *  The genus of animal.
 *  The "_get_" method for this attribute should be overridden
 *  by derived classes.  The default version here just gives
 *  "<unknown>" as the genus.
 */

SOM_Scope string  SOMLINK a__get_genus(Animals_Animal somSelf, Environment *ev)
{
    Animals_AnimalMethodDebug("Animals_Animal","a__get_genus");

    return ("<Unknown>");
}

/*
 *  The species of animal.
 *  The "_get" method for this attribute should be overridden
 *  by derived classes.  The default version here just gives
 *  "<unknown>" as the species.
 */

SOM_Scope string  SOMLINK a__get_species(Animals_Animal somSelf, Environment *ev)
{
    Animals_AnimalMethodDebug("Animals_Animal","a__get_species");

    return ("<Unknown>");
}

/*
 *  Ask the animal to talk.  Normally this just prints out the
 *  string corresponding to the sound attribute, but it can be
 *  overridden to do something else.
 */

SOM_Scope void  SOMLINK a_talk(Animals_Animal somSelf, Environment *ev)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a_talk");

    somPrintf("\t%s\n", _sound ? _sound : "<Unknown>");
}

/*
 *  Displays an animal.	Derived classes should override this to
 *  display new derived information, and then call their parent
 *  version. Note: this method makes use of talk() to describe what
 *  the animal says.
 */

SOM_Scope void  SOMLINK a_display(Animals_Animal somSelf, Environment *ev)
{
    Animals_AnimalMethodDebug("Animals_Animal","a_display");

    somPrintf ("\nThe animal named %s", Animals_Animal__get_name (somSelf, ev));
    somPrintf (" (Genus: %s,", Animals_Animal__get_genus (somSelf, ev));
    somPrintf (" Species: %s) says:\n", Animals_Animal__get_species (somSelf,
	ev));
    Animals_Animal_talk (somSelf, ev);
}

SOM_Scope void  SOMLINK a_somFree(Animals_Animal somSelf)
{
    Environment *ev = somGetGlobalEnvironment ();
    Animals_AnimalMethodDebug("Animals_Animal","a_somFree");

    /* Reduce the animal population */
    Animals_M_Animal_deleteInstance (_Animals_Animal, ev, somSelf);
    Animals_Animal_parent_SOMObject_somFree (somSelf);
}

SOM_Scope void  SOMLINK a_somInit(Animals_Animal somSelf)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a_somInit");

    Animals_Animal_parent_SOMObject_somInit (somSelf);
    _sound = (string) NULL;
}

SOM_Scope void  SOMLINK a_somUninit(Animals_Animal somSelf)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a_somUninit");

    if (_sound)
        SOMFree (_sound);
    Animals_Animal_parent_SOMObject_somUninit (somSelf);
}

SOM_Scope void  SOMLINK a_somDumpSelfInt(Animals_Animal somSelf,
		long level)
{
    Animals_AnimalData *somThis = Animals_AnimalGetData(somSelf);
    Animals_AnimalMethodDebug("Animals_Animal","a_somDumpSelfInt");

    Animals_Animal_display (somSelf, somGetGlobalEnvironment());
    Animals_Animal_parent_SOMObject_somDumpSelfInt (somSelf, level);
}

/*
 *  Create an instance of an Animals_Animal with a specific sound.
 */

SOM_Scope Animals_Animal  SOMLINK ma_newAnimal (Animals_M_Animal somSelf,
    Environment *ev, string name, string sound)
{
    Animals_Animal animal;
    Animals_M_AnimalData *somThis = Animals_M_AnimalGetData(somSelf);
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_newAnimal");

    animal = (Animals_Animal)
	Animals_M_Animal_parent_SOMClass_somNew (somSelf);
    /* Bump animal population */
    /* _Animals_Animal, not somSelf! */
    Animals_M_Animal_addInstance (_Animals_Animal, ev, animal);
    Animals_Animal__set_name (animal, ev, name);
    Animals_Animal__set_sound (animal, ev, sound);
    return (animal);
}

/*
 *  Used to add an new instance to the instances sequence.
 */

SOM_Scope void SOMLINK ma_addInstance (Animals_M_Animal somSelf,
    Environment *ev, Animals_Animal obj)
{
    int i;
    Animals_Animal *newbuf;
    Animals_M_AnimalData *somThis = Animals_M_AnimalGetData(somSelf);
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_addInstance");

    if (_instances._length < _instances._maximum)
	_instances._buffer[_instances._length++] = obj;
    else {
        _instances._maximum += BUFFER_INCREMENT_COUNT;
	newbuf = (Animals_Animal *) SOMRealloc (_instances._buffer,
		BUFFER_INCREMENT_SIZE);
	if (newbuf) {
            _instances._buffer = newbuf;
            _instances._buffer[_instances._length++] = obj;
        }
    }
}

/*
 *  Used to remove an instance from the instances sequence.
 */

SOM_Scope void SOMLINK ma_deleteInstance (Animals_M_Animal somSelf,
    Environment *ev, Animals_Animal obj)
{
    int i;
    Animals_M_AnimalData *somThis = Animals_M_AnimalGetData(somSelf);
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_deleteInstance");

    for (i=0; i<_instances._length; i++) {
        if (obj == _instances._buffer[i]) {
	    _instances._buffer[i] = _instances._buffer[--_instances._length];
	    break;
        }
    }
}

SOM_Scope SOMObject  SOMLINK ma_somNew(Animals_M_Animal somSelf)
{
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_somNew");

    return Animals_M_Animal_newAnimal (somSelf, somGetGlobalEnvironment (),
	"<Unnamed>", (string) NULL);
}

SOM_Scope void  SOMLINK ma_somInit(Animals_M_Animal somSelf)
{
    Animals_M_AnimalData *somThis = Animals_M_AnimalGetData(somSelf);
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_somInit");

    _instances._buffer = (Animals_Animal *) SOMMalloc (BUFFER_INCREMENT_SIZE);
    _instances._maximum = BUFFER_INCREMENT_COUNT;
    _instances._length = 0;
    Animals_M_Animal_parent_SOMClass_somInit (somSelf);
}

SOM_Scope void  SOMLINK ma_somUninit(Animals_M_Animal somSelf)
{
    Animals_M_AnimalData *somThis = Animals_M_AnimalGetData(somSelf);
    Animals_M_AnimalMethodDebug("Animals_M_Animal","ma_somUninit");

    if (_instances._buffer)
	SOMFree (_instances._buffer);
    _instances._length = _instances._maximum = 0;
    Animals_M_Animal_parent_SOMClass_somInit (somSelf);
}

/*
 *  The breed of this Dog.
 */

SOM_Scope void  SOMLINK d__set_breed (Animals_Dog somSelf, Environment *ev,
		string myBreed)
{
    Animals_DogData *somThis = Animals_DogGetData(somSelf);
    Animals_DogMethodDebug("Animals_Dog","d__set_breed");

    if (_breed)
        SOMFree (_breed);
    if (myBreed) {
        _breed = (string) SOMMalloc (strlen (myBreed) + 1);
        strcpy (_breed, myBreed);
    } else
	_breed = (string) NULL;
}

/*
 *  The color of this Dog.
 */

SOM_Scope void  SOMLINK d__set_color (Animals_Dog somSelf, Environment *ev,
		string myColor)
{
    Animals_DogData *somThis = Animals_DogGetData(somSelf);
    Animals_DogMethodDebug("Animals_Dog","d__set_color");

    if (_color)
        SOMFree (_color);
    if (myColor) {
        _color = (string) SOMMalloc (strlen (myColor) + 1);
        strcpy (_color, myColor);
    } else
	_color = (string) NULL;
}

SOM_Scope string  SOMLINK d__get_genus (Animals_Dog somSelf, Environment *ev)
{
    Animals_DogMethodDebug("Animals_Dog","d__get_genus");

    return ("Canis");
}

SOM_Scope string  SOMLINK d__get_species (Animals_Dog somSelf, Environment *ev)
{
    Animals_DogMethodDebug("Animals_Dog","d__get_species");

    return ("Familiaris");
}

SOM_Scope void  SOMLINK d_display (Animals_Dog somSelf, Environment *ev)
{
    Animals_DogMethodDebug("Animals_Dog","d_display");

    Animals_Dog_parent_Animals_Animal_display (somSelf, ev);
    somPrintf("It's breed is %s", __get_breed (somSelf, ev));
    somPrintf(" and its color is %s.\n", __get_color (somSelf, ev));
}

SOM_Scope void  SOMLINK d_somInit(Animals_Dog somSelf)
{
    Animals_DogData *somThis = Animals_DogGetData(somSelf);
    Animals_DogMethodDebug("Animals_Dog","d_somInit");

    Animals_Dog_parent_Animals_Animal_somInit (somSelf);
    _color = (string) NULL;
    _breed = (string) NULL;
}

SOM_Scope void  SOMLINK d_somUninit(Animals_Dog somSelf)
{
    Animals_DogData *somThis = Animals_DogGetData(somSelf);
    Animals_DogMethodDebug("Animals_Dog","d_somUninit");

    if (_color)
        SOMFree(_color);
    if (_breed)
        SOMFree(_breed);
    Animals_Dog_parent_Animals_Animal_somUninit (somSelf);
}

SOM_Scope void  SOMLINK d_somDumpSelfInt(Animals_Dog somSelf, long level)
{
    Animals_DogMethodDebug("Animals_Dog","d_somDumpSelfInt");

    Animals_Dog_parent_Animals_Animal_somDumpSelfInt (somSelf, level);
}

/*
 *  Create an instance of a Animals_Dog with a specific name,
 *  sound, breed, & color.
 */

SOM_Scope Animals_Dog  SOMLINK md_newDog(Animals_Kennel somSelf,
    Environment *ev, string name, string sound, string breed, string color)
{
    Animals_KennelData *somThis = Animals_KennelGetData(somSelf);
    Animals_Dog dog;
    Animals_KennelMethodDebug("Animals_Kennel","md_newDog");

    dog = Animals_M_Animal_newAnimal (somSelf, ev, name, sound);
    Animals_Dog__set_breed (dog, ev, breed);
    Animals_Dog__set_color (dog, ev, color);
    return (dog);
}

SOM_Scope SOMObject  SOMLINK md_somNew(Animals_Kennel somSelf)
{
    Animals_KennelData *somThis = Animals_KennelGetData(somSelf);
    Animals_KennelMethodDebug("Animals_Kennel","md_somNew");

    return (Animals_Kennel_parent_SOMClass_somNew (somSelf));
}

SOM_Scope void  SOMLINK bd_talk(Animals_BigDog somSelf, Environment *ev)
{
    string sound;
    Animals_BigDogMethodDebug("Animals_BigDog","bd_talk");

    somPrintf ("\tWOOF WOOF\n");
    somPrintf ("\tWOOF WOOF\n");
    somPrintf ("\tWOOF WOOF\n");
    somPrintf ("\tWOOF WOOF\n");
    sound = Animals_Animal__get_sound (somSelf, ev);
    if (sound)
        somPrintf ("(and sometimes: %s)\n", sound);
}

SOM_Scope void  SOMLINK ld_talk(Animals_LittleDog somSelf, Environment *ev)
{
    string sound;
    Animals_LittleDogMethodDebug("Animals_LittleDog","ld_talk");

    somPrintf ("\twoof woof\n");
    somPrintf ("\twoof woof\n");
    sound = Animals_Animal__get_sound (somSelf, ev);
    if (sound)
        somPrintf ("(and sometimes: %s)\n", sound);
}
