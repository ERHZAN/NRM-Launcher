#include "parseConfig.h"
#include <windows.h>

void parseConfig(Config& config) {
	std::fstream fileConfig;

	fileConfig.open("launcher.cfg", std::ios::in);

	std::string tempStr;

	bool windowName = false;
	
	if (fileConfig.is_open()) {
		while (getline(fileConfig, tempStr)) {
			if (tempStr.find("WindowName:") != -1) {
				windowName = true;
				continue;
			}
			if (windowName)
				config.m_name = tempStr;

			break;
		}
	}

	fileConfig.close();
}