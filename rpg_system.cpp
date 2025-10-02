#include <iostream>
using namespace std;

struct Statistics{
    int level;
    int HP;
    int attack;
    int defense;
};

struct Character{
    Statistics baseStats;
    Statistics currentStats;
    string name;
    string role;
    string weapon;
    string specialItem;
};

struct Weapon{
    string weaponName;
    int addAttack;
    int addDefense;
    int addHP;
};

void buatKarakter(int &charCount, int MAX_CHAR, Character chara[]){
    if (charCount >= MAX_CHAR){
        cout << "Jumlah karakter telah mencapai batas maksimal\n";
    }
    else{
        cin.ignore();
        Character newChar;
        cout << "Masukkan nama karakter: ";
        getline(cin, newChar.name);
        cout << "Masukkan role karakter (DPS/Marksman/Sustain): ";
        getline(cin, newChar.role);

        while(newChar.role != "DPS" && newChar.role != "dps" && newChar.role != "Dps" && newChar.role != "Marksman" && newChar.role != "marksman" && newChar.role != "Sustain" && newChar.role != "sustain"){
            cout << "Role tidak valid. Masukkan role karakter (DPS/Marksman/Sustain): ";
            getline(cin, newChar.role);
        }

        if(newChar.role == "DPS" || newChar.role == "dps" || newChar.role == "Dps"){
            //newChar = {{1, 150, 80, 50}, newChar.baseStats, newChar.name, "Marksman", "Wooden Bow", "None"};
            newChar.baseStats = {1, 150, 80, 50};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "DPS";
            newChar.weapon = "Basic Sword";
            newChar.specialItem = "None";

        }
        else if(newChar.role == "Marksman" || newChar.role == "marksman"){
            //newChar = {{1, 120, 70, 50}, newChar.baseStats, newChar.name, "Marksman", "Wooden Bow", "None"};
            newChar.baseStats = {1, 120, 70, 50};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "Marksman";
            newChar.weapon = "Wooden Bow";
            newChar.specialItem = "None";
        }
        else if(newChar.role == "Sustain" || newChar.role == "sustain"){
            //newChar = {{1, 200, 50, 90},newChar.baseStats, newChar.name, "Sustain", "Basic Shield", "None"};
            newChar.baseStats = {1, 200, 50, 90};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "Sustain";
            newChar.weapon = "Basic Shield";
            newChar.specialItem = "None";
        }
        chara[charCount] = newChar;
        charCount++;
        cout << "Karakter telah berhasil dibuat!\n";
    }
}

void listKarakter(int charCount, Character chara[]){
    if(charCount == 0){
        cout << "Kamu belum memiliki karakter\n";
        return;
    }
    for(int i = 0; i < charCount; i++){
        cout << i+1 << ". Nama Karakter : " << chara[i].name << '\n';
        cout << " Role : " << chara[i].role << '\n';
        cout << " Level : " << chara[i].currentStats.level << '\n';
        cout << " Attack : " << chara[i].currentStats.attack << '\n';
        cout << " HP : " << chara[i].currentStats.HP << '\n';
        cout << " Defense : " << chara[i].currentStats.defense << '\n';
        cout << " Weapon : " << chara[i].weapon << '\n';
        cout << " Special Item : " << chara[i].specialItem << "\n\n";
    }
}

int toko(int &uang, int charCount, string item[], int harga[], int totalItem){
    int beli;
    cout << "Uangmu: " << uang << '\n';
    if(charCount == 0){
        cout << "Kamu harus membuat karakter terlebih dahulu sebelum masuk ke toko\n";
        return 0;
    }
    do{
        cout << "Selamat datang di toko!\n";
        cout << "Gunakan uangmu untuk membeli item\n";
        cout << "Daftar Item:\n";
        for(int i = 0; i < totalItem; i++){
            cout << i+1 << ". " << item[i] << " - " << harga[i] << '\n';
        }
        cout << "Masukkan nomor item yang ingin dibeli (0 untuk keluar): ";
        cin >> beli;
        if(beli < 0 || beli > 13){
            cout << "Masukkan nomor item yang valid!\n";
        }
        else if(beli != 0){
            if(uang < harga[beli-1]){
                cout << "Uangmu tidak cukup untuk membeli item ini\n";
                continue;
            }
            else{
                cout << "Kamu telah membeli " << item[beli-1] << " seharga " << harga[beli-1] << '\n';
                uang -= harga[beli-1];
                cout << "Sisa uangmu: " << uang << "\n\n";
                break;
            }
        }
    }while(beli != 0);
    return beli-1;
}

void inventory(string item[], int purchasedItem, string inventoryList[], int invertoryCount, int totalItem, int jumlahItemInventory[]){
    cout << "Item kamu: \n";
    for(int i = 0; i < totalItem; i++){
        cout << i+1 << ". " << item[i] << " - "<< "Kamu punya : " << jumlahItemInventory[i] <<'\n';
    }
}

