	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.file	"stress.xpln"
	.text
	.globl	alotofarguments         # -- Begin function alotofarguments
	.p2align	2
	.type	alotofarguments,@function
	.set	nomicromips
	.set	nomips16
	.ent	alotofarguments
alotofarguments:                        # @alotofarguments
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	ldc1	$f0, 504($sp)
	jr	$ra
	add.d	$f0, $f12, $f0
	.set	at
	.set	macro
	.set	reorder
	.end	alotofarguments
$func_end0:
	.size	alotofarguments, ($func_end0)-alotofarguments
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function testalotofarguments
$CPI1_0:
	.8byte	4607182418800017408     # double 1
$CPI1_1:
	.8byte	4611686018427387904     # double 2
	.text
	.globl	testalotofarguments
	.p2align	2
	.type	testalotofarguments,@function
	.set	nomicromips
	.set	nomips16
	.ent	testalotofarguments
testalotofarguments:                    # @testalotofarguments
	.cfi_startproc
	.frame	$sp,552,$ra
	.mask 	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -552
	.cfi_def_cfa_offset 552
	sw	$ra, 548($sp)           # 4-byte Folded Spill
	sw	$fp, 544($sp)           # 4-byte Folded Spill
	sw	$23, 540($sp)           # 4-byte Folded Spill
	sw	$22, 536($sp)           # 4-byte Folded Spill
	sw	$21, 532($sp)           # 4-byte Folded Spill
	sw	$20, 528($sp)           # 4-byte Folded Spill
	sw	$19, 524($sp)           # 4-byte Folded Spill
	sw	$18, 520($sp)           # 4-byte Folded Spill
	sw	$17, 516($sp)           # 4-byte Folded Spill
	sw	$16, 512($sp)           # 4-byte Folded Spill
	.cfi_offset 31, -4
	.cfi_offset 30, -8
	.cfi_offset 23, -12
	.cfi_offset 22, -16
	.cfi_offset 21, -20
	.cfi_offset 20, -24
	.cfi_offset 19, -28
	.cfi_offset 18, -32
	.cfi_offset 17, -36
	.cfi_offset 16, -40
	lui	$5, 16412
	lui	$6, 16422
	lui	$7, 16418
	lui	$8, 16416
	lui	$9, 16408
	lui	$10, 16404
	lui	$11, 16400
	lui	$12, 16392
	lui	$13, 16430
	lui	$14, 16428
	lui	$15, 16424
	lui	$24, 16420
	lui	$3, 16448
	lui	$25, 16434
	lui	$gp, 16432
	lui	$16, 16426
	lui	$17, 16439
	lui	$2, 16452
	lui	$18, 16437
	lui	$19, 16445
	lui	$20, 16444
	lui	$21, 16443
	lui	$1, 16463
	lui	$22, 16442
	lui	$4, 16450
	lui	$23, 16438
	lui	$fp, 16436
	sw	$12, 16($sp)
	lui	$12, 16433
	sw	$11, 24($sp)
	lui	$11, 16441
	sw	$10, 32($sp)
	lui	$10, 16440
	sw	$9, 40($sp)
	lui	$9, 16451
	sw	$5, 48($sp)
	lui	$5, 16449
	sw	$8, 56($sp)
	lui	$8, 16435
	sw	$7, 64($sp)
	lui	$7, 16454
	sw	$24, 72($sp)
	lui	$24, 16455
	sw	$6, 80($sp)
	lui	$6, 16456
	sw	$15, 88($sp)
	lui	$15, 16457
	sw	$16, 96($sp)
	lui	$16, 16458
	sw	$14, 104($sp)
	lui	$14, 16447
	sw	$13, 112($sp)
	lui	$13, 16446
	sw	$gp, 120($sp)
	lui	$gp, 16461
	sw	$12, 128($sp)
	lui	$12, 16462
	sw	$25, 136($sp)
	ori	$25, $3, 32768
	sw	$8, 144($sp)
	lui	$8, 16459
	sw	$fp, 152($sp)
	lui	$fp, 16460
	sw	$18, 160($sp)
	ori	$18, $5, 32768
	sw	$23, 168($sp)
	ori	$23, $2, 32768
	sw	$17, 176($sp)
	ori	$17, $9, 32768
	sw	$10, 184($sp)
	ori	$10, $4, 32768
	sw	$11, 192($sp)
	lui	$11, 16453
	sw	$22, 200($sp)
	ori	$22, $1, 32768
	sw	$21, 208($sp)
	ori	$21, $12, 32768
	sw	$20, 216($sp)
	ori	$20, $gp, 32768
	sw	$19, 224($sp)
	ori	$19, $fp, 32768
	sw	$13, 232($sp)
	ori	$13, $8, 32768
	sw	$14, 240($sp)
	ori	$14, $16, 32768
	sw	$3, 248($sp)
	ori	$3, $15, 32768
	sw	$25, 256($sp)
	ori	$25, $6, 32768
	sw	$5, 264($sp)
	ori	$5, $24, 32768
	sw	$18, 272($sp)
	ori	$18, $7, 32768
	sw	$4, 280($sp)
	ori	$4, $11, 32768
	sw	$10, 288($sp)
	lui	$10, 16464
	sw	$9, 296($sp)
	sw	$17, 304($sp)
	sw	$2, 312($sp)
	sw	$23, 320($sp)
	sw	$11, 328($sp)
	sw	$4, 336($sp)
	sw	$7, 344($sp)
	sw	$18, 352($sp)
	sw	$24, 360($sp)
	sw	$5, 368($sp)
	sw	$6, 376($sp)
	sw	$25, 384($sp)
	sw	$15, 392($sp)
	sw	$3, 400($sp)
	sw	$16, 408($sp)
	sw	$14, 416($sp)
	sw	$8, 424($sp)
	sw	$13, 432($sp)
	sw	$fp, 440($sp)
	sw	$19, 448($sp)
	sw	$gp, 456($sp)
	sw	$20, 464($sp)
	sw	$12, 472($sp)
	sw	$21, 480($sp)
	sw	$1, 488($sp)
	sw	$22, 496($sp)
	sw	$10, 504($sp)
	sw	$zero, 20($sp)
	sw	$zero, 28($sp)
	sw	$zero, 36($sp)
	sw	$zero, 44($sp)
	sw	$zero, 52($sp)
	sw	$zero, 60($sp)
	sw	$zero, 68($sp)
	sw	$zero, 76($sp)
	sw	$zero, 84($sp)
	sw	$zero, 92($sp)
	sw	$zero, 100($sp)
	sw	$zero, 108($sp)
	sw	$zero, 116($sp)
	sw	$zero, 124($sp)
	sw	$zero, 132($sp)
	sw	$zero, 140($sp)
	sw	$zero, 148($sp)
	sw	$zero, 156($sp)
	sw	$zero, 164($sp)
	sw	$zero, 172($sp)
	sw	$zero, 180($sp)
	sw	$zero, 188($sp)
	sw	$zero, 196($sp)
	sw	$zero, 204($sp)
	sw	$zero, 212($sp)
	sw	$zero, 220($sp)
	sw	$zero, 228($sp)
	sw	$zero, 236($sp)
	sw	$zero, 244($sp)
	sw	$zero, 252($sp)
	sw	$zero, 260($sp)
	sw	$zero, 268($sp)
	sw	$zero, 276($sp)
	sw	$zero, 284($sp)
	sw	$zero, 292($sp)
	sw	$zero, 300($sp)
	sw	$zero, 308($sp)
	sw	$zero, 316($sp)
	sw	$zero, 324($sp)
	sw	$zero, 332($sp)
	sw	$zero, 340($sp)
	sw	$zero, 348($sp)
	sw	$zero, 356($sp)
	sw	$zero, 364($sp)
	sw	$zero, 372($sp)
	sw	$zero, 380($sp)
	sw	$zero, 388($sp)
	sw	$zero, 396($sp)
	sw	$zero, 404($sp)
	sw	$zero, 412($sp)
	sw	$zero, 420($sp)
	sw	$zero, 428($sp)
	sw	$zero, 436($sp)
	sw	$zero, 444($sp)
	sw	$zero, 452($sp)
	sw	$zero, 460($sp)
	sw	$zero, 468($sp)
	sw	$zero, 476($sp)
	sw	$zero, 484($sp)
	sw	$zero, 492($sp)
	sw	$zero, 500($sp)
	sw	$zero, 508($sp)
	lui	$1, %hi($CPI1_0)
	ldc1	$f12, %lo($CPI1_0)($1)
	lui	$1, %hi($CPI1_1)
	ldc1	$f14, %lo($CPI1_1)($1)
	jal	alotofarguments
	nop
	lw	$16, 512($sp)           # 4-byte Folded Reload
	lw	$17, 516($sp)           # 4-byte Folded Reload
	lw	$18, 520($sp)           # 4-byte Folded Reload
	lw	$19, 524($sp)           # 4-byte Folded Reload
	lw	$20, 528($sp)           # 4-byte Folded Reload
	lw	$21, 532($sp)           # 4-byte Folded Reload
	lw	$22, 536($sp)           # 4-byte Folded Reload
	lw	$23, 540($sp)           # 4-byte Folded Reload
	lw	$fp, 544($sp)           # 4-byte Folded Reload
	lw	$ra, 548($sp)           # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 552
	.set	at
	.set	macro
	.set	reorder
	.end	testalotofarguments
