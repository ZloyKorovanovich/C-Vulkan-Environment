#include "main.h"
#define INCLUDE_VULKAN_EXTERNAL
#include "vulkan/vulkan.h"
#ifdef _WIN32
#include <windows.h>
#else 
#include <pthread.h>
#endif


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
    char data_path[256];
    strcpy(data_path, argv[0]);
    upFolder(data_path);
    upFolder(data_path);
    strcat(data_path, "/data/");
    printf("data path: %s\n", data_path);

    ThreadCommandBuffer command_buffer = (ThreadCommandBuffer){
        .thread_lock = 0,
        .command = 0,
        .data = NULL
    };
    VulkanThreadBuffer vk_thread_buffer = (VulkanThreadBuffer) {
        .callback = &debugCallback,
        .data_path = data_path,
        .flags = VULKAN_FLAG_RESIZABLE,
        .width = 800,
        .height = 600,
        .command_buffer = &command_buffer
    };

    HANDLE vulkan_thread;
    vulkan_thread = CreateThread(NULL, 0, vulkanRun, &vk_thread_buffer, 0, 0);
    ERROR_CATCH(!vulkan_thread) {
        printf("failed to start vulkan thread!\n");
        return -1;
    }

    u32 input_command;
_loop:
    scanf("%u", &input_command);
    if(input_command == 10) goto _end_loop;

    command_buffer.thread_lock = 1;
    command_buffer.command = input_command;
    command_buffer.data = NULL;
    command_buffer.thread_lock = 0;
    goto _loop;
_end_loop:

    return 0;
}
