
#define INCLUDE_VULKAN_INTERNAL
#define INCLUDE_QUEUE_RENDER
#include "vulkan.h"
#include "shaders.h"

/*                                                                                                                        
                             ###.                                                                                               
                           ##.  -###.                                                                                           
                         ##.  ..   ####.                                                    .+##############                    
                       ##. .......  ---###.          -++######+-......-#######+-.       ..##+.  -----------##                   
                     ##.  .......... #...-###-######++.         ......        .-+#####+##.    -#+---------.-+#                  
                    ##  ............ #---..###.        .-###################-.        .+##.  ---------------.##                 
               #####. .............. -+...-   .+###########++--------++++++########-.     .###-...--+-------..#                 
              ###..#-   ............ .-.--+######+---+++++++++++++++++++++++++++++######     ###+..-------...-####              
             ###..  ###    ......    .#####+---+##############++++++++###########++-++#####. -..+##..--....+#+ ###              
            ##+ ...-+#####.       +####--++######+.........-############+..  ...######+-.-#####.  ##.....+##  . ####            
           ###....##+..#######..####+++-####.                   .##.                .############# .-.-###### ...###            
           ##....###+++.-######+--++++###.   ...................    ...............    +##################++## ..####          
          ##....######++-.+#####+.-###.   ................   ..........................  .###############-+###....####          
          #. ..###+#++++++-.+#######  ....................##.............................   ############++##### ...###          
          ## .#####+++++++++-..+###. .....................  -#+ ...........................  .########+++####### . .#         
           #############+##++++-+##  ........................ #. ............................  ####+-++##########  ##+
           ####+#++##++#+##+###+-## ......................... .#.............................  ##-.+################-#
           # .#+++++++##+#++###-##. ................           ........    ...................##-+################+..#+
          #. .#+###+#+++#++++++##. ..............   -#####++++.       .-+-...   .............  ###+++#############...+# 
          #. .#-###+++#+++#+++## ..............  .##+-....--..-+-. -++--+#####+-    ..........  +#################.--.#+
         #.  ##++++++#++++#++## .............  .#+---+#########--###---+++++++###+-.  .......... ##+#+############.--.-# 
        ##.. ##+#+##++######## ............  .#--+###-         ##  ####-..   .#####--+   ........ ##+##########+#+.---.#
        #. . ##+++++##-     .............  -####+      .......                   -###--#-  ...... .##+###########-.--+.## 
       ## ..  ##++-+#  ................   ###.    ..............................    +#---+#- .... +-#####-.######.-+++.-# 
       #...... ##+-#+ ................  ###   .....................................   ##+..-##.  .+...... -######.---+-.#
      #+....... ####- ...............  ##   .........................................   ##-..+## ++--....#######..--++-.+# 
      #. ......  #.#- ............. .##   .............................................   ##-..++++--..-##.####..-+-++---# 
     ##........ .+.## ............ +#.  .................................................   ##.-----+###-... #-.----++-+.#+
     #......... #+.#+   ........  ##  ............ ........................     ...........  ##....-+-...---.#..--+-+-+-.-#
    ##......... #-.## ##-.      +#   ........          ..................   --.     .......  .+###......---.-#.-++++------# 
    #......... ##..-#+  .########. ..........##########...................#########  ........- .#+#####+++-.##.-----++++-.#+
   ##..........#+--.##-#   ----#- ...........           .................         -##........+- ##......-+-.#.------++-+-.##
  ##. ....... #+.....#--+##-..##  ..........    ....##  ................. .#+         ..... .+-. #-.------.#+ ...----+---.--
  ## .........#-+####-#-.....##  ........    -.       ##.................+#     .+ .#     .  ....##.-----.-#####+.--+--++--#.
  #+ .........#.# .  ###-.-.##            #########.    ................   .############    ### ..#-.-++..#. .- #---+++---.#   
 ##  # ..... -+-# .#+  -#-.+#  . +###   ###.......+###  ................. ##.#. .......###+## ##  .##.--.## ##  ##.--+-++-.##   
 ## .# ..... ++.#   .#  ##--#   +#   ###+..++####+-.#.# .................   #.########+. .##   ##  .#.-.## #-.. #+.--+----.+#   
##. ## ..... #-.#  .  ## .#-#   #.  .#++-.#+#######-.#  .................. #.    ##+++#+...+#-  #+. #-.-# #+ -. #.---+-++-.-#   
##  #...... -#..#. ..  #- .##. .# .-# +..   ########.##  ................. #+-+########+-.++.-  #- .#.+#.#  .-.-#.+-+++++-..#   
## .# ..... ##..## ...  ##  #.  - .   #+++-.---.-.. .+#+. ..............   #+.. .++#+-..--+# ...#..-###.### -- ##.--+++++--.##+ 
#. ## ..... #--.-#  ..  ###     +. .. ###+.        .+..## .............. #####.        .+++# -.##..### #. #.. -#.--------+-.##+ 
# ##- ......#---.##    #  #......#. .  .##+##+.-+####.    ..............  -  ###+---+++++##.-.   ..-...  ## ..#+----++-++--.###.
##.#. .... -#--....#.   ##   ...  ##      #########.  ...................      #########  .. +#-----...##   -#...-++++++++-.+## 
#- # ..... ++...-#####    ##...    -#     #         ..........................        ###.  ##..----..##   ###....---+-++--..## 
#-+# ..... +..####-#####     . # ..  ## ## # ........................................ #  ###. .-----##.  +#######...-+-+++-..##.
#### ..... -####++#######-   . ##  .  .#. +# .................   ....................  +#- ..---.#-..  +###########..--++++..###
#+## .... .################     #  ...   #-  ..................# .....................  #..+---..#   ###############+..-++--.###
###- ..  +####################. .#  .... -#................... ##-................... .## ---.  ##+###################..-+--.###
###. .  ###########################  ....   ...................  .........   ........ +...--- +########################...--.###
###. . ##########################.-#  ..................   ..              #........ +-----..+#.########################-.--.###
###   -#########################+..-#  ..................#    .-+++######### ...... -+----..##.. #########################...###
###  .###+---+##################..-.-#   ...............  +############.    ...... .+----..##..- ##########################..###
###  ##-+###+###################...-.-##   ..............                ........  ++--. .#...-. ########################### ###
### ##+####+#####################..--..##.  .................................... .+--.. ###..--.-###########################.###
###########+###################### .--..###    ................................ .+-.. .####..-. ################################
####+#############################..--..+####    ............................  ++.  -#####..--..###############################.
###+############################### .--. #######     ....................... .-. .#######+..-. ################################ 
#################################### .--. +########     ..................   ..########## .--..#################################
##################################### .--. ########+###.                  .####+######## .--. ##################################
###################################### .. #########.-++#######--... .--####++--#.-###### ..-..##################################
#######################################  #######..+#++####+-+++.######++---++-#+--.+#####... ###################################
#############################################+..+++##-++++##### -- ++###++##+##-+#++-.####- .##################################.
###########################################+.-+#++++++##++.    .----. .+##+++++++++++++--##-##################################. 

                                                            REBECCA
*/

