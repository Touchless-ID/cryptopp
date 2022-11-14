
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

#include <jni.h>

#else
#define LOGD(...)
#define LOGE(...)
#endif

