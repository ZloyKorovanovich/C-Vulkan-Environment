#define INCLUDE_VULKAN_INTERNALS
#include "vulkan.h"

/*
                                                                                              .-..-.                             
                                                                          ...               .-..--.                              
                                                                      .+#######-           --..-.                                
                                                                   -+###++++++###+.      .-..-.                                  
                                                                .+##++++++++++#####+.  .--.-.                                    
                                                              .###+++++++++++++++####---..-.                                     
                                                            -+####+++++++++++++++++##+..-.                              ----     
                                                          .###+++++++++++++++++++##+..-##.                          ..+-...-+    
                                                        .+##+++++++++++++++++++###-.-+####+                       --.....--.     
                                                      .+##++++++++++++++++++++##+..+##+++###.                 ..--....--.        
                                                     .###++++++++++++++++#++##+..-##+++++++##-              --.....--.           
                                  ......            +##+++++++++++++++++++###-.-+##+#++++#####+          --....--..              
                                   ..+#####++-.    +#+++++++++++++++++##+##+..+#####++++++++###+.    ..-....--.                  
                                        .#########-###+++++++++++++++####+..+##++###+++++++++###+ .+-....+-.                     
                                           .-+##+#######++++##++++++####-.-#####++++++++++++####+-...--.                         
                                   .........   -##+++#######++++++++##+..+####+++++++++++++##+-...--.                            
                             .+#################+####+#########+++##+..+##+#+++++++++++###+-...+####.                            
                         .+######++#+++######++######++++###########++#######++#+++####+-..-+#######+                            
                       -###+++++++++++++++#++++++++##+##++######++++++++######++####+-..-+###++++++##+                           
                    -###++##++++++++++++++++++++++++++##++++###+++++++++++++#####+-..++###++#++++++###+                          
                  .####++++++++++++++++++++++++++++++++++++++##+++++++++++++++###++###+++++++++++#++----                         
                .###++#+++++++++++++++++++++++++++++++++++++++++++++#+###++++++++#####+++++++++++#+------                        
              .+###+++++++++++++++++++++++++++++++++++++++++++++++#############++++#####++++++++#+--------                       
             -+----+#++++++++++++++++++++++++++++++++++++++++++++###-.-.  ...-+###+++####+++++++#+-------+-                      
           .+--------+#++++++++++++++++++++++##++++++++++++++++++#+.-###- ..... .+##++#####+++++#+--------+-                     
          .+---------+#++++++++++++++++++#######++++++++++++++++##-.#####-...------+#########++++#+--------+-                    
         -+----------+####++++++++++++++#####+++++++++++++##++++##--######-...--.....#########+++##+--------+-                   
       .++-----------+##++++++++++++++#####++++++++++++########++#+.-######...........+#++#####+++##---------+-                  
       +-------------+#+++#++++++++++####++++++++++++++#########+##+..+####-...........+#+#####++##+----------+-                 
      +-------------------+##++++++######++++++++++++++##########+###. .-+##............##+####+##+------------+-                
     ----------------------+############++++++++++++++###############............   ....+######++--++##+--------+-               
    -+---------------------+########++++++++++++++++++###++++--+#+-.++---......+#####++++######+####+++##+++----+#.              
   .+-------------------------+++#######+######++++++++##++++...........--. ....+##################################.             
   -+-----------+----------------+---+---++++++++++++++##+++-............-+++-...-#########################+++++++##.            
   ++---------+##+-------+######################+++++++##+++-................--.-+##+++###+++++++########++++++++++#+.           
  .##+-+----+######+++++##+#+++###++####++++++++++++++++##++-.................---+########+++++##########++++++++++###.          
  -#####++######+++###########+###++#####+++++++++++++++##+-......................######+++++++#######################+.         
  +#+###++#####++++++++++++########+##+##++++++++++++++++#+-......................-###+++#######++#####################+         
  #####++++####++++++++++++##########+--####+++++++#####+##+......-++##+++-.......-####+++++++###+++++++######+#####++##+.       
 .#####++++####+++++++++++###########+++#####++++++++###++##-..++++--......----....-####+++++++#++++++++++++++######+++##+       
 .#####++++####++++++++++++#####++###+....+##++++++++####+##-..................--...+####++++++++++++++++++######++++++###+      
  ###+#+++#####++++++++++++#####+-+#+-.....-####++++++######+.......................-######+###+++++++++#######++++++++####-     
  ##-.##++#####++++++++++++#####-..#+-....---###+++++++######+.......................########################++++++++++++###.    
  -#-.##++######+++++++++++####+...-#++#####+--###++++++#+-###-..--.-+########-......+##################+++++++++++++++++####-   
  .#- -##+######+++#++#++++####+...+##+----+#######+++++##-.+##...+##+..-##+-+##+....-##############++++++++++++++++++++++#+++.  
  .#-  +##+############++++#+##+.-##+-..    +##--.+####++##-..##..+...   +##+.-+##-..-#################+++++##+++++++++++++++##. 
   .-  .+#+############++++++##+-##+.. ++..-#+##-...+###++##....+.. ##++##+##+..+##..-###++##############+++##++++++++++++++++#+.
        .+#########+####++++++##+##.  .#########+.....+###+#+.......##########. .#+..-###++######++++####++++++++++++++++++++++#+
          -#########+#####++++###+#-  .##########........+###+......##########. -+...-##++++####++++++++++++++++++++++++++++++++#
           .+##############+++++#+-+.  ##++##++#+..........-+#+.... +#+-##+-#+..-....###++++####+++++++++++++++++++++++++++++++++
             +#####+.+########++###... .##-..-.+..............-+.....+#+--+#+.......-###+++++###+++++++++++++++++++++++++++++++##
              .-####..##############.....+####+........................++++-........+###++++#####+##+++++++++++++++++++++++++++++
                .-##+  ##############-....-----.........................--.........++###+++++#######+++++++++++++++++++++++++++++
                   .#. -#########..-+#+............................................#+###++++++#####++++++++++++++++++++++++++++++
                       -#########-......................+-........................-++###+++++++#####+++++++++++++++++++++++++++++
                       +#########+......................+-........................#####++++++++######++++++++++++++++++++++++++++
                       ###+######-+..............................................+#####+++++++++######+++++++++++++++++++++++++++
                      -##++++###. .-...............................-............+######++++++++++#######+++++++++++++++++++++++++
                     .###+++++##-.-#+..............++=---------++++-...........+#++#####+++++++++#######+++++++++++++++++++++++++
                     .##+++++++##+++++........................................+++++++###++++++++++########+++++++++++++++++++++++
                     +##+++++++##+++++#+....................................+#+++++++###+++++++++###########+++++++++++++++++++++
                    .###++++++##++++++#+#+-...............................-#+++++++-.-##++++++++++##########+++++++++++++++++++++
                    ##+++++++###-.+##++++++#+-..........................+#++++++++#+-.##+++++++++++###########+++++++++++++++++++
                   -##+++++++##+-#+.      -+###+-....................-+#+###+--.   -####+++++++++++############++++++++++++++++++
                  .#++++#++++##+#+      .###-...-##+..........----+++-...-###-      .+##+++++++++++++############++++++++++++++++
                  +##+++##+++###+.     .+##...........--+-.--..............-##-      .###++++++++++++############++++++++++++++++
                 -##++++++++####-      .##-..............-##- ..............-#+.      +##++++++++++++##############++++++++++++++
                .##++++++++#####-      -##................##+................+#.      .###++++++++++++##############+++++++++++++
               .##++++++++###+##.      -#+................##+................-#-      .+##+++++++++++++##############++++++++++++
              .+##+++++++++##+##.      -#+................+##................-#-       +###+++++++++++#################++++++++++
              -##+++++++#######+       -##................-##-...............-#-       .#########+++++###################++++++++
              +++##+++++++####-.       +##.................+#+...............+#-        .#++++++++###+++##################+#+++++
             .+---+####+++###.        .###.................-##...............##-         .###########+++####################+++++
            .#####++++++++##.        -##+...................##- .............+##.         +#+###++++++++#####################++++
       .-+++-###########++##.      .+##+...................+##- ..............+#+.        -#####++++++++######################+++
     .++-...-#####++#++++###.     -###....................+###.................+##-       .######+++++++##-.+###################+
   .-+......-#####++++++++##+.  .+##-....................-##+...................-##+.     .+#####+++++++##.....+################+
  .+-.......-######++++++###+++..+#+.....................-##-....................-##+.   .+###++##++++++#+......-################
 -+..........+#####++++++###-++++##-......................##+.....................+##- .+++###--##++#####-.......-###############
+-...........+######+++++###..-+++#+......................+##.....................-###++--.###.-##+++#+##.........+##############
.............-###+##++++++##-...-++###-...................-##-..................-+####.....##+.-##++++##-..........##############

                                                           YOKO
*/

