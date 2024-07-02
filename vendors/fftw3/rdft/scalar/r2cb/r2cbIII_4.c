/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Sep 14 10:46:59 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 4 -name r2cbIII_4 -dft-III -include
 * rdft/scalar/r2cbIII.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 6 additions, 4 multiplications, 0 fused multiply/add),
 * 9 stack variables, 2 constants, and 8 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_4(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                      stride csi, INT v, INT ivs, INT ovs) {
  DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
  DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs,
        Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(16, rs),
        MAKE_VOLATILE_STRIDE(16, csr), MAKE_VOLATILE_STRIDE(16, csi)) {
      E T1, T2, T3, T4, T5, T6;
      T1 = Cr[0];
      T2 = Cr[WS(csr, 1)];
      T3 = T1 - T2;
      T4 = Ci[0];
      T5 = Ci[WS(csi, 1)];
      T6 = T4 + T5;
      R0[0] = KP2_000000000 * (T1 + T2);
      R0[WS(rs, 1)] = KP2_000000000 * (T5 - T4);
      R1[0] = KP1_414213562 * (T3 - T6);
      R1[WS(rs, 1)] = -(KP1_414213562 * (T3 + T6));
    }
  }
}

static const kr2c_desc desc = {4, "r2cbIII_4", {6, 4, 0, 0}, &GENUS};

void X(codelet_r2cbIII_4)(planner *p) { X(kr2c_register)(p, r2cbIII_4, &desc); }

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 4 -name r2cbIII_4 -dft-III -include
 * rdft/scalar/r2cbIII.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 6 additions, 4 multiplications, 0 fused multiply/add),
 * 9 stack variables, 2 constants, and 8 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_4(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                      stride csi, INT v, INT ivs, INT ovs) {
  DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
  DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs,
        Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(16, rs),
        MAKE_VOLATILE_STRIDE(16, csr), MAKE_VOLATILE_STRIDE(16, csi)) {
      E T1, T2, T3, T4, T5, T6;
      T1 = Cr[0];
      T2 = Cr[WS(csr, 1)];
      T3 = T1 - T2;
      T4 = Ci[0];
      T5 = Ci[WS(csi, 1)];
      T6 = T4 + T5;
      R0[0] = KP2_000000000 * (T1 + T2);
      R0[WS(rs, 1)] = KP2_000000000 * (T5 - T4);
      R1[0] = KP1_414213562 * (T3 - T6);
      R1[WS(rs, 1)] = -(KP1_414213562 * (T3 + T6));
    }
  }
}

static const kr2c_desc desc = {4, "r2cbIII_4", {6, 4, 0, 0}, &GENUS};

void X(codelet_r2cbIII_4)(planner *p) { X(kr2c_register)(p, r2cbIII_4, &desc); }

#endif
