
static float3 triangle_table[3] = {
    float3( 0.0, 1.0, 0.0),
    float3(-1.0, 0.0, 0.0),
    float3( 1.0, 0.0, 0.0)
};

float4 vertexFunc(uint vertex_id : SV_VERTEXID) : SV_POSITION {
    return float4(triangle_table[vertex_id], 1);
}

float4 fragmentFunc(float4 position_cs : SV_POSITION) : SV_TARGET {
    return float4(1, 1, 1, 1);
}
