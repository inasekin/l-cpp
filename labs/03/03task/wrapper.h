//
// Created by Иван Насекин on 08.03.2026.
//

#pragma once

#include "tracked_string.h"

#include <string>

class Wrapper {
public:
    Wrapper(const std::string& s);

private:
    TrackedString str_;
};
