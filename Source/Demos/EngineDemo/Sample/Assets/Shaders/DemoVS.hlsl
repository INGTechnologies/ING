
struct I2V {

    float4 PosH: POSITION;

};

struct V2P {

    float4 PosH: SV_POSITION;

};

V2P main(I2V vin){

    V2P vout;

    vout.PosH = vin.PosH;

    return vout;
}