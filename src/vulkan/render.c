
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

const u32 c_command_pool_count = DEVICE_QUEUE_COUNT;
static VkCommandPool s_command_pools[DEVICE_QUEUE_COUNT] = {0};

static u32 s_shader_module_count = 0;
static VkShaderModule* s_shader_modules = NULL;

static EventCallback s_event_callback = NULL;
static VulkanContext s_vulkan_context = (VulkanContext){0};
static ExtContext s_ext_context = (ExtContext){0};


#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(s_event_callback, code, _fail)

// =================================================== RENDER PASSES
// =================================================================

b32 readShaderFile(const char* path, u32 buffer_size, void* const buffer) {
    FILE* file = fopen(path, "rb");
    ERROR_CATCH(!file) return FALSE;
    fread(buffer, sizeof(u32), buffer_size / sizeof(u32), file);
    fclose(file);
    return TRUE;
}

static VkPipelineLayout s_triangle_pipeline_layout;
static VkPipeline s_triangle_pipeline;

b32 createTrianglePipeline(VkPipeline* const pipeline, VkPipelineLayout* const layout) {
    VkPipelineLayoutCreateInfo layout_info = (VkPipelineLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .flags = 0,
        .pPushConstantRanges = NULL,
        .pSetLayouts = NULL,
        .pushConstantRangeCount = 0,
        .setLayoutCount = 0
    };
    ERROR_CATCH(vkCreatePipelineLayout(s_vulkan_context.device, &layout_info, NULL, layout) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_TRIANGLE_PIPELINE_CREATE)
    }

    VkPipelineShaderStageCreateInfo shader_stages[2] = {
        (VkPipelineShaderStageCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .pName = SHADER_ENTRY_VERTEX,
            .stage = VK_SHADER_STAGE_VERTEX_BIT,
            .module = s_shader_modules[SHADER_ID_TRIANGLE_V]
        },
        (VkPipelineShaderStageCreateInfo) {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .pName = SHADER_ENTRY_FRAGMENT,
            .stage = VK_SHADER_STAGE_FRAGMENT_BIT,
            .module = s_shader_modules[SHADER_ID_TRIANGLE_F]
        }
    };

    

    VkGraphicsPipelineCreateInfo pipeline_info = (VkGraphicsPipelineCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
        .basePipelineHandle = NULL,
        .basePipelineIndex = -1,
        .stageCount = 2,
        .pStages = shader_stages,
        .pVertexInputState = &vertex_input_state,
        .pInputAssemblyState = &default_assembly_state,
        .pViewportState = &default_viewport_state,
        .pRasterizationState = &default_rasterization_state,
        .pMultisampleState = &multisample_state,
        .pDepthStencilState = NULL,
        .pColorBlendState = &default_color_blend_state,
        .pDynamicState = &default_dynamic_state,
        .layout = triangle_pipeline_layout,
        .renderPass = TRIANGLE_PASS,
        .subpass = 0,
    };
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

    SwapchainContext swapchain_context;
    getSwapchainContext(&swapchain_context);

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
    u32 image_id;

    // render loop
    while(!glfwWindowShouldClose(s_vulkan_context.window)) {
        glfwPollEvents();
        vkWaitForFences(s_vulkan_context.device, 1, &s_in_flight_fence, VK_TRUE, U32_MAX);
        VkResult image_acquire_result = vkAcquireNextImageKHR(s_vulkan_context.device, s_vulkan_context.swapchain, U32_MAX, s_image_available_semaphore, NULL, &image_id);
        if(EXPECT_F(image_acquire_result == VK_ERROR_OUT_OF_DATE_KHR)) {
            recreateSwapchain();
            continue;
        }

        vk_rendeirng_info.renderArea = (VkRect2D) {
            .extent = swapchain_context.descriptor->extent,
            .offset = (VkOffset2D) {0, 0}
        };

        vkResetFences(s_vulkan_context.device, 1, &s_in_flight_fence);
        vkResetCommandBuffer(command_buffer, 0);
        VkCommandBufferBeginInfo command_buffer_begin_info = (VkCommandBufferBeginInfo) {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
            .flags = 0,
            .pInheritanceInfo = NULL
        };
        vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);//@(Mitro): should chekc error if fails

        image_memory_top_barrier.image = swapchain_context.images[image_id];
        vkCmdPipelineBarrier(
            command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 
            0, 0, NULL, 0, NULL, 1, &image_memory_top_barrier
        );
        color_attachment.imageView = swapchain_context.views[image_id];
        s_ext_context.cmd_begin_rendering(command_buffer, &vk_rendeirng_info);
        
        //... DRAW here

        s_ext_context.cmd_end_rendering(command_buffer);
        image_memory_bottom_barrier.image = swapchain_context.images[image_id];
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
            recreateSwapchain();
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
    void* shader_buffer = malloc(SHADER_BUFFER_SIZE);
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

    ERROR_CATCH(!renderLoop()) {
        _INVOKE_CALLBACK(VK_ERR_RENDER_LOOP_FAIL)
    }

//_sucess:
    goto _end;
_fail:
    func_result = FALSE;
_end:
    for(u32 i = 0; i < s_shader_module_count; i++) {
        SAFE_DESTROY(s_shader_modules[i], vkDestroyShaderModule(s_vulkan_context.device, s_shader_modules[i], NULL))
    }
    SAFE_DESTROY(s_shader_modules, free(s_shader_modules));
    for(u32 i = 0; i < c_command_pool_count; i++) {
        SAFE_DESTROY(s_command_pools[i], vkDestroyCommandPool(s_vulkan_context.device, s_command_pools[i], NULL))
    }
    return func_result;
}