typedef struct {
    VkImage image;
    VkImageView view;
    VkFormat format;
    u32 allocation_id;
} DepthBuffer;

#define PIPELINE_COUNT 2
#define PIPELINE_DISTRIBUTION_ID 0
#define PIPELINE_TRIANGLE_ID 1

static void* s_pipeline_buffer = NULL; 
static VkPipeline* s_pipelines = NULL;
static VkPipelineLayout* s_pipeline_layouts = NULL;

static VkCommandPool s_command_pool = NULL;
static VkDescriptorPool s_descriptor_pool = NULL;

static void* s_descriptor_buffer = NULL;
static VkDescriptorSetLayout* s_descriptor_layout_sets = NULL;
static VkDescriptorSet* s_descriptor_sets = NULL;
static u32 s_descriptor_layout_set_count = 0;

static DepthBuffer s_depth_buffer = (DepthBuffer){0};

static EventCallback s_event_callback = NULL;

#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(s_event_callback, code, _fail)

typedef struct {
    float viewport_params[4];
} GlobalUniformBuffer;

// ================================================== SCREEN BUFFERS
// =================================================================

b32 createDepthBuffer(VkDevice device) {
    VkExtent2D screen_extent = getSwapchainContextPtr()->descriptor.extent;
    s_depth_buffer.format = VK_FORMAT_D16_UNORM;
    VkImageCreateInfo image_info = (VkImageCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .imageType = VK_IMAGE_TYPE_2D,
        .extent = (VkExtent3D){
            .width = screen_extent.width, 
            .height = screen_extent.height, 
            .depth = 1
        },
        .format = s_depth_buffer.format,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = 1,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE
    };
    ERROR_CATCH(vkCreateImage(device, &image_info, NULL, &s_depth_buffer.image) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_FAILED_TO_CREATE_DEPTH_IMAGE)
    }
    VkImageViewCreateInfo image_view_info = (VkImageViewCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
        .image = s_depth_buffer.image,
        .format = s_depth_buffer.format,
        .subresourceRange = (VkImageSubresourceRange) {
            .baseMipLevel = 0,
            .levelCount = 1,
            .baseArrayLayer = 0,
            .layerCount = 1,
            .aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT
        }
    };

    ERROR_CATCH(vramAllocateImages(1, &s_depth_buffer.image, MEMORY_BLOCK_DEVICE_ID, &s_depth_buffer.allocation_id) != VRAM_ALLOCATE_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_FAILED_TO_ALLOCATE_DEPTH_IMAGE)
    }
    ERROR_CATCH(vkCreateImageView(device, &image_view_info, NULL, &s_depth_buffer.view) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_FAILED_TO_CREATE_DEPTH_IMAGE_VIEW)
    }