$func_end1:
	.size	testalotofarguments, ($func_end1)-testalotofarguments
	.cfi_endproc
                                        # -- End function
	.globl	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa # -- Begin function unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	.p2align	2
	.type	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa,@function
	.set	nomicromips
	.set	nomips16
	.ent	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa: # @unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	mtc1	$zero, $f0
	jr	$ra
	mtc1	$zero, $f1
	.set	at
	.set	macro
	.set	reorder
	.end	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
$func_end2:
	.size	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa, ($func_end2)-unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function triviallyoptimizabledeepnesting
$CPI3_0:
	.8byte	4631107791820423168     # double 42
	.text
	.globl	triviallyoptimizabledeepnesting
	.p2align	2
	.type	triviallyoptimizabledeepnesting,@function
	.set	nomicromips
	.set	nomips16
	.ent	triviallyoptimizabledeepnesting
triviallyoptimizabledeepnesting:        # @triviallyoptimizabledeepnesting
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	lui	$1, %hi($CPI3_0)
	ldc1	$f0, %lo($CPI3_0)($1)
	jr	$ra
	nop
	.set	at
	.set	macro
	.set	reorder
	.end	triviallyoptimizabledeepnesting
$func_end3:
	.size	triviallyoptimizabledeepnesting, ($func_end3)-triviallyoptimizabledeepnesting
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function iterativefactorial
$CPI4_0:
	.8byte	4607182418800017408     # double 1
	.text
	.globl	iterativefactorial
	.p2align	2
	.type	iterativefactorial,@function
	.set	nomicromips
	.set	nomips16
	.ent	iterativefactorial
