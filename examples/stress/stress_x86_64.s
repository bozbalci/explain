	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 14
	.globl	_alotofarguments        ## -- Begin function alotofarguments
	.p2align	4, 0x90
_alotofarguments:                       ## @alotofarguments
	.cfi_startproc
## %bb.0:                               ## %entry
	addsd	448(%rsp), %xmm0
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function testalotofarguments
LCPI1_0:
	.quad	4607182418800017408     ## double 1
LCPI1_1:
	.quad	4611686018427387904     ## double 2
LCPI1_2:
	.quad	4613937818241073152     ## double 3
LCPI1_3:
	.quad	4616189618054758400     ## double 4
LCPI1_4:
	.quad	4617315517961601024     ## double 5
LCPI1_5:
	.quad	4618441417868443648     ## double 6
LCPI1_6:
	.quad	4619567317775286272     ## double 7
LCPI1_7:
	.quad	4620693217682128896     ## double 8
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_testalotofarguments
	.p2align	4, 0x90
_testalotofarguments:                   ## @testalotofarguments
	.cfi_startproc
## %bb.0:                               ## %entry
	subq	$456, %rsp              ## imm = 0x1C8
	.cfi_def_cfa_offset 464
	movabsq	$4634204016564240384, %rax ## imm = 0x4050000000000000
	movq	%rax, 440(%rsp)
	movabsq	$4634063279075885056, %rax ## imm = 0x404F800000000000
	movq	%rax, 432(%rsp)
	movabsq	$4633922541587529728, %rax ## imm = 0x404F000000000000
	movq	%rax, 424(%rsp)
	movabsq	$4633781804099174400, %rax ## imm = 0x404E800000000000
	movq	%rax, 416(%rsp)
	movabsq	$4633641066610819072, %rax ## imm = 0x404E000000000000
	movq	%rax, 408(%rsp)
	movabsq	$4633500329122463744, %rax ## imm = 0x404D800000000000
	movq	%rax, 400(%rsp)
	movabsq	$4633359591634108416, %rax ## imm = 0x404D000000000000
	movq	%rax, 392(%rsp)
	movabsq	$4633218854145753088, %rax ## imm = 0x404C800000000000
	movq	%rax, 384(%rsp)
	movabsq	$4633078116657397760, %rax ## imm = 0x404C000000000000
	movq	%rax, 376(%rsp)
	movabsq	$4632937379169042432, %rax ## imm = 0x404B800000000000
	movq	%rax, 368(%rsp)
	movabsq	$4632796641680687104, %rax ## imm = 0x404B000000000000
	movq	%rax, 360(%rsp)
	movabsq	$4632655904192331776, %rax ## imm = 0x404A800000000000
	movq	%rax, 352(%rsp)
	movabsq	$4632515166703976448, %rax ## imm = 0x404A000000000000
	movq	%rax, 344(%rsp)
	movabsq	$4632374429215621120, %rax ## imm = 0x4049800000000000
	movq	%rax, 336(%rsp)
	movabsq	$4632233691727265792, %rax ## imm = 0x4049000000000000
	movq	%rax, 328(%rsp)
	movabsq	$4632092954238910464, %rax ## imm = 0x4048800000000000
	movq	%rax, 320(%rsp)
	movabsq	$4631952216750555136, %rax ## imm = 0x4048000000000000
	movq	%rax, 312(%rsp)
	movabsq	$4631811479262199808, %rax ## imm = 0x4047800000000000
	movq	%rax, 304(%rsp)
	movabsq	$4631670741773844480, %rax ## imm = 0x4047000000000000
	movq	%rax, 296(%rsp)
	movabsq	$4631530004285489152, %rax ## imm = 0x4046800000000000
	movq	%rax, 288(%rsp)
	movabsq	$4631389266797133824, %rax ## imm = 0x4046000000000000
	movq	%rax, 280(%rsp)
	movabsq	$4631248529308778496, %rax ## imm = 0x4045800000000000
	movq	%rax, 272(%rsp)
	movabsq	$4631107791820423168, %rax ## imm = 0x4045000000000000
	movq	%rax, 264(%rsp)
	movabsq	$4630967054332067840, %rax ## imm = 0x4044800000000000
	movq	%rax, 256(%rsp)
	movabsq	$4630826316843712512, %rax ## imm = 0x4044000000000000
	movq	%rax, 248(%rsp)
	movabsq	$4630685579355357184, %rax ## imm = 0x4043800000000000
	movq	%rax, 240(%rsp)
	movabsq	$4630544841867001856, %rax ## imm = 0x4043000000000000
	movq	%rax, 232(%rsp)
	movabsq	$4630404104378646528, %rax ## imm = 0x4042800000000000
	movq	%rax, 224(%rsp)
	movabsq	$4630263366890291200, %rax ## imm = 0x4042000000000000
	movq	%rax, 216(%rsp)
	movabsq	$4630122629401935872, %rax ## imm = 0x4041800000000000
	movq	%rax, 208(%rsp)
	movabsq	$4629981891913580544, %rax ## imm = 0x4041000000000000
	movq	%rax, 200(%rsp)
	movabsq	$4629841154425225216, %rax ## imm = 0x4040800000000000
	movq	%rax, 192(%rsp)
	movabsq	$4629700416936869888, %rax ## imm = 0x4040000000000000
	movq	%rax, 184(%rsp)
	movabsq	$4629418941960159232, %rax ## imm = 0x403F000000000000
	movq	%rax, 176(%rsp)
	movabsq	$4629137466983448576, %rax ## imm = 0x403E000000000000
	movq	%rax, 168(%rsp)
	movabsq	$4628855992006737920, %rax ## imm = 0x403D000000000000
	movq	%rax, 160(%rsp)
	movabsq	$4628574517030027264, %rax ## imm = 0x403C000000000000
	movq	%rax, 152(%rsp)
	movabsq	$4628293042053316608, %rax ## imm = 0x403B000000000000
	movq	%rax, 144(%rsp)
	movabsq	$4628011567076605952, %rax ## imm = 0x403A000000000000
	movq	%rax, 136(%rsp)
	movabsq	$4627730092099895296, %rax ## imm = 0x4039000000000000
	movq	%rax, 128(%rsp)
	movabsq	$4627448617123184640, %rax ## imm = 0x4038000000000000
	movq	%rax, 120(%rsp)
	movabsq	$4627167142146473984, %rax ## imm = 0x4037000000000000
	movq	%rax, 112(%rsp)
	movabsq	$4626885667169763328, %rax ## imm = 0x4036000000000000
	movq	%rax, 104(%rsp)
	movabsq	$4626604192193052672, %rax ## imm = 0x4035000000000000
	movq	%rax, 96(%rsp)
	movabsq	$4626322717216342016, %rax ## imm = 0x4034000000000000
	movq	%rax, 88(%rsp)
	movabsq	$4626041242239631360, %rax ## imm = 0x4033000000000000
	movq	%rax, 80(%rsp)
	movabsq	$4625759767262920704, %rax ## imm = 0x4032000000000000
	movq	%rax, 72(%rsp)
	movabsq	$4625478292286210048, %rax ## imm = 0x4031000000000000
	movq	%rax, 64(%rsp)
	movabsq	$4625196817309499392, %rax ## imm = 0x4030000000000000
	movq	%rax, 56(%rsp)
	movabsq	$4624633867356078080, %rax ## imm = 0x402E000000000000
	movq	%rax, 48(%rsp)
	movabsq	$4624070917402656768, %rax ## imm = 0x402C000000000000
	movq	%rax, 40(%rsp)
	movabsq	$4623507967449235456, %rax ## imm = 0x402A000000000000
	movq	%rax, 32(%rsp)
	movabsq	$4622945017495814144, %rax ## imm = 0x4028000000000000
	movq	%rax, 24(%rsp)
	movabsq	$4622382067542392832, %rax ## imm = 0x4026000000000000
	movq	%rax, 16(%rsp)
	movabsq	$4621819117588971520, %rax ## imm = 0x4024000000000000
	movq	%rax, 8(%rsp)
	movabsq	$4621256167635550208, %rax ## imm = 0x4022000000000000
	movq	%rax, (%rsp)
	movsd	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI1_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	LCPI1_2(%rip), %xmm2    ## xmm2 = mem[0],zero
	movsd	LCPI1_3(%rip), %xmm3    ## xmm3 = mem[0],zero
	movsd	LCPI1_4(%rip), %xmm4    ## xmm4 = mem[0],zero
	movsd	LCPI1_5(%rip), %xmm5    ## xmm5 = mem[0],zero
	movsd	LCPI1_6(%rip), %xmm6    ## xmm6 = mem[0],zero
	movsd	LCPI1_7(%rip), %xmm7    ## xmm7 = mem[0],zero
	callq	_alotofarguments
	addq	$456, %rsp              ## imm = 0x1C8
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ## -- Begin function unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	.p2align	4, 0x90
_unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa: ## @unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	.cfi_startproc
## %bb.0:                               ## %entry
	xorps	%xmm0, %xmm0
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function triviallyoptimizabledeepnesting
LCPI3_0:
	.quad	4631107791820423168     ## double 42
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_triviallyoptimizabledeepnesting
	.p2align	4, 0x90
