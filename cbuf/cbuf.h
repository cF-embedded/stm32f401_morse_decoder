#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CBUF_SIZE 32

typedef uint32_t buffer_t;
typedef size_t index_t;

/* if buffer size changes, item must also change */
typedef buffer_t item_t;

typedef struct
{
    buffer_t buffer[CBUF_SIZE];
    index_t head;
    index_t tail;
} cbuf_s_t;

void cbuf_init(cbuf_s_t*);

bool cbuf_is_empty(cbuf_s_t*);

bool cbuf_is_full(cbuf_s_t*);

bool cbuf_push(cbuf_s_t*, item_t);

item_t cbuf_pop(cbuf_s_t*);

size_t cbuf_size(cbuf_s_t*);

#ifdef UNIT_TESTING
index_t cbuf_get_head(const cbuf_s_t* cbuf);

index_t cbuf_get_tail(const cbuf_s_t* cbuf);
#endif
