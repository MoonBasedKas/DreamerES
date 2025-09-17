#include "../cpu.h"

int execInstruction()
{
    byte op = CpuRead(CpuRegs->PC);
    CpuRegs->PC++;
    // Low/high bytes of each opcode.
    byte low = 0;
    byte high = 0;
    ushort temp = 0;
    switch (op)
    {
    /// @brief LDA - Load A
    case 0xA9: // Immediate
    case 0xB5: // Zero page, X
    case 0xA5: // Zero Page
    case 0xBD: // Absolute, X
    case 0xB9: // Absolute, Y
    case 0xAD: // Absolute
    case 0xA1: // (Indirect, X)
    case 0xB1: // (Inderect), Y
        LDA(op, low, high, temp);
        break;

    /// @brief STA - Store A
    case 0x95: // Zero page, X
    case 0x85: // Zero Page
    case 0x9D: // Absolute, X
    case 0x99: // Absolute, Y
    case 0x8D: // Absolute
    case 0x81: // (Indirect, X)
    case 0x91: // (Inderect), Y
        STA(op, low, high, temp);
        break;

    /// @brief LDY - Load Y
    case 0xA0: // Immediate
    case 0xB4: // Zero page, X
    case 0xA4: // Zero PAge
    case 0xBC: // Absolute, X
    case 0xAC: // Absolute
        LDY(op, low, high, temp);
        break;

    /// @brief STY - Store Y
    case 0x84: // Zero Page
    case 0x94: // Zero page, X
    case 0x8c: // Absolute
        break;

    /// @brief LDX - Load X
    case 0xA2: // Immediate
        CpuRegs->X = CpuRead(CpuRegs->PC);
        CpuRegs->PC++;
        cycles += tempValue;
        break;
    case 0xA6: // Zero PAge
    case 0xB6: // Zero page, Y
    case 0xAE: // Absolute
    case 0xBE: // Absolute, Y
        break;

    /// @brief STX - Store X
    case 0x86: // Zero PAge
    case 0x96: // Zero page, Y
    case 0x8E: // Absolute
        break;

    /// @brief TAX - transfer a to x
    case 0xAA:
        CpuRegs->X = CpuRegs->A;
        cycles += tempValue;
        break;

    /// @brief TXA - transfer x to a
    case 0x8A:
        CpuRegs->A = CpuRegs->X;
        cycles += tempValue;
        break;

    /// @brief TAY - transfer a to y
    case 0xA8:
        CpuRegs->Y = CpuRegs->A;
        cycles += tempValue;
        break;

    /// @brief TYA - Transfer y to a
    case 0x98:
        CpuRegs->A = CpuRegs->Y;
        cycles += tempValue;
        break;

    /// @brief ADC - Add with carry
    case 0x69: // Immediate
    case 0x65: // Zero Page
    case 0x75: // Zero page, X
    case 0x6D: // Absolute
    case 0x7D: // Absolute, X
    case 0x79: // Absolute, Y
    case 0x61: // (Indirect, X)
    case 0x71: // (Inderect), Y
        break;

    /// @brief SBC - Subtract with carry
    case 0xE9: // Immediate
    case 0xE5: // Zero PAge
    case 0xF5: // Zero page, X
    case 0xED: // Absolute
    case 0xFD: // Absolute, X
    case 0xF9: // Absolute, Y
    case 0xE1: // (Indirect, X)
    case 0xF1: // (Inderect), Y
        break;

    /// @brief INC - Increment memory
    case 0xE6: // Zero page
    case 0xF6: // zero page, x
    case 0xEE: // absolute
    case 0xFE: // absolute, X
        break;

    /// @brief DEC - Decrement memory
    case 0xC6: // Zero page
    case 0xD6: // zero page, x
    case 0xCE: // absolute
    case 0xDE: // absolute, X
        break;

    /// @brief INX - Increment X
    case 0xE8:
        CpuRegs->X++;
        cycles += tempValue;
        break;

    /// @brief DEX - Decrement X
    case 0xCA:
        CpuRegs->X--;
        cycles += tempValue;
        break;

    /// @brief INY - Increment Y
    case 0xC8:
        CpuRegs->Y++;
        cycles += tempValue;
        break;

    /// @brief DEY - Decrement Y
    case 0x88:
        CpuRegs->Y--;
        cycles += tempValue;
        break;

    /// @brief ASL - arithmetic shift left
    case 0x0A: // Accumulator
    case 0x06: // Zero page
    case 0x16: // zero page, x
    case 0x0E: // absolute
    case 0x1E: // absolute, X
        break;

    /// @brief LSR - Logical Shift Right
    case 0x4A: // Accumulator
    case 0x46: // Zero page
    case 0x56: // zero page, x
    case 0x4E: // absolute
    case 0x5E: // absolute, X
        break;

    /// @brief ROL - Rotate Left
    case 0x2A: // Accumulator
    case 0x26: // Zero page
    case 0x36: // zero page, x
    case 0x2E: // absolute
    case 0x3E: // absolute, X
        break;

    /// @brief ROR - Rotate Right
    case 0x6A: // Accumulator
    case 0x66: // Zero page
    case 0x76: // zero page, x
    case 0x6E: // absolute
    case 0x7E: // absolute, X
        break;

    /// @brief AND - Bitwise and
    case 0x29: // Immediate
    case 0x25: // Zero PAge
    case 0x35: // Zero page, X
    case 0x2D: // Absolute
    case 0x3D: // Absolute, X
    case 0x39: // Absolute, Y
    case 0x21: // (Indirect, X)
    case 0x31: // (Inderect), Y
        break;

    /// @brief ORA - Bitwise or
    case 0x09: // Immediate
    case 0x05: // Zero PAge
    case 0x15: // Zero page, X
    case 0x0D: // Absolute
    case 0x1D: // Absolute, X
    case 0x19: // Absolute, Y
    case 0x01: // (Indirect, X)
    case 0x11: // (Inderect), Y
        break;

    /// @brief EOR - Bitwise xor
    case 0x49: // Immediate
    case 0x45: // Zero PAge
    case 0x55: // Zero page, X
    case 0x4D: // Absolute
    case 0x5D: // Absolute, X
    case 0x59: // Absolute, Y
    case 0x41: // (Indirect, X)
    case 0x51: // (Inderect), Y
        break;

    /// @brief BIT - Bit test?
    case 0x24: // zero page
    case 0x2C: // absolute
        break;
    /// @brief CMP - Compare A
    case 0xC9: // Immediate
    case 0xC5: // Zero PAge
    case 0xD5: // Zero page, X
    case 0xCD: // Absolute
    case 0xDD: // Absolute, X
    case 0xD9: // Absolute, Y
    case 0xC1: // (Indirect, X)
    case 0xD1: // (Inderect), Y
        break;

    /// @brief CPX - Compare X
    case 0xE0: // Immediate
    case 0xE4: // Zero page
    case 0xEC: // Absolute
        break;

    /// @brief CPY - Compare Y
    case 0xC0: // Immediate
    case 0xC4: // Zero page
    case 0xCC: // Absolute
        break;

    /// @brief BCC - Branch if carry clear
    case 0x90:
        break;
    /// @brief BCS - Branch if  carry set
    case 0xB0:
        break;
    /// @brief BEQ - Branch if equal
    case 0xF0:
        break;
    /// @brief BNE - Branch if not equal
    case 0xD0:
        break;
    /// @brief BPL - Branch if plus
    case 0x10:
        break;
    /// @brief BMI - Branch if Minus
    case 0x30:
        break;
    /// @brief BVC - Branch if overflow clear
    case 0x50:
        break;

    /// @brief BVS - Branch if overflow set
    case 0x70:
        break;

    /// @brief JMP - Jump
    case 0x4C: // Absolute
    case 0x6C: // (indirect)
        break;

    /// @brief JSR - Jump to subroutine
    case 0x20:
        // TODO Push return address onto stack.
        temp += readAddress();
        CpuRegs->PC = CpuRead(temp);
        cycles += tempValue;
        break;
    /// @brief RTS - Return from subroutine
    case 0x60:
        break;

    /// @brief BRK - Break (software interupt request)
    case 0x00: // Implied and immediate
        break;

    /// @brief RTI - Return from interupt
    case 0x40:
        break;

    /// @brief PHA - Push A
    case 0x48:
        break;
    /// @brief PLA - Pull A
    case 0x68:
        break;
    /// @brief PHP - Push processor status
    case 0x08:
        break;
    /// @brief PLP - Pull processor status
    case 0x28:
        break;
    /// @brief TXS - Transfer X to stack pointer
    case 0x9A:
        break;

    /// @brief TSX - Transfer stack pointer to X
    case 0xBA:
        break;
    /// @brief NOP - no operation
    case 0xEA:
        cycles += tempValue;
        break;

    // --- Flags ---
    /// @brief CLC - clears the carry flag
    case 0x18:
        if (CpuRegs->status & Carry)
            CpuRegs->status ^= Carry;
        cycles += tempValue;
        break;
    /// @brief SEC - Set carry
    case 0x38:
        CpuRegs->status |= Carry;
        cycles += tempValue;
        break;

    /// @brief CLI - Clear interupt disable
    case 0x58:
        if (CpuRegs->status & InteruptDisable)
            CpuRegs->status ^= InteruptDisable;
        cycles += tempValue;
        break;

    /// @brief SEI - Set interupt disable
    case 0x78:
        CpuRegs->status |= InteruptDisable;
        cycles += tempValue;
        break;

    /// @brief CLD - Clears the decimal flag.
    case 0xD8:
        if (CpuRegs->status & Decimal)
            CpuRegs->status ^= Decimal;
        cycles += tempValue;
        break;

    /// @brief SED - Set decimal
    case 0xF8:
        CpuRegs->status |= Decimal;
        cycles += tempValue;
        break;

    /// @brief CLV - clear overflow
    case 0xB8:
        if (CpuRegs->status & Overflow)
            CpuRegs->status ^= Overflow;
        cycles += tempValue;
        break;

    // Unofficial op code, treat as No op.
    default:
        break;
    }

    return 0;
}

