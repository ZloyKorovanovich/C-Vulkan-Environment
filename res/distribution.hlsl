
[[vk::binding(1, 0)]] RWStructuredBuffer<float4> position_buffer;

[numthreads(64, 1, 1)]
void computeFunc(uint3 global_id : SV_DISPATCHTHREADID) {
    position_buffer[global_id.x] = float4((float(global_id.x) / 32.0) - 1.0, (global_id.x % 4) * 0.25, global_id.x / 64.0, 0.0); 
}
