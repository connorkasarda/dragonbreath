#include "window.h"

namespace dragon::window
{
    Window::Window(int width, int height, const char *title)
        : m_width {width}, m_height {height}, m_title {title}
    {
        init();
    }

    Window::~Window(void) 
    {
        glfwTerminate();
    }

    WindowInitStatus Window::init(void)
    {
        if (!glfwInit())
        {
            std::cout << "failed to initialize GLFW...\n";
            return WindowInitStatus::e_WindowInitFail;
        }
        m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        if (!m_window)
        {
            glfwTerminate();
            std::cout << "failed to create GLFW window...\n";
            return WindowInitStatus::e_WindowCreateFail;
        }
        std::cout << "GLFW window created successfully...\n";
        glfwMakeContextCurrent(m_window);
        return WindowInitStatus::e_WindowCreateSuccess;
    }
}