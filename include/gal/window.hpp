#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>

#include <gal/inputs.hpp>

struct GLFWwindow;
struct ImVec4;
struct ImGuiIO;

namespace gal {
    class Context;
    class Window {
    public:
        Window(std::string title, unsigned int width, unsigned int height);
        ~Window();
        void GetFrameBufferSize(int& w, int& h);

        gal::input::KeyState checkKeyState(unsigned int key);

        void ClearScreen();
        bool CloseRequested();
        void requestClose(bool closeRequested = true) {
            _closeRequested = closeRequested;
        }
        void SwapBufffers();

        bool isDockSpace();
        void setDockSpace(bool state);

        GLFWwindow* window;
    private:
        bool _closeRequested;

        ImVec4* clear_color;
        ImGuiIO* imguiConfig;
        bool _dockSpaceStatus;

        friend Context;
    };
}

#endif