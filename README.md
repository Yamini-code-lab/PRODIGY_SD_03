# 📋 CLI Contact Manager

![C++](https://img.shields.io/badge/C++-blue) ![CRUD](https://img.shields.io/badge/CRUD-green) ![File I/O](https://img.shields.io/badge/File_IO-amber)

A menu-driven CLI app to add, display, search, and delete contacts. Data is saved to a local `contacts.txt` file and persists across runs.

## Features
| Option | Action |
|--------|--------|
| 1 | Add a contact (name, phone, email) |
| 2 | Display all contacts |
| 3 | Search contact by name |
| 4 | Delete contact by name |
| 5 | Exit |

## Storage
Contacts are stored in `contacts.txt` (created automatically on first run) in the format:
```
Name Phone Email
```
> **Note:** Names and fields are single-word only — spaces in input will break parsing. Multi-word names are not supported in the current version.

## Run locally
```bash
git clone https://github.com/Yamini-code-lab/cli-contact-manager
cd cli-contact-manager
g++ -o contacts main.cpp
./contacts
```

## Skills used
C++ · File I/O · CRUD Operations · Vectors · Modular Functions · CLI
