#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)																		//alokuje si rovnaku pamat
	{
		//TODO 01: Vector
		//throw std::exception("Vector::Vector: Not implemented yet.");
		memory_ = memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		//TODO 01: Vector
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			size_ = other.size_;
			memory_ = realloc(memory_, size_);
			memory_ = memcpy(memory_, other.memory_, size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		return (size_ == other.size_) && (memcmp(memory_, other.memory_, size_) == 0);
		/*if (size_ == other.size_)
		{
			if (memcmp(memory_, other.memory_, size_) == 0)
			{
				return true;
			}
		}
		return false;*/
	}

	byte& Vector::operator[](const int index)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");										//keby to nahodou pretieklo
		return *(reinterpret_cast<byte*>(memory_) + index);															//vrati pointer
	}


	byte Vector::operator[](const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");										//keby to nahodou pretieklo
		return *(reinterpret_cast<byte*>(memory_) + index);															//vrati pointer
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		DSRoutines::rangeCheck(index + count, size_, true);
		memcpy(&dest, reinterpret_cast<byte*>(memory_) + index, count);
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length > 0)
		{
			DSRoutines::rangeCheck(srcStartIndex, src.size_, true);
			DSRoutines::rangeCheck(srcStartIndex + length, src.size_ + 1, true);
			DSRoutines::rangeCheck(destStartIndex, dest.size_, true);
			DSRoutines::rangeCheck(destStartIndex + length, dest.size_ + 1, true);

			if (src.memory_ != dest.memory_)
			{
				memcpy(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
			}
			else
			{
				memmove(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
			}
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");										//keby to nahodou pretieklo
		return (reinterpret_cast<byte*>(memory_) + index);															//vrati pointer
	}

}