_triviallyoptimizabledeepnesting:       ## @triviallyoptimizabledeepnesting
	.cfi_startproc
## %bb.0:                               ## %entry
	movsd	LCPI3_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function iterativefactorial
LCPI4_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_iterativefactorial
	.p2align	4, 0x90
_iterativefactorial:                    ## @iterativefactorial
	.cfi_startproc
## %bb.0:                               ## %entry
	movsd	LCPI4_0(%rip), %xmm2    ## xmm2 = mem[0],zero
	movapd	%xmm2, %xmm1
	movapd	%xmm2, %xmm3
	ucomisd	%xmm3, %xmm0
	jb	LBB4_3
	.p2align	4, 0x90
LBB4_2:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	mulsd	%xmm3, %xmm1
	addsd	%xmm2, %xmm3
	ucomisd	%xmm3, %xmm0
	jae	LBB4_2
LBB4_3:                                 ## %post
	movapd	%xmm1, %xmm0
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function recursivefibonacci
LCPI5_0:
	.quad	4607182418800017408     ## double 1
LCPI5_1:
	.quad	4611686018427387904     ## double 2
LCPI5_2:
	.quad	-4616189618054758400    ## double -1
LCPI5_3:
	.quad	-4611686018427387904    ## double -2
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_recursivefibonacci
	.p2align	4, 0x90