//_success:
    return TRUE;
_fail:
    return FALSE;
}

void destroyDepthBuffer(VkDevice device) {
    vkDestroyImageView(device, s_depth_buffer.view, NULL);
    vkDestroyImage(device, s_depth_buffer.image, NULL);
    vramFree(MEMORY_BLOCK_DEVICE_ID, s_depth_buffer.allocation_id);
    s_depth_buffer = (DepthBuffer){0};
}

// ================================================ RENDER PIPELINES
// =================================================================

b32 createDistributionPipeline(VkDevice device, const VkShaderModule* shader_modules, VkPipeline* const pipeline, VkPipelineLayout* const layout) {
    VkPipelineLayoutCreateInfo layout_info = (VkPipelineLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .flags = 0,
        .pPushConstantRanges = NULL,
        .pushConstantRangeCount = 0,
        .setLayoutCount = 1,
        .pSetLayouts = s_descriptor_layout_sets
    };
    ERROR_CATCH(vkCreatePipelineLayout(device, &layout_info, NULL, layout) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DISTRIBUTION_PIPELINE_LAYOUT_CREATE)
    }

    VkComputePipelineCreateInfo pipeline_info = (VkComputePipelineCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
        .basePipelineHandle = NULL,
        .basePipelineIndex = -1,
        .stage = (VkPipelineShaderStageCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .pName = SHADER_ENTRY_COMPUTE,
            .stage = VK_SHADER_STAGE_COMPUTE_BIT,
            .module = shader_modules[SHADER_ID_DISTRIBUTION_C]
        },
        .layout = *layout
    };
    ERROR_CATCH(vkCreateComputePipelines(device, NULL, 1, &pipeline_info, NULL, pipeline) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DISTRIBUTION_PIPELINE_CREATE)
    }
//_sucess:
    return TRUE;
_fail:
    return FALSE;
}

