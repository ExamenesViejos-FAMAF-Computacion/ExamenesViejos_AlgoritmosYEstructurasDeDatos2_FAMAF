#include <stdlib.h>
#include "fence.h"

struct _fence_t {
    fence_t next;
    type_t type;
};
