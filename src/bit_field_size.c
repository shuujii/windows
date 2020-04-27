#include <stdio.h>
#include <stdint.h>

enum mrb_fiber_state {MRB_FIBER_CREATED};
typedef int mrb_value;
typedef int mrb_callinfo;
typedef uint8_t mrb_bool;

struct {
  struct mrb_context *prev;
  mrb_value *stack, *stbase, *stend;
  mrb_callinfo *ci, *cibase, *ciend;
  uint16_t *rescue, rsize;
  struct RProc **ensure;
  uint16_t esize, eidx;
  enum mrb_fiber_state status;
  mrb_bool vmexec;
  struct RFiber *fib;
} mrb_context_Original;

struct {
  struct mrb_context *prev;
  mrb_value *stack, *stbase, *stend;
  mrb_callinfo *ci, *cibase, *ciend;
  uint16_t *rescue, rsize;
  struct RProc **ensure;
  uint16_t esize, eidx;
  enum mrb_fiber_state status : 4;
  mrb_bool vmexec : 1;
  struct RFiber *fib;
} mrb_context_BitField_Enum;

struct {
  struct mrb_context *prev;
  mrb_value *stack, *stbase, *stend;
  mrb_callinfo *ci, *cibase, *ciend;
  uint16_t *rescue, rsize;
  struct RProc **ensure;
  uint16_t esize, eidx;
  uint8_t status : 4;
  uint8_t vmexec : 1;
  struct RFiber *fib;
} mrb_context_BitField_Uint8;

struct {
  struct mrb_context *prev;
  mrb_value *stack, *stbase, *stend;
  mrb_callinfo *ci, *cibase, *ciend;
  struct RFiber *fib;
  uint16_t *rescue;
  struct RProc **ensure;
  enum mrb_fiber_state status;
  uint16_t esize, eidx, rsize;
  mrb_bool vmexec;
} mrb_context_Sorted;

struct {
  struct mrb_context *prev;
  mrb_value *stack, *stbase, *stend;
  mrb_callinfo *ci, *cibase, *ciend;
  struct RFiber *fib;
  uint16_t *rescue;
  struct RProc **ensure;
  uint16_t esize, eidx, rsize;
  uint8_t status;
  mrb_bool vmexec;
} mrb_context_Sorted_Uint8;

#define PRINT_SIZE(type) printf("%-26s = %3d\n", #type, (int)sizeof(type))

int main(void) {
  PRINT_SIZE(void*);
  PRINT_SIZE(mrb_context_Original);
  PRINT_SIZE(mrb_context_BitField_Enum);
  PRINT_SIZE(mrb_context_BitField_Uint8);
  PRINT_SIZE(mrb_context_Sorted);
  PRINT_SIZE(mrb_context_Sorted_Uint8);
}