b32 createTrianglePipeline(VkDevice device, const VkShaderModule* shader_modules, VkPipeline* const pipeline, VkPipelineLayout* const layout) {
    VkPipelineLayoutCreateInfo layout_info = (VkPipelineLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .flags = 0,
        .pPushConstantRanges = NULL,
        .pushConstantRangeCount = 0,
        .setLayoutCount = 1,
        .pSetLayouts = s_descriptor_layout_sets
    };
    ERROR_CATCH(vkCreatePipelineLayout(device, &layout_info, NULL, layout) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_TRIANGLE_PIPELINE_LAYOUT_CREATE)
    }

    VkPipelineShaderStageCreateInfo shader_stages[2] = {
        (VkPipelineShaderStageCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .pName = SHADER_ENTRY_VERTEX,
            .stage = VK_SHADER_STAGE_VERTEX_BIT,
            .module = shader_modules[SHADER_ID_TRIANGLE_V]
        },
        (VkPipelineShaderStageCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .pName = SHADER_ENTRY_FRAGMENT,
            .stage = VK_SHADER_STAGE_FRAGMENT_BIT,
            .module = shader_modules[SHADER_ID_TRIANGLE_F]
        }
    };

    VkPipelineDynamicStateCreateInfo dynamic_state = (VkPipelineDynamicStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,
        .dynamicStateCount = 2,
        .pDynamicStates = (const VkDynamicState[]){VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR}
    };
    VkPipelineVertexInputStateCreateInfo vertex_input_state = (VkPipelineVertexInputStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
        .vertexAttributeDescriptionCount = 0,
        .vertexBindingDescriptionCount = 0,
        .pVertexAttributeDescriptions = NULL,
        .pVertexBindingDescriptions = NULL
    };
    VkPipelineInputAssemblyStateCreateInfo input_assembly_state = (VkPipelineInputAssemblyStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
        .topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
        .primitiveRestartEnable = FALSE
    };
    VkPipelineRasterizationStateCreateInfo rasterization_state = (VkPipelineRasterizationStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
        .depthClampEnable = FALSE,
        .rasterizerDiscardEnable = FALSE,
        .polygonMode = VK_POLYGON_MODE_FILL,
        .lineWidth = 1.0f,
        .cullMode = VK_CULL_MODE_NONE,
        .frontFace = VK_FRONT_FACE_CLOCKWISE,
        .depthBiasEnable = FALSE,
        .depthBiasConstantFactor = 0.0f,
        .depthBiasClamp = 0.0f,
        .depthBiasSlopeFactor = 0.0f
    };
    VkPipelineMultisampleStateCreateInfo multisample_state = (VkPipelineMultisampleStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
        .sampleShadingEnable = FALSE,
        .rasterizationSamples = VK_SAMPLE_COUNT_1_BIT,
        .minSampleShading = 1.0f,
        .pSampleMask = NULL,
        .alphaToCoverageEnable = FALSE,
        .alphaToOneEnable = FALSE
    };
    VkPipelineColorBlendAttachmentState color_blend_attachment_state = (VkPipelineColorBlendAttachmentState) {
        .colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT,
        .blendEnable = VK_FALSE,
        .srcColorBlendFactor = VK_BLEND_FACTOR_ONE,
        .dstColorBlendFactor = VK_BLEND_FACTOR_ZERO,
        .colorBlendOp = VK_BLEND_OP_ADD,
        .srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE,
        .dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO,
        .alphaBlendOp = VK_BLEND_OP_ADD
    };
    VkPipelineColorBlendStateCreateInfo color_blend_state = (VkPipelineColorBlendStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
        .logicOpEnable = VK_FALSE,
        .logicOp = VK_LOGIC_OP_COPY,
        .attachmentCount = 1,
        .pAttachments = &color_blend_attachment_state,
        .blendConstants[0] = 0.0f,
        .blendConstants[1] = 0.0f,
        .blendConstants[2] = 0.0f,
        .blendConstants[3] = 0.0f
    };
    VkPipelineRenderingCreateInfoKHR rendering_create_info = (VkPipelineRenderingCreateInfoKHR) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR,
        .colorAttachmentCount = 1,
        .pColorAttachmentFormats = &getSwapchainContextPtr()->descriptor.color_format.format
    };

    VkPipelineViewportStateCreateInfo viewport_state = (VkPipelineViewportStateCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
        .viewportCount = 1,
        .scissorCount = 1
    };

    VkGraphicsPipelineCreateInfo pipeline_info = (VkGraphicsPipelineCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
        .basePipelineHandle = NULL,
        .basePipelineIndex = -1,
        .stageCount = 2,
        .pStages = shader_stages,
        .pVertexInputState = &vertex_input_state,
        .pInputAssemblyState = &input_assembly_state,
        .pViewportState = &viewport_state,
        .pRasterizationState = &rasterization_state,
        .pMultisampleState = &multisample_state,
        .pDepthStencilState = NULL,
        .pColorBlendState = &color_blend_state,
        .pDynamicState = &dynamic_state,
        .layout = *layout,
        .renderPass = NULL,
        .pNext = &rendering_create_info
    };

    ERROR_CATCH(vkCreateGraphicsPipelines(device, NULL, 1, &pipeline_info, NULL, pipeline) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_TRIANGLE_PIPELINE_CREATE)
    }
//_sucess:
    return TRUE;
_fail:
    return FALSE;
}

// ===================================================== DESCRIPTORS
// =================================================================

b32 createDescriptorSets(VkDevice device, VkDescriptorPool pool, VkDescriptorSet* const descriptor_sets, VkDescriptorSetLayout* const layout_sets) {
    VkDescriptorSetLayoutCreateInfo layout_set_info = (VkDescriptorSetLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .bindingCount = 2,
        .pBindings = (VkDescriptorSetLayoutBinding[]) {
            (VkDescriptorSetLayoutBinding) {
                .binding = 0,
                .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .descriptorCount = 1,
                .stageFlags = VK_SHADER_STAGE_ALL_GRAPHICS
            },
            (VkDescriptorSetLayoutBinding) {
                .binding = 1,
                .descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                .descriptorCount = 1,
                .stageFlags = VK_SHADER_STAGE_ALL
            }
        }
    };
    ERROR_CATCH(vkCreateDescriptorSetLayout(device, &layout_set_info, NULL, layout_sets) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_CREATE_DESCRIPTOR_SET_LAYOUT)
    }

    VkDescriptorSetAllocateInfo allocate_info = (VkDescriptorSetAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        .descriptorPool = pool,
        .descriptorSetCount = 1,
        .pSetLayouts = layout_sets
    };
    ERROR_CATCH(vkAllocateDescriptorSets(device, &allocate_info, descriptor_sets) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_ALLOCATE_DISCRIPTOR_SET)
    }
    