_recursivefibonacci:                    ## @recursivefibonacci
	.cfi_startproc
## %bb.0:                               ## %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	ucomisd	LCPI5_0(%rip), %xmm0
	jne	LBB5_1
	jnp	LBB5_2
LBB5_1:                                 ## %entry
	movapd	%xmm0, %xmm1
	ucomisd	LCPI5_1(%rip), %xmm0
	jne	LBB5_3
	jnp	LBB5_2
LBB5_3:                                 ## %else
	movsd	LCPI5_2(%rip), %xmm0    ## xmm0 = mem[0],zero
	addsd	%xmm1, %xmm0
	movsd	%xmm1, 8(%rsp)          ## 8-byte Spill
	callq	_recursivefibonacci
	movsd	%xmm0, 16(%rsp)         ## 8-byte Spill
	movsd	8(%rsp), %xmm0          ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	addsd	LCPI5_3(%rip), %xmm0
	callq	_recursivefibonacci
	addsd	16(%rsp), %xmm0         ## 8-byte Folded Reload
	addq	$24, %rsp
	retq
LBB5_2:                                 ## %then
	movsd	LCPI5_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	addq	$24, %rsp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function calculatepi
LCPI6_0:
	.quad	-4616189618054758400    ## double -1
LCPI6_1:
	.quad	4607182418800017408     ## double 1
