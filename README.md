# Space Invaders in C++
## What is GLFW and OpenGL?
GLFS is a library for creating windows and handling input in C++. It is responsible for handling the windows where graphics will be drawn, as well as handling the keyboard and mouse inputs. However, it does not draw the graphics itself.  

OpenGL is a graphics API that tells the GPU how to draw things into the window. It is responsible for rendering context, but cannot create the window or handle input.

## Setting up GLFW
### Headers
Include the GLFW header file, which contains all the constants, types, and function prototypes of the GLFW API
```cpp
#include <GLFW/glfw3.h>
```

Because OpenGL is an API specification, the implementation can vary depending on GPUs, operating systems, and graphic drivers. Depending on these factors, not all functions may be supported. For this reason, OpenGL functions need to be declared and loaded explicitly at runtime. A loading library helps manage this.  
For this project, GLEW will be used for the loading library:
```cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
```

> [!NOTE]
> Needs to be included before GLFW.  
> Can also define `GLFW_INCLUDE_NONE` before the GLFW header to explicitly disable inclusion of development environment header.  
> Allows including the headers in any order.  

### Initializing and Terminating
To use GLFW functions, the library must be initialized.
```cpp
if (!glfwInit()) return -1;
```
On successful initialization, `GLFW_TRUE` is returned, otherwise `GLFW_FALSE`. Returned as `1` and `0`, respectively.  

Once done using GLFW, it must be terminated:
```cpp
glfwTerminate();
```

### Error Callback
Most events are reported through callbacks that are called by GLFW with arguments describing the event.  

The reports can be received using an error callback:
```cpp
void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}
```
The `error_callback` function must have the structure above.  

To set the callback function:
```cpp
glfwSetErrorCallback(error_callback);
```

### Creating a Window
The window can be created using a call to the `glfwCreateWindow` function:
```cpp
GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
if (!window) {
  glfwTerminate();
  return -1;
}
```
The code above creates a `640x480` window in windowed mode with an OpenGL context.  

By default, the OpenGL context GLFW creates may have any version. A minimum OpenGL version can be required by setting the `GLFW_CONTEXT_VERSION_MAJOR` and `GLFW_CONTEXT_VERSION_MINOR` hints before creating the window.  
Additionally, can set the OpenGL profile by setting the `GLFW_OPENGL_PROFILE` hint.
```cpp
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
if (!window) {
    // Window or context creation failed
}
```
