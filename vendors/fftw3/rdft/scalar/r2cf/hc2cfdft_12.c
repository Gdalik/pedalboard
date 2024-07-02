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
/* Generated on Tue Sep 14 10:46:37 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2cdft.native -fma -compact -variables 4
 * -pipeline-latency 4 -n 12 -dit -name hc2cfdft_12 -include rdft/scalar/hc2cf.h
 */

/*
 * This function contains 142 FP additions, 92 FP multiplications,
 * (or, 96 additions, 46 multiplications, 46 fused multiply/add),
 * 65 stack variables, 2 constants, and 48 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cfdft_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                        INT mb, INT me, INT ms) {
  DK(KP866025403, +0.866025403784438646763723170752936183471402627);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 22); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 22,
        MAKE_VOLATILE_STRIDE(48, rs)) {
      E To, T1E, T1m, T2H, Ta, T1G, Tk, T1I, Tl, T1J, T1s, T2b, T1A, T2d, T1B;
      E T2I, T12, T18, T19, T24, T26, T2C, Tz, T1M, T1f, T2B, TJ, T1O, TT, T1Q;
      E TU, T1R;
      {
        E Tm, Tn, T1u, T1x, T1y, T1z, T1v, T2c, Te, Tj, T1i, T1l, Tf, T1H, T4;
        E T1o, T9, T1r, T5, T1F, T1p, T2a, T1t, T1, T1n;
        Tm = Ip[0];
        Tn = Im[0];
        T1u = Tm + Tn;
        T1x = Rp[0];
        T1y = Rm[0];
        T1z = T1x - T1y;
        T1t = W[0];
        T1v = T1t * T1u;
        T2c = T1t * T1z;
        {
          E Tc, Td, Th, Ti, Tb;
          Tc = Ip[WS(rs, 4)];
          Td = Im[WS(rs, 4)];
          Te = Tc - Td;
          Th = Rp[WS(rs, 4)];
          Ti = Rm[WS(rs, 4)];
          Tj = Th + Ti;
          T1i = Tc + Td;
          T1l = Th - Ti;
          Tb = W[14];
          Tf = Tb * Te;
          T1H = Tb * Tj;
        }
        {
          E T2, T3, T7, T8;
          T2 = Ip[WS(rs, 2)];
          T3 = Im[WS(rs, 2)];
          T4 = T2 - T3;
          T1o = T2 + T3;
          T7 = Rp[WS(rs, 2)];
          T8 = Rm[WS(rs, 2)];
          T9 = T7 + T8;
          T1r = T7 - T8;
        }
        T1 = W[6];
        T5 = T1 * T4;
        T1F = T1 * T9;
        T1n = W[8];
        T1p = T1n * T1o;
        T2a = T1n * T1r;
        To = Tm - Tn;
        T1E = T1x + T1y;
        {
          E T1j, T2G, T1h, T1k;
          T1h = W[16];
          T1j = T1h * T1i;
          T2G = T1h * T1l;
          T1k = W[17];
          T1m = FNMS(T1k, T1l, T1j);
          T2H = FMA(T1k, T1i, T2G);
        }
        {
          E T6, Tg, T1q, T1w;
          T6 = W[7];
          Ta = FNMS(T6, T9, T5);
          T1G = FMA(T6, T4, T1F);
          Tg = W[15];
          Tk = FNMS(Tg, Tj, Tf);
          T1I = FMA(Tg, Te, T1H);
          Tl = Ta + Tk;
          T1J = T1G + T1I;
          T1q = W[9];
          T1s = FNMS(T1q, T1r, T1p);
          T2b = FMA(T1q, T1o, T2a);
          T1w = W[1];
          T1A = FNMS(T1w, T1z, T1v);
          T2d = FMA(T1w, T1u, T2c);
          T1B = T1s + T1A;
          T2I = T2b + T2d;
        }
      }
      {
        E Tt, T11, Ty, T10, T23, TX, TZ, TN, TS, T1b, T1e, TO, T1P, TD, TI;
        E T17, T16, T25, T13, T15, TE, T1N, TF, TP;
        {
          E Tr, Ts, Tw, Tx, TY;
          Tr = Ip[WS(rs, 3)];
          Ts = Im[WS(rs, 3)];
          Tt = Tr - Ts;
          T11 = Tr + Ts;
          Tw = Rp[WS(rs, 3)];
          Tx = Rm[WS(rs, 3)];
          TY = Tx - Tw;
          Ty = Tw + Tx;
          T10 = W[12];
          T23 = T10 * TY;
          TX = W[13];
          TZ = TX * TY;
        }
        {
          E TL, TM, TQ, TR, TK;
          TL = Ip[WS(rs, 1)];
          TM = Im[WS(rs, 1)];
          TN = TL - TM;
          TQ = Rp[WS(rs, 1)];
          TR = Rm[WS(rs, 1)];
          TS = TQ + TR;
          T1b = TL + TM;
          T1e = TQ - TR;
          TK = W[2];
          TO = TK * TN;
          T1P = TK * TS;
        }
        {
          E TB, TC, T14, TG, TH, TA;
          TB = Ip[WS(rs, 5)];
          TC = Im[WS(rs, 5)];
          TD = TB - TC;
          TG = Rp[WS(rs, 5)];
          TH = Rm[WS(rs, 5)];
          TI = TG + TH;
          T14 = TH - TG;
          T17 = TB + TC;
          T16 = W[20];
          T25 = T16 * T14;
          T13 = W[21];
          T15 = T13 * T14;
          TA = W[18];
          TE = TA * TD;
          T1N = TA * TI;
        }
        T12 = FMA(T10, T11, TZ);
        T18 = FMA(T16, T17, T15);
        T19 = T12 + T18;
        T24 = FNMS(TX, T11, T23);
        T26 = FNMS(T13, T17, T25);
        T2C = T24 + T26;
        {
          E Tu, T1L, Tq, Tv;
          Tq = W[10];
          Tu = Tq * Tt;
          T1L = Tq * Ty;
          Tv = W[11];
          Tz = FNMS(Tv, Ty, Tu);
          T1M = FMA(Tv, Tt, T1L);
        }
        {
          E T1c, T2A, T1a, T1d;
          T1a = W[4];
          T1c = T1a * T1b;
          T2A = T1a * T1e;
          T1d = W[5];
          T1f = FNMS(T1d, T1e, T1c);
          T2B = FMA(T1d, T1b, T2A);
        }
        TF = W[19];
        TJ = FNMS(TF, TI, TE);
        T1O = FMA(TF, TD, T1N);
        TP = W[3];
        TT = FNMS(TP, TS, TO);
        T1Q = FMA(TP, TN, T1P);
        TU = TJ + TT;
        T1R = T1O + T1Q;
      }
      {
        E TW, T2V, T2Y, T30, T1D, T1U, T1T, T2Z;
        {
          E Tp, TV, T2W, T2X;
          Tp = Tl + To;
          TV = Tz + TU;
          TW = Tp - TV;
          T2V = TV + Tp;
          T2W = T2C - T2B;
          T2X = T2H + T2I;
          T2Y = T2W - T2X;
          T30 = T2W + T2X;
        }
        {
          E T1g, T1C, T1K, T1S;
          T1g = T19 + T1f;
          T1C = T1m + T1B;
          T1D = T1g - T1C;
          T1U = T1g + T1C;
          T1K = T1E + T1J;
          T1S = T1M + T1R;
          T1T = T1K + T1S;
          T2Z = T1K - T1S;
        }
        Ip[WS(rs, 3)] = KP500000000 * (TW + T1D);
        Rp[WS(rs, 3)] = KP500000000 * (T2Z - T30);
        Im[WS(rs, 2)] = KP500000000 * (T1D - TW);
        Rm[WS(rs, 2)] = KP500000000 * (T2Z + T30);
        Rm[WS(rs, 5)] = KP500000000 * (T1T - T1U);
        Im[WS(rs, 5)] = KP500000000 * (T2Y - T2V);
        Rp[0] = KP500000000 * (T1T + T1U);
        Ip[0] = KP500000000 * (T2V + T2Y);
      }
      {
        E T1X, T2v, T2F, T2Q, T2L, T2R, T20, T2w, T28, T2t, T2j, T2p, T2m, T2q,
            T2f;
        E T2s;
        {
          E T1V, T1W, T2D, T2E;
          T1V = FNMS(KP500000000, T1J, T1E);
          T1W = Ta - Tk;
          T1X = FNMS(KP866025403, T1W, T1V);
          T2v = FMA(KP866025403, T1W, T1V);
          T2D = FMA(KP500000000, T2C, T2B);
          T2E = T18 - T12;
          T2F = FNMS(KP866025403, T2E, T2D);
          T2Q = FMA(KP866025403, T2E, T2D);
        }
        {
          E T2J, T2K, T1Y, T1Z;
          T2J = FNMS(KP500000000, T2I, T2H);
          T2K = T1s - T1A;
          T2L = FNMS(KP866025403, T2K, T2J);
          T2R = FMA(KP866025403, T2K, T2J);
          T1Y = FNMS(KP500000000, T1R, T1M);
          T1Z = TJ - TT;
          T20 = FNMS(KP866025403, T1Z, T1Y);
          T2w = FMA(KP866025403, T1Z, T1Y);
        }
        {
          E T22, T27, T2h, T2i;
          T22 = FNMS(KP500000000, T19, T1f);
          T27 = T24 - T26;
          T28 = FNMS(KP866025403, T27, T22);
          T2t = FMA(KP866025403, T27, T22);
          T2h = FNMS(KP500000000, Tl, To);
          T2i = T1I - T1G;
          T2j = FNMS(KP866025403, T2i, T2h);
          T2p = FMA(KP866025403, T2i, T2h);
        }
        {
          E T2k, T2l, T29, T2e;
          T2k = FNMS(KP500000000, TU, Tz);
          T2l = T1Q - T1O;
          T2m = FNMS(KP866025403, T2l, T2k);
          T2q = FMA(KP866025403, T2l, T2k);
          T29 = FNMS(KP500000000, T1B, T1m);
          T2e = T2b - T2d;
          T2f = FNMS(KP866025403, T2e, T29);
          T2s = FMA(KP866025403, T2e, T29);
        }
        {
          E T21, T2g, T2P, T2S;
          T21 = T1X + T20;
          T2g = T28 + T2f;
          Rp[WS(rs, 2)] = KP500000000 * (T21 - T2g);
          Rm[WS(rs, 3)] = KP500000000 * (T21 + T2g);
          T2P = T2m + T2j;
          T2S = T2Q + T2R;
          Ip[WS(rs, 2)] = KP500000000 * (T2P + T2S);
          Im[WS(rs, 3)] = KP500000000 * (T2S - T2P);
        }
        {
          E T2n, T2o, T2T, T2U;
          T2n = T2j - T2m;
          T2o = T2f - T28;
          Ip[WS(rs, 5)] = KP500000000 * (T2n + T2o);
          Im[0] = KP500000000 * (T2o - T2n);
          T2T = T1X - T20;
          T2U = T2R - T2Q;
          Rm[0] = KP500000000 * (T2T - T2U);
          Rp[WS(rs, 5)] = KP500000000 * (T2T + T2U);
        }
        {
          E T2r, T2u, T2N, T2O;
          T2r = T2p - T2q;
          T2u = T2s - T2t;
          Ip[WS(rs, 1)] = KP500000000 * (T2r + T2u);
          Im[WS(rs, 4)] = KP500000000 * (T2u - T2r);
          T2N = T2v - T2w;
          T2O = T2L - T2F;
          Rm[WS(rs, 4)] = KP500000000 * (T2N - T2O);
          Rp[WS(rs, 1)] = KP500000000 * (T2N + T2O);
        }
        {
          E T2x, T2y, T2z, T2M;
          T2x = T2v + T2w;
          T2y = T2t + T2s;
          Rm[WS(rs, 1)] = KP500000000 * (T2x - T2y);
          Rp[WS(rs, 4)] = KP500000000 * (T2x + T2y);
          T2z = T2q + T2p;
          T2M = T2F + T2L;
          Ip[WS(rs, 4)] = KP500000000 * (T2z - T2M);
          Im[WS(rs, 1)] = -(KP500000000 * (T2z + T2M));
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 12}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {
    12, "hc2cfdft_12", twinstr, &GENUS, {96, 46, 46, 0}};

void X(codelet_hc2cfdft_12)(planner *p) {
  X(khc2c_register)(p, hc2cfdft_12, &desc, HC2C_VIA_DFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2cdft.native -compact -variables 4
 * -pipeline-latency 4 -n 12 -dit -name hc2cfdft_12 -include rdft/scalar/hc2cf.h
 */

