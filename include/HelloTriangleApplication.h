/**
 * @file HelloTriangleApplication.h
 *
 * @date 29.09.2024
 * @author mltya.usov04\@gmail.com
 *
 * Copyright (c) 2024 Sireth
 */

#ifndef HELLOTRIANGLEAPPLICATION_H
#define HELLOTRIANGLEAPPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

namespace vt {
    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;
    const std::vector validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    constexpr bool enableValidationLayers = false;
#else
    constexpr bool enableValidationLayers = true;
#endif

    inline VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
                                                 const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                                 const VkAllocationCallbacks *pAllocator,
                                                 VkDebugUtilsMessengerEXT *pDebugMessenger) {
        const auto func = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(
            vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"));

        if (func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
        }
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    inline void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                              VkDebugUtilsMessengerEXT debugMessenger,
                                              const VkAllocationCallbacks *pAllocator) {
        const auto func = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
            vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"));

        if (func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }

    class HelloTriangleApplication {
    public:
        void run();

    private:
        void initWindow();

        void createInstance();

        void initVulkan();

        void setupDebugMessenger();

        static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

        static bool checkValidationLayerSupport();

        static std::vector<const char *> getRequiredExtensions();

        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
                VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                void *pUserData);

        void mainLoop() const;

        void cleanup() const;

    private:
        GLFWwindow *m_window{};

        VkInstance m_instance{};
        VkDebugUtilsMessengerEXT debugMessenger{};
    };
} // vt

#endif //HELLOTRIANGLEAPPLICATION_H
