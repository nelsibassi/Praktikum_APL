#include <iostream>
#include <vector>

struct Data {
    std::string name;
    int nomorIDPajak;
};

void printData() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Tambah Data\n";
    std::cout << "2. Lihat Data\n";
    std::cout << "3. Ubah Data\n";
    std::cout << "4. Hapus Data\n";
    std::cout << "5. Keluar\n";
    std::cout << "Pilih menu (1-5): ";
}

int main() {
    std::vector<Data> dataList;
    std::string username, password;
    int pilih, attempts = 0;

    do {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (username != "nelsi" || password != "2309106120") {
            attempts++;
            std::cout << "Username atau password salah. Coba lagi.\n";
        }
        if (attempts == 3) {
            std::cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            return 0;
        }
    } while (username != "nelsi" || password != "2309106120");

    do {
        printData();
        std::cin >> pilih;

        switch (pilih) {
            case 1: {
                Data newData;
                std::cout << "Nama: ";
                std::cin >> newData.name;
                std::cout << "Nomor ID Pajak: ";
                std::cin >> newData.nomorIDPajak;
                dataList.push_back(newData);
                break;
            }
            case 2: {
                std::cout << "\nData Pajak:\n";
                for (const auto& data : dataList) {
                    std::cout << "Nama: " << data.name << ", Nomor ID Pajak: " << data.nomorIDPajak << "\n";
                }
                break;
            }
            case 3: {
                int index;
                std::cout << "Masukkan indeks data yang ingin diubah: ";
                std::cin >> index;
                if (index >= 0 && index < dataList.size()) {
                    std::cout << "Nama baru: ";
                    std::cin >> dataList[index].name;
                    std::cout << "Nomor ID Pajak baru: ";
                    std::cin >> dataList[index].nomorIDPajak;
                } else {
                    std::cout << "Indeks tidak valid.\n";
                }
                break;
            }
            case 4: {
                int index;
                std::cout << "Masukkan indeks data yang ingin dihapus: ";
                std::cin >> index;
                if (index >= 0 && index < dataList.size()) {
                    dataList.erase(dataList.begin() + index);
                } else {
                    std::cout << "Indeks tidak valid.\n";
                }
                break;
            }
            case 5:
                std::cout << "Program berhenti.\n";
                break;
            default:
                std::cout << "Menu tidak valid.\n";
                break;
        }
    } while (pilih != 5);

    return 0;
}
