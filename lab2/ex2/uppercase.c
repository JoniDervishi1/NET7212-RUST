#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void my_strcpy(char *dest, const char *src) {
	size_t i = 0;
	while (true) {
		dest[i] = src[i];
		if (src[i] == '\0') {
			break;
		}
		i++;
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <string to uppercase>\n", argv[0]);
		return 1;
	}
    
	char uppercase[strlen(argv[1])];

	my_strcpy(uppercase, argv[1]);

	for (int i = 0; uppercase[i] != '\0'; i++) {
		if(uppercase[i] >= 'a' && uppercase[i] <= 'z') {
			uppercase[i] = uppercase[i] - ('a' - 'A');
		}
	}

	printf("%s\n", uppercase);
}

/* OUTPUT OF COMPILING WITH -fsanitise=address

joni@LAPTOP-V1875EKR:~/NET7212-RUST/lab2/ex2$ clang -fsanitize=address -g uppercase.c -o uppercase
joni@LAPTOP-V1875EKR:~/NET7212-RUST/lab2/ex2$ ./uppercase hello
=================================================================
==53625==ERROR: AddressSanitizer: dynamic-stack-buffer-overflow on address 0x7ffe276164e5 at pc 0x56597055a7d0 bp 0x7ffe27616450 sp 0x7ffe27616448
WRITE of size 1 at 0x7ffe276164e5 thread T0
    #0 0x56597055a7cf in my_strcpy /home/joni/NET7212-RUST/lab2/ex2/uppercase.c:9:11
    #1 0x56597055a9d7 in main /home/joni/NET7212-RUST/lab2/ex2/uppercase.c:25:2
    #2 0x7b6cbb82a1c9 in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #3 0x7b6cbb82a28a in __libc_start_main csu/../csu/libc-start.c:360:3
    #4 0x565970481344 in _start (/home/joni/NET7212-RUST/lab2/ex2/uppercase+0x2b344) (BuildId: e11fd0bf03fe9cb8ca4118f956e6d391f3c5b6b5)

Address 0x7ffe276164e5 is located in stack of thread T0
SUMMARY: AddressSanitizer: dynamic-stack-buffer-overflow /home/joni/NET7212-RUST/lab2/ex2/uppercase.c:9:11 in my_strcpy
Shadow bytes around the buggy address:
  0x7ffe27616200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616300: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616380: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616400: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x7ffe27616480: 00 00 00 00 00 00 00 00 ca ca ca ca[05]cb cb cb
  0x7ffe27616500: cb cb cb cb 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616580: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616600: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616680: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7ffe27616700: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==53625==ABORTING


result from valgrind


==130707== Memcheck, a memory error detector
==130707== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==130707== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==130707== Command: ./uppercase Hello,\ World!
==130707== 
==130707==Shadow memory range interleaves with an existing memory mapping. ASan cannot proceed correctly. ABORTING.
==130707==ASan shadow was supposed to be located in the [0x00007fff7000-0x10007fff7fff] range.
==130707==This might be related to ELF_ET_DYN_BASE change in Linux 4.12.
==130707==See https://github.com/google/sanitizers/issues/856 for possible workarounds.
==130707==Process memory map follows:
        0x000000108000-0x000000133000   /home/joni/NET7212-RUST/lab2/ex2/uppercase
        0x000000133000-0x00000020d000   /home/joni/NET7212-RUST/lab2/ex2/uppercase
        0x00000020d000-0x000000244000   /home/joni/NET7212-RUST/lab2/ex2/uppercase
        0x000000244000-0x000000245000   /home/joni/NET7212-RUST/lab2/ex2/uppercase
        0x000000245000-0x000000248000   /home/joni/NET7212-RUST/lab2/ex2/uppercase
        0x000000248000-0x000000b9c000
        0x000004000000-0x000004001000   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
        0x000004001000-0x00000402c000   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
        0x00000402c000-0x000004036000   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
        0x000004036000-0x000004038000   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
        0x000004038000-0x00000403a000   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
        0x00000403a000-0x00000403b000
        0x00000483a000-0x00000483c000
        0x00000483c000-0x00000483d000   /usr/libexec/valgrind/vgpreload_core-amd64-linux.so
        0x00000483d000-0x00000483e000   /usr/libexec/valgrind/vgpreload_core-amd64-linux.so
        0x00000483e000-0x00000483f000   /usr/libexec/valgrind/vgpreload_core-amd64-linux.so
        0x00000483f000-0x000004840000   /usr/libexec/valgrind/vgpreload_core-amd64-linux.so
        0x000004840000-0x000004841000   /usr/libexec/valgrind/vgpreload_core-amd64-linux.so
        0x000004841000-0x000004846000   /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so
        0x000004846000-0x000004855000   /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so
        0x000004855000-0x000004858000   /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so
        0x000004858000-0x000004859000   /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so
        0x000004859000-0x00000485a000   /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so
        0x00000485a000-0x000004861000
        0x000004865000-0x000004875000   /usr/lib/x86_64-linux-gnu/libm.so.6
        0x000004875000-0x0000048f4000   /usr/lib/x86_64-linux-gnu/libm.so.6
        0x0000048f4000-0x00000494c000   /usr/lib/x86_64-linux-gnu/libm.so.6
        0x00000494c000-0x00000494d000   /usr/lib/x86_64-linux-gnu/libm.so.6
        0x00000494d000-0x00000494e000   /usr/lib/x86_64-linux-gnu/libm.so.6
        0x00000494e000-0x000004951000   /usr/lib/x86_64-linux-gnu/libresolv.so.2
        0x000004951000-0x00000495a000   /usr/lib/x86_64-linux-gnu/libresolv.so.2
        0x00000495a000-0x00000495c000   /usr/lib/x86_64-linux-gnu/libresolv.so.2
        0x00000495c000-0x00000495d000   /usr/lib/x86_64-linux-gnu/libresolv.so.2
        0x00000495d000-0x00000495e000   /usr/lib/x86_64-linux-gnu/libresolv.so.2
        0x00000495e000-0x000004960000
        0x000004960000-0x000004964000   /usr/lib/x86_64-linux-gnu/libgcc_s.so.1
        0x000004964000-0x000004988000   /usr/lib/x86_64-linux-gnu/libgcc_s.so.1
        0x000004988000-0x00000498c000   /usr/lib/x86_64-linux-gnu/libgcc_s.so.1
        0x00000498c000-0x00000498d000   /usr/lib/x86_64-linux-gnu/libgcc_s.so.1
        0x00000498d000-0x00000498e000   /usr/lib/x86_64-linux-gnu/libgcc_s.so.1
        0x00000498e000-0x0000049b6000   /usr/lib/x86_64-linux-gnu/libc.so.6
        0x0000049b6000-0x000004b3f000   /usr/lib/x86_64-linux-gnu/libc.so.6
        0x000004b3f000-0x000004b8e000   /usr/lib/x86_64-linux-gnu/libc.so.6
        0x000004b8e000-0x000004b92000   /usr/lib/x86_64-linux-gnu/libc.so.6
        0x000004b92000-0x000004b94000   /usr/lib/x86_64-linux-gnu/libc.so.6
        0x000004b94000-0x000004f44000
        0x000004f44000-0x000005344000
        0x000005344000-0x000005354000
        0x000058000000-0x000058001000   /usr/libexec/valgrind/memcheck-amd64-linux
        0x000058001000-0x0000581e8000   /usr/libexec/valgrind/memcheck-amd64-linux
        0x0000581e8000-0x000058281000   /usr/libexec/valgrind/memcheck-amd64-linux
        0x000058281000-0x000058287000   /usr/libexec/valgrind/memcheck-amd64-linux
        0x000058287000-0x000059c93000
        0x001002001000-0x001002db8000
        0x001002db8000-0x001002dba000
        0x001002dba000-0x001002eba000
        0x001002eba000-0x001002ebc000
        0x001002ebc000-0x001002ebd000   /tmp/vgdb-pipe-shared-mem-vgdb-130707-by-joni-on-???
        0x001002ebd000-0x00100523d000
        0x001005245000-0x00100527b000
        0x001005431000-0x001005531000
        0x001005a11000-0x001005b11000
        0x001005c97000-0x001005f97000
        0x00100608c000-0x0010062e6000
        0x001ffeffd000-0x001fff001000
        0x7ffee0934000-0x7ffee0956000   [stack]
        0x7ffee098a000-0x7ffee098e000   [vvar]
==130707==End of process memory map.
==130707== 
==130707== HEAP SUMMARY:
==130707==     in use at exit: 0 bytes in 0 blocks
==130707==   total heap usage: 86 allocs, 86 frees, 2,909 bytes allocated
==130707== 
==130707== All heap blocks were freed -- no leaks are possible
==130707== 
==130707== For lists of detected and suppressed errors, rerun with: -s
==130707== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/