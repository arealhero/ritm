#pragma once

#include <cassert>
#include <array>

template<std::size_t Rows, std::size_t Cols = Rows>
class Matrix
{
public:
    double& at(std::size_t index)
    {
        if constexpr (Rows == 1)
            return at(0, index);
        else if constexpr (Cols == 1)
            return at(index, 0);
        else
            assert(0 && "Cannot use at() with one parameter");
    }

    double& at(std::size_t row, std::size_t col)
    {
        assert(row < Rows && col < Cols);
        return data[row * Cols + col];
    }
    const double& at(std::size_t row, std::size_t col) const
    {
        assert(row < Rows && col < Cols);
        return data[row * Cols + col];
    }

    std::array<double, Rows * Cols> data = {};
};

template<std::size_t Rows>
using Column = Matrix<Rows, 1>;

template<std::size_t Cols>
using Row = Matrix<1, Cols>;


template<std::size_t Rows, std::size_t Cols>
Matrix<Rows, Cols> operator* (double num, const Matrix<Rows, Cols>& mat)
{
    Matrix<Rows, Cols> result;
    for (std::size_t row = 0; row < Rows; ++row)
        for (std::size_t col = 0; col < Cols; ++col)
            result.at(row, col) = num * mat.at(row, col);
    return result;
}
template<std::size_t Rows, std::size_t Cols>
Matrix<Rows, Cols> operator/ (const Matrix<Rows, Cols>& mat, double num)
{
    Matrix<Rows, Cols> result;
    for (std::size_t row = 0; row < Rows; ++row)
        for (std::size_t col = 0; col < Cols; ++col)
            result.at(row, col) = mat.at(row, col) / num;
    return result;
}

template<std::size_t Rows, std::size_t Cols>
Matrix<Rows, Cols> operator+ (const Matrix<Rows, Cols>& lhs, const Matrix<Rows, Cols>& rhs)
{
    Matrix<Rows, Cols> result;
    for (std::size_t row = 0; row < Rows; ++row)
        for (std::size_t col = 0; col < Cols; ++col)
            result.at(row, col) = lhs.at(row, col) + rhs.at(row, col);
    return result;
}

template<std::size_t Rows, std::size_t K, std::size_t Cols>
Matrix<Rows, Cols> operator* (const Matrix<Rows, K>& lhs, const Matrix<K, Cols>& rhs)
{
    Matrix<Rows, Cols> result;
    for (std::size_t row = 0; row < Rows; ++row)
        for (std::size_t col = 0; col < Cols; ++col)
            for (std::size_t k = 0; k < K; ++k)
                result.at(row, col) += lhs.at(row, k) * rhs.at(k, col);
    return result;
}