iterativefactorial:                     # @iterativefactorial
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	lui	$1, %hi($CPI4_0)
	ldc1	$f2, %lo($CPI4_0)($1)
	mov.d	$f4, $f2
	c.ole.d	$f4, $f12
	bc1f	$BB4_2
	mov.d	$f0, $f2
$BB4_1:                                 # %loop
                                        # =>This Inner Loop Header: Depth=1
	mul.d	$f0, $f0, $f4
	add.d	$f4, $f4, $f2
	c.ole.d	$f4, $f12
	bc1t	$BB4_1
	nop
$BB4_2:                                 # %post
	jr	$ra
	nop
	.set	at
	.set	macro
	.set	reorder
	.end	iterativefactorial
$func_end4:
	.size	iterativefactorial, ($func_end4)-iterativefactorial
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function recursivefibonacci
$CPI5_0:
	.8byte	4607182418800017408     # double 1
$CPI5_1:
	.8byte	4611686018427387904     # double 2
$CPI5_2:
	.8byte	-4616189618054758400    # double -1
$CPI5_3:
	.8byte	-4611686018427387904    # double -2
	.text
	.globl	recursivefibonacci
	.p2align	2
	.type	recursivefibonacci,@function
	.set	nomicromips
	.set	nomips16
	.ent	recursivefibonacci
