#pragma once

#pragma comment(lib, "../lib/common.lib")
#include "../common/Link.hpp"

namespace jklim {

}

#ifdef QUEUE_EXPORTS
#define QUEUEAPI __declspec(dllexport)
#else
#define QUEUEAPI __declspec(dllimport)
#endif // STACK_EXPORTS

Version QUEUEAPI GetVersionQueue();