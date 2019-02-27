#include <jni.h>
#include "inc/fmod.hpp"
#include <unistd.h>
#include <android/log.h>
#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);

#define MODE_NORMAL 0
using namespace FMOD;
extern "C"
JNIEXPORT void JNICALL
Java_com_example_user_voicechange_1master_Main2Activity_playSounr(JNIEnv *env, jobject instance,
                                                                  jstring path_jstr, jint type) {
    System *system;
    Sound *sound;
    Channel *channel;
    DSP *dsp;
    //初始化
    System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, NULL);

    const char* path_cstr = env->GetStringUTFChars(path_jstr,NULL);
    //创建声音
    system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);
    switch (type) {
        case MODE_NORMAL:
            //原生播放
            LOGI("%s",path_cstr);
            system->playSound(sound, 0, false, &channel);
            LOGI("%s","fix normal");

            break;
        default:
            break;
    }
    system->update();
    //释放资源
    usleep(5000);
    env->ReleaseStringUTFChars(path_jstr,path_cstr);

    sound->release();
    system->close();
    system->release();
}