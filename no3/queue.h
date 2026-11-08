#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
using namespace std;

#define MAX_QUEUE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE]; // index array dimulai dari 0
    int head;                 // -1 jika queue kosong
    int tail;                 // -1 jika queue kosong
};

/* I.S. sembarang
   F.S. terbentuk queue kosong (head = -1, tail = -1) */
void createQueue(Queue &Q);

/* mengembalikan true jika queue kosong */
bool isEmptyQueue(Queue Q);

/* mengembalikan true jika queue penuh */
bool isFullQueue(Queue Q);

/* I.S. queue mungkin kosong, tidak penuh
   F.S. x ditambahkan pada akhir queue */
void enqueue(Queue &Q, infotype x);

/* I.S. queue tidak kosong
   F.S. mengembalikan elemen paling depan, elemen tersebut dihapus dari queue */
infotype dequeue(Queue &Q);

/* I.S. queue mungkin kosong
   F.S. menampilkan head, tail, dan isi queue */
void printInfo(Queue Q);

#endif
