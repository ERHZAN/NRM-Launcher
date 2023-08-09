#include "MainWindow.h"

cli::array<System::Object^>^ NrmLauncher::MainWindow::getSubmodsNames() {
	std::vector<std::wstring> tmpVector = getVector();
	cli::array<System::Object^>^ arr = gcnew cli::array<System::Object^>(tmpVector.size());

	for (int i = 0; i < tmpVector.size(); i++) {
		arr[i] = gcnew String(tmpVector[i].c_str());
	}

	return arr;
}

void NrmLauncher::MainWindow::pushSelectedSubmod(std::wstring str) {
	m_submodsSelected.push_back(str);
}

void NrmLauncher::MainWindow::calcCmdArgs() {
	std::vector<std::wstring>& temp = getSubmodsSelectedVector();

	std::wstring& tmpStr = getCmdArgsStr();
	for (const auto& elem : temp) {
		tmpStr += L" -mod=";
		tmpStr += elem;
		tmpStr += L".mod";
	}
}

void NrmLauncher::MainWindow::startGame(LPCTSTR lpApplicationName) {
	const std::vector<std::wstring>& tmp1 = getSubmodsPathsVector();
	std::vector<std::wstring>& tmp2 = getSubmodsSelectedVector();

	for (int i = 0; i < this->checkedListBox1->Items->Count; i++) {
		if (this->checkedListBox1->GetItemChecked(i)) {
			pushSelectedSubmod(tmp1[i]);
		}
	}

	// -mod=submod/somemod.mod
	auto currentPath = std::filesystem::current_path();
	currentPath += "/Game";
	std::filesystem::current_path(currentPath);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	//std::cout << "test1" << std::endl;
	calcCmdArgs();
	//std::cout << "test2" << std::endl;
	std::wstring tempStr = getCmdArgsStr();
	//std::cout << "test3" << std::endl;

	CreateProcess(lpApplicationName,   // the path
		tempStr.data(),			// Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	exit(0);
}