extern const VulkanContext* getVulkanContextPtr(void);
extern const QueueContext* getQueueContextPtr(void);
extern const EventCallback getCallbackPfn(void);

typedef struct {
    VkDeviceMemory memory;
    u64 size;
    u32 type_id;
    u32 flags;
} VramBlock;

typedef struct {
    u64 offset;
    u64 size;
} VramAllocation;

static VulkanContext s_vulkan_context = (VulkanContext){0};
static VramBlock s_vram_blocks[MEMORY_BLOCK_COUNT] = {0};
static EventCallback s_callback = NULL;

static void* s_vram_allocation_buffer = NULL;
static VramAllocation* s_vram_allocations = NULL; // = s_vram_allocation_buffer
static VramAllocation* s_vram_free_spaces = NULL; // = (VramAllocation*)s_vram_allocation_buffer + MEMORY_BLOCK_COUNT * MEMORY_BLOCK_MAX_ALLOCATIONS 
static u32* s_vram_allocation_counts = NULL;
static u32* s_vram_free_space_counts = NULL;

#define VRAM_ALLOCATION(array, block_id, local_id) array[block_id * MEMORY_BLOCK_MAX_ALLOCATIONS + local_id]
#define VRAM_ALLOCATION_COUNT(array, block_id) array[block_id]

