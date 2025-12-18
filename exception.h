#pragma once

#include <string>
#include <stdexcept>

using namespace std;

// Custom Out of Stock exception
class OutOfStock : public runtime_error {
public:
	OutOfStock(const string& msg) : runtime_error(msg) {}
};