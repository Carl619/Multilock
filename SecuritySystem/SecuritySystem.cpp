// SecuritySystem.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "interface.h"
#include "locksystem.h"
#include <ctime>
#include <vector>
#include <memory>
const int MAX_NUMBER_SYSTEMS = 100;
const int NUMBER_LOCKS = 5;
using namespace std;
int main()
{
	srand(time(0));
	std::vector<std::shared_ptr<LockSystem>> systems;
	while (systems.size() < MAX_NUMBER_SYSTEMS) {
		bool systemValidated = true;
		std::shared_ptr<LockSystem> sys = std::unique_ptr<LockSystem>(Interface::generateSystem(NUMBER_LOCKS));
		if (sys->init()){
			Interface::showLockSystem(*sys.get());
			systems.push_back(std::move(sys));
		}
	}
	Interface::writeKeyFile("keyfile.txt", systems);
	Interface::writeMultiSafeFile("multisafefile.txt", systems);
	return 0;
}

