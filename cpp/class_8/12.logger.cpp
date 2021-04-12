/*************************************************************************
	> File Name: 12.logger.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 15时28分44秒
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include <mutex>
#include "thread_pool.h"

#define LOG(level) ls::Logger::LoggerStream(level, __FILE__, __LINE__, ls::ls_log)
#define LOG_INFO LOG(ls::LogLevel::INFO)
#define LOG_WARNING LOG(ls::LogLevel::WARNING)
#define LOG_DEBUG LOG(ls::LogLevel::DEBUG)
#define LOG_ERROR LOG(ls::LogLevel::ERROR)
#define LOG_FATAL LOG(ls::LogLevel::FATAL)
#define SET_LEVEL(level) ls::ls_log.set_level(level)

namespace ls {

    class LogLevel {
    public :
        static const int INFO;
        static const int WARNING;
        static const int DEBUG;
        static const int ERROR;
        static const int FATAL;
    };
    const int LogLevel::INFO = 1;
    const int LogLevel::WARNING = 2;
    const int LogLevel::DEBUG = 3;
    const int LogLevel::ERROR = 4;
    const int LogLevel::FATAL = 5;

    static std::map<int, std::string> LevelString = {
        {LogLevel::INFO, "INFO"},
        {LogLevel::WARNING, "WARNING"},
        {LogLevel::DEBUG, "DEBUG"},
        {LogLevel::ERROR, "ERROR"},
        {LogLevel::FATAL, "FATAL"}
    };

    class Logger {
    public : 
        Logger() : LOG_LEVEL(LogLevel::INFO) {}
        class LoggerStream : public std::ostringstream {
        public :
            LoggerStream(int level, const char *file_name, int line_no, Logger &raw_log) : line_no(line_no), level(level), raw_log(raw_log){
                std::ostringstream &now = *this;
                now << "[" << file_name << " : " << LevelString[level] << "]";
            }
            ~LoggerStream() {
                if (level  < raw_log.LOG_LEVEL) return ; 
                std::unique_lock<std::mutex> lock(raw_log.m_mutex);
                std::cout << this->str() << " (" << line_no << ") " << std::endl;
            }

        private :
            int line_no, level;
            Logger &raw_log;
        };
        void set_level(int level) {this->LOG_LEVEL = level;}
        int LOG_LEVEL;
        std::mutex m_mutex;
    };
    Logger ls_log;

}

void func(int a, int b, int c) {
    LOG_INFO << a << " " << b << " " << c;
    return ;
}

int main() {
    std::ostringstream s;
    s << "hello world" << " " << "123" << std::endl;
    std::cout << s.str() << std::endl;

    ls::ThreadPool tp;
    for (int i = 0; i < 100; i++) {
        tp.addOneTask(func, i, 2 * i, 3 * i);
    }
    tp.stop();

    SET_LEVEL(ls::LogLevel::DEBUG);
    LOG_INFO << "hello world" << " " << 123 << " " << 12.45;
    LOG_WARNING << "hello world" << " " << 123 << " " << 12.45;
    LOG_DEBUG << "hello world" << " " << 123 << " " << 12.45;
    LOG_ERROR << "hello world" << " " << 123 << " " << 12.45;
    LOG_FATAL << "hello world" << " " << 123 << " " << 12.45;
    return 0;
}
