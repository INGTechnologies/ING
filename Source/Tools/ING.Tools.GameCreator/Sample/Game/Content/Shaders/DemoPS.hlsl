
cbuffer Properties : register(b0){

    float4x4 ING_WorldMatrix;
    float4x4 ING_ViewMatrix;
    float4x4 ING_ProjectionMatrix;
    
    float4x4 ING_WorldViewProjMatrix;

    float4 color;
    float4 color2;

};

struct V2P {

    float4 PosH: SV_POSITION;
    float3 PosW: POSITION;

};

float4 main(V2P vin): SV_TARGET {



    return color;
}