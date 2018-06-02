#include "logger.hh"

Logger::Logger(std::ostream& os)
    : os_(os)
{}

Logger& Logger::operator<<(const std::string& str)
{
    os_ << str;
    return *this;
}