LCPI6_2:
	.quad	4616189618054758400     ## double 4
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_calculatepi
	.p2align	4, 0x90
_calculatepi:                           ## @calculatepi
	.cfi_startproc
## %bb.0:                               ## %entry
	movsd	LCPI6_0(%rip), %xmm4    ## xmm4 = mem[0],zero
	movsd	LCPI6_1(%rip), %xmm2    ## xmm2 = mem[0],zero
	movapd	%xmm2, %xmm3
	movapd	%xmm2, %xmm1
	ucomisd	%xmm3, %xmm0
	jb	LBB6_3
	.p2align	4, 0x90
LBB6_2:                                 ## %loop
                                        ## =>This Inner Loop Header: Depth=1
	movapd	%xmm3, %xmm5
	addsd	%xmm3, %xmm5
	addsd	%xmm2, %xmm5
	xorpd	%xmm6, %xmm6
	subsd	%xmm4, %xmm6
	divsd	%xmm5, %xmm4
	addsd	%xmm4, %xmm1
	addsd	%xmm2, %xmm3
	movapd	%xmm6, %xmm4
	ucomisd	%xmm3, %xmm0
	jae	LBB6_2
LBB6_3:                                 ## %post
	mulsd	LCPI6_2(%rip), %xmm1
	movapd	%xmm1, %xmm0
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_abs                    ## -- Begin function abs
	.p2align	4, 0x90
_abs:                                   ## @abs
	.cfi_startproc
## %bb.0:                               ## %entry
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	LBB7_2
## %bb.1:                               ## %then
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
LBB7_2:                                 ## %else
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function eq
LCPI8_0:
	.quad	4562254508917369340     ## double 0.001
	.section	__TEXT,__literal16,16byte_literals
	.p2align	3
LCPI8_1:
	.quad	-4616189618054758400    ## double -1
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_eq
	.p2align	4, 0x90
_eq:                                    ## @eq
	.cfi_startproc
## %bb.0:                               ## %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	subsd	%xmm1, %xmm0
	callq	_abs
	movsd	LCPI8_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	xorl	%eax, %eax
	ucomisd	%xmm0, %xmm1
	seta	%al
	leaq	LCPI8_1(%rip), %rcx
	movsd	(%rcx,%rax,8), %xmm0    ## xmm0 = mem[0],zero
	popq	%rax
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function euclideangcd
LCPI9_0:
	.quad	0                       ## double 0
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_euclideangcd
	.p2align	4, 0x90
_euclideangcd:                          ## @euclideangcd
	.cfi_startproc
## %bb.0:                               ## %entry
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	jmp	LBB9_1
	.p2align	4, 0x90
LBB9_4:                                 ## %loop
                                        ##   in Loop: Header=BB9_1 Depth=1
	movapd	%xmm4, %xmm2
	cmpltsd	%xmm3, %xmm2
	movapd	%xmm2, %xmm3
	andnpd	%xmm1, %xmm3
	andpd	%xmm4, %xmm2
	orpd	%xmm3, %xmm2
	movapd	%xmm2, %xmm1
LBB9_1:                                 ## %cond
                                        ## =>This Inner Loop Header: Depth=1
	movaps	%xmm1, 16(%rsp)         ## 16-byte Spill
	movsd	%xmm0, 8(%rsp)          ## 8-byte Spill
	callq	_eq
	xorps	%xmm1, %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	LBB9_5
