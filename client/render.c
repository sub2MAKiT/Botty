#include "render.h"



extern FT_Library ft;


int MKTC_TransformImage() {
    FT_Face face;
    FT_New_Face(ft, "./testSource/_decterm.ttf", 0, &face);

    
    FT_Set_Pixel_Sizes(face, 0, 48);
    return 0;
}
