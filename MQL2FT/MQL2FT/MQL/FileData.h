#pragma once

// File flags
#define FILE_BIN 4
#define FILE_CSV 8
#define FILE_TXT 16
#define FILE_ANSI 32
#define FILE_UNICODE 64
#define FILE_READ 128
#define FILE_WRITE 256
//#define FILE_SHARE_READ 128
//#define FILE_SHARE_WRITE 256
#define FILE_REWRITE 512
#define FILE_COMMON 4096

struct FileData
{
	std::fstream* stream;
	int flags;
	short delimiter;

	long long readpos;
	long long writepos;
	long long size;

	bool ReadString(int length, std::string& buff);
    bool ReadInteger(int size, int& value);
    bool ReadDouble(int size, double& value);

	void Seek(long long offset, int origin);

	bool shareRead();
	bool shareWrite();
	bool isBinary();
	bool isCSV();
	bool isTXT();
	bool isANSI();
	bool isUnicode();
	bool canWrite();
	bool canRead();
	bool rewrite();
	bool common();
};