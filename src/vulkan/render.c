
#define INCLUDE_VULKAN_INTERNALS
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

#define PIPELINE_COUNT 1

const u32 c_command_pool_count = DEVICE_QUEUE_COUNT;
static VkCommandPool s_command_pools[DEVICE_QUEUE_COUNT] = {0};

static u32 s_shader_module_count = 0;
static VkShaderModule* s_shader_modules = NULL;

static EventCallback s_event_callback = NULL;
static VulkanContext s_vulkan_context = NULL;
static ExtContext s_ext_context = (ExtContext){0};
static SwapchainContext s_swapchain_context = (SwapchainContext){0};

static u32 c_pipeline_count = PIPELINE_COUNT;
static void* s_pipeline_buffer = NULL; 
static VkPipeline* s_pipelines = NULL;
static VkPipelineLayout* s_pipeline_layouts = NULL;

#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(s_event_callback, code, _fail)

// =================================================== RENDER PASSES
// =================================================================

b32 readShaderFile(const char* path, u64 buffer_size, u32* const buffer) {
    FILE* file = fopen(path, "rb");
    ERROR_CATCH(!file) return FALSE;
    fread(buffer, 1, buffer_size, file);
    fclose(file);
    return TRUE;
}

b32 createTrianglePipeline(VkPipeline* const pipeline, VkPipelineLayout* const layout, const VkShaderModule* shader_modules) {
    VkPipelineLayoutCreateInfo layout_info = (VkPipelineLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .flags = 0,
        .pPushConstantRanges = NULL,
        .pSetLayouts = NULL,
        .pushConstantRangeCount = 0,
        .setLayoutCount = 0
    };
    ERROR_CATCH(vkCreatePipelineLayout(s_vulkan_context.device, &layout_info, NULL, layout) != VK_SUCCESS) {
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
        .pColorAttachmentFormats = &s_swapchain_context.descriptor->color_format.format
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

    ERROR_CATCH(vkCreateGraphicsPipelines(s_vulkan_context.device, NULL, 1, &pipeline_info, NULL, pipeline) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_TRIANGLE_PIPELINE_CREATE)
    }
_fail:
    return FALSE;
}

// ================================================ RENDER INTERFACE
// =================================================================

