#include "main.h"
#include "init.h"
#include "MKTUtil.h"

int main(void) {

    init();

    DEBUG("Client initialized");

    while (!glfwWindowShouldClose(window)) {

        // glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DEBUG("Draw loop terminated");

    glfwTerminate();
    return 0;
}