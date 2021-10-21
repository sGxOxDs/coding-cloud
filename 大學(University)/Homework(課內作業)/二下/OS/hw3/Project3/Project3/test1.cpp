/*
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

class Moniter
{
public:
    Moniter()
    {
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL);
    };

    void acquire()
    {
        if (pthread_mutex_lock(&mutex) != 0)
            pthread_cond_wait(&cond, &mutex);
    };

    void release()
    {
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
    };

    ~Moniter()
    {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    };
private:

    pthread_mutex_t mutex;
    pthread_cond_t cond;
}mlock;

//宣告互斥鎖
pthread_mutex_t lock;

//宣告互斥鎖的屬性
pthread_mutexattr_t attr;

// 子執行緒函數
void* child(void* data) {
    char* str = (char*)data; // 取得輸入資料
    for (int i = 0; i < 5; ++i) {
        //printf("%s\n", str); // 每秒輸出文字
        

        mlock.acquire();
        cout << str << " " << i << endl;
        mlock.release();

        Sleep(900+(rand()%10+1)*20);
    }
    pthread_exit(NULL); // 離開子執行緒
    return NULL;
}

// 主程式
int main() {
    pthread_mutexattr_init(&attr); // 初始化互斥鎖屬性

    // 設置attr屬性為PTHREAD_MUTEX_TIMED_NP，即默認屬性（當一個線程加鎖後，其余請求鎖的線程形成等待隊列，在解鎖後按優先級獲得鎖）
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_TIMED_NP); // 設定互斥鎖屬性的類型

    pthread_mutex_init(&lock, &attr); // 初始化互斥鎖

    srand(10);

    pthread_t t; // 宣告 pthread 變數
    pthread_create(&t, NULL, child, (void*)"1Child"); // 建立子執行緒

    pthread_t t2; // 宣告 pthread 變數
    pthread_create(&t2, NULL, child, (void*)"2Child"); // 建立子執行緒

    pthread_t t3; // 宣告 pthread 變數
    pthread_create(&t3, NULL, child, (void*)"3Child"); // 建立子執行緒

    // 主執行緒工作
    for (int i = 0; i < 5; ++i) {
        //printf("Master\n"); // 每秒輸出文字
        
        mlock.acquire();
        cout << "Master " << i << endl;
        mlock.release();

        Sleep(900 + (rand() % 10 + 1) * 20);
    }
    

    pthread_join(t, NULL); // 等待子執行緒執行完成
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&lock); // 釋放mutex相關資源
    return 0;
}*/
