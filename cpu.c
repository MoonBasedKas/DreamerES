#include "cpu.h"

int execInstruction(int op)
{
    switch (op)
    {
    // LDA - Load A

    // STA - Store A

    // LDA - Load Y

    // STY - Store Y

    // LDA - Load X

    // STX - Store X

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
    case 0x9A:
        break;

    // ADC - Add with carry
    // SBC - Subtract with carry
    // INC - Increment memory
    // DEC - Decrement memory
    // INX - Increment X
    // DEX - Decrement X
    // INY - Increment Y
    // DEY - Decrement Y
    // ASL - arithmetic shift left
    // LSR - Logical Shift Right
    // ROL - Rotate Left
    // ROR - Rotate Right
    // AND - Bitwise and
    // ORA - Bitwise or
    // EOR - Bitwise xor
    // BIT - Bit test?
    // CMP - Compare A
    // CPX - Compare X
    // CPY - Compare Y
    // BCC - Branch if carry clear
    // BCS - Branch if  carry set
    // BEQ - Branch if equal
    // BNE - Branch if not equal
    // BPL - Branch if plus
    // BMI - Branch if Minus
    // BVC - Branch if overflow clear
    // BVS - Branch if overflow set
    // JMP - Jump
    // JSR - Jump to subroutine
    case 0x20:
        break;
    // RTS - Return from subroutine
    // BRK - Break (software interupt request)
    // RTI - Return from interupt
    // PHA - Push A
    // PLA - Pull A
    // PHP - Push processor status
    // PLP - Pull processor status
    // TXS - Transfer X to stack pointer
    // TSX - Transfer stack pointer to X
    // NOP - no operation
    case 0xEA:
        break;

        // Flags
        // CLC -
        // SEC -
        // CLI -
        // SEI -
        // CLD -
        // SED -
        // CLV -
    }

    return 0;
}