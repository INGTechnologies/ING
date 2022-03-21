
struct I2V {

    float4 PosH: POSITION;

};

struct V2P {

    float4 PosH: SV_POSITION;

};

float4 main(V2P vin): SV_TARGET {



    return float4(1,1,1,1);
}