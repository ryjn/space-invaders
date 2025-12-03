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
