#include <print>

int main(int argc, char** argv) {
	if (argc == 2) {
		std::println("{}", argv[1]);
	}
	return 0;
}