b32 renderLoop(void) {
    static VkSemaphore s_image_available_semaphore = NULL;
    static VkSemaphore s_image_finished_semaphore = NULL;
    static VkFence s_in_flight_fence = NULL;

    VkCommandBuffer command_buffer;
    VkCommandBufferAllocateInfo cmbuffers_info = (VkCommandBufferAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandBufferCount = 1,
        .commandPool = s_command_pools[0],
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY
    };
    ERROR_CATCH(vkAllocateCommandBuffers(s_vulkan_context.device, &cmbuffers_info, &command_buffer) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_COMMAND_BUFFER_ALLOCATE)
    }
    VkSemaphoreCreateInfo semaphore_info = (VkSemaphoreCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
    };
    VkFenceCreateInfo fence_info = (VkFenceCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        .flags = VK_FENCE_CREATE_SIGNALED_BIT
    };
    ERROR_CATCH(vkCreateSemaphore(s_vulkan_context.device, &semaphore_info, NULL, &s_image_available_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEAMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateSemaphore(s_vulkan_context.device, &semaphore_info, NULL, &s_image_finished_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEAMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateFence(s_vulkan_context.device, &fence_info, NULL, &s_in_flight_fence)) {
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

    // render loop
    while(!glfwWindowShouldClose(s_vulkan_context.window)) {
        glfwPollEvents();
        vkWaitForFences(s_vulkan_context.device, 1, &s_in_flight_fence, VK_TRUE, U32_MAX);
        VkResult image_acquire_result = vkAcquireNextImageKHR(s_vulkan_context.device, s_vulkan_context.swapchain, U32_MAX, s_image_available_semaphore, NULL, &image_id);
        if(image_acquire_result == VK_ERROR_OUT_OF_DATE_KHR) {
            vkDeviceWaitIdle(s_vulkan_context.device);
            recreateSwapchain();
            getVulkanContext(&s_vulkan_context);
            getSwapchainContext(&s_swapchain_context);
            continue;
        }

        vk_rendeirng_info.renderArea = (VkRect2D) {
            .extent = s_swapchain_context.descriptor->extent,
            .offset = (VkOffset2D){0}
        };
        viewport = (VkViewport) {
            .width = vk_rendeirng_info.renderArea.extent.width,
            .height = vk_rendeirng_info.renderArea.extent.height,
            .maxDepth = 1.0f,
            .minDepth = 0.0f,
            .x = 0,
            .y = 0
        };

        vkResetFences(s_vulkan_context.device, 1, &s_in_flight_fence);
        vkResetCommandBuffer(command_buffer, 0);
        VkCommandBufferBeginInfo command_buffer_begin_info = (VkCommandBufferBeginInfo) {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
            .flags = 0,
            .pInheritanceInfo = NULL
        };
        vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);//@(Mitro): should chekc error if fails

        image_memory_top_barrier.image = s_swapchain_context.images[image_id];
        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 
            0, 0, NULL, 0, NULL, 1, &image_memory_top_barrier
        );
        color_attachment.imageView = s_swapchain_context.views[image_id];
        s_ext_context.cmd_begin_rendering(command_buffer, &vk_rendeirng_info);

        vkCmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, s_pipelines[0]);
        vkCmdSetViewport(command_buffer, 0, 1, &viewport);
        vkCmdSetScissor(command_buffer, 0, 1, &vk_rendeirng_info.renderArea);

        vkCmdDraw(command_buffer, 3, 1, 0, 0);
        //... DRAW here

        s_ext_context.cmd_end_rendering(command_buffer);
        image_memory_bottom_barrier.image = s_swapchain_context.images[image_id];
        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 
            0, 0, NULL, 0, NULL, 1, &image_memory_bottom_barrier
        );

        vkEndCommandBuffer(command_buffer);
        VkSubmitInfo submit_info = (VkSubmitInfo) {
            .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
            .waitSemaphoreCount = 1,
            .pWaitSemaphores = &s_image_available_semaphore,
            .pWaitDstStageMask = (const VkPipelineStageFlags[]){VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
            .signalSemaphoreCount = 1,
            .pSignalSemaphores = &s_image_finished_semaphore,
            .commandBufferCount = 1,
            .pCommandBuffers = &command_buffer
        };
        ERROR_CATCH(vkQueueSubmit(s_vulkan_context.queues[0], 1, &submit_info, s_in_flight_fence) != VK_SUCCESS) {
            _INVOKE_CALLBACK(VK_ERR_QUEUE_SUBMIT)
        }

        VkPresentInfoKHR present_info = (VkPresentInfoKHR) {
            .sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
            .waitSemaphoreCount = 1,
            .pWaitSemaphores = &s_image_finished_semaphore,
            .swapchainCount = 1,
            .pSwapchains = &s_vulkan_context.swapchain,
            .pImageIndices = &image_id,
            .pResults = NULL
        };
        VkResult present_result = vkQueuePresentKHR(s_vulkan_context.queues[0], &present_info);
        if(present_result == VK_ERROR_OUT_OF_DATE_KHR) {
            vkDeviceWaitIdle(s_vulkan_context.device);
            recreateSwapchain();
            getVulkanContext(&s_vulkan_context);
            getSwapchainContext(&s_swapchain_context);
            continue;
        }
    }
    vkDeviceWaitIdle(s_vulkan_context.device);

//_sucess:
    SAFE_DESTROY(s_image_available_semaphore, vkDestroySemaphore(s_vulkan_context.device, s_image_available_semaphore, NULL))
    SAFE_DESTROY(s_image_finished_semaphore, vkDestroySemaphore(s_vulkan_context.device, s_image_finished_semaphore, NULL))
    SAFE_DESTROY(s_in_flight_fence, vkDestroyFence(s_vulkan_context.device, s_in_flight_fence, NULL))
    return TRUE;
_fail:
    SAFE_DESTROY(s_image_available_semaphore, vkDestroySemaphore(s_vulkan_context.device, s_image_available_semaphore, NULL))
    SAFE_DESTROY(s_image_finished_semaphore, vkDestroySemaphore(s_vulkan_context.device, s_image_finished_semaphore, NULL))
    SAFE_DESTROY(s_in_flight_fence, vkDestroyFence(s_vulkan_context.device, s_in_flight_fence, NULL))
    return FALSE;
}