b32 layoutDeviceMemory(VkPhysicalDevice device, u32 block_count, const MemoryBlockDscr* block_dscrs, VramBlock* vram_blocks) {
    const u64 reserved_space = 1024 * 1024;
    VkPhysicalDeviceMemoryProperties device_memory;
    vkGetPhysicalDeviceMemoryProperties(device, &device_memory);

    for(u32 i = 0; i < block_count; i++) {
        u64 block_size = block_dscrs[i].size;
        u32 pos_flag = block_dscrs[i].positive_flags;
        u32 neg_flag = block_dscrs[i].negative_flags;
        for(u32 j = 0; j < device_memory.memoryTypeCount; j++) {
            u32 heap_id = device_memory.memoryTypes[j].heapIndex;
            u32 memory_flags = device_memory.memoryTypes[j].propertyFlags;
            if(
                device_memory.memoryHeaps[heap_id].size >= reserved_space + block_size &&
                FLAG_IN_MASK(memory_flags, pos_flag) && FLAG_NOT_IN_MASK(memory_flags, neg_flag)
            ) {
                device_memory.memoryHeaps[heap_id].size -= block_size;
                vram_blocks[i].size = block_size;
                vram_blocks[i].type_id = j;
                vram_blocks[i].flags = memory_flags;
                goto _found;
            }
        }
//_not_found:
        return FALSE;
_found:
    }
    return TRUE;
}

