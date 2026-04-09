//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <filesystem>

class Base7 {
public:
    Base7() {
        spdlog::info("Base7 constructor");
        describe();
    }
    virtual ~Base7() { spdlog::debug("Base7 destructor"); }

    virtual void describe() const {
        spdlog::info("Base7::describe()");
    }
};

class Derived7 : public Base7 {
public:
    Derived7() : Base7() {
        spdlog::info("Derived7 constructor");
        describe();
    }
    ~Derived7() override { spdlog::debug("Derived7 destructor"); }

    void describe() const override {
        spdlog::info("Derived7::describe()");
    }
};

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task07_logger", LOGS_DIR "/task07.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    Derived7 d;

    Base7* ptr = &d;
    ptr->describe();

    return 0;
}
