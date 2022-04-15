//what controls application
#ifndef two
#define two


#include "lve_window.hpp"

namespace lve{
  class FirstApp{

  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();
  //private member variable so when app is created window is created and destroyed
  private:
    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
  };
}


#endif /* end of include guard: two */