//_sucess:
    return TRUE;
_fail:
    return FALSE;
}

// ================================================ RENDER INTERFACE
// =================================================================

b32 renderLoop(UpdateCallback update_callback) {
    VulkanContext vulkan_context = *getVulkanContextPtr();
    QueueContext queue_context = *getQueueContextPtr();
    ExtContext ext_context = *getExtensionContextPtr();

    VkSemaphore image_available_semaphore;
    VkSemaphore image_finished_semaphore;
    VkFence in_flight_fence;
    b32 func_result;

    VkCommandBuffer command_buffer;
    VkCommandBufferAllocateInfo cmbuffers_info = (VkCommandBufferAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandBufferCount = 1,
        .commandPool = s_command_pool,
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY
    };
    ERROR_CATCH(vkAllocateCommandBuffers(vulkan_context.device, &cmbuffers_info, &command_buffer) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_COMMAND_BUFFER_ALLOCATE)
    }
    VkSemaphoreCreateInfo semaphore_info = (VkSemaphoreCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
    };
    VkFenceCreateInfo fence_info = (VkFenceCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        .flags = VK_FENCE_CREATE_SIGNALED_BIT
    };
    ERROR_CATCH(vkCreateSemaphore(vulkan_context.device, &semaphore_info, NULL, &image_available_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEAMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateSemaphore(vulkan_context.device, &semaphore_info, NULL, &image_finished_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEAMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateFence(vulkan_context.device, &fence_info, NULL, &in_flight_fence)) {
        _INVOKE_CALLBACK(VK_ERR_FENCE_CREATE)
    }

    VkRenderingAttachmentInfoKHR color_attachment = (VkRenderingAttachmentInfoKHR) {
        .sType = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO_KHR,
        .clearValue = (VkClearValue) {
            .color = (VkClearColorValue){0},
            .depthStencil = (VkClearDepthStencilValue){0}
        },
        .imageLayout = VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR,
        .loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR,
        .storeOp = VK_ATTACHMENT_STORE_OP_STORE
    };
    VkRenderingInfoKHR vk_rendeirng_info = (VkRenderingInfoKHR) {
        .sType = VK_STRUCTURE_TYPE_RENDERING_INFO_KHR,
        .colorAttachmentCount = 1,
        .pColorAttachments = &color_attachment,
        .layerCount = 1
    };
    VkImageMemoryBarrier image_memory_top_barrier = (VkImageMemoryBarrier) {
        .sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        .dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        .oldLayout = VK_IMAGE_LAYOUT_UNDEFINED,
        .newLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        .subresourceRange = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .baseMipLevel = 0,
            .levelCount = 1,
            .baseArrayLayer = 0,
            .layerCount = 1,
        }
    };
    VkImageMemoryBarrier image_memory_bottom_barrier = (VkImageMemoryBarrier) {
        .sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        .srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        .oldLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        .newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
        .subresourceRange = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .baseMipLevel = 0,
            .levelCount = 1,
            .baseArrayLayer = 0,
            .layerCount = 1,
        }
    };
    VkViewport viewport;
    u32 image_id;


    // buffer creation
    VkBuffer global_uniform_buffer_device;
    VkBuffer global_uniform_buffer_host;
    VkBuffer position_buffer_device;
    VkBufferCreateInfo buffer_create_info = (VkBufferCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        .usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        .queueFamilyIndexCount = 1,
        .pQueueFamilyIndices = &queue_context.queue_locators[CURRENT_QUEUE_ID].family_id,
        .size = sizeof(GlobalUniformBuffer),
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE
    };
    ERROR_CATCH(vkCreateBuffer(vulkan_context.device, &buffer_create_info, NULL, &global_uniform_buffer_device) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_GLOBAL_UNIFORM_BUFFER_DEVICE_CREATE)
    }
    buffer_create_info = (VkBufferCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        .usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
        .queueFamilyIndexCount = 1,
        .pQueueFamilyIndices = &queue_context.queue_locators[CURRENT_QUEUE_ID].family_id,
        .size = sizeof(GlobalUniformBuffer),
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE
    };
    ERROR_CATCH(vkCreateBuffer(vulkan_context.device, &buffer_create_info, NULL, &global_uniform_buffer_host) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_GLOBAL_UNIFORM_BUFFER_HOST_CREATE)
    }
    buffer_create_info = (VkBufferCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        .usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
        .queueFamilyIndexCount = 1,
        .pQueueFamilyIndices = &queue_context.queue_locators[CURRENT_QUEUE_ID].family_id,
        .size = sizeof(float) * 2 * 64,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE
    };
    ERROR_CATCH(vkCreateBuffer(vulkan_context.device, &buffer_create_info, NULL, &position_buffer_device) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_POSITION_BUFFER_HOST_CREATE)
    }

    u32 gubuffer_host_id, buffers_device_id;
    ERROR_CATCH(vramAllocateBuffers(1, &global_uniform_buffer_host, MEMORY_BLOCK_HOST_ID, &gubuffer_host_id) != VRAM_ALLOCATE_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_GLOBAL_UNIFORM_BUFFER_HOST_ALLOCATE)
    }
    ERROR_CATCH(vramAllocateBuffers(2, (VkBuffer[]){global_uniform_buffer_device, position_buffer_device}, MEMORY_BLOCK_DEVICE_ID, &buffers_device_id) != VRAM_ALLOCATE_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_GLOBAL_UNIFORM_BUFFER_DEVICE_ALLOCATE)
    }

    VkDescriptorBufferInfo descriptor_gubuffer_info = (VkDescriptorBufferInfo) {
        .buffer = global_uniform_buffer_device,
        .offset = 0,
        .range = sizeof(GlobalUniformBuffer)
    };
    VkDescriptorBufferInfo descriptor_pbuffer_info = (VkDescriptorBufferInfo) {
        .buffer = position_buffer_device,
        .offset = 0,
        .range = sizeof(float) * 2 * 64
    };
    // write descriptor set
    VkWriteDescriptorSet descriptor_set_writes[] = {
        (VkWriteDescriptorSet) {
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = s_descriptor_sets[0],
            .dstBinding = 0,
            .dstArrayElement = 0,
            .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            .descriptorCount = 1,
            .pBufferInfo = &descriptor_gubuffer_info,
            .pImageInfo = NULL,
            .pTexelBufferView = NULL
        },
        (VkWriteDescriptorSet) {
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = s_descriptor_sets[0],
            .dstBinding = 1,
            .dstArrayElement = 0,
            .descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            .descriptorCount = 1,
            .pBufferInfo = &descriptor_pbuffer_info,
            .pImageInfo = NULL,
            .pTexelBufferView = NULL
        }
    };
    vkUpdateDescriptorSets(vulkan_context.device, 2, descriptor_set_writes, 0, NULL);

    // render loop
    while(!glfwWindowShouldClose(vulkan_context.window)) {
        glfwPollEvents();
        vkWaitForFences(vulkan_context.device, 1, &in_flight_fence, VK_TRUE, U32_MAX);
        VkResult image_acquire_result = vkAcquireNextImageKHR(vulkan_context.device, getSwapchainContextPtr()->swapchain, U32_MAX, image_available_semaphore, NULL, &image_id);
        if(image_acquire_result == VK_ERROR_OUT_OF_DATE_KHR) {
            vkDeviceWaitIdle(vulkan_context.device);
            recreateSwapchain();
            destroyDepthBuffer(vulkan_context.device);
            createDepthBuffer(vulkan_context.device);
            continue;
        }

        vk_rendeirng_info.renderArea = (VkRect2D) {
            .extent = getSwapchainContextPtr()->descriptor.extent,
            .offset = (VkOffset2D){0}
        };
        viewport = (VkViewport) {
            .width = (float)vk_rendeirng_info.renderArea.extent.width,
            .height = (float)vk_rendeirng_info.renderArea.extent.height,
            .maxDepth = 1.0f,
            .minDepth = 0.0f,
            .x = 0,
            .y = 0
        };

        image_memory_top_barrier.image = getSwapchainContextPtr()->images[image_id];
        image_memory_bottom_barrier.image = getSwapchainContextPtr()->images[image_id];
            
        GlobalUniformBuffer gubuffer_struct = (GlobalUniformBuffer) {
            .viewport_params = {viewport.x, viewport.y, viewport.width, viewport.height}
        };
        ERROR_CATCH(!vramWriteToAllocation(MEMORY_BLOCK_HOST_ID, gubuffer_host_id, (VramWriteDscr[]){{.src = &gubuffer_struct, .size = sizeof(GlobalUniformBuffer)}})) {
            _INVOKE_CALLBACK(VK_ERR_GLOBAL_UNIFORM_BUFFER_WRITE)
        }
        
        VkCommandBufferBeginInfo command_buffer_begin_info = (VkCommandBufferBeginInfo) {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
            .flags = 0,
            .pInheritanceInfo = NULL
        };
        vkResetFences(vulkan_context.device, 1, &in_flight_fence);
        vkResetCommandBuffer(command_buffer, 0);
        vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);//@(Mitro): should chekc error if fails

        
        VkBufferCopy buffer_copy = (VkBufferCopy) {
            .dstOffset = 0,
            .srcOffset = 0,
            .size = sizeof(GlobalUniformBuffer)
        };
        vkCmdCopyBuffer(command_buffer, global_uniform_buffer_host, global_uniform_buffer_device, 1, &buffer_copy);

        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 
            0, 0, NULL, 0, NULL, 0, NULL
        );

        // distribution pass
        vkCmdBindDescriptorSets(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, s_pipeline_layouts[PIPELINE_DISTRIBUTION_ID], 0, 1, s_descriptor_sets, 0, NULL);
        vkCmdBindDescriptorSets(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, s_pipeline_layouts[PIPELINE_TRIANGLE_ID], 0, 1, s_descriptor_sets, 0, NULL);

        vkCmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, s_pipelines[PIPELINE_DISTRIBUTION_ID]);
        vkCmdDispatch(command_buffer, 1, 1, 1);
        

        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 
            0, 0, NULL, 0, NULL, 0, NULL
        );
        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 
            0, 0, NULL, 0, NULL, 1, &image_memory_top_barrier
        );
        color_attachment.imageView = getSwapchainContextPtr()->views[image_id];
        ext_context.cmd_begin_rendering(command_buffer, &vk_rendeirng_info);
        
        vkCmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, s_pipelines[PIPELINE_TRIANGLE_ID]);
        vkCmdSetViewport(command_buffer, 0, 1, &viewport);
        vkCmdSetScissor(command_buffer, 0, 1, &vk_rendeirng_info.renderArea);

        vkCmdDraw(command_buffer, 3 * 64, 1, 0, 0);
        //... DRAW here

        ext_context.cmd_end_rendering(command_buffer);
        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 
            0, 0, NULL, 0, NULL, 1, &image_memory_bottom_barrier
        );

        vkEndCommandBuffer(command_buffer);
        VkSubmitInfo submit_info = (VkSubmitInfo) {
            .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
            .waitSemaphoreCount = 1,
            .pWaitSemaphores = &image_available_semaphore,
            .pWaitDstStageMask = (const VkPipelineStageFlags[]){VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
            .signalSemaphoreCount = 1,
            .pSignalSemaphores = &image_finished_semaphore,
            .commandBufferCount = 1,
            .pCommandBuffers = &command_buffer
        };
        ERROR_CATCH(vkQueueSubmit(queue_context.queues[CURRENT_QUEUE_ID], 1, &submit_info, in_flight_fence) != VK_SUCCESS) {
            _INVOKE_CALLBACK(VK_ERR_QUEUE_SUBMIT)
        }

        VkPresentInfoKHR present_info = (VkPresentInfoKHR) {
            .sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
            .waitSemaphoreCount = 1,
            .pWaitSemaphores = &image_finished_semaphore,
            .swapchainCount = 1,
            .pSwapchains = &getSwapchainContextPtr()->swapchain,
            .pImageIndices = &image_id,
            .pResults = NULL
        };
        VkResult present_result = vkQueuePresentKHR(queue_context.queues[CURRENT_QUEUE_ID], &present_info);
        if(present_result == VK_ERROR_OUT_OF_DATE_KHR) {
            vkDeviceWaitIdle(vulkan_context.device);
            recreateSwapchain();
            destroyDepthBuffer(vulkan_context.device);
            createDepthBuffer(vulkan_context.device);
            continue;
        }
    }
    vkDeviceWaitIdle(vulkan_context.device);
