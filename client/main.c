#include "main.h"
#include "init.h"
#include "MKTUtil.h"
#include "input.h"
#include "cleanup.h"
#include "transform.h"

unsigned int temp = 0;

char buttonPressed = 0;

selectedObject MKT_selectedTextObject;

int main(void) {




    init();

    DEBUG("Client initialized");

    char tempImage = 0;

    while (!glfwWindowShouldClose(window)) {

        MKT_selectedTextObject.index = 0;
        MKT_selectedTextObject.type = 0;
        MKT_selectedTextObject.text = MKT_textObject;
        // printf("%f\n",glfwGetTime());

        temp = glfwGetTime();

        getInput();

        glClear(GL_COLOR_BUFFER_BIT);

        //image

        // glUseProgram(GL_shaderProgram[SHADER_IMAGE]);
        // glBindVertexArray(GL_ArrayID[SHADER_IMAGE]);
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_IndiceID[SHADER_IMAGE]);
        // if(MKT_input.space==1)
        //     tempImage = 1-tempImage;
        
        // glBindTexture(GL_TEXTURE_2D, MKT_VisualObject[tempImage].texture);
        // MKT_VisualObject[0].colour[0] += MKT_input.key[1];
        // MKT_VisualObject[0].colour[0] -= MKT_input.key[2];

        // MKT_VisualObject[0].transform[12] += MKT_input.arrow[0]?0.1:0.0;
        // MKT_VisualObject[0].transform[12] -= MKT_input.arrow[1]?0.1:0.0;

        // MKT_VisualObject[0].transform[13] -= MKT_input.arrow[2]?0.1:0.0;
        // MKT_VisualObject[0].transform[13] += MKT_input.arrow[3]?0.1:0.0;

        // unsigned int colorLoc = glGetUniformLocation(GL_shaderProgram[SHADER_IMAGE], "modColor");
        // unsigned int transformLoc = glGetUniformLocation(GL_shaderProgram[SHADER_IMAGE], "transform");
        // glUniform4fv(colorLoc, 1, MKT_VisualObject[0].colour);
        // glUniformMatrix4fv(transformLoc, 1, GL_FALSE, MKT_VisualObject[0].transform);


        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // Fonts

        

        for(int i = 0; i < MKT_textObjectSize; i++) {
            unsigned int newline = 0;
            unsigned int offset = 0;
            for(int character = 0; character < MKT_textObject[i].sizeOfText; character++)
            {
                offset++;
                glUseProgram(GL_shaderProgram[SHADER_FONTS]);
                glBindVertexArray(GL_ArrayID[SHADER_FONTS]);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_IndiceID[SHADER_FONTS]);
                
                glBindTexture(GL_TEXTURE_2D, MKT_FontObject[i].texture);


                unsigned int colorLocFont = glGetUniformLocation(GL_shaderProgram[SHADER_FONTS], "modColor");
                unsigned int transformLocFont = glGetUniformLocation(GL_shaderProgram[SHADER_FONTS], "transform");
                unsigned int letterLocFont = glGetUniformLocation(GL_shaderProgram[SHADER_FONTS], "letter");
                unsigned int offsetLocFont = glGetUniformLocation(GL_shaderProgram[SHADER_FONTS], "offset");
                unsigned int newLineLocFont = glGetUniformLocation(GL_shaderProgram[SHADER_FONTS], "newline");
                glUniform4fv(colorLocFont, 1, MKT_textObject[i].colour);
                glUniformMatrix4fv(transformLocFont, 1, GL_FALSE, MKT_textObject[i].transform);
                if(MKT_textObject[i].text[character] == 100) {
                    glUniform1i(letterLocFont, -1);
                    newline++;
                    offset = 0;
                } else
                    glUniform1i(letterLocFont, MKT_textObject[i].text[character]);

                glUniform1i(offsetLocFont, offset);
                glUniform1i(newLineLocFont, newline);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            }
        }
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DEBUG("Draw loop terminated");

    glfwTerminate();
    DEBUG("GLFW terminated");

    Cleanup();
    DEBUG("Cleaned up");
    return 0;
}