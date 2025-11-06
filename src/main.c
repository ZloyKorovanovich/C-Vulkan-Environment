#include "main.h"
#include "vulkan/vulkan.h"

b32 debugCallback(u32 code) {
    printf("error: module %u, code %u\n", CODE_UNPACK_MODULE(code), CODE_UNPACK_CODE(code));
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
    strcat(shader_path, "/data/");
    printf("path %s\n", shader_path);

    coreInit(800, 600, VULKAN_FLAG_RESIZABLE, &debugCallback);
    vramInit(NULL);
    resourcesInit(shader_path);
    renderInit(NULL);
    renderLoop(NULL);
    renderTerminate();
    resourcesTerminate();
    vramTerminate();
    coreTerminate();
    return 0;
}
