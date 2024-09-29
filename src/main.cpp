/**
 * @file main.cpp
 *
 * @date 28.09.2024
 * @author mltya.usov04\@gmail.com
 *
 * Copyright (c) 2024 Sireth
 */

#include <cstdlib>
#include <iostream>
#include <ostream>

#include "HelloTriangleApplication.h"

int main() {
    vt::HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
