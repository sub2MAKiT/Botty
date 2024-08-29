#include "init.h"
#include "main.h"
#include "MKTUtil.h"
#include "input.h"

input MKT_input;

long long int MKT_selectedFontObject = 0;

void getInput(){
    for(int i = 0; i < 34; i++)
        MKT_input.key[i] = 0;
    for(int i = 0; i < 4; i++)
        MKT_input.arrow[i] = 0;

    
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);

    for(int i = 0; i < 10; i++)
        if(glfwGetKey(window, GLFW_KEY_0+i) == GLFW_PRESS)
            MKT_input.key[i] = 1;

    for(int i = 0; i < 24; i++)
        if(glfwGetKey(window, GLFW_KEY_A+i) == GLFW_PRESS)
            MKT_input.key[i+10] = 1;

    for(int i = 0; i < 4; i++)
        if(glfwGetKey(window, GLFW_KEY_RIGHT+i) == GLFW_PRESS)
            MKT_input.arrow[i] = 1;


    MKT_input.space = MKT_input.space>0&glfwGetKey(window, GLFW_KEY_SPACE)?2:glfwGetKey(window, GLFW_KEY_SPACE);


    // keyboard





}// 

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_RELEASE && key != GLFW_KEY_LEFT_SHIFT)
        buttonPressed = 0;

    if(buttonPressed)
        return;
    buttonPressed = 1;

    MKT_FontObject[MKT_selectedFontObject].sizeOfText++;

    if(!(MKT_FontObject[MKT_selectedFontObject].sizeOfText%100))
        MKT_FontObject[MKT_selectedFontObject].text = realloc(MKT_FontObject[MKT_selectedFontObject].text,MKT_FontObject[MKT_selectedFontObject].sizeOfText);

    MKT_FontObject[MKT_selectedFontObject].text[MKT_FontObject[MKT_selectedFontObject].sizeOfText-1];

    char * characterToChange = &MKT_FontObject[MKT_selectedFontObject].text[MKT_FontObject[MKT_selectedFontObject].sizeOfText-1];
    
    if (key == GLFW_KEY_1 && (mods&GLFW_MOD_SHIFT)) {*characterToChange = 0;return;}
    if (key == GLFW_KEY_APOSTROPHE && (mods&GLFW_MOD_SHIFT)) {*characterToChange = 1;return;}
    
    if (key == GLFW_KEY_A && mods&GLFW_MOD_SHIFT) {*characterToChange = 32;return;}
    if (key == GLFW_KEY_B && mods&GLFW_MOD_SHIFT) {*characterToChange = 33;return;}
    if (key == GLFW_KEY_C && mods&GLFW_MOD_SHIFT) {*characterToChange = 34;return;}
    if (key == GLFW_KEY_D && mods&GLFW_MOD_SHIFT) {*characterToChange = 35;return;}
    if (key == GLFW_KEY_E && mods&GLFW_MOD_SHIFT) {*characterToChange = 36;return;}
    if (key == GLFW_KEY_F && mods&GLFW_MOD_SHIFT) {*characterToChange = 37;return;}
    if (key == GLFW_KEY_G && mods&GLFW_MOD_SHIFT) {*characterToChange = 38;return;}
    if (key == GLFW_KEY_H && mods&GLFW_MOD_SHIFT) {*characterToChange = 39;return;}
    if (key == GLFW_KEY_I && mods&GLFW_MOD_SHIFT) {*characterToChange = 40;return;}
    if (key == GLFW_KEY_J && mods&GLFW_MOD_SHIFT) {*characterToChange = 41;return;}
    if (key == GLFW_KEY_K && mods&GLFW_MOD_SHIFT) {*characterToChange = 42;return;}
    if (key == GLFW_KEY_L && mods&GLFW_MOD_SHIFT) {*characterToChange = 43;return;}
    if (key == GLFW_KEY_M && mods&GLFW_MOD_SHIFT) {*characterToChange = 44;return;}
    if (key == GLFW_KEY_N && mods&GLFW_MOD_SHIFT) {*characterToChange = 45;return;}
    if (key == GLFW_KEY_O && mods&GLFW_MOD_SHIFT) {*characterToChange = 46;return;}
    if (key == GLFW_KEY_P && mods&GLFW_MOD_SHIFT) {*characterToChange = 47;return;}
    if (key == GLFW_KEY_Q && mods&GLFW_MOD_SHIFT) {*characterToChange = 48;return;}
    if (key == GLFW_KEY_R && mods&GLFW_MOD_SHIFT) {*characterToChange = 49;return;}
    if (key == GLFW_KEY_S && mods&GLFW_MOD_SHIFT) {*characterToChange = 50;return;}
    if (key == GLFW_KEY_T && mods&GLFW_MOD_SHIFT) {*characterToChange = 51;return;}
    if (key == GLFW_KEY_U && mods&GLFW_MOD_SHIFT) {*characterToChange = 52;return;}
    if (key == GLFW_KEY_V && mods&GLFW_MOD_SHIFT) {*characterToChange = 53;return;}
    if (key == GLFW_KEY_W && mods&GLFW_MOD_SHIFT) {*characterToChange = 54;return;}
    if (key == GLFW_KEY_X && mods&GLFW_MOD_SHIFT) {*characterToChange = 55;return;}
    if (key == GLFW_KEY_Y && mods&GLFW_MOD_SHIFT) {*characterToChange = 56;return;}
    if (key == GLFW_KEY_Z && mods&GLFW_MOD_SHIFT) {*characterToChange = 57;return;}

    if (key == GLFW_KEY_APOSTROPHE) *characterToChange = 6;
    if (key == GLFW_KEY_1) *characterToChange = 16;
    if (key == GLFW_KEY_2) *characterToChange = 17;
    if (key == GLFW_KEY_3) *characterToChange = 18;
    if (key == GLFW_KEY_4) *characterToChange = 19;
    if (key == GLFW_KEY_5) *characterToChange = 20;
    if (key == GLFW_KEY_6) *characterToChange = 21;
    if (key == GLFW_KEY_7) *characterToChange = 22;
    if (key == GLFW_KEY_8) *characterToChange = 23;
    if (key == GLFW_KEY_9) *characterToChange = 24;

    if (key == GLFW_KEY_A)*characterToChange = 32+32;
    if (key == GLFW_KEY_B)*characterToChange = 33+32;
    if (key == GLFW_KEY_C)*characterToChange = 34+32;
    if (key == GLFW_KEY_D)*characterToChange = 35+32;
    if (key == GLFW_KEY_E)*characterToChange = 36+32;
    if (key == GLFW_KEY_F)*characterToChange = 37+32;
    if (key == GLFW_KEY_G)*characterToChange = 38+32;
    if (key == GLFW_KEY_H)*characterToChange = 39+32;
    if (key == GLFW_KEY_I)*characterToChange = 40+32;
    if (key == GLFW_KEY_J)*characterToChange = 41+32;
    if (key == GLFW_KEY_K)*characterToChange = 42+32;
    if (key == GLFW_KEY_L)*characterToChange = 43+32;
    if (key == GLFW_KEY_M)*characterToChange = 44+32;
    if (key == GLFW_KEY_N)*characterToChange = 45+32;
    if (key == GLFW_KEY_O)*characterToChange = 46+32;
    if (key == GLFW_KEY_P)*characterToChange = 47+32;
    if (key == GLFW_KEY_Q)*characterToChange = 48+32;
    if (key == GLFW_KEY_R)*characterToChange = 49+32;
    if (key == GLFW_KEY_S)*characterToChange = 50+32;
    if (key == GLFW_KEY_T)*characterToChange = 51+32;
    if (key == GLFW_KEY_U)*characterToChange = 52+32;
    if (key == GLFW_KEY_V)*characterToChange = 53+32;
    if (key == GLFW_KEY_W)*characterToChange = 54+32;
    if (key == GLFW_KEY_X)*characterToChange = 55+32;
    if (key == GLFW_KEY_Y)*characterToChange = 56+32;
    if (key == GLFW_KEY_Z)*characterToChange = 57+32;

}