#ifndef _MAIN_INCLUDED
#define _MAIN_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// =========================================================== TYPES
// =================================================================

typedef long long i64x;
typedef long i64;
typedef int i32;
typedef short i16;
typedef char i8;

typedef unsigned long long u64x;
typedef unsigned long u64;
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef float f32;
typedef double f64;

typedef int b32;
#define FALSE 0
#define TRUE 1

#define I64_MAX 9223372036854775807
#define I32_MAX 2147483647
#define U32_MAX 0xffffffff

#define I64_MIN (-9223372036854775807 - 1)
#define I32_MIN (-2147483647 - 1)
#define U32_MIN 0

typedef u32 Handle;
#define HANDLE_INVALID 0xffffffff

// ======================================================= BASIC OPS
// =================================================================

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

#define CLAMP(a, b, t) MAX(MIN(t, b), a)

#define FLAG_IN_MASK(mask, flag) ((flag & mask) == flag)
#define FLAG_NOT_IN_MASK(mask, flag) ((flag & mask) != flag)


// ======================================================= FUNCTIONS
// =================================================================

#define DYN_ARG u32 argc, u64* argp
#define ARG(n) argp[n]

typedef b32 (*UpdateCallback) (f64 time, f64 delta);

// =========================================================== CODES
// =================================================================

// IN MEMORY:
// +----------------+----------------+--------------------------------+
// |  MODULE 8bit   | RESERVED 8bit  |           CODE 16bit           |
// +----------------+----------------+--------------------------------+
// IN HEX NUMBER: MMRRCCCC

typedef b32 (*EventCallback) (u32 event_code);

#define CODE_MASK_MODULE        0xff000000
#define CODE_MASK_RESERVED      0x00ff0000
#define CODE_MASK_CODE          0x0000ffff
#define CODE_MASK_EMPTY         0x00000000

#define CODE_SHIFT_MODULE       24
#define CODE_SHIFT_RESERVED     16
#define CODE_SHIFT_CODE         0

#define CODE_UNPACK_MODULE(code) (code >> CODE_SHIFT_MODULE)
#define CODE_UNPACK_RESERVED(code) ((code & CODE_MASK_RESERVED) >> CODE_SHIFT_RESERVED)
#define CODE_UNPACK_CODE(code) (code & CODE_MASK_CODE)

#define CODE_PACK_MODULE(mask, code) (mask | (code << CODE_SHIFT_MODULE))
#define CODE_PACK_RESERVED(mask, code) (mask | (code << CODE_SHIFT_RESERVED))
#define CODE_PACK_CODE(mask, code) (mask | code)

// ========================================================= ATTRIBS
// =================================================================

#define ATTRIB_PACKED __attribute__((__packed__))

// ========================================================= MODULES
// =================================================================

// 8 bits for this enum values
typedef enum {
    CODE_MODULE_MAIN = 0,
    CODE_MODULE_VULKAN,
} ModuleCodes;

// names id should match ModuleCodes value
static const char* module_names[] = {
    "MAIN",
    "VULKAN"
};

#define MODULE_NAME(id) module_names[id];

// ====================================================== ALLOCATION
// ================================================================= 

#define MIN_STACK 16
#define ZE_ALLOCA(bytes) _alloca((MIN_STACK > bytes) ? MIN_STACK : bytes)
#define Z_FREE(ptr) free(ptr); ptr = NULL; // zero memory after free()

#define SET_MEMORY(ptr, value, count, i)                \
for(u32 i = 0; i < count; i++) {                        \
    ptr[i] = value;                                     \
}

#define SAFE_DESTROY(ptr, func) if(ptr) {func; ptr = NULL;}

#endif
