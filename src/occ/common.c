/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ/common.c $                                            */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

// Description: Standard Library Calls

#include "ssx.h"
#include "ssx_io.h"
#include <common.h>
#include <trac_service_codes.h>
#include <string.h>

// Function Specification
//
// Name: memcmp
//
// Description: Standard Library Calls
//              Need implemented, since we can't statically link in Open Source libs
//              These implementations aren't optimized, but allow the code to function
//              so we can test out the code port.
//
// End Function Specification
//int memcmp ( const void * ptr1, const void * ptr2, size_t num )
//{
//  return 0;
//}

// Function Specification
//
// Name: gpstCheckByte
//
// Description: Generate check byte for each entry of the Pstate table.
//
// End Function Specification
uint8_t gpstCheckByte(const uint64_t gpstEntry)
{
    int cb[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    cb[0] ^= BIT(gpstEntry, 0);
    cb[0] ^= BIT(gpstEntry, 1);
    cb[0] ^= BIT(gpstEntry, 2);
    cb[0] ^= BIT(gpstEntry, 3);
    cb[0] ^= BIT(gpstEntry, 4);
    cb[0] ^= BIT(gpstEntry, 5);
    cb[0] ^= BIT(gpstEntry, 6);
    cb[0] ^= BIT(gpstEntry, 7);
    cb[0] ^= BIT(gpstEntry, 24);
    cb[0] ^= BIT(gpstEntry, 25);
    cb[0] ^= BIT(gpstEntry, 26);
    cb[0] ^= BIT(gpstEntry, 28);
    cb[0] ^= BIT(gpstEntry, 33);
    cb[0] ^= BIT(gpstEntry, 38);
    cb[0] ^= BIT(gpstEntry, 42);
    cb[0] ^= BIT(gpstEntry, 43);
    cb[0] ^= BIT(gpstEntry, 44);
    cb[0] ^= BIT(gpstEntry, 45);
    cb[0] ^= BIT(gpstEntry, 52);
    cb[0] ^= BIT(gpstEntry, 53);
    cb[0] ^= BIT(gpstEntry, 54);
    cb[0] ^= BIT(gpstEntry, 55);
    cb[1] ^= BIT(gpstEntry, 0);
    cb[1] ^= BIT(gpstEntry, 3);
    cb[1] ^= BIT(gpstEntry, 4);
    cb[1] ^= BIT(gpstEntry, 7);
    cb[1] ^= BIT(gpstEntry, 8);
    cb[1] ^= BIT(gpstEntry, 9);
    cb[1] ^= BIT(gpstEntry, 10);
    cb[1] ^= BIT(gpstEntry, 11);
    cb[1] ^= BIT(gpstEntry, 12);
    cb[1] ^= BIT(gpstEntry, 13);
    cb[1] ^= BIT(gpstEntry, 14);
    cb[1] ^= BIT(gpstEntry, 15);
    cb[1] ^= BIT(gpstEntry, 32);
    cb[1] ^= BIT(gpstEntry, 33);
    cb[1] ^= BIT(gpstEntry, 34);
    cb[1] ^= BIT(gpstEntry, 36);
    cb[1] ^= BIT(gpstEntry, 41);
    cb[1] ^= BIT(gpstEntry, 46);
    cb[1] ^= BIT(gpstEntry, 50);
    cb[1] ^= BIT(gpstEntry, 51);
    cb[1] ^= BIT(gpstEntry, 52);
    cb[1] ^= BIT(gpstEntry, 53);
    cb[2] ^= BIT(gpstEntry, 4);
    cb[2] ^= BIT(gpstEntry, 5);
    cb[2] ^= BIT(gpstEntry, 6);
    cb[2] ^= BIT(gpstEntry, 7);
    cb[2] ^= BIT(gpstEntry, 8);
    cb[2] ^= BIT(gpstEntry, 11);
    cb[2] ^= BIT(gpstEntry, 12);
    cb[2] ^= BIT(gpstEntry, 15);
    cb[2] ^= BIT(gpstEntry, 16);
    cb[2] ^= BIT(gpstEntry, 17);
    cb[2] ^= BIT(gpstEntry, 18);
    cb[2] ^= BIT(gpstEntry, 19);
    cb[2] ^= BIT(gpstEntry, 20);
    cb[2] ^= BIT(gpstEntry, 21);
    cb[2] ^= BIT(gpstEntry, 22);
    cb[2] ^= BIT(gpstEntry, 23);
    cb[2] ^= BIT(gpstEntry, 40);
    cb[2] ^= BIT(gpstEntry, 41);
    cb[2] ^= BIT(gpstEntry, 42);
    cb[2] ^= BIT(gpstEntry, 44);
    cb[2] ^= BIT(gpstEntry, 49);
    cb[2] ^= BIT(gpstEntry, 54);
    cb[3] ^= BIT(gpstEntry, 2);
    cb[3] ^= BIT(gpstEntry, 3);
    cb[3] ^= BIT(gpstEntry, 4);
    cb[3] ^= BIT(gpstEntry, 5);
    cb[3] ^= BIT(gpstEntry, 12);
    cb[3] ^= BIT(gpstEntry, 13);
    cb[3] ^= BIT(gpstEntry, 14);
    cb[3] ^= BIT(gpstEntry, 15);
    cb[3] ^= BIT(gpstEntry, 16);
    cb[3] ^= BIT(gpstEntry, 19);
    cb[3] ^= BIT(gpstEntry, 20);
    cb[3] ^= BIT(gpstEntry, 23);
    cb[3] ^= BIT(gpstEntry, 24);
    cb[3] ^= BIT(gpstEntry, 25);
    cb[3] ^= BIT(gpstEntry, 26);
    cb[3] ^= BIT(gpstEntry, 27);
    cb[3] ^= BIT(gpstEntry, 28);
    cb[3] ^= BIT(gpstEntry, 29);
    cb[3] ^= BIT(gpstEntry, 30);
    cb[3] ^= BIT(gpstEntry, 31);
    cb[3] ^= BIT(gpstEntry, 48);
    cb[3] ^= BIT(gpstEntry, 49);
    cb[3] ^= BIT(gpstEntry, 50);
    cb[3] ^= BIT(gpstEntry, 52);
    cb[4] ^= BIT(gpstEntry, 1);
    cb[4] ^= BIT(gpstEntry, 6);
    cb[4] ^= BIT(gpstEntry, 10);
    cb[4] ^= BIT(gpstEntry, 11);
    cb[4] ^= BIT(gpstEntry, 12);
    cb[4] ^= BIT(gpstEntry, 13);
    cb[4] ^= BIT(gpstEntry, 20);
    cb[4] ^= BIT(gpstEntry, 21);
    cb[4] ^= BIT(gpstEntry, 22);
    cb[4] ^= BIT(gpstEntry, 23);
    cb[4] ^= BIT(gpstEntry, 24);
    cb[4] ^= BIT(gpstEntry, 27);
    cb[4] ^= BIT(gpstEntry, 28);
    cb[4] ^= BIT(gpstEntry, 31);
    cb[4] ^= BIT(gpstEntry, 32);
    cb[4] ^= BIT(gpstEntry, 33);
    cb[4] ^= BIT(gpstEntry, 34);
    cb[4] ^= BIT(gpstEntry, 35);
    cb[4] ^= BIT(gpstEntry, 36);
    cb[4] ^= BIT(gpstEntry, 37);
    cb[4] ^= BIT(gpstEntry, 38);
    cb[4] ^= BIT(gpstEntry, 39);
    cb[5] ^= BIT(gpstEntry, 0);
    cb[5] ^= BIT(gpstEntry, 1);
    cb[5] ^= BIT(gpstEntry, 2);
    cb[5] ^= BIT(gpstEntry, 4);
    cb[5] ^= BIT(gpstEntry, 9);
    cb[5] ^= BIT(gpstEntry, 14);
    cb[5] ^= BIT(gpstEntry, 18);
    cb[5] ^= BIT(gpstEntry, 19);
    cb[5] ^= BIT(gpstEntry, 20);
    cb[5] ^= BIT(gpstEntry, 21);
    cb[5] ^= BIT(gpstEntry, 28);
    cb[5] ^= BIT(gpstEntry, 29);
    cb[5] ^= BIT(gpstEntry, 30);
    cb[5] ^= BIT(gpstEntry, 31);
    cb[5] ^= BIT(gpstEntry, 32);
    cb[5] ^= BIT(gpstEntry, 35);
    cb[5] ^= BIT(gpstEntry, 36);
    cb[5] ^= BIT(gpstEntry, 39);
    cb[5] ^= BIT(gpstEntry, 40);
    cb[5] ^= BIT(gpstEntry, 41);
    cb[5] ^= BIT(gpstEntry, 42);
    cb[5] ^= BIT(gpstEntry, 43);
    cb[5] ^= BIT(gpstEntry, 44);
    cb[5] ^= BIT(gpstEntry, 45);
    cb[5] ^= BIT(gpstEntry, 46);
    cb[5] ^= BIT(gpstEntry, 47);
    cb[6] ^= BIT(gpstEntry, 8);
    cb[6] ^= BIT(gpstEntry, 9);
    cb[6] ^= BIT(gpstEntry, 10);
    cb[6] ^= BIT(gpstEntry, 12);
    cb[6] ^= BIT(gpstEntry, 17);
    cb[6] ^= BIT(gpstEntry, 22);
    cb[6] ^= BIT(gpstEntry, 26);
    cb[6] ^= BIT(gpstEntry, 27);
    cb[6] ^= BIT(gpstEntry, 28);
    cb[6] ^= BIT(gpstEntry, 29);
    cb[6] ^= BIT(gpstEntry, 36);
    cb[6] ^= BIT(gpstEntry, 37);
    cb[6] ^= BIT(gpstEntry, 38);
    cb[6] ^= BIT(gpstEntry, 39);
    cb[6] ^= BIT(gpstEntry, 40);
    cb[6] ^= BIT(gpstEntry, 43);
    cb[6] ^= BIT(gpstEntry, 44);
    cb[6] ^= BIT(gpstEntry, 47);
    cb[6] ^= BIT(gpstEntry, 48);
    cb[6] ^= BIT(gpstEntry, 49);
    cb[6] ^= BIT(gpstEntry, 50);
    cb[6] ^= BIT(gpstEntry, 51);
    cb[6] ^= BIT(gpstEntry, 52);
    cb[6] ^= BIT(gpstEntry, 53);
    cb[6] ^= BIT(gpstEntry, 54);
    cb[6] ^= BIT(gpstEntry, 55);
    cb[7] ^= BIT(gpstEntry, 16);
    cb[7] ^= BIT(gpstEntry, 17);
    cb[7] ^= BIT(gpstEntry, 18);
    cb[7] ^= BIT(gpstEntry, 20);
    cb[7] ^= BIT(gpstEntry, 25);
    cb[7] ^= BIT(gpstEntry, 30);
    cb[7] ^= BIT(gpstEntry, 34);
    cb[7] ^= BIT(gpstEntry, 35);
    cb[7] ^= BIT(gpstEntry, 36);
    cb[7] ^= BIT(gpstEntry, 37);
    cb[7] ^= BIT(gpstEntry, 44);
    cb[7] ^= BIT(gpstEntry, 45);
    cb[7] ^= BIT(gpstEntry, 46);
    cb[7] ^= BIT(gpstEntry, 47);
    cb[7] ^= BIT(gpstEntry, 48);
    cb[7] ^= BIT(gpstEntry, 51);
    cb[7] ^= BIT(gpstEntry, 52);
    cb[7] ^= BIT(gpstEntry, 55);
    return
        (cb[0] << 7) |
        (cb[1] << 6) |
        (cb[2] << 5) |
        (cb[3] << 4) |
        (cb[4] << 3) |
        (cb[5] << 2) |
        (cb[6] << 1) |
        (cb[7] << 0);
}
