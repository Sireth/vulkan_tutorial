/**
 * @file HelloTriangleApplication.cpp
 *
 * @date 29.09.2024
 * @author mltya.usov04\@gmail.com
 *
 * Copyright (c) 2024 Sireth
 */

#include "HelloTriangleApplication.h"

#include <cstdlib>
#include <iostream>
#include <vector>

namespace vt {
    void HelloTriangleApplication::run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

    void HelloTriangleApplication::initWindow() {
        if (!glfwInit()) {
            std::cerr << "Ошибка инициализации GLFW" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
        if (!m_window) {
            std::cerr << "Ошибка создания окна GLFW" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
    }

    void HelloTriangleApplication::createInstance() {
        /// Create info for application
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        /// Create info for instance
        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;

        const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        if (glfwExtensions == nullptr) {
            throw std::runtime_error("Не удалось получить необходимые расширения GLFW");
        }

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        /// Create instance
        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("Не удалось создать экземпляр!");
        }
    }

    void HelloTriangleApplication::initVulkan() {
        createInstance();
    }

    void HelloTriangleApplication::mainLoop() {
        while (!glfwWindowShouldClose(m_window)) {
            glfwPollEvents();
        }
    }

    void HelloTriangleApplication::cleanup() {
        vkDestroyInstance(instance, nullptr);

        glfwDestroyWindow(m_window);

        glfwTerminate();
    }
} // vt
