@ commands

    .macro loadspritegfx tag:req
	.byte 0x0
	.2byte \tag
	.endm

    .macro monbg battler:req
	.byte 0xa
	.byte \battler
	.endm

    .macro playsewithpan se:req, pan:req
	.byte 0x19
	.2byte \se
	.byte \pan
	.endm

    .macro waitplaysewithpan se:req, pan:req, wait:req
	.byte 0x1d
	.2byte \se
	.byte \pan
	.byte \wait
	.endm

    .macro createsprite template:req, anim_battler:req, subpriority_offset:req, argv:vararg
	.byte 0x02
	.4byte \template
	.if \anim_battler == ANIM_TARGET
	.byte 0x80 | (\subpriority_offset & 0x7F)
	.else
	.byte (\subpriority_offset & 0x7F)
	.endif
	.byte (.Lsprite_\@_2 - .Lsprite_\@_1) / 2
.Lsprite_\@_1:
	.2byte \argv
.Lsprite_\@_2:
	.endm

    .macro delay param0:req
	.byte 0x4
	.byte \param0
	.endm

    .macro waitforvisualfinish
	.byte 0x5
	.endm

    .macro clearmonbg battler:req
	.byte 0xb
	.byte \battler
	.endm

    .macro createvisualtask addr:req, priority:req, argv:vararg
	.byte 0x03
	.4byte \addr
	.byte \priority
	.byte (.Lcreatetask_\@_2 - .Lcreatetask_\@_1) / 2
.Lcreatetask_\@_1:
	.2byte \argv
.Lcreatetask_\@_2:
	.endm