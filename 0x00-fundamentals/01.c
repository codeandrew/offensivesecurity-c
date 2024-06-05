#include <stdio.h>

int main() {
  int i;
  for(i=0; i < 10; i++) // Loop 10 times.
  {
    puts("Hello, world!\n");  // put the string to the output.
  }
  return 0;                   // Tell OS the program exited without errors.
}
// ╰─$ gcc 01.c                      
// ╰─$ ls -l                   
// total 80
// -rw-r--r--  1 j4f  staff    244 Jun  5 12:07 01.c
// -rwxr-xr-x  1 j4f  staff  33432 Jun  5 12:07 a.out
// ╰─$ ./a.out                
// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// Hello, world!

// ╰─$ objdump -D a.out | grep -A20 main.:
// 0000000100003f30 <_main>:
// 100003f30: d10083ff     sub     sp, sp, #32
// 100003f34: a9017bfd     stp     x29, x30, [sp, #16]
// 100003f38: 910043fd     add     x29, sp, #16
// 100003f3c: b81fc3bf     stur    wzr, [x29, #-4]
// 100003f40: b9000bff     str     wzr, [sp, #8]
// 100003f44: 14000001     b       0x100003f48 <_main+0x18>
// 100003f48: b9400be8     ldr     w8, [sp, #8]
// 100003f4c: 71002908     subs    w8, w8, #10
// 100003f50: 1a9fb7e8     cset    w8, ge
// 100003f54: 37000148     tbnz    w8, #0, 0x100003f7c <_main+0x4c>
// 100003f58: 14000001     b       0x100003f5c <_main+0x2c>
// 100003f5c: 90000000     adrp    x0, 0x100003000 <_main+0x2c>
// 100003f60: 913e6000     add     x0, x0, #3992
// 100003f64: 9400000a     bl      0x100003f8c <_puts+0x100003f8c>
// 100003f68: 14000001     b       0x100003f6c <_main+0x3c>
// 100003f6c: b9400be8     ldr     w8, [sp, #8]
// 100003f70: 11000508     add     w8, w8, #1
// 100003f74: b9000be8     str     w8, [sp, #8]
// 100003f78: 17fffff4     b       0x100003f48 <_main+0x18>
// 100003f7c: 52800000     mov     w0, #0