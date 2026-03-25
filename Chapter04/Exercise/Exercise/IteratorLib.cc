#include <iterator>

#include "IteratorLib.h"

namespace mystd
{
    void advance(It &it, DifferenceType n)
    {
        it += n;
    }

    DifferenceType distance(It first, It last)
    {
        return last - first;
    }

    It next(It it, DifferenceType n)
    {
        return it + n;
    }

    It prev(It it, DifferenceType n)
    {
        return it - n;
    }
}
