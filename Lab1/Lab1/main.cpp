#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC
#include <GLFW/glfw3.h>
#include <math.h>

int mytime = 100;
float x = -0.78;
float x2 = -0.65;

using namespace std;

void display()
{

    if (mytime > 0) {
        glColor3f(0.0, 1.0, 0.0);
    }
    else {
        glColor3f(0.0, 0.56, 0.0);
    }

    glBegin(GL_QUADS); //grass
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, -1.0);
    glEnd();

    if (mytime > 0) {
        glColor3f(0.0, 1.0, 1.0);
    }
    else {
        glColor3f(0.0, 0.15, 0.77);
    }

    glBegin(GL_QUADS); //sky
    glVertex2i(-1.0, 0.0);
    glVertex2i(-1.0, 1.0);
    glVertex2i(1.0, 1.0);
    glVertex2i(1.0, 0.0);
    glEnd();

    if (mytime > 0) {
        glColor3f(1.0, 1.0, 0.0);
    }
    else {
        glColor3f(1.0, 1.0, 1.0);
    }

    double r = 0.2;
    double twicePi = 2.0 * 3.142;
    float y = 0.78;
    glBegin(GL_TRIANGLE_FAN); //sun or moon
    glVertex2f(x, y);
    for (int i = 0; i <= 20; i++)   {
        glVertex2f ((x + (r * cos(i * twicePi/20))), (y + (r * sin(i * twicePi/20))));
    }
    glEnd();
    
    if (mytime < 0) {
        glColor3f(0.0, 0.15, 0.77);
        
        glBegin(GL_TRIANGLE_FAN); //halfmonth
        glVertex2f(x2, y);
        for (int i = 0; i <= 20; i++)   {
            glVertex2f ((x2 + (r * cos(i * twicePi/20))), (y + (r * sin(i * twicePi/20))));
        }
        glEnd();
    }

    if (mytime > 0) {
        glColor3f(0.66, 0.32, 0.0);
    }
    else {
        glColor3f(0.33, 0.13, 0.0);
    }
    
    glBegin(GL_QUADS); //house
    glVertex2f(0.3, 0.4);
    glVertex2f(0.7, 0.4);
    glVertex2f(0.7, 0.0);
    glVertex2f(0.3, 0.0);
    glEnd();

    if (mytime > 0) {
        glColor3f(1.0, 0.0, 0.0);
    }
    else {
        glColor3f(0.7, 0.05, 0.0);
    }

    glBegin(GL_TRIANGLES); //roof
    glVertex2f(0.3, 0.4);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.7, 0.4);
    glEnd();
    
}

void mytime_go()
{
    mytime--;
    if (mytime<-100) {
        mytime = 100;
    }
    
    if (mytime == 0) {
        x2 = -0.87;
    }
    
    if (mytime == 0 || mytime == 100) {
        x = -1.0;
    }
    
    x+=0.02;
    
    if (mytime < 0) {
        x2+=0.02;
    }
    
    //sleep(1);
    printf("%d\n", mytime);
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 600, "Lab1", NULL, NULL);
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
        
        display();
        mytime_go();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
