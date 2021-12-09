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

using namespace std;

GLfloat content[] {
    -1.0, -1.0, //grass
    -1.0, 0.0,
    1.0, 0.0,
    1.0, -1.0,
    
    -1.0, 0.0, //sky
    -1.0, 1.0,
    1.0, 1.0,
    1.0, 0.0,
    
    0.3, 0.4, //house
    0.7, 0.4,
    0.7, 0.0,
    0.3, 0.0,
    
    0.3, 0.4, //roof
    0.5, 0.6,
    0.7, 0.4
};

GLfloat day_color[] {
    0.0, 1.0, 0.0, //grass
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    
    0.0, 1.0, 1.0, //sky
    0.0, 1.0, 1.0,
    0.0, 1.0, 1.0,
    0.0, 1.0, 1.0,
    
    0.66, 0.32, 0.0, //house
    0.66, 0.32, 0.0,
    0.66, 0.32, 0.0,
    0.66, 0.32, 0.0,
    
    1.0, 0.0, 0.0, //roof
    1.0, 0.0, 0.0,
    1.0, 0.0, 0.0
};

GLfloat night_color[] {
    0.0, 0.56, 0.0, //grass
    0.0, 0.56, 0.0,
    0.0, 0.56, 0.0,
    0.0, 0.56, 0.0,
    
    0.0, 0.15, 0.77, //sky
    0.0, 0.15, 0.77,
    0.0, 0.15, 0.77,
    0.0, 0.15, 0.77,
    
    0.33, 0.13, 0.0, //house
    0.33, 0.13, 0.0,
    0.33, 0.13, 0.0,
    0.33, 0.13, 0.0,
    
    0.7, 0.05, 0.0, //roof
    0.7, 0.05, 0.0,
    0.7, 0.05, 0.0
};

void sun_moon()
{
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
}

void mytime_go()
{
    mytime--;
    if (mytime<-100) {
        mytime = 100;
    }
    
    if (mytime == 0 || mytime == 100) {
        x = -1.0;
    }
    
    x+=0.02;
    //sleep(1);
    printf("%d\n", mytime);
}

int main(void)
{
    GLFWwindow* window;
    
    if(!glfwInit()){
        return -1;
    }
    
    
    window = glfwCreateWindow(800, 600, "Lab2", NULL, NULL);
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
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        glVertexPointer(2, GL_FLOAT, 0, content);
        glColorPointer(3, GL_FLOAT, 0, (mytime > 0) ? day_color : night_color);
        
        glDrawArrays(GL_QUADS, 0, 8);
        
        sun_moon();
        
        glDrawArrays(GL_QUADS, 8, 4);
        glDrawArrays(GL_TRIANGLES, 12, 3);
        
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        
        mytime_go();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
