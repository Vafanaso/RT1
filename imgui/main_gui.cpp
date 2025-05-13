/*#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "raytracer.hpp" // Expose `render(...)` and `Sphere`, etc.
#include <GLFW/glfw3.h>
#include <vector>

int main() {
  // Setup GLFW and ImGui
  glfwInit();
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Raytracer Control", NULL, NULL);
  glfwMakeContextCurrent(window);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // Create scene
  std::vector<Sphere> spheres =
      create_scene(); // extract scene creation to a function
  const int WIDTH = 640, HEIGHT = 480;
  unsigned char *pixelBuffer = new unsigned char[WIDTH * HEIGHT * 3];

  // OpenGL texture
  GLuint textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB,
               GL_UNSIGNED_BYTE, pixelBuffer);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  float sphereX = 0.0f;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // GUI controls
    ImGui::Begin("Controls");
    ImGui::SliderFloat("Sphere X", &sphereX, -10.0f, 10.0f);
    ImGui::End();

    // Update scene
    spheres[1].center.x = sphereX;
    render(spheres, pixelBuffer, WIDTH, HEIGHT);

    // Update texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, WIDTH, HEIGHT, GL_RGB,
                    GL_UNSIGNED_BYTE, pixelBuffer);

    // Show image
    ImGui::Begin("Raytraced Image");
    ImGui::Image((void *)(intptr_t)textureID, ImVec2(WIDTH, HEIGHT));
    ImGui::End();

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  }

  // Cleanup
  delete[] pixelBuffer;
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
  */
