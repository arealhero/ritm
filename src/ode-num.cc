#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <Matrix.h>

constexpr std::size_t N = 5;

const Column<N> y_0 = { 0.0, 3.0, -9.0, -8.0, 0.0 };
const Matrix<N> A = {
       0,    1,    0,   0,   0,
       0,    0,    1,   0,   0,
       0,    0,    0,   1,   0,
       0,    0,    0,   0,   1,
    -243, -405, -270, -90, -15
};

Column<N> f(const Column<N>& y)
{
    auto res = A * y;
    return res;
}

double etalon(double x)
{
    return -(x * std::exp(-3 * x) * (129*x*x*x + 16*x*x - 54*x - 36)) / 12;
}

void print_usage()
{
    std::cout << "usage: ode-num <h>\n";
}

Column<N> get_step(const Column<N>& y, double h)
{
    Column<N> k1, k2, k3, k4;
    k1 = h * f(y);
    k2 = h * f(y + (k1 / 2));
    k3 = h * f(y + (k2 / 2));
    k4 = h * f(y + k3);

    return ((k1 + 2*k2 + 2*k3 + k4) / 6);
}

int main(int argc, const char* argv[])
{
    Column<N> k1, k2, k3, k4;
    Column<N> y, y_next;
    double h;

    if (argc != 2)
    {
        print_usage();
        return EXIT_FAILURE;
    }

    std::stringstream stream(argv[1]);
    stream >> h;

    int precision = 5;
    int k = 4;

    std::ofstream fout("points.csv");
    fout << "x,y (num),y (etalon),diff\n";
    y = y_0;
    for (double x = 0.0; x < 2.0 + h/10; x += h)
    {
        y_next = y + get_step(y, h);

        fout << std::setprecision(2) << std::fixed << x;
        fout << std::setprecision(precision) << std::scientific;

        double y_num = y.at(0);
        double y_etalon = etalon(x);

        fout << ',' << y_num
            << ',' << y_etalon
            << ',' << (y_etalon - y_num) << '\n';

        y = y_next;
    }
    fout.close();

    return EXIT_SUCCESS;
}

