#include "disassembler.h"

int* read_bin_file ()
{
    FILE* num_com_bin = fopen ("../test-code.bin", "rb");
    MY_ASSERT (num_com_bin != NULL);

    struct stat stat_of_bin = {};
    stat ("../test-code.bin", &stat_of_bin);
    size_t size_of_bin = stat_of_bin.st_size;
    int*   code_of_com = (int*) calloc (size_of_bin, sizeof (int));
    MY_ASSERT (code_of_com != NULL);
    fread (code_of_com, sizeof (int), size_of_bin, num_com_bin);

    fclose (num_com_bin);

    return code_of_com;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

int disasm_com (int* code_of_com)
{
    FILE* disasm_prog = fopen ("../disasm.asm", "w");
    MY_ASSERT (disasm_prog != NULL)
    char* name_of_reg = (char*) calloc (1, sizeof ("ax"));

    int elem         = 0;
    int code_of_reg  = 0;
    int label_of_jmp = 0;
    for (int i = 0; code_of_com[i] != HLT; i++)
    {
        switch (code_of_com[i])
        {
            case PUSH:
                i++;
                elem = code_of_com[i];
                write_elem ();
                break;

            case IN:
                write_elem ();
                break;

            case PUSHR:
                i++;
                code_of_reg = code_of_com[i];
                reg_def (code_of_reg, name_of_reg);
                write_elem ();
                break;

            case PUSHM:
                i++;
                elem = code_of_com[i];
                write_elem ();
                break;

            case PUSHRM:
                i++;
                code_of_reg = code_of_com[i];
                reg_def (code_of_reg, name_of_reg);
                write_elem ();
                break;

            case POP:
                i++;
                code_of_reg = code_of_com[i];
                reg_def (code_of_reg, name_of_reg);
                write_elem();
                break;

            case ADD:
                write_elem ();
                break;

            case MUL:
                write_elem ();
                break;

            case DIV:
                write_elem ();
                break;

            case SQRT:
                write_elem ();
                break;

            case OUT:
                write_elem ();
                break;

            case JMP:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JB:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JBE:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JA:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JAE:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JE:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case JNE:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case CALL:
                i++;
                label_of_jmp = code_of_com[i];
                write_elem ();
                break;

            case RET:
                write_elem ();
                break;

            case ENTER:
                write_elem ();
                break;

            case HLT:
                write_elem ();
                break;
        }
    }

    free   (name_of_reg);
    fclose (disasm_prog);
}

void reg_def (int code_of_reg, char* name_of_reg)
{
    switch (code_of_reg)
    {
        case ax:
            name_of_reg = (char*)"ax";
            break;

        case bx:
            name_of_reg = (char*)"bx";
            break;

        case cx:
            name_of_reg = (char*)"cx";
            break;

        case dx:
            name_of_reg =(char*) "dx";
            break;
    }
}

void write_elem ()
{

}
