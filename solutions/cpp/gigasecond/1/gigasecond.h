#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include <boost/date_time.hpp>

namespace gigasecond
{
    boost::posix_time::ptime advance(const boost::posix_time::ptime& time)
    {
        return time + boost::posix_time::seconds(1'000'000'000);
    }
}  // namespace gigasecond

#endif // GIGASECOND_H