recursivefibonacci:                     # @recursivefibonacci
	.cfi_startproc
	.frame	$sp,40,$ra
	.mask 	0x80000000,-20
	.fmask	0x00f00000,-8
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -40
	.cfi_def_cfa_offset 40
	sdc1	$f22, 32($sp)           # 8-byte Folded Spill
	sdc1	$f20, 24($sp)           # 8-byte Folded Spill
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 55, -8
	.cfi_offset 54, -4
	.cfi_offset 53, -16
	.cfi_offset 52, -12
	.cfi_offset 31, -20
	lui	$1, %hi($CPI5_0)
	ldc1	$f0, %lo($CPI5_0)($1)
	c.eq.d	$f12, $f0
	bc1t	$BB5_3
	nop
# %bb.1:                                # %entry
	lui	$1, %hi($CPI5_1)
	ldc1	$f2, %lo($CPI5_1)($1)
	c.eq.d	$f12, $f2
	bc1t	$BB5_3
	mov.d	$f20, $f12
# %bb.2:                                # %else
	lui	$1, %hi($CPI5_2)
	ldc1	$f0, %lo($CPI5_2)($1)
	jal	recursivefibonacci
	add.d	$f12, $f20, $f0
	mov.d	$f22, $f0
	lui	$1, %hi($CPI5_3)
	ldc1	$f0, %lo($CPI5_3)($1)
	jal	recursivefibonacci
	add.d	$f12, $f20, $f0
	add.d	$f0, $f22, $f0
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
$BB5_3:                                 # %then
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
	.set	at
	.set	macro
	.set	reorder
	.end	recursivefibonacci
$func_end5:
	.size	recursivefibonacci, ($func_end5)-recursivefibonacci
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function calculatepi
$CPI6_0:
	.8byte	-4616189618054758400    # double -1
$CPI6_1:
	.8byte	4607182418800017408     # double 1
$CPI6_2:
	.8byte	4616189618054758400     # double 4
	.text
	.globl	calculatepi
	.p2align	2
	.type	calculatepi,@function
	.set	nomicromips
	.set	nomips16
	.ent	calculatepi
calculatepi:                            # @calculatepi
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	lui	$1, %hi($CPI6_0)
	ldc1	$f4, %lo($CPI6_0)($1)
	lui	$1, %hi($CPI6_1)
	ldc1	$f2, %lo($CPI6_1)($1)
	mov.d	$f6, $f2
	c.ole.d	$f6, $f12
	bc1f	$BB6_2
	mov.d	$f0, $f2
$BB6_1:                                 # %loop
                                        # =>This Inner Loop Header: Depth=1
	mtc1	$zero, $f8
	mtc1	$zero, $f9
	sub.d	$f8, $f8, $f4
	add.d	$f10, $f6, $f2
	add.d	$f6, $f6, $f6
	add.d	$f6, $f6, $f2
	div.d	$f4, $f4, $f6
	add.d	$f0, $f0, $f4
	mov.d	$f6, $f10
	c.ole.d	$f6, $f12
	bc1t	$BB6_1
	mov.d	$f4, $f8
$BB6_2:                                 # %post
	lui	$1, %hi($CPI6_2)
	ldc1	$f2, %lo($CPI6_2)($1)
	jr	$ra
	mul.d	$f0, $f0, $f2
	.set	at
	.set	macro
	.set	reorder
	.end	calculatepi
$func_end6:
	.size	calculatepi, ($func_end6)-calculatepi
	.cfi_endproc
                                        # -- End function
	.globl	abs                     # -- Begin function abs
	.p2align	2
	.type	abs,@function
	.set	nomicromips
	.set	nomips16
	.ent	abs
abs:                                    # @abs
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	c.olt.d	$f12, $f0
	bc1f	$BB7_2
	nop
# %bb.1:                                # %then
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	jr	$ra
	sub.d	$f0, $f0, $f12
$BB7_2:                                 # %else
	jr	$ra
	mov.d	$f0, $f12
	.set	at
	.set	macro
	.set	reorder
	.end	abs
$func_end7:
	.size	abs, ($func_end7)-abs
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function eq
$CPI8_0:
	.8byte	4562254508917369340     # double 0.001
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	3
$CPI8_1:
	.8byte	-4616189618054758400    # double -1
	.8byte	4607182418800017408     # double 1
	.text
	.globl	eq
	.p2align	2
	.type	eq,@function
	.set	nomicromips
	.set	nomips16
	.ent	eq
