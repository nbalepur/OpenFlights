#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include "RouteGraph.h"
#include "Utility.h"
#include "AirportList.hpp"
#include "MapImage.h"
#include "dijkstra.hpp"

int main(int argc, const char * argv[]) {

	/* ensures valid arguments are pssed */
	if (argc != 7) {
		std::cout << "------------------" << std::endl;
		std::cout << "ERROR: Please pass in the following arguments" << std::endl;
		std::cout << "Argument 1: Airport Dataset File Location" << std::endl;
		std::cout << "Argument 2: Routes Dataset File Location" << std::endl;
		std::cout << "Argument 3: Airport Source" << std::endl;
		std::cout << "Argument 4: Airport Destination" << std::endl;
		std::cout << "Argument 5: Image Destination File Name (must end in .png)" << std::endl;
		std::cout << "Argument 6: Image Destination File Name (must end in .gif)" << std::endl;
		std::cout << "------------------\nPlease make the above changes and run again" << std::endl;
		return -1;
	}

	/* console output to verify inputs */
	std::cout << "------------------\nAttempting to find the shorest path between Airport " << argv[3] << " and Airport " << argv[4] << "\n------------------" << std::endl;

	/* create the map */
	std::cout << "Creating the map..." << std::endl;
	MapImage map(argv[1], argv[2]);

	/* find the shortest path */
	std::cout << "Finding the shortest path..." << std::endl;
	map.drawShortestPath(argv[3], argv[4], argv[5]);

	/* export the files */
	std::cout << "Exporting the GIF..." << std::endl;
	map.playAnimation(argv[6]);

	/* verify success output */
	std::cout << "------------------\nSuccess!\nYou can view the full path at results/" << argv[5] << " and the path animation at results/" << argv[6] << std::endl;
	return 0;
};