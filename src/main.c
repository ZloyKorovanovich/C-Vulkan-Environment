#include "main.h"
#include "vulkan/vulkan.h"

b32 debugCallback(u32 code) {
    printf("error: %u\n", code);
    return TRUE;
}

b32 upFolder(char* path) {
    u32 len = strlen(path);
    for(u32 i = len - 1; i > 0; i--) {
        if(path[i] == '\\' || path[i] == '/') {
            path[i] = '\0';
            return TRUE;
        }
    }
    return FALSE;
}

i32 main(i32 argc, char** argv) {
    char shader_path[256];
    strcpy(shader_path, argv[0]);
    upFolder(shader_path);
    upFolder(shader_path);
    strcat(shader_path, "\\data\\shaders.res");
    printf("path %s\n", shader_path);

    renderInit(800, 600, VULKAN_FLAG_DEBUG, &debugCallback);
    renderRun(NULL, NULL, shader_path);
    renderTerminate();
    return 0;
}
