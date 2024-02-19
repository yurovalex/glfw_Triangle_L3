#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#include <iostream>
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
int main(void)
{
    if (!glfwInit())
        exit(-1);

    glfwWindowHint ( GLFW_RESIZABLE, 1 );
        // можно менять размер окна мышью
    glfwWindowHint ( GLFW_DOUBLEBUFFER, 1 ); // поддержка двойной буферизации
    glfwWindowHint ( GLFW_DEPTH_BITS, 24 ); // 24-битовый буфер глубины
    // заказываем OpenGL 3.3, forward-compatible,
    // core profile
    // glfwWindowHint ( GLFW_CLIENT_API, GLFW_OPENGL_API );
    // glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    // glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 3 );
    // glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, 1 );
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(2560, 1440, "Simple GLFW Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    //Подготовка к выводу в полноэкранном режиме
    GLFWmonitor * monitor = NULL;
    monitor = glfwGetPrimaryMonitor ();
    glfwSetWindowMonitor ( window, monitor,
                          0,0, 2560, 1440, 165);

    // Get the OpenGL version
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;

    //Define a loop that terminates when the window is closed:

    while (!glfwWindowShouldClose(window))
    {
    //Set up the viewport (using the width and height of the window)
    //and clear the screen color buffer:
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float) width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5f,0.5f,0.5f,1);
    //Set up the camera matrix. Note that further details on the camera model
    //Interactive 3D Data Visualization:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    //Draw a rotating triangle and set a different color (red, green, and blue channels)
    //for each vertex (x, y, and z) of the triangle.
    //The first line rotates the triangle over time:
        glRotatef((float)glfwGetTime() * 60.f, 1.f, 1.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
    //Swap the front and back buffers (GLFW uses double buffering)
    //to update the screen and process all pending events:
        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);
    }
    //Release the memory and terminate the GLFW library. Then, exit the application:
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
