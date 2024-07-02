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
/* Generated on Tue Sep 14 10:47:22 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -fma -simd -compact
 * -variables 4 -pipeline-latency 8 -trivial-stores -variables 32
 * -no-generate-bytw -n 10 -dit -name hc2cfdftv_10 -include rdft/simd/hc2cfv.h
 */

/*
 * This function contains 61 FP additions, 60 FP multiplications,
 * (or, 33 additions, 32 multiplications, 28 fused multiply/add),
 * 77 stack variables, 5 constants, and 20 memory accesses
 */
#include "rdft/simd/hc2cfv.h"

static void hc2cfdftv_10(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                         INT mb, INT me, INT ms) {
  DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
  DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 18)); m < me; m = m + VL,
        Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms),
        Im = Im - (VL * ms), W = W + (TWVL * 18),
        MAKE_VOLATILE_STRIDE(40, rs)) {
      V T8, T11, T12, TG, TH, TP, Tp, TA, TB, TS, TV, TW, TC, TX, TI;
      V TM, TF, TL, TD, TE, TJ, TO, TK, TN, T13, T17, T10, T16, TY, TZ;
      V T14, T19, T15, T18;
      {
        V T3, To, TU, Th, TT, TR, Tz, Tu, TQ, T7, T1, T2, Tw, T5, T6;
        V Tr, Tc, Tj, Tg, Ty, Tn, Tt, Tv, Tq, Ta, Tb, T9, Ti, Te, Tf;
        V Td, Tx, Tl, Tm, Tk, Ts, T4;
        T1 = LD(&(Rp[0]), ms, &(Rp[0]));
        T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
        Tv = LDW(&(W[0]));
        Tw = VZMULIJ(Tv, VFNMSCONJ(T2, T1));
        T5 = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
        T6 = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
        Tq = LDW(&(W[TWVL * 6]));
        Tr = VZMULJ(Tq, VFMACONJ(T6, T5));
        Ta = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
        Tb = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
        T9 = LDW(&(W[TWVL * 2]));
        Tc = VZMULJ(T9, VFMACONJ(Tb, Ta));
        Ti = LDW(&(W[TWVL * 4]));
        Tj = VZMULIJ(Ti, VFNMSCONJ(Tb, Ta));
        Te = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
        Tf = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
        Td = LDW(&(W[TWVL * 12]));
        Tg = VZMULIJ(Td, VFNMSCONJ(Tf, Te));
        Tx = LDW(&(W[TWVL * 10]));
        Ty = VZMULJ(Tx, VFMACONJ(Tf, Te));
        Tl = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
        Tm = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
        Tk = LDW(&(W[TWVL * 14]));
        Tn = VZMULJ(Tk, VFMACONJ(Tm, Tl));
        Ts = LDW(&(W[TWVL * 16]));
        Tt = VZMULIJ(Ts, VFNMSCONJ(Tm, Tl));
        T3 = VFMACONJ(T2, T1);
        To = VSUB(Tj, Tn);
        TU = VADD(Tr, Tt);
        Th = VSUB(Tc, Tg);
        TT = VADD(Tw, Ty);
        TR = VADD(Tj, Tn);
        Tz = VSUB(Tw, Ty);
        Tu = VSUB(Tr, Tt);
        TQ = VADD(Tc, Tg);
        T4 = LDW(&(W[TWVL * 8]));
        T7 = VZMULIJ(T4, VFNMSCONJ(T6, T5));
        T8 = VSUB(T3, T7);
        T11 = VSUB(TQ, TR);
        T12 = VSUB(TU, TT);
        TG = VADD(Tz, Tu);
        TH = VADD(Th, To);
        TP = VADD(T3, T7);
        Tp = VSUB(Th, To);
        TA = VSUB(Tu, Tz);
        TB = VADD(Tp, TA);
        TS = VADD(TQ, TR);
        TV = VADD(TT, TU);
        TW = VADD(TS, TV);
      }
      TC = VMUL(LDK(KP500000000), VADD(T8, TB));
      ST(&(Rp[0]), TC, ms, &(Rp[0]));
      TX = VCONJ(VMUL(LDK(KP500000000), VADD(TP, TW)));
      ST(&(Rm[WS(rs, 4)]), TX, -ms, &(Rm[0]));
      TI = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TH, TG));
      TM = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TG, TH));
      TD = VFNMS(LDK(KP250000000), TB, T8);
      TE = VSUB(Tp, TA);
      TF = VFNMS(LDK(KP559016994), TE, TD);
      TL = VFMA(LDK(KP559016994), TE, TD);
      TJ = VCONJ(VMUL(LDK(KP500000000), VFNMSI(TI, TF)));
      ST(&(Rm[WS(rs, 1)]), TJ, -ms, &(Rm[WS(rs, 1)]));
      TO = VMUL(LDK(KP500000000), VFMAI(TM, TL));
      ST(&(Rp[WS(rs, 4)]), TO, ms, &(Rp[0]));
      TK = VMUL(LDK(KP500000000), VFMAI(TI, TF));
      ST(&(Rp[WS(rs, 2)]), TK, ms, &(Rp[0]));
      TN = VCONJ(VMUL(LDK(KP500000000), VFNMSI(TM, TL)));
      ST(&(Rm[WS(rs, 3)]), TN, -ms, &(Rm[WS(rs, 1)]));
      T13 = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T12, T11));
      T17 = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T11, T12));
      TY = VFNMS(LDK(KP250000000), TW, TP);
      TZ = VSUB(TS, TV);
      T10 = VFMA(LDK(KP559016994), TZ, TY);
      T16 = VFNMS(LDK(KP559016994), TZ, TY);
      T14 = VMUL(LDK(KP500000000), VFNMSI(T13, T10));
      ST(&(Rp[WS(rs, 1)]), T14, ms, &(Rp[WS(rs, 1)]));
      T19 = VCONJ(VMUL(LDK(KP500000000), VFMAI(T17, T16)));
      ST(&(Rm[WS(rs, 2)]), T19, -ms, &(Rm[0]));
      T15 = VCONJ(VMUL(LDK(KP500000000), VFMAI(T13, T10)));
      ST(&(Rm[0]), T15, -ms, &(Rm[0]));
      T18 = VMUL(LDK(KP500000000), VFNMSI(T17, T16));
      ST(&(Rp[WS(rs, 3)]), T18, ms, &(Rp[WS(rs, 1)]));
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(1, 1), VTW(1, 2), VTW(1, 3), VTW(1, 4), VTW(1, 5),
    VTW(1, 6), VTW(1, 7), VTW(1, 8), VTW(1, 9), {TW_NEXT, VL, 0}};

