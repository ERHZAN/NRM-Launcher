#include "parseSubmods.h"

void parseSubmods(std::vector<std::wstring>& arr1, std::vector<std::wstring>& arr2) {
	namespace fs = std::filesystem;

	fs::path path = fs::current_path();
	path += "/Game/mod";
	bool exists = fs::is_directory(path);

	std::wstring tempStr;

	if (exists) {
		for (auto const& elem : fs::directory_iterator(path)) {
			if (elem.path().string().find(".mod") != -1) {
				std::wfstream file;
				file.open(elem, std::ios::in);
				if (file.is_open()) {
					while (getline(file, tempStr)) {
						if (tempStr.find(L"name") == 0) {
							int index = tempStr.find(L"\"");
							std::wstring tmp = tempStr.substr(index);
							int length = tmp.length();
							arr1.push_back(tmp.substr(1, tmp.length() - 2));
						}
						if (tempStr.find(L"path") == 0) {
							int index = tempStr.find(L"\"");
							std::wstring tmp = tempStr.substr(index);
							int length = tmp.length();
							arr2.push_back(tmp.substr(1, tmp.length() - 2));
						}
					}
				}
				file.close();
			}
		}
	}
}