#ifndef _VULKAN_INCLUDED
#define _VULKAN_INCLUDED

#include "../main.h"


// ================================================ RENDER INTERFACE
// =================================================================

b32 renderInit(u32 width, u32 height, u32 flags, EventCallback callback);
b32 renderRun(UpdateCallback update_callback);
void renderTerminate(void);

typedef enum {
    VK_CODE_SUCESS = 0,
    VK_ERR_GLFW_INIT = 1,
    VK_ERR_WINDOW_CREATE,
    VK_ERR_DEBUG_LAYERS_NOT_PRESENT,
    VK_ERR_EXT_NOT_PRESENT,
    VK_ERR_LOAD_EXT_PFN,
    VK_ERR_INSTANCE_CREATE,
    VK_ERR_DEBUG_MESSENGER_CREATE,
    VK_ERR_SURFACE_CREATE,
    VK_ERR_NO_GPU,
    VK_ERR_NO_SUITABLE_GPU,
    VK_ERR_DEVICE_CREATE,
    VK_ERR_SWAPCHAIN_CREATE,
    VK_ERR_SWAPCHAIN_VIEW_CREATE,

    VK_ERR_COMMAND_POOL_CREATE
} VulkanCodes;


typedef enum {
    VULKAN_FLAG_DEBUG = 0b0001,
    VULKAN_FLAG_FULLSCREEN = 0b0010,
    VULKAN_FLAG_RESIZABLE = 0b0100,
} VulkanFlags;


#ifdef INCLUDE_VULKAN_INTERNALS

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// =============================================== CONTROL CONSTANTS
// =================================================================

#define DEVICE_QUEUE_COUNT 3
#define DEVICE_QUEUE_FLAG_MASK (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT)
#define DEVICE_QUEUE_FLAGS  {                                               \
    VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT,   \
    VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT,                           \
    VK_QUEUE_TRANSFER_BIT                                                   \
}

#define DEVICE_EXTENSION_COUNT 5
#define DEVICE_EXTENSIONS {                     \
    VK_EXT_SHADER_OBJECT_EXTENSION_NAME,        \
    VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME,    \
    VK_KHR_SWAPCHAIN_EXTENSION_NAME,            \
    VK_KHR_SPIRV_1_4_EXTENSION_NAME,            \
    VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME     \
}

#define SWAPCHAIN_MAX_IMAGE_COUNT 2


// ========================================================= HELPERS
// =================================================================

#define VULKAN_VK_ERR(code) CODE_PACK_CODE(CODE_PACK_MODULE(CODE_MASK_EMPTY, CODE_MODULE_VULKAN), code)
#define INVOKE_CALLBACK(code) if(s_callback(VULKAN_VK_ERR(code))) goto _fail;

typedef struct {
    u32 family_id;
    u32 local_id;
} Queue;

typedef struct {
    VkExtent2D extent;
    VkSurfaceTransformFlagBitsKHR surface_transform;
    VkSurfaceFormatKHR color_format;
    VkPresentModeKHR present_mode;
    u32 min_image_count;
} SwapchainDscr;


// ======================================================== CONTEXTS
// =================================================================
// contexts are structs that are used to pass necessary data
// between render sources

typedef struct {
    GLFWwindow* window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkDevice device;
    EventCallback callback;
} VulkanContext;

typedef struct {
    VkSwapchainKHR swapchain;
    const SwapchainDscr* descriptor;
    const VkImage* images;
    const VkImageView* views;
    u32 image_count;
} SwapchainContext;

typedef struct {
    VkPhysicalDevice device;
    const VkPhysicalDeviceFeatures* features;
    const char* const* extensions;
    u32 extension_count;
} DeviceContext;

typedef struct {
    const Queue* locators;
    const VkQueue* queues;
    u32 queue_count;
} QueueContext;

void getVulkanContext(VulkanContext* const context);
void getSwapchainContext(SwapchainContext* const context);
void getDeviceContext(DeviceContext* const context);
void getQueueContext(QueueContext* const context);

b32 recreateSwapchain(void);

#endif // INCLUDE INTERNALS
#endif
