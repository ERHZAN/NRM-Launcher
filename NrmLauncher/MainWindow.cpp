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
	std::vector<std::wstring> submodsNames;
	std::vector<std::wstring> submodsPaths;
	std::vector<std::wstring> submodsSelected;
	parseSubmods(submodsNames, submodsPaths);

	std::wstring smdFullArgs;

	// Initialize form
	NrmLauncher::MainWindow mWindow(gcnew String(cfg.m_name.c_str()), submodsNames,
		submodsPaths, submodsSelected, smdFullArgs);
	Application::Run(% mWindow);
	return 0;
}