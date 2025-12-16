/*
 * Lustre API stub header for static analysis (clang-tidy)
 * This provides minimal type definitions to allow parsing without the
 * Lustre development headers.
 */

#ifndef LUSTREAPI_H
#define LUSTREAPI_H

#include <stdint.h>
#include <sys/types.h>

/* Lustre File ID */
struct lu_fid {
    uint64_t f_seq;
    uint32_t f_oid;
    uint32_t f_ver;
};

/* FID printf helpers */
#define DFID "[0x%llx:0x%x:0x%x]"
#define PFID(fid) \
    (unsigned long long)(fid)->f_seq, (fid)->f_oid, (fid)->f_ver

/* HSM state flags */
#define HS_NONE      0x00000000
#define HS_EXISTS    0x00000001
#define HS_DIRTY     0x00000002
#define HS_RELEASED  0x00000004
#define HS_ARCHIVED  0x00000008
#define HS_NORELEASE 0x00000010
#define HS_NOARCHIVE 0x00000020
#define HS_LOST      0x00000040

/* HSM user state */
struct hsm_user_state {
    uint32_t hus_states;
    uint32_t hus_archive_id;
    uint32_t hus_in_progress_state;
    uint32_t hus_in_progress_action;
    struct lu_fid hus_in_progress_fid;
    uint64_t hus_in_progress_offset;
    uint64_t hus_in_progress_length;
};

/* HSM action types */
enum hsm_user_action {
    HUA_NONE    = 1,
    HUA_ARCHIVE = 10,
    HUA_RESTORE = 11,
    HUA_RELEASE = 12,
    HUA_REMOVE  = 13,
    HUA_CANCEL  = 14
};

/* HSM user item */
struct hsm_user_item {
    struct lu_fid hui_fid;
    struct {
        uint64_t offset;
        uint64_t length;
    } hui_extent;
};

/* HSM request descriptor */
struct hsm_request {
    uint32_t hr_action;
    uint32_t hr_archive_id;
    uint64_t hr_flags;
    uint32_t hr_itemcount;
    uint32_t hr_data_len;
};

/* HSM user request */
struct hsm_user_request {
    struct hsm_request hur_request;
    struct hsm_user_item hur_user_item[0];
};

/* Helper macro for HSM user items in request */
#define hur_user_item(hur) ((hur)->hur_user_item)

/* Function prototypes */
int llapi_search_fsname(const char *pathname, char *fsname);
int llapi_hsm_state_get(const char *path, struct hsm_user_state *hus);
int llapi_path2fid(const char *path, struct lu_fid *fid);
struct hsm_user_request *llapi_hsm_user_request_alloc(int itemcount, int data_len);
int llapi_hsm_request(const char *path, const struct hsm_user_request *request);

#endif /* LUSTREAPI_H */
