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
float angle = 0.0;
float rotate_x = -25.0;
float rotate_y = -60.0;

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
            angle += 0.1;
            break;
    }
    
}

void DrawCube(GLfloat size, unsigned int texture[6])
{
    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS); // left
    
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-x-size, -size, -size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-x-size,  size, -size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-x-size,  size,  size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-x-size, -size,  size);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS); // right
    
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x+size, -size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x+size, -size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x+size, size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x+size, size, -size);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS); // bottom
    
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -x-size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -x-size, size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -x-size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -x-size, -size);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS); // top
    
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, x+size, -size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, x+size, size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, x+size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, x+size, -size);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS); // back
    
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -x-size);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, -x-size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, -x-size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, -x-size);
    
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS); // front
    
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, x+size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, x+size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, x+size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, x+size);
    
    glEnd();
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 800, "Lab4", NULL, NULL);
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
    
    unsigned int texture[6];
    int tex_width[6], tex_height[6], nrChannels[6];
    
    glGenTextures(6, &texture[0]);
    
    unsigned char* texture1 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture1.jpg", &tex_width[0], &tex_height[0], &nrChannels[0], 0);
    unsigned char* texture2 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture2.jpg", &tex_width[1], &tex_height[1], &nrChannels[1], 0);
    unsigned char* texture3 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture3.jpg", &tex_width[2], &tex_height[2], &nrChannels[2], 0);
    unsigned char* texture4 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture4.jpg", &tex_width[3], &tex_height[3], &nrChannels[3], 0);
    unsigned char* texture5 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture5.jpg", &tex_width[4], &tex_height[4], &nrChannels[4], 0);
    unsigned char* texture6 = stbi_load("/Users/vadim/Desktop/KG_Labs/Lab4/texture6.jpg", &tex_width[5], &tex_height[5], &nrChannels[5], 0);
    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    if (texture1) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[0], tex_height[0], 0, GL_RGB, GL_UNSIGNED_BYTE, texture1);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture1);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    if (texture2) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[1], tex_height[1], 0, GL_RGB, GL_UNSIGNED_BYTE, texture2);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture2);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    if (texture3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[2], tex_height[2], 0, GL_RGB, GL_UNSIGNED_BYTE, texture3);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture3);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    if (texture4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[3], tex_height[3], 0, GL_RGB, GL_UNSIGNED_BYTE, texture4);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture4);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    if (texture5) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[4], tex_height[4], 0, GL_RGB, GL_UNSIGNED_BYTE, texture5);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture5);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    if (texture6) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width[5], tex_height[5], 0, GL_RGB, GL_UNSIGNED_BYTE, texture6);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(texture6);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        
        glfwSetKeyCallback(window, keyCallback);
        
        glEnable(GL_NORMALIZE);
        
        float light_x = 0.9*cos(angle);
        float light_z = 0.9*sin(angle);
        GLfloat light_position[] = {light_x, 0, light_z, 0 };
        GLfloat light_diffuse[] = {1.0, 1.0, 1.0};
        
        glEnable(GL_LIGHT0);
        
        glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        
        GLfloat color_sphere[] = {1.0, 1.0, 1.0};
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_sphere);
        
        GLUquadricObj* sphere;
        sphere = gluNewQuadric();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.9*cos(angle), 0.0, 0.9*sin(angle));
        gluSphere(sphere, 0.07, 20, 20);
        glTranslatef(-0.9*cos(angle), 0.0, -0.9*sin(angle));
        
        glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);
        
        DrawCube(0.3, texture);
        
        glDisable(GL_LIGHT0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