#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(s_callback, code, _fail)

b32 vramInit(EventCallback callback) {
    s_vulkan_context = *getVulkanContextPtr();
    s_callback = callback ? callback : getCallbackPfn();

    ERROR_CATCH(!layoutDeviceMemory(s_vulkan_context.physical_device, MEMORY_BLOCK_COUNT, (MemoryBlockDscr[])MEMORY_BLOCK_DESCRIPTORS, s_vram_blocks)) {
        _INVOKE_CALLBACK(VK_ERR_VRAM_LAYOUT_FAIL)
    }

    VkMemoryAllocateInfo alloc_info = (VkMemoryAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
    };
    for(u32 i = 0; i < MEMORY_BLOCK_COUNT; i++) {
        alloc_info.allocationSize = s_vram_blocks[i].size;
        alloc_info.memoryTypeIndex = s_vram_blocks[i].type_id;
        ERROR_CATCH(vkAllocateMemory(s_vulkan_context.device, &alloc_info, NULL, &s_vram_blocks[i].memory) != VK_SUCCESS) {
            _INVOKE_CALLBACK(VK_ERR_VRAM_ALLOCATE);
        }
    }

    s_vram_allocation_buffer = malloc((sizeof(VramAllocation) * MEMORY_BLOCK_MAX_ALLOCATIONS + sizeof(u32)) * MEMORY_BLOCK_COUNT * 2);
    ERROR_CATCH(!s_vram_allocation_buffer) {
        _INVOKE_CALLBACK(VK_ERR_VRAM_ALLOCATION_BUFFER_ALLOCATE)
    }
    s_vram_allocations = s_vram_allocation_buffer;
    s_vram_free_spaces = (VramAllocation*)s_vram_allocation_buffer + MEMORY_BLOCK_COUNT * MEMORY_BLOCK_MAX_ALLOCATIONS;
    s_vram_allocation_counts = (u32*)((char*)s_vram_allocation_buffer + sizeof(VramAllocation) * MEMORY_BLOCK_MAX_ALLOCATIONS * MEMORY_BLOCK_COUNT * 2);
    s_vram_free_space_counts = (u32*)((char*)s_vram_allocation_buffer + (sizeof(VramAllocation) * MEMORY_BLOCK_MAX_ALLOCATIONS * 2 + sizeof(u32)) * MEMORY_BLOCK_COUNT);
    for(u32 i = 0; i < MEMORY_BLOCK_COUNT; i++) {
        VRAM_ALLOCATION(s_vram_allocations, i, 0) = (VramAllocation){0};
        VRAM_ALLOCATION(s_vram_free_spaces, i, 0) = (VramAllocation) {
            .offset = 0,
            .size = s_vram_blocks[i].size
        };
        VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, i) = 0;
        VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, i) = 1;
        for(u32 j = 1; j < MEMORY_BLOCK_MAX_ALLOCATIONS; j++) {
            VRAM_ALLOCATION(s_vram_allocations, i, j) = (VramAllocation){0};
            VRAM_ALLOCATION(s_vram_free_spaces, i, j) = (VramAllocation){0};
        };
    }

//_sucess:
    return TRUE;
_fail:
    return FALSE;
}

void vramTerminate(void) {
    SAFE_DESTROY(s_vram_allocation_buffer, free(s_vram_allocation_buffer));
    s_vram_allocations = s_vram_free_spaces = NULL;
    s_vram_allocation_counts = s_vram_free_space_counts = NULL;
    for(u32 i = 0; i < MEMORY_BLOCK_COUNT; i++) {
        SAFE_DESTROY(s_vram_blocks[i].memory, vkFreeMemory(s_vulkan_context.device, s_vram_blocks[i].memory, NULL))
        s_vram_blocks[i] = (VramBlock){0};
    }
    s_vulkan_context = (VulkanContext){0};
    s_callback = NULL;
}

