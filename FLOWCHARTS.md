# Boarding House Management System - Flowcharts

This document contains comprehensive flowcharts for the entire boarding house management system project.

## Table of Contents
1. [System Architecture](#system-architecture)
2. [Main Program Flow](#main-program-flow)
3. [Add Resident (tambahPenghuni)](#add-resident-tambahpenghuni)
4. [Display Rooms (tampilkanKamar)](#display-rooms-tampilkankamar)
5. [Edit Room (editKamar)](#edit-room-editkamar)
6. [Empty Room (kosongkanKamar)](#empty-room-kosongkankamar)
7. [Search Resident (cariPenghuni)](#search-resident-caripenghuni)
8. [Data Structure](#data-structure)

---

## System Architecture

```mermaid
graph TB
    Start([Program Start]) --> Init[Initialize Array of 10 Rooms]
    Init --> InitLoop[Set Initial Values:<br/>- Room Numbers 1-10<br/>- Empty Names<br/>- Status: Not Paid<br/>- Status: Empty]
    InitLoop --> MainMenu[Display Main Menu]
    
    MainMenu --> Choice{User Choice}
    
    Choice -->|1| AddResident[tambah_penghuni<br/>Add Resident]
    Choice -->|2| DisplayRooms[tampilkan_kamar<br/>Display All Rooms]
    Choice -->|3| EditRoom[edit_kamar<br/>Edit Room Data]
    Choice -->|4| EmptyRoom[kosongkan_kamar<br/>Empty Room]
    Choice -->|5| SearchResident[cari_penghuni<br/>Search Resident]
    Choice -->|6| Exit[keluar<br/>Exit Program]
    Choice -->|Invalid| Invalid[Display Error Message]
    
    AddResident --> MainMenu
    DisplayRooms --> MainMenu
    EditRoom --> MainMenu
    EmptyRoom --> MainMenu
    SearchResident --> MainMenu
    Invalid --> MainMenu
    Exit --> End([Program End])
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style MainMenu fill:#87CEEB
    style AddResident fill:#FFE4B5
    style DisplayRooms fill:#FFE4B5
    style EditRoom fill:#FFE4B5
    style EmptyRoom fill:#FFE4B5
    style SearchResident fill:#FFE4B5
    style Exit fill:#FFE4B5
```

---

## Main Program Flow

```mermaid
flowchart TD
    A([Start Program]) --> B[Set UTF-8 Console Encoding]
    B --> C[Declare Array: kamar ruangan 10]
    C --> D[Initialize Loop i=0 to 9]
    
    D --> E[For Each Room:<br/>- nomor = i+1<br/>- nama = empty string<br/>- statusBayar = 0<br/>- statusKamar = 0]
    
    E --> F{Display Menu:<br/>╔═══════════════════════╗<br/>║ Manajemen Kost Menu ║<br/>╠═══════════════════════╣<br/>║ 1. Tambah Penghuni    ║<br/>║ 2. Tampilkan Kamar    ║<br/>║ 3. Edit Data Kamar    ║<br/>║ 4. Kosongkan Kamar    ║<br/>║ 5. Cari Penghuni      ║<br/>║ 6. Keluar             ║<br/>╚═══════════════════════╝}
    
    F --> G[Input: User Choice]
    
    G --> H{Switch Case}
    
    H -->|Case 1| I[Call tambah_penghuni]
    H -->|Case 2| J[Call tampilkan_kamar]
    H -->|Case 3| K[Call edit_kamar]
    H -->|Case 4| L[Call kosongkan_kamar]
    H -->|Case 5| M[Call cari_penghuni]
    H -->|Case 6| N[Call keluar]
    H -->|Default| O[Print: Opsi tidak valid]
    
    I --> P{Check opsi != 6}
    J --> P
    K --> P
    L --> P
    M --> P
    O --> P
    N --> Q([End Program])
    
    P -->|True| F
    P -->|False| Q
    
    style A fill:#90EE90
    style Q fill:#FFB6C1
    style F fill:#87CEEB
    style H fill:#FFFFE0
```

---

## Add Resident (tambahPenghuni)

```mermaid
flowchart TD
    A([Start tambah_penghuni]) --> B[Input: Room Number]
    B --> C{Room Number<br/>Valid?<br/>1 <= no <= 10}
    
    C -->|No| D[Print: Nomor kamar tidak valid]
    D --> Z([Return])
    
    C -->|Yes| E[Calculate Index: i = noKamar - 1]
    E --> F{Check<br/>statusKamar == 1<br/>Room Occupied?}
    
    F -->|Yes| G["Print: Kamar sudah terisi<br/>oleh [nama]"]
    G --> Z
    
    F -->|No| H[Input: Resident Name<br/>Max 44 characters]
    H --> I[Start Payment Status Loop]
    
    I --> J[Input: Payment Status<br/>1 = Paid / 0 = Unpaid]
    J --> K{Payment<br/>Status Value?}
    
    K -->|1| L[Set statusBayar = 1<br/>Print: Oke cuan!]
    K -->|0| M[Set statusBayar = 0<br/>Print: jangan lupa di tagih!]
    K -->|Invalid| N[Print: Status tidak valid<br/>pilih antara 0 dan 1]
    
    N --> J
    
    L --> O[Set Room Data:<br/>- nomor = noKamar<br/>- statusKamar = 1]
    M --> O
    
    O --> Z
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style C fill:#FFFFE0
    style F fill:#FFFFE0
    style K fill:#FFFFE0
```

---

## Display Rooms (tampilkanKamar)

```mermaid
flowchart TD
    A([Start tampilkan_kamar]) --> B[Print Table Header:<br/>+----------+----------------------+---------------+----------------+<br/>| No Kamar | Nama | Status Kamar | Status Bayar |]
    
    B --> C[Start Loop: i = 0 to jumlah-1]
    
    C --> D[Set no = i + 1]
    D --> E{Check<br/>statusKamar == 0<br/>Empty Room?}
    
    E -->|Yes| F["Set Display Values:<br/>- nama = '-'<br/>- statusKamar = 'Kosong'<br/>- statusBayar = '-'"]
    
    E -->|No| G{Check<br/>nama0 == '\\0'<br/>Name Empty?}
    
    G -->|Yes| H["Set nama = '-'"]
    G -->|No| I["Set nama = ruangan[i].nama"]
    
    H --> J["Set statusKamar = 'Terisi'"]
    I --> J
    
    J --> K{Check<br/>statusBayar == 1<br/>Paid?}
    
    K -->|Yes| L["Set statusBayar = 'Lunas'"]
    K -->|No| M["Set statusBayar = 'Belum Lunas'"]
    
    F --> N["Print Row:<br/>| no | nama | statusKamar | statusBayar |"]
    L --> N
    M --> N
    
    N --> O{More Rooms?<br/>i < jumlah}
    
    O -->|Yes| D
    O -->|No| P[Print Table Footer:<br/>+----------+----------------------+---------------+----------------+]
    
    P --> Z([Return])
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style E fill:#FFFFE0
    style G fill:#FFFFE0
    style K fill:#FFFFE0
    style O fill:#FFFFE0
```

---

## Edit Room (editKamar)

```mermaid
flowchart TD
    A([Start edit_kamar]) --> B[Input: Room Number to Edit]
    B --> C{Room Number<br/>Valid?<br/>1 <= no <= jumlah}
    
    C -->|No| D[Print: Nomor kamar tidak valid]
    D --> Z([Return])
    
    C -->|Yes| E[Calculate Index: i = noKamar - 1]
    E --> F{Check<br/>statusKamar == 0<br/>Room Empty?}
    
    F -->|Yes| G["Print: Kamar [no] kosong"]
    G --> Z
    
    F -->|No| H["Display Current Data:<br/>- Nama: [nama]<br/>- Status Bayar: Lunas/Belum Lunas"]
    
    H --> I["Display Edit Options:<br/>1. Nama Penghuni<br/>2. Status Bayar"]
    I --> J[Input: User Choice]
    
    J --> K{Switch<br/>Choice}
    
    K -->|Case 1| L[Input: New Resident Name]
    L --> M[Start Payment Status Loop]
    
    M --> N[Input: Payment Status<br/>1 = Paid / 0 = Unpaid]
    N --> O{Payment<br/>Status?}
    
    O -->|1| P[Set statusBayar = 1<br/>Print: Oke cuan!]
    O -->|0| Q[Set statusBayar = 0<br/>Print: jangan lupa di tagih!]
    O -->|Invalid| R[Print: Status tidak valid<br/>pilih antara 0 dan 1]
    
    R --> N
    P --> Z
    Q --> Z
    
    K -->|Case 2| S[Start Payment Status Loop]
    S --> T[Input: Payment Status<br/>1 = Paid / 0 = Unpaid]
    
    T --> U{Payment<br/>Status?}
    
    U -->|1| V[Set statusBayar = 1<br/>Print: Oke cuan!]
    U -->|0| W[Set statusBayar = 0<br/>Print: jangan lupa di tagih!]
    U -->|Invalid| X[Print: Status tidak valid<br/>pilih antara 0 dan 1]
    
    X --> T
    V --> Z
    W --> Z
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style C fill:#FFFFE0
    style F fill:#FFFFE0
    style K fill:#FFFFE0
    style O fill:#FFFFE0
    style U fill:#FFFFE0
```

---

## Empty Room (kosongkanKamar)

```mermaid
flowchart TD
    A([Start kosongkan_kamar]) --> B[Input: Room Number to Empty]
    B --> C{Room Number<br/>Valid?<br/>1 <= no <= jumlah}
    
    C -->|No| D[Print: Nomor kamar tidak valid]
    D --> Z([Return])
    
    C -->|Yes| E[Calculate Index: i = noKamar - 1]
    E --> F{Check<br/>statusKamar == 0<br/>Already Empty?}
    
    F -->|Yes| G["Print: Kamar [no] kosong"]
    G --> Z
    
    F -->|No| H[Call hapusKamar Function]
    
    H --> I["hapusKamar Function:<br/>- Set nama0 = '\\0'<br/>- Set statusBayar = 0<br/>- Set statusKamar = 0"]
    
    I --> J["Print: Kamar [no]<br/>berhasil di kosongkan"]
    J --> Z([Return])
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style C fill:#FFFFE0
    style F fill:#FFFFE0
    style I fill:#FFE4B5
```

---

## Search Resident (cariPenghuni)

```mermaid
flowchart TD
    A([Start cari_penghuni]) --> B[Input: Resident Name to Search]
    B --> C[Initialize found = 0]
    C --> D[Start Loop: i = 0 to jumlah-1]
    
    D --> E{Check<br/>statusKamar == 0<br/>Room Empty?}
    
    E -->|Yes| F[Continue to Next Room]
    F --> G{More Rooms?<br/>i < jumlah}
    
    E -->|No| H["Call stringCompare<br/>Compare search name<br/>with ruangan[i].nama"]
    
    H --> I{Names<br/>Match?<br/>result == 0}
    
    I -->|No| G
    
    I -->|Yes| J["Display Resident Info:<br/>- Nama Penghuni: [nama]<br/>- Nomor Kamar: [nomor]<br/>- Status Bayar: Lunas/Belum Lunas<br/>- Status Kamar: Terisi/Kosong"]
    
    J --> K[Set found = 1]
    K --> G
    
    G -->|Yes| D
    G -->|No| L{Check<br/>found == 0<br/>Not Found?}
    
    L -->|Yes| M[Print: Penghuni tidak ditemukan]
    L -->|No| N([Skip])
    
    M --> Z([Return])
    N --> Z
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style E fill:#FFFFE0
    style I fill:#FFFFE0
    style G fill:#FFFFE0
    style L fill:#FFFFE0
    style H fill:#FFE4B5
```

### String Compare Helper Function

```mermaid
flowchart TD
    A([Start stringCompare]) --> B["Input Parameters:<br/>- str1[]: Search String<br/>- str2[]: Target String"]
    B --> C[Initialize i = 0]
    C --> D{Check<br/>str1[i] == str2[i]}
    
    D -->|No| E["Return<br/>str1[i] - str2[i]"]
    
    D -->|Yes| F{Check<br/>str1[i] == '\\0' OR<br/>str2[i] == '\\0'<br/>End of String?}
    
    F -->|Yes| E
    F -->|No| G[Increment i++]
    G --> D
    
    E --> Z([Return Result:<br/>0 = Match<br/>!= 0 = Different])
    
    style A fill:#90EE90
    style Z fill:#FFB6C1
    style D fill:#FFFFE0
    style F fill:#FFFFE0
```

---

## Data Structure

```mermaid
classDiagram
    class kamar {
        +int nomor
        +char nama[45]
        +int statusBayar
        +int statusKamar
    }
    
    class Application {
        +kamar ruangan[10]
        +int jumlahKamar
        +void tambah_penghuni()
        +void tampilkan_kamar()
        +void edit_kamar()
        +void kosongkan_kamar()
        +void cari_penghuni()
        +void keluar()
    }
    
    Application --> kamar : uses array of
    
    note for kamar "statusBayar:\n0 = Belum Lunas (Unpaid)\n1 = Lunas (Paid)\n\nstatusKamar:\n0 = Kosong (Empty)\n1 = Terisi (Occupied)"
```

### Data Structure Details

**kamar struct:**
- `nomor` (int): Room number (1-10)
- `nama` (char[45]): Resident name (max 44 characters + null terminator)
- `statusBayar` (int): Payment status
  - `0` = Belum Lunas (Unpaid)
  - `1` = Lunas (Paid)
- `statusKamar` (int): Room occupancy status
  - `0` = Kosong (Empty)
  - `1` = Terisi (Occupied)

**Global Constants:**
- `jumlahKamar`: Fixed value of 10 rooms

---

## Program Files Overview

| File | Function | Description |
|------|----------|-------------|
| [main.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/main.c) | main() | Entry point, menu loop, dispatch functions |
| [tambahPenghuni.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/tambahPenghuni.c) | tambah_penghuni() | Add new resident to a room |
| [tampilkanKamar.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/tampilkanKamar.c) | tampilkan_kamar() | Display all rooms in table format |
| [editKamar.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/editKamar.c) | edit_kamar() | Edit resident name or payment status |
| [kosongkanKamar.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/kosongkanKamar.c) | kosongkan_kamar() | Clear room data |
| [cariPenghuni.c](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/cariPenghuni.c) | cari_penghuni() | Search for resident by name |
| [keluar.c](file:///d:/INFORMATIKA/Pengenalen%20Pemrograman/project_akhir/keluar.c) | keluar() | Display exit message |
| [header/kamar.h](file:///d:/INFORMATIKA/Pengenalan%20Pemrograman/project_akhir/header/kamar.h) | N/A | Header file with struct definition and function declarations |

---

## Summary

This boarding house management system provides a complete solution for managing room occupancy with the following features:

1. **Add Resident**: Register new residents with payment status
2. **Display Rooms**: View all rooms with current occupancy and payment information
3. **Edit Room**: Update resident information or payment status
4. **Empty Room**: Clear room data when resident leaves
5. **Search Resident**: Find resident by name across all rooms
6. **Exit**: Gracefully exit the application

The system manages 10 rooms with persistent in-memory storage during runtime, tracking resident names, payment status, and room occupancy status.
