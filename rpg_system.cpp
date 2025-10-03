#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Statistics{
    int level;
    int HP;
    int attack;
    int defense;
    int exp;
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

struct SpecialItem{
    string itemName;
    int addAttack;
    int addDefense;
    int addHP;
};

struct Enemy{
    Statistics enemyStats;
    string enemyName;
};

void buatKarakter(int &charCount, int MAX_CHAR, Character chara[], int &uang){
    int agreeMake;
    cout << "Membuat karakter baru membutuhkan uang 50000\n";
    cout << "Apakah kamu setuju? (1. Ya / 2. Tidak): ";
    cin >> agreeMake;
    if(agreeMake == 2){
        cout << "Kamu membatalkan pembuatan karakter\n";
        return;
    }
    else if(agreeMake != 1 && agreeMake != 2){
        cout << "Masukkan pilihan yang valid!\n";
        return;
    }
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
            newChar.baseStats = {1, 150, 80, 50, 0};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "DPS";
            newChar.weapon = "Basic Sword";
            newChar.specialItem = "None";

        }
        else if(newChar.role == "Marksman" || newChar.role == "marksman"){
            //newChar = {{1, 120, 70, 50}, newChar.baseStats, newChar.name, "Marksman", "Wooden Bow", "None"};
            newChar.baseStats = {1, 120, 70, 50, 0};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "Marksman";
            newChar.weapon = "Wooden Bow";
            newChar.specialItem = "None";
        }
        else if(newChar.role == "Sustain" || newChar.role == "sustain"){
            //newChar = {{1, 200, 50, 90},newChar.baseStats, newChar.name, "Sustain", "Basic Shield", "None"};
            newChar.baseStats = {1, 200, 50, 90, 0};
            newChar.currentStats = newChar.baseStats;
            newChar.role = "Sustain";
            newChar.weapon = "Basic Shield";
            newChar.specialItem = "None";
        }
        chara[charCount] = newChar;
        charCount++;
        uang -= 50000;
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
        cout << " Special Item : " << chara[i].specialItem << "\n";
    }
}

int searchKarakter(int charCount, Character chara[], string name){
    string nameSearch;
    cout << "Masukkan nama karakter yang ingin dicari: ";
    getline(cin, nameSearch);
    for(int i = 0; i < charCount; i++){
        if(chara[i].name == nameSearch){
            return i;
        }
    }
    return -1;
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

void inventory(string item[], int purchasedItem, int totalItem, int jumlahItemInventory[]){
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

void equipSpecialItem(Character &chara, SpecialItem specialitem, string item[]){
    chara.specialItem = specialitem.itemName;
    if(specialitem.itemName == item[9]){
        chara.currentStats.HP += specialitem.addHP;
    }
    else if(specialitem.itemName == item[10]){
        chara.currentStats.attack += specialitem.addAttack;
    }
    else if(specialitem.itemName == item[11]){
        chara.currentStats.defense += specialitem.addDefense;
    }
    else if(specialitem.itemName == item[12]){
        chara.currentStats.HP += specialitem.addHP;
        chara.currentStats.attack += specialitem.addAttack;
        chara.currentStats.defense += specialitem.addDefense;
    }
}

void equipItem(string item[], int purchasedItem, int totalItem, int jumlahItemInventory[], Character chara[], int charCount , Weapon weapon){
    cout << "Kamu punya item : \n";
    inventory(item, purchasedItem, totalItem, jumlahItemInventory);
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
                equipSpecialItem(chara[charEquip-1], {item[equip-1], 0, 0, 40}, item);
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 11:
                equipSpecialItem(chara[charEquip-1], {item[equip-1], 30, 0, 0}, item);
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 12:
                equipSpecialItem(chara[charEquip-1], {item[equip-1], 0, 25, 0}, item);
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            case 13:
                equipSpecialItem(chara[charEquip-1], {item[equip-1], 30, 25, 40}, item);
                cout << "Kamu telah memakai item " << item[equip-1] << "\n";
                break;
            default:
                break;
        }
        cout << "\nStats karakter setelah memakai item: \n";
        listKarakter(charCount, chara);
    }
}

