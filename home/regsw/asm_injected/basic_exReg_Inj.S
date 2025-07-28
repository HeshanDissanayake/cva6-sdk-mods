	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_zicsr2p0_zifencei2p0"
	.file	"basic.c"
	.option	push
	.option	arch, +a, +m, +zifencei
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   # @main
# %bb.0:
	addi	sp, sp, -16
	sd	ra, 8(sp)                       # 8-byte Folded Spill
	#APP
	regsw_c	x8, 0x600(x30)		# 111100100011000000000
	add	x20, x3, x4
	#NO_APP
	#APP
	li	x6, 3
	#NO_APP
	#APP
	li	x7, 6
	#NO_APP
	#APP
	add	a1, x6, x7
	#NO_APP
	sext.w	a1, a1
	lui	a0, %hi(.L.str)
	addi	a0, a0, %lo(.L.str)
	call	printf
	li	a0, 0
	ld	ra, 8(sp)                       # 8-byte Folded Reload
	addi	sp, sp, 16
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.option	pop
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"result %d\n"
	.size	.L.str, 11

	.ident	"clang version 19.0.0git (https://github.com/llvm/llvm-project.git 4b702946006cfa9be9ab646ce5fc5b25248edd81)"
	.section	".note.GNU-stack","",@progbits