b32 renderRun(UpdateCallback update_callback, EventCallback event_callback, const char* shader_path) {
    b32 func_result = TRUE;
    s_event_callback = event_callback ? event_callback : getCallbackPfn();
    getVulkanContext(&s_vulkan_context);
    getExtContext(&s_ext_context);
    getSwapchainContext(&s_swapchain_context);
    
    u64 stack_ptr;
    REMEMBER_RSP(stack_ptr) {
        // create command pools
        VkCommandPoolCreateInfo pool_info = (VkCommandPoolCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
        };
        for(u32 i = 0; i < c_command_pool_count; i++) {
            pool_info.queueFamilyIndex = s_vulkan_context.queue_locators[i].family_id;
            pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
            ERROR_CATCH(vkCreateCommandPool(s_vulkan_context.device, &pool_info, NULL, s_command_pools + i) != VK_SUCCESS) {
                _INVOKE_CALLBACK(VK_ERR_COMMAND_POOL_CREATE)
            }
        }

        // read shaders and create shader objects
        u32* shader_buffer = malloc(SHADER_BUFFER_SIZE);
        ERROR_CATCH(!shader_buffer) {
            _INVOKE_CALLBACK(VK_ERR_SHADER_BUFFER_ALLOCATE);
        }
        ERROR_CATCH(!readShaderFile(shader_path, SHADER_BUFFER_SIZE, shader_buffer)) {
            _INVOKE_CALLBACK(VK_ERR_SHADER_BUFFER_LOAD)
        }

        s_shader_module_count = SHADER_COUNT;
        s_shader_modules = malloc(sizeof(VkShaderModule) * SHADER_COUNT);
        ERROR_CATCH(!s_shader_modules) {
            _INVOKE_CALLBACK(VK_ERR_SHADER_MODULE_ARRAY_ALLOCATE);
        }
        VkShaderModuleCreateInfo shader_module_info = (VkShaderModuleCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO
        };
        for(u32 i = 0; i < SHADER_COUNT; i++) {
            shader_module_info.pCode = (u32*)((char*)shader_buffer + c_shader_infos[i].code_offset);
            shader_module_info.codeSize = c_shader_infos[i].code_size;
            vkCreateShaderModule(s_vulkan_context.device, &shader_module_info, NULL, s_shader_modules + i);
        }
        free(shader_buffer);

        s_pipeline_buffer = malloc(sizeof(void*) * c_pipeline_count * 2);
        ERROR_CATCH(!s_pipeline_buffer) {
            _INVOKE_CALLBACK(VK_ERR_PIPELINE_BUFFER_ALLOCATE)
        }
        s_pipeline_layouts = s_pipeline_buffer;
        s_pipelines = (VkPipeline*)((void**)s_pipeline_buffer + c_pipeline_count);
        createTrianglePipeline(s_pipelines, s_pipeline_layouts, s_shader_modules);
    } SET_RSP(stack_ptr)


    ERROR_CATCH(!renderLoop()) {
        _INVOKE_CALLBACK(VK_ERR_RENDER_LOOP_FAIL)
    }

//_sucess:
    goto _end;
_fail:
    func_result = FALSE;
_end:
    for(u32 i = 0; i < c_pipeline_count; i++) {
        SAFE_DESTROY(s_pipelines[i], vkDestroyPipeline(s_vulkan_context.device, s_pipelines[i], NULL))
    }
    for(u32 i = 0; i < c_pipeline_count; i++) {
        SAFE_DESTROY(s_pipeline_layouts[i], vkDestroyPipelineLayout(s_vulkan_context.device, s_pipeline_layouts[i], NULL))
    }
    for(u32 i = 0; i < s_shader_module_count; i++) {
        SAFE_DESTROY(s_shader_modules[i], vkDestroyShaderModule(s_vulkan_context.device, s_shader_modules[i], NULL))
    }
    SAFE_DESTROY(s_shader_modules, free(s_shader_modules));
    for(u32 i = 0; i < c_command_pool_count; i++) {
        SAFE_DESTROY(s_command_pools[i], vkDestroyCommandPool(s_vulkan_context.device, s_command_pools[i], NULL))
    }
    return func_result;
}
