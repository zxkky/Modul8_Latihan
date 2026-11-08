# Modul 8 – Latihan Queue (Struktur Data)

Implementasi ADT Queue berbasis **array** (ukuran 5) dalam C++ dengan tiga mekanisme berbeda.

## Struktur Folder

```
modul8/
├── alt1/   # Alternatif 1: head diam, tail bergerak
│   ├── queue.h
│   ├── queue.cpp
│   └── main.cpp
├── alt2/   # Alternatif 2: head bergerak, tail bergerak
│   ├── queue.h
│   ├── queue.cpp
│   └── main.cpp
└── alt3/   # Alternatif 3: head dan tail berputar (circular)
    ├── queue.h
    ├── queue.cpp
    └── main.cpp
```

`queue.h` dan `main.cpp` sama di ketiga folder. Perbedaan hanya ada di `queue.cpp`.

## ADT Queue

```cpp
typedef int infotype;

struct Queue {
    infotype info[5];   // indeks dimulai dari 0
    int head, tail;     // -1 jika queue kosong
};
```

| Primitif | Keterangan |
|---|---|
| `createQueue(Q)` | Membuat queue kosong (`head = tail = -1`) |
| `isEmptyQueue(Q)` | `true` jika queue kosong |
| `isFullQueue(Q)` | `true` jika queue penuh |
| `enqueue(Q, x)` | Menambah elemen `x` di akhir queue |
| `dequeue(Q)` | Mengambil dan menghapus elemen terdepan, mengembalikan nilainya |
| `printInfo(Q)` | Menampilkan `head - tail` dan isi queue |

## Perbedaan Tiga Alternatif

| | Alternatif 1 | Alternatif 2 | Alternatif 3 |
|---|---|---|---|
| Head | Selalu 0 | Maju saat dequeue | Maju melingkar |
| Tail | Maju saat enqueue | Maju saat enqueue | Maju melingkar |
| `dequeue` | Geser semua elemen ke kiri, `tail--` | `head++` | `head = (head + 1) % 5` |
| `enqueue` | `tail++` | `tail++`, geser dulu jika "penuh semu" | `tail = (tail + 1) % 5` |
| `isFullQueue` | `tail == 4` | `head == 0 && tail == 4` | `(tail + 1) % 5 == head` |
| Kelebihan | Sederhana | Dequeue O(1) | Tanpa pergeseran, memori terpakai penuh |
| Kekurangan | Dequeue O(n) | Perlu geser saat penuh semu | Kondisi penuh/kosong lebih rumit |

## Cara Menjalankan

### Terminal (g++)

Masuk ke folder alternatif yang ingin dijalankan, lalu kompilasi dan jalankan:

```bash
cd alt1
g++ main.cpp queue.cpp -o main
./main            # Windows: main.exe
```

Ganti `alt1` dengan `alt2` atau `alt3` untuk alternatif lain.

### Code::Blocks

1. Buat project baru: **File → New → Project → Console application → C++**.
2. Hapus `main.cpp` bawaan, lalu tambahkan `main.cpp`, `queue.cpp`, dan `queue.h` dari salah satu folder alternatif (**Project → Add files...**).
3. Tekan **F9** (Build and Run).

Gunakan satu project per alternatif. Jangan menggabungkan beberapa alternatif dalam satu project karena akan terjadi *multiple definition*.

## Contoh Output

**Alternatif 1**

```
Hello World
----------------------
 H - T 	 | Queue info
----------------------
 -1 - -1 	 | empty queue
 0 - 0 	 | 5
 0 - 1 	 | 5 2
 0 - 2 	 | 5 2 7
 0 - 1 	 | 2 7
 0 - 2 	 | 2 7 4
 0 - 1 	 | 7 4
 0 - 0 	 | 4
```

**Alternatif 2 dan 3** (isi queue sama, kolom H - T berbeda)

```
 -1 - -1 	 | empty queue
 0 - 0 	 | 5
 0 - 1 	 | 5 2
 0 - 2 	 | 5 2 7
 1 - 2 	 | 2 7
 1 - 3 	 | 2 7 4
 2 - 3 	 | 7 4
 3 - 3 	 | 4
```

> Gambar 8-17 pada modul berakhir dengan `empty queue`, sedangkan `main` hanya memanggil `dequeue` tiga kali sehingga tersisa satu elemen (4). Untuk mendapatkan baris terakhir kosong, tambahkan `dequeue(Q); printInfo(Q);` di akhir `main`.

## Catatan

- Nama fungsi mengikuti `main` pada modul: `createQueue` (huruf kecil di awal).
- `enqueue` pada queue penuh menampilkan `Queue penuh`, sedangkan `dequeue` pada queue kosong menampilkan `Queue kosong` dan mengembalikan `-1`.
