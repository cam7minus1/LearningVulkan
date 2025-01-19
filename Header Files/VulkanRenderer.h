#pragma once

// Include Vulkan via GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

class VulkanRenderer
{
public:
    // Constructor
    VulkanRenderer();

    int init(GLFWwindow* newWindow);

    // Destructor
    ~VulkanRenderer();

private:
    GLFWwindow* window;
    
    // Create Vulkan Instance
    VkInstance instance;

    // Vulkan Functions
    void createInstance();

    // Support functions
    bool checkInstanceExtensionSupport(std::vector<const char*> checkExtensions);
};
