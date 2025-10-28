
[[vk::binding(1, 0)]] RWStructuredBuffer<float2> position_buffer;

[numthreads(64, 1, 1)]
void computeFunc(uint3 global_id : SV_DISPATCHTHREADID) {
    position_buffer[global_id.x] = float2((float(global_id.x) / 32.0) - 1.0, 0); 
}
