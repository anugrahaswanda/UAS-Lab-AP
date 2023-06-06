#include <iostream>
#include <vector>

//Struktur untuk menyimpan informasi tugas
struct Tugas {
    std::string deskripsi;
    bool selesai;
};

//fungsi untuk menambahkan tugas baru ke dalam daftar
void tambahTugas(std::vector<Tugas>& daftarTugas, const std::string& deskripsi) {
    Tugas tugas;
    tugas.deskripsi = deskripsi;
    tugas.selesai = false;
    daftarTugas.push_back(tugas);
    std::cout << "Tugas berhasil ditambahkan!\n";
}

//fungsi untuk melihat daftar tugas
void lihatTugas(const std::vector<Tugas>& daftarTugas) {
    if (daftarTugas.empty()) {
        std::cout << "Daftar tugas kosong.\n";
    } else {
        std::cout << "Daftar Tugas:\n";
        for (size_t i = 0; i < daftarTugas.size(); ++i) {
            const Tugas& tugas = daftarTugas[i];
            std::cout << "[" << i << "] " << tugas.deskripsi << " - "
                      << (tugas.selesai ? "Selesai" : "Belum Selesai") << "\n";
        }
    }
}

//fungsi untuk menandai tugas sebagai selesai
void tandaiSelesai(std::vector<Tugas>& daftarTugas, size_t indeks) {
    if (indeks < daftarTugas.size()) {
        daftarTugas[indeks].selesai = true;
        std::cout << "Tugas ditandai sebagai selesai berhasil!\n";
    } else {
        std::cout << "Maaf, nomor tidak ditemukan.\n";
    }
}

//fungsi untuk menandai tugas sebagai belum selesai
void tandaiBelumSelesai(std::vector<Tugas>& daftarTugas, size_t indeks) {
    if (indeks < daftarTugas.size()) {
        daftarTugas[indeks].selesai = false;
        std::cout << "Tugas ditandai sebagai belum selesai berhasil!\n";
    } else {
        std::cout << "Maaf, nomor tidak ditemukan.\n";
    }
}

//fungsi untuk menghapus tugas dari daftar
void hapusTugas(std::vector<Tugas>& daftarTugas, size_t indeks) {
    if (indeks < daftarTugas.size()) {
        daftarTugas.erase(daftarTugas.begin() + indeks);
        std::cout << "Tugas berhasil dihapus!\n";
    } else {
        std::cout << "Maaf, nomor tidak ditemukan.\n";
    }
}

int main() {
    std::vector<Tugas> daftarTugas;
    char pilihan;

    do {
        std::cout << "\nMenu Daftar Tugas:\n";
        std::cout << "1. Tambah Tugas\n";
        std::cout << "2. Lihat Tugas\n";
        std::cout << "3. Tandai Tugas Selesai\n";
        std::cout << "4. Tandai Tugas Belum Selesai\n";
        std::cout << "5. Hapus Tugas\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case '1': {
                std::string deskripsi;
                std::cout << "Kamu mau ngapain nih? : ";
                std::cin.ignore();
                std::getline(std::cin, deskripsi);
                tambahTugas(daftarTugas, deskripsi);
                break;
            }
            case '2':
                lihatTugas(daftarTugas);
                break;
            case '3': {
                size_t indeks;
                std::cout << "Tugas yang nomor berapa? : ";
                std::cin >> indeks;
                tandaiSelesai(daftarTugas, indeks);
                break;
            }
            case '4': {
                size_t indeks;
                std::cout << "Tugas yang nomor berapa? : ";
                std::cin >> indeks;
                tandaiBelumSelesai(daftarTugas, indeks);
                break;
            }
            case '5': {
                size_t indeks;
                std::cout << "Tugas yang nomor berapa? : ";
                std::cin >> indeks;
                hapusTugas(daftarTugas, indeks);
                break;
            }
            case '6':
                std::cout << "Keluar dari program...\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != '6');

    return 0;
}
