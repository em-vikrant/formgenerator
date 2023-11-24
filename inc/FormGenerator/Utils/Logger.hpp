/* File: Logger.hpp
 * Header file for logging mechanisms.
 */

#ifndef LOGGER_H
#define LOGGER_H

/* STD includes. */
#include <cstdio>
#include <string>


/* Brief: Enumeration denoting log levels supported. */
enum LogLevel
{
    INFO = 0,
    WARNING,
    ERROR,

    LOG_LEVEL_CNT
};

const LogLevel defaultLogLevel = LogLevel::INFO;        /*! Default log level. */
const std::string logLevels[LogLevel::LOG_LEVEL_CNT] =  /*! String values for each log level. */
{
    "INFO",
    "WARN",
    "ERR"
};

/* Functions to support logging. */
template <typename T>
T Argument(T value) noexcept
{
    return value;
}

template <typename T>
T const * Argument(std::basic_string<T> const & value) noexcept
{
    return value.c_str();
}                                                                                                   

template <typename ... Args>
void LOG(char const * const format,
    Args const & ... args) noexcept
{
    printf("[%s] ", Argument(logLevels[defaultLogLevel]));
    printf(format, Argument(args) ...);
}

template <typename ... Args>
void LOG(const LogLevel logLevel,
    char const * const format,
    Args const & ... args) noexcept
{
    printf("[%s] ", Argument(logLevels[logLevel]));
    printf(format, Argument(args) ...);
}

inline void LOG(char const * const format) noexcept
{
    printf("[%s] %s", Argument(logLevels[defaultLogLevel]), format);
}

inline void LOG(const LogLevel logLevel, char const * const format) noexcept
{
    printf("[%s] %s", Argument(logLevels[logLevel]), format);
}

inline void LOG(wchar_t const * const format) noexcept
{
    printf("[%s] %ls", Argument(logLevels[defaultLogLevel]), format);
}

inline void LOG(const LogLevel logLevel, wchar_t const * const format) noexcept
{
    printf("[%s] %ls", Argument(logLevels[logLevel]), format);
}

#endif // LOGGER_H

