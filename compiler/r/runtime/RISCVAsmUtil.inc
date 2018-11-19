!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!! Copyright (c) 2000, 2016 IBM Corp. and others
!!
!! This program and the accompanying materials are made available under
!! the terms of the Eclipse Public License 2.0 which accompanies this
!! distribution and is available at http://eclipse.org/legal/epl-2.0
!! or the Apache License, Version 2.0 which accompanies this distribution
!! and is available at https://www.apache.org/licenses/LICENSE-2.0.
!!
!! This Source Code may also be made available under the following Secondary
!! Licenses when the conditions for such availability set forth in the
!! Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
!! version 2 with the GNU Classpath Exception [1] and GNU General Public
!! License, version 2 with the OpenJDK Assembly Exception [2].
!!
!! [1] https://www.gnu.org/software/classpath/license.html
!! [2] http://openjdk.java.net/legal/assembly-exception.html
!!
!! SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

.globl _tr_try_lock
.globl _tr_unlock
.globl jitPPCDataCacheBlockZero
.globl jitPPCSmpAtomicIncrement


.jitPPCUniLockCheck:
	or x0, x0, x0
__uni_lock_check:
.__uni_lock_check:
	startproc.__uni_lock_check:
	or x0, x0, x0
	endproc.__uni_lock_check:

.jitPPCUniLockUpdate:
	or x0, x0, x0
__uni_lock_update:
.__uni_lock_update:
	startproc.__uni_lock_update:
	or x0, x0, x0
	endproc.__uni_lock_update:

.jitPPCSmpLockCheck:
	or x0, x0, x0
__smp_lock_check:
.__smp_lock_check:
	startproc.__smp_lock_check:
	or x0, x0, x0
L.check_done:
	endproc.__smp_lock_check:

.jitPPCSmpLockUpdate:
	or x0, x0, x0
__smp_lock_update:
.__smp_lock_update:
	startproc.__smp_lock_update:
	or x0, x0, x0
	endproc.__smp_lock_update:

.jitPPCCodeSync:
	or x0, x0, x0
__code_synchronization:
.__code_synchronization:
	startproc.__code_synchronization:
	or x0, x0, x0
	endproc.__code_synchronization:

! prototype int jitPPCSmpAtomicIncrement(int32_t *value);
#ifdef AIXPPC
.jitPPCSmpAtomicIncrement:
	.function .jitPPCSmpAtomicIncrement,startproc.jitPPCSmpAtomicIncrement,16,0,(endproc.jitPPCSmpAtomicIncrement-startproc.jitPPCSmpAtomicIncrement)
#elif defined(LINUXPPC64)
FUNC_LABEL(jitPPCSmpAtomicIncrement):
#else
jitPPCSmpAtomicIncrement:
#endif
	startproc.jitPPCSmpAtomicIncrement:
	or x0, x0, x0
L.tryNextValue:
	or x0, x0, x0
	endproc.jitPPCSmpAtomicIncrement:

#ifdef AIXPPC
.jitPPCDataCacheBlockZero:
	.function .jitPPCDataCacheBlockZero,startproc.jitPPCDataCacheBlockZero,16,0,(endproc.jitPPCDataCacheBlockZero-startproc.jitPPCDataCacheBlockZero)
#elif defined(LINUXPPC64)
FUNC_LABEL(jitPPCDataCacheBlockZero):
#else
jitPPCDataCacheBlockZero:
#endif
	startproc.jitPPCDataCacheBlockZero:
	or x0, x0, x0
   endproc.jitPPCDataCacheBlockZero:

_tr_try_lock:
._tr_try_lock:
	or x0, x0, x0
L.try_done:
	or x0, x0, x0
	endproc._tr_try_lock:

_tr_unlock:
._tr_unlock:
	or x0, x0, x0
	endproc._tr_unlock:

