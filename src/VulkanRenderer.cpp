
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include "VulkanRenderer.h"
#include <iostream>
#include <string.h>

VulkanRenderer::VulkanRenderer(){

}

int VulkanRenderer::init(GLFWwindow* newWindow){
    window = newWindow;

    try{
        createInstance();
    }catch(const std::runtime_error &e){
        std::cout<<"ERROR: Failed to create Vulkan Instance "<<e.what()<<std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

void VulkanRenderer::createInstance(){

    // Application information for Vulkan Instance
    // Most data here does not affect the program, is for developer mostly
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;     // NOTICE VkApplicationInfo needs a VK_STRUCTURE_TYPE_APPLICATION_INFO
    appInfo.pApplicationName = "VulkanRenderer";            // Custom of application
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);  // Custom version of application
    appInfo.pEngineName = "No Engine";                      // Custom engine name
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);       // Custom engine version
    appInfo.apiVersion = VK_API_VERSION_1_0;                // Vulkan API version

    // Creation information for Vulkan Instance
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;  // Structure type 
    createInfo.pApplicationInfo = &appInfo;                     // POINTER TO THE APPLICATION ABOVE APPINFO

    // Create list to hold instance exceptions
    std::vector<const char*> instanceExceptions = std::vector<const char*>();

    // Get required extensions for Vulkan
    uint32_t glfwExtensionsCount = 0;
    const char** glfwExtensions;                                                // Array of pointers to extensions
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);   // Get GLFW extensions

    // Add GLFW Extensions to Vulkan
    for(size_t i = 0; i < glfwExtensionsCount; i++){
        instanceExceptions.push_back(glfwExtensions[i]);
    }

    if(!checkInstanceExtensionSupport(&instanceExceptions)){
        throw std::runtime_error("Missing Vulkan Extensions");
    }

    createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExceptions.size());
    createInfo.ppEnabledExtensionNames = instanceExceptions.data();

    // Validation Layers TODO
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = nullptr;

    // Create Vulkan Instance
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if(result != VK_SUCCESS){
        throw std::runtime_error("Failed to create Vulkan Instance");
    }
}


bool checkInstanceExtensionSupport(std::vector<const char*> checkExtensions)
{
    // Get the number of extensions to create an array of extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    // Get the list of available extensions
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    // Iterate over the required extensions and check if they are available
    for(const auto &checkExtension : *checkExtensions){
        bool hasExtension = false;
        for(const auto &extension : extensions){
            if(strcmp(checkExtension, extension.extensionName){
                hasExtension = true;
                break;
            }
        }
        if(!hasExtension){
            return false;
        }
    }
    return true;
}

VulkanRenderer::~VulkanRenderer(){

}