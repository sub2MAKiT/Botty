#include "init.h"
#include "main.h"
#include "MKTUtil.h"

void getInput(){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}