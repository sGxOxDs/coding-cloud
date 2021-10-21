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

//�ŧi������
pthread_mutex_t lock;

//�ŧi�����ꪺ�ݩ�
pthread_mutexattr_t attr;

// �l��������
void* child(void* data) {
    char* str = (char*)data; // ���o��J���
    for (int i = 0; i < 5; ++i) {
        //printf("%s\n", str); // �C���X��r
        

        mlock.acquire();
        cout << str << " " << i << endl;
        mlock.release();

        Sleep(900+(rand()%10+1)*20);
    }
    pthread_exit(NULL); // ���}�l�����
    return NULL;
}

// �D�{��
int main() {
    pthread_mutexattr_init(&attr); // ��l�Ƥ������ݩ�

    // �]�mattr�ݩʬ�PTHREAD_MUTEX_TIMED_NP�A�Y�q�{�ݩʡ]��@�ӽu�{�[���A��E�ШD�ꪺ�u�{�Φ����ݶ��C�A�b�������u������o��^
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_TIMED_NP); // �]�w�������ݩʪ�����

    pthread_mutex_init(&lock, &attr); // ��l�Ƥ�����

    srand(10);

    pthread_t t; // �ŧi pthread �ܼ�
    pthread_create(&t, NULL, child, (void*)"1Child"); // �إߤl�����

    pthread_t t2; // �ŧi pthread �ܼ�
    pthread_create(&t2, NULL, child, (void*)"2Child"); // �إߤl�����

    pthread_t t3; // �ŧi pthread �ܼ�
    pthread_create(&t3, NULL, child, (void*)"3Child"); // �إߤl�����

    // �D������u�@
    for (int i = 0; i < 5; ++i) {
        //printf("Master\n"); // �C���X��r
        
        mlock.acquire();
        cout << "Master " << i << endl;
        mlock.release();

        Sleep(900 + (rand() % 10 + 1) * 20);
    }
    

    pthread_join(t, NULL); // ���ݤl��������槹��
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&lock); // ����mutex�����귽
    return 0;
}*/
