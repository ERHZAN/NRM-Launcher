#pragma once

#include <fstream>
#include <filesystem>

struct Config {
	std::string m_name;
};

void parseConfig(Config& config);