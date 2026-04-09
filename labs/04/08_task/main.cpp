//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "circle.h"
#include "rectangle.h"
#include <string>
#include <filesystem>

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task08_logger", LOGS_DIR "/task08.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    Circle c1(1.0);
    Circle c2(2.0);
    Rectangle r(3.0, 4.0);

    void* vptr_c1 = *reinterpret_cast<void**>(&c1);
    void* vptr_c2 = *reinterpret_cast<void**>(&c2);
    void* vptr_r  = *reinterpret_cast<void**>(&r);

    spdlog::info("c1 vptr = {:p}", vptr_c1);
    spdlog::info("c2 vptr = {:p}", vptr_c2);
    spdlog::info("r  vptr = {:p}", vptr_r);
    spdlog::info("c1 == c2: {}", vptr_c1 == vptr_c2);
    spdlog::info("c1 == r:  {}", vptr_c1 == vptr_r);

    void** vtable = reinterpret_cast<void**>(vptr_c1);
    spdlog::info("vtable[0] = {:p}", vtable[0]);
    spdlog::info("vtable[1] = {:p}", vtable[1]);

    spdlog::info("sizeof(Circle)    = {}", sizeof(Circle));
    spdlog::info("sizeof(Rectangle) = {}", sizeof(Rectangle));
    spdlog::info("sizeof(void*)     = {}", sizeof(void*));
    spdlog::info("sizeof(std::string) = {}", sizeof(std::string));

    return 0;
}
