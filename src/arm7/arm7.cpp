#include "arm7.h"

bool ARM7::getFlag(CPUFlag flag)
{
    return getBit(CPSR, flag);
}

bool ARM7::IsBranchAndBranchExchange(u32 opcode)
{
    const u32 branchAndExchangeFormat = 0b0000'0001'0010'1111'1111'1111'0001'0000;

    const u32 formatMask = 0b0000'1111'1111'1111'1111'1111'1111'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == branchAndExchangeFormat;
}

bool ARM7::IsBlockDataTransfer(u32 opcode)
{
    const u32 blockDataTransferFormat = 0b0000'1000'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1110'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == blockDataTransferFormat;
}



bool ARM7::IsBranchAndBranchWithLink(u32 opcode)
{
    const u32 branchFormat = 0b0000'1010'0000'0000'0000'0000'0000'0000;
    const u32 branchWithLinkFormat = 0b0000'1011'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1111'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == (extractedFormat == branchFormat || extractedFormat == branchWithLinkFormat);
}

bool ARM7::IsSoftwareInterrupt(u32 opcode)
{
    const u32 softwareInterruptFormat = 0b0000'1111'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1111'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == softwareInterruptFormat;
}

bool ARM7::IsUndefined(u32 opcode)
{
    const u32 undefinedFormat = 0b0000'0110'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1110'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == undefinedFormat;
}

bool ARM7::IsSingleDataTransfer(u32 opcode)
{
    const u32 singleDataTransferFormat = 0b0000'0100'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1100'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == singleDataTransferFormat;
}

bool ARM7::IsSingleDataSwap(u32 opcode)
{
    const u32 singleDataSwapFormat = 0b0000'0001'0000'0000'0000'0000'0000'0000;

    const u32 formatMask = 0b0000'1111'1000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == singleDataSwapFormat;
}

bool ARM7::IsMultiply(u32 opcode)
{
    const u32 multiplyFormat = 0b0000'0000'0000'0000'0000'0000'1001'0000;
    const u32 multiplyLongFormat = 0b0000'0000'1000'0000'0000'0000'1001'0000;

    const u32 formatMask = 0b0000'1111'1000'0000'0000'0000'1111'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == multiplyFormat || extractedFormat == multiplyLongFormat;
}

bool ARM7::IsHalfwordDataTransferRegister(u32 opcode)
{
    const u32 halfwordDataTransferRegisterFormat = 0b0000'0000'0000'0000'0000'0000'1001'0000;
    

    const u32 formatMask = 0b0000'1110'0100'0000'0000'1111'1001'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == halfwordDataTransferRegisterFormat;
}

bool ARM7::IsHalfwordDataTransferImmediate(u32 opcode)
{
    const u32 halfwordDataTransferImmediateFormat = 0b0000'0000'0100'0000'0000'0000'1001'0000;
    

    const u32 formatMask = 0b0000'1110'0100'0000'0000'0000'1001'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == halfwordDataTransferImmediateFormat;
}

bool ARM7::IsPSRTransferMRS(u32 opcode)
{
    const u32 mrsFormat = 0b0000'0001'0000'1111'0000'0000'0000'0000;
    

    const u32 formatMask = 0b0000'1111'1011'1111'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == mrsFormat;
}

bool ARM7::IsPSRTransferMSR(u32 opcode)
{
    const u32 msrFormat = 0b0000'0001'0010'0000'1111'0000'0000'0000;
    

    const u32 formatMask = 0b0000'1101'1011'0000'1111'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == msrFormat;
}

bool ARM7::IsDataProcessing(u32 opcode)
{
    const u32 dataProcessingFormat = 0b0000'0000'0000'0000'0000'0000'0000'0000;
    

    const u32 formatMask = 0b0000'1100'0000'0000'0000'0000'0000'0000;

    u32 extractedFormat = opcode & formatMask;

    return extractedFormat == dataProcessingFormat;
}



Instruction ARM7::DecodeARMInstruction(u32 opcode)
{
    Instruction instr;
    if (IsBranchAndBranchExchange(opcode))
    {
        return;
    }
    if (IsBlockDataTransfer(opcode))
    {
        return;
    }
    if (IsBranchAndBranchWithLink(opcode))
    {
        return;
    }
    if (IsSoftwareInterrupt(opcode))
    {
        return;
    }
    if (IsUndefined(opcode))
    {
        return;
    }
    if (IsSingleDataTransfer(opcode))
    {
        return;
    }
    if (IsSingleDataSwap(opcode))
    {
        return;
    }
    if (IsMultiply(opcode))
    {
        
        return;
    }
    if (IsHalfwordDataTransferRegister(opcode))
    {
        return;
    }
    if (IsHalfwordDataTransferImmediate(opcode))
    {
        return;
    }
    if (IsDataProcessing(opcode))
    {
        return;
    }
    
    
    return instr;
}

u32 ARM7::fetch()
{
    if (CpuState == ARM)
    {
        PC() += 4;
    }
    else if (CpuState == THUMB)
    {
        PC() += 2;
    }
    
}

Instruction ARM7::decode(u32 opcode)
{
    if (CpuState == ARM)
    {
        return DecodeARMInstruction(opcode);
    }
    else if (CpuState == THUMB)
    {

    }
}

Cycles ARM7::execute(Instruction instr)
{

}

Cycles ARM7::step()
{
    u32 opcode = fetch();
    Instruction instr = decode(opcode);
    Cycles cycles = execute(instr);

    return cycles;
}