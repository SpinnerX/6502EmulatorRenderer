#include <core/Window.h>
#include <iostream>


void Window::initialize(){
    // static_assert(glfwInit(), "GLFW does not work correctly!"); // Check that GLFW does not work
    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

void Window::mainloop(){

    // nullptr if we did not call initialze()
    if(window == nullptr){
        std::cout << "Didn't call initialize()\n";
        glfwTerminate();
        return;
    }

    bool appQuit = false;

    while(true){
        clear();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            appQuit = true;
            break;
        }

        refresh();
    }

    if(appQuit){
        glfwTerminate();
        return;
    }

}


void Window::clear(){
    glClear(GL_COLOR_BUFFER_BIT); // clearing windows buffer
}

void Window::refresh(){
    if(window == nullptr){
        std::cout << "Window not initialized!\n";
        glfwTerminate();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();

}