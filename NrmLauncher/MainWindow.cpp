#include "MainWindow.h"
#include "parseConfig.h"
#include "parseSubmods.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	// Parse launcher config
	Config cfg;
	parseConfig(cfg);

	// Parse game submods
	std::vector<std::string> submods;
	parseSubmods(submods);
	for (int i = 0; i < submods.size(); i++) {
		std::cout << submods[i] << std::endl;
	}
	std::vector<std::string>* ptr = &submods;

	// Initialize form
	NrmLauncher::MainWindow mWindow(gcnew String(cfg.m_name.c_str()), ptr);
	Application::Run(% mWindow);
	return 0;
}