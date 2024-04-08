#include <iostream>
#include <fstream> //https://cplusplus.com/reference/fstream/fstream/

#include <string>

using namespace std;
#define YELLOW "\033[33m" 
#define RESET "\033[0m"

class LinuxAbout {
public:
	void kernelOS() {
		ifstream os_release("/etc/os-release"); // https://www.freedesktop.org/software/systemd/man/latest/os-release.html
		if (!os_release.is_open()) {
			cerr << "Error\n";
			return;
		}
		string line;
		while (getline(os_release, line)) {
			if (line.find("PRETTY_NAME=") != string::npos) {
				cout << "Operating System: " << line.substr(13) << endl;
				break;
			}
		}
		os_release.close();
	}
	void kernelArchitecture() {
		ifstream arch("/proc/cpuinfo"); //https://stackoverflow.com/questions/51688334/c-why-is-ifstream-get-function-returning-unrecognized-special-characters
		if (!arch.is_open()) {
			cerr << "Error:\n";
			return;
		}
		string line;
		while (getline(arch, line)) { //https://www.codecademy.com/resources/docs/cpp/user-input/getline
			if (line.find("model name") != string::npos) {
				cout << "Architecture: " << line.substr(line.find(":") + 2) << endl;
				break;
			}
		}
		arch.close();
	}
	void kernelVersion() {
		ifstream version("/proc/version");
		if (!version.is_open()) {
			cerr << "Error:\n";
			return;
		}
		string line;
		getline(version, line);
		cout << "Kernel Version: " << line << endl;
		version.close();
	}
};
int main() {
	LinuxAbout kernelInfo;
	cout << YELLOW << " Linux Kernel Information: " << RESET << endl;
	kernelInfo.kernelOS();
	kernelInfo.kernelArchitecture();
	kernelInfo.kernelVersion();
	return 0;
}
//https://github.com/rootAHMED
