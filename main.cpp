#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

int main() {
  glfwSetErrorCallback(error_callback);

  GLFWwindow* window;

  // Initialize the library
  if (!glfwInit()) return -1;
 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Create window
  window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
  if(!window) {
    glfwTerminate();
    return -1;
  }
  glfsMakeContextCurrent(window);

  return 0;
}
