
cbuffer Properties : register(b0){

    float4x4 ING_WorldMatrix;
    float4x4 ING_ViewMatrix;
    float4x4 ING_ProjectionMatrix;
    
    float4x4 ING_WorldViewProjMatrix;

    float4 color;
    float4 color2;

};

struct I2V {

    float3 PosL: POSITION;

};

struct V2P {

    float4 PosH: SV_POSITION;
    float3 PosW: POSITION;

};

V2P main(I2V vin){

    V2P vout;

    //float4 posW = mul(float4(vin.PosL, 1.0f), ING_WorldMatrix);

    //vout.PosH = mul(mul(posW, ING_ViewMatrix), ING_ProjectionMatrix);

    //vout.PosH = mul(float4(vin.PosL, 1.0f), ING_ProjectionMatrix);

   // vout.PosW = posW.xyz;

    vout.PosW = float3(1,1,1);

    vout.PosH = float4(vin.PosL, 1.0f);

    return vout;
}