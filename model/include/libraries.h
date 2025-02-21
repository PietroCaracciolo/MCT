// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

/**
 * This header centralizes the inclusion of all external libraries, providing a
 * single reference point for managing dependencies. By updating this file, you
 * ensure consistency across the project. It is included in helpers.h, which, in
 * turn, propagates the dependencies to all other headers.
 */

#ifndef LIBRARIES_HEADER_H
#define LIBRARIES_HEADER_H

/**example of external libraries*/
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <random>

/**example of alias*/
using json = nlohmann::json;

#endif // LIBRARIES_HEADER_H
