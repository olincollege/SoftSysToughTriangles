#ifndef once
#define once

//include vulkan headers
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//include standar string
#include<string>

namespace lve{

  class LveWindow{

  public:
    //constructor that takes values we use to initialize our variables
    LveWindow(int w, int h, std::string name);
    //destroy instance
    ~LveWindow();


    //delete copy constructor and operator bc we are using pointer to glf pointer
    //resource creation is aquisition
    LveWindow(const LveWindow &) = delete;
    LveWindow &operator=(const LveWindow &) = delete;

    bool shouldClose(){return glfwWindowShouldClose(window); }

  private:

    //initialize window
    void initWindow();

    const int width;
    const int height;

    std::string windowName;
    //private pointer to window
    GLFWwindow *window;

  };
  }


#endif /* end of include guard: once */
