#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
class FirstApp {
    public:
      static constexpr int WIDTH = 800;
      static constexpr int HEIGHT = 600;

      FirstApp();
      ~FirstApp();

      FirstApp(const FirstApp &) = delete;
      FirstApp &operator=(const FirstApp &) = delete;

      void run();

    private:
      void createPipelineLayout();
      void createPipeline();
      void createCommandBuffers();
      void drawFrame();

      LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
      LveDevice lveDevice{lveWindow};
      LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
      std::unique_ptr<LvePipeline> lvePipeline; //smart pointer
      VkPipelineLayout pipelineLayout;
      std::vector<VkCommandBuffer> commandBuffers;

      // LvePipeline lvePipeine{lveDevice,
      //   "shaders/simple_shader.vert.spv",
      //   "shaders/simple_shader.frag.spv",
      // LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};

} // namespace lve
