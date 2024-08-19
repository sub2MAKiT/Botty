#include "main.h"
#include "init.h"
#include "MKTUtil.h"
#include "input.h"

int main(void) {

    init();

    DEBUG("Client initialized");

    while (!glfwWindowShouldClose(window)) {

        getInput();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(GLArrayID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GLIndiceID);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DEBUG("Draw loop terminated");

    glfwTerminate();
    return 0;
}