void enemyGenerator(Enemy enemies[], int level){
    for(int i = 0; i < 4; i++){
        enemies[i].enemyStats.level = level;
        enemies[i].enemyStats.HP = 100 + (level * 20);
        enemies[i].enemyStats.attack = 50 + (level * 10);
        enemies[i].enemyStats.defense = 30 + (level * 5);
        enemies[i].enemyStats.exp = 20 + (level * 5);
    }
    enemies[0].enemyName = "Slime";
    enemies[1].enemyName = "Goblin";
    enemies[2].enemyName = "Oni";
    enemies[3].enemyName = "Dragon";
}

int damageCalculationKarakter(int &damage, Character chara, Enemy enemies){
    int damage = (chara.currentStats.attack - (enemies.enemyStats.defense/2)) + rand() % 21 - 10;
    if( rand() % 100 < 20){
        damage *= 2;
        cout << "Critical Hit!\n";
    }
    return damage;
}

int damageCalculationEnemy(int &damage, Character chara, Enemy enemies){
    int damage = (enemies.enemyStats.attack - (chara.currentStats.defense/2)) + rand() % 21 - 10;
    if( rand() % 100 < 20){
        damage *= 2;
        cout << "Critical Hit!\n";
    }
    return damage;
}

void playerTurn(int &damage, Character chara, Enemy enemies){
    int action;
    int damageDealt = damageCalculationKarakter(damage, chara, enemies);
    cout << "Pilih aksi:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "Masukkan pilihan: ";
    cin >> action;
    if (action == 1){
        cout << chara.name << " menyerang " << enemies.enemyName << " dan memberikan " << damageDealt << " damage!\n";
        enemies.enemyStats.HP -= damageDealt;
        if(enemies.enemyStats.HP < 0){
            enemies.enemyStats.HP = 0;
        }
        cout << enemies.enemyName << " memiliki sisa HP: " << enemies.enemyStats.HP << '\n';
    }
    else if(action == 2){
        cout << chara.name << " memilih untuk bertahan!\n";
        chara.currentStats.defense += chara.baseStats.defense / 2;
        cout << chara.name << " mendapatkan tambahan defense sebesar " << chara.baseStats.defense / 2 << '\n';
    }
    else{
        cout << "Masukkan pilihan yang valid!\n";
    }
}

void enemyTurn(int &damage, Character chara, Enemy enemies){
    cout << "Giliran musuh\n";
    int damageDealt = damageCalculationEnemy(damage, chara, enemies);
    cout << enemies.enemyName << " menyerang " << chara.name << " dan memberikan " << damageDealt << " damage!\n";
    chara.currentStats.HP -= damageDealt;
    if(chara.currentStats.HP < 0){
        chara.currentStats.HP = 0;
    }
    cout << chara.name << " memiliki sisa HP: " << chara.currentStats.HP << '\n';
}

bool checkMenang(Character chara, Enemy enemies){
    if(enemies.enemyStats.HP <= 0){
        cout << "Kamu menang!\n";
        return true;
    }
    else if(chara.currentStats.HP <= 0){
        cout << "Kamu kalah!\n";
        return true;
    }
    return false;
}

int expCalculation(int level, Character &chara){
    return 0;
}