typedef enum {
    VRAM_ALLOCATE_SUCESS = 0,
    VRAM_ALLOCATE_WRONG_MEMORY_TYPE,
    VRAM_ALLOCATE_TOO_MANY_ALLOCATIONS,
    VRAM_ALLOCATE_ALLOCATION_BIGGER_THAN_BLOCK,
    VRAM_ALLOCATE_FAILED_TO_FIND_FREE_SAPCE,

    VRAM_FREE_SUCESS = 0,
    VRAM_FREE_TO_MANY_FREE_BLOCKS,
    VRAM_FREE_ALREADY_EMPTY
} vramAllocateCodes;

u32 vramAllocate(u64 size, u32 block_id, u32* const alloc_id) {
    VramAllocation allocation = (VramAllocation){
        .size = size
    };
    ERROR_CATCH(allocation.size > s_vram_blocks[block_id].size) {
        return VRAM_ALLOCATE_ALLOCATION_BIGGER_THAN_BLOCK;
    }

    u32 allocation_count = VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, block_id);
    ERROR_CATCH(allocation_count == MEMORY_BLOCK_MAX_ALLOCATIONS) {
        return VRAM_ALLOCATE_TOO_MANY_ALLOCATIONS;
    }

    // search for suitable space
    u32 free_space_count = VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, block_id);
    for(u32 i = 0; i < free_space_count; i++) {
        VramAllocation free_space = VRAM_ALLOCATION(s_vram_free_spaces, block_id, i); 
        if(free_space.size >= allocation.size) {
            // found suitable space
            allocation.offset = free_space.offset;
            free_space.offset += allocation.size;
            free_space.size = free_space.size - allocation.size;
            // if free space disappears
            if(free_space.size == 0) {
                free_space_count--;
                for(u32 j = i; j < free_space_count; j++) {
                    VRAM_ALLOCATION(s_vram_free_spaces, block_id, j) = VRAM_ALLOCATION(s_vram_free_spaces, block_id, j + 1);
                }
            }
            // this keeps free space ordered from smallest to biggest
            u32 free_space_insert_id = i;
            for(u32 j = 0; j < i; j++) {
                if(VRAM_ALLOCATION(s_vram_free_spaces, block_id, j).size > free_space.size) {
                    // displace and put value to j
                    free_space_count++;
                    free_space_insert_id = j;
                    for(u32 k = j + 1; k < free_space_count; k++) {
                        VRAM_ALLOCATION(s_vram_free_spaces, block_id, k) = VRAM_ALLOCATION(s_vram_free_spaces, block_id, k - 1);
                    }
                    break;
                }
            }

            VRAM_ALLOCATION(s_vram_free_spaces, block_id, free_space_insert_id) = free_space;
            VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, block_id) = free_space_count;
            allocation_count = VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, block_id);
            for(u32 j = 0; j < MEMORY_BLOCK_MAX_ALLOCATIONS; j++) {
                VramAllocation alloc_slot = VRAM_ALLOCATION(s_vram_allocations, block_id, j);
                if(!(alloc_slot.offset || alloc_slot.size)) {
                    VRAM_ALLOCATION(s_vram_allocations, block_id, j) = allocation;
                    *alloc_id = j;
                    break;
                }
            }
            VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, block_id) = allocation_count + 1;
            return VRAM_ALLOCATE_SUCESS;
        }
    }
    return VRAM_ALLOCATE_FAILED_TO_FIND_FREE_SAPCE;
}

u32 vramAllocateBuffers(u32 buffer_count, const VkBuffer* buffers, u32 block_id, u32* const alloc_id) {
    u64 allocation_size = 0;
    VkMemoryRequirements memory_requirements;
    u32 type_id = s_vram_blocks[block_id].type_id;
    for(u32 i = 0; i < buffer_count; i++) {
        vkGetBufferMemoryRequirements(s_vulkan_context.device, buffers[i], &memory_requirements);
        ERROR_CATCH(!(BIT(type_id) & memory_requirements.memoryTypeBits)) {
            return VRAM_ALLOCATE_WRONG_MEMORY_TYPE;
        }
        allocation_size += memory_requirements.size;
    }
    return vramAllocate(allocation_size, block_id, alloc_id);
}

