#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

struct CpuRegisters *CpuRegs = NULL;

struct CpuRegisters *initCpuReg()
{
    return calloc(0, sizeof(struct CpuRegisters));
}

int execInstruction(int op)
{
    switch (op)
    {
    // LDA - Load A
    case 0xA9: // Immediate
    case 0xA5: // Zero PAge
    case 0xB5: // Zero page, X
    case 0xAD: // Absolute
    case 0xBD: // Absolute, X
    case 0xB9: // Absolute, Y
    case 0xA1: // (Indirect, X)
    case 0xB1: // (Inderect), Y
        break;

    // STA - Store A
    case 0x85: // Zero PAge
    case 0x95: // Zero page, X
    case 0x8D: // Absolute
    case 0x9D: // Absolute, X
    case 0x99: // Absolute, Y
    case 0x81: // (Indirect, X)
    case 0x91: // (Inderect), Y
        break;

    // LDY - Load Y
    case 0xA0: // Immediate
    case 0xA4: // Zero PAge
    case 0xB4: // Zero page, X
    case 0xAC: // Absolute
    case 0xBC: // Absolute, X
        break;

    // STY - Store Y
    case 0x84: // Zero Page
    case 0x94: // Zero page, X
    case 0x8c: // Absolute
        break;

    // LDX - Load X
    case 0xA2: // Immediate
    case 0xA6: // Zero PAge
    case 0xB6: // Zero page, Y
    case 0xAE: // Absolute
    case 0xBE: // Absolute, Y
        break;

    // STX - Store X
    case 0x86: // Zero PAge
    case 0x96: // Zero page, Y
    case 0x8E: // Absolute
        break;

    // TAX - transfer a to x
    case 0xAA:
        break;

    // TXA - transfer x to a
    case 0x8A:
        break;

    // TAY - transfer a to y
    case 0xA8:
        break;

    // TYA - Transfer y to a
    case 0x98:
        break;

    // ADC - Add with carry
    case 0x69: // Immediate
    case 0x65: // Zero PAge
    case 0x75: // Zero page, X
    case 0x6D: // Absolute
    case 0x7D: // Absolute, X
    case 0x79: // Absolute, Y
    case 0x61: // (Indirect, X)
    case 0x71: // (Inderect), Y
        break;

    // SBC - Subtract with carry
    case 0xE9: // Immediate
    case 0xE5: // Zero PAge
    case 0xF5: // Zero page, X
    case 0xED: // Absolute
    case 0xFD: // Absolute, X
    case 0xF9: // Absolute, Y
    case 0xE1: // (Indirect, X)
    case 0xF1: // (Inderect), Y
        break;

    // INC - Increment memory
    case 0xE6: // Zero page
    case 0xF6: // zero page, x
    case 0xEE: // absolute
    case 0xFE: // absolute, X
        break;

    // DEC - Decrement memory
    case 0xC6: // Zero page
    case 0xD6: // zero page, x
    case 0xCE: // absolute
    case 0xDE: // absolute, X
        break;

    // INX - Increment X
    case 0xE8:
        break;

    // DEX - Decrement X
    case 0xCA:
        break;

    // INY - Increment Y
    case 0xC8:
        break;

    // DEY - Decrement Y
    case 0x88:
        break;

    // ASL - arithmetic shift left
    case 0x0A: // Accumulator
    case 0x06: // Zero page
    case 0x16: // zero page, x
    case 0x0E: // absolute
    case 0x1E: // absolute, X
        break;

    // LSR - Logical Shift Right
    case 0x4A: // Accumulator
    case 0x46: // Zero page
    case 0x56: // zero page, x
    case 0x4E: // absolute
    case 0x5E: // absolute, X
        break;

    // ROL - Rotate Left
    case 0x2A: // Accumulator
    case 0x26: // Zero page
    case 0x36: // zero page, x
    case 0x2E: // absolute
    case 0x3E: // absolute, X
        break;

    // ROR - Rotate Right
    case 0x6A: // Accumulator
    case 0x66: // Zero page
    case 0x76: // zero page, x
    case 0x6E: // absolute
    case 0x7E: // absolute, X
        break;

    // AND - Bitwise and
    case 0x29: // Immediate
    case 0x25: // Zero PAge
    case 0x35: // Zero page, X
    case 0x2D: // Absolute
    case 0x3D: // Absolute, X
    case 0x39: // Absolute, Y
    case 0x21: // (Indirect, X)
    case 0x31: // (Inderect), Y
        break;

    // ORA - Bitwise or
    case 0x09: // Immediate
    case 0x05: // Zero PAge
    case 0x15: // Zero page, X
    case 0x0D: // Absolute
    case 0x1D: // Absolute, X
    case 0x19: // Absolute, Y
    case 0x01: // (Indirect, X)
    case 0x11: // (Inderect), Y
        break;

    // EOR - Bitwise xor
    case 0x49: // Immediate
    case 0x45: // Zero PAge
    case 0x55: // Zero page, X
    case 0x4D: // Absolute
    case 0x5D: // Absolute, X
    case 0x59: // Absolute, Y
    case 0x41: // (Indirect, X)
    case 0x51: // (Inderect), Y
        break;

    // BIT - Bit test?
    case 0x24: // zero page
    case 0x2C: // absolute
        break;
    // CMP - Compare A
    case 0xC9: // Immediate
    case 0xC5: // Zero PAge
    case 0xD5: // Zero page, X
    case 0xCD: // Absolute
    case 0xDD: // Absolute, X
    case 0xD9: // Absolute, Y
    case 0xC1: // (Indirect, X)
    case 0xD1: // (Inderect), Y
        break;

    // CPX - Compare X
    case 0xE0: // Immediate
    case 0xE4: // Zero page
    case 0xEC: // Absolute
        break;

    // CPY - Compare Y
    case 0xC0: // Immediate
    case 0xC4: // Zero page
    case 0xCC: // Absolute
        break;

    // BCC - Branch if carry clear
    case 0x90:
        break;
    // BCS - Branch if  carry set
    case 0xB0:
        break;
    // BEQ - Branch if equal
    case 0xF0:
        break;
    // BNE - Branch if not equal
    case 0xD0:
        break;
    // BPL - Branch if plus
    case 0x10:
        break;
    // BMI - Branch if Minus
    case 0x30:
        break;
    // BVC - Branch if overflow clear
    case 0x50:
        break;

    // BVS - Branch if overflow set
    case 0x70:
        break;

    // JMP - Jump
    case 0x4C: // Absolute
    case 0x6C: // (indirect)
        break;

    // JSR - Jump to subroutine
    case 0x20:
        break;
    // RTS - Return from subroutine
    case 0x60:
        break;

    // BRK - Break (software interupt request)
    case 0x00: // Implied and immediate
        break;

    // RTI - Return from interupt
    case 0x40:
        break;

    // PHA - Push A
    case 0x48:
        break;
    // PLA - Pull A
    case 0x68:
        break;
    // PHP - Push processor status
    case 0x08:
        break;
    // PLP - Pull processor status
    case 0x28:
        break;
    // TXS - Transfer X to stack pointer
    case 0x9A:
        break;

    // TSX - Transfer stack pointer to X
    case 0xBA:
        break;
    // NOP - no operation
    case 0xEA:
        break;

    // --- Flags ---
    // CLC - clears the carry flag
    case 0x18:
        break;
    // SEC - Set carry
    case 0x38:
        break;

    // CLI - Clear interupt disable
    case 0x58:
        break;

    // SEI - Set interupt disable
    case 0x78:
        break;

    // CLD - Clears the decimal flag.
    case 0xD8:
        break;

    // SED - Set decimal
    case 0xF8:
        break;

    // CLV - clear overflow
    case 0xB8:
        break;

    // Unofficial op code, treat as No op.
    default:
        break;
    }

    return 0;
}