#include <print>
#include <string>
#include <cstdlib>
#include <format>
#include <filesystem>
#include <nlohmann/json.hpp>

bool pkgjson_exists = std::filesystem::exists("pkg.json");

int main(int argc, char** argv) {
	std::println("{}", pkgjson_exists);
	if (argc >= 2) {
		if (argc >= 3) {
			if (static_cast<std::string>(argv[1]) == "install") {
				std::println("{}", argv[2]);
				// Make the c++pkg_libraries folder and install the repo into that folder
				std::filesystem::create_directories("c++pkg_libraries/repos");
				system(std::format("cd ./c++pkg_libraries/repos && git clone {}", argv[2]).c_str());
				// Add to json
			}
		}
	}
	return 0;
}
