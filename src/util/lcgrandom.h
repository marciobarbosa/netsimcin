//==========================================================================
//  LCGRANDOM.H - part of
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//  Author: Andras Varga
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 2006-2008 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __LCGRANDOM_H
#define __LCGRANDOM_H

#include "commondefs.h"
#include "intxtypes.h"
#include "exception.h"

NAMESPACE_BEGIN

#define GLRAND_MAX  0x7ffffffeL  /* = 2**31-2 */

/**
 * Our RNG on [0,1), for the layouting library and other non-simulation purposes.
 * C's rand() is not to be trusted.
 */
class COMMON_API LCGRandom
{
    private:
        int32 seed;

    public:
        LCGRandom(int32 seed=1);

        int32 getSeed() { return seed; }
        void setSeed(int32 seed);

        double next01();

        int draw(int range);

        void selfTest();
};

NAMESPACE_END


#endif
