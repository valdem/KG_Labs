#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include "stb_image.h"

float x = 0.0;
float rotate_x = -25.0;
float rotate_y = -60.0;
int alpha = 1;

void keyCallback (GLFWwindow * window, int key, int scancode, int action, int mode) {
    
    switch (key) {
        case GLFW_KEY_UP:
            rotate_x += 5.0;
            break;
        case GLFW_KEY_DOWN:
            rotate_x -= 5.0;
            break;
        case GLFW_KEY_RIGHT:
            rotate_y -= 5.0;
            break;
        case GLFW_KEY_LEFT:
            rotate_y += 5.0;
            break;
        case GLFW_KEY_D:
            if (x < 0.09) {
                x += 0.03;
            }
            break;
        case GLFW_KEY_A:
            if (x > 0.0) {
                x -= 0.03;
            }
            break;
        case GLFW_KEY_SPACE:
            if (action == GLFW_PRESS) {
                if (alpha == 1) {
                    alpha--;
                }
                else {
                    alpha++;
                }
            }
            std::cout<<alpha<<std::endl;
            break;
    }
    
}

void DrawCube(GLfloat size, unsigned int texture)
{
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glBegin(GL_QUADS); // left
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-x-size, -size, -size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-x-size,  size, -size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-x-size,  size,  size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-x-size, -size,  size);
    
    glEnd();
    
    glBegin(GL_QUADS); // right
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x+size, -size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, -size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x+size, size, -size);
    
    glEnd();

    glBegin(GL_QUADS); // bottom
    
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -x-size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -x-size, size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -x-size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -x-size, -size);
    
    glEnd();
    
    glBegin(GL_QUADS); // top
    
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, x+size, -size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, x+size, size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, x+size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, x+size, -size);
    
    glEnd();

    glBegin(GL_QUADS); // back
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, x+size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, x+size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, x+size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, x+size);
    
    glEnd();
    
    glBegin(GL_QUADS); // front
    
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -x-size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, -x-size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, -x-size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, -x-size);
    
    glEnd();
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 800, "Lab5", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    
    unsigned int texture;
    int tex_width, tex_height, nrChannels;
    
    glGenTextures(1, &texture);
    
    unsigned char* texture1 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab5/texture7.png", &tex_width, &tex_height, &nrChannels, 0);
    
    
    glBindTexture(GL_TEXTURE_2D, texture);
    if (texture1) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_width, tex_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture1);
    }
    else
    {
        std::cout << "Failed to load texture 1" << std::endl;
    }
    stbi_image_free(texture1);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_TEXTURE_2D);
        
        glfwSetKeyCallback(window, keyCallback);
        
        glEnable(GL_BLEND);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        
        glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);
        
        DrawCube(0.3, texture);
        
        glDepthMask(GL_TRUE);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