static const hc2c_desc desc = {
    10, XSIMD_STRING("hc2cfdftv_10"), twinstr, &GENUS, {33, 32, 28, 0}};

void XSIMD(codelet_hc2cfdftv_10)(planner *p) {
  X(khc2c_register)(p, hc2cfdftv_10, &desc, HC2C_VIA_DFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -simd -compact -variables
 * 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 10
 * -dit -name hc2cfdftv_10 -include rdft/simd/hc2cfv.h */

/*
 * This function contains 61 FP additions, 38 FP multiplications,
 * (or, 55 additions, 32 multiplications, 6 fused multiply/add),
 * 82 stack variables, 5 constants, and 20 memory accesses
 */
#include "rdft/simd/hc2cfv.h"

static void hc2cfdftv_10(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                         INT mb, INT me, INT ms) {
  DVK(KP125000000, +0.125000000000000000000000000000000000000000000);
  DVK(KP279508497, +0.279508497187473712051146708591409529430077295);
  DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
  DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 18)); m < me; m = m + VL,
        Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms),
        Im = Im - (VL * ms), W = W + (TWVL * 18),
        MAKE_VOLATILE_STRIDE(40, rs)) {
      V Tl, Tt, Tu, TY, TZ, T10, Tz, TE, TF, TV, TW, TX, Ta, TU, TN;
      V TR, TH, TQ, TK, TL, TM, TI, TG, TJ, TT, TO, TP, TS, T18, T1c;
      V T12, T1b, T15, T16, T17, T14, T11, T13, T1e, T19, T1a, T1d;
      {
        V T1, T3, Ty, T8, T7, TB, Tf, Ts, Tk, Tw, Tq, TD, T2, Tx, T6;
        V TA, Tc, Te, Td, Tb, Tr, Tj, Ti, Th, Tg, Tv, Tn, Tp, To, Tm;
        V TC, T4, T9, T5;
        T1 = LD(&(Rp[0]), ms, &(Rp[0]));
        T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
        T3 = VCONJ(T2);
        Tx = LDW(&(W[0]));
        Ty = VZMULIJ(Tx, VSUB(T3, T1));
        T8 = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
        T6 = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
        T7 = VCONJ(T6);
        TA = LDW(&(W[TWVL * 6]));
        TB = VZMULJ(TA, VADD(T7, T8));
        Tc = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
        Td = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
        Te = VCONJ(Td);
        Tb = LDW(&(W[TWVL * 2]));
        Tf = VZMULJ(Tb, VADD(Tc, Te));
        Tr = LDW(&(W[TWVL * 4]));
        Ts = VZMULIJ(Tr, VSUB(Te, Tc));
        Tj = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
        Th = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
        Ti = VCONJ(Th);
        Tg = LDW(&(W[TWVL * 12]));
        Tk = VZMULIJ(Tg, VSUB(Ti, Tj));
        Tv = LDW(&(W[TWVL * 10]));
        Tw = VZMULJ(Tv, VADD(Ti, Tj));
        Tn = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
        To = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
        Tp = VCONJ(To);
        Tm = LDW(&(W[TWVL * 14]));
        Tq = VZMULJ(Tm, VADD(Tn, Tp));
        TC = LDW(&(W[TWVL * 16]));
        TD = VZMULIJ(TC, VSUB(Tp, Tn));
        Tl = VSUB(Tf, Tk);
        Tt = VSUB(Tq, Ts);
        Tu = VADD(Tl, Tt);
        TY = VADD(Ty, Tw);
        TZ = VADD(TB, TD);
        T10 = VADD(TY, TZ);
        Tz = VSUB(Tw, Ty);
        TE = VSUB(TB, TD);
        TF = VADD(Tz, TE);
        TV = VADD(Tf, Tk);
        TW = VADD(Ts, Tq);
        TX = VADD(TV, TW);
        T4 = VADD(T1, T3);
        T5 = LDW(&(W[TWVL * 8]));
        T9 = VZMULIJ(T5, VSUB(T7, T8));
        Ta = VSUB(T4, T9);
        TU = VADD(T4, T9);
      }
      TL = VSUB(Tl, Tt);
      TM = VSUB(TE, Tz);
      TN = VMUL(LDK(KP500000000),
                VBYI(VFMA(LDK(KP951056516), TL, VMUL(LDK(KP587785252), TM))));
      TR = VMUL(LDK(KP500000000),
                VBYI(VFNMS(LDK(KP587785252), TL, VMUL(LDK(KP951056516), TM))));
      TI = VMUL(LDK(KP279508497), VSUB(Tu, TF));
      TG = VADD(Tu, TF);
      TJ = VFNMS(LDK(KP125000000), TG, VMUL(LDK(KP500000000), Ta));
      TH = VCONJ(VMUL(LDK(KP500000000), VADD(Ta, TG)));
      TQ = VSUB(TJ, TI);
      TK = VADD(TI, TJ);
      ST(&(Rm[WS(rs, 4)]), TH, -ms, &(Rm[0]));
      TT = VCONJ(VADD(TQ, TR));
      ST(&(Rm[WS(rs, 2)]), TT, -ms, &(Rm[0]));
      TO = VSUB(TK, TN);
      ST(&(Rp[WS(rs, 1)]), TO, ms, &(Rp[WS(rs, 1)]));
      TP = VCONJ(VADD(TK, TN));
      ST(&(Rm[0]), TP, -ms, &(Rm[0]));
      TS = VSUB(TQ, TR);
      ST(&(Rp[WS(rs, 3)]), TS, ms, &(Rp[WS(rs, 1)]));
      T16 = VSUB(TZ, TY);
      T17 = VSUB(TV, TW);
      T18 =
          VMUL(LDK(KP500000000),
               VBYI(VFNMS(LDK(KP587785252), T17, VMUL(LDK(KP951056516), T16))));
      T1c =
          VMUL(LDK(KP500000000),
               VBYI(VFMA(LDK(KP951056516), T17, VMUL(LDK(KP587785252), T16))));
      T14 = VMUL(LDK(KP279508497), VSUB(TX, T10));
      T11 = VADD(TX, T10);
      T13 = VFNMS(LDK(KP125000000), T11, VMUL(LDK(KP500000000), TU));
      T12 = VMUL(LDK(KP500000000), VADD(TU, T11));
      T1b = VADD(T14, T13);
      T15 = VSUB(T13, T14);
      ST(&(Rp[0]), T12, ms, &(Rp[0]));
      T1e = VADD(T1b, T1c);
      ST(&(Rp[WS(rs, 4)]), T1e, ms, &(Rp[0]));
      T19 = VCONJ(VSUB(T15, T18));
      ST(&(Rm[WS(rs, 1)]), T19, -ms, &(Rm[WS(rs, 1)]));
      T1a = VADD(T15, T18);
      ST(&(Rp[WS(rs, 2)]), T1a, ms, &(Rp[0]));
      T1d = VCONJ(VSUB(T1b, T1c));
      ST(&(Rm[WS(rs, 3)]), T1d, -ms, &(Rm[WS(rs, 1)]));
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(1, 1), VTW(1, 2), VTW(1, 3), VTW(1, 4), VTW(1, 5),
    VTW(1, 6), VTW(1, 7), VTW(1, 8), VTW(1, 9), {TW_NEXT, VL, 0}};

static const hc2c_desc desc = {
    10, XSIMD_STRING("hc2cfdftv_10"), twinstr, &GENUS, {55, 32, 6, 0}};

void XSIMD(codelet_hc2cfdftv_10)(planner *p) {
  X(khc2c_register)(p, hc2cfdftv_10, &desc, HC2C_VIA_DFT);
}
#endif
