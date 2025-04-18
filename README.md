# 📚 Student Management System in C

A simple console-based application written in C language that allows managing student records using basic file handling.

## ✅ Features
- Add a new student
- View all students
- Search for a student by ID
- Update student information
- Delete a student
- Data stored in a binary file (`students.dat`)

## 📁 File Structure
```
📁 Student-Management-C
├── students.c         # Main source code
├── students.dat       # Auto-created binary file for data storage
└── README.md          # Project documentation
```

## ⚙️ How to Compile and Run
Make sure you have a C compiler (e.g., `gcc`), then:

```bash
gcc students.c -o students
./students
```

## 📸 Screenshots (Optional)
You can add screenshots of the terminal interface here for better presentation.

## 🧠 Concepts Used
- Structures in C
- File handling (`fopen`, `fread`, `fwrite`, etc.)
- Basic console UI
- Binary file management

## 📌 Note
All student records are saved in `students.dat`. Make sure you do not delete the file unless you want to reset the database.

## 📄 License
This project is open source and free to use.
