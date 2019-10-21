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

#ifndef __MS_LOG_HEADER__
#define __MS_LOG_HEADER__

#include <ostream>

class ILogger {
private:
    std::shared_ptr<char> _msg;

    const int _logger_msg_max_length = 4096;

protected:
    enum LOGGER_LEVEL {
        LOGGER_LEVEL_INFO = 0,
        LOGGER_LEVEL_WARN,
        LOGGER_LEVEL_ERROR
    };
public:
    ILogger() {
        _msg = std::shared_ptr<char>(new char[_logger_msg_max_length]);
    };

    virtual ~ILogger() = default;

public:
    void info(const char *fmt, ...);

    void warn(const char *fmt, ...);

    void error(const char *fmt, ...);

public:
    virtual void print_log(LOGGER_LEVEL level, std::string msg) = 0;
};

class ConsoleLogger : public ILogger {
public:
    ConsoleLogger() = default;

    ~ConsoleLogger() override = default;

public:
    void print_log(LOGGER_LEVEL level, std::string msg) override;
};


class LoggerManager {
public:
    LoggerManager() = default;

    ~LoggerManager() = default;

public:
    static std::shared_ptr<ILogger> get_logger() {
        static std::shared_ptr<ILogger> logger = nullptr;
        if (logger == nullptr) {
            logger = std::shared_ptr<ILogger>(new ConsoleLogger());
        }
        return logger;
    }
};

#define INFO(fmt, ...) LoggerManager::get_logger()->info(fmt, ##__VA_ARGS__)
#define WARN(fmt, ...) LoggerManager::get_logger()->warn(fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...) LoggerManager::get_logger()->error(fmt, ##__VA_ARGS__)
#endif