## %bb.2:                               ## %loop
                                        ##   in Loop: Header=BB9_1 Depth=1
	movsd	8(%rsp), %xmm3          ## 8-byte Reload
                                        ## xmm3 = mem[0],zero
	movapd	16(%rsp), %xmm0         ## 16-byte Reload
	ucomisd	%xmm0, %xmm3
	movapd	%xmm0, %xmm1
	subsd	%xmm3, %xmm1
	movapd	%xmm0, %xmm4
	movapd	%xmm3, %xmm0
	jbe	LBB9_4
## %bb.3:                               ##   in Loop: Header=BB9_1 Depth=1
	subsd	%xmm4, %xmm0
	jmp	LBB9_4
LBB9_5:                                 ## %post
	movsd	8(%rsp), %xmm0          ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	addq	$40, %rsp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function modulo
LCPI10_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_modulo
	.p2align	4, 0x90
_modulo:                                ## @modulo
	.cfi_startproc
## %bb.0:                               ## %entry
	xorpd	%xmm3, %xmm3
	movsd	LCPI10_0(%rip), %xmm4   ## xmm4 = mem[0],zero
	jmp	LBB10_1
	.p2align	4, 0x90
LBB10_2:                                ## %loop
                                        ##   in Loop: Header=BB10_1 Depth=1
	addsd	%xmm4, %xmm3
LBB10_1:                                ## %cond
                                        ## =>This Inner Loop Header: Depth=1
	movapd	%xmm1, %xmm5
	mulsd	%xmm3, %xmm5
	movapd	%xmm0, %xmm2
	subsd	%xmm5, %xmm2
	ucomisd	%xmm1, %xmm2
	jae	LBB10_2
## %bb.3:                               ## %post
	movapd	%xmm2, %xmm0
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function iseven
LCPI11_0:
	.quad	4611686018427387904     ## double 2
	.section	__TEXT,__literal16,16byte_literals
	.p2align	3
LCPI11_1:
	.quad	-4616189618054758400    ## double -1
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_iseven
	.p2align	4, 0x90
_iseven:                                ## @iseven
	.cfi_startproc
## %bb.0:                               ## %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movsd	LCPI11_0(%rip), %xmm1   ## xmm1 = mem[0],zero
	callq	_modulo
	xorpd	%xmm1, %xmm1
	cmpeqsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	andl	$1, %eax
	leaq	LCPI11_1(%rip), %rcx
	movsd	(%rcx,%rax,8), %xmm0    ## xmm0 = mem[0],zero
	popq	%rax
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function isodd
LCPI12_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_isodd
	.p2align	4, 0x90
_isodd:                                 ## @isodd
	.cfi_startproc
## %bb.0:                               ## %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	_iseven
	movsd	LCPI12_0(%rip), %xmm1   ## xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	popq	%rax
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function exponentiationbysquaring
LCPI13_0:
	.quad	4607182418800017408     ## double 1
LCPI13_1:
	.quad	-4616189618054758400    ## double -1
LCPI13_2:
	.quad	4602678819172646912     ## double 0.5
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_exponentiationbysquaring
	.p2align	4, 0x90
_exponentiationbysquaring:              ## @exponentiationbysquaring
	.cfi_startproc
## %bb.0:                               ## %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movapd	%xmm1, %xmm3
	movapd	%xmm0, %xmm2
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm3, %xmm1
	jbe	LBB13_3
## %bb.1:                               ## %then
	movsd	LCPI13_0(%rip), %xmm0   ## xmm0 = mem[0],zero
	divsd	%xmm2, %xmm0
	subsd	%xmm3, %xmm1
LBB13_2:                                ## %then
	callq	_exponentiationbysquaring
	addq	$24, %rsp
	retq
LBB13_3:                                ## %else
	ucomisd	%xmm1, %xmm3
	jne	LBB13_6
	jp	LBB13_6
## %bb.4:
	movsd	LCPI13_0(%rip), %xmm2   ## xmm2 = mem[0],zero
	jmp	LBB13_5
