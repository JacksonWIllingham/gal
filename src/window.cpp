#include <string>

#include <gal/window.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include <imgui/examples/imgui_impl_glfw.h>
#include <imgui/examples/imgui_impl_opengl3.h>

#include <gal/context.hpp>

gal::Window::Window(std::string title, unsigned int width, unsigned int height) {
    _closeRequested = false;
    _dockSpaceStatus = false;
//    Context::getInstance().registerWindow(this);//simply amke sure shits setup
//
//#if __APPLE__
//// GL 3.2 + GLSL 150
//    glsl_version = "#version 150";
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
//    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
//#else
//    // GL 3.0 + GLSL 130
//    const char* glsl_version = "#version 130";
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_SAMPLES, 4);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
//    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
//#endif
//    window = glfwCreateWindow(1280, 720, title.c_str(), NULL, NULL);
//    if (window == NULL)
//        return;// 1;
//    glfwMakeContextCurrent(window);
//    glfwSwapInterval(1);

#if __APPLE__
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
#endif

    Context::getInstance().prewindowCreation();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetCursorPosCallback(window, mouse_callback);
    //glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    Context::getInstance().postWindowCreation();

    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        imguiConfig = &io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        io.IniFilename = NULL;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);


        bool show_demo_window = true;
        bool show_another_window = false;
        clear_color = new ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    }
}

gal::Window::~Window() {
    glfwDestroyWindow(window);
}


void gal::Window::ClearScreen() {
    glClearColor(clear_color->x, clear_color->y, clear_color->z, clear_color->w);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool gal::Window::CloseRequested() {
    return (glfwWindowShouldClose(window) || _closeRequested);
}

void gal::Window::SwapBufffers() {
    glfwSwapBuffers(window);
}

bool gal::Window::isDockSpace() {
    return _dockSpaceStatus;
}

void gal::Window::setDockSpace(bool status) {
    _dockSpaceStatus = status;
}

void gal::Window::GetFrameBufferSize(int& w, int& h) {
    glfwGetFramebufferSize(window, &w, &h);
}

gal::input::KeyState gal::Window::checkKeyState(unsigned int key) {
    return (gal::input::KeyState)glfwGetKey(window, key);
}