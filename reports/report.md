# Tough Triangles: Graphics in Vulcan

# Goals For This Project
Our goal is to learn how to use Vulcan to do graphics programming. Our lower bound is to make a triangle (it seems pretty tough). Our upper bound is 3d rendering with user input for perspective. Or raytracing.

## Learning Goals

 
Trevor: I think learning about an exciting application of C++ or C. Getting into this slimy of an api with lots of complicated structures is also going to be a new experience for me.

Andrew: I would love to learn about how computer graphics are handled on modern systems. If we managed to implement any sort of ray tracing I would be thrilled, but I’ll take an image processed by the GPU. 

## How did it go?

We mostly followed a tutorial series from Brenden Galea on youtube (https://www.youtube.com/watch?v=Y9U9IE0gVHA) that went into more detail about implementation than other tutorials pages.
We were able to follow the tutorial up to getting a triangle to show up in a static window.

File overview:
first_app: combines everything
lve_device.cpp : Sets up a Vulkan Device with access to the physical GPU in order to utilize parallel computing.
lve_pipeline.cpp: Sets up a graphics pipeline object and configures the fixed parts of the pipeline and utilizes a vertex and fragment shader for the programmable parts using OpenGL Shading Language (GLSL) in the shaders folder
lve_swap_chain.cpp: Sets up a swap chain to swap rendered frames
lve_window: sets up a VK surface that feeds into a GLF Window (an API for creating cross-platform compatible windows)

We realized that even a triangle was a bit out of our depth (1500+ lines), the C++ syntax and Vulkan API had a very high learning curve. In Vulkan, there are no default settings, so even to create a window or visualize a single triangle takes hundreds of lines of parameter settings and a dense file structure. Understanding what each of those values could be several SoftSys projects in and of themselves. 

ex.
```
  VkCommandBufferBeginInfo beginInfo{};
  beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
  beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
  configInfo.rasterizationInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;

```

There was a lot of background information to understand about the graphics pipeline, Vulkan device, physical device, Vulkan instance, surface, queue, frame buffers, swap chain, push constants, shaders, etc. We managed to follow along with the tutorial, but there were many sections where we were filling out dozens of parameters with no real explanation of their meaning (“We’ll talk about this later”).  Andrew could’ve even run the code once we got to it because of WSL. Once we got through understanding how to implement the different parts of the graphics pipeline for a hard coded triangle, we felt that it was more useful to understand theoretical concepts than to get lost debugging so we continued to watch the explanation parts of the rest of the series and learned about what we would need to do to implement more complex concepts like using buffers more efficiently, rasterization/gradient coloring, moveable objects, a moveable camera angle/position, spectral/diffuse lighting, generating 3d models, ect (much more visually interesting).


The biggest choice we made was stopping once we got to the triangle. Even though we could’ve kept on following along mindlessly and rendered some things that looked cool, we realized that the barrier of entry was already so high that continuing wouldn't feel as beneficial to our learning. We continued to watch the concept overview sections because we felt we would get more from a conceptual understanding than from copying more bricks of code.

We ended up achieving our MVP which was a much more intensive feat than we initially imagined. Overall we did both achieve our learning goals. We did get to learn a lot about c++ and its syntax and we did work with an incredibly slimy API that is easily the most complicated either of us have worked with to date. Although we did not get to ray tracing, we did cover the basics of computer graphics and developed a much stronger low-level understanding of graphics engines. If we were to do this project again we would start with a pre-made basic graphics engine already implemented and build an implementation for 3D models and lighting. This would eliminate most of the low-level parameterization that ate up a lot of time and required more background knowledge than we had.
