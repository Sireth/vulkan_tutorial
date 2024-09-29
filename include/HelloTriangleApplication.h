/**
 * @file HelloTriangleApplication.h
 *
 * @date 29.09.2024
 * @author mltya.usov04\@gmail.com
 */

#ifndef HELLOTRIANGLEAPPLICATION_H
#define HELLOTRIANGLEAPPLICATION_H

#include <vulkan/vulkan.h>

namespace vt {
    class HelloTriangleApplication {
    public:
        void run();

    private:
        void initVulkan();

        void mainLoop();

        void cleanup();
    };
} // vt

#endif //HELLOTRIANGLEAPPLICATION_H