/*
 * This function contains 142 FP additions, 76 FP multiplications,
 * (or, 112 additions, 46 multiplications, 30 fused multiply/add),
 * 52 stack variables, 3 constants, and 48 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cfdft_12(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                        INT mb, INT me, INT ms) {
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  DK(KP433012701, +0.433012701892219323381861585376468091735701313);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 22); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 22,
        MAKE_VOLATILE_STRIDE(48, rs)) {
      E Tm, T1t, T1d, T2j, Tj, T1Y, T1w, T1G, T1q, T2q, T1U, T2k, Tw, T1y, T17;
      E T2g, TP, T21, T1B, T1J, T12, T2u, T1P, T2h;
      {
        E Tk, Tl, T1k, T1m, T1n, T1o, T4, T1f, T8, T1h, Th, T1c, Td, T1a, T19;
        E T1b;
        {
          E T2, T3, T6, T7;
          Tk = Ip[0];
          Tl = Im[0];
          T1k = Tk + Tl;
          T1m = Rp[0];
          T1n = Rm[0];
          T1o = T1m - T1n;
          T2 = Ip[WS(rs, 2)];
          T3 = Im[WS(rs, 2)];
          T4 = T2 - T3;
          T1f = T2 + T3;
          T6 = Rp[WS(rs, 2)];
          T7 = Rm[WS(rs, 2)];
          T8 = T6 + T7;
          T1h = T6 - T7;
          {
            E Tf, Tg, Tb, Tc;
            Tf = Rp[WS(rs, 4)];
            Tg = Rm[WS(rs, 4)];
            Th = Tf + Tg;
            T1c = Tf - Tg;
            Tb = Ip[WS(rs, 4)];
            Tc = Im[WS(rs, 4)];
            Td = Tb - Tc;
            T1a = Tb + Tc;
          }
        }
        Tm = Tk - Tl;
        T1t = T1m + T1n;
        T19 = W[16];
        T1b = W[17];
        T1d = FNMS(T1b, T1c, T19 * T1a);
        T2j = FMA(T19, T1c, T1b * T1a);
        {
          E T9, T1u, Ti, T1v;
          {
            E T1, T5, Ta, Te;
            T1 = W[6];
            T5 = W[7];
            T9 = FNMS(T5, T8, T1 * T4);
            T1u = FMA(T1, T8, T5 * T4);
            Ta = W[14];
            Te = W[15];
            Ti = FNMS(Te, Th, Ta * Td);
            T1v = FMA(Ta, Th, Te * Td);
          }
          Tj = T9 + Ti;
          T1Y = KP433012701 * (T1v - T1u);
          T1w = T1u + T1v;
          T1G = KP433012701 * (T9 - Ti);
        }
        {
          E T1i, T1S, T1p, T1T;
          {
            E T1e, T1g, T1j, T1l;
            T1e = W[8];
            T1g = W[9];
            T1i = FNMS(T1g, T1h, T1e * T1f);
            T1S = FMA(T1e, T1h, T1g * T1f);
            T1j = W[0];
            T1l = W[1];
            T1p = FNMS(T1l, T1o, T1j * T1k);
            T1T = FMA(T1j, T1o, T1l * T1k);
          }
          T1q = T1i + T1p;
          T2q = KP433012701 * (T1i - T1p);
          T1U = KP433012701 * (T1S - T1T);
          T2k = T1S + T1T;
        }
      }
      {
        E Tr, TT, Tv, TV, TA, TY, TE, T10, TN, T14, TJ, T16;
        {
          E Tp, Tq, TC, TD;
          Tp = Ip[WS(rs, 3)];
          Tq = Im[WS(rs, 3)];
          Tr = Tp - Tq;
          TT = Tp + Tq;
          {
            E Tt, Tu, Ty, Tz;
            Tt = Rp[WS(rs, 3)];
            Tu = Rm[WS(rs, 3)];
            Tv = Tt + Tu;
            TV = Tt - Tu;
            Ty = Ip[WS(rs, 5)];
            Tz = Im[WS(rs, 5)];
            TA = Ty - Tz;
            TY = Ty + Tz;
          }
          TC = Rp[WS(rs, 5)];
          TD = Rm[WS(rs, 5)];
          TE = TC + TD;
          T10 = TC - TD;
          {
            E TL, TM, TH, TI;
            TL = Rp[WS(rs, 1)];
            TM = Rm[WS(rs, 1)];
            TN = TL + TM;
            T14 = TM - TL;
            TH = Ip[WS(rs, 1)];
            TI = Im[WS(rs, 1)];
            TJ = TH - TI;
            T16 = TH + TI;
          }
        }
        {
          E To, Ts, T13, T15;
          To = W[10];
          Ts = W[11];
          Tw = FNMS(Ts, Tv, To * Tr);
          T1y = FMA(To, Tv, Ts * Tr);
          T13 = W[5];
          T15 = W[4];
          T17 = FMA(T13, T14, T15 * T16);
          T2g = FNMS(T13, T16, T15 * T14);
        }
        {
          E TF, T1z, TO, T1A;
          {
            E Tx, TB, TG, TK;
            Tx = W[18];
            TB = W[19];
            TF = FNMS(TB, TE, Tx * TA);
            T1z = FMA(Tx, TE, TB * TA);
            TG = W[2];
            TK = W[3];
            TO = FNMS(TK, TN, TG * TJ);
            T1A = FMA(TG, TN, TK * TJ);
          }
          TP = TF + TO;
          T21 = KP433012701 * (T1A - T1z);
          T1B = T1z + T1A;
          T1J = KP433012701 * (TF - TO);
        }
        {
          E TW, T1O, T11, T1N;
          {
            E TS, TU, TX, TZ;
            TS = W[12];
            TU = W[13];
            TW = FNMS(TU, TV, TS * TT);
            T1O = FMA(TS, TV, TU * TT);
            TX = W[20];
            TZ = W[21];
            T11 = FNMS(TZ, T10, TX * TY);
            T1N = FMA(TX, T10, TZ * TY);
          }
          T12 = TW + T11;
          T2u = KP433012701 * (T11 - TW);
          T1P = KP433012701 * (T1N - T1O);
          T2h = T1O + T1N;
        }
      }
      {
        E TR, T2f, T2m, T2o, T1s, T1E, T1D, T2n;
        {
          E Tn, TQ, T2i, T2l;
          Tn = Tj + Tm;
          TQ = Tw + TP;
          TR = Tn - TQ;
          T2f = TQ + Tn;
          T2i = T2g - T2h;
          T2l = T2j + T2k;
          T2m = T2i - T2l;
          T2o = T2i + T2l;
        }
        {
          E T18, T1r, T1x, T1C;
          T18 = T12 + T17;
          T1r = T1d + T1q;
          T1s = T18 - T1r;
          T1E = T18 + T1r;
          T1x = T1t + T1w;
          T1C = T1y + T1B;
          T1D = T1x + T1C;
          T2n = T1x - T1C;
        }
        Ip[WS(rs, 3)] = KP500000000 * (TR + T1s);
        Rp[WS(rs, 3)] = KP500000000 * (T2n - T2o);
        Im[WS(rs, 2)] = KP500000000 * (T1s - TR);
        Rm[WS(rs, 2)] = KP500000000 * (T2n + T2o);
        Rm[WS(rs, 5)] = KP500000000 * (T1D - T1E);
        Im[WS(rs, 5)] = KP500000000 * (T2m - T2f);
        Rp[0] = KP500000000 * (T1D + T1E);
        Ip[0] = KP500000000 * (T2f + T2m);
      }
      {
        E T1H, T2b, T2s, T2B, T2v, T2A, T1K, T2c, T1Q, T29, T1Z, T25, T22, T26,
            T1V;
        E T28;
        {
          E T1F, T2r, T2t, T1I;
          T1F = FNMS(KP250000000, T1w, KP500000000 * T1t);
          T1H = T1F - T1G;
          T2b = T1F + T1G;
          T2r = FNMS(KP500000000, T2j, KP250000000 * T2k);
          T2s = T2q - T2r;
          T2B = T2q + T2r;
          T2t = FMA(KP250000000, T2h, KP500000000 * T2g);
          T2v = T2t - T2u;
          T2A = T2u + T2t;
          T1I = FNMS(KP250000000, T1B, KP500000000 * T1y);
          T1K = T1I - T1J;
          T2c = T1I + T1J;
        }
        {
          E T1M, T1X, T20, T1R;
          T1M = FNMS(KP250000000, T12, KP500000000 * T17);
          T1Q = T1M - T1P;
          T29 = T1P + T1M;
          T1X = FNMS(KP250000000, Tj, KP500000000 * Tm);
          T1Z = T1X - T1Y;
          T25 = T1Y + T1X;
          T20 = FNMS(KP250000000, TP, KP500000000 * Tw);
          T22 = T20 - T21;
          T26 = T21 + T20;
          T1R = FNMS(KP250000000, T1q, KP500000000 * T1d);
          T1V = T1R - T1U;
          T28 = T1R + T1U;
        }
        {
          E T1L, T1W, T2p, T2w;
          T1L = T1H + T1K;
          T1W = T1Q + T1V;
          Rp[WS(rs, 2)] = T1L - T1W;
          Rm[WS(rs, 3)] = T1L + T1W;
          T2p = T22 + T1Z;
          T2w = T2s - T2v;
          Ip[WS(rs, 2)] = T2p + T2w;
          Im[WS(rs, 3)] = T2w - T2p;
        }
        {
          E T23, T24, T2x, T2y;
          T23 = T1Z - T22;
          T24 = T1V - T1Q;
          Ip[WS(rs, 5)] = T23 + T24;
          Im[0] = T24 - T23;
          T2x = T1H - T1K;
          T2y = T2v + T2s;
          Rm[0] = T2x - T2y;
          Rp[WS(rs, 5)] = T2x + T2y;
        }
        {
          E T27, T2a, T2z, T2C;
          T27 = T25 - T26;
          T2a = T28 - T29;
          Ip[WS(rs, 1)] = T27 + T2a;
          Im[WS(rs, 4)] = T2a - T27;
          T2z = T2b - T2c;
          T2C = T2A - T2B;
          Rm[WS(rs, 4)] = T2z - T2C;
          Rp[WS(rs, 1)] = T2z + T2C;
        }
        {
          E T2d, T2e, T2D, T2E;
          T2d = T2b + T2c;
          T2e = T29 + T28;
          Rm[WS(rs, 1)] = T2d - T2e;
          Rp[WS(rs, 4)] = T2d + T2e;
          T2D = T26 + T25;
          T2E = T2A + T2B;
          Ip[WS(rs, 4)] = T2D + T2E;
          Im[WS(rs, 1)] = T2E - T2D;
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 12}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {
    12, "hc2cfdft_12", twinstr, &GENUS, {112, 46, 30, 0}};

void X(codelet_hc2cfdft_12)(planner *p) {
  X(khc2c_register)(p, hc2cfdft_12, &desc, HC2C_VIA_DFT);
}
#endif
