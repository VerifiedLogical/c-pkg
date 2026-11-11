#include <iostream>
#include <print>
#include <string>
#include <cstdlib>
#include <format>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>

using namespace nlohmann;

bool pkgjson_exists = std::filesystem::exists("pkg.json");
json pkgjson;


int main(int argc, char** argv) {
	if (pkgjson_exists == true) {
		pkgjson = json::parse(std::ifstream{"pkg.json"});
	}
	std::println("{}", pkgjson_exists);
	if (argc >= 2) {
		std::string command = static_cast<std::string>(argv[1]);
		if (command == "gen") {
			// Create pkg.json file
			std::println("Generating...");
			std::ofstream file("pkg.json");
			file << "{\n\t\"packages\": [\n\t\n\t]\n}";
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
				if (pkgjson_exists == true) {
					// Continue
					pkgjson["packages"].push_back(argv[2]);
					
					std::ofstream json_file("pkg.json", std::ios::trunc);

					json_file << pkgjson.dump(4);

					json_file.close();
					
				} else {
					std::runtime_error("pkg.json doesn't exist! Run \033[38;2;0;255;0mc++pkg gen\033[0m");
				}
			}
		}
	}
	return 0;
}
