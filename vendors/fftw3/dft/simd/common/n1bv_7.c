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
/* Generated on Tue Sep 14 10:45:02 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact
 * -variables 4 -pipeline-latency 8 -sign 1 -n 7 -name n1bv_7 -include
 * dft/simd/n1b.h */

/*
 * This function contains 30 FP additions, 24 FP multiplications,
 * (or, 9 additions, 3 multiplications, 21 fused multiply/add),
 * 33 stack variables, 6 constants, and 14 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_7(const R *ri, const R *ii, R *ro, R *io, stride is, stride os,
                   INT v, INT ivs, INT ovs) {
  DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
  DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
  DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
  DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
  DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
  DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
  {
    INT i;
    const R *xi;
    R *xo;
    xi = ii;
    xo = io;
    for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs),
        MAKE_VOLATILE_STRIDE(14, is), MAKE_VOLATILE_STRIDE(14, os)) {
      V T1, T4, Tg, Ta, Te, T7, Tf, Tb, Th, Tr, To, Tm, Tj, T2, T3;
      V Ts, Tq, Tp;
      T1 = LD(&(xi[0]), ivs, &(xi[0]));
      T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
      T3 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
      T4 = VADD(T2, T3);
      Tg = VSUB(T2, T3);
      {
        V T8, T9, T5, T6;
        T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
        T9 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
        Ta = VADD(T8, T9);
        Te = VSUB(T8, T9);
        T5 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
        T6 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
        T7 = VADD(T5, T6);
        Tf = VSUB(T5, T6);
      }
      Tb = VFNMS(LDK(KP356895867), Ta, T7);
      Th = VFNMS(LDK(KP554958132), Tg, Tf);
      Tr = VFMA(LDK(KP554958132), Te, Tg);
      To = VFNMS(LDK(KP356895867), T7, T4);
      Tm = VFMA(LDK(KP554958132), Tf, Te);
      Tj = VFNMS(LDK(KP356895867), T4, Ta);
      ST(&(xo[0]), VADD(T1, VADD(T4, VADD(T7, Ta))), ovs, &(xo[0]));
      Ts = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), Tr, Tf));
      Tp = VFNMS(LDK(KP692021471), To, Ta);
      Tq = VFNMS(LDK(KP900968867), Tp, T1);
      ST(&(xo[WS(os, 1)]), VFMAI(Ts, Tq), ovs, &(xo[WS(os, 1)]));
      ST(&(xo[WS(os, 6)]), VFNMSI(Ts, Tq), ovs, &(xo[0]));
      {
        V Ti, Td, Tc, Tn, Tl, Tk;
        Ti = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Th, Te));
        Tc = VFNMS(LDK(KP692021471), Tb, T4);
        Td = VFNMS(LDK(KP900968867), Tc, T1);
        ST(&(xo[WS(os, 3)]), VFMAI(Ti, Td), ovs, &(xo[WS(os, 1)]));
        ST(&(xo[WS(os, 4)]), VFNMSI(Ti, Td), ovs, &(xo[0]));
        Tn = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tm, Tg));
        Tk = VFNMS(LDK(KP692021471), Tj, T7);
        Tl = VFNMS(LDK(KP900968867), Tk, T1);
        ST(&(xo[WS(os, 2)]), VFMAI(Tn, Tl), ovs, &(xo[0]));
        ST(&(xo[WS(os, 5)]), VFNMSI(Tn, Tl), ovs, &(xo[WS(os, 1)]));
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    7, XSIMD_STRING("n1bv_7"), {9, 3, 21, 0}, &GENUS, 0, 0, 0, 0};

void XSIMD(codelet_n1bv_7)(planner *p) { X(kdft_register)(p, n1bv_7, &desc); }

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4
 * -pipeline-latency 8 -sign 1 -n 7 -name n1bv_7 -include dft/simd/n1b.h */

/*
 * This function contains 30 FP additions, 18 FP multiplications,
 * (or, 18 additions, 6 multiplications, 12 fused multiply/add),
 * 24 stack variables, 6 constants, and 14 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_7(const R *ri, const R *ii, R *ro, R *io, stride is, stride os,
                   INT v, INT ivs, INT ovs) {
  DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
  DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
  DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
  DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
  DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
  DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
  {
    INT i;
    const R *xi;
    R *xo;
    xi = ii;
    xo = io;
    for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs),
        MAKE_VOLATILE_STRIDE(14, is), MAKE_VOLATILE_STRIDE(14, os)) {
      V Tb, T9, Tc, T3, Te, T6, Td, T7, T8, Ti, Tj;
      Tb = LD(&(xi[0]), ivs, &(xi[0]));
      T7 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
      T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
      T9 = VSUB(T7, T8);
      Tc = VADD(T7, T8);
      {
        V T1, T2, T4, T5;
        T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
        T2 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
        T3 = VSUB(T1, T2);
        Te = VADD(T1, T2);
        T4 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
        T5 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
        T6 = VSUB(T4, T5);
        Td = VADD(T4, T5);
      }
      ST(&(xo[0]), VADD(Tb, VADD(Te, VADD(Tc, Td))), ovs, &(xo[0]));
      Ti = VBYI(VFNMS(LDK(KP781831482), T6,
                      VFNMS(LDK(KP433883739), T9, VMUL(LDK(KP974927912), T3))));
      Tj = VFMA(LDK(KP623489801), Td,
                VFNMS(LDK(KP900968867), Tc, VFNMS(LDK(KP222520933), Te, Tb)));
      ST(&(xo[WS(os, 2)]), VADD(Ti, Tj), ovs, &(xo[0]));
      ST(&(xo[WS(os, 5)]), VSUB(Tj, Ti), ovs, &(xo[WS(os, 1)]));
      {
        V Ta, Tf, Tg, Th;
        Ta =
            VBYI(VFMA(LDK(KP433883739), T3,
                      VFNMS(LDK(KP781831482), T9, VMUL(LDK(KP974927912), T6))));
        Tf = VFMA(LDK(KP623489801), Tc,
                  VFNMS(LDK(KP222520933), Td, VFNMS(LDK(KP900968867), Te, Tb)));
        ST(&(xo[WS(os, 3)]), VADD(Ta, Tf), ovs, &(xo[WS(os, 1)]));
        ST(&(xo[WS(os, 4)]), VSUB(Tf, Ta), ovs, &(xo[0]));
        Tg = VBYI(VFMA(LDK(KP781831482), T3,
                       VFMA(LDK(KP974927912), T9, VMUL(LDK(KP433883739), T6))));
        Th = VFMA(LDK(KP623489801), Te,
                  VFNMS(LDK(KP900968867), Td, VFNMS(LDK(KP222520933), Tc, Tb)));
        ST(&(xo[WS(os, 1)]), VADD(Tg, Th), ovs, &(xo[WS(os, 1)]));
        ST(&(xo[WS(os, 6)]), VSUB(Th, Tg), ovs, &(xo[0]));
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    7, XSIMD_STRING("n1bv_7"), {18, 6, 12, 0}, &GENUS, 0, 0, 0, 0};

void XSIMD(codelet_n1bv_7)(planner *p) { X(kdft_register)(p, n1bv_7, &desc); }

#endif
