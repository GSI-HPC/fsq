/*
 * LTSM API stub header for static analysis (clang-tidy)
 * This provides minimal type definitions to allow parsing without the
 * full LTSM library.
 */

#ifndef TSMAPI_H
#define TSMAPI_H

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <sys/types.h>

/* Include TSM stubs */
#include "dsmapitd.h"
#include "dsmapifp.h"
#include "dsmapips.h"
#include "dsmrc.h"
#include "dapint64.h"

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "NA"
#endif

#define MAGIC_ID_V1 71147
#define DEFAULT_NUM_BUCKETS 64

/* Forward declarations for Lustre HSM types (defined in lustreapi.h) */
struct hsm_action_item;
struct hsm_copyaction_private;

/* Forward declaration for LTSM's common.h type */
struct kv_opt;

enum sort_by_t {
    SORT_NONE            = 0,
    SORT_DATE_ASCENDING  = 1,
    SORT_DATE_DESCENDING = 2,
    SORT_RESTORE_ORDER   = 3
};

struct fid_t {
    uint64_t seq;
    uint32_t oid;
    uint32_t ver;
};

struct lov_t {
    uint32_t stripe_size;
    uint16_t stripe_count;
};

struct lustre_info_t {
    struct fid_t fid;
    struct lov_t lov;
};

struct obj_info_t {
    uint32_t magic;
    dsStruct64_t size;
    mode_t st_mode;
    uint32_t crc32;
    struct lustre_info_t lustre_info;
};

struct archive_info_t {
    char fpath[PATH_MAX + 1];
    char desc[DSM_MAX_DESCR_LENGTH + 1];
    struct obj_info_t obj_info;
    dsmObjName obj_name;
};

/* Simple hash table stub for qtable */
typedef struct chashtable_t chashtable_t;

struct qarray_t {
    qryRespArchiveData *data;
    uint32_t size;
};

struct qtable_t {
    chashtable_t *chashtable;
    uint32_t nbuckets;
    dsmBool_t multiple;
    enum sort_by_t sort_by;
    struct qarray_t qarray;
};

struct progress_size_t {
    uint64_t cur;
    uint64_t cur_total;
    uint64_t total;
};

struct tsm_file_t {
    ObjAttr obj_attr;
    struct archive_info_t archive_info;
    off64_t bytes_processed;
    int err;
};

struct session_t {
    dsUint32_t handle;
    char owner[DSM_MAX_OWNER_LENGTH + 1];
    struct qtable_t qtable;

    struct hsm_action_item *hai;
    struct hsm_copyaction_private *hcp;
    long hal_flags;
    int (*progress)(struct progress_size_t *data,
                    struct session_t *session);

    struct tsm_file_t *tsm_file;
};

/* Login structure - defined in common.h, just forward declare here */
struct login_t;

/* Function prototypes */
void set_recursive(const dsBool_t recursive);
void select_latest(const dsBool_t latest);
void set_prefix(const char *_prefix);
void set_restore_stripe(const dsBool_t _restore_stripe);
int parse_verbose(const char *val, int *opt_verbose);
int mkdir_p(const char *path, const mode_t st_mode);
dsInt16_t extract_hl_ll(const char *fpath, const char *fs,
                        char *hl, char *ll);

void login_fill(struct login_t *login, const char *servername,
                const char *node, const char *password,
                const char *owner, const char *platform,
                const char *fsname, const char *fstype);

dsInt16_t tsm_init(const dsBool_t mt_flag);
void tsm_cleanup(const dsBool_t mt_flag);

dsInt16_t tsm_connect(struct login_t *login, struct session_t *session);
void tsm_disconnect(struct session_t *session);

dsmAppVersion get_appapi_ver(void);
dsmApiVersionEx get_libapi_ver(void);

dsInt16_t tsm_check_free_mountp(const char *fs, struct session_t *session);
dsInt16_t tsm_query_session(struct session_t *session);
dsInt16_t tsm_archive_fpath(const char *fs, const char *fpath,
                            const char *desc, int fd,
                            const struct lustre_info_t *lustre_info,
                            struct session_t *session);
dsInt16_t tsm_query_fpath(const char *fs, const char *fpath,
                          const char *desc, const dsmDate *date_lower_bound,
                          const dsmDate *date_upper_bound,
                          struct session_t *session);
dsInt16_t tsm_delete_fpath(const char *fs, const char *fpath,
                           struct session_t *session);
dsInt16_t tsm_retrieve_fpath(const char *fs, const char *fpath,
                             const char *desc, int fd,
                             struct session_t *session);

int tsm_fconnect(struct login_t *login, struct session_t *session);
void tsm_fdisconnect(struct session_t *session);
int tsm_fopen(const char *fs, const char *fpath, const char *desc,
              struct session_t *session);
ssize_t tsm_fwrite(const void *ptr, size_t size, size_t nmemb,
                   struct session_t *session);
int tsm_fclose(struct session_t *session);

#endif /* TSMAPI_H */
