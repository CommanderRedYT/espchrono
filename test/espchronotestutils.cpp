#include "espchronotestutils.h"

using namespace std::chrono_literals;
using namespace date;

const espchrono::time_zone testTimeZone{.offset=60min, .dayLightSavingMode=espchrono::DayLightSavingMode::EuropeanSummerTime};

espchrono::millis_clock::time_point wallClock{};

namespace QTest {
template<>
char *toString(const espchrono::DateTime &dateTime)
{
    return ::QTest::toString(espchrono::toString(dateTime));
}

template<>
char *toString(const espchrono::LocalDateTime &dateTime)
{
    return ::QTest::toString(espchrono::toString(dateTime));
}

template<>
char *toString(const espchrono::utc_clock::time_point &ts)
{
    return ::QTest::toString(espchrono::toDateTime(ts));
}

template<>
char *toString(const espchrono::local_clock::time_point &ts)
{
    return ::QTest::toString(espchrono::toDateTime(ts));
}

template<>
char *toString(const espchrono::seconds &val)
{
    return ::QTest::toString(espchrono::toDaypointString(val));
}

template<>
char *toString(const std::optional<espchrono::seconds> &val)
{
    return val ? ::QTest::toString(*val) : ::QTest::toString("(invalid)");
}
} // namespace QTest

// stub implementation to make unit tests happy
auto espchrono::millis_clock::now() noexcept -> time_point
{
    return wallClock;
}
