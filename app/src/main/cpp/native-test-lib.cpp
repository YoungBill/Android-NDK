#include <jni.h>
#include <string>

static void callShow(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);
    // TODO
    jclass myclass = env->FindClass("baina/android/com/hellondk/Test");
    jmethodID mid = env->GetMethodID(myclass, "show", "(Ljava/lang/String;)V");
    env->CallVoidMethod(instance, mid, msg_);
    env->ReleaseStringUTFChars(msg_, msg);
}

static void callToastShow(JNIEnv *env, jobject instance, jobject context,
                          jstring msg_) {
    // TODO
    jclass tclss = env->FindClass("android/widget/Toast");
    jmethodID mid = env->GetStaticMethodID(tclss, "makeText",
                                           "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
    jobject job = env->CallStaticObjectMethod(tclss, mid, context, msg_);
    jmethodID showId = env->GetMethodID(tclss, "show", "()V");
    env->CallVoidMethod(job, showId, context, msg_);
}

/**
* Table of methods associated with a single class.
*/
static JNINativeMethod gMethods[] = {
        {"callToastShow", "(Landroid/content/Context;Ljava/lang/String;)V", (void *) callToastShow},
        {"callShow",      "(Ljava/lang/String;)V",                          (void *) callShow},
};
static const char *const classPathName = "baina/android/com/hellondk/Test";

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    printf("call JNI_OnLoad");
    JNIEnv *env = NULL;
    jclass clazz;
    //获取JNI环境对象
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return JNI_ERR;
    }
    //注册本地方法.Load 目标类
    clazz = env->FindClass(classPathName);
    if (clazz == NULL) {
        printf("call JNI_OnLoad clazz==NULL");
        return JNI_ERR;
    }
    //注册本地native方法
    if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) < 0) {
        printf("call JNI_OnLoad RegisterNatives failed");
        return JNI_ERR;
    }

    /* success -- return valid version number */
    return JNI_VERSION_1_4;
}