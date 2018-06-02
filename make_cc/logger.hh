#pragma once

#include <iostream>
#include <string>

class Logger
{
public:
    Logger(std::ostream& os);

    Logger& operator<<(const std::string& str);
    
private:
    std::ostream& os_;
};
