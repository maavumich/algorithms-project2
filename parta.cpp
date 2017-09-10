#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <boost/tuple/tuple.hpp>
#include <Eigen/Dense>

#include "gnuplot-iostream/gnuplot-iostream.h"

int main ()
{
	using namespace std::chrono_literals;
	// read in the file

	std::vector<std::pair<Eigen::Vector3d, Eigen::Matrix3d>> states(1);
	while (std::cin >> states.back().first(0)
			>> states.back().first(1)
			>> states.back().first(2)
			>> states.back().second(0, 0)
			>> states.back().second(0, 1)
			>> states.back().second(0, 2)
			>> states.back().second(1, 0)
			>> states.back().second(1, 1)
			>> states.back().second(1, 2)
			>> states.back().second(2, 0)
			>> states.back().second(2, 1)
			>> states.back().second(2, 2)
			)
	{
		states.emplace_back();
	}
	states.pop_back();

	std::cout << states.back().first << std::endl << states.back().second << std::endl << std::endl;
	
	Gnuplot gp;
	gp << "set multiplot layout 1, 2\n";
	gp << "unset key\n";
	// don't mess with code above this line
	// unless you know what you're doing

	for (auto &state: states)
	{
		gp << "set title \"Position\"\n";
		gp << "set parametric\n";
		gp << "set xrange [-10:10]\nset yrange [-10:10]\n";
		gp << "set object 1 ellipse at " << x << "," << y << " size 20,10 angle 40\n";
		gp << "plot 2,2 with points\n";
		gp << "set title \"Angle\"\n";
		gp << "set xrange [0:360]\nset yrange [0:1]\n";
		gp << "set object 1 ellipse at 2,2 size 15,5 angle 30\n";
		gp << "plot 2,2 with points\n";
		std::this_thread::sleep_for(1500ms);
	}

	////////////////////////////////////////////////////////////////////////
	// don't mess with code beneath this line
	// unless you know what you're doing
	gp << "unset multiplot\n";
}
