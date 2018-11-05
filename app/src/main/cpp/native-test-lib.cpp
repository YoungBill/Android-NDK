#include <jni.h>
#include <string>

extern "C"
JNIEXPORT void JNICALL
Java_baina_android_com_hellondk_Test_callShow(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);
    // TODO
    jclass myclass = env->FindClass("baina/android/com/hellondk/Test");
    jmethodID mid = env->GetMethodID(myclass, "show", "(Ljava/lang/String;)V");
    env->CallVoidMethod(instance, mid, msg_);
    env->ReleaseStringUTFChars(msg_, msg);
}
extern "C"
JNIEXPORT void JNICALL
Java_baina_android_com_hellondk_Test_callToastShow(JNIEnv *env, jobject instance, jobject context,
                                                   jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);
    // TODO
    jclass tclss = env->FindClass("android/widget/Toast");
    jmethodID mid = env->GetStaticMethodID(tclss, "makeText",
                                           "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
    jobject job = env->CallStaticObjectMethod(tclss, mid, context, msg_);
    jmethodID showId = env->GetMethodID(tclss, "show", "()V");
    env->CallVoidMethod(job, showId, context, msg_);
    env->ReleaseStringUTFChars(msg_, msg);
}