LBB13_6:                                ## %else8
	ucomisd	LCPI13_0(%rip), %xmm3
	jne	LBB13_7
	jp	LBB13_7
LBB13_5:                                ## %then7
	movapd	%xmm2, %xmm0
	addq	$24, %rsp
	retq
LBB13_7:                                ## %else12
	movsd	%xmm3, 8(%rsp)          ## 8-byte Spill
	movapd	%xmm3, %xmm0
	movsd	%xmm2, 16(%rsp)         ## 8-byte Spill
	callq	_iseven
	movsd	16(%rsp), %xmm2         ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	ucomisd	LCPI13_0(%rip), %xmm0
	movapd	%xmm2, %xmm0
	mulsd	%xmm2, %xmm0
	jbe	LBB13_9
## %bb.8:                               ## %then16
	movsd	8(%rsp), %xmm1          ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	LCPI13_2(%rip), %xmm1
	jmp	LBB13_2
LBB13_9:                                ## %else17
	movsd	8(%rsp), %xmm1          ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	addsd	LCPI13_1(%rip), %xmm1
	mulsd	LCPI13_2(%rip), %xmm1
	callq	_exponentiationbysquaring
	mulsd	16(%rsp), %xmm0         ## 8-byte Folded Reload
	addq	$24, %rsp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function etothepower
LCPI14_0:
	.quad	4613303445314885481     ## double 2.7182818284590451
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_etothepower
	.p2align	4, 0x90
_etothepower:                           ## @etothepower
	.cfi_startproc
## %bb.0:                               ## %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movaps	%xmm0, %xmm1
	movsd	LCPI14_0(%rip), %xmm0   ## xmm0 = mem[0],zero
	callq	_exponentiationbysquaring
	popq	%rax
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function xpln_main
LCPI15_0:
	.quad	4626322717216342016     ## double 20
LCPI15_1:
	.quad	4629137466983448576     ## double 30
LCPI15_2:
	.quad	4726483295884279808     ## double 1.0E+8
LCPI15_3:
	.quad	4677173480733540352     ## double 50500
LCPI15_4:
	.quad	4681670139693760512     ## double 100899
LCPI15_5:
	.quad	4636737291354636288     ## double 100
LCPI15_6:
	.quad	4619567317775286272     ## double 7
LCPI15_7:
	.quad	4624633867356078080     ## double 15
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_xpln_main
	.p2align	4, 0x90
_xpln_main:                             ## @xpln_main
	.cfi_startproc
## %bb.0:                               ## %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	callq	_testalotofarguments
	leaq	_ofmt(%rip), %rbx
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	callq	_unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	callq	_triviallyoptimizabledeepnesting
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_0(%rip), %xmm0   ## xmm0 = mem[0],zero
	callq	_iterativefactorial
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_1(%rip), %xmm0   ## xmm0 = mem[0],zero
	callq	_recursivefibonacci
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_2(%rip), %xmm0   ## xmm0 = mem[0],zero
	callq	_calculatepi
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_3(%rip), %xmm0   ## xmm0 = mem[0],zero
	movsd	LCPI15_4(%rip), %xmm1   ## xmm1 = mem[0],zero
	callq	_euclideangcd
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_5(%rip), %xmm0   ## xmm0 = mem[0],zero
	movsd	LCPI15_6(%rip), %xmm1   ## xmm1 = mem[0],zero
	callq	_modulo
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	movsd	LCPI15_7(%rip), %xmm0   ## xmm0 = mem[0],zero
	callq	_etothepower
	movb	$1, %al
	movq	%rbx, %rdi
	callq	_printf
	xorps	%xmm0, %xmm0
	popq	%rbx
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
_ifmt:                                  ## @ifmt
	.asciz	"%lf"

_ofmt:                                  ## @ofmt
	.asciz	"%lf\n"


.subsections_via_symbols
