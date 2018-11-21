// DO NOT EDIT THIS FILE!!!
// This file was generated by 'ftops.pl'.
// In order to change the information in this
// file you must edit '$OMR/compiler/p/codegen/PPCOps.ops'
// and then run 'perl $OMR/tools/compiler/p/ftops.pl'.

#include "codegen/InstOpCode.hpp"  // for InstOpCode, etc

const TR_PPCOpCodeBinaryEntry OMR::Power::InstOpCode::binaryEncodings[PPCNumOpCodes] =
   {
   0x00000000,  // bad
   0x7c000214,  // add
   0x7c000215,  // add_r
   0x7c000014,  // addc
   0x7c000015,  // addc_r
   0x7c000414,  // addco
   0x7c000415,  // addco_r
   0x7c000114,  // adde
   0x7c000115,  // adde_r
   0x7c000514,  // addeo
   0x7c000515,  // addeo_r
   0x38000000,  // addi
   0x30000000,  // addic
   0x34000000,  // addic_r
   0x38000000,  // addi2
   0x34000000,  // addi2_r
   0x3c000000,  // addis
   0x7c0001d4,  // addme
   0x7c0001d5,  // addme_r
   0x7c0005d4,  // addmeo
   0x7c0005d5,  // addmeo_r
   0x7c000614,  // addo
   0x7c000615,  // addo_r
   0x4c000004,  // addpcis
   0x7c000194,  // addze
   0x7c000195,  // addze_r
   0x7c000594,  // addzeo
   0x7c000595,  // addzeo_r
   0x7c000038,  // and
   0x7c000039,  // and_r
   0x7c000078,  // andc
   0x7c000079,  // andc_r
   0x7c000154,  // addex
   0x7c000155,  // addex_r
   0x70000000,  // andi_r
   0x74000000,  // andis_r
   0x48000000,  // b
   0x48000002,  // ba
   0x4e800420,  // bctr
   0x4e800421,  // bctrl
   0x42000000,  // bdnz
   0x42400000,  // bdz
   0x41820000,  // beq
   0x41820001,  // beql
   0x4c800020,  // bfctr
   0x40800000,  // bge
   0x40800001,  // bgel
   0x41810000,  // bgt
   0x41810001,  // bgtl
   0x48000001,  // bl
   0x40810000,  // ble
   0x40810001,  // blel
   0x41800000,  // blt
   0x41800001,  // bltl
   0x48000003,  // bla
   0x00008067,  // blr
   0x4e800021,  // blrl
   0x40820000,  // bne
   0x40820001,  // bnel
   0x40830000,  // bnun
   0x4d800020,  // btctr
   0x41830000,  // bun
   0x4d820020,  // beqlr
   0x4c800020,  // bgelr
   0x4d810020,  // bgtlr
   0x4c810020,  // blelr
   0x4d800020,  // bltlr
   0x4c820020,  // bnelr
   0x7c000000,  // cmp4
   0x7c200000,  // cmp8
   0x2c000000,  // cmpi4
   0x2c200000,  // cmpi8
   0x7c000040,  // cmpl4
   0x7c200040,  // cmpl8
   0x28000000,  // cmpli4
   0x28200000,  // cmpli8
   0x7c000180,  // cmprb
   0x7c0001c0,  // cmpeqb
   0x7c000074,  // cntlzd
   0x7c000075,  // cntlzd_r
   0x7c000034,  // cntlzw
   0x7c000035,  // cntlzw_r
   0x4c000202,  // crand
   0x4c000102,  // crandc
   0x4c000242,  // creqv
   0x4c0001c2,  // crnand
   0x4c000042,  // crnor
   0x4c000382,  // cror
   0x4c000342,  // crorc
   0x4c000182,  // crxor
   0xec000004,  // dadd
   0xec000005,  // dadd_r
   0x7c0005e6,  // darn
   0x7c00022c,  // dcbt
   0x7c0001ec,  // dcbtst
   0x7e0001ec,  // dcbtstt
   0x7e00022c,  // dcbtt
   0x7c0007ec,  // dcbz
   0xec000644,  // dcffix
   0xec000645,  // dcffix_r
   0xfc000644,  // dcffixq
   0xfc000645,  // dcffixq_r
   0xec000504,  // dcmpu
   0xec000244,  // dctfix
   0xec000245,  // dctfix_r
   0xec000284,  // ddedpd
   0xec000285,  // ddedpd_r
   0xec000444,  // ddiv
   0xec000445,  // ddiv_r
   0xec000684,  // denbcdu
   0xec000685,  // denbcdu_r
   0x7c0003d2,  // divd
   0x7c0003d3,  // divd_r
   0xec0006c4,  // diex
   0xec0006c5,  // diex_r
   0x7c0007d2,  // divdo
   0x7c0007d3,  // divdo_r
   0x7c000392,  // divdu
   0x7c000393,  // divdu_r
   0x7c000792,  // divduo
   0x7c000793,  // divduo_r
   0x7c0003d6,  // divw
   0x7c0003d7,  // divw_r
   0x7c0007d6,  // divwo
   0x7c0007d7,  // divwo_r
   0x7c000396,  // divwu
   0x7c000397,  // divwu_r
   0x7c000796,  // divwuo
   0x7c000797,  // divwuo_r
   0xec000044,  // dmul
   0xec000045,  // dmul_r
   0xec000006,  // dqua
   0xec000007,  // dqua_r
   0xec000046,  // drrnd
   0xec000047,  // drrnd_r
   0xfc000604,  // drdpq
   0xfc000605,  // drdpq_r
   0xec000404,  // dsub
   0xec000405,  // dsub_r
   0xec000184,  // dtstdc
   0xec0001c4,  // dtstdg
   0xec0002c4,  // dxex
   0xec0002c5,  // dxex_r
   0x7c0006ac,  // eieio
   0x7c000238,  // eqv
   0x7c000239,  // eqv_r
   0x7c000774,  // extsb
   0x7c000775,  // extsb_r
   0x7c000734,  // extsh
   0x7c000735,  // extsh_r
   0x7c0007b4,  // extsw
   0x7c0007b5,  // extsw_r
   0x7c0006f4,  // extswsli
   0x7c0006f5,  // extswsli_r
   0xfc000210,  // fabs
   0xfc00002a,  // fadd
   0xec00002a,  // fadds
   0xfc00069c,  // fcfid
   0xfc00079c,  // fcfidu
   0xec00069c,  // fcfids
   0xec00079c,  // fcfidus
   0xfc000040,  // fcmpo
   0xfc000000,  // fcmpu
   0xfc000010,  // fcpsgn
   0xfc00065c,  // fctid
   0xfc00065e,  // fctidz
   0xfc00001c,  // fctiw
   0xfc00001e,  // fctiwz
   0xfc000024,  // fdiv
   0xec000024,  // fdivs
   0xfc00003a,  // fmadd
   0xec00003a,  // fmadds
   0xfc000090,  // fmr
   0xfc000038,  // fmsub
   0xec000038,  // fmsubs
   0xfc000032,  // fmul
   0xec000032,  // fmuls
   0xfc000110,  // fnabs
   0xfc000050,  // fneg
   0xfc00003e,  // fnmadd
   0xec00003e,  // fnmadds
   0xfc00003c,  // fnmsub
   0xec00003c,  // fnmsubs
   0xfc000030,  // fres
   0xfc0003d0,  // frim
   0xfc000310,  // frin
   0xfc000390,  // frip
   0xfc000018,  // frsp
   0xfc000034,  // frsqrte
   0xfc00002e,  // fsel
   0xfc00002c,  // fsqrt
   0xec00002c,  // fsqrts
   0xfc000028,  // fsub
   0xec000028,  // fsubs
   0x4c00012c,  // isync
   0x88000000,  // lbz
   0x8c000000,  // lbzu
   0x7c0000ee,  // lbzux
   0x7c0000ae,  // lbzx
   0xe8000000,  // ld
   0x7c0000a8,  // ldarx
   0x7c00026a,  // ldmx
   0x7c000268,  // lwzmx
   0xe8000001,  // ldu
   0x7c00006c,  // ldux
   0x7c00002a,  // ldx
   0xc8000000,  // lfd
   0xe4000000,  // lfdp
   0xcc000000,  // lfdu
   0x7c0004ee,  // lfdux
   0x7c0004ae,  // lfdx
   0x7c00062e,  // lfdpx
   0x7c0006ae,  // lfiwax
   0x7c0006ee,  // lfiwzx
   0xc0000000,  // lfs
   0xc4000000,  // lfsu
   0x7c00046e,  // lfsux
   0x7c00042e,  // lfsx
   0xa8000000,  // lha
   0xac000000,  // lhau
   0x7c0002ee,  // lhaux
   0x7c0002ae,  // lhax
   0x7c00062c,  // lhbrx
   0xa0000000,  // lhz
   0xa4000000,  // lhzu
   0x7c00026e,  // lhzux
   0x7c00022e,  // lhzx
   0x00000013,  // li -- PATCHED
   0x3c000000,  // lis
   0xb8000000,  // lmw
   0x7c0004aa,  // lswi
   0x7c00042a,  // lswx
   0xe8000002,  // lwa
   0x7c000028,  // lwarx
   0x7c0002ea,  // lwaux
   0x7c0002aa,  // lwax
   0x7c00042c,  // lwbrx
   0x7c000428,  // ldbrx
   0x80000000,  // lwz
   0x84000000,  // lwzu
   0x7c00006e,  // lwzux
   0x7c00002e,  // lwzx
   0x10000033,  // maddld
   0x4c000000,  // mcrf
   0xfc000080,  // mcrfs
   0x7c000400,  // mcrxr
   0x7c000026,  // mfcr
   0x7c100026,  // mfocrf
   0x7c0902a6,  // mfctr
   0x7c0004be,  // mffgpr
   0xfc00048e,  // mffs
   0x7c0802a6,  // mflr
   0x7c0000a6,  // mfmsr
   0x7c0002a6,  // mfspr
   0x7c0222a6,  // mftexasr
   0x7c0322a6,  // mftexasru
   0x7c0005be,  // mftgpr
   0x7c000212,  // modud
   0x7c000612,  // modsd
   0x7c000216,  // moduw
   0x7c000616,  // modsw
   0x60000000,  // mr
   0x7c000120,  // mtcrf
   0x7c0903a6,  // mtctr
   0xfc00008c,  // mtfsb0
   0xfc00004c,  // mtfsb1
   0xfe00058e,  // mtfsfl
   0xfe00058f,  // mtfsfl_r
   0xfc00058e,  // mtfsf
   0xfc00058f,  // mtfsf_r
   0xfc01058e,  // mtfsfw
   0xfc01058f,  // mtfsfw_r
   0xfc00010c,  // mtfsfi
   0xfc00010d,  // mtfsfi_r
   0x7c0803a6,  // mtlr
   0x7c000124,  // mtmsr
   0x7c0003a6,  // mtspr
   0x7c000066,  // mfvsrd
   0x7c0000e6,  // mfvsrwz
   0x7c000166,  // mtvsrd
   0x7c0001e6,  // mtvsrwz
   0x7c0001a6,  // mtvsrwa
   0x7c000092,  // mulhd
   0x7c000093,  // mulhd_r
   0x7c000012,  // mulhdu
   0x7c000013,  // mulhdu_r
   0x7c000096,  // mulhw
   0x7c000097,  // mulhw_r
   0x7c000016,  // mulhwu
   0x7c000017,  // mulhwu_r
   0x7c0001d2,  // mulld
   0x7c0001d3,  // mulld_r
   0x7c0005d2,  // mulldo
   0x7c0005d3,  // mulldo_r
   0x1c000000,  // mulli
   0x7c0001d6,  // mullw
   0x7c0001d7,  // mullw_r
   0x7c0005d6,  // mullwo
   0x7c0005d7,  // mullwo_r
   0x7c0003b8,  // nand
   0x7c0003b9,  // nand_r
   0x7c0000d0,  // neg
   0x7c0000d1,  // neg_r
   0x7c0004d0,  // nego
   0x7c0004d1,  // nego_r
   0x7c0000f8,  // nor
   0x7c0000f9,  // nor_r
   0x7c000378,  // or
   0x7c000379,  // or_r
   0x7c000338,  // orc
   0x7c000339,  // orc_r
   0x60000000,  // ori
   0x64000000,  // oris
   0x7c0003f4,  // popcntd
   0x7c0002f4,  // popcntw
   0x4c000064,  // rfi
   0x78000010,  // rldcl
   0x78000011,  // rldcl_r
   0x78000012,  // rldcr
   0x78000013,  // rldcr_r
   0x78000008,  // rldic
   0x78000009,  // rldic_r
   0x78000000,  // rldicl
   0x78000001,  // rldicl_r
   0x78000004,  // rldicr
   0x78000005,  // rldicr_r
   0x7800000c,  // rldimi
   0x7800000d,  // rldimi_r
   0x50000000,  // rlwimi
   0x50000001,  // rlwimi_r
   0x54000000,  // rlwinm
   0x54000001,  // rlwinm_r
   0x5c000000,  // rlwnm
   0x5c000001,  // rlwnm_r
   0x7c000100,  // setb
   0x7c000036,  // sld
   0x7c000037,  // sld_r
   0x7c000030,  // slw
   0x7c000031,  // slw_r
   0x7c000634,  // srad
   0x7c000635,  // srad_r
   0x7c000674,  // sradi
   0x7c000675,  // sradi_r
   0x7c000630,  // sraw
   0x7c000631,  // sraw_r
   0x7c000670,  // srawi
   0x7c000671,  // srawi_r
   0x7c000436,  // srd
   0x7c000437,  // srd_r
   0x7c000430,  // srw
   0x7c000431,  // srw_r
   0x98000000,  // stb
   0x9c000000,  // stbu
   0x7c0001ee,  // stbux
   0x7c0001ae,  // stbx
   0xf8000000,  // std
   0x7c0001ad,  // stdcx_r
   0xf8000001,  // stdu
   0x7c00016a,  // stdux
   0x7c00012a,  // stdx
   0xd8000000,  // stfd
   0xf4000000,  // stfdp
   0xdc000000,  // stfdu
   0x7c0005ee,  // stfdux
   0x7c0005ae,  // stfdx
   0x7c00072e,  // stfdpx
   0x7c0007ae,  // stfiwx
   0xd0000000,  // stfs
   0xd4000000,  // stfsu
   0x7c00056e,  // stfsux
   0x7c00052e,  // stfsx
   0xb0000000,  // sth
   0x7c00072c,  // sthbrx
   0xb4000000,  // sthu
   0x7c00036e,  // sthux
   0x7c00032e,  // sthx
   0xbc000000,  // stmw
   0x7c0005aa,  // stswi
   0x7c00052a,  // stswx
   0x90000000,  // stw
   0x7c00052c,  // stwbrx
   0x7c000528,  // stdbrx
   0x7c00012d,  // stwcx_r
   0x94000000,  // stwu
   0x7c00016e,  // stwux
   0x7c00012e,  // stwx
   0x7c000050,  // subf
   0x7c000051,  // subf_r
   0x7c000010,  // subfc
   0x7c000011,  // subfc_r
   0x7c000410,  // subfco
   0x7c000411,  // subfco_r
   0x7c000110,  // subfe
   0x7c000111,  // subfe_r
   0x7c000510,  // subfeo
   0x7c000511,  // subfeo_r
   0x20000000,  // subfic
   0x7c0001d0,  // subfme
   0x7c0001d1,  // subfme_r
   0x7c0005d0,  // subfmeo
   0x7c0005d1,  // subfmeo_r
   0x7c000190,  // subfze
   0x7c000191,  // subfze_r
   0x7c000590,  // subfzeo
   0x7c000591,  // subfzeo_r
   0x7c0004ac,  // sync
   0x7c00071d,  // tabort_r
   0x7c80065d,  // tabortdeq_r
   0x7c8006dd,  // tabortdeqi_r
   0x7d80065d,  // tabortdge_r
   0x7d8006dd,  // tabortdgei_r
   0x7d00065d,  // tabortdgt_r
   0x7d0006dd,  // tabortdgti_r
   0x7e80065d,  // tabortdle_r
   0x7e8006dd,  // tabortdlei_r
   0x7ca0065d,  // tabortdlge_r
   0x7ca006dd,  // tabortdlgei_r
   0x7c20065d,  // tabortdlgt_r
   0x7c2006dd,  // tabortdlgti_r
   0x7cc0065d,  // tabortdlle_r
   0x7cc006dd,  // tabortdllei_r
   0x7c40065d,  // tabortdllt_r
   0x7c4006dd,  // tabortdllti_r
   0x7e00065d,  // tabortdlt_r
   0x7e0006dd,  // tabortdlti_r
   0x7f00065d,  // tabortdneq_r
   0x7f0006dd,  // tabortdneqi_r
   0x7c80065d,  // tabortweq_r
   0x7c8006dd,  // tabortweqi_r
   0x7d80065d,  // tabortwge_r
   0x7d8006dd,  // tabortwgei_r
   0x7d00065d,  // tabortwgt_r
   0x7d0006dd,  // tabortwgti_r
   0x7e80065d,  // tabortwle_r
   0x7e8006dd,  // tabortwlei_r
   0x7ca0065d,  // tabortwlge_r
   0x7ca006dd,  // tabortwlgei_r
   0x7c20065d,  // tabortwlgt_r
   0x7c2006dd,  // tabortwlgti_r
   0x7cc0065d,  // tabortwlle_r
   0x7cc006dd,  // tabortwllei_r
   0x7c40065d,  // tabortwllt_r
   0x7c4006dd,  // tabortwllti_r
   0x7e00065d,  // tabortwlt_r
   0x7e0006dd,  // tabortwlti_r
   0x7f00065d,  // tabortwneq_r
   0x7f0006dd,  // tabortwneqi_r
   0x7c00051d,  // tbegin_r
   0x7c20051d,  // tbeginro_r
   0x7c00055d,  // tend_r
   0x7e00055d,  // tendall_r
   0x7c800088,  // tdeq
   0x08800000,  // tdeqi
   0x7d800088,  // tdge
   0x09800000,  // tdgei
   0x7d000088,  // tdgt
   0x09000000,  // tdgti
   0x7e800088,  // tdle
   0x0a800000,  // tdlei
   0x7ca00088,  // tdlge
   0x08a00000,  // tdlgei
   0x7c200088,  // tdlgt
   0x08200000,  // tdlgti
   0x7cc00088,  // tdlle
   0x08c00000,  // tdllei
   0x7c400088,  // tdllt
   0x08400000,  // tdllti
   0x7e000088,  // tdlt
   0x0a000000,  // tdlti
   0x7f000088,  // tdneq
   0x0b000000,  // tdneqi
   0x7fe00008,  // trap
   0x7c800008,  // tweq
   0x0c800000,  // tweqi
   0x7d800008,  // twge
   0x0d800000,  // twgei
   0x7d000008,  // twgt
   0x0d000000,  // twgti
   0x7e800008,  // twle
   0x0e800000,  // twlei
   0x7ca00008,  // twlge
   0x0ca00000,  // twlgei
   0x7c200008,  // twlgt
   0x0c200000,  // twlgti
   0x7cc00008,  // twlle
   0x0cc00000,  // twllei
   0x7c400008,  // twllt
   0x0c400000,  // twllti
   0x7e000008,  // twlt
   0x0e000000,  // twlti
   0x7f000008,  // twneq
   0x0f000000,  // twneqi
   0x7c000278,  // xor
   0x7c000279,  // xor_r
   0x68000000,  // xori
   0x6c000000,  // xoris
   0x60000000,  // nop
   0x60000000,  // genop
   0x00000000,  // fence
   0x00000000,  // shdfence
   0x00000000,  // ret
   0x00000000,  // wrtbar
   0x00000000,  // proc
   0x00000000,  // dd
   0x00000000,  // assocreg
   0x00000000,  // vgdnop
   0x00000000,  // depend
   0x7c000038,  // probenop
   0x00000000,  // iflong
   0x00000000,  // setblong
   0x00000000,  // setbool
   0x00000000,  // setbflt
   0x00000000,  // lcmp
   0x00000000,  // flcmpl
   0x00000000,  // flcmpg
   0x00000000,  // idiv
   0x00000000,  // ldiv
   0x00000000,  // irem
   0x00000000,  // lrem
   0x00000000,  // cdnan
   0x00000000,  // cfnan
   0x00000000,  // d2i
   0x00000000,  // d2l
   0x00000000,  // ifx
   0x00000000,  // setbx
   0x00000000,  // iternary
   0x7c00000c,  // lvsl
   0x7c00004c,  // lvsr
   0x7c0000ce,  // lvx
   0x7c00000e,  // lvebx
   0x7c00004e,  // lvehx
   0x7c00008e,  // lvewx
   0x7c0001ce,  // stvx
   0x7c00010e,  // stvebx
   0x7c00014e,  // stvehx
   0x7c00018e,  // stvewx
   0x10000404,  // vand
   0x10000444,  // vandc
   0x10000484,  // vor
   0x100004c4,  // vxor
   0x10000504,  // vnor
   0x1000002b,  // vperm
   0x1000002a,  // vsel
   0x10000788,  // vsumsws
   0x10000688,  // vsum2sws
   0x10000708,  // vsum4sbs
   0x10000648,  // vsum4shs
   0x10000608,  // vsum4ubs
   0x1000020c,  // vspltb
   0x1000024c,  // vsplth
   0x1000028c,  // vspltw
   0x1000030c,  // vspltisb
   0x1000034c,  // vspltish
   0x1000038c,  // vspltisw
   0x100001c4,  // vsl
   0x10000104,  // vslb
   0x1000002c,  // vsldoi
   0x10000144,  // vslh
   0x1000040c,  // vslo
   0x10000184,  // vslw
   0x100002c4,  // vsr
   0x10000304,  // vsrab
   0x10000344,  // vsrah
   0x10000384,  // vsraw
   0x10000204,  // vsrb
   0x10000244,  // vsrh
   0x1000044c,  // vsro
   0x10000284,  // vsrw
   0x10000004,  // vrlb
   0x10000044,  // vrlh
   0x10000084,  // vrlw
   0x10000300,  // vaddsbs
   0x10000340,  // vaddshs
   0x10000380,  // vaddsws
   0x10000000,  // vaddubm
   0x10000200,  // vaddubs
   0x100000c0,  // vaddudm
   0x10000040,  // vadduhm
   0x10000240,  // vadduhs
   0x10000080,  // vadduwm
   0x10000280,  // vadduws
   0x10000700,  // vsubsbs
   0x10000740,  // vsubshs
   0x10000780,  // vsubsws
   0x10000400,  // vsububm
   0x10000600,  // vsububs
   0x100004c0,  // vsubudm
   0x10000440,  // vsubuhm
   0x10000640,  // vsubuhs
   0x10000480,  // vsubuwm
   0x10000680,  // vsubuws
   0x10000348,  // vmulesh
   0x10000148,  // vmulosh
   0x10000048,  // vmulouh
   0x10000089,  // vmuluwm
   0x10000302,  // vminsb
   0x10000342,  // vminsh
   0x10000382,  // vminsw
   0x10000202,  // vminub
   0x10000242,  // vminuh
   0x10000282,  // vminuw
   0x10000002,  // vmaxsb
   0x10000042,  // vmaxsh
   0x10000082,  // vmaxsw
   0x10000102,  // vmaxub
   0x10000142,  // vmaxuh
   0x10000182,  // vmaxuw
   0x10000026,  // vmsumuhm
   0x10000006,  // vcmpequb
   0x10000406,  // vcmpeubr
   0x10000046,  // vcmpequh
   0x10000446,  // vcmpeuhr
   0x10000086,  // vcmpequw
   0x10000486,  // vcmpeuwr
   0x10000306,  // vcmpgtsb
   0x10000706,  // vcmpgsbr
   0x10000346,  // vcmpgtsh
   0x10000746,  // vcmpgshr
   0x10000386,  // vcmpgtsw
   0x10000786,  // vcmpgswr
   0x10000206,  // vcmpgtub
   0x10000606,  // vcmpgubr
   0x10000246,  // vcmpgtuh
   0x10000646,  // vcmpguhr
   0x10000286,  // vcmpgtuw
   0x10000686,  // vcmpguwr
   0x1000020e,  // vupkhsb
   0x1000024e,  // vupkhsh
   0x1000028e,  // vupklsb
   0x100002ce,  // vupklsh
   0x1000000e,  // vpkuhum
   0x1000004e,  // vpkuwum
   0x1000000c,  // vmrghb
   0x1000004c,  // vmrghh
   0x1000008c,  // vmrghw
   0x1000010c,  // vmrglb
   0x1000014c,  // vmrglh
   0x1000018c,  // vmrglw
   0x7c000498,  // lxsdx
   0x7c0004d8,  // lxsdux
   0x7c000598,  // stxsdx
   0x7c0005d8,  // stxsdux
   0x7c000698,  // lxvd2x
   0x7c0006d8,  // lxvd2ux
   0x7c000298,  // lxvdsx
   0x7c000618,  // lxvw4x
   0x7c000658,  // lxvw4ux
   0x7c000798,  // stxvd2x
   0x7c0007d8,  // stxvd2ux
   0x7c000718,  // stxvw4x
   0x7c000758,  // stxvw4ux
   0xf0000564,  // xsabsdp
   0xf0000100,  // xsadddp
   0xf0000158,  // xscmpodp
   0xf0000118,  // xscmpudp
   0xf0000580,  // xscpsgndp
   0xf0000560,  // xscvdpsxds
   0xf0000160,  // xscvdpsxws
   0xf00001c0,  // xsdivdp
   0xf0000108,  // xsmaddadp
   0xf0000148,  // xsmaddmdp
   0xf0000188,  // xsmsubadp
   0xf00001c8,  // xsmsubmdp
   0xf0000180,  // xsmuldp
   0xf00005a4,  // xsnabsdp
   0xf00005e4,  // xsnegdp
   0xf0000508,  // xsnmaddadp
   0xf0000548,  // xsnmaddmdp
   0xf0000588,  // xsnmsubadp
   0xf00005c8,  // xsnmsubmdp
   0xf00001ac,  // xsrdpic
   0xf0000168,  // xsredp
   0xf0000128,  // xsrsqrtedp
   0xf0000490,  // xxlor
   0xf0000510,  // xxlnor
   0xf0000030,  // xxsel
   0xf0000010,  // xxsldwi
   0xf0000290,  // xxspltw
   0xf0000050,  // xxpermdi
   0xf000012c,  // xssqrtdp
   0xf0000140,  // xssubdp
   0xf00005e0,  // xscvsxddp
   0xf0000424,  // xscvdpsp
   0xf0000300,  // xvadddp
   0xf0000740,  // xvmindp
   0xf0000700,  // xvmaxdp
   0xf0000318,  // xvcmpeqdp
   0xf0000718,  // xvcmpeqdp_r
   0xf0000398,  // xvcmpgedp
   0xf0000798,  // xvcmpgedp_r
   0xf0000358,  // xvcmpgtdp
   0xf0000758,  // xvcmpgtdp_r
   0xf00003c0,  // xvdivdp
   0xf0000380,  // xvmuldp
   0xf00007e4,  // xvnegdp
   0xf0000788,  // xvnmsubadp
   0xf00007c8,  // xvnmsubmdp
   0xf0000340,  // xvsubdp
   0xf0000308,  // xvmaddadp
   0xf0000348,  // xvmaddmdp
   0xf0000388,  // xvmsubadp
   0xf00003c8,  // xvmsubmdp
   0xf000032c,  // xvsqrtdp
   0xfc00078c,  // fmrgew
   0xfc00068c,  // fmrgow
   0x7c000098,  // lxsiwax
   0x7c000018,  // lxsiwzx
   0x7c000418,  // lxsspx
   0x7c000118,  // stxsiwx
   0x7c000518,  // stxsspx
   0xf0000000,  // xsaddsp
   0xf000042c,  // xscvdpspn
   0xf0000520,  // xscvdpuxds
   0xf0000120,  // xscvdpuxws
   0xf0000524,  // xscvspdp
   0xf000052c,  // xscvspdpn
   0xf00004e0,  // xscvsxdsp
   0xf00005a0,  // xscvuxddp
   0xf00004a0,  // xscvuxdsp
   0xf00000c0,  // xsdivsp
   0xf0000008,  // xsmaddasp
   0xf0000048,  // xsmaddmsp
   0xf0000500,  // xsmaxdp
   0xf0000540,  // xsmindp
   0xf0000088,  // xsmsubasp
   0xf00000c8,  // xsmsubmsp
   0xf0000080,  // xsmulsp
   0xf0000408,  // xsnmaddasp
   0xf0000448,  // xsnmaddmsp
   0xf0000488,  // xsnmsubasp
   0xf00004c8,  // xsnmsubmsp
   0xf0000124,  // xsrdpi
   0xf00001e4,  // xsrdpim
   0xf00001a4,  // xsrdpip
   0xf0000164,  // xsrdpiz
   0xf0000068,  // xsresp
   0xf0000464,  // xsrsp
   0xf0000028,  // xsrsqrtesp
   0xf000002c,  // xssqrtsp
   0xf0000040,  // xssubsp
   0xf0000410,  // xxland
   0xf0000450,  // xxlandc
   0xf00005d0,  // xxleqv
   0xf0000590,  // xxlnand
   0xf0000550,  // xxlorc
   0xf00004d0,  // xxlxor
   0xf0000090,  // xxmrghw
   0xf0000190,  // xxmrglw
   0x1000078c,  // vmrgew
   0x1000068c,  // vmrgow
   0xf0000764,  // xvabsdp
   0xf0000664,  // xvabssp
   0xf0000200,  // xvaddsp
   0xf0000218,  // xvcmpeqsp
   0xf0000618,  // xvcmpeqsp_r
   0xf0000298,  // xvcmpgesp
   0xf0000698,  // xvcmpgesp_r
   0xf0000258,  // xvcmpgtsp
   0xf0000658,  // xvcmpgtsp_r
   0xf0000780,  // xvcpsgndp
   0xf0000680,  // xvcpsgnsp
   0xf0000624,  // xvcvdpsp
   0xf0000760,  // xvcvdpsxds
   0xf0000360,  // xvcvdpsxws
   0xf0000720,  // xvcvdpuxds
   0xf0000320,  // xvcvdpuxws
   0xf0000724,  // xvcvspdp
   0xf0000660,  // xvcvspsxds
   0xf0000260,  // xvcvspsxws
   0xf0000620,  // xvcvspuxds
   0xf0000220,  // xvcvspuxws
   0xf00007e0,  // xvcvsxddp
   0xf00006e0,  // xvcvsxdsp
   0xf00003e0,  // xvcvsxwdp
   0xf00002e0,  // xvcvsxwsp
   0xf00007a0,  // xvcvuxddp
   0xf00006a0,  // xvcvuxdsp
   0xf00003a0,  // xvcvuxwdp
   0xf00002a0,  // xvcvuxwsp
   0xf00002c0,  // xvdivsp
   0xf0000208,  // xvmaddasp
   0xf0000248,  // xvmaddmsp
   0xf0000600,  // xvmaxsp
   0xf0000640,  // xvminsp
   0xf0000288,  // xvmsubasp
   0xf00002c8,  // xvmsubmsp
   0xf0000280,  // xvmulsp
   0xf00007a4,  // xvnabsdp
   0xf00006a4,  // xvnabssp
   0xf00006e4,  // xvnegsp
   0xf0000708,  // xvnmaddadp
   0xf0000608,  // xvnmaddasp
   0xf0000748,  // xvnmaddmdp
   0xf0000648,  // xvnmaddmsp
   0xf0000688,  // xvnmsubasp
   0xf00006c8,  // xvnmsubmsp
   0xf0000324,  // xvrdpi
   0xf00003ac,  // xvrdpic
   0xf00003e4,  // xvrdpim
   0xf00003a4,  // xvrdpip
   0xf0000364,  // xvrdpiz
   0xf0000368,  // xvredp
   0xf0000268,  // xvresp
   0xf0000224,  // xvrspi
   0xf00002ac,  // xvrspic
   0xf00002e4,  // xvrspim
   0xf00002a4,  // xvrspip
   0xf0000264,  // xvrspiz
   0xf0000328,  // xvrsqrtedp
   0xf0000228,  // xvrsqrtesp
   0xf000022c,  // xvsqrtsp
   0xf0000240,  // xvsubsp
   0x00000000   // label
   };
