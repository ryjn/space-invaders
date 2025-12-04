#include <cstdio>
#include <cstdint>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

struct Buffer {
  size_t width, height;
  uint32_t* data;
};

/**
 * @brief Converts RGB color values to a 32-bit unsigned integer 
 *
 * Sets left-most 24 bits to r, g, and b values, respectively.
 * 8 right-most bits are set to 255
 * Format: RGBA
 *
 * @param r Red component (0 - 255)
 * @param g Green component (0 - 255)
 * @param b Blue component (0 - 255)
 * @return uint32_t Combined RGBA value
 */
uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b) {
  return  (r << 24) |
          (g << 16) |
          (b << 8)  |
          255;
}

void buffer_clear(Buffer* buffer, uint32_t color) {
  for(size_t i = 0; i < buffer->width * buffer->height; ++i) {
    buffer->data[i] = color;
  }
}


int main() {
  const size_t buffer_width = 224;
  const size_t buffer_height = 256;

  // Set callback for errors
  glfwSetErrorCallback(error_callback);

  // Initialize the library
  if (!glfwInit()) return -1;
 
  // Set hints
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Create window
  GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
  if(!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLEW
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fprintf(stderr, "Error initializing GLEW.\n");
    glfwTerminate();
    return -1;
  }

  // Get OpenGL version
  int glVersion[2] = {-1, 1};
  glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
  glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

  printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);

  glClearColor(1.0, 0.0, 0.0, 1.0);

  // Initialize buffer
  Buffer buffer;
  buffer.width = buffer_width;
  buffer.height = buffer_height;
  buffer.data = new uint32_t[buffer.width * buffer.height];

  buffer_clear(&buffer, 0);

  // Game loop
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
