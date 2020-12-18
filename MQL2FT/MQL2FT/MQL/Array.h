#pragma once

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
extern "C" __declspec(dllexport) TInterfaceProcRec IntrfProcsRec;
#endif

#ifdef __STRATEGY
#include "StrategyInterfaceUnit.h"
#endif

#include "datetime.h"
#include "MqlEnums.h"
#include <vector>

const int WHOLE_ARRAY = 0;
const int MODE_ASCEND = 0;
const int MODE_DESCEND = 1;

extern mql4::ENUM_TIMEFRAMES _Period;


#define Min(a, b)  (a < b ? a : b)

template<typename V>
struct gr {
	bool operator() (V i, V j) { return (i>j); }
};


template<typename T>
class ArrayBase
{
protected:
	int begin;
	bool _changed = false;
	mutable bool _indexDirection = false;
	bool _isStatic = false;
	std::vector<T> buffer;
	std::vector<int> _size = { 0,0,0,0,0 };
	int _range;

public:

	ArrayBase<T>() {}
	ArrayBase<T>(int c) {
		buffer.resize(c);
		_isStatic = (c != 0);
		_size[0] = c;
		_range = 1;
	}

	ArrayBase<T>(std::initializer_list<T> l) : buffer(l) {
		_size[0] = buffer.size();
		_isStatic = (_size[0] != 0);
		_range = 1;
	}
	~ArrayBase<T>() {};

	std::vector<T>& GetBuffer()
	{
		return buffer;
	}

	typename std::vector<T>::reference operator[](int i) 
	{
		static std::vector<T> default_vector(1,T());

		if (i >= buffer.size())
		{
			default_vector[0] = T();
			return default_vector[0];
		}

		if (_indexDirection) {
			return buffer[ReverseIndex(i)];
		}
		return buffer[i];
	}

	virtual T operator[](int i) const
	{
		if(i >= buffer.size())
		{
			return T();
		}

		if(_indexDirection) {
			return buffer[ReverseIndex(i)];
		}
		return buffer[i];
	}

	bool IsDynamic() {
		return !_isStatic;
	}

	virtual int Count() const
	{
		return buffer.size();
	}

	virtual int Range(int rank_index) {
		if (rank_index == 0)
		{
			return Count();
		}
		return 0;
	}

	virtual int LinearSize()
	{
		return buffer.size();
	}

	int SetIndexDirection(bool flag) const
	{
		//if (_isStatic)
		//	return false;
		_indexDirection = flag;
		return true;
	}

	bool GetIndexDirection() const
	{
		return _indexDirection;
	}

	T Item(int i) const
	{
		if (_indexDirection) {
			return buffer[ReverseIndex(i)];
		}
		return buffer[i];
	}

	virtual void Resize(int c) {
		if (!_isStatic) {
			buffer.resize(c);
			_size[0] = c;
		}
	}

	void Reserve(int reserve) {
		buffer.reserve(reserve);
	}

	int IncreaseLast() {};
	int GetLast() {};

	virtual int ReverseIndex(int i) const
	{
		return buffer.size() - i - 1;
	}

	void  Fill(int start, int count, T value) {
		if (start >= 0 && start < buffer.size()) {
			int cn = (count <= WHOLE_ARRAY ? buffer.size() - start : Min(Count() - start, count));
			for (int i = start, c = 0; c < cn; i++, c++) {
				buffer[i] = value;
			}
		}
	}

	virtual void Clear()
	{
		return buffer.clear();
	}

	virtual void Free()
	{
		buffer.clear();
		_size[0] = 0;
	}

	virtual void Add(T el)
	{
		return buffer.push_back(el);
	}

	virtual int Dimentions() const = 0;

};

////////////////// 1-D Array  ////////////////////

template <typename T> 
class Array : public ArrayBase<T>
{
private:
	gr<T> Greater;
	std::vector<T> linearBuffer;

public:
	Array<T>() {
		this->_range = 1;
	}
	Array<T>(int c) {
		this->buffer.resize(c);
		this->_isStatic = (c != 0);
		this->_size[0] = c;
		this->_range = 1;
	}

	Array<T>(std::initializer_list<T> l) {
		this->buffer = l;
		this->_size[0] = this->buffer.size();
		this->_isStatic = (this->_size[0] != 0);
		this->_range = 1;
	}