void equipWeapon(Character &chara, Weapon weapon){
    chara.weapon = weapon.weaponName;
    chara.currentStats = chara.baseStats;
    chara.currentStats.attack += weapon.addAttack;
    chara.currentStats.defense += weapon.addDefense;
    chara.currentStats.HP += weapon.addHP;
}

void equipSpecialItem(Character &chara, string specialItem){
    chara.specialItem = specialItem;
}

void equipItem(string item[], int purchasedItem, string inventoryList[], int invertoryCount, int totalItem, int jumlahItemInventory[], Character chara[], int charCount , Weapon weapon){
    cout << "Kamu punya item : \n";
    inventory(item, purchasedItem, inventoryList, invertoryCount, totalItem, jumlahItemInventory);
    cout << "Masukkan nomor item yang ingin di pakai: ";
    int equip;
    cin >> equip;
    if(equip < 1 || equip > totalItem){
        cout << "Masukkan nomor item yang valid!\n";
    }
    else if(jumlahItemInventory[equip-1] <= 0){
        cout << "Kamu tidak memiliki item ini di inventory\n";
    }
    else{
        jumlahItemInventory[equip-1]--;
        cout << "Mau equip ke karakter mana? (masukkan nomor karakter): ";
        int charEquip = 0;
        cin >> charEquip;
        switch(equip){
            case 1:
                equipWeapon(chara[charEquip-1], {item[equip-1], 20, 5, 10});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 2:
                equipWeapon(chara[charEquip-1], {item[equip-1], 40, 10, 15});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 3:
                equipWeapon(chara[charEquip-1], {item[equip-1], 80, 15, 25});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 4:
                equipWeapon(chara[charEquip-1], {item[equip-1], 25, 5, 8});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 5:
                equipWeapon(chara[charEquip-1], {item[equip-1], 35, 12, 15});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 6:
                equipWeapon(chara[charEquip-1], {item[equip-1], 85, 20, 25});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 7:
                equipWeapon(chara[charEquip-1], {item[equip-1], 10, 20, 15});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 8:
                equipWeapon(chara[charEquip-1], {item[equip-1], 20, 40, 35});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 9:
                equipWeapon(chara[charEquip-1], {item[equip-1], 40, 85, 90});
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 10:
                cout << "Item ini adalah potion untuk menambah HP\n";
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 11:
                cout << "Item ini adalah potion untuk menambah Attack\n";
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 12:
                cout << "Item ini adalah potion untuk menambah Defense\n";
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 13:
                cout << "Item ini adalah potion untuk menambah semua stats\n";
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            default:
                break;
        }
        cout << "\nStats karakter setelah memakai item: \n";
        listKarakter(charCount, chara);
    }

}

int main(){
    int pilihan;
    int charCount = 0;
    const int MAX_CHAR = 4;
    int uang = 500000;
    Character chara[MAX_CHAR];
    Weapon weapon;
    
    string item[13] = {"Stone Sword", "Iron Sword", "Diamond Sword", "Iron Bow", "Diamond Bow", "Assault Rifle", "Stone Shield", "Iron Shield", "Diamond Shield", "Health Potion", "Attack Potion", "Defense Potion", "All in One Potion"};
    int harga[13] = {50000, 100000, 150000, 50000, 50000, 150000, 50000, 100000, 150000, 20000, 30000, 30000, 50000};
    int totalItem = sizeof(item)/sizeof(item[0]);
    int jumlahItemInventory[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int purchasedItem = -1;
    string inventoryList[13];
    int invertoryCount = 0;

    cout << "Selamat datang di game RPG ku\n";
    do{
        cout << "Menu: \n";
        cout << "1. Buat karakter baru\n";
        cout << "2. Karakterku\n";
        cout << "3. Toko\n";
        cout << "4. Inventory\n";
        cout << "5. Equip item\n";
        cout << "6. Battle\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                buatKarakter(charCount, MAX_CHAR, chara);
                cout << '\n';
                break;
            case 2:
                cout << "Daftar Karakter:\n";
                listKarakter(charCount, chara);
                cout << '\n';
                break;
            case 3:
                purchasedItem = toko(uang, charCount, item, harga, totalItem);
                if (purchasedItem != -1){
                    cout << "Item " << item[purchasedItem] << " telah ditambahkan ke inventory\n";
                    jumlahItemInventory[purchasedItem]++;
                    invertoryCount++;
                }
                cout << '\n';
                break;
            case 4:
                inventory(item, purchasedItem, inventoryList, invertoryCount, totalItem, jumlahItemInventory);
                cout << '\n';
                break;
            case 5:
                equipItem(item, purchasedItem, inventoryList, invertoryCount, totalItem, jumlahItemInventory, chara, charCount, weapon);
                break;
            case 6:
                break;
            case 7:
                cout << "Terima kasih sudah memainkan game ini!\n";
                break;
            default:
                cout << "Masukkan pilihan yang valid!\n";
                break;
        }
    }while(pilihan != 7);
    return 0;
}