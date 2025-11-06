
out = out/bin
inc = ext/inc
lib = ext/lib

compile_vulkan:
	gcc -c -Wall -O3 -I$(inc) src/vulkan/core.c -o $(out)/vk_core.obj
	gcc -c -Wall -O3 -I$(inc) src/vulkan/vram.c -o $(out)/vk_vram.obj
	gcc -c -Wall -O3 -I$(inc) src/vulkan/resources.c -o $(out)/vk_resources.obj
	gcc -c -Wall -O3 -I$(inc) src/vulkan/render.c -o $(out)/vk_render.obj

compile_main:
	gcc -c -Wall -O3 src/main.c -o $(out)/main.obj

link:
	gcc -o out/bin/main.exe $(out)/main.obj $(out)/vk_core.obj $(out)/vk_vram.obj $(out)/vk_resources.obj $(out)/vk_render.obj -L$(lib) -lglfw3 -lvulkan-1 -lgdi32 -luser32
