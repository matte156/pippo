	.file	"commonFunctions.c"
	.text
.Ltext0:
	.file 0 "/home/biblio/wordle" "src/commonFunctions.c"
	.section	.rodata
.LC0:
	.string	"r"
	.align 8
.LC1:
	.string	"usefulDataset/dataset-ascii.txt"
.LC2:
	.string	"%d\n"
	.text
	.globl	openDataset
	.type	openDataset, @function
openDataset:
.LFB6:
	.file 1 "src/commonFunctions.c"
	.loc 1 5 1
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	.loc 1 6 16
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -8(%rbp)
	.loc 1 10 9
	movl	$0, -16(%rbp)
	.loc 1 12 10
	nop
.L4:
	.loc 1 12 15 discriminator 5
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc@PLT
	.loc 1 12 14 discriminator 5
	movb	%al, -17(%rbp)
	.loc 1 12 55 discriminator 5
	cmpb	$10, -17(%rbp)
	jne	.L2
	.loc 1 12 55 is_stmt 0 discriminator 1
	addl	$1, -16(%rbp)
	cmpl	$-1, -16(%rbp)
	setne	%al
	jmp	.L3
.L2:
	.loc 1 12 55 discriminator 2
	cmpb	$-1, -17(%rbp)
	setne	%al
