#include "pch.h"

#include "FileData.h"

#pragma warning(disable : 4996)  

using namespace std;

bool FileData::ReadString(int length, string & target)
{
	if (this->isCSV())
	{
		int buff_size = 0x40;
		int buff_pos = 0;
		char* buff = new char[buff_size + 1];
		char ch;
		while (true)
		{
			this->stream->get(ch);
			
			if (ch == '\n' || ch == (char)this->delimiter || ch == EOF) {
				this->readpos += target.length() + 1;
				break;
			}
			else if (ch == '\r') {
				ch = static_cast<char>( this->stream->peek());
				if (ch == '\n') {
					this->stream->get();
					this->readpos += 1;
				} 
				this->readpos += target.length() + 1;
				break;
			}
			else {
				buff[buff_pos++] = ch;

				if (buff_pos == buff_size) {
					buff_size += buff_size / 2;
					char* tmp = new char[buff_size + 1];
					strncpy(tmp, buff, buff_pos);
					delete buff;
					buff = tmp;
				}
			}
			
		}
		buff[buff_pos] = '\0';

		target = string(buff);
	}
	else if (this->isTXT())
	{
		std::getline(*this->stream, target);
	}
	else if (this->isBinary())
	{
		if (length < 1) {
			target = "";
			return false;
		}
		char* buff = new char[length + 1];
		char ch;
		size_t i = 0;
		for (; i < length; i++)
		{
			this->stream->get(ch);
			if (ch == EOF) break;
			else buff[i] = ch;
		}
		buff[i] = '\0';

		target = string(buff);
	}

	return true;
}

bool FileData::ReadInteger(int size, int& value)
{
    if (this->isBinary()) {
        // char, short, int
        if (size != 1 && size != 2 && size != 4) {
            value = 0;
            return false;
        }
        this->stream->read((char*)&value, size);
        return true;
    }
    return false;
}

bool FileData::ReadDouble(int size, double& value)
{
    if (this->isBinary()) {
        // float, double
        if (size != 4 && size != 8) {
            value = 0.0;
            return false;
        }

        if (size == 4) {  // FLOAT_VALUE
            float f_value;
            this->stream->read((char*)&f_value, size);
            value = static_cast<double>(f_value);
        }
        else {
            this->stream->read((char*)&value, size);
        }
        return true;
    }
    return false;
}

void FileData::Seek(long long offset, int origin)
{
	const long long pos = stream->tellp();
	stream->seekp(0, ios::end);
	size = stream->tellp();
	stream->seekp(pos);

	ios_base::seekdir way;
	long long absolute_pos;

	switch (origin)
	{
	case SEEK_SET:
		way = ios_base::beg;
		absolute_pos = offset;
		break;
	case SEEK_END:
		way = ios_base::end;
		absolute_pos = this->size + offset;
		break;
	default:
		way = ios_base::cur;
		absolute_pos = pos + offset;
	}

	if (absolute_pos < 0) {

		this->writepos = 0;
		this->stream->seekp(writepos, ios_base::beg);
	}
	else if (absolute_pos > this->size) {

		MessageBoxA(NULL, (string("\n\n\n\nABSPOS MORE THAT SIZE OMG!!\nSize is: ") + to_string(size)).c_str(), "LOL", MB_OK);
		writepos = absolute_pos;
		this->stream->seekp(0, ios_base::end);
	}
	else {
		this->stream->seekp(absolute_pos, ios_base::beg);
	}

}

bool FileData::shareRead()
{
	return (this->flags & 1) != 0;
}

bool FileData::shareWrite()
{
	return (this->flags & 2) != 0;
}

bool FileData::isBinary()
{
	return (this->flags & FILE_BIN) != 0;
}

bool FileData::isCSV()
{
	return (this->flags & FILE_CSV) != 0;
}

bool FileData::isTXT()
{
	return (this->flags & FILE_TXT) != 0;
}

bool FileData::isANSI()
{
	return (this->flags & FILE_ANSI) != 0;
}

bool FileData::isUnicode()
{
	return (this->flags & FILE_UNICODE) != 0;
}

bool FileData::canWrite()
{
	return (this->flags & FILE_WRITE) != 0;
}

bool FileData::canRead()
{
	return (this->flags & FILE_READ) != 0;
}

bool FileData::rewrite()
{
	return (this->flags & FILE_REWRITE) != 0;
}

bool FileData::common()
{
	return (this->flags & FILE_COMMON) != 0;
}

