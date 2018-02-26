#include "memory_routines.h"
#include <stdexcept>
namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		return B = 255;
	}
	byte & MemoryRoutines::byteReset(byte & B)
	{
		return B = 0;
	}
	byte & MemoryRoutines::byteXOR(byte & B)
	{
		return B ^= 255;
	}
	byte & MemoryRoutines::byteSHL(byte & B)
	{
		return B = B << 1;
	}
	byte & MemoryRoutines::byteSHR(byte & B)
	{
		return B = B >> 1;
	}
	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		if (n < 0 || n > 7)
		{
			throw std::invalid_argument("Zle poradie bitu! Poradie bitu musi byt v intervale <0,7>!");
		}
		return (B >> n) & 1;
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		if (n < 0 || n > 7)
		{
			throw std::invalid_argument("Zle poradie bitu! Poradie bitu musi byt v intervale <0,7>!");
		}
		byte num = 1;
		num <<= n;
		num = ~num;
		return B &= num;
	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		if (n < 0 || n > 7)
		{
			throw std::invalid_argument("Zle poradie bitu! Poradie bitu musi byt v intervale <0,7>!");
		}
		byte num = 1;
		num <<= n;
		return B |= num;
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		if (n < 0 || n > 7)
		{
			throw std::invalid_argument("Zle poradie bitu! Poradie bitu musi byt v intervale <0,7>!");
		}
		byte num = 1;
		num <<= n;
		return B ^= num;
	}

	MemoryRoutines::MemoryRoutines()
	{
	}

}
