#ifndef _VULKAN_INCLUDED
#define _VULKAN_INCLUDED

#include "../main.h"

// ================================================ RENDER INTERFACE
// =================================================================

b32 renderInit(u32 width, u32 height, u32 flags, EventCallback callback);
b32 renderRun(UpdateCallback update_callback, EventCallback event_callback, const char* shader_path);
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
    VK_ERR_SWAPCHAIN_TOO_MANY_IMAGES,
    VK_ERR_SWAPCHAIN_VIEW_CREATE,

    VK_ERR_COMMAND_POOL_CREATE,
    VK_ERR_SHADER_BUFFER_ALLOCATE,
    VK_ERR_SHADER_BUFFER_LOAD,
    VK_ERR_SHADER_MODULE_ARRAY_ALLOCATE,
    VK_ERR_SHADER_MODULE_CREATE,
    VK_ERR_PIPELINE_BUFFER_ALLOCATE,
    VK_ERR_RENDER_LOOP_FAIL,

    VK_ERR_TRIANGLE_PIPELINE_LAYOUT_CREATE,
    VK_ERR_TRIANGLE_PIPELINE_CREATE,

    VK_ERR_COMMAND_BUFFER_ALLOCATE,
    VK_ERR_SEAMAPHORE_CREATE,
    VK_ERR_FENCE_CREATE,
    VK_ERR_QUEUE_SUBMIT
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

#define DEVICE_EXTENSION_COUNT 4
#define DEVICE_EXTENSIONS {                     \
    VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME,    \
    VK_KHR_SWAPCHAIN_EXTENSION_NAME,            \
    VK_KHR_SPIRV_1_4_EXTENSION_NAME,            \
    VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME     \
}

#define DEVICE_FEATURES (VkPhysicalDeviceFeatures){0}

#define SWAPCHAIN_MAX_IMAGE_COUNT 2


// ========================================================= HELPERS
// =================================================================

#define VULKAN_VK_ERR(code) CODE_PACK_CODE(CODE_PACK_MODULE(CODE_MASK_EMPTY, CODE_MODULE_VULKAN), code)
#define INVOKE_CALLBACK(callback, code, label) if(callback(VULKAN_VK_ERR(code))) goto label;

typedef struct {
    u32 family_id;
    u32 local_id;
} QueueLocator;

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
    VkSwapchainKHR swapchain;
    VkPhysicalDevice physical_device;
    QueueLocator* queue_locators;
    VkQueue* queues;
} VulkanContext;

typedef struct {
    SwapchainDscr* descriptor;
    VkImage* images;
    VkImageView* views;
    u32 image_count;
} SwapchainContext;


typedef struct {
    // dynamic rendering khr
    PFN_vkCmdBeginRenderingKHR cmd_begin_rendering;
    PFN_vkCmdEndRenderingKHR cmd_end_rendering;
} ExtContext;

void getVulkanContext(VulkanContext* const context);
void getSwapchainContext(SwapchainContext* const context);
void getExtContext(ExtContext* const context);
EventCallback getCallbackPfn(void);

b32 recreateSwapchain(void);

#endif // INCLUDE INTERNALS
#endif