void battle(int &damage, int MAX_ENEMY, Character chara[], Enemy enemies[], int &uang, int level, int exp){
    int charBattle;
    cout << "Pilih karakter yang ingin digunakan untuk bertarung (masukkan nomor karakter): ";
    cin >> charBattle;
    cout << "Kamu telah memilih karakter " << chara[charBattle-1].name << " untuk bertarung\n";
    cout << "Pilih musuh yang ingin dihadapi:\n";
    for(int i = 0; i < MAX_ENEMY; i++){
        cout << i+1 << ". " << enemies[i].enemyName << " (Level " << enemies[i].enemyStats.level << ")\n";
    }
    cout << "Masukkan nomor musuh yang ingin dihadapi: ";
    int enemyBattle;
    cin >> enemyBattle;
    cout << "Kamu telah memilih musuh " << enemies[enemyBattle-1].enemyName << " untuk dihadapi\n";
    cout << "Pertarungan dimulai!\n";
    do{
        playerTurn(damage, chara[charBattle-1], enemies[enemyBattle-1]);
        checkMenang(chara[charBattle-1], enemies[enemyBattle-1]);
        enemyTurn(damage, chara[charBattle-1], enemies[enemyBattle-1]);
        checkMenang(chara[charBattle-1], enemies[enemyBattle-1]);
    }while(!checkMenang(chara[charBattle-1], enemies[enemyBattle-1]));
}

int main(){
    int pilihan;
    int charCount = 0;
    int uang = 200000;
    srand(time(0));

    const int MAX_CHAR = 10;
    Character chara[MAX_CHAR];
    Weapon weapon;
    const int MAX_ENEMY = 4;
    Enemy enemies[MAX_ENEMY];
    
    string item[13] = {"Stone Sword", "Iron Sword", "Diamond Sword", "Iron Bow", "Diamond Bow", "Assault Rifle", "Stone Shield", "Iron Shield", "Diamond Shield", "Health Potion", "Attack Potion", "Defense Potion", "All in One Potion"};
    int harga[13] = {50000, 120000, 200000, 50000, 120000, 200000, 50000, 120000, 200000, 30000, 30000, 30000, 75000};
    int totalItem = sizeof(item)/sizeof(item[0]);
    int jumlahItemInventory[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    const int MAX_EXP = 100;
    int purchasedItem = -1;
    int damage = 0;

    cout << "Selamat datang di game RPG ngasal\n";
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
        cout << '\n';

        switch(pilihan){
            case 1:
                buatKarakter(charCount, MAX_CHAR, chara, uang);
                cout << '\n';
                break;
            case 2:
                cout << "List atau cari karakter? (1. List / 2. Cari): ";
                int listOrSearch;
                cin >> listOrSearch;
                cin.ignore();
                cout << '\n';
                if(listOrSearch == 1){
                    cout << "Daftar Karakter:\n";
                    listKarakter(charCount, chara);
                    cout << '\n';
                }
                else if(listOrSearch == 2){
                    int foundIndex = searchKarakter(charCount, chara, "");
                    if(foundIndex != -1){
                        cout << "Karakter ditemukan!\n";
                        cout << "Nama Karakter : " << chara[foundIndex].name << '\n';
                        cout << " Role : " << chara[foundIndex].role << '\n';
                        cout << " Level : " << chara[foundIndex].currentStats.level << '\n';
                        cout << " Attack : " << chara[foundIndex].currentStats.attack << '\n';
                        cout << " HP : " << chara[foundIndex].currentStats.HP << '\n';
                        cout << " Defense : " << chara[foundIndex].currentStats.defense << '\n';
                        cout << " Weapon : " << chara[foundIndex].weapon << '\n';
                        cout << " Special Item : " << chara[foundIndex].specialItem << "\n\n";
                    }
                    else{
                        cout << "Karakter tidak ditemukan!\n\n";
                    }
                }
                else{
                    cout << "Masukkan pilihan yang valid!\n\n";
                }
                break;
            case 3:
                purchasedItem = toko(uang, charCount, item, harga, totalItem);
                if (purchasedItem != -1){
                    cout << "Item " << item[purchasedItem] << " telah ditambahkan ke inventory\n";
                    jumlahItemInventory[purchasedItem]++;
                }
                cout << '\n';
                break;
            case 4:
                inventory(item, purchasedItem, totalItem, jumlahItemInventory);
                cout << '\n';
                break;
            case 5:
                equipItem(item, purchasedItem, totalItem, jumlahItemInventory, chara, charCount, weapon);
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