	Array<T>(int c, std::initializer_list<T> l) {
		this->buffer.resize(c);
		this->_isStatic = (c != 0);
		this->_size[0] = c;
		this->_range = 1;

		this->buffer = std::vector<T>(c);
		int i = 0;
		for (auto it = l.begin(); it < l.end() && i < LinearSize(); it++, i++)
		{
			Set(i, *it);
		}
	}

	virtual int LinearSize() override
	{
		return this->buffer.size();
	}

	int Count() const override
	{
		return this->buffer.size();
	}

	T Get(int i) const {
		if (this->_indexDirection) {
			return this->buffer[this->ReverseIndex(i)];
		}
		return this->buffer[i];
	}

	void Set(int i, T val) {
		if (this->_indexDirection) {
			this->buffer[this->ReverseIndex(i)] = val;
		}
		else {
			this->buffer[i] = val;
		}
	}

	void LoadLinearBuffer() {
		int c = LinearSize();
		linearBuffer.resize(c);
		for (int i = 0; i < c; i++) {
			linearBuffer[i] = Get(i);
		}
	}
	void StoreLinearBuffer() {
		int c = LinearSize();
		for (int i = 0; i < c; i++) {
			Set(i, linearBuffer[i]);
		}
	}

	void Resize(int c0) {
		if (!this->_isStatic) {
			this->buffer.resize(c0);
			this->_size[0] = c0;
		}
	}

	int  Minimum(int count, int start) const
	{
		int iRet = 0;
		T val = 0;
		bool filled = false;
		if (start < 0 || start >= this->buffer.size())
			return -1;
		int cn = count == WHOLE_ARRAY ? this->buffer.size() - start : Min(this->buffer.size() - start, count);
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || val > this->buffer[i]) {
				val = this->buffer[i];
				iRet = i;
				filled = true;
			}
		}
		if (!filled)
			return -1;
		if (!this->_indexDirection)
			return iRet;
		return this->ReverseIndex(iRet);
	}

	int Maximum(int count, int start) const
	{
		int iRet = 0;
		T val = 0;
		bool filled = false;
		if (start < 0 || start >= this->buffer.size())
			return -1;
		int cn = (count == WHOLE_ARRAY ? this->buffer.size() - start : Min(this->buffer.size() - start, count));
		for (int i = start, c = 0; c < cn; i++, c++) {
			T currVal = this->buffer[i];
			if (!filled || ( val < currVal )) {
				val = currVal;
				iRet = i;
				filled = true;
			}
		}
		if (!filled)
			return -1;
		if (!this->_indexDirection)
			return iRet;
		return this->ReverseIndex(iRet);
	}

	virtual bool Sort(int count = WHOLE_ARRAY, int start = 0, int direction = MODE_ASCEND) {
		if (start >= 0 && start < this->buffer.size()) {
			if (direction == MODE_ASCEND) {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? this->buffer.begin() : this->buffer.end() - Min(start + count, this->buffer.size()),
						      this->buffer.end() - start, Greater);
				}
				else {
					std::sort(this->buffer.begin() + start, count <= WHOLE_ARRAY ? this->buffer.end() : this->buffer.begin() + Min(start + count, this->buffer.size()));
				}
			}
			else {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? this->buffer.begin() : this->buffer.end() - Min(start + count, this->buffer.size()), this->buffer.end() - start);
				}
				else {
					std::sort(this->buffer.begin() + start,
						      count == WHOLE_ARRAY ? this->buffer.end() : this->buffer.begin() + Min(start + count, this->buffer.size()), Greater);
				}
			}
			return true;
		}
		return false;
	}

	int CopySeries(int series_index, char* symbol, int timeframe) {
		this->_indexDirection = true;
		if ((symbol == NULL || symbol == Symbol()) &&
            (timeframe == 0 || timeframe == _Period))
        {
			int n = Bars();
			Resize(n);
			switch (series_index) {
			case MODE_OPEN:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = Open(i);
				}
				break;
			case MODE_LOW:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = Low(i);
				}
				break;
			case MODE_HIGH:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = High(i);
				}
				break;
			case MODE_CLOSE:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = Close(i);
				}
				break;
			case MODE_VOLUME:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = Volume(i);
				}
				break;
			case MODE_TIME:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = datetime::FromVariantTime(ft::Time(i));
				}
				break;
			}
		}
		else {
			int n = ft::iBars(symbol, timeframe);
			Resize(n);
			switch (series_index) {
			case MODE_OPEN:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)ft::iOpen(symbol, timeframe, i);
				}
				break;
			case MODE_LOW:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)ft::iLow(symbol, timeframe, i);
				}
				break;
			case MODE_HIGH:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)ft::iHigh(symbol, timeframe, i);
				}
				break;
			case MODE_CLOSE:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)ft::iClose(symbol, timeframe, i);
				}
				break;
			case MODE_VOLUME:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)ft::iVolume(symbol, timeframe, i);
				}
				break;
			case MODE_TIME:
				for (int i = 0; i < n; i++) {
					this->buffer[this->ReverseIndex(i)] = (T)datetime::FromVariantTime(ft::iTime(symbol, timeframe, i));
				}
				break;
			}
		}
		return this->buffer.size();
	}

	int CopySeries(double(*Fn)(char*, int, int), char* symbol, int timeframe) {
		for (int i = 0; i < this->buffer.size(); i++) {
			this->buffer[i] = (T)Fn(symbol, timeframe, i);
		}
		return this->buffer.size();
	}

	int Dimentions() const { return 1; }
};

