/*
MIT License

Copyright (c) 2019 ME_Kun_Han

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <sstream>
#include "ms_log.hpp"

void ILogger::info(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    auto size = vsnprintf(_msg.get(), _logger_msg_max_length, fmt, ap);
    va_end(ap);

    return print_log(LOGGER_LEVEL_INFO, std::string(_msg.get(), size));
}

void ILogger::warn(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    auto size = vsnprintf(_msg.get(), _logger_msg_max_length, fmt, ap);
    va_end(ap);
    return print_log(LOGGER_LEVEL_WARN, std::string(_msg.get(), size));
}

void ILogger::error(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    auto size = vsnprintf(_msg.get(), _logger_msg_max_length, fmt, ap);
    va_end(ap);
    return print_log(LOGGER_LEVEL_ERROR, std::string(_msg.get(), size));
}

void ConsoleLogger::print_log(LOGGER_LEVEL level, std::string msg) {
    std::stringstream ss;
    switch (level) {
        case LOGGER_LEVEL_INFO:
            ss << "[info]";
            break;
        case LOGGER_LEVEL_WARN:
            ss << "[warn]";
            break;
        case LOGGER_LEVEL_ERROR:
            ss << "[error]";
            break;
        default:
            assert(false);
    }

    ss << ": " << msg;

    printf("%s\n", ss.str().c_str());
    fflush(stdout);
}