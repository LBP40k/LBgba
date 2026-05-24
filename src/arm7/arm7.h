#pragma once
#include "common/common.h"
#include "mmu/mmu.h"

using Cycles = int;

enum ARM7State
{
    ARM,
    THUMB
};




enum CPUFlag
{
   N = 31,
   Z = 30,
   C = 29,
   V = 28,
   Q = 27,
   I = 7,
   F = 6,
   T = 5, 
};

enum CPUConditions
{
    EQ,
    NE,
    CS_HS,
    CC_LO,
    MI,
    PL,
    VS,
    VC,
    HI,
    LS,
    GE,
    LT,
    GT,
    LE,
    AL,
    NV
};


enum InstructionType
{
    BranchAndBranchExchange,
    BlockDataTransfer,
    BranchWithLink,
    SoftwareInterrupt,
    Undefined,
    SingleDataTransfer,
    SingleDataSwap,
    HalfwordDataTransferRegister,
    HalfwordDataTransferImmediate,
    DataProcessing,
};

struct Instruction
{
    InstructionType instructionType;
    u8 opcode;
    u8 condition;
    u8 rn;
    u8 rd;
    u8 rm;
    u32 offset;
    u16 registerList;
    u16 operand2;

    bool setFlags; // S bit
    bool load; // L bit
    bool writeBack; // W bit
    bool preIndex; //P bit
    bool up; // U bit
    bool immediate; // I bit

};


class ARM7
{
public:
    ARM7();
    ARM7State CpuState = ARM;
    u32 R[31]{};
    u32 CPSR{};

    bool getFlag(CPUFlag flag);

    

    Instruction DecodeARMInstruction(u32 opcode);

    

    int step();

    u32& SP(){return R[13];}
    u32& LR(){return R[14];}
    u32& PC(){return R[15];}

    MMU* mmu;
private:
    u32 fetch();
    Instruction decode(u32 opcode);
    
    Cycles execute(Instruction instr);

    Cycles handleDataProcessing(Instruction instr);

    bool IsBranchAndBranchExchange(u32 opcode);
    bool IsBlockDataTransfer(u32 opcode);
    bool IsSoftwareInterrupt(u32 opcode);
    bool IsUndefined(u32 opcode);
    bool IsSingleDataTransfer(u32 opcode);
    bool IsSingleDataSwap(u32 opcode);
    bool IsMultiply(u32 opcode);
    bool IsHalfwordDataTransferRegister(u32 opcode);
    bool IsHalfwordDataTransferImmediate(u32 opcode);
    bool IsPSRTransferMRS(u32 opcode);
    bool IsPSRTransferMSR(u32 opcode);
    bool IsDataProcessing(u32 opcode);
    bool IsBranchAndBranchWithLink(u32 opcode);
};