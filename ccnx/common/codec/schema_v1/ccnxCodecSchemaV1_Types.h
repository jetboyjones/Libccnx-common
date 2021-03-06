/*
 * Copyright (c) 2013-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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
/**
 * @file ccnxCodecSchemaV1_Types.h
 * @brief Common definitions for Schema version 1
 *
 * Defines the TLV "type" values for each field
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */

#ifndef TransportRTA_ccnxCodecSchemaV1_Types_h
#define TransportRTA_ccnxCodecSchemaV1_Types_h

#include <ccnx/common/codec/schema_v1/ccnxCodecSchemaV1_TlvDictionary.h>

/**
 * @typedef CCNxCodecSchemaV1Types_PacketType
 * @abstract The values used in the PacketType field of the Fixed Header
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_packet_type {
    CCNxCodecSchemaV1Types_PacketType_Interest = 0x00,
    CCNxCodecSchemaV1Types_PacketType_ContentObject = 0x01,
    CCNxCodecSchemaV1Types_PacketType_InterestReturn = 0x02,
    CCNxCodecSchemaV1Types_PacketType_Control = 0xA4,
} CCNxCodecSchemaV1Types_PacketType;

/**
 * @typedef CCNxCodecSchemaV1Types_MessageType
 * @abstract The values used in the MessageType field of the CCNx Message body
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_message_type {
    CCNxCodecSchemaV1Types_MessageType_Interest = 0x0001,
    CCNxCodecSchemaV1Types_MessageType_ContentObject = 0x0002,
    CCNxCodecSchemaV1Types_MessageType_ValidationAlg = 0x0003,
    CCNxCodecSchemaV1Types_MessageType_ValidationPayload = 0x0004,
    CCNxCodecSchemaV1Types_MessageType_Control = 0xBEEF,
} CCNxCodecSchemaV1Types_MessageType;

/**
 * @typedef CCNxCodecSchemaV1Types_OptionalHeadersTypes
 * @abstract The well-known keys for the hop-by-hop headers
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_optional_headers_types {
    CCNxCodecSchemaV1Types_OptionalHeaders_InterestLifetime = 0x0001,
    CCNxCodecSchemaV1Types_OptionalHeaders_RecommendedCacheTime = 0x0002,
    CCNxCodecSchemaV1Types_OptionalHeaders_InterestFragment = 0x0003,
    CCNxCodecSchemaV1Types_OptionalHeaders_ContentObjectFragment = 0x0004,
} CCNxCodecSchemaV1Types_OptionalHeaders;

/**
 * @typedef CCNxCodecSchemaV1Types_PayloadType
 * @abstract The values of the PayloadType field
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_payloadtype_types {
    CCNxCodecSchemaV1Types_PayloadType_Data = 0,
    CCNxCodecSchemaV1Types_PayloadType_Key = 1,
    CCNxCodecSchemaV1Types_PayloadType_Link = 2,
    CCNxCodecSchemaV1Types_PayloadType_Manifest = 3,
} CCNxCodecSchemaV1Types_PayloadType;

// ==================================================
// Fields in a Message Object

/**
 * @typedef CCNxCodecSchemaV1Types_MessageTypes
 * @abstract The well-known types inside the CCNxMessage
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_ccnxmessage_types {
    CCNxCodecSchemaV1Types_CCNxMessage_Name = 0x0000,
    CCNxCodecSchemaV1Types_CCNxMessage_Payload = 0x0001,
    CCNxCodecSchemaV1Types_CCNxMessage_KeyIdRestriction = 0x0002,
    CCNxCodecSchemaV1Types_CCNxMessage_ContentObjectHashRestriction = 0x0003,
    CCNxCodecSchemaV1Types_CCNxMessage_PayloadType = 0x0005,
    CCNxCodecSchemaV1Types_CCNxMessage_ExpiryTime = 0x0006,
    CCNxCodecSchemaV1Types_CCNxMessage_EndChunkNumber = 0x0019,
} CCNxCodecSchemaV1Types_CCNxMessage;


// ==================================================
// Fields in a Validation Algorithm

/**
 * @typedef CCNxCodecSchemaV1Types_ValidationAlg
 * @abstract The well-known keys for the ContentObject
 * @constant <#name#> <#description#>
 * @discussion the CCNxCodecSchemaV1Types_ValidationAlg values for the crypto suites must be the same as CCNxCodecSchemaV1Types_CryptoSuiteType
 */
typedef enum rta_tlv_schema_v1_validation_alg {
    CCNxCodecSchemaV1Types_ValidationAlg_CRC32C = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_CRC32C,                 // 0x0002
    CCNxCodecSchemaV1Types_ValidationAlg_HMAC_SHA256 = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_HmacSha256,       // 0x0004
    CCNxCodecSchemaV1Types_ValidationAlg_RSA_SHA256 = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_RsaSha256,         // 0x0006
    CCNxCodecSchemaV1Types_ValidationAlg_EC_SECP_256K1 = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_EcSecp256K1,   // 0x0007

    CCNxCodecSchemaV1Types_ValidationAlg_KeyId = 0x0009,
    CCNxCodecSchemaV1Types_ValidationAlg_PublicKey = 0x000B,
    CCNxCodecSchemaV1Types_ValidationAlg_Cert = 0x000C,
    CCNxCodecSchemaV1Types_ValidationAlg_KeyName = 0x000E,
    CCNxCodecSchemaV1Types_ValidationAlg_SigTime = 0x000F,
} CCNxCodecSchemaV1Types_ValidationAlg;

/**
 * @typedef CCNxCodecSchemaV1Types_Link
 * @abstract The well-known keys for the LINK body
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_link_types {
    CCNxCodecSchemaV1Types_Link_Name = 0x0000,
    CCNxCodecSchemaV1Types_Link_KeyIdRestriction = 0x0001,
    CCNxCodecSchemaV1Types_Link_ContentObjectHashRestriction = 0x0002,
} CCNxCodecSchemaV1Types_Link;

// ==================================================
// Interest Return

/**
 * @typedef CCNxCodecSchemaV1Types_InterestReturnCode
 * @abstract The values of the InterestReturn ReturnCode field
 * @constant <#name#> <#description#>
 * @discussion <#Discussion#>
 */
typedef enum rta_tlv_schema_v1_interestreturncode_types {
    CCNxCodecSchemaV1Types_InterestReturnCode_NoRoute = 0x01,
    CCNxCodecSchemaV1Types_InterestReturnCode_HopLimitExceeded = 0x02,
    CCNxCodecSchemaV1Types_InterestReturnCode_NoResources = 0x03,
    CCNxCodecSchemaV1Types_InterestReturnCode_PathError = 0x04,
    CCNxCodecSchemaV1Types_InterestReturnCode_Prohibited = 0x05,
    CCNxCodecSchemaV1Types_InterestReturnCode_Congestion = 0x06,
    CCNxCodecSchemaV1Types_InterestReturnCode_MTUTooLarge = 0x07,
} CCNxCodecSchemaV1Types_InterestReturnCode;

#endif //TransportRTA_ccnxCodecSchemaV1_Types_h
