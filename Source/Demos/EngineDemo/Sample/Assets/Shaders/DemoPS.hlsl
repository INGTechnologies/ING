
cbuffer Properties : register(b0){

    float4 color;
    float4 color2;

};

struct I2V {

    float4 PosH: POSITION;

};

struct V2P {

    float4 PosH: SV_POSITION;

};

float4 main(V2P vin): SV_TARGET {



    return color;
}