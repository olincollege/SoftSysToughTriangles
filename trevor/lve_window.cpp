#include "lve_window.hpp"

namespace lve{

  //implement constructor
  LveWindow::LveWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}{
    initWindow();

  }

  //destroy resources we require at initialization (pass in window pointer)
  LveWindow::~LveWindow(){
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  void LveWindow::initWindow(){
    //initialize glfw library
    glfwInit();
    //don't vreate openGL contest, not using vulkan, we don't want that
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //prevent window from being resized after creation
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //initialize window pointer
    window = glfwCreateWindow(width,height, windowName.c_str(), nullptr,nullptr);
  }
} //namespace lvw
