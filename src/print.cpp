#include "Arduino.h"

#include <mruby.h>
#include <mruby/string.h>

static void
printstr(mrb_state *mrb, mrb_value obj)
{
  if (mrb_string_p(obj)) {
    Serial.write(RSTRING_PTR(obj), RSTRING_LEN(obj));
  }
}

/* 15.3.1.2.9  */
/* 15.3.1.3.34 */
mrb_value
mrb_printstr(mrb_state *mrb, mrb_value self)
{
  mrb_value argv;

  mrb_get_args(mrb, "o", &argv);
  printstr(mrb, argv);

  return argv;
}

extern "C"
void
mrb_mruby_print_gem_init(mrb_state* mrb)
{
  Serial.begin(115200);

  struct RClass *krn;
  krn = mrb->kernel_module;
  mrb_define_method(mrb, krn, "__printstr__", mrb_printstr, MRB_ARGS_REQ(1));
}

extern "C"
void
mrb_mruby_print_gem_final(mrb_state* mrb)
{
}
