#ifndef _VULKAN_INCLUDED
#define _VULKAN_INCLUDED

#include "../main.h"

// ============================================== EXTERNAL INTERFACE
// =================================================================

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

    VK_ERR_DESCRIPTOR_POOL_CREATE,
    VK_ERR_DESCRIPTOR_BUFFER_ALLOCATE,
    VK_ERR_SHADER_BUFFER_ALLOCATE,
    VK_ERR_SHADER_BUFFER_LOAD,
    VK_ERR_SHADER_MODULE_ARRAY_ALLOCATE,
    VK_ERR_SHADER_MODULE_CREATE,
    VK_ERR_PIPELINE_BUFFER_ALLOCATE,
    VK_ERR_RENDER_LOOP_FAIL,

    VK_ERR_CREATE_DESCRIPTOR_SET_LAYOUT,
    VK_ERR_ALLOCATE_DISCRIPTOR_SET,

    VK_ERR_TRIANGLE_PIPELINE_LAYOUT_CREATE,
    VK_ERR_TRIANGLE_PIPELINE_CREATE,

    VK_ERR_DISTRIBUTION_PIPELINE_LAYOUT_CREATE,
    VK_ERR_DISTRIBUTION_PIPELINE_CREATE,

    VK_ERR_COMMAND_BUFFER_ALLOCATE,
    VK_ERR_SEAMAPHORE_CREATE,
    VK_ERR_FENCE_CREATE,
    VK_ERR_QUEUE_SUBMIT,

    VK_ERR_GLOBAL_UNIFORM_BUFFER_DEVICE_CREATE,
    VK_ERR_GLOBAL_UNIFORM_BUFFER_HOST_CREATE,
    VK_ERR_GLOBAL_UNIFORM_BUFFER_HOST_ALLOCATE,
    VK_ERR_GLOBAL_UNIFORM_BUFFER_DEVICE_ALLOCATE,
    VK_ERR_GLOBAL_UNIFORM_BUFFER_WRITE,
    VK_ERR_POSITION_BUFFER_HOST_CREATE,


    VK_ERR_VRAM_LAYOUT_FAIL,
    VK_ERR_VRAM_ALLOCATE,
    VK_ERR_VRAM_ALLOCATION_BUFFER_ALLOCATE,

    VK_ERR_VRAM_NOT_SUITABLE_FOR_BUFFER
} VulkanCodes;

typedef enum {
    VULKAN_FLAG_DEBUG = BIT(0),
    VULKAN_FLAG_FULLSCREEN = BIT(1),
    VULKAN_FLAG_RESIZABLE = BIT(2),
} VulkanFlags;

b32 coreInit(u32 width, u32 height, u32 flags, EventCallback callback);
void coreTerminate(void);
b32 vramInit(EventCallback callback);
void vramTerminate(void);

b32 resourcesInit(const char* res_path);
void resourcesTerminate(void);

b32 renderInit(EventCallback event_callback);
void renderTerminate(void);
b32 renderLoop(UpdateCallback update_callback) ;

// ============================================== INTERNAL INTERFACE
// =================================================================
#ifdef INCLUDE_VULKAN_INTERNAL

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// =============================================== CONTROL CONSTANTS
// =================================================================

typedef struct {
    u64 size;
    u32 positive_flags;
    u32 negative_flags;
} MemoryBlockDscr;

typedef struct {
    
} DescriptorSetDscr;

#define DEVICE_QUEUE_COUNT 3
#define DEVICE_QUEUE_FLAG_MASK (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT)
#define DEVICE_QUEUE_FLAGS  {                                               \
    VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT,   \
    VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT,                           \
    VK_QUEUE_TRANSFER_BIT                                                   \
}

#define QUEUE_RENDER_ID 0
#define QUEUE_COMPUTE_ID 1
#define QUEUE_TRANSFER_ID 2

#define DEVICE_EXTENSION_COUNT 4
#define DEVICE_EXTENSIONS {                     \
    VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME,    \
    VK_KHR_SWAPCHAIN_EXTENSION_NAME,            \
    VK_KHR_SPIRV_1_4_EXTENSION_NAME,            \
    VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME     \
}

#define DEVICE_FEATURES (VkPhysicalDeviceFeatures){0}
#define SWAPCHAIN_MAX_IMAGE_COUNT 2

/*
    VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 0x00000001,
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 0x00000002,
    VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 0x00000004,
    VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 0x00000008,
    VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 0x00000010,
    VK_MEMORY_PROPERTY_PROTECTED_BIT = 0x00000020,
    VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD = 0x00000040,
    VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD = 0x00000080,
    VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV = 0x00000100,
    VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
*/

