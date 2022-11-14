
#ifdef __ANDROID__
// Includes and macros when we are running in android
#include <android/log.h>
#include <chrono>
#include <type_traits>

//    std::chrono::system_clock::rep time_since_epoch(){
//        static_assert(
//                std::is_integral<std::chrono::system_clock::rep>::value,
//                "Representation of ticks isn't an integral value."
//        );

//}
#define LOG_TAG "JNIpart"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__))
#else
#define LOGD(...)
#define LOGE(...)
#endif

#include <cstdint>
#include <time.h> // clock_gettime
#include <jni.h>
#include <string>
#include <stdio.h>


static inline int64_t getTimeMs() {
#ifdef _WIN32
    //skipping the code in windows for now
    return (int64_t)0;
#else
//    struct timespec now;
//    clock_gettime(CLOCK_MONOTONIC, &now);
//    return (int64_t) now.tv_sec * 1000 + now.tv_nsec / 1000000;
//    using namespace std::chrono;
//    milliseconds ms = duration_cast< milliseconds >(
//            system_clock::now().time_since_epoch()
//    );
    auto now = std::chrono::system_clock::now().time_since_epoch();

//    timeval time;
//    gettimeofday(&time, NULL);
//    long millis = (time.tv_sec * 1000) + (time.tv_usec / 1000);
//    return millis;
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
#endif
}

static inline int64_t getTimes() {
#ifdef _WIN32
    //skipping the code in windows for now
    return (int64_t)0;
#else
//    struct timespec now;
//    clock_gettime(CLOCK_MONOTONIC, &now);
//    return (int64_t) now.tv_sec * 1000 + now.tv_nsec / 1000000;
//    using namespace std::chrono;
//    milliseconds ms = duration_cast< milliseconds >(
//            system_clock::now().time_since_epoch()
//    );
    auto now = std::chrono::system_clock::now().time_since_epoch();

//    timeval time;
//    gettimeofday(&time, NULL);
//    long millis = (time.tv_sec * 1000) + (time.tv_usec / 1000);
//    return millis;
    return std::chrono::duration_cast<std::chrono::seconds>(now).count();
#endif
}

static inline int getTimeInterval(int64_t startTime) {
    return int(getTimeMs() - startTime);
}