////////////////// Index Buffer Array  ////////////////////
#ifdef __INDICATOR

class IndexBuffer : public Array<double>
{
public:
	class Item // Proxy class for lvalue operator[]
	{
		friend class IndexBuffer;
	public:
		Item();
		operator double() const;
		Item& operator=(const Item& other);
		Item& operator=(double value);
		Item& operator+=(double value);
		Item& operator-=(double value);
		Item& operator/=(double value);
		Item& operator*=(double value);

		friend double operator+(const IndexBuffer::Item& lhs, const IndexBuffer::Item& rhs);

	private:
		double CheckAndGet() const;
		// Data
		IndexBuffer* ptr_;
		int index_;
		int prev_index_;
	};

	IndexBuffer();

	int Count() const;

	Item& operator[] (int index);
	double operator[] (int index) const;

	void CreateBuffer();
	void SetBuffer(int index) const;
	int Ri(int i) const; // Reverse index

	friend double operator+(const IndexBuffer::Item& lhs, const IndexBuffer::Item& rhs);

private:
	int index_;
	Item item_;
};

// Index Buffer Item ///////////////////////////////

inline IndexBuffer::Item::Item() : ptr_(nullptr), index_(-1), prev_index_(-1) {}

inline IndexBuffer::Item::operator double() const
{
	if(index_ < 0 || index_ > ptr_->Count()-1)
	{
		return 0.0;
	}
	return IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, ptr_->index_, ptr_->Ri(index_));
}

inline IndexBuffer::Item& IndexBuffer::Item::operator=(const Item& other)
{
	if(index_ < 0 || index_ > ptr_->Count()-1)
	{
		static Item empty_item;
		return empty_item;
	}

	if(other.ptr_ == ptr_)
	{
		double val = IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, ptr_->index_, ptr_->Ri(prev_index_));
		IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), val);
		return *this;
	}

	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), (double)other);
	return *this;
}

inline IndexBuffer::Item& IndexBuffer::Item::operator=(double value)
{
	if(index_ < 0 || index_ > ptr_->Count()-1)
	{
		static Item empty_item;
		return empty_item;
	}
	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), value);
	return *this;
}

inline IndexBuffer::Item& IndexBuffer::Item::operator+=(double value)
{
	double d = CheckAndGet();
	d += value;
	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), d);
	return *this;
}

inline IndexBuffer::Item& IndexBuffer::Item::operator-=(double value)
{
	double d = CheckAndGet();
	d -= value;
	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), d);
	return *this;
}

inline IndexBuffer::Item& IndexBuffer::Item::operator/=(double value)
{
	double d = CheckAndGet();
	d /= value;
	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), d);
	return *this;
}

