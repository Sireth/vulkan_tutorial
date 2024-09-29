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

namespace vt {
    constexpr uint32_t WIDTH = 800;
    constexpr uint32_t HEIGHT = 600;

    class HelloTriangleApplication {
    public:
        void run();

    private:
        void initWindow();
        void initVulkan();

        void mainLoop();

        void cleanup();

    private:
        GLFWwindow *m_window{};
    };
} // vt

#endif //HELLOTRIANGLEAPPLICATION_H
