// filename: MyTemplates.h

template <typename T>
T difference (T x, T y)
{
    return (x - y);
}

template <typename T>
double scalar_difference (T x, T y)
{
    return (x.getScalarValue() - y.getScalarValue());
}

template <typename T>
bool equals (T x, T y)
{
    if (x == y)
        return true;
    else
        return false;
}