inline IndexBuffer::Item& IndexBuffer::Item::operator*=(double value)
{
	double d = CheckAndGet();
	d *= value;
	IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, ptr_->index_, ptr_->Ri(index_), d);
	return *this;
}

inline double IndexBuffer::Item::CheckAndGet() const
{
	if(index_ < 0 || index_ > ptr_->Count()-1)
	{
		static Item empty_item;
		return empty_item;
	}
	return IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, ptr_->index_, ptr_->Ri(index_));
}

// Index Buffer ///////////////////////////////

inline IndexBuffer::IndexBuffer() : index_(-1)
{
	_indexDirection = true;
	item_.ptr_ = this;
}

inline int IndexBuffer::Count() const
{
	return IntrfProcsRec.GetBufferCount(IntrfProcsRec.pGetBufferCount, index_);
}

inline IndexBuffer::Item& IndexBuffer::operator[] (int index)
{
	item_.prev_index_ = item_.index_;
	item_.index_ = index;
	return item_;
}

inline double IndexBuffer::operator[] (int index) const
{
	if(index < 0 || index > Count()-1)
	{
		return 0.0;
	}
	return IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, index_, Ri(index));
}

inline void IndexBuffer::CreateBuffer()
{
	index_ = IntrfProcsRec.CreateIndexBuffer(IntrfProcsRec.pCreateIndexBuffer);
}

inline void IndexBuffer::SetBuffer(int index) const
{
	IntrfProcsRec.SetIndexBuffer(IntrfProcsRec.pSetIndexBuffer, index, index_);
}

inline int IndexBuffer::Ri(int i) const
{
	if(_indexDirection)
	{
		return Count() - 1 - i;
	}
	
	return i;
}

inline std::ostream& operator<<(std::ostream& os, const IndexBuffer::Item& item)
{
	return os << (double)item;
}

// Operators ///////////////////////////////

inline double operator+(double lhs, const IndexBuffer::Item& rhs) { return lhs + (double)rhs; }
inline double operator+(const IndexBuffer::Item& lhs, double rhs) { return (double)lhs + rhs; }
inline int operator+(int lhs, const IndexBuffer::Item& rhs) { return lhs + (int)(double)rhs; }
inline int operator+(const IndexBuffer::Item& lhs, int rhs) { return (int)(double)lhs + rhs; }
inline double operator+(const IndexBuffer::Item& lhs, const IndexBuffer::Item& rhs)
{
	if(lhs.ptr_ == rhs.ptr_)
	{
		return IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, rhs.ptr_->index_, rhs.ptr_->Ri(rhs.prev_index_)) +
			IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, rhs.ptr_->index_, rhs.ptr_->Ri(rhs.index_));
	}
	
	return (double)lhs + (double)rhs;
}

#endif
////////////////// 2-D Array  ////////////////////

template <typename T> 
class Array2D : public ArrayBase <Array<T> >
{
private:
	gr<T> Greater;
	std::vector<T> linearBuffer;

public:
	Array2D<T>() {
		this->_range = 2;
	}
	Array2D<T>(std::initializer_list <Array<T> > l) {
		this->buffer = l;
		this->_size[0] = this->buffer.size();
		this->_isStatic = (this->_size[0] != 0);
		if (this->_size[0] > 0) {
			this->_size[1] = this->buffer[0].Count();
		}
		this->_range = 2;
	}

	Array2D<T>(int c0, int c1) {
		this->buffer.resize(c0);
		for (int i = 0; i < c0; i++) {
			this->buffer[i] = Array<T>(c1);
		}
		this->_isStatic = (c0 != 0);
		this->_size[0]  = c0;
		this->_size[1] = c1;
		this->_range = 2;
	}

	Array2D<T>(int c0, int c1, std::initializer_list <T> l) {
		this->buffer.resize(c0);
		for (int i = 0; i < c0; i++) {
			this->buffer[i] = Array<T>(c1);
		}
		this->_isStatic = c0 != 0;
		this->_size[0] = c0;
		this->_size[1] = c1;
		this->_range = 2;
		
		int i = 0;
		for (auto it = l.begin(); it < l.end() && i < LinearSize(); it++, i++)
		{
			Set(i, *it);
		}
	}

	int Count() const override
	{
		return this->buffer.size();
	}

