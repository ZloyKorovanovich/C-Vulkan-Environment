static float3 positions[3] = {
    float3( 0.5, 0.5, 0.0),
    float3(-0.5, 0.5, 0.0),
    float3( 0.0,-0.5, 0.0)
};

static float3 colors[3] = {
    float3(1.0, 0.0, 0.0),
    float3(0.0, 1.0, 0.0),
    float3(0.0, 0.0, 1.0)
};

struct Interpolators {
    float4 position_cs : SV_POSITION;
    float4 color : COLOR;
};

cbuffer per_object {
    uniform float4 c_screen_size;
    uniform float4 c_position;
};

Interpolators vertexFunc(uint vertex_id : SV_VERTEXID) {
    Interpolators output = (Interpolators)0;
    output.position_cs = float4(positions[vertex_id], 1);
    output.color = float4(colors[vertex_id], 1);
    return output;
}

float4 fragmentFunc(Interpolators input) : SV_TARGET {
    return input.color;
}
