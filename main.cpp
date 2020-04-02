#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>
#include <cstring>

#include "ZEN/zen.h"

#include "Sandbox/DemoScenes/DemoClearColor.hpp"
#include "Sandbox/DemoScenes/DemoTriangle.hpp"
#include "Sandbox/DemoScenes/DemoTexture2D.hpp"

using namespace zen;

void ChangeDemo(int selection, Sandbox::Scene **pScene) {

    delete *pScene;

    // and build a new one
    switch (selection) {
        default:
        case 0:
            *pScene = new Sandbox::Scene();
            break;
        case 1:
            *pScene = new Sandbox::DemoClearColor();
            break;
        case 2:
            *pScene = new Sandbox::DemoTriangle();
            break;
        case 3:
            *pScene = new Sandbox::DemoTexture2D();
    }

}

int main(int argc, const char** argv) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required for ImGui in macOS
    const char* glsl_version = "#version 150";

    const int width = 800;
    const int height = 600;

    window = glfwCreateWindow(width, height, "Hello OpenGL", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glfwSwapInterval(1);

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << '\n';

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    Renderer renderer;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    const char* demos[] = { "None", "Clear color", "Triangle", "Texture 2D" };
    const unsigned int nDemos = sizeof(demos) / sizeof(char*);
    static int current_selection = 0;

    Sandbox::Scene* scene = nullptr;

    if (argc == 2) {
        for (int i = 0; i < nDemos; ++i) {
            if (strcmp(demos[i], argv[1]) == 0) {
                ChangeDemo(i, &scene);
                current_selection = i;
            }
        }

        if (scene == nullptr) scene = new Sandbox::Scene;
    } else {
        scene = new Sandbox::Scene;
    }

    while(!glfwWindowShouldClose(window)) {
        renderer.Clear();

        scene->OnUpdate(glfwGetTime());
        scene->OnRender();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Demo selection");
        ImGui::Combo("Demo", &current_selection, demos, nDemos);
        if (ImGui::Button("Change"))
            ChangeDemo(current_selection, &scene);
        ImGui::End();

        scene->OnImGuiRender();

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    delete scene;

    // Cleanup
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}