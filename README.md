## Penjelasan Singkat

Program ini menyelesaikan puzzle **Queens** (LinkedIn Games) menggunakan algoritma **Brute Force (Exhaustive Search)**. Puzzle Queens dimainkan pada board N×N yang dibagi menjadi N region. Tujuannya adalah menempatkan tepat 1 queen di setiap baris, setiap kolom, dan setiap region, dengan syarat tidak ada dua queen yang saling bersentuhan (termasuk diagonal). Program mencoba semua N! kemungkinan permutasi penempatan queen secara murni tanpa heuristik.

## Requirement

- **Compiler**: g++ (MinGW di Windows / GCC di Linux)
- **Standar**: C++17
- Tidak memerlukan library eksternal tambahan

## Cara Kompilasi dan Menjalankan

### Menggunakan Makefile (direkomendasikan)

```bash
make        # kompilasi
make run    # jalankan program
make clean  # hapus hasil kompilasi
```

### Manual

#### Windows
```bash
g++ -std=c++17 -o bin/queens.exe src/input.cpp src/solutions.cpp src/main.cpp
.\bin\queens.exe
```

#### Linux
```bash
g++ -std=c++17 -o bin/queens src/input.cpp src/solutions.cpp src/main.cpp
./bin/queens
```

## Cara Penggunaan

Setelah program berjalan, masukkan **nama file** test case (tanpa path) saat diminta:

```
masukkan nama file input (dari folder test/input/): tc1.txt
```

File input dibaca dari folder `test/input/`. Program akan menampilkan proses pencarian secara live setiap 20 percobaan, lalu menampilkan hasil akhir berupa board dengan posisi queen (ditandai `#`), waktu pencarian (ms), dan jumlah kasus yang ditinjau.

Jika solusi ditemukan, program menawarkan opsi simpan. Masukkan nama file output (tanpa ekstensi):

```
nama file output (akan disimpan di test/output/, tanpa .txt): hasil_tc1
```

Hasil akan tersimpan di `test/output/hasil_tc1.txt`.

## Struktur Folder

```
.
├── bin/            # hasil kompilasi (.exe)
├── doc/            # dokumentasi (penjelasan.txt)
├── src/            # source code
│   ├── input.h
│   ├── input.cpp
│   ├── solutions.h
│   ├── solutions.cpp
│   └── main.cpp
├── test/
│   ├── input/      # file test case input (.txt)
│   └── output/     # file hasil solusi (.txt)
├── Makefile
└── README.md
```

## Author

| NIM | Nama |
| --- | ---- |
| 13524085 | Ariel Cornelius Sitorus |
