#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "VulkanRenderer.h"
#include <string.h>

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600){

    // Initialize GLFW
    if(!glfwInit())
    {
        throw std::runtime_error("GLFW initialization failed!");
    }

    // Set GLFW to not work with OPEN_GL (As it does by default)
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);

}

int main()
{
    // Create our window
    initWindow("Test Window", 800, 600);

    // Create VulkanRenderer instance
    if(vulkanRenderer.init(window) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    // Loop until the user closes the window
    while(!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        // This will get the event that the X button was pressed
        glfwPollEvents();
    }

    // Destroy window
    glfwDestroyWindow(window);

    // Stop GLFW
    glfwTerminate();

    return 0;
}