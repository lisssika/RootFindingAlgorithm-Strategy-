#include "Solver.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <utility>

#include "Bisection.h"

int main()
{
	std::vector<double> a;
	std::vector<double> b;
	for (int i = 0; i < 100; i++)
	{
		a.push_back(-5 + i * 0.1);
		b.push_back(sin(-5 + i * 0.1));
	}
	std::unique_ptr<IRootFindingAlgorithm<double, double>> bisection = std::make_unique<Bisection>(); //  (new Bisection);
	//Secant* secant = new(Secant );
	//Newton* newton = new(Newton );
	//Solver<double, double> solver_(std::make_unique<Bisection>());
	const Solver<double, double> solver(std::move(bisection));
	try
	{
		const ParabolaWOffset f0;
		std::cout << solver(f0, -1, -10, 0.001) << '\n';
	}
	catch (std::runtime_error& error)
	{
		std::cout << error.what();
	}

	return 0;
}
