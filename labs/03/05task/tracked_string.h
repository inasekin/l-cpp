//
// Created by Иван Насекин on 08.03.2026.
//

#pragma once

#include <ostream>
#include <string>

class TrackedString {
public:
    TrackedString();
    explicit TrackedString(std::string s);
    explicit TrackedString(const char* s);
    TrackedString(const TrackedString& other);
    ~TrackedString();

    [[nodiscard]] const std::string& value() const { return value_; }

private:
    std::string value_;
    int id_;
    static int counter_;
};

std::ostream& operator<<(std::ostream& os, const TrackedString& ts);
bool operator==(const TrackedString& a, const TrackedString& b);
bool operator!=(const TrackedString& a, const TrackedString& b);
bool operator<(const TrackedString& a, const TrackedString& b);
TrackedString operator+(const TrackedString& a, const TrackedString& b);
