/*
** $Id: i386_punpcklbw_pq_qd.c,v 1.1 2007-01-26 14:18:37 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_punpcklbw_pq_qq" opcode="0x60"/>
 */

int     i386_punpcklbw_pq_qd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PUNPCKLBW;
  
  new->op1.type = ASM_OTYPE_PMMX;
  new->op1.size = ASM_OSIZE_QWORD;
  new->op2.type = ASM_OTYPE_QMMX;
  new->op2.size = ASM_OSIZE_DWORD;
  
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op1.regset = ASM_REGSET_MM;
  new->op2.regset = ASM_REGSET_MM;
  
  return (new->len);
}
