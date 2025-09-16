struct Registers
{
    unsigned short PC; // Program counter
    unsigned short SP; // stack pointer
    // A, X, Y registers.
    unsigned char A;
    unsigned char X;
    unsigned char Y;
};

enum instructions
{
    LDA = 0,
    LDX,
    LDY,
    HLT,

};