//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <filesystem>

class BadBase {
public:
    BadBase() { spdlog::info("BadBase constructor"); }
    ~BadBase() { spdlog::info("BadBase destructor"); }

    virtual void work() { spdlog::info("BadBase::work()"); }
};

class BadDerived : public BadBase {
public:
    BadDerived() { spdlog::info("BadDerived constructor"); }
    ~BadDerived() { spdlog::info("BadDerived destructor"); }

    void work() override { spdlog::info("BadDerived::work()"); }
};

class GoodBase {
public:
    GoodBase() { spdlog::info("GoodBase constructor"); }
    virtual ~GoodBase() { spdlog::info("GoodBase destructor"); }

    virtual void work() { spdlog::info("GoodBase::work()"); }
};

class GoodDerived : public GoodBase {
public:
    GoodDerived() { spdlog::info("GoodDerived constructor"); }
    ~GoodDerived() override { spdlog::info("GoodDerived destructor"); }

    void work() override { spdlog::info("GoodDerived::work()"); }
};

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task06_logger", LOGS_DIR "/task06.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    {
        BadBase* b = new BadDerived();
        b->work();
        delete b;
    }

    {
        GoodBase* g = new GoodDerived();
        g->work();
        delete g;
    }

    return 0;
}