eq:                                     # @eq
	.cfi_startproc
	.frame	$sp,24,$ra
	.mask 	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -24
	.cfi_def_cfa_offset 24
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	jal	abs
	sub.d	$f12, $f12, $f14
	lui	$1, %hi($CPI8_0)
	ldc1	$f2, %lo($CPI8_0)($1)
	addiu	$1, $zero, 1
	c.olt.d	$f0, $f2
	movf	$1, $zero, $fcc0
	sll	$1, $1, 3
	lui	$2, %hi($CPI8_1)
	addiu	$2, $2, %lo($CPI8_1)
	addu	$1, $2, $1
	ldc1	$f0, 0($1)
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 24
	.set	at
	.set	macro
	.set	reorder
	.end	eq
$func_end8:
	.size	eq, ($func_end8)-eq
	.cfi_endproc
                                        # -- End function
	.globl	euclideangcd            # -- Begin function euclideangcd
	.p2align	2
	.type	euclideangcd,@function
	.set	nomicromips
	.set	nomips16
	.ent	euclideangcd
euclideangcd:                           # @euclideangcd
	.cfi_startproc
	.frame	$sp,40,$ra
	.mask 	0x80000000,-20
	.fmask	0x00f00000,-8
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -40
	.cfi_def_cfa_offset 40
	sdc1	$f22, 32($sp)           # 8-byte Folded Spill
	sdc1	$f20, 24($sp)           # 8-byte Folded Spill
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 55, -8
	.cfi_offset 54, -4
	.cfi_offset 53, -16
	.cfi_offset 52, -12
	.cfi_offset 31, -20
	mov.d	$f22, $f14
	j	$BB9_2
	mov.d	$f20, $f12
$BB9_1:                                 # %loop
                                        #   in Loop: Header=BB9_2 Depth=1
	sub.d	$f0, $f22, $f20
	c.ule.d	$f20, $f22
	movf.d	$f0, $f22, $fcc0
	sub.d	$f2, $f20, $f22
	movf.d	$f20, $f2, $fcc0
	mov.d	$f22, $f0
$BB9_2:                                 # %cond
                                        # =>This Inner Loop Header: Depth=1
	mov.d	$f12, $f20
	jal	eq
	mov.d	$f14, $f22
	mtc1	$zero, $f2
	mtc1	$zero, $f3
	c.olt.d	$f0, $f2
	bc1t	$BB9_1
	nop
# %bb.3:                                # %post
	mov.d	$f0, $f20
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
	.set	at
	.set	macro
	.set	reorder
	.end	euclideangcd
$func_end9:
	.size	euclideangcd, ($func_end9)-euclideangcd
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function modulo
$CPI10_0:
	.8byte	4607182418800017408     # double 1
	.text
	.globl	modulo
	.p2align	2
	.type	modulo,@function
	.set	nomicromips
	.set	nomips16
	.ent	modulo
modulo:                                 # @modulo
	.cfi_startproc
	.frame	$sp,0,$ra
	.mask 	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	mtc1	$zero, $f2
	lui	$1, %hi($CPI10_0)
	ldc1	$f4, %lo($CPI10_0)($1)
	j	$BB10_2
	mtc1	$zero, $f3
$BB10_1:                                # %loop
                                        #   in Loop: Header=BB10_2 Depth=1
	add.d	$f2, $f2, $f4
$BB10_2:                                # %cond
                                        # =>This Inner Loop Header: Depth=1
	mul.d	$f0, $f14, $f2
	sub.d	$f0, $f12, $f0
	c.ult.d	$f0, $f14
	bc1f	$BB10_1
	nop
# %bb.3:                                # %post
	jr	$ra
	nop
	.set	at
	.set	macro
	.set	reorder
	.end	modulo
$func_end10:
	.size	modulo, ($func_end10)-modulo
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function iseven
$CPI11_0:
	.8byte	4611686018427387904     # double 2
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	3
$CPI11_1:
	.8byte	-4616189618054758400    # double -1
	.8byte	4607182418800017408     # double 1
	.text
	.globl	iseven
	.p2align	2
	.type	iseven,@function
	.set	nomicromips
	.set	nomips16
	.ent	iseven
