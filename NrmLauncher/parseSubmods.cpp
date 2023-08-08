#include "parseSubmods.h"

void parseSubmods(std::vector<std::string>& arr) {
	namespace fs = std::filesystem;

	fs::path path = fs::current_path();
	path += "/Game/submods";
	bool exists = fs::is_directory(path);

	std::string tempStr;

	if (exists) {
		for (auto const& elem : fs::directory_iterator(path)) {
			if (elem.path().string().find(".mod") != -1) {
				std::fstream file;
				file.open(elem, std::ios::in);
				if (file.is_open()) {
					while (getline(file, tempStr)) {
						if (tempStr.find("path") == 0) {
							int index = tempStr.find("\"");
							std::string tmp1 = tempStr.substr(index);
							int length = tmp1.length();
							arr.push_back(tmp1.substr(1, tmp1.length() - 2));
						}
					}
				}
				file.close();
			}
		}
	}
}