#pragma once
#include <iomanip>
#if __APPLE__ // This is to disable deprecation warnings from opengl
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#endif

class Window{
public:
    Window(std::string name, std::size_t width, std::size_t height) : name(name), width(width), height(height), window(nullptr) { }
    ~Window() = default;

    void initialize();

    void mainloop();

    void clear(); // clearing windows buffer

    void refresh(); // refreshes the windows buffer, and the events after the events are handled.

    std::size_t height;
    std::size_t width;
    std::string name;

    GLFWwindow* window;
};