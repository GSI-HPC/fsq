/*
 * TSM API stub header for static analysis (clang-tidy)
 * This provides minimal type definitions to allow parsing without the
 * proprietary IBM TSM SDK.
 */

#ifndef DSMAPITD_H
#define DSMAPITD_H

#include <stdint.h>

/* Basic TSM types */
typedef int16_t  dsInt16_t;
typedef uint16_t dsUint16_t;
typedef int32_t  dsInt32_t;
typedef uint32_t dsUint32_t;
typedef int64_t  dsInt64_t;
typedef uint64_t dsUint64_t;
typedef uint8_t  dsUint8_t;
typedef char     dsChar_t;

typedef dsUint8_t  dsBool_t;
typedef dsUint8_t  dsmBool_t;

/* String length constants */
#define DSM_MAX_HL_LENGTH       1024
#define DSM_MAX_LL_LENGTH       256
#define DSM_MAX_FSNAME_LENGTH   1024
#define DSM_MAX_FSTYPE_LENGTH   32
#define DSM_MAX_DESCR_LENGTH    255
#define DSM_MAX_OWNER_LENGTH    64
#define DSM_MAX_NODE_LENGTH     64
#define DSM_MAX_VERIFIER_LENGTH 64
#define DSM_MAX_PLATFORM_LENGTH 16
#define DSM_MAX_MC_NAME_LENGTH  30
#define DSM_MAX_OBJINFO_LENGTH  255

/* 64-bit structure for file sizes */
typedef struct {
    dsUint32_t hi;
    dsUint32_t lo;
} dsStruct64_t;

/* Object name structure */
typedef struct {
    dsChar_t fs[DSM_MAX_FSNAME_LENGTH + 1];
    dsChar_t hl[DSM_MAX_HL_LENGTH + 1];
    dsChar_t ll[DSM_MAX_LL_LENGTH + 1];
    dsUint8_t objType;
} dsmObjName;

/* Date structure */
typedef struct {
    dsUint16_t year;
    dsUint8_t  month;
    dsUint8_t  day;
    dsUint8_t  hour;
    dsUint8_t  minute;
    dsUint8_t  second;
} dsmDate;

/* Object attributes */
typedef struct {
    dsUint8_t   stVersion;
    dsChar_t    owner[DSM_MAX_OWNER_LENGTH + 1];
    dsStruct64_t sizeEstimate;
    dsmBool_t   objCompressed;
    dsUint16_t  objInfoLength;
    char        *objInfo;
    dsChar_t    mcName[DSM_MAX_MC_NAME_LENGTH + 1];
} ObjAttr;

/* Query response for archive data */
typedef struct {
    dsUint8_t    stVersion;
    dsmObjName   objName;
    dsUint32_t   copyGroup;
    dsChar_t     mcName[DSM_MAX_MC_NAME_LENGTH + 1];
    dsChar_t     owner[DSM_MAX_OWNER_LENGTH + 1];
    dsmDate      insDate;
    dsmDate      expDate;
    dsChar_t     descr[DSM_MAX_DESCR_LENGTH + 1];
    dsUint16_t   objInfoLength;
    dsStruct64_t sizeEstimate;
    dsUint8_t    compressType;
    dsUint8_t    retentionInitiated;
    dsUint8_t    objHeld;
    dsUint8_t    encryptionType;
    dsmBool_t    clientDeduplicated;
    char         objInfo[DSM_MAX_OBJINFO_LENGTH];
} qryRespArchiveData;

/* Version structures */
typedef struct {
    dsUint16_t stVersion;
    dsUint16_t version;
    dsUint16_t release;
    dsUint16_t level;
} dsmAppVersion;

typedef struct {
    dsUint16_t stVersion;
    dsUint16_t version;
    dsUint16_t release;
    dsUint16_t level;
    dsUint16_t subLevel;
} dsmApiVersionEx;

#endif /* DSMAPITD_H */
