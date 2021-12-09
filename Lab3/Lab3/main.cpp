#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

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

void DrawCube(GLfloat size)
{
    glBegin(GL_QUADS);
    
    // left
    glNormal3f(-1.0, 0.0, 0.0);
    GLfloat color_left[] = {1.0, 0.0, 0.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_left);
    glVertex3f(-x-size, -size, -size);
    glVertex3f(-x-size,  size, -size);
    glVertex3f(-x-size,  size,  size);
    glVertex3f(-x-size, -size,  size);
    
    // right
    glNormal3f(1.0, 0.0, 0.0);
    GLfloat color_right[] = {0.0, 1.0, 0.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_right);
    glVertex3f(x+size, -size, -size);
    glVertex3f(x+size, -size, size);
    glVertex3f(x+size, size, size);
    glVertex3f(x+size, size, -size);
    
    // bottom
    glNormal3f(0.0, -1.0, 0.0);
    GLfloat color_bottom[] = {0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_bottom);
    glVertex3f(-size, -x-size, -size);
    glVertex3f(-size, -x-size, size);
    glVertex3f(size, -x-size, size);
    glVertex3f(size, -x-size, -size);
    
    // top
    glNormal3f(0.0, 1.0, 0.0);
    GLfloat color_top[] = {1.0, 1.0, 0.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_top);
    glVertex3f(-size, x+size, -size);
    glVertex3f(-size, x+size, size);
    glVertex3f(size, x+size, size);
    glVertex3f(size, x+size, -size);
    
    // back
    glNormal3f(0.0, 0.0, -1.0);
    GLfloat color_back[] = {1.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_back);
    glVertex3f(-size, -size, -x-size);
    glVertex3f(size, -size, -x-size);
    glVertex3f(size, size, -x-size);
    glVertex3f(-size, size, -x-size);
    
    // front
    glNormal3f(0.0, 0.0, 1.0);
    GLfloat color_front[] = {0.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color_front);
    glVertex3f(-size, -size, x+size);
    glVertex3f(size, -size, x+size);
    glVertex3f(size, size, x+size);
    glVertex3f(-size, size, x+size);
    glEnd();
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 800, "Lab3", NULL, NULL);
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
    
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        
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
        
        DrawCube(0.3);
        
        glDisable(GL_LIGHT0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