//_sucess:
    func_result = TRUE;
    goto _dispose;
_fail:
    func_result = FALSE;
_dispose:
    SAFE_DESTROY(global_uniform_buffer_device, vkDestroyBuffer(vulkan_context.device, global_uniform_buffer_device, NULL))
    SAFE_DESTROY(global_uniform_buffer_host, vkDestroyBuffer(vulkan_context.device, global_uniform_buffer_host, NULL))
    SAFE_DESTROY(position_buffer_device, vkDestroyBuffer(vulkan_context.device, position_buffer_device, NULL))

    SAFE_DESTROY(image_available_semaphore, vkDestroySemaphore(vulkan_context.device, image_available_semaphore, NULL))
    SAFE_DESTROY(image_finished_semaphore, vkDestroySemaphore(vulkan_context.device, image_finished_semaphore, NULL))
    SAFE_DESTROY(in_flight_fence, vkDestroyFence(vulkan_context.device, in_flight_fence, NULL))
    return func_result;
}

b32 renderInit(EventCallback event_callback) {
    VulkanContext vulkan_context = *getVulkanContextPtr();
    QueueContext queue_context = *getQueueContextPtr();
    s_event_callback = event_callback ? event_callback : vulkan_context.callback;

    // creating allocation pools
    VkCommandPoolCreateInfo command_pool_info = (VkCommandPoolCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
        .queueFamilyIndex = queue_context.queue_locators[CURRENT_QUEUE_ID].family_id,
        .flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT
    };
    ERROR_CATCH(vkCreateCommandPool(vulkan_context.device, &command_pool_info, NULL, &s_command_pool) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_COMMAND_POOL_CREATE)
    }
        
    VkDescriptorPoolCreateInfo descriptor_pool_info = (VkDescriptorPoolCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .maxSets = DESCRIPTOR_SET_COUNT,
        .poolSizeCount = 1,
        .pPoolSizes = (VkDescriptorPoolSize[]) {
            (VkDescriptorPoolSize) {
                .type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .descriptorCount = DESCRIPTOR_MAX_COUNT
            }
        }
    };
    ERROR_CATCH(vkCreateDescriptorPool(vulkan_context.device, &descriptor_pool_info, NULL, &s_descriptor_pool) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_POOL_CREATE)
    }

    // descriptor set creation
    s_descriptor_buffer = malloc(sizeof(void*) * DESCRIPTOR_SET_COUNT * 2);
    ERROR_CATCH(!s_descriptor_buffer) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_BUFFER_ALLOCATE)
    }

    s_descriptor_layout_sets = s_descriptor_buffer;
    s_descriptor_sets = (VkDescriptorSet*)((void**)s_descriptor_buffer + DESCRIPTOR_SET_COUNT);
    s_descriptor_layout_set_count = 1;
    ERROR_CATCH(!createDescriptorSets(vulkan_context.device, s_descriptor_pool, s_descriptor_sets, s_descriptor_layout_sets)) {
        goto _fail;
    }
    
    // depth buffer
    ERROR_CATCH(!createDepthBuffer(vulkan_context.device)) {
        goto _fail;
    }

    // pipelines creation
    s_pipeline_buffer = malloc(sizeof(void*) * PIPELINE_COUNT * 2);
    ERROR_CATCH(!s_pipeline_buffer) {
        _INVOKE_CALLBACK(VK_ERR_PIPELINE_BUFFER_ALLOCATE)
    }
    s_pipeline_layouts = s_pipeline_buffer;
    s_pipelines = (VkPipeline*)((void**)s_pipeline_buffer + PIPELINE_COUNT);

    const VkShaderModule* shader_modules = getShaderModulesPtr();
    ERROR_CATCH(!createTrianglePipeline(vulkan_context.device, shader_modules, s_pipelines + PIPELINE_TRIANGLE_ID, s_pipeline_layouts + PIPELINE_TRIANGLE_ID)) {
        goto _fail;
    }
    ERROR_CATCH(!createDistributionPipeline(vulkan_context.device, shader_modules, s_pipelines + PIPELINE_DISTRIBUTION_ID, s_pipeline_layouts + PIPELINE_DISTRIBUTION_ID)) {
        goto _fail;
    }

