#pragma once

#include <iostream>
#include <vector>

#include <format>

#include <common/common.hpp>
#include <modes/modes.hpp>

namespace blixt {
    void parseCommand(std::function<void()> quit);
};