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

#define ATLAS_ATLAS_IMAGE_PATH      "char_move_0.png"
#define ATLAS_ATLAS_SPRITE_COUNT    64

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
static rtpAtlasSprite rtpDescAtlas[64] = {
    { "warrior_armed_walk_E_0", 0, 0, 0, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 256, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 512, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 768, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 1024, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 1280, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 1536, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_E_0", 0, 0, 1792, 0, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 0, 256, 256, 256, 0, false, 0, 0, 256, 255 },
    { "warrior_armed_walk_N_90", 0, 0, 256, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 512, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 768, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 1024, 256, 256, 256, 0, false, 0, 0, 256, 255 },
    { "warrior_armed_walk_N_90", 0, 0, 1280, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 1536, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_N_90", 0, 0, 1792, 256, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 0, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 256, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 512, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 768, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 1024, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 1280, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 1536, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NE_45", 0, 0, 1792, 512, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 0, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 256, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 512, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 768, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 1024, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 1280, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 1536, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NEE_22", 0, 0, 1792, 768, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 0, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 256, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 512, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 768, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 1024, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 1280, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 1536, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNE_67", 0, 0, 1792, 1024, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 0, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 256, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 512, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 768, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 1024, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 1280, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 1536, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NNW_112", 0, 0, 1792, 1280, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 0, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 256, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 512, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 768, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 1024, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 1280, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 1536, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NW_135", 0, 0, 1792, 1536, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 0, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 256, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 512, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 768, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 1024, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 1280, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 1536, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
    { "warrior_armed_walk_NWW_157", 0, 0, 1792, 1792, 256, 256, 0, false, 0, 0, 256, 256 },
};
