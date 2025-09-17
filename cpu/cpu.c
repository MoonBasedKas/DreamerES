#include <stdio.h>
#include <stdlib.h>
#include "../cpu.h"

/**
 * @brief Inits the Cpu registers and returns it.
 *
 * @return struct CpuRegisters*
 */
struct CpuRegisters *initCpuReg()
{
    struct CpuRegisters *new = calloc(0, sizeof(struct CpuRegisters));
    new->SP = StackStart;
    return new;
}

/**
 * @brief Reads a provided rom
 *
 * @param loc, file we are reading.
 */
void RomRead(char *loc)
{
    FILE *fp = fopen(loc, "rb");
    fread(RomHeader, 1, ftell(fp), fp);
    fread(CpuRom, 1, ftell(fp) - RomHeaderSize, fp);
    CpuRegs->PC = ((ushort)CpuRead(0xFFFD) * 0x100) + (ushort)CpuRead(0xFFFC);
    fclose(fp);
}

void Reset(char *loc)
{
    FILE *fp = fopen(loc, "rb");
    fread(RomHeader, 1, ftell(fp), fp);
    fread(CpuRom, 1, ftell(fp) - RomHeaderSize, fp);

    CpuRegs->PC = ((ushort)CpuRead(0xFFFD) * 0x100) + (ushort)CpuRead(0xFFFC);
    fclose(fp);
}

/**
 * @brief Performs a read from the CpuRom
 *
 * @param address
 * @return char
 */
byte CpuRead(ushort address)
{
    if (address < RAMSize)
    {
        return CpuRam[address];
    }
    else if (address < RAMMirrorTwo)
    {
        return CpuRam[address - RAMMirrorOne];
    }
    else if (address < RAMMIrrorThree)
    {
        return CpuRam[address - RAMMirrorTwo];
    }
    else if (address < RAMMirrorLimit)
    {
        return CpuRam[address - RAMMIrrorThree];
    }
    return CpuRom[address];
}

int CpuWrite(ushort address, byte value)
{
    if (address < RAMSize)
    {
        CpuRam[address] = value;
    }
    else if (address < RAMMirrorTwo)
    {
        CpuRam[address - RAMMirrorOne] = value;
    }
    else if (address < RAMMIrrorThree)
    {
        CpuRam[address - RAMMirrorTwo] = value;
    }
    else if (address < RAMMirrorLimit)
    {
        CpuRam[address - RAMMIrrorThree] = value;
    }

    CpuRom[address] = value;
    return 0;
}

/**
 * @brief Generates an address with the current PC
 *
 * @return ushort
 */
ushort readAddress()
{
    byte low = CpuRead(CpuRegs->PC++);
    byte high = CpuRead(CpuRegs->PC);
    return ((ushort)high * 0x100) + (ushort)low;
}