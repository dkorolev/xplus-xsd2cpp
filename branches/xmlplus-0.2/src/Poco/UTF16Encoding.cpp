//
// UTF16Encoding.cpp
//
// $Id: //poco/1.3/Foundation/src/UTF16Encoding.cpp#5 $
//
// Library: Foundation
// Package: Text
// Module:  UTF16Encoding
//
// Copyright (c) 2004-2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/UTF16Encoding.h"
#include "Poco/ByteOrder.h"
#include "Poco/String.h"


namespace Poco {


const char* UTF16Encoding::_names[] =
{
	"UTF-16",
	"UTF16",
	NULL
};


const TextEncoding::CharacterMap UTF16Encoding::_charMap = 
{
	/* 00 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 10 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 20 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 30 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 40 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 50 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 60 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 70 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 80 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* 90 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* a0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* b0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* c0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* d0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* e0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
	/* f0 */	-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 
};


UTF16Encoding::UTF16Encoding(ByteOrderType byteOrder)
{
	setByteOrder(byteOrder);
}

	
UTF16Encoding::UTF16Encoding(int byteOrderMark)
{
	setByteOrder(byteOrderMark);
}

	
UTF16Encoding::~UTF16Encoding()
{
}


UTF16Encoding::ByteOrderType UTF16Encoding::getByteOrder() const
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	return _flipBytes ? LITTLE_ENDIAN_BYTE_ORDER : BIG_ENDIAN_BYTE_ORDER;
#else
	return _flipBytes ? BIG_ENDIAN_BYTE_ORDER : LITTLE_ENDIAN_BYTE_ORDER;
#endif
}

	
void UTF16Encoding::setByteOrder(ByteOrderType byteOrder)
{
#if defined(POCO_ARCH_BIG_ENDIAN)
	_flipBytes = byteOrder == LITTLE_ENDIAN_BYTE_ORDER;
#else
	_flipBytes = byteOrder == BIG_ENDIAN_BYTE_ORDER;;
#endif
}

	
void UTF16Encoding::setByteOrder(int byteOrderMark)
{
	_flipBytes = byteOrderMark != 0xFEFF;
}


const char* UTF16Encoding::canonicalName() const
{
	return _names[0];
}


bool UTF16Encoding::isA(const std::string& encodingName) const
{
	for (const char** name = _names; *name; ++name)
	{
		if (Poco::icompare(encodingName, *name) == 0)
			return true;
	}
	return false;
}


const TextEncoding::CharacterMap& UTF16Encoding::characterMap() const
{
	return _charMap;
}


int UTF16Encoding::convert(const unsigned char* bytes) const
{
	UInt16 uc;
	unsigned char* p = (unsigned char*) &uc;
	*p++ = *bytes++;
	*p++ = *bytes++;

	if (_flipBytes)
	{
		ByteOrder::flipBytes(uc);
	}

	if (uc >= 0xd800 && uc < 0xdc00)
	{
		UInt16 uc2;
		p = (unsigned char*) &uc2;
		*p++ = *bytes++;
		*p++ = *bytes++;

		if (_flipBytes)
		{
			ByteOrder::flipBytes(uc2);
		}
		if (uc2 >= 0xdc00 && uc2 < 0xe000)
		{
			return ((uc & 0x3ff) << 10) + (uc2 & 0x3ff) + 0x10000;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return uc;
	}
}


int UTF16Encoding::convert(int ch, unsigned char* bytes, int length) const
{
	if (ch <= 0xFFFF)
	{
		if (bytes && length >= 2)
		{
			UInt16 ch1 = _flipBytes ? ByteOrder::flipBytes((UInt16) ch) : (UInt16) ch;
			unsigned char* p = (unsigned char*) &ch1;
			*bytes++ = *p++;
			*bytes++ = *p++;
		}
		return 2;
	}
	else
	{
		if (bytes && length >= 4)
		{
			int ch1 = ch - 0x10000;
			UInt16 w1 = 0xD800 + ((ch1 >> 10) & 0x3FF);
			UInt16 w2 = 0xDC00 + (ch1 & 0x3FF);
			if (_flipBytes)
			{
				w1 = ByteOrder::flipBytes(w1);
				w2 = ByteOrder::flipBytes(w2);
			}
			unsigned char* p = (unsigned char*) &w1;
			*bytes++ = *p++;
			*bytes++ = *p++;
			p = (unsigned char*) &w2;
			*bytes++ = *p++;
			*bytes++ = *p++;
		}
		return 4;
	}
}


int UTF16Encoding::queryConvert(const unsigned char* bytes, int length) const
{
	int ret = -2;

	if (length >= 2)
	{
		UInt16 uc;
		unsigned char* p = (unsigned char*) &uc;
		*p++ = *bytes++;
		*p++ = *bytes++;
		if (_flipBytes) 
			ByteOrder::flipBytes(ret);
		if (uc >= 0xd800 && uc < 0xdc00)
		{
			if (length >= 4)
			{
				UInt16 uc2;
				p = (unsigned char*) &uc2;
				*p++ = *bytes++;
				*p++ = *bytes++;
				if (_flipBytes) 
					ByteOrder::flipBytes(ret);
				if (uc2 >= 0xdc00 && uc < 0xe000)
				{
					ret = ((uc & 0x3ff) << 10) + (uc2 & 0x3ff) + 0x10000;
				}
				else
				{
					ret = -1;	// Malformed sequence
				}
			}
			else
			{
				ret = -4;	// surrogate pair, four bytes needed
			}
		}
		else
		{
			ret = uc;
		}
	}

	return ret;
}


int UTF16Encoding::sequenceLength(const unsigned char* bytes, int length) const
{
	int ret = -2;

	if (_flipBytes)
	{
		if (length >= 1)
		{
			unsigned char c = *bytes;
			if (c >= 0xd8 && c < 0xdc)
				ret = 4;
			else
				ret = 2;
		}
	}
	else
	{
		if (length >= 2)
		{
			UInt16 uc;
			unsigned char* p = (unsigned char*) &uc;
			*p++ = *bytes++;
			*p++ = *bytes++;
			if (uc >= 0xd800 && uc < 0xdc00)
				ret = 4;
			else
				ret = 2;
		}
	}
	return ret;
}


} // namespace Poco