	virtual int Range(int rank_index)  override {
		if (rank_index == 0)
		{
			return Count();
		}
		if (rank_index > 0 && rank_index < this->_range && this->buffer.size() > 0) {
			return this->buffer[0].Range(rank_index - 1);
		}
		return 0;
	}

	virtual int LinearSize() override
	{
		if (this->buffer.size() > 0) {
			int cnt = this->buffer[0].LinearSize();
			return this->buffer.size() * cnt;
		}
		return 0;
	}

	virtual int ReverseIndex(int i) const override
	{
		int amount = this->buffer.size();
		if (amount > 0) {
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			return amount - i - 1;
		}
		return 0;
	}

	T Get(int idx) const {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				return this->buffer[j].Get(idx);
			}
		}
		return T(0);
	}

	void Set(int idx, T val) {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				this->buffer[j].Set(idx, val);
			}
		}
	}

	void LoadLinearBuffer() {
		int c = LinearSize();
		linearBuffer.resize(c);
		for (int i = 0; i < c; i++) {
			linearBuffer[i] = Get(i);
		}
	}
	void StoreLinearBuffer() {
		int c = LinearSize();
		for (int i = 0; i < c; i++) {
			Set(i, linearBuffer[i]);
		}
	}

	void Resize(int c0, int c1 = 0) {
		if (!this->_isStatic) {
			this->buffer.resize(c0);
		}
		this->_size[0] = this->buffer.size();
		if (c1 != 0) {
			this->_size[1] = c1;
		}
		for (int i = 0; i < this->_size[0]; i++) {
			this->buffer[i] = Array<T>(this->_size[1]);
		}
	}

	void  Fill(int start, int count, T value) {
		if (this->buffer.size() > 0) {
			int l1 = this->buffer[0].Count();
			int fullSize = this->buffer.size()*l1;
			if (start >= 0 && start < this->buffer.size()*l1 && count > 0) {
				int cn = (count <= WHOLE_ARRAY ? fullSize - start : Min(fullSize - start, count));
				int st = start;
				for (int c = 0; c < cn;) {
					int i = st / l1;
					int idx = st % l1;
					int cnt = Min(l1 - idx, cn - c);
					this->buffer[i].Fill(idx, cnt, value);
					st += cnt;
					c += cnt;
				}
			}
		}
	}

	int Minimum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		bool filled = false;
		LoadLinearBuffer();
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(this->buffer.size() - start, count);
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || val > linearBuffer[i]) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	int  Maximum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		LoadLinearBuffer();
		bool filled = false;
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = (count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(linearBuffer.size() - start, count));
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || (val < linearBuffer[i])) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	bool Sort(int count = WHOLE_ARRAY, int start = 0, int direction = MODE_ASCEND) {
		LoadLinearBuffer();
		if (start >= 0 && start < linearBuffer.size()) {
			if (direction == MODE_ASCEND) {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()),
						      linearBuffer.end() - start, Greater);
				}
				else {
					std::sort(linearBuffer.begin() + start, count <= WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()));
				}
			}
			else {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()), linearBuffer.end() - start);
				}
				else {
					std::sort(linearBuffer.begin() + start, count == WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()), Greater);
				}
			}
			StoreLinearBuffer();
			return true;
		}
		return false;
	}

	int Dimentions() const { return 2; }
};

////////////////// 3-D Array  ////////////////////

template <typename T> 
class Array3D : public ArrayBase< Array2D<T> >
{
private:
	gr<T> Greater;
	std::vector<T> linearBuffer;

public:
	Array3D<T>() {
		this->_range = 3;
	}

	Array3D<T>(std::initializer_list<T> l) 
	{
		int s0 = this->_size[0], s1 = this->_size[1], s2 = this->_size[2];
		this->buffer = std::vector<Array2D<T>>(s0);
		for (size_t i = 0; i < s0; i++)
		{
			this->buffer[i].GetBuffer() = std::vector<Array<T>>(s1);
			for (size_t j = 0; j < s1; j++)
			{
				this->buffer[i].GetBuffer()[j].GetBuffer() = std::vector<T>(s2);
			}
		}

		if (this->_size[0] > 0) {
			this->_isStatic = true;

			auto it = l.begin();
			for (size_t i = 0; i < l.size() && it != l.end() ;)
			{
				Set(i, *it);
				i++;
				it++;
			}
		}
		else {
			this->_isStatic = false;
		}
		this->_range = 3;
	}