! .data section
#ifdef AIXPPC
	.toc

	.csect	  _tr_try_lock{DS}
	ADDR	  ._tr_try_lock
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  _tr_try_lock{DS}

	.csect	  _tr_unlock{DS}
	ADDR	  ._tr_unlock
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  _tr_unlock{DS}

	.csect	  jitPPCUniLockCheck{DS}
	ADDR	  .jitPPCUniLockCheck
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCUniLockCheck{DS}

	.csect	  jitPPCUniLockUpdate{DS}
	ADDR	  .jitPPCUniLockUpdate
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCUniLockUpdate{DS}

	.csect	  jitPPCSmpLockCheck{DS}
	ADDR	  .jitPPCSmpLockCheck
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCSmpLockCheck{DS}

	.csect	  jitPPCSmpLockUpdate{DS}
	ADDR	  .jitPPCSmpLockUpdate
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCSmpLockUpdate{DS}

	.csect	  jitPPCCodeSync{DS}
	ADDR	  .jitPPCCodeSync
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCCodeSync{DS}

	.csect	  jitPPCSmpAtomicIncrement{DS}
	ADDR	  .jitPPCSmpAtomicIncrement
	ADDR 	  TOC{TC0}
	ADDR	  0x00000000
!End	csect	  jitPPCSmpAtomicIncrement{DS}

#elif defined(LINUXPPC64)
	.section ".toc", "wa"
	.align   4
.tocL_tr_try_lock:
        .tc       _tr_try_lock[TC], _tr_try_lock
.tocL_tr_unlock:
        .tc       _tr_unlock[TC], _tr_unlock
.tocL_jitPPCUniLockCheck:
        .tc       jitPPCUniLockCheck[TC], jitPPCUniLockCheck
.tocL_jitPPCUniLockUpdate:
        .tc       jitPPCUniLockUpdate[TC], jitPPCUniLockUpdate
.tocL_jitPPCSmpLockCheck:
        .tc       jitPPCSmpLockCheck[TC], jitPPCSmpLockCheck
.tocL_jitPPCSmpLockUpdate:
        .tc       jitPPCSmpLockUpdate[TC], jitPPCSmpLockUpdate
.tocL_jitPPCCodeSync:
        .tc       jitPPCCodeSync[TC], jitPPCCodeSync
.tocL_jitPPCSmpAtomicIncrement:
        .tc       jitPPCSmpAtomicIncrement[TC], jitPPCSmpAtomicIncrement
.tocL_jitPPCDataCacheBlockZero:
        .tc jitPPCDataCacheBlockZero[TC], jitPPCDataCacheBlockZero

#if !defined(__LITTLE_ENDIAN__)
        .section  ".opd", "wa"
        .align    3
	.globl    _tr_try_lock
	.size     _tr_try_lock,24
_tr_try_lock:
	.quad     ._tr_try_lock
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    _tr_unlock
	.size     _tr_unlock,24
_tr_unlock:
	.quad     ._tr_unlock
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCUniLockCheck
	.size     jitPPCUniLockCheck,24
jitPPCUniLockCheck:
	.quad     .jitPPCUniLockCheck
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCUniLockUpdate
	.size     jitPPCUniLockUpdate,24
jitPPCUniLockUpdate:
	.quad     .jitPPCUniLockUpdate
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCSmpLockCheck
	.size     jitPPCSmpLockCheck,24
jitPPCSmpLockCheck:
	.quad     .jitPPCSmpLockCheck
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCSmpLockUpdate
	.size     jitPPCSmpLockUpdate,24
jitPPCSmpLockUpdate:
	.quad     .jitPPCSmpLockUpdate
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCCodeSync
	.size     jitPPCCodeSync,24
jitPPCCodeSync:
	.quad     .jitPPCCodeSync
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

	.globl    jitPPCSmpAtomicIncrement
	.size     jitPPCSmpAtomicIncrement,24
jitPPCSmpAtomicIncrement:
	.quad     .jitPPCSmpAtomicIncrement
	.quad     .TOC.@tocbase
	.long     0x00000000
	.long     0x00000000

        .globl jitPPCDataCacheBlockZero
        .size jitPPCDataCacheBlockZero,24
jitPPCDataCacheBlockZero:
        .quad .jitPPCDataCacheBlockZero
        .quad .TOC.@tocbase
        .long 0x00000000
        .long 0x00000000
#endif
#endif
