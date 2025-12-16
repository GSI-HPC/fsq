/*
 * LTSM API stub library for static analysis builds.
 * Provides empty implementations to satisfy the linker.
 */

#include "ltsmapi.h"
#include <stdlib.h>
#include <sys/types.h>

dsInt16_t tsm_connect(struct login_t *login, struct session_t *session) {
    (void)login; (void)session;
    return 0;
}

void tsm_disconnect(struct session_t *session) {
    (void)session;
}

dsInt16_t extract_hl_ll(const char *fpath, const char *fs, char *hl, char *ll) {
    (void)fpath; (void)fs; (void)hl; (void)ll;
    return 0;
}

int mkdir_p(const char *path, const mode_t st_mode) {
    (void)path; (void)st_mode;
    return 0;
}

int parse_conf(const char *filename, struct kv_opt *kv_opt) {
    (void)filename; (void)kv_opt;
    return 0;
}

int parse_verbose(const char *val, int *opt_verbose) {
    (void)val; (void)opt_verbose;
    return 0;
}

double time_now(void) {
    return 0.0;
}

/* List stubs (real implementation in LTSM's list.c) */
typedef struct list_node_t list_node_t;
typedef struct list_t list_t;

void list_init(list_t *list, void (*destroy)(void *data)) {
    (void)list; (void)destroy;
}

void list_destroy(list_t *list) {
    (void)list;
}

int list_ins_next(list_t *list, list_node_t *node, const void *data) {
    (void)list; (void)node; (void)data;
    return 0;
}

int list_rem_next(list_t *list, list_node_t *node, void **data) {
    (void)list; (void)node; (void)data;
    return 0;
}

void list_for_each(const list_t *list, void (*callback)(void *data)) {
    (void)list; (void)callback;
}

/* FIXME: queue.h is not part of LTSM's public API */
typedef struct queue_t queue_t;

int queue_enqueue(queue_t *queue, const void *data) {
    (void)queue; (void)data;
    return 0;
}

int queue_dequeue(queue_t *queue, void **data) {
    (void)queue; (void)data;
    return 0;
}

/* From LTSM common.h */
void login_init(struct login_t *login, const char *servername) {
    (void)login; (void)servername;
}