	Array3D<T>(std::initializer_list<Array2D <T> > l) {
		this->buffer = l;
		this->_size[0] = this->buffer.size();
		if (this->_size[0] > 0) {
			this->_isStatic = true;
			this->_size[1] = this->buffer[0].Count();
			if (this->_size[1] > 0) {
				this->_size[2] = this->buffer[0][0].Count();
			}
		}
		else {
			this->_isStatic = false;
		}
		this->_range = 3;
	}

	Array3D<T>(int c0, int c1, int c2) {
		this->buffer.resize(c0);
		if (c0 > 0) {
			this->_isStatic = true;
			for (int i = 0; i < c0; i++) {
				this->buffer[i] = Array2D<T>(c1, c2);
			}
		}
		else {
			this->_isStatic = false;
		}
		this->_size[0]  = c0;
		this->_size[1] = c1;
		this->_size[2] = c2;
		this->_range = 3;
	}

	Array3D<T>(int c0, int c1, int c2, std::initializer_list <T> l) {
		this->buffer.resize(c0);
		if (c0 > 0) {
			this->_isStatic = true;
			for (int i = 0; i < c0; i++) {
				this->buffer[i] = Array2D<T>(c1, c2);
			}
		}
		else {
			this->_isStatic = false;
		}
		this->_size[0] = c0;
		this->_size[1] = c1;
		this->_size[2] = c2;
		this->_range = 3;

		int i = 0;
		for (auto it = l.begin(); it < l.end() && i < LinearSize(); it++, i++)
		{
			Set(i, *it);
		}
	}

	int Count() const override
	{
		return this->buffer.size();
	}

	virtual int Range(int rank_index)  override {
		if (rank_index == 0)
		{
			return Count();
		}
		if (rank_index > 0 && rank_index < this->_range && this->buffer.size() > 0) {
			return this->buffer[0].Range(rank_index - 1);
		}
		return 0;
	}

	virtual int LinearSize() override
	{
		if (this->buffer.size() > 0) {
			return this->buffer.size() * this->buffer[0].LinearSize();
		}
		return 0;
	}

	void Resize(int c0, int c1 = 0, int c2 = 0) {
		if (!this->_isStatic) {
			this->buffer.resize(c0);
		}
		this->_size[0] = this->buffer.size();
		if (c1 != 0) {
			this->_size[1] = c1;
		}
		if (c2 != 0) {
			this->_size[2] = c2;
		}
		for (int i = 0; i < this->_size[0]; i++) {
			this->buffer[i] = Array2D<T>(this->_size[1], this->_size[2]);
		}
	}

	virtual int ReverseIndex(int i) const override
	{
		int amount = this->buffer.size();
		if (amount > 0) {
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			return amount - i - 1;
		}
		return 0;
	}

	T Get(int idx) const {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				return this->buffer[j].Get(idx);
			}
		}
		return T(0);
	}

	void Set(int idx, T val) {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				this->buffer[j].Set(idx, val);
			}
		}
	}

	void LoadLinearBuffer() {
		int c = LinearSize();
		linearBuffer.resize(c);
		for (int i = 0; i < c; i++) {
			linearBuffer[i] = Get(i);
		}
	}
	void StoreLinearBuffer() {
		int c = LinearSize();
		for (int i = 0; i < c; i++) {
			Set(i, linearBuffer[i]);
		}
	}

	void  Fill(int start, int count, T value) {
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			int fullSize = this->buffer.size()*amount;
			if (start >= 0 && start < fullSize && count > 0) {
				int cn = (count <= WHOLE_ARRAY ? fullSize - start : Min(fullSize - start, count));
				int st = start;
				for (int c = 0; c < cn;) {
					int i = st / amount;
					int idx = st % amount;
					int cnt = Min(amount - idx, cn - c);
					this->buffer[i].Fill(idx, cnt, value);
					st += cnt;
					c += cnt;
				}
			}
		}
	}

	int Minimum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		bool filled = false;
		LoadLinearBuffer();
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(this->buffer.size() - start, count);
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || val > linearBuffer[i]) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	int  Maximum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		LoadLinearBuffer();
		bool filled = false;
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = (count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(linearBuffer.size() - start, count));
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || (val < linearBuffer[i])) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	bool Sort(int count = WHOLE_ARRAY, int start = 0, int direction = MODE_ASCEND) {
		LoadLinearBuffer();
		if (start >= 0 && start < linearBuffer.size()) {
			if (direction == MODE_ASCEND) {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()),
						      linearBuffer.end() - start, Greater);
				}
				else {
					std::sort(linearBuffer.begin() + start, count <= WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()));
				}
			}
			else {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()), linearBuffer.end() - start);
				}
				else {
					std::sort(linearBuffer.begin() + start, count == WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()), Greater);
				}
			}
			StoreLinearBuffer();
			return true;
		}
		return false;
	}

	int Dimentions() const { return 3; }
};

