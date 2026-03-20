//
// Created by Иван Насекин on 07.03.2026.
//

#include "logger.h"

int main() {
    auto& logger = Logger::getInstance(LOG_FILE);

    logger.setLevel(Level::DEBUG);

    logger.log("Старт", Level::INFO);
    logger.log("Инициализация", Level::DEBUG);
    logger.log("Мало места на диске", Level::WARNING);
    logger.log("Хьюстон у нас проблемы", Level::ERROR);

    logger.setLevel(Level::INFO);
    logger.log("Это сообщение DEBUG должно быть отфильтровано", Level::DEBUG);
    logger.log("Это сообщение INFO должно быть отфильтровано", Level::INFO);
    logger.log("Это сообщение WARNING должно появиться", Level::WARNING);
    logger.log("Это сообщение ERROR должно появиться", Level::ERROR);

    return 0;
}
