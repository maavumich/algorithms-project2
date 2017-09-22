#include <iostream>
#include <vector>
#include <Eigen/Dense>

Eigen::Vector3d getEllipseParams(const Eigen::Matrix3d &covar);

int main ()
{
	using namespace std;
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

	for (auto &state: states)
	{
		cout << "set multiplot layout 1, 2\n";
		cout << "unset key\n";

		double x = state.first(0);
		double y = state.first(1);
		double theta = state.first(2);
		Eigen::Vector3d ellipseInfo = getEllipseParams(state.second);
		double semimajor = ellipseInfo(0);
		double semiminor = ellipseInfo(1);
		double angle = ellipseInfo(2);
		cout << "set title \"Position\"\n";
		cout << "set parametric\n";
		cout << "set xrange [-10:10]\nset yrange [-10:10]\n";
		cout << "set object 1 ellipse at " << x << "," << y << " size " << semimajor << "," << semiminor << " angle " << angle << "\n";
		cout << "plot " << x << "," << y << " with points\n";
		cout << "set title \"Angle\"\n";
		cout << "set xrange [0:360]\nset yrange [0:1]\n";
		cout << "set object 1 ellipse at 180,.5 size 15,5 angle 30\n";
		cout << "plot 180,.5 with points\n";
		cout << "pause 1\n";

		cout << "unset multiplot\n" << endl;
		cout << "clear\n";
	}
}

/**
 * Your task is to write a function that, given the covariance matrix of the
 * state, output the length of the semimajor and semiminor axes, as well as
 * the angle of the ellipse (TODO degrees or rads?)
 *
 * Format:
 *
 * output(0) = semimajor axis length
 * output(1) = semiminor axis length
 * output(2) = angle of ellipse
 */
Eigen::Vector3d getEllipseParams(const Eigen::Matrix3d &covar)
{
	Eigen::Vector3d result;
	result(0) = 20;
	result(1) = 30;
	result(2) = 40;

	// YOUR CODE HERE

	return result;
}

