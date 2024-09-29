/**
 * @file HelloTriangleApplication.cpp
 *
 * @date 29.09.2024
 * @author mltya.usov04\@gmail.com
 */

#include "HelloTriangleApplication.h"

#include <cstdlib>
#include <iostream>

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

    void HelloTriangleApplication::initVulkan() {
    }

    void HelloTriangleApplication::mainLoop() {
        while (!glfwWindowShouldClose(m_window)) {
            glfwPollEvents();
        }
    }

    void HelloTriangleApplication::cleanup() {
        glfwDestroyWindow(m_window);

        glfwTerminate();
    }
} // vt
