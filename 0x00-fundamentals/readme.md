# 

## x86 vs ARM architecture
The difference in assembly instructions you see is due to the difference in architectures between the systems you're using. The original example uses the x86 architecture, whereas your Mac M1 uses the ARM architecture (specifically ARM64, also known as AArch64). These architectures have different instruction sets and conventions for generating assembly code.

### Key Differences

1. **Architecture**:
   - **x86**: A complex instruction set computer (CISC) architecture, known for a rich set of instructions like `movl`, `call`, `jmp`, `leave`, `ret`, `nop`, etc.
   - **ARM64 (AArch64)**: A reduced instruction set computer (RISC) architecture, known for a simpler and more consistent set of instructions, such as `ldr`, `str`, `add`, `sub`, `bl`, `b`, etc.

2. **Registers**:
   - **x86**: Uses general-purpose registers like `eax`, `ebx`, `ecx`, `edx`, `ebp`, `esp`, etc.
   - **ARM64**: Uses 31 general-purpose registers (`x0` to `x30`) and a stack pointer `sp`.

3. **Instruction Set**:
   - **x86**: Has a wide variety of instructions, including complex addressing modes and special-purpose registers.
   - **ARM64**: Focuses on simple and uniform instructions, each generally executing in a single cycle.

### ARM Assembly Breakdown

Let's break down the ARM64 assembly code you provided:

```assembly
0000000100003f30 <_main>:
100003f30: d10083ff     sub     sp, sp, #32          ; Allocate 32 bytes on the stack
100003f34: a9017bfd     stp     x29, x30, [sp, #16]  ; Save the frame pointer (x29) and return address (x30)
100003f38: 910043fd     add     x29, sp, #16         ; Set the frame pointer to the current stack pointer + 16
100003f3c: b81fc3bf     stur    wzr, [x29, #-4]      ; Store zero at the address (x29 - 4)
100003f40: b9000bff     str     wzr, [sp, #8]        ; Store zero at the address (sp + 8)
100003f44: 14000001     b       0x100003f48 <_main+0x18> ; Branch to offset
100003f48: b9400be8     ldr     w8, [sp, #8]         ; Load word from address (sp + 8) into w8
100003f4c: 71002908     subs    w8, w8, #10          ; Subtract 10 from w8, and set condition flags
100003f50: 1a9fb7e8     cset    w8, ge               ; Set w8 to 1 if the result was greater or equal to zero
100003f54: 37000148     tbnz    w8, #0, 0x100003f7c <_main+0x4c> ; Test bit and branch if not zero
100003f58: 14000001     b       0x100003f5c <_main+0x2c> ; Branch to offset
100003f5c: 90000000     adrp    x0, 0x100003000 <_main+0x2c> ; Load page address of symbol into x0
100003f60: 913e6000     add     x0, x0, #3992        ; Add offset to x0
100003f64: 9400000a     bl      0x100003f8c <_puts+0x100003f8c> ; Branch with link (call puts function)
100003f68: 14000001     b       0x100003f6c <_main+0x3c> ; Branch to offset
100003f6c: b9400be8     ldr     w8, [sp, #8]         ; Load word from address (sp + 8) into w8
100003f70: 11000508     add     w8, w8, #1           ; Add 1 to w8
100003f74: b9000be8     str     w8, [sp, #8]         ; Store w8 back to address (sp + 8)
100003f78: 17fffff4     b       0x100003f48 <_main+0x18> ; Branch to earlier code location (loop)
100003f7c: 52800000     mov     w0, #0               ; Move zero into w0 (prepare return value)
```

### Explanation of Differences

- **Function Prologue and Epilogue**:
  - x86 uses `push`, `mov`, `sub`, `leave`, and `ret` for function prologue and epilogue.
  - ARM64 uses `sub sp, sp, #32`, `stp x29, x30, [sp, #16]`, `add x29, sp, #16` for prologue and `ldr` and `ldp` for epilogue.

- **Branch Instructions**:
  - x86 uses `jmp`, `call`, and `ret`.
  - ARM64 uses `b`, `bl`, and `ret`.

- **Data Movement**:
  - x86 uses `mov` for moving data between registers and memory.
  - ARM64 uses `ldr` and `str` for loading and storing data, and `mov` for moving data between registers.


When explaining why your Mac M1 doesn't use `movl`, `call`, `jmp`, `leave`, `ret`, `nop` instructions, focus on the architectural differences:
- **x86 and ARM64 architectures have different instruction sets and conventions.**
- **ARM64 uses a simpler and more consistent set of instructions compared to the complex x86 instruction set.**
- **These differences are due to the underlying hardware architecture and design philosophies of CISC (x86) versus RISC (ARM64).**

Understanding these differences is crucial for adapting exploitation techniques across different platforms.

---
Given the rise of ARM architecture in devices like Mac M1/M2 and Raspberry Pi products, as well as the prevalence of x86 architectures, here's a strategic approach for learning assembly and preparing for CTFs and the OSCP exam:

### Starting with x86 Assembly

1. **Widespread Use in Learning Resources**: Most introductory resources, tutorials, and textbooks focus on x86 assembly. This makes it easier to find study material, exercises, and community support.
2. **Foundation for Understanding**: Learning x86 assembly will give you a solid foundation in assembly language concepts, which are transferable to ARM.
3. **Relevant for OSCP**: The OSCP exam and many CTF challenges are often based on x86 architectures. This makes x86 a more immediately practical choice for exam preparation.

### Transitioning to ARM Assembly

1. **Growing Relevance**: With the increasing use of ARM in modern devices, understanding ARM assembly is becoming increasingly relevant.
2. **CTF Challenges**: Many modern CTFs include challenges based on ARM architecture, especially with the popularity of IoT devices and mobile platforms.
3. **ARM Devices**: If you plan to work with or develop for ARM-based devices, understanding ARM assembly is crucial.

### Learning Path

1. **Start with x86 Assembly**:
    - **Resources**: Books like "Programming from the Ground Up" and "Hacking: The Art of Exploitation" (which you are already reading) are excellent starting points.
    - **Tools**: Use tools like `gdb` for debugging and `objdump` for disassembly.
    - **Exercises**: Solve x86-based assembly challenges on platforms like Hack The Box, CTFtime, and other CTF practice sites.

2. **Move to ARM Assembly**:
    - **Resources**: Books like "ARM Assembly Language" by William Hohl and "Professional Assembly Language" cover ARM-specific instructions and examples.
    - **Tools**: Use ARM-specific tools like `gdb-multiarch`, `objdump`, and `qemu` for emulating ARM environments.
    - **Exercises**: Practice with ARM-based challenges, particularly those involving Raspberry Pi or ARM emulators.

### Combining Both

- **Simultaneous Practice**: Once comfortable with x86, start incorporating ARM challenges into your practice routine.
- **Understand Differences**: Focus on understanding the differences in instruction sets, calling conventions, and architecture-specific features.

### Conclusion

Starting with x86 assembly will give you a strong foundation and immediate practical benefits for CTFs and the OSCP exam. Transitioning to ARM assembly will broaden your skillset and prepare you for the growing number of ARM-based challenges and devices. Balancing both architectures will make you a versatile and well-rounded security professional.