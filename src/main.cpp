#include <print>
#include <string>

int main(int argc, char** argv) {
	if (argc >= 2) {
		if (argc >= 3) {
			if (static_cast<std::string>(argv[1]) == "install") {
				std::println("{}", argv[2]);
			}
		}
	}
	return 0;
}
