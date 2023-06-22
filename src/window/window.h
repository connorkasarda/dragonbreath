#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>

namespace dragon::window
{
    enum class WindowInitStatus
    {
        e_WindowInitFail,
        e_WindowCreateFail,
        e_WindowCreateSuccess
    };
    class Window
    {
    private:
        int m_width {};
        int m_height {};
        const char *m_title {};
        GLFWwindow *m_window {};
    public:
        Window(int width, int height, const char *title);
        ~Window(void);
    private:
        WindowInitStatus init(void);
    };
}

#endif