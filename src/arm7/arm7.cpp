#include "arm7.h"

ARM7::ARM7()
{
    PC() = 0x08000000;
}

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
    Instruction instr{};
    if (IsBranchAndBranchExchange(opcode))
    {
        return instr;
    }
    if (IsBlockDataTransfer(opcode))
    {
        return instr;
    }
    if (IsBranchAndBranchWithLink(opcode))
    {
        return instr;
    }
    if (IsSoftwareInterrupt(opcode))
    {
        return instr;
    }
    if (IsUndefined(opcode))
    {
        return instr;
    }
    if (IsSingleDataTransfer(opcode))
    {
        return instr;
    }
    if (IsSingleDataSwap(opcode))
    {
        return instr;
    }
    if (IsMultiply(opcode))
    {
        return instr;
    }
    if (IsHalfwordDataTransferRegister(opcode))
    {
        return instr;
    }
    if (IsHalfwordDataTransferImmediate(opcode))
    {
        return instr;
    }
    if (IsDataProcessing(opcode))
    {
        instr.operand2 = opcode & 0b1111'1111'1111;
        instr.rd = (opcode >> 12) & 0b1111;
        instr.rn = (opcode >> 16) & 0b1111;
        instr.opcode = (opcode >> 21) & 0b1111;
        instr.instructionType = InstructionType::DataProcessing;
        instr.immediate = (opcode >> 25) & 0x1;
        return instr;
    }
    
    
    return instr;
}

u32 ARM7::fetch()
{
    u32 pc = PC();

    u32 opcode;

    if (CpuState == ARM)
    {
        opcode = mmu->read32(pc);
        PC() += 4;
    }
    else
    {
        opcode = mmu->read16(pc);
        PC() += 2;
    }

    return opcode;
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
    return Instruction();
}

Cycles ARM7::handleDataProcessing(Instruction instr)
{
            u16 operand;
            switch (instr.opcode)
            {
                case 0xD: // MOV
                {
                    std::cout << "MOV!\n";
                    if (instr.immediate)
                    {
                        R[instr.rd] = instr.operand2;
                    }
                    else
                    {
                        R[instr.rd] = R[instr.operand2];
                    }
                    break;
                }
            }
}

bool ARM7::checkCondition()

Cycles ARM7::execute(Instruction instr)
{
    
    switch(instr.instructionType)
    {

        case DataProcessing:
        {
            handleDataProcessing(instr);
            break;
        }
    }
    return 0;
}

Cycles ARM7::step()
{
    u32 opcode = fetch();
    Instruction instr = decode(opcode);
    Cycles cycles = execute(instr);

    return cycles;
}