u32 vramFreeAllocation(u32 block_id, u32 alloc_id) {
    VramAllocation allocation = VRAM_ALLOCATION(s_vram_allocations, block_id, alloc_id);
    if(!(allocation.size || allocation.offset)) {
        return VRAM_FREE_ALREADY_EMPTY;
    }
    u32 block_allocation_count = VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, block_id) - 1; // copy of count
    u32 block_free_space_count = VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, block_id);

    u32 left_id = U32_MAX;
    u32 right_id = U32_MAX;
    u32 right_exists = 0;
    u32 left_exists = 0;
    u32 space_id = 0;
    for(u32 i = 0; i < block_free_space_count; i++) {
        VramAllocation space = VRAM_ALLOCATION(s_vram_free_spaces, block_id, i);

        left_exists = (space.offset + space.size == allocation.offset);
        right_exists = (allocation.offset + allocation.size == space.offset);
        left_id = left_exists ? i : left_id;
        right_id = right_exists ? i : right_id;

        allocation.offset = left_exists ? space.offset : allocation.offset;
        allocation.size = (right_exists || left_exists) ? allocation.size + space.size : allocation.size;
        space_id = (space.size < allocation.size) ? i + 1 : space_id;
    }
    if(space_id >= MEMORY_BLOCK_MAX_ALLOCATIONS) {
        return VRAM_FREE_TO_MANY_FREE_BLOCKS;
    }
    block_free_space_count += !(right_exists || left_exists) - (right_exists && left_exists); // keep in mind that its a copy of count
    space_id += - (right_exists && (space_id != right_id)) - left_exists;
    for(u32 i = 0; i < block_free_space_count; i++) {
        u32 offset = (right_exists && i > right_id) + (left_exists && i > left_id) - (i > space_id);
        VRAM_ALLOCATION(s_vram_free_spaces, block_id, i) = VRAM_ALLOCATION(s_vram_free_spaces, block_id, i + offset);
    }
    VRAM_ALLOCATION(s_vram_free_spaces, block_id, space_id) = allocation;
    VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, block_id) = block_free_space_count;
    VRAM_ALLOCATION(s_vram_allocations, block_id, alloc_id) = (VramAllocation){0};
    VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, block_id) = block_allocation_count;
    return VRAM_FREE_SUCESS;
}

void vramDebugPrintLayout(void) {
    for(u32 i = 0; i < MEMORY_BLOCK_COUNT; i++) {
        printf("block_id: %u {\n", i);
        u32 alloc_count = VRAM_ALLOCATION_COUNT(s_vram_allocation_counts, i);
        printf("\tallocation_count: %u\n", alloc_count);
        for(u32 j = 0; j < MEMORY_BLOCK_MAX_ALLOCATIONS; j++) {
            VramAllocation allocation = VRAM_ALLOCATION(s_vram_allocations, i, j);
            if(!allocation.size && !allocation.offset) continue;
            printf("\t\tallocation_id: %u offset: %lu size: %lu\n", j, allocation.offset, allocation.size);
        }

        u32 free_count = VRAM_ALLOCATION_COUNT(s_vram_free_space_counts, i);
        printf("\tfree_space_count: %u\n", free_count);
        for(u32 j = 0; j < free_count; j++) {
            VramAllocation space = VRAM_ALLOCATION(s_vram_free_spaces, i, j);
            printf("\t\tfree_sapce_id: %u offset: %lu size: %lu\n", j, space.offset, space.size);
        }
        printf("}\n");
    }
}
