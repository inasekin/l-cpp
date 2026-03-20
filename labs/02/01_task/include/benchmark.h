//
// Created by Иван Насекин on 21.02.2026.
//

#pragma once
#include <vector>

void measure_push_back(const std::vector<int> & vec);
void measure_push_front(const std::vector<int>& vec);
void measure_random_insert(const std::vector<int>& vec);
void measure_random_erase(const std::vector<int>& vec);
void measure_random_access(const std::vector<int>& vec);