//_sucess:
    return TRUE;
_fail:
    return FALSE;
}

void renderTerminate(void) {
    VulkanContext vulkan_context = *getVulkanContextPtr();

    for(u32 i = 0; i < PIPELINE_COUNT; i++) {
        SAFE_DESTROY(s_pipelines[i], vkDestroyPipeline(vulkan_context.device, s_pipelines[i], NULL))
        SAFE_DESTROY(s_pipeline_layouts[i], vkDestroyPipelineLayout(vulkan_context.device, s_pipeline_layouts[i], NULL))
    }
    SAFE_DESTROY(s_pipeline_buffer, free(s_pipeline_buffer))
    s_pipeline_layouts = NULL;
    s_pipelines = NULL;

    destroyDepthBuffer(vulkan_context.device);

    for(u32 i = 0; i < s_descriptor_layout_set_count; i++) {
        SAFE_DESTROY(s_descriptor_layout_sets[i], vkDestroyDescriptorSetLayout(vulkan_context.device, s_descriptor_layout_sets[i], NULL))
    }
    SAFE_DESTROY(s_descriptor_buffer, free(s_descriptor_buffer));
    s_descriptor_layout_sets = NULL;
    s_descriptor_sets = NULL;
    s_descriptor_layout_set_count = 0;
    SAFE_DESTROY(s_descriptor_pool, vkDestroyDescriptorPool(vulkan_context.device, s_descriptor_pool, NULL))
    SAFE_DESTROY(s_command_pool, vkDestroyCommandPool(vulkan_context.device, s_command_pool, NULL))
}
