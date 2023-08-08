#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();


	const char* windowText {"<Victoria 2 HoD(v3.04)> <New Realism mod (v1.25.4)> <Checksum (GJBI)>"};
	// gcnew String(temp.c_str())

	NrmLauncher::MainWindow mWindow(gcnew String(windowText));

	Application::Run(% mWindow);

	return 0;
}