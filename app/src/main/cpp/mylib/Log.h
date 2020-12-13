//
// Created by housaibang on 2020-12-11.
//

#ifndef _LOG_H
#define _LOG_H

#include <jni.h>
#include <string>
#include <unistd.h>
#include <stdarg.h>
#include <iostream>
#include <android/log.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define PIPE_BUFSIZE 128
#define LOGPIPE_BUFSIZE 1024

namespace HynLib {

pthread_cond_t cond;
pthread_mutex_t sleep_mutex;
static int log_fd[2];
static int pipRet = -1;
char log_buff[LOGPIPE_BUFSIZE];

int p_printf(const char *fmt, ...) {
    ssize_t ret = -1;
    static char temp[PIPE_BUFSIZE];
    memset(temp, 0, PIPE_BUFSIZE);
    va_list args;
    int rc;

    va_start(args, fmt);
    rc = vsnprintf(temp, PIPE_BUFSIZE, fmt, args);
    va_end(args);

    if (pipRet == 0) ret = write(log_fd[1], temp, rc);
    return static_cast<int>(ret);
}
void pipeSize(){
    static long length = 0;
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "pipesize1 %d",length);
    fcntl(log_fd[1], F_SETFL, O_NONBLOCK);
    while (1){
        ssize_t ret = write(log_fd[1], "1234567890", 10);
        if(ret<0){
            break;
        }
        else length = length + ret;
    }
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "pipesize2 %d",length);
}

void p_sleep(int ms) {
    struct timeval now;
    struct timespec timeout;
    gettimeofday(&now, NULL);
    now.tv_usec += 1000 * ms;
    if (now.tv_usec > 1000000) {
        now.tv_sec += now.tv_usec / 1000000;
        now.tv_usec %= 1000000;
    }

    timeout.tv_sec = now.tv_sec;
    timeout.tv_nsec = now.tv_usec * 1000;
    pthread_cond_timedwait(&cond, &sleep_mutex, &timeout);
}

void* pipeTask(void *args) {
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "read thread start ");
    //pipeSize();
    while (1){
        if(pipRet==0) {
            memset(log_buff, 0, sizeof(log_buff));
            ssize_t ret = read(log_fd[0], log_buff, sizeof(log_buff));
            if(ret > 0) {
                __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "%s", log_buff);
            }
            else p_sleep(10);
        }
        else{
            break;
        }
    }
    return NULL;
}

extern "C" JNIEXPORT void JNICALL
Java_com_myalgorithm_tab_MainActivity_unbindLogPipe(JNIEnv* env, jobject /* this */) {
    if(pipRet == 0){
        pipRet = -1;
        close(log_fd[0]);
        close(log_fd[1]);
    }
}

extern "C" JNIEXPORT jint JNICALL
Java_com_myalgorithm_tab_MainActivity_bindLogPipe(
        JNIEnv* env, jobject /* this */){
    pipRet = pipe(log_fd);
    if(pipRet != 0 ){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "create pipe failed...");
    }
    else{
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "create pipe success...");
        pthread_t thread_p;
        fcntl(log_fd[0], F_SETFL, O_NONBLOCK);
        fcntl(log_fd[1], F_SETFL, O_NONBLOCK);
        pthread_mutex_init(&sleep_mutex, nullptr);
        int pt = pthread_create(&thread_p, NULL, pipeTask, NULL);
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "thread1 %d",pt);
    }
    return pipRet;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_myalgorithm_tab_MainActivity_readMessage(JNIEnv* env, jobject thiz){
    if((pipRet==0)){
        fcntl(log_fd[0], F_SETFL, O_NONBLOCK);
        ssize_t ret = read(log_fd[0], log_buff, sizeof(log_buff));
        //__android_log_print(ANDROID_LOG_VERBOSE, TGA, "read data null %d",ret);
        if(ret ==-1 ) return nullptr;
    }
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "read data");
    return env->NewStringUTF((const char *)log_buff);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_myalgorithm_tab_MainActivity_writeMessage(JNIEnv* env, jobject thiz,jstring message){
    ssize_t ret = -1;
    if(pipRet==0) {
        const char *buff = env->GetStringUTFChars(message, 0);
        ret = write(log_fd[1], buff, strlen(buff));
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "write data %d",strlen(buff));
        env->ReleaseStringUTFChars(message,buff);
    }
    return static_cast<jint>(ret);
}
extern "C" JNIEXPORT jint JNICALL
Java_com_myalgorithm_tab_MainActivity_testPipeSize(JNIEnv* env, jobject thiz){

    return static_cast<jint>(1);
}
}
#endif //_LOG_H
