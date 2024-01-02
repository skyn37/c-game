//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// rTexpacker v3.0 Atlas Descriptor Code exporter v2.0                          //
//                                                                              //
// more info and bugs-report:  github.com/raylibtech/rtools                     //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2023 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#define ATLAS_ATLAS_IMAGE_PATH      "atlas.png"
#define ATLAS_ATLAS_SPRITE_COUNT    16

// Atlas sprite properties
typedef struct rtpAtlasSprite {
    const char *nameId;
    int originX, originY;
    int positionX, positionY;
    int sourceWidth, sourceHeight;
    int padding;
    bool trimmed;
    int trimRecX, trimRecY, trimRecWidth, trimRecHeight;
} rtpAtlasSprite;

// Atlas sprites array
static rtpAtlasSprite rtpDescAtlas[16] = {
    { "warrior_armed_idle_E_0", 0, 0, 0, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NW_135", 0, 0, 256, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SSW_247", 0, 0, 512, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_N_90", 0, 0, 768, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NWW_157", 0, 0, 0, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SW_225", 0, 0, 256, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NE_45", 0, 0, 512, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_S_270", 0, 0, 768, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SWW_202", 0, 0, 0, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NEE_22", 0, 0, 256, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SE_315", 0, 0, 512, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_W_180", 0, 0, 768, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NNE_67", 0, 0, 0, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SEE_337", 0, 0, 256, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_NNW_112", 0, 0, 512, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_idle_SSE_292", 0, 0, 768, 768, 256, 256, 0, false, 0, 0, 256, 256 },
};
