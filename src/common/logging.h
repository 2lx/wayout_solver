#ifndef LOG_H
#define LOG_H

#ifdef LOGGING
#include <iostream>
#include <iomanip>

#define LOG(M) { std::clog << M; }
#define LOG_FN(M) { M; }
#else
#define LOG(M)
#define LOG_FN(M)
#endif // LOGGING

#endif // LOG_H
