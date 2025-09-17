#ifndef CPU_H
#define CPU_H

#define StackStart (ushort)0x01FF
#define ROMSize 0x8000
#define RomHeaderSize 0x10

#define RAMSize 0x0800
#define RAMMirrorOne 0x800
#define RAMMirrorTwo 0x1000
#define RAMMIrrorThree 0x1800
#define RAMMirrorLimit 0x2000

#define kilobyte 1024

/// @brief 100x faster than writing unsigned char everywhere.
typedef unsigned char byte;
///@brief 100x faster than writing unsigned short everywhere.
typedef unsigned short ushort;

enum CpuFlags
{

    Negative = 0b10000000,
    Overflow = 0b01000000,
    Decimal = 0b00001000,
    InteruptDisable = 0b00000100,
    Zero = 0b00000010,
    Carry = 0b00000001
};

struct CpuRegisters
{
    ushort PC; // Program counter
    byte SP;   // stack pointer 0x0100 -> 0x01FF
    byte A;    // Accumulator
    // X and Y registers.
    byte X;
    byte Y;

    byte status; // status register, NOTE we only use 6 of these.
    // Negative, Overflow, N/A, N/A, Decimal, Interrupt Disable, Zero, Carry
};

void RomRead(char *loc);
void Reset(char *loc);
byte CpuRead(ushort address);
int CpuWrite(ushort address, byte value);
int execInstruction();

#endif