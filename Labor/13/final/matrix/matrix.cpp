#include <iostream>

template <class LhsDerived, class RhsDerived>
class MatrixSum;

template <class Derived>
class MatrixBase
{
public:
    const Derived &derived()
    {
        return static_cast<const Derived &>(*this);
    }

    const Derived &derived() const
    {
        return static_cast<const Derived &>(*this);
    }

    unsigned rows() const
    {
        return derived().rows();
    }
    unsigned cols() const
    {
        return derived().cols();
    }
    double operator()(unsigned row, unsigned col) const
    {
        return derived()(row, col);
    }

    void print(std::ostream &os)
    {
        for (unsigned i = 0; i < rows(); i++)
        {
            for (unsigned j = 0; j < cols(); j++)
            {
                os << (*this)(i, j) << " ";
            }
            os << std::endl;
        }
    }

    template <class RhsDerived>
    MatrixSum<Derived, RhsDerived> operator+(const MatrixBase<RhsDerived> &rhs);
};

template <class LhsDerived, class RhsDerived>
class MatrixSum : public MatrixBase<MatrixSum<LhsDerived, RhsDerived>>
{
public:
    MatrixSum(const LhsDerived &lhs, const RhsDerived &rhs) : lhs(lhs), rhs(rhs) {}

    unsigned rows() { return lhs.rows(); }
    unsigned cols() { return rhs.cols(); }
    double operator()(unsigned row, unsigned col)
    {
        return lhs(row, col) + rhs(row, col);
    }

private:
    LhsDerived const &lhs;
    RhsDerived const &rhs;
};

template<class Derived>
template <class RhsDerived>
MatrixSum<Derived, RhsDerived> MatrixBase<Derived>::operator+(const MatrixBase<RhsDerived> &rhs)
{
    return MatrixSum<Derived, RhsDerived>(derived(), rhs.derived());
}

template <unsigned Rows, unsigned Cols>
class Matrix : public MatrixBase<Matrix<Rows, Cols>>
{
public:
    unsigned rows() const { return Rows; }
    unsigned cols() const { return Cols; }
    double operator()(unsigned row, unsigned col) const
    {
        return elements[row][col];
    }

private:
    double elements[Rows][Cols];
};

int main(int argc, char const *argv[])
{
    Matrix<4, 4> m1, m2;
    double d = (m1 + m2)(3, 5);

    MatrixSum<Matrix<4, 4>, Matrix<4, 4>> m3(m1, m2);

    m3.print(std::cout);
    return 0;
}