#define MEMORY_BLOCK_COUNT 2
#define MEMORY_BLOCK_DESCRIPTORS {                              \
    (MemoryBlockDscr) {                                         \
        .size = 1024 * 1024 * 4,                                \
        .positive_flags = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,  \
        .negative_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT   \
    },                                                          \
    (MemoryBlockDscr) {                                         \
        .size = 1024 * 1024 * 4,                                \
        .positive_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT,  \
        .negative_flags = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT   \
    }                                                           \
}

#define MEMORY_BLOCK_MAX_ALLOCATIONS 32
#define MEMORY_ALLOCATION_SNAP 256

#define MEMORY_BLOCK_DEVICE_ID 0
#define MEMORY_BLOCK_HOST_ID 1

#define DESCRIPTOR_MAX_COUNT 1024

#define GENERAL_QUEUE_DESCRIPTOR_POOL_SIZES {       \
    (VkDescriptorPoolSize) {                        \
        .type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,  \
        .descriptorCount = DESCRIPTOR_MAX_COUNT     \
    }                                               \
    (VkDescriptorPoolSize) {                        \
        .type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,  \
        .descriptorCount = DESCRIPTOR_MAX_COUNT     \
    }                                               \
}
#define COMPUTE_QUEUE_DESCRIPTOR_POOL_SIZES {       \
    (VkDescriptorPoolSize) {                        \
        .type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,  \
        .descriptorCount = DESCRIPTOR_MAX_COUNT     \
    }                                               \
    (VkDescriptorPoolSize) {                        \
        .type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,  \
        .descriptorCount = DESCRIPTOR_MAX_COUNT     \
    }                                               \
}

#define DESCRIPTOR_SET_COUNT 4

#define DESCRIPTOR_SET_GLOBAL_ID 0
#define DESCRIPTOR_SET_PASS_ID 1
#define DESCRIPTOR_SET_MATERIAL_ID 2
#define DESCRIPTOR_SET_OBJECT_ID 3

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
    VkPhysicalDevice physical_device;
    EventCallback callback;
    VkSurfaceFormatKHR surface_format;
} VulkanContext;

typedef struct {
    QueueLocator queue_locators[DEVICE_QUEUE_COUNT];
    VkQueue queues[DEVICE_QUEUE_COUNT];
} QueueContext;

typedef struct {
    VkImage images[SWAPCHAIN_MAX_IMAGE_COUNT];
    VkImageView views[SWAPCHAIN_MAX_IMAGE_COUNT];
    VkSwapchainKHR swapchain;
    SwapchainDscr descriptor;
    u32 image_count;
} SwapchainContext;

typedef struct {
    // dynamic rendering khr
    PFN_vkCmdBeginRenderingKHR cmd_begin_rendering;
    PFN_vkCmdEndRenderingKHR cmd_end_rendering;
} ExtContext;

const VulkanContext* getVulkanContextPtr(void);
const SwapchainContext* getSwapchainContextPtr(void);
const QueueContext* getQueueContextPtr(void);
const ExtContext* getExtensionContextPtr(void);

b32 recreateSwapchain(void);

typedef enum {
    VRAM_ALLOCATE_SUCESS = 0,
    VRAM_ALLOCATE_WRONG_MEMORY_TYPE,
    VRAM_ALLOCATE_TOO_MANY_ALLOCATIONS,
    VRAM_ALLOCATE_ALLOCATION_BIGGER_THAN_BLOCK,
    VRAM_ALLOCATE_FAILED_TO_FIND_FREE_SAPCE,
    VRAM_ALLOCATE_BUFFER_BIND_FAILED,

    VRAM_FREE_SUCESS = 0,
    VRAM_FREE_TO_MANY_FREE_BLOCKS,
    VRAM_FREE_ALREADY_EMPTY
} VramAllocateCodes;

typedef struct {
    void* src;
    u64 offset;
    u64 size;
} VramWriteDscr;

u32 vramAllocate(u64 size, u32 block_id, u32* const alloc_id);
u32 vramAllocateBuffers(u32 buffer_count, const VkBuffer* buffers, u32 block_id, u32* const alloc_id);
u32 vramFree(u32 block_id, u32 alloc_id);
b32 vramWriteToAllocation(u32 block_id, u32 alloc_id, VramWriteDscr* write_dscr);
void vramDebugPrintLayout(void);

const VkShaderModule* getShaderModulesPtr(void);

#ifdef INCLUDE_QUEUE_RENDER
#define CURRENT_QUEUE_ID QUEUE_RENDER_ID
#endif // defined(INCLUDE_QUEUE_GENERAL)

#endif // INCLUDE_VULKAN_INTERNAL
#endif