/**
 * @brief Performs the LDA operation and its various addressing modes. Load A
 *
 * @param op
 * @return int
 */
int LDA(byte op, byte low, byte high, ushort temp)
{

    switch (op)
    {
    case 0xA9: // Immediate
        CpuRegs->A = CpuRead(CpuRegs->PC);
        CpuRegs->PC++;
        cycles += 2;
        break;

    case 0xB5: // Zero page, X
        temp = CpuRegs->X;
        cycles += tempValue;
    case 0xA5: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuRegs->A = CpuRead(temp);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0xBD: // Absolute, X
    case 0xB9: // Absolute, Y
        if (op == 0xBD)
        {
            temp = CpuRegs->X;
        }
        else
        {
            temp = CpuRegs->Y;
        }
        cycles += tempValue;
    case 0xAD: // Absolute

        temp += readAddress();
        CpuRegs->A = CpuRead(temp);
        cycles += tempValue;
        break;
    case 0xA1: // (Indirect, X)
    case 0xB1: // (Inderect), Y
        break;
    }
}

/**
 * @brief Performs the STA operation Store A
 *
 * @param op
 * @param low temp var
 * @param high temp var
 * @param temp temp var
 * @return int
 */
int STA(byte op, byte low, byte high, ushort temp)
{
    switch (op)
    {
    case 0x95: // Zero page, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0x85: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuWrite(temp, CpuRegs->A);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0x9D: // Absolute, X
    case 0x99: // Absolute, Y
        if (op == 0xBD)
        {
            temp = CpuRegs->X;
        }
        else
        {
            temp = CpuRegs->Y;
        }
        cycles += tempValue;
    case 0x8D: // Absolute
        temp += readAddress();
        CpuWrite(temp, CpuRegs->A);
        cycles += tempValue;
    case 0x81: // (Indirect, X)
    case 0x91: // (Inderect), Y
        break;
    }
    return 0;
}

