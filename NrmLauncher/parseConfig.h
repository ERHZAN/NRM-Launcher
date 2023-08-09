#pragma once

#include <fstream>
#include <filesystem>

struct Config {
	std::wstring m_name;
};

void parseConfig(Config& config);