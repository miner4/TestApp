//============================================================================
// Name        : main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"

int main(int argc, char *argv[]) {

	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " --destination DESTINATION SOURCE"
				<< std::endl;
		return 1;
	}
	std::vector<std::string> sources;
	std::string destination;
	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == "--destination") {
			if (i + 1 < argc) { // Make sure we aren't at the end of argv!
				destination = argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
			} else { // Uh-oh, there was no argument to the destination option.
				std::cerr << "--destination option requires one argument."
						<< std::endl;
				return 1;
			}
		} else {
			sources.push_back(argv[i]);
		}
	}

	Bus bus;

	std::cout << "bus fuel capacity: " << bus.getFuelCapacity() << std::endl;
	std::cout << "bus vFunc: " << bus.vFunc() << std::endl;
	bus.pushStuff(2);
	bus.pushStuff(4);
	// Using a for loop with iterator
	for (auto it = std::begin(bus.getV()); it != std::end(bus.getV()); ++it) {
		std::cout << *it << "\n";
	}

	std::ifstream infile("import.csv");
	std::string line;

	while (std::getline(infile, line)) {

		std::cout << line << "\n";
	}
	return 0;
}
