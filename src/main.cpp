#include <iostream>
#include <print>
#include <string>
#include <cstdlib>
#include <format>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>

bool pkgjson_exists = std::filesystem::exists("pkg.json");

int main(int argc, char** argv) {
	std::println("{}", pkgjson_exists);
	if (argc >= 2) {
		std::string command = static_cast<std::string>(argv[1]);
		if (command == "gen") {
			// Create pkg.json file
			std::println("Generating...");
			std::ofstream file("pkg.json");
			file << "{\n\t\"packages\": {\n\t\n\t}\n}";
			file.close();
			// Check again
			pkgjson_exists = std::filesystem::exists("pkg.json");
		}
		if (argc >= 3) {
			if (command == "install") {
				std::println("{}", argv[2]);
				// Make the c++pkg_libraries folder and install the repo into that folder
				std::filesystem::create_directories("c++pkg_libraries/repos");
				system(std::format("cd ./c++pkg_libraries/repos && git clone {} && cd ../..", argv[2]).c_str());
				// Add to json
			}
		}
	}
	return 0;
}
