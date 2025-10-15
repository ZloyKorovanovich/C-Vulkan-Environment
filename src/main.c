#include "main.h"
#include "vulkan/vulkan.h"

b32 debugCallback(u32 code) {
    printf("error: %u\n", code);
    return TRUE;
}


i32 main(i32 argc, char** argv) {
    renderInit(800, 600, VULKAN_FLAG_DEBUG, &debugCallback);
    renderTerminate();
    return 0;
}