.L3:
	.loc 1 12 55 discriminator 4
	testb	%al, %al
	jne	.L4
	.loc 1 15 5 is_stmt 1
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 18 48
	movl	-16(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	.loc 1 18 35
	cltq
	.loc 1 18 16
	addq	$1, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, %rdx
	.loc 1 18 14
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	.loc 1 20 5
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	fseek@PLT
	.loc 1 22 9
	movl	$0, -12(%rbp)
	.loc 1 23 13
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	.loc 1 23 17
	movb	$97, (%rax)
	.loc 1 28 10
	jmp	.L5
.L6:
	.loc 1 30 6
	movsbl	-17(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	.loc 1 31 14
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	.loc 1 31 24
	movzbl	-17(%rbp), %edx
	movb	%dl, (%rax)
.L5:
	.loc 1 28 14
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc@PLT
	.loc 1 28 13
	movb	%al, -17(%rbp)
	.loc 1 28 24
	cmpb	$-1, -17(%rbp)
	jne	.L6
	.loc 1 33 5
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	.loc 1 35 12
	movl	-16(%rbp), %eax
	.loc 1 36 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	openDataset, .-openDataset
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
	.file 6 "/usr/include/stdio.h"
	.file 7 "/usr/include/stdlib.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x380
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0xc
	.long	.LASF56
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x6
	.long	.LASF10
	.byte	0x2
	.byte	0xd1
	.byte	0x17
	.long	0x3a
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF2
	.uleb128 0xd
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF3
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF4
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF5
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF6
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF9
	.uleb128 0x6
	.long	.LASF11
	.byte	0x3
	.byte	0x98
	.byte	0x19
	.long	0x48
	.uleb128 0x6
	.long	.LASF12
	.byte	0x3
	.byte	0x99
	.byte	0x1b
	.long	0x48
	.uleb128 0xe
	.byte	0x8
	.uleb128 0x3
	.long	0x98
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF13
	.uleb128 0xf
	.long	0x98
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF14
	.uleb128 0x10
	.long	.LASF57
	.byte	0xd8
	.byte	0x4
	.byte	0x31
	.byte	0x8
	.long	0x215
	.uleb128 0x1
	.long	.LASF15
	.byte	0x33
	.byte	0x7
	.long	0x41
	.byte	0
	.uleb128 0x1
	.long	.LASF16
	.byte	0x36
	.byte	0x9
	.long	0x93
	.byte	0x8
	.uleb128 0x1
	.long	.LASF17
	.byte	0x37
	.byte	0x9
	.long	0x93
	.byte	0x10
	.uleb128 0x1
	.long	.LASF18
	.byte	0x38
	.byte	0x9
	.long	0x93
	.byte	0x18
	.uleb128 0x1
	.long	.LASF19
	.byte	0x39
	.byte	0x9
	.long	0x93
	.byte	0x20
	.uleb128 0x1
	.long	.LASF20
	.byte	0x3a
	.byte	0x9
	.long	0x93
	.byte	0x28
	.uleb128 0x1
	.long	.LASF21
	.byte	0x3b
	.byte	0x9
	.long	0x93
	.byte	0x30
	.uleb128 0x1
	.long	.LASF22
	.byte	0x3c
	.byte	0x9
	.long	0x93
	.byte	0x38
	.uleb128 0x1
	.long	.LASF23
	.byte	0x3d
	.byte	0x9
	.long	0x93
	.byte	0x40
	.uleb128 0x1
	.long	.LASF24
	.byte	0x40
	.byte	0x9
	.long	0x93
	.byte	0x48
	.uleb128 0x1
	.long	.LASF25
	.byte	0x41
	.byte	0x9
	.long	0x93
	.byte	0x50
	.uleb128 0x1
	.long	.LASF26
	.byte	0x42
	.byte	0x9
	.long	0x93
	.byte	0x58
	.uleb128 0x1
	.long	.LASF27
	.byte	0x44
	.byte	0x16
	.long	0x22e
	.byte	0x60
	.uleb128 0x1
	.long	.LASF28
	.byte	0x46
	.byte	0x14
	.long	0x233
	.byte	0x68
	.uleb128 0x1
	.long	.LASF29
	.byte	0x48
	.byte	0x7
	.long	0x41
	.byte	0x70
	.uleb128 0x1
	.long	.LASF30
	.byte	0x49
	.byte	0x7
	.long	0x41
	.byte	0x74
	.uleb128 0x1
	.long	.LASF31
	.byte	0x4a
	.byte	0xb
	.long	0x79
	.byte	0x78
	.uleb128 0x1
	.long	.LASF32
	.byte	0x4d
	.byte	0x12
	.long	0x5d
	.byte	0x80
	.uleb128 0x1
	.long	.LASF33
	.byte	0x4e
	.byte	0xf
	.long	0x6b
	.byte	0x82
	.uleb128 0x1
	.long	.LASF34
	.byte	0x4f
	.byte	0x8
	.long	0x238
	.byte	0x83
	.uleb128 0x1
	.long	.LASF35
	.byte	0x51
	.byte	0xf
	.long	0x248
	.byte	0x88
	.uleb128 0x1
	.long	.LASF36
	.byte	0x59
	.byte	0xd
	.long	0x85
	.byte	0x90
	.uleb128 0x1
	.long	.LASF37
	.byte	0x5b
	.byte	0x17
	.long	0x252
	.byte	0x98
	.uleb128 0x1
	.long	.LASF38
	.byte	0x5c
	.byte	0x19
	.long	0x25c
	.byte	0xa0
	.uleb128 0x1
	.long	.LASF39
	.byte	0x5d
	.byte	0x14
	.long	0x233
	.byte	0xa8
	.uleb128 0x1
	.long	.LASF40
	.byte	0x5e
	.byte	0x9
	.long	0x91
	.byte	0xb0
	.uleb128 0x1
	.long	.LASF41
	.byte	0x5f
	.byte	0xa
	.long	0x2e
	.byte	0xb8
	.uleb128 0x1
	.long	.LASF42
	.byte	0x60
	.byte	0x7
	.long	0x41
	.byte	0xc0
	.uleb128 0x1
	.long	.LASF43
	.byte	0x62
	.byte	0x8
	.long	0x261
	.byte	0xc4
	.byte	0
	.uleb128 0x6
	.long	.LASF44
	.byte	0x5
	.byte	0x7
	.byte	0x19
	.long	0xab
	.uleb128 0x11
	.long	.LASF58
	.byte	0x4
	.byte	0x2b
	.byte	0xe
	.uleb128 0x7
	.long	.LASF45
	.uleb128 0x3
	.long	0x229
	.uleb128 0x3
	.long	0xab
	.uleb128 0x8
	.long	0x98
	.long	0x248
	.uleb128 0x9
	.long	0x3a
	.byte	0
	.byte	0
	.uleb128 0x3
	.long	0x221
	.uleb128 0x7
	.long	.LASF46
	.uleb128 0x3
	.long	0x24d
	.uleb128 0x7
	.long	.LASF47
	.uleb128 0x3
	.long	0x257
	.uleb128 0x8
	.long	0x98
	.long	0x271
	.uleb128 0x9
	.long	0x3a
	.byte	0x13
	.byte	0
	.uleb128 0x3
	.long	0x215
	.uleb128 0x12
	.long	.LASF48
	.byte	0x6
	.byte	0xb2
	.byte	0xc
	.long	0x41
	.long	0x28c
	.uleb128 0x4
	.long	0x271
	.byte	0
	.uleb128 0x5
	.long	.LASF49
	.byte	0x6
	.value	0x2c9
	.byte	0xc
	.long	0x41
	.long	0x2ad
	.uleb128 0x4
	.long	0x271
	.uleb128 0x4
	.long	0x48
	.uleb128 0x4
	.long	0x41
	.byte	0
	.uleb128 0x5
	.long	.LASF50
	.byte	0x7
	.value	0x21c
	.byte	0xe
	.long	0x91
	.long	0x2c4
	.uleb128 0x4
	.long	0x2e
	.byte	0
	.uleb128 0x5
	.long	.LASF51
	.byte	0x6
	.value	0x164
	.byte	0xc
	.long	0x41
	.long	0x2dc
	.uleb128 0x4
	.long	0x2dc
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.long	0x9f
	.uleb128 0x14
	.long	0x2dc
	.uleb128 0x5
	.long	.LASF52
	.byte	0x6
	.value	0x201
	.byte	0xc
	.long	0x41
	.long	0x2fd
	.uleb128 0x4
	.long	0x271
	.byte	0
	.uleb128 0x5
	.long	.LASF53
	.byte	0x6
	.value	0x102
	.byte	0xe
	.long	0x271
	.long	0x319
	.uleb128 0x4
	.long	0x2e1
	.uleb128 0x4
	.long	0x2e1
	.byte	0
	.uleb128 0x15
	.long	.LASF59
	.byte	0x1
	.byte	0x4
	.byte	0x5
	.long	0x41
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x37e
	.uleb128 0x16
	.long	.LASF60
	.byte	0x1
	.byte	0x4
	.byte	0x18
	.long	0x37e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xa
	.string	"fp"
	.byte	0x6
	.byte	0xb
	.long	0x271
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.long	.LASF54
	.byte	0xa
	.long	0x41
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xa
	.string	"c"
	.byte	0xb
	.byte	0xa
	.long	0x98
	.uleb128 0x2
	.byte	0x91
	.sleb128 -33
	.uleb128 0xb
	.long	.LASF55
	.byte	0x16
	.long	0x41
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x3
	.long	0x93
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 4
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 9
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x37
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF12:
	.string	"__off64_t"
.LASF17:
	.string	"_IO_read_end"
.LASF10:
	.string	"size_t"
.LASF57:
	.string	"_IO_FILE"
.LASF19:
	.string	"_IO_write_base"
.LASF23:
	.string	"_IO_buf_end"
.LASF56:
	.string	"GNU C17 11.3.0 -mtune=generic -march=x86-64 -g -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF16:
	.string	"_IO_read_ptr"
.LASF41:
	.string	"__pad5"
.LASF7:
	.string	"unsigned int"
.LASF36:
	.string	"_offset"
.LASF42:
	.string	"_mode"
.LASF28:
	.string	"_chain"
.LASF55:
	.string	"counter"
.LASF24:
	.string	"_IO_save_base"
.LASF5:
	.string	"unsigned char"
.LASF49:
	.string	"fseek"
.LASF2:
	.string	"long unsigned int"
.LASF6:
	.string	"short unsigned int"
.LASF48:
	.string	"fclose"
.LASF26:
	.string	"_IO_save_end"
.LASF58:
	.string	"_IO_lock_t"
.LASF27:
	.string	"_markers"
.LASF53:
	.string	"fopen"
.LASF44:
	.string	"FILE"
.LASF59:
	.string	"openDataset"
.LASF31:
	.string	"_old_offset"
.LASF35:
	.string	"_lock"
.LASF45:
	.string	"_IO_marker"
.LASF60:
	.string	"dataset"
.LASF32:
	.string	"_cur_column"
.LASF14:
	.string	"long long unsigned int"
.LASF46:
	.string	"_IO_codecvt"
.LASF29:
	.string	"_fileno"
.LASF52:
	.string	"fgetc"
.LASF22:
	.string	"_IO_buf_base"
.LASF30:
	.string	"_flags2"
.LASF33:
	.string	"_vtable_offset"
.LASF37:
	.string	"_codecvt"
.LASF39:
	.string	"_freeres_list"
.LASF11:
	.string	"__off_t"
.LASF43:
	.string	"_unused2"
.LASF4:
	.string	"long long int"
.LASF13:
	.string	"char"
.LASF51:
	.string	"printf"
.LASF21:
	.string	"_IO_write_end"
.LASF9:
	.string	"short int"
.LASF25:
	.string	"_IO_backup_base"
.LASF15:
	.string	"_flags"
.LASF38:
	.string	"_wide_data"
.LASF3:
	.string	"long int"
.LASF20:
	.string	"_IO_write_ptr"
.LASF54:
	.string	"linecounter"
.LASF47:
	.string	"_IO_wide_data"
.LASF8:
	.string	"signed char"
.LASF40:
	.string	"_freeres_buf"
.LASF18:
	.string	"_IO_read_base"
.LASF50:
	.string	"malloc"
.LASF34:
	.string	"_shortbuf"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/biblio/wordle"
.LASF0:
	.string	"src/commonFunctions.c"
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
