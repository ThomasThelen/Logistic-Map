#include "stdafx.h"
#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::iota;

FILE *pipe = _popen("gnuplot -persist", "w");

class LogisticMap
{
public:
	LogisticMap(int, double, int);
	void ComputeX();
	double GetX(int pos) { return x.at(pos); }
	double GetY(int pos) { return y.at(pos); }
	int Size() { return max_value;  }
	friend void Plot(LogisticMap);

protected:
	vector<double> x, y;
	int max_value, a;
	double initial_x;
};

void LogisticMap::ComputeX()
{
	for (int i = 1; i < y.size(); ++i)
		x.push_back((x.at(i-1)*a)*(1-x.at(i-1)));
}

LogisticMap::LogisticMap(int max, double x0, int parameter) : max_value(max), initial_x(x0), a(parameter)
{
	y.resize(max_value);
	x.push_back(initial_x);
	iota(y.begin(), y.end(), 0);
}

void Plot(LogisticMap Logistic)
{
	extern FILE *pipe;
	fprintf(pipe, "set term win\n");
	fprintf(pipe, "set title ''\n");
	fprintf(pipe, "set xlabel 'y'\n");
	fprintf(pipe, "set ylabel 'x'\n");
	fprintf(pipe, "plot '-' with lines title 'Logistic Map'\n");

	for (int i = 0; i < Logistic.Size() ; ++i)
	{
		fprintf(pipe, "%f, %f\n", Logistic.GetY(i), Logistic.GetX(i));
	}
	_pclose(pipe);
}

int main()
{
	LogisticMap *LMap = new LogisticMap(100, 0.1, 3); // The number of y values to compute, intial x, and a

	LMap->ComputeX();
	Plot(*LMap);
    return 0;
}
