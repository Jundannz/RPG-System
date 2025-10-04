# 🎮 RPG Ngasal (C++ Console Game)

**RPG Ngasal** adalah sebuah game RPG sederhana berbasis **C++** yang dimainkan di console/terminal.  
Game ini dibuat untuk latihan struct, array, dan konsep dasar OOP ala C++, dengan fitur membuat karakter, battle melawan musuh, hingga membeli dan memakai item.  

---

## ✨ Fitur Utama
- 🧑‍🤝‍🧑 **Membuat Karakter**
  - Pilih role: **DPS, Marksman, Sustain**
  - Setiap role punya **statistik awal & senjata bawaan** berbeda
  - Membuat karakter membutuhkan biaya **50.000 gold**

- 📜 **Daftar & Cari Karakter**
  - Tampilkan semua karakter yang dimiliki
  - Cari karakter berdasarkan nama

- 🏪 **Toko Item**
  - Beli senjata, shield, dan potion dengan gold
  - Item memiliki efek berbeda (menambah ATK, DEF, HP, dll.)

- 🎒 **Inventory**
  - Simpan semua item yang sudah dibeli
  - Tampilkan jumlah item yang dimiliki

- 🗡 **Equip Item**
  - Pasang senjata atau potion pada karakter pilihan
  - Statistik karakter otomatis bertambah sesuai item

- 🐉 **Sistem Battle**
  - Pilih karakter dan musuh untuk bertarung
  - Aksi: **Attack** atau **Defend**
  - Terdapat **Critical Hit** dengan peluang 20%
  - Menang akan memberikan **EXP & Gold**

- 📈 **Level Up System**
  - EXP yang cukup akan menaikkan level karakter
  - Statistik bertambah otomatis (HP, ATK, DEF)

---

## 👾 Musuh
Game menyediakan 4 jenis musuh dengan scaling berdasarkan level:
- **Slime**
- **Goblin**
- **Oni**
- **Dragon**

Semakin tinggi level musuh → semakin besar HP, ATK, DEF, dan EXP reward.

---

## 📂 Struktur Program
- `struct Statistics` → Menyimpan level, HP, attack, defense, exp
- `struct Character` → Data karakter player
- `struct Weapon` → Data senjata
- `struct SpecialItem` → Data item spesial/potion
- `struct Enemy` → Data musuh

---

## 🕹 Cara Main
1. **Compile program**  
   ```bash
   g++ main.cpp -o rpg
   ./rpg
   ```
2. Pilih menu:
   - `1` → Buat karakter
   - `2` → Lihat / cari karakter
   - `3` → Masuk toko, beli item
   - `4` → Lihat inventory
   - `5` → Equip item
   - `6` → Battle
   - `7` → Keluar

---

## 📖 Contoh Gameplay
```text
==================================
Selamat datang di game RPG ngasal
==================================
Menu:
1. Buat karakter baru
2. Karakterku
3. Toko
4. Inventory
5. Equip item
6. Battle
7. Keluar
Masukkan pilihan:
```

---

## 🚀 Next Update (Ide Pengembangan)
- Save & Load progress (pakai file txt/JSON)
- Sistem skill & magic
- Quest & dungeon
- Multi-character battle (party system)

---

## 📝 License
Project ini dibuat untuk pembelajaran **C++ dasar**.  
Silakan gunakan, modifikasi, dan kembangkan sesuka hati 🎉
