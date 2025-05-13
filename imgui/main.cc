#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
  // Setup GLFW
  glfwInit();
  GLFWwindow *window =
      glfwCreateWindow(1280, 720, "Dear ImGui Example", NULL, NULL);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer bindings
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Your GUI code here
    ImGui::ShowDemoWindow();
    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some text");
    static float x = 0.0f;
    static float y = 0.0f;
    static float z = 0.0f;
    ImGui::SliderFloat("x", &x, -20.0f, 20.0f);
    ImGui::SliderFloat("y", &y, -20.0f, 20.0f);
    ImGui::SliderFloat("z", &z, -20.0f, 20.0f);
    static int counter = 0;
    if (ImGui::Button("Button")) {
      counter++;
      x += 0.1;
    }
    ImGui::Text("counter = %d", counter);
    ImGui::End();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
