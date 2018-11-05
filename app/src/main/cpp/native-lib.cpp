#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_baina_android_com_hellondk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}