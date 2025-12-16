/*
 * Lustre API stub library for static analysis builds.
 * Provides empty implementations to satisfy the linker.
 */

#include "lustre/lustreapi.h"
#include <stdlib.h>

int llapi_search_fsname(const char *pathname, char *fsname) {
    (void)pathname; (void)fsname;
    return 0;
}

int llapi_hsm_state_get(const char *path, struct hsm_user_state *hus) {
    (void)path; (void)hus;
    return 0;
}

int llapi_path2fid(const char *path, struct lu_fid *fid) {
    (void)path; (void)fid;
    return 0;
}

struct hsm_user_request *llapi_hsm_user_request_alloc(int itemcount, int data_len) {
    (void)itemcount; (void)data_len;
    return malloc(sizeof(struct hsm_user_request));
}

int llapi_hsm_request(const char *path, const struct hsm_user_request *request) {
    (void)path; (void)request;
    return 0;
}
