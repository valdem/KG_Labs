#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

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
    }
    
}

void DrawOctahedron()
{
     
    glBegin(GL_TRIANGLES); //white
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.125, 0.375, 0);
    glVertex3f(0, 0.375, 0.125);
    glVertex3f(0, 0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.13, 0.37, 0);
    glVertex3f(0, 0.37, 0.13);
    glVertex3f(0, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.255, 0.245, 0);
    glVertex3f(0, 0.245, 0.255);
    glVertex3f(0, 0.125, 0.375);
    glVertex3f(-0.375, 0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.38, 0.12, 0);
    glVertex3f(0, 0.12, 0.38);
    glVertex3f(0, 0, 0.5);
    glVertex3f(-0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //pink top
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.125, 0.375, 0);
    glVertex3f(0, 0.375, 0.125);
    glVertex3f(0, 0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.13, 0.37, 0);
    glVertex3f(0, 0.37, 0.13);
    glVertex3f(0, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.255, 0.245, 0);
    glVertex3f(0, 0.245, 0.255);
    glVertex3f(0, 0.125, 0.375);
    glVertex3f(0.375, 0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.38, 0.12, 0);
    glVertex3f(0, 0.12, 0.38);
    glVertex3f(0, 0, 0.5);
    glVertex3f(0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //red
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.125, 0.375, 0);
    glVertex3f(0, 0.375, -0.125);
    glVertex3f(0, 0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.13, 0.37, 0);
    glVertex3f(0, 0.37, -0.13);
    glVertex3f(0, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.255, 0.245, 0);
    glVertex3f(0, 0.245, -0.255);
    glVertex3f(0, 0.125, -0.375);
    glVertex3f(-0.375, 0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.38, 0.12, 0);
    glVertex3f(0, 0.12, -0.38);
    glVertex3f(0, 0, -0.5);
    glVertex3f(-0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //yellow
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.125, 0.375, 0);
    glVertex3f(0, 0.375, -0.125);
    glVertex3f(0, 0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.13, 0.37, 0);
    glVertex3f(0, 0.37, -0.13);
    glVertex3f(0, 0.25, -0.25);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.255, 0.245, 0);
    glVertex3f(0, 0.245, -0.255);
    glVertex3f(0, 0.125, -0.375);
    glVertex3f(0.375, 0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.38, 0.12, 0);
    glVertex3f(0, 0.12, -0.38);
    glVertex3f(0, 0, -0.5);
    glVertex3f(0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //green
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.125, -0.375, 0);
    glVertex3f(0, -0.375, 0.125);
    glVertex3f(0, -0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.13, -0.37, 0);
    glVertex3f(0, -0.37, 0.13);
    glVertex3f(0, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.255, -0.245, 0);
    glVertex3f(0, -0.245, 0.255);
    glVertex3f(0, -0.125, 0.375);
    glVertex3f(-0.375, -0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.38, -0.12, 0);
    glVertex3f(0, -0.12, 0.38);
    glVertex3f(0, 0, 0.5);
    glVertex3f(-0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //blue
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.125, -0.375, 0);
    glVertex3f(0, -0.375, 0.125);
    glVertex3f(0, -0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.13, -0.37, 0);
    glVertex3f(0, -0.37, 0.13);
    glVertex3f(0, -0.25, 0.25);
    glVertex3f(0.25, -0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.255, -0.245, 0);
    glVertex3f(0, -0.245, 0.255);
    glVertex3f(0, -0.125, 0.375);
    glVertex3f(0.375, -0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.38, -0.12, 0);
    glVertex3f(0, -0.12, 0.38);
    glVertex3f(0, 0, 0.5);
    glVertex3f(0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //pink bottom
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.125, -0.375, 0);
    glVertex3f(0, -0.375, -0.125);
    glVertex3f(0, -0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.13, -0.37, 0);
    glVertex3f(0, -0.37, -0.13);
    glVertex3f(0, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.255, -0.245, 0);
    glVertex3f(0, -0.245, -0.255);
    glVertex3f(0, -0.125, -0.375);
    glVertex3f(-0.375, -0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.38, -0.12, 0);
    glVertex3f(0, -0.12, -0.38);
    glVertex3f(0, 0, -0.5);
    glVertex3f(-0.5, 0, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES); //yellow
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.125, -0.375, 0);
    glVertex3f(0, -0.375, -0.125);
    glVertex3f(0, -0.5, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.13, -0.37, 0);
    glVertex3f(0, -0.37, -0.13);
    glVertex3f(0, -0.25, -0.25);
    glVertex3f(0.25, -0.25, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.255, -0.245, 0);
    glVertex3f(0, -0.245, -0.255);
    glVertex3f(0, -0.125, -0.375);
    glVertex3f(0.375, -0.125, 0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(0.38, -0.12, 0);
    glVertex3f(0, -0.12, -0.38);
    glVertex3f(0, 0, -0.5);
    glVertex3f(0.5, 0, 0);
    glEnd();
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 800, "Lab6", NULL, NULL);
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
    
    int octa = glGenLists(17);
    glNewList(octa, GL_COMPILE_AND_EXECUTE);
    DrawOctahedron();
    glEndList();
    
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);
        
        glfwSetKeyCallback(window, keyCallback);
        
        glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);
        
        glCallList(octa);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
