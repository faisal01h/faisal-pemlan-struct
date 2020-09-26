#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Buku {
    char isbn[20];
    char judul[64];
    char penulis[32];
    bool exists;
};

struct Buku buku1;

int menu() {
    int menuInput;
    printf("1 - Tambahkan Buku\n2 - Cari Buku\n0 - Keluar\n> ");
    scanf("%d", &menuInput);
    if(menuInput < 0 || menuInput > 2) return -1;

    return menuInput;
}

bool createBook() {
    printf("Masukkan ISBN           : ");
    scanf(" %[^\n]s", &buku1.isbn);

    printf("Masukkan Judul Buku     : ");
    scanf(" %[^\n]s", &buku1.judul);

    printf("Masukkan Penulis Buku   : ");
    scanf(" %[^\n]s", &buku1.penulis);

    buku1.exists = true;

    return true;
}

bool readBook(char isbn[20]) {
    if(!strcmp(buku1.isbn, isbn)) {
        printf("Buku ditemukan!\n");
        printf("ISBN     : %s\n", buku1.isbn);
        printf("Judul    : %s\n", buku1.judul);
        printf("Penulis  : %s\n\n", buku1.penulis);
    } else return false;

    return true;
}

int main() {
    int userInput;
    bool run = true;
    while(run) {
        userInput = menu();
        
        if(userInput == -1) {
            printf("Input tidak valid!\n\n");
        } else if (userInput == 0) return 0;

        if(userInput == 1) {
            if(createBook() == true) {
                printf("Data buku dengan ISBN %s berhasil ditambahkan! (%s oleh %s)\n\n", buku1.isbn, buku1.judul, buku1.penulis);
            } else {
                printf("Gagal.\n\n");
            }
        
        
        } else if (userInput == 2) {
            printf("Masukkan ISBN: ");
            char isbn[20];
            scanf(" %[^\n]s", &isbn);
            if(readBook(isbn) == false) printf("Buku tidak ditemukan!\n\n");
        
        }
        getch();
        system("cls");

    }

    return 0;
}