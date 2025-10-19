
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

const u32 c_shader_count = SHADER_COUNT;
static VkShaderEXT s_shaders[SHADER_COUNT] = {0};

// =================================================== RENDER PASSES
// =================================================================

b32 readShaderFile(const char* path, u32 buffer_size, void* const buffer) {
    FILE* file = fopen(path, "rb");
    if(!file) return FALSE;
    fread(buffer, sizeof(u32), buffer_size / sizeof(u32), file);
    fclose(file);
    return TRUE;
}

// ================================================ RENDER INTERFACE
// =================================================================


b32 renderLoop(VulkanContext* vk_context, ExtContext* ext_context) {
    // render loop
    while(!glfwWindowShouldClose(vk_context->window)) {
        glfwPollEvents();
    }
    return TRUE;
}

#define _INVOKE_CALLBACK(code) INVOKE_CALLBACK(event_callback, code)

b32 renderRun(UpdateCallback update_callback, EventCallback event_callback, const char* shader_path) {
    event_callback = event_callback ? event_callback : getCallbackPfn();
    VulkanContext vulkan_context;
    ExtContext ext_context;
    getVulkanContext(&vulkan_context);
    getExtContext(&ext_context);
    
    // create command pools
    u32 command_pool_count = DEVICE_QUEUE_COUNT;
    VkCommandPool* command_pools = alloca(sizeof(VkCommandPool) * DEVICE_QUEUE_COUNT);
    VkCommandPoolCreateInfo pool_info = (VkCommandPoolCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO 
    };
    for(u32 i = 0; i < DEVICE_QUEUE_COUNT; i++) {
        pool_info.queueFamilyIndex = vulkan_context.queue_locators[i].family_id;
        if(vkCreateCommandPool(vulkan_context.device, &pool_info, NULL, command_pools + i) != VK_SUCCESS) {
            _INVOKE_CALLBACK(VK_ERR_COMMAND_POOL_CREATE)
        }
    }

    // create layouts
    VkDescriptorSetLayout set_layout;
    VkDescriptorSetLayoutCreateInfo layout_set_info = (VkDescriptorSetLayoutCreateInfo) {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .pBindings = NULL,
        .bindingCount = 0
    };
    if(vkCreateDescriptorSetLayout(vulkan_context.device, &layout_set_info, NULL, &set_layout) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_DESCRIPTOR_SET_LAYOUT_CREATE)
    }

    // read shaders and create shader objects
    void* shader_compilation_memory = malloc(sizeof(VkShaderCreateInfoEXT) * SHADER_COUNT + SHADER_BUFFER_SIZE);
    void* shader_buffer = (char*)shader_compilation_memory + sizeof(VkShaderCreateInfoEXT) * SHADER_COUNT;
    VkShaderCreateInfoEXT* shader_create_infos = shader_compilation_memory;

    if(!readShaderFile(shader_path, SHADER_BUFFER_SIZE, shader_buffer)) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_BUFFER_LOAD)
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
    }
    if(ext_context.create_shaders(vulkan_context.device, SHADER_COUNT, shader_create_infos, NULL, s_shaders) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_SHADER_OBJECT_CREATE)
    }
    free(shader_compilation_memory);

    VkCommandBuffer command_buffer;
    VkCommandBufferAllocateInfo cmbuffers_info = (VkCommandBufferAllocateInfo) {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandBufferCount = 1,
        .commandPool = command_pools[0],
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY
    };
    if(vkAllocateCommandBuffers(vulkan_context.device, &cmbuffers_info, &command_buffer) != VK_SUCCESS) {
        _INVOKE_CALLBACK(VK_ERR_ALLOCATE_COMMAND_BUFFER)
    }
    if(!renderLoop(&vulkan_context, &ext_context)) {
        _INVOKE_CALLBACK(VK_ERR_RENDER_LOOP_FAIL)
    }

//_sucess:
    for(u32 i = 0; i < c_shader_count; i++) {
        SAFE_DESTROY(s_shaders[i], ext_context.destroy_shader(vulkan_context.device, s_shaders[i], NULL))
    }
    SAFE_DESTROY(set_layout, vkDestroyDescriptorSetLayout(vulkan_context.device, set_layout, NULL))
    for(u32 i = 0; i < command_pool_count; i++) {
        SAFE_DESTROY(command_pools[i], vkDestroyCommandPool(vulkan_context.device, command_pools[i], NULL))
    }
    return TRUE;
_fail:
    for(u32 i = 0; i < c_shader_count; i++) {
        SAFE_DESTROY(s_shaders[i], ext_context.destroy_shader(vulkan_context.device, s_shaders[i], NULL))
    }
    SAFE_DESTROY(set_layout, vkDestroyDescriptorSetLayout(vulkan_context.device, set_layout, NULL))
    for(u32 i = 0; i < command_pool_count; i++) {
        SAFE_DESTROY(command_pools[i], vkDestroyCommandPool(vulkan_context.device, command_pools[i], NULL))
    }
    return FALSE;
}