////////////////// 4-D Array  ////////////////////

template <typename T> 
class Array4D : public ArrayBase< Array3D<T> >
{
private:
	gr<T> Greater;
	std::vector<T> linearBuffer;

public:
	Array4D<T>() {
		this->_range = 4;
	}

	Array4D<T>(std::initializer_list<T> l)
	{
		int s0 = this->_size[0], s1 = this->_size[1], s2 = this->_size[2], s3 = this->_size[3];

		this->buffer = std::vector<Array3D<T>>(s0);
		
		for (size_t i = 0; i < s0; i++)
		{
			this->buffer[i].GetBuffer() = std::vector<Array2D<T>>(s1);
			for (size_t j = 0; j < s1; j++)
			{
				this->buffer[i].GetBuffer()[j].GetBuffer() = std::vector<Array<T>>(s2);

				for (size_t k = 0; k < s2; k++)
				{
					this->buffer[i].GetBuffer()[j].GetBuffer()[k].GetBuffer() = std::vector<T>(s3);
				}
			}
		}

		if (this->_size[0] > 0) {
			this->_isStatic = true;

			auto it = l.begin();
			for (size_t i = 0; i < l.size() && it != l.end();)
			{
				Set(i, *it);
				i++;
				it++;
			}
		}
		else {
			this->_isStatic = false;
		}
		this->_range = 4;
	}

	Array4D<T>(std::initializer_list<Array3D<T> > l) {
		this->buffer = l;
		this->_size[0] = this->buffer.size();
		if (this->_size[0] > 0) {
			this->_isStatic = true;
			this->_size[1] = this->buffer[0].Count();
			if (this->_size[1] > 0) {
				this->_size[2] = this->buffer[0][0].Count();
				if (this->_size[2] > 0) {
					this->_size[3] = this->buffer[0][0][0].Count();
				}
			}
		}
		else
			this->_isStatic = false;
		this->_range = 4;
	}

	Array4D<T>(int c0, int c1, int c2, int c3) {
		this->buffer.resize(c0);
		if (c0 > 0) {
			this->_isStatic = true;
			for (int i = 0; i < c0; i++) {
				this->buffer[i] = Array3D<T>(c1, c2, c3);
			}
		}
		else
			this->_isStatic = false;
		this->_size[0]  = c0;
		this->_size[1] = c1;
		this->_size[2] = c2;
		this->_size[3] = c3;
		this->_range = 4;
	}

	Array4D<T>(int c0, int c1, int c2, int c3, std::initializer_list <T> l) {
		//this->buffer = l;
		this->buffer.resize(c0);
		if (c0 > 0) {
			this->_isStatic = true;
			for (int i = 0; i < c0; i++) {
				this->buffer[i] = Array3D<T>(c1, c2, c3);
			}
		}
		else
			this->_isStatic = false;
		this->_size[0]  = c0;
		this->_size[1] = c1;
		this->_size[2] = c2;
		this->_size[3] = c3;
		this->_range = 4;

		int i = 0;
		for (auto it = l.begin(); it < l.end() && i < LinearSize(); it++, i++)
		{
			Set(i, *it);
		}
	}

	virtual int Range(int rank_index) override {
		if (rank_index == 0)
		{
			return this->buffer.size();
		}
		if (rank_index > 0 && rank_index < this->_range && this->buffer.size() > 0) {
			return this->buffer[0].Range(rank_index - 1);
		}
		return 0;
	}

