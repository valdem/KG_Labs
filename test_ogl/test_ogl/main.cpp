/* OpenGL libs */
#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>


int main(void)
{
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*Initialize the GLEW library */
    if(glewInit() != GLEW_OK)
    {
        std::cout << "GLEW initialization error" << std::endl;
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0, 0.5f);
            glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /* Проверка версии GL */
    const GLubyte *render       = glGetString( GL_RENDERER );
    const GLubyte *vendor       = glGetString( GL_VENDOR );
    const GLubyte *version      = glGetString( GL_VERSION );
    const GLubyte *glslVersion  = glGetString ( GL_SHADING_LANGUAGE_VERSION );

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    std::cout << "GL Vendor:            " << vendor     << std::endl;
    std::cout << "GL Render:            " << render     << std::endl;
    std::cout << "GL Version (string)   " << version    << std::endl;
    std::cout << "GL Version (integer)  " << major << "." << minor << std::endl;
    std::cout << "GLSL Version:         " << glslVersion << std::endl;



    glfwTerminate();
    return 0;
}