iseven:                                 # @iseven
	.cfi_startproc
	.frame	$sp,24,$ra
	.mask 	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -24
	.cfi_def_cfa_offset 24
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	lui	$1, %hi($CPI11_0)
	ldc1	$f14, %lo($CPI11_0)($1)
	jal	modulo
	nop
	mtc1	$zero, $f2
	mtc1	$zero, $f3
	addiu	$1, $zero, 1
	c.eq.d	$f0, $f2
	movf	$1, $zero, $fcc0
	sll	$1, $1, 3
	lui	$2, %hi($CPI11_1)
	addiu	$2, $2, %lo($CPI11_1)
	addu	$1, $2, $1
	ldc1	$f0, 0($1)
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 24
	.set	at
	.set	macro
	.set	reorder
	.end	iseven
$func_end11:
	.size	iseven, ($func_end11)-iseven
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function isodd
$CPI12_0:
	.8byte	4607182418800017408     # double 1
	.text
	.globl	isodd
	.p2align	2
	.type	isodd,@function
	.set	nomicromips
	.set	nomips16
	.ent	isodd
isodd:                                  # @isodd
	.cfi_startproc
	.frame	$sp,24,$ra
	.mask 	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -24
	.cfi_def_cfa_offset 24
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	jal	iseven
	nop
	lui	$1, %hi($CPI12_0)
	ldc1	$f2, %lo($CPI12_0)($1)
	sub.d	$f0, $f2, $f0
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 24
	.set	at
	.set	macro
	.set	reorder
	.end	isodd
$func_end12:
	.size	isodd, ($func_end12)-isodd
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function exponentiationbysquaring
$CPI13_0:
	.8byte	4607182418800017408     # double 1
$CPI13_1:
	.8byte	-4616189618054758400    # double -1
$CPI13_2:
	.8byte	4602678819172646912     # double 0.5
	.text
	.globl	exponentiationbysquaring
	.p2align	2
	.type	exponentiationbysquaring,@function
	.set	nomicromips
	.set	nomips16
	.ent	exponentiationbysquaring
exponentiationbysquaring:               # @exponentiationbysquaring
	.cfi_startproc
	.frame	$sp,40,$ra
	.mask 	0x80000000,-20
	.fmask	0x00f00000,-8
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -40
	.cfi_def_cfa_offset 40
	sdc1	$f22, 32($sp)           # 8-byte Folded Spill
	sdc1	$f20, 24($sp)           # 8-byte Folded Spill
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 55, -8
	.cfi_offset 54, -4
	.cfi_offset 53, -16
	.cfi_offset 52, -12
	.cfi_offset 31, -20
	mov.d	$f22, $f14
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	c.olt.d	$f14, $f0
	bc1f	$BB13_2
	mov.d	$f20, $f12
# %bb.1:                                # %then
	lui	$1, %hi($CPI13_0)
	ldc1	$f0, %lo($CPI13_0)($1)
	div.d	$f12, $f0, $f20
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	jal	exponentiationbysquaring
	sub.d	$f14, $f0, $f22
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
$BB13_2:                                # %else
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	c.eq.d	$f22, $f0
	bc1f	$BB13_4
	lui	$2, %hi($CPI13_0)
# %bb.3:
	ldc1	$f20, %lo($CPI13_0)($2)
	j	$BB13_5
	nop
$BB13_4:                                # %else8
	ldc1	$f0, %lo($CPI13_0)($2)
	c.eq.d	$f22, $f0
	bc1f	$BB13_6
	nop
$BB13_5:                                # %then7
	mov.d	$f0, $f20
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
$BB13_6:                                # %else12
	jal	iseven
	mov.d	$f12, $f22
	lui	$1, %hi($CPI13_0)
	ldc1	$f2, %lo($CPI13_0)($1)
	c.ule.d	$f0, $f2
	bc1t	$BB13_8
	mul.d	$f12, $f20, $f20
# %bb.7:                                # %then16
	lui	$1, %hi($CPI13_2)
	ldc1	$f0, %lo($CPI13_2)($1)
	jal	exponentiationbysquaring
	mul.d	$f14, $f22, $f0
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
$BB13_8:                                # %else17
	lui	$1, %hi($CPI13_1)
	ldc1	$f0, %lo($CPI13_1)($1)
	add.d	$f0, $f22, $f0
	lui	$1, %hi($CPI13_2)
	ldc1	$f2, %lo($CPI13_2)($1)
	jal	exponentiationbysquaring
	mul.d	$f14, $f0, $f2
	mul.d	$f0, $f20, $f0
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	ldc1	$f20, 24($sp)           # 8-byte Folded Reload
	ldc1	$f22, 32($sp)           # 8-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 40
	.set	at
	.set	macro
	.set	reorder
	.end	exponentiationbysquaring
