#include "init.h"
#include "main.h"
#include "MKTUtil.h"
#include "input.h"

input MKT_input;

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
}// 