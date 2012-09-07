#include "BinaryReader.hpp"
#include "IOException.hpp"
#include "FileNotFoundException.hpp"

#include <stdio.h>
#include <stdlib.h>

BinaryReader::BinaryReader(const Stream& stream) :
    Stream(stream)
{}

void BinaryReader::WriteByte(Int8)
{
    throw IOException("BinaryReader::WriteByte() -> Stream not open for writing");
}

void BinaryReader::WriteBytes(Int8*, Int64)
{
    throw IOException("BinaryReader::WriteBytes() -> Stream not open for writing");
}

Int16 BinaryReader::ReadInt16()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadInt16() -> Position outside stream bounds: " + m_position);
    Int16 ret = *(Int16*)(m_data + m_position);
    m_position += sizeof(Int16);
    return ret;
}

Uint16 BinaryReader::ReadUInt16()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadUint16() -> Position outside stream bounds: " + m_position);
    Uint16 ret = *(Uint16*)(m_data + m_position);
    m_position += sizeof(Uint16);
    return ret;
}

Int32 BinaryReader::ReadInt32()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadUint32() -> Position outside stream bounds");
    Int32 ret = *(Int32*)(m_data + m_position);
    m_position += sizeof(Int32);
    return ret;
}

Uint32 BinaryReader::ReadUInt32()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadUint32() -> Position outside stream bounds");

    Uint32 ret = *(Uint32*)(m_data + m_position);
    m_position += sizeof(Uint32);
    return ret;
}

Int64 BinaryReader::ReadInt64()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadInt64() -> Position outside stream bounds");

    Int64 ret = *(Int64*)(m_data + m_position);
    m_position += sizeof(Int64);
    return ret;
}

Uint64 BinaryReader::ReadUInt64()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadUInt64() -> Position outside stream bounds");
    Uint64 ret = *(Uint64*)(m_data + m_position);
    m_position += sizeof(Uint64);
    return ret;
}

float BinaryReader::ReadFloat()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadFloat() -> Position outside stream bounds");

    float ret = *(float*)(m_data + m_position);
    m_position += sizeof(float);
    return ret;
}

double BinaryReader::ReadDouble()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadDouble() -> Position outside stream bounds");

    double ret = *(double*)(m_data + m_position);
    m_position += sizeof(double);

    return ret;
}

bool BinaryReader::ReadBool()
{
    if (m_position > m_length || m_position <= 0)
        throw IOException("BinaryReader::ReadBool() -> Position outside stream bounds");

    bool ret = *(bool*)(m_data + m_position);
    m_position += sizeof(bool);
    return ret;
}