$func_end13:
	.size	exponentiationbysquaring, ($func_end13)-exponentiationbysquaring
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function etothepower
$CPI14_0:
	.8byte	4613303445314885481     # double 2.7182818284590451
	.text
	.globl	etothepower
	.p2align	2
	.type	etothepower,@function
	.set	nomicromips
	.set	nomips16
	.ent	etothepower
etothepower:                            # @etothepower
	.cfi_startproc
	.frame	$sp,24,$ra
	.mask 	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -24
	.cfi_def_cfa_offset 24
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	mov.d	$f14, $f12
	lui	$1, %hi($CPI14_0)
	ldc1	$f12, %lo($CPI14_0)($1)
	jal	exponentiationbysquaring
	nop
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 24
	.set	at
	.set	macro
	.set	reorder
	.end	etothepower
$func_end14:
	.size	etothepower, ($func_end14)-etothepower
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function xpln_main
$CPI15_0:
	.8byte	4626322717216342016     # double 20
$CPI15_1:
	.8byte	4629137466983448576     # double 30
$CPI15_2:
	.8byte	4726483295884279808     # double 1.0E+8
$CPI15_3:
	.8byte	4677173480733540352     # double 50500
$CPI15_4:
	.8byte	4681670139693760512     # double 100899
$CPI15_5:
	.8byte	4636737291354636288     # double 100
$CPI15_6:
	.8byte	4619567317775286272     # double 7
$CPI15_7:
	.8byte	4624633867356078080     # double 15
	.text
	.globl	xpln_main
	.p2align	2
	.type	xpln_main,@function
	.set	nomicromips
	.set	nomips16
	.ent	xpln_main
xpln_main:                              # @xpln_main
	.cfi_startproc
	.frame	$sp,24,$ra
	.mask 	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -24
	.cfi_def_cfa_offset 24
	sw	$ra, 20($sp)            # 4-byte Folded Spill
	sw	$16, 16($sp)            # 4-byte Folded Spill
	.cfi_offset 31, -4
	.cfi_offset 16, -8
	jal	testalotofarguments
	nop
	lui	$1, %hi(ofmt)
	addiu	$16, $1, %lo(ofmt)
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	jal	unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	nop
	jal	triviallyoptimizabledeepnesting
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_0)
	ldc1	$f12, %lo($CPI15_0)($1)
	jal	iterativefactorial
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_1)
	ldc1	$f12, %lo($CPI15_1)($1)
	jal	recursivefibonacci
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_2)
	ldc1	$f12, %lo($CPI15_2)($1)
	jal	calculatepi
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_3)
	ldc1	$f12, %lo($CPI15_3)($1)
	lui	$1, %hi($CPI15_4)
	ldc1	$f14, %lo($CPI15_4)($1)
	jal	euclideangcd
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_5)
	ldc1	$f12, %lo($CPI15_5)($1)
	lui	$1, %hi($CPI15_6)
	ldc1	$f14, %lo($CPI15_6)($1)
	jal	modulo
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	lui	$1, %hi($CPI15_7)
	ldc1	$f12, %lo($CPI15_7)($1)
	jal	etothepower
	nop
	mfc1	$6, $f1
	mfc1	$7, $f0
	jal	printf
	move	$4, $16
	mtc1	$zero, $f0
	mtc1	$zero, $f1
	lw	$16, 16($sp)            # 4-byte Folded Reload
	lw	$ra, 20($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 24
	.set	at
	.set	macro
	.set	reorder
	.end	xpln_main
$func_end15:
	.size	xpln_main, ($func_end15)-xpln_main
	.cfi_endproc
                                        # -- End function
	.type	ifmt,@object            # @ifmt
	.section	.rodata,"a",@progbits
	.p2align	2
ifmt:
	.asciz	"%lf"
	.size	ifmt, 4

	.type	ofmt,@object            # @ofmt
	.p2align	2
ofmt:
	.asciz	"%lf\n"
	.size	ofmt, 5


	.section	".note.GNU-stack","",@progbits
	.text
