/*
 * Copyright (c) 2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Patent rights are not granted under this agreement. Patent rights are
 *       available under FRAND terms.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX or PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//  testdata_common.h
//  TransportRTA
//
//  Created by Marc Mosko on 7/27/14.
//  Copyright (c) 2014 Mosko, Marc <Marc.Mosko@parc.com>. All rights reserved.
//

#ifndef TransportRTA_testdata_common_h
#define TransportRTA_testdata_common_h

#include <ccnx/common/codec/ccnxCodec_Error.h>

typedef struct tlv_extent {
    uint16_t offset;
    uint16_t length;
} TlvExtent;

// Equal to { 0xFFFF, 0xFFFF }
extern const TlvExtent TlvExtentNotFound;

/**
 * Determine if two TlvExtent instances are equal.
 *
 * The following equivalence relations on non-null `TlvExtent` instances are maintained:
 *
 *  * It is reflexive: for any non-null reference value x, `TlvExtent_Equals(x, x)`
 *      must return true.
 *
 *  * It is symmetric: for any non-null reference values x and y,
 *    `tlvExtent_Equals(x, y)` must return true if and only if
 *        `tlvExtent_Equals(y, x)` returns true.
 *
 *  * It is transitive: for any non-null reference values x, y, and z, if
 *        `tlvExtent_Equals(x, y)` returns true and
 *        `tlvExtent_Equals(y, z)` returns true,
 *        then  `tlvExtent_Equals(x, z)` must return true.
 *
 *  * It is consistent: for any non-null reference values x and y, multiple
 *      invocations of `tlvExtent_Equals(x, y)` consistently return true or
 *      consistently return false.
 *
 *  * For any non-null reference value x, `tlvExtent_Equals(x, NULL)` must
 *      return false.
 *
 * @param a A pointer to a `TlvExtent` instance.
 * @param b A pointer to a `TlvExtent` instance.
 * @return true if the two `TlvExtent` instances are equal.
 *
 * Example:
 * @code
 * {
 *    TlvExtent *a = tlvExtent_Create();
 *    TlvExtent *b = tlvExtent_Create();
 *
 *    if (tlvExtent_Equals(a, b)) {
 *        // true
 *    } else {
 *        // false
 *    }
 * }
 * @endcode
 */
bool tlvExtent_Equals(const TlvExtent *a, const TlvExtent *b);

#define TRUTHTABLENAME(NAME) NAME ## _truthTableEntries

// easy way to generate table entries, so long as you use the standard naming
// convention for the the TruthTableEntry array
#define TABLEENTRY(NAME, ERROR) { .testname= #NAME, .packet= NAME, .length=sizeof(NAME), .expectedError=ERROR, .entry= TRUTHTABLENAME(NAME) }

typedef struct testrig_truth_table_entry {
    bool wellKnownType;

    // is the wellKnownType in the body manifest?  or the header?
    bool bodyManifest;

    // if its a well known type, this is the manifest array index
    // otherwise, its the unknown type value
    int indexOrKey;

    TlvExtent extent;
} TruthTableEntry;


typedef struct testrig_truth_table {
    const char *testname;
    uint8_t *packet;
    size_t length;

    CCNxCodecErrorCodes expectedError;

    // the array is terminated by a T_INVALID value
    // for "arrayIndexOrTypeKey"
    TruthTableEntry *entry;
} TruthTable;

#endif
