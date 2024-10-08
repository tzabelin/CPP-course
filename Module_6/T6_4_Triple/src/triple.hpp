/* Add include guards here */

#ifndef AALTO_ELEC_CPP_TRIPLE_CLASS
#define AALTO_ELEC_CPP_TRIPLE_CLASS
#include <iostream>
/**
 * @brief: The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
 template <typename T1, typename T2, typename T3>
class Triple 
{
    public:
    Triple();
    Triple(const T1& first, const T2& second, const T3& third):first_(first), second_(second), third_(third) {}

/* Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */
    const T1& First() const 
    {
        return first_;
    }

    const T2& Second() const 
    {
        return second_;
    }

    const T3& Third() const 
    {
        return third_;
    }

    bool operator==(const Triple& other) const 
    {
        return first_ == other.first_ && second_ == other.second_ && third_ == other.third_;
    }

    bool operator!=(const Triple& other) const 
    {
        return !(*this == other);
    }
    
    private:
    T1 first_;
    T2 second_;
    T3 third_;
};
/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */

template <typename T1, typename T2, typename T3> bool IsHomogenous(const Triple<T1, T2, T3>&) 
{
    return false;
}

template <typename T> bool IsHomogenous(const Triple<T, T, T>&) 
{
    return true;
}

template <typename T1, typename T2, typename T3> std::ostream& operator<<(std::ostream& os, const Triple<T1, T2, T3>& triple) 
{
    os << "[" << triple.First() << ", " << triple.Second() << ", " << triple.Third() << "]";
    return os;
}
/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

/* Remember the endif here to close the header guards */

#endif