/**
 * @brief Performs the load y operation.
 *
 * @param op
 * @param low
 * @param high
 * @param temp
 * @return int
 */
int LDY(byte op, byte low, byte high, ushort temp)
{
    switch (op)
    {
    case 0xA0: // Immediate
        CpuRegs->Y = CpuRead(CpuRegs->PC);
        CpuRegs->PC++;
        cycles += tempValue;
        break;
    case 0xB4: // Zero page, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0xA4: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuRegs->Y = CpuRead(temp);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0xBC: // Absolute, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0xAC: // Absolute
        temp += readAddress();
        CpuRegs->Y = CpuRead(temp);
        cycles += tempValue;
        break;
    }

    return 0;
}

int STY(byte op, byte low, byte high, ushort temp)
{
    switch (op)
    {
    case 0x94: // Zero page, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0x84: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuWrite(temp, CpuRegs->Y);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0x8c: // Absolute
        temp = readAddress();
        CpuWrite(temp, CpuRegs->Y);
        cycles += tempValue;
        break;
    }
    return 0;
}

int LDX(byte op, byte low, byte high, ushort temp)
{
    switch (op)
    {
    case 0xA0: // Immediate
        CpuRegs->X = CpuRead(CpuRegs->PC);
        CpuRegs->PC++;
        cycles += tempValue;
        break;
    case 0xB4: // Zero page, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0xA4: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuRegs->X = CpuRead(temp);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0xBC: // Absolute, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0xAC: // Absolute
        temp += readAddress();
        CpuRegs->X = CpuRead(temp);
        cycles += tempValue;
        break;
    }

    return 0;
}

int STX(byte op, byte low, byte high, ushort temp)
{
    switch (op)
    {
    case 0x94: // Zero page, X
        temp += CpuRegs->X;
        cycles += tempValue;
    case 0x84: // Zero Page
        temp += CpuRead(CpuRegs->PC);
        temp %= byteLimit;
        CpuWrite(temp, CpuRegs->X);
        CpuRegs->PC++;
        cycles += tempValue; // Base cycles added.
        break;
    case 0x8c: // Absolute
        temp = readAddress();
        CpuWrite(temp, CpuRegs->X);
        cycles += tempValue;
        break;
    }
    return 0;
}