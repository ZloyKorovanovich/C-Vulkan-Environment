
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

static u32 s_shader_count = 0;
static VkShaderEXT* s_shaders = NULL;
static u32* s_shader_stages = NULL;

static EventCallback s_event_callback = NULL;
static VulkanContext s_vulkan_context = (VulkanContext){0};
static ExtContext s_ext_context = (ExtContext){0};

static VkDescriptorPool s_descriptor_pool = NULL;
static VkDescriptorSetLayout s_layout_set = NULL;
static VkPipelineLayout s_layout = NULL;

// =================================================== RENDER PASSES
// =================================================================

b32 readShaderFile(const char* path, u32 buffer_size, void* const buffer) {
    FILE* file = fopen(path, "rb");
    ERROR_CATCH(!file) return FALSE;
    fread(buffer, sizeof(u32), buffer_size / sizeof(u32), file);
    fclose(file);
    return TRUE;
}

// ================================================ RENDER INTERFACE
// =================================================================

#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(s_event_callback, code, _fail)

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

    VkDescriptorSet descriptor_set;
    VkDescriptorSetAllocateInfo descriptor_set_info = (VkDescriptorSetAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        .descriptorPool = s_descriptor_pool,
        .descriptorSetCount = 1,
        .pSetLayouts = &s_layout_set
    };
    ERROR_CATCH(vkAllocateDescriptorSets(s_vulkan_context.device, &descriptor_set_info, &descriptor_set) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_SET_ALLOCATE)
    }

    VkSemaphoreCreateInfo semaphore_info = (VkSemaphoreCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
    };
    VkFenceCreateInfo fence_info = (VkFenceCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        .flags = VK_FENCE_CREATE_SIGNALED_BIT
    };
    ERROR_CATCH(vkCreateSemaphore(s_vulkan_context.device, &semaphore_info, NULL, &s_image_available_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateSemaphore(s_vulkan_context.device, &semaphore_info, NULL, &s_image_finished_semaphore) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SEMAPHORE_CREATE)
    };
    ERROR_CATCH(vkCreateFence(s_vulkan_context.device, &fence_info, NULL, &s_in_flight_fence)) {
        _INVOKE_CALLBACK(VK_ERR_FENCE_CREATE)
    }

    SwapchainContext swapchain_context;
    getSwapchainContext(&swapchain_context);

    VkRect2D render_area = (VkRect2D) {
        .extent = swapchain_context.descriptor->extent,
        .offset = (VkOffset2D) {0, 0}
    };

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
        .layerCount = 1,
        .renderArea = render_area
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
        vkWaitForFences(s_vulkan_context.device, 1, &s_in_flight_fence, VK_TRUE, U64_MAX);
        VkResult image_acquire_result = vkAcquireNextImageKHR(s_vulkan_context.device, s_vulkan_context.swapchain, U64_MAX, s_image_available_semaphore, NULL, &image_id);
        if(EXPECT_F(image_acquire_result == VK_ERROR_OUT_OF_DATE_KHR)) {
            recreateSwapchain();
            continue;
        }

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
        
        // DRAWING BEGIN
        VkViewport viewport = (VkViewport) { 
            .height = swapchain_context.descriptor->extent.height,
            .width = swapchain_context.descriptor->extent.width,
            .x = 0,
            .y = 0,
            .minDepth = 0,
            .maxDepth = 1
        };
        vkCmdSetViewportWithCount(command_buffer, 1, &viewport);
        vkCmdSetScissorWithCount(command_buffer, 1, &render_area);
        vkCmdSetRasterizerDiscardEnable(command_buffer, FALSE);
        
        s_ext_context.cmd_set_vertex_input(command_buffer, 0, NULL,0, NULL);
        vkCmdSetPrimitiveTopology(command_buffer, VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
        vkCmdSetPrimitiveRestartEnable(command_buffer, FALSE);

        //only if rasterisation discard disabled
        s_ext_context.cmd_set_rasterization_samples(command_buffer, VK_SAMPLE_COUNT_1_BIT);
        s_ext_context.cmd_set_sample_mask(command_buffer, 0, NULL);
        s_ext_context.cmd_set_alpha_to_coverage_enable(command_buffer, FALSE);
        s_ext_context.cmd_set_polygon_mode(command_buffer, VK_POLYGON_MODE_FILL);
        vkCmdSetLineWidth(command_buffer, 1.0f);
        vkCmdSetCullMode(command_buffer, VK_CULL_MODE_NONE);
        vkCmdSetFrontFace(command_buffer, VK_FRONT_FACE_CLOCKWISE);
        vkCmdSetDepthTestEnable(command_buffer, FALSE);
        vkCmdSetDepthBiasEnable(command_buffer, FALSE);
        vkCmdSetStencilTestEnable(command_buffer, FALSE);

        s_ext_context.cmd_set_color_blend_enable(command_buffer, 0, 1, (VkBool32[]){FALSE});
        s_ext_context.cmd_set_color_write_mask(command_buffer, 0, 1, (u32[]){0});

        // STOPPED HERE AND THATS NOT EVERYTHING
        // check laggy website page https://registry.khronos.org/vulkan/specs/latest/html/vkspec.html#shaders-objects-state
        // May be switch to old good pipelines?

        vkCmdBindDescriptorSets(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, s_layout, 0, 1, &descriptor_set, 0, NULL);
        s_ext_context.cmd_bind_shaders(command_buffer, s_shader_count, s_shader_stages, s_shaders);
        vkCmdDraw(command_buffer, 3, 1, 0, 0);
        // DRAWING END

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
    s_event_callback = event_callback ? event_callback : getCallbackPfn();
    getVulkanContext(&s_vulkan_context);
    getExtContext(&s_ext_context);
    
    // create command pools
    VkCommandPoolCreateInfo command_pool_info = (VkCommandPoolCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
    };
    for(u32 i = 0; i < c_command_pool_count; i++) {
        command_pool_info.queueFamilyIndex = s_vulkan_context.queue_locators[i].family_id;
        command_pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        ERROR_CATCH(vkCreateCommandPool(s_vulkan_context.device, &command_pool_info, NULL, s_command_pools + i) != VK_SUCCESS) {
            _INVOKE_CALLBACK(VK_ERR_COMMAND_POOL_CREATE)
        }
    }

    // create descriptor pool
    VkDescriptorPoolCreateInfo descriptor_pool_info = (VkDescriptorPoolCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .maxSets = 1
    };
    ERROR_CATCH(vkCreateDescriptorPool(s_vulkan_context.device, &descriptor_pool_info, NULL, &s_descriptor_pool) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_POOL_CREATE)
    }

    // create layouts
    VkDescriptorSetLayoutCreateInfo layout_set_info = (VkDescriptorSetLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .pBindings = NULL,
        .bindingCount = 0
    };
    ERROR_CATCH(vkCreateDescriptorSetLayout(s_vulkan_context.device, &layout_set_info, NULL, &s_layout_set) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_SET_LAYOUT_CREATE)
    }
    VkPipelineLayoutCreateInfo layout_info = (VkPipelineLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .setLayoutCount = 1,
        .pSetLayouts = &s_layout_set
    };
    ERROR_CATCH(vkCreatePipelineLayout(s_vulkan_context.device, &layout_info, NULL, &s_layout) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_PIPELINE_LAYOUT_CREATE)
    }

    // read shaders and create shader objects
    void* shader_compilation_memory = malloc(sizeof(VkShaderCreateInfoEXT) * SHADER_COUNT + SHADER_BUFFER_SIZE);
    ERROR_CATCH(!shader_compilation_memory) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_BUFFER_ALLOCATE);
    }
    void* shader_buffer = (char*)shader_compilation_memory + sizeof(VkShaderCreateInfoEXT) * SHADER_COUNT;
    VkShaderCreateInfoEXT* shader_create_infos = shader_compilation_memory;

    ERROR_CATCH(!readShaderFile(shader_path, SHADER_BUFFER_SIZE, shader_buffer)) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_BUFFER_LOAD)
    }

    s_shader_count = SHADER_COUNT;
    s_shaders = malloc(sizeof(VkShaderEXT) * SHADER_COUNT + sizeof(u32) * SHADER_COUNT);
    s_shader_stages = (u32*)((char*)s_shaders + sizeof(VkShaderEXT) * SHADER_COUNT); //@(Mitro): A little bit tricky part here
    ERROR_CATCH(!shader_compilation_memory) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_OBJECT_ARRAY_ALLOCATE);
    }
    
    for(u32 i = 0; i < SHADER_COUNT; i++) {
        shader_create_infos[i] = (VkShaderCreateInfoEXT) {
            .sType = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT,
            .codeType = VK_SHADER_CODE_TYPE_SPIRV_EXT,
            .flags = 0,
            .stage = c_shader_infos[i].stage,
            .nextStage = c_shader_infos[i].next_stage,
            .pName = c_shader_infos[i].entry,
            .pCode = (char*)shader_buffer + c_shader_infos[i].code_offset,
            .codeSize = c_shader_infos[i].code_size
        };
        s_shader_stages[i] = c_shader_infos[i].stage;
    }
    ERROR_CATCH(s_ext_context.create_shaders(s_vulkan_context.device, SHADER_COUNT, shader_create_infos, NULL, s_shaders) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_OBJECT_CREATE)
    }
    free(shader_compilation_memory);

    ERROR_CATCH(!renderLoop()) {
        _INVOKE_CALLBACK(VK_ERR_RENDER_LOOP_FAIL)
    }

//_sucess:
    for(u32 i = 0; i < s_shader_count; i++) {
        SAFE_DESTROY(s_shaders[i], s_ext_context.destroy_shader(s_vulkan_context.device, s_shaders[i], NULL))
    }
    SAFE_DESTROY(s_shaders, free(s_shaders));
    SAFE_DESTROY(s_layout_set, vkDestroyDescriptorSetLayout(s_vulkan_context.device, s_layout_set, NULL))
    SAFE_DESTROY(s_descriptor_pool, vkDestroyDescriptorPool(s_vulkan_context.device, s_descriptor_pool, NULL))
    for(u32 i = 0; i < c_command_pool_count; i++) {
        SAFE_DESTROY(s_command_pools[i], vkDestroyCommandPool(s_vulkan_context.device, s_command_pools[i], NULL))
    }
    return TRUE;
_fail:
    for(u32 i = 0; i < s_shader_count; i++) {
        SAFE_DESTROY(s_shaders[i], s_ext_context.destroy_shader(s_vulkan_context.device, s_shaders[i], NULL))
    }
    SAFE_DESTROY(s_shaders, free(s_shaders));
    SAFE_DESTROY(s_layout_set, vkDestroyDescriptorSetLayout(s_vulkan_context.device, s_layout_set, NULL))
    SAFE_DESTROY(s_descriptor_pool, vkDestroyDescriptorPool(s_vulkan_context.device, s_descriptor_pool, NULL))
    for(u32 i = 0; i < c_command_pool_count; i++) {
        SAFE_DESTROY(s_command_pools[i], vkDestroyCommandPool(s_vulkan_context.device, s_command_pools[i], NULL))
    }
    return FALSE;
}