	virtual int LinearSize() override
	{
		if (this->buffer.size() > 0) {
			return this->buffer.size() * this->buffer[0].LinearSize();
		}
		return 0;
	}

	virtual int ReverseIndex(int i) const override
	{
		int amount = this->buffer.size();
		if (amount > 0) {
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			return amount - i - 1;
		}
		return 0;
	}

	T Get(int idx) const {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				return this->buffer[j].Get(idx);
			}
		}
		return T(0);
	}

	void Set(int idx, T val) {
		int index = this->_indexDirection ? ReverseIndex(idx) : idx;
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			if (amount > 0) {
				int j = index / amount;
				int idx = index % amount;
				this->buffer[j].Set(idx, val);
			}
		}
	}

	void LoadLinearBuffer() {
		int c = LinearSize();
		linearBuffer.resize(c);
		for (int i = 0; i < c; i++) {
			linearBuffer[i] = Get(i);
		}
	}

	void StoreLinearBuffer() {
		int c = LinearSize();
		for (int i = 0; i < c; i++) {
			Set(i, linearBuffer[i]);
		}
	}

	void Resize(int c0, int c1 = 0, int c2 = 0, int c3 = 0) {
		if (!this->_isStatic) {
			this->buffer.resize(c0);
		}
		this->_size[0] = this->buffer.size();
		if (c1 != 0) {
			this->_size[1] = c1;
		}
		if (c2 != 0) {
			this->_size[2] = c2;
		}
		if (c3 != 0) {
			this->_size[3] = c3;
		}
		for (int i = 0; i < this->_size[0]; i++) {
			this->buffer[i] = Array3D<T>(this->_size[1], this->_size[2], this->_size[3]);
		}
	}

	void  Fill(int start, int count, T value) {
		if (this->buffer.size() > 0) {
			int amount = 1;
			for (int i = 1; i < this->_range; i++) {
				amount *= this->_size[i];
			}
			int fullSize = this->buffer.size()*amount;
			if (start >= 0 && start < fullSize && count > 0) {
				int cn = (count <= WHOLE_ARRAY ? fullSize - start : Min(fullSize - start, count));
				int st = start;
				for (int c = 0; c < cn;) {
					int i = st / amount;
					int idx = st % amount;
					int cnt = Min(amount - idx, cn - c);
					this->buffer[i].Fill(idx, cnt, value);
					st += cnt;
					c += cnt;
				}
			}
		}
	}

	int Minimum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		bool filled = false;
		LoadLinearBuffer();
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(this->buffer.size() - start, count);
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || val > linearBuffer[i]) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	int  Maximum(int count, int start)
	{
		int iRet = 0;
		T val = 0;
		LoadLinearBuffer();
		bool filled = false;
		if (start < 0 || start >= linearBuffer.size())
			return -1;
		int cn = (count == WHOLE_ARRAY ? linearBuffer.size() - start : Min(linearBuffer.size() - start, count));
		for (int i = start, c = 0; c < cn; i++, c++) {
			if (!filled || (val < linearBuffer[i])) {
				val = linearBuffer[i];
				iRet = i;
				filled = true;
			}
		}
		return filled ? iRet : -1;
	}

	bool Sort(int count = WHOLE_ARRAY, int start = 0, int direction = MODE_ASCEND) {
		LoadLinearBuffer();
		if (start >= 0 && start < linearBuffer.size()) {
			if (direction == MODE_ASCEND) {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()),
						      linearBuffer.end() - start, Greater);
				}
				else {
					std::sort(linearBuffer.begin() + start, count <= WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()));
				}
			}
			else {
				if (this->_indexDirection) {
					std::sort(count == WHOLE_ARRAY ? linearBuffer.begin() : linearBuffer.end() - Min(start + count, linearBuffer.size()), linearBuffer.end() - start);
				}
				else {
					std::sort(linearBuffer.begin() + start, count == WHOLE_ARRAY ? linearBuffer.end() : linearBuffer.begin() + Min(start + count, linearBuffer.size()), Greater);
				}
			}
			StoreLinearBuffer();
			return true;
		}
		return false;
	}

	int Dimentions() const { return 3; }
};
