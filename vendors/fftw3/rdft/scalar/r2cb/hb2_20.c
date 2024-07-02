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
/* Generated on Tue Sep 14 10:46:57 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -compact -variables 4
 * -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 20 -dif
 * -name hb2_20 -include rdft/scalar/hb.h */

/*
 * This function contains 276 FP additions, 198 FP multiplications,
 * (or, 136 additions, 58 multiplications, 140 fused multiply/add),
 * 129 stack variables, 4 constants, and 80 memory accesses
 */
#include "rdft/scalar/hb.h"

static void hb2_20(R *cr, R *ci, const R *W, stride rs, INT mb, INT me,
                   INT ms) {
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP618033988, +0.618033988749894848204586834365638117720309180);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, cr = cr + ms,
        ci = ci - ms, W = W + 8, MAKE_VOLATILE_STRIDE(40, rs)) {
      E TD, TH, TE, T1L, T1N, T1X, TG, T29, TI, T2b, T1V, T1O, T24, T36, T5b;
      E T1S, T1Y, T3b, T3e, T2o, T2Y, T2U, T31, T2s, T4y, T4u, T2f, T2c, T2g,
          T5g;
      E T2k, T1s, T48, T4c, T5q, T5m, T4k, T4f;
      {
        E T1r, T1M, T2T, T1R, T2X, T23, T2r, T1W, T2n, T2a, TF, T4x;
        TD = W[0];
        TH = W[3];
        TE = W[2];
        TF = TD * TE;
        T1r = TD * TH;
        T1L = W[6];
        T1M = TD * T1L;
        T2T = TE * T1L;
        T1N = W[7];
        T1R = TD * T1N;
        T2X = TE * T1N;
        T1X = W[5];
        T23 = TE * T1X;
        T2r = TD * T1X;
        TG = W[1];
        T29 = FNMS(TG, TH, TF);
        TI = FMA(TG, TH, TF);
        T2b = FMA(TG, TE, T1r);
        T1V = W[4];
        T1W = TE * T1V;
        T2n = TD * T1V;
        T2a = T29 * T1V;
        T1O = FMA(TG, T1N, T1M);
        T24 = FNMS(TH, T1V, T23);
        T36 = FNMS(TG, T1V, T2r);
        T5b = FNMS(T2b, T1X, T2a);
        T1S = FNMS(TG, T1L, T1R);
        T1Y = FMA(TH, T1X, T1W);
        T3b = FNMS(TH, T1X, T1W);
        T3e = FMA(TH, T1V, T23);
        T2o = FNMS(TG, T1X, T2n);
        T2Y = FNMS(TH, T1L, T2X);
        T2U = FMA(TH, T1N, T2T);
        T31 = FMA(TG, T1X, T2n);
        T2s = FMA(TG, T1V, T2r);
        T4x = T29 * T1N;
        T4y = FNMS(T2b, T1L, T4x);
        {
          E T4t, T2e, T2d, T2j;
          T4t = T29 * T1L;
          T4u = FMA(T2b, T1N, T4t);
          T2e = T29 * T1X;
          T2f = FNMS(T2b, T1V, T2e);
          T2c = FMA(T2b, T1X, T2a);
          T2d = T2c * T1L;
          T2j = T2c * T1N;
          T2g = FMA(T2f, T1N, T2d);
          T5g = FMA(T2b, T1V, T2e);
          T2k = FNMS(T2f, T1L, T2j);
          {
            E T47, T5p, T4b, T5l;
            T47 = TI * T1V;
            T5p = TI * T1N;
            T4b = TI * T1X;
            T5l = TI * T1L;
            T1s = FNMS(TG, TE, T1r);
            T48 = FMA(T1s, T1X, T47);
            T4c = FNMS(T1s, T1V, T4b);
            T5q = FNMS(T1s, T1L, T5p);
            T5m = FMA(T1s, T1N, T5l);
            T4k = FMA(T1s, T1V, T4b);
            T4f = FNMS(T1s, T1X, T47);
          }
        }
      }
      {
        E T7, T4B, T4V, TJ, T1z, T3j, T3V, T2H, T18, T42, T43, T1n, T2D, T53,
            T52;
        E T2A, T1H, T4R, T4O, T1G, T2O, T3I, T2P, T3P, T2I, T2J, T2K, T1A, T1B,
            T1C;
        E TC, T2w, T3Y, T40, T4I, T4K, TQ, TS, T3y, T3A, T4Y, T50;
        {
          E T3, T3h, T1y, T3i, T6, T3U, T1v, T3T;
          {
            E T1, T2, T1w, T1x;
            T1 = cr[0];
            T2 = ci[WS(rs, 9)];
            T3 = T1 + T2;
            T3h = T1 - T2;
            T1w = ci[WS(rs, 14)];
            T1x = cr[WS(rs, 15)];
            T1y = T1w - T1x;
            T3i = T1w + T1x;
          }
          {
            E T4, T5, T1t, T1u;
            T4 = cr[WS(rs, 5)];
            T5 = ci[WS(rs, 4)];
            T6 = T4 + T5;
            T3U = T4 - T5;
            T1t = ci[WS(rs, 19)];
            T1u = cr[WS(rs, 10)];
            T1v = T1t - T1u;
            T3T = T1t + T1u;
          }
          T7 = T3 + T6;
          T4B = T3h - T3i;
          T4V = T3U + T3T;
          TJ = T3 - T6;
          T1z = T1v - T1y;
          T3j = T3h + T3i;
          T3V = T3T - T3U;
          T2H = T1v + T1y;
        }
        {
          E Te, T4C, T4M, TK, T1f, T3m, T3L, T2y, TA, T4G, T4Q, TO, T17, T3w,
              T3H;
          E T2C, Tl, T4D, T4N, TL, T1m, T3p, T3O, T2z, Tt, T4F, T4P, TN, T10,
              T3t;
          E T3E, T2B;
          {
            E Ta, T3k, T1e, T3l, Td, T3K, T1b, T3J;
            {
              E T8, T9, T1c, T1d;
              T8 = cr[WS(rs, 4)];
              T9 = ci[WS(rs, 5)];
              Ta = T8 + T9;
              T3k = T8 - T9;
              T1c = ci[WS(rs, 10)];
              T1d = cr[WS(rs, 19)];
              T1e = T1c - T1d;
              T3l = T1c + T1d;
            }
            {
              E Tb, Tc, T19, T1a;
              Tb = cr[WS(rs, 9)];
              Tc = ci[0];
              Td = Tb + Tc;
              T3K = Tb - Tc;
              T19 = ci[WS(rs, 15)];
              T1a = cr[WS(rs, 14)];
              T1b = T19 - T1a;
              T3J = T19 + T1a;
            }
            Te = Ta + Td;
            T4C = T3k - T3l;
            T4M = T3K + T3J;
            TK = Ta - Td;
            T1f = T1b - T1e;
            T3m = T3k + T3l;
            T3L = T3J - T3K;
            T2y = T1b + T1e;
          }
          {
            E Tw, T3u, Tz, T3F, T13, T3G, T16, T3v;
            {
              E Tu, Tv, Tx, Ty;
              Tu = ci[WS(rs, 7)];
              Tv = cr[WS(rs, 2)];
              Tw = Tu + Tv;
              T3u = Tu - Tv;
              Tx = ci[WS(rs, 2)];
              Ty = cr[WS(rs, 7)];
              Tz = Tx + Ty;
              T3F = Tx - Ty;
            }
            {
              E T11, T12, T14, T15;
              T11 = ci[WS(rs, 17)];
              T12 = cr[WS(rs, 12)];
              T13 = T11 - T12;
              T3G = T11 + T12;
              T14 = ci[WS(rs, 12)];
              T15 = cr[WS(rs, 17)];
              T16 = T14 - T15;
              T3v = T14 + T15;
            }
            TA = Tw + Tz;
            T4G = T3u + T3v;
            T4Q = T3F - T3G;
            TO = Tw - Tz;
            T17 = T13 - T16;
            T3w = T3u - T3v;
            T3H = T3F + T3G;
            T2C = T13 + T16;
          }
          {
            E Th, T3n, T1l, T3o, Tk, T3M, T1i, T3N;
            {
              E Tf, Tg, T1j, T1k;
              Tf = ci[WS(rs, 3)];
              Tg = cr[WS(rs, 6)];
              Th = Tf + Tg;
              T3n = Tf - Tg;
              T1j = ci[WS(rs, 18)];
              T1k = cr[WS(rs, 11)];
              T1l = T1j - T1k;
              T3o = T1j + T1k;
            }
            {
              E Ti, Tj, T1g, T1h;
              Ti = cr[WS(rs, 1)];
              Tj = ci[WS(rs, 8)];
              Tk = Ti + Tj;
              T3M = Ti - Tj;
              T1g = ci[WS(rs, 13)];
              T1h = cr[WS(rs, 16)];
              T1i = T1g - T1h;
              T3N = T1g + T1h;
            }
            Tl = Th + Tk;
            T4D = T3n - T3o;
            T4N = T3M - T3N;
            TL = Th - Tk;
            T1m = T1i - T1l;
            T3p = T3n + T3o;
            T3O = T3M + T3N;
            T2z = T1i + T1l;
          }
          {
            E Tp, T3r, TZ, T3s, Ts, T3D, TW, T3C;
            {
              E Tn, To, TX, TY;
              Tn = cr[WS(rs, 8)];
              To = ci[WS(rs, 1)];
              Tp = Tn + To;
              T3r = Tn - To;
              TX = ci[WS(rs, 16)];
              TY = cr[WS(rs, 13)];
              TZ = TX - TY;
              T3s = TX + TY;
            }
            {
              E Tq, Tr, TU, TV;
              Tq = ci[WS(rs, 6)];
              Tr = cr[WS(rs, 3)];
              Ts = Tq + Tr;
              T3D = Tq - Tr;
              TU = ci[WS(rs, 11)];
              TV = cr[WS(rs, 18)];
              TW = TU - TV;
              T3C = TU + TV;
            }
            Tt = Tp + Ts;
            T4F = T3r + T3s;
            T4P = T3D + T3C;
            TN = Tp - Ts;
            T10 = TW - TZ;
            T3t = T3r - T3s;
            T3E = T3C - T3D;
            T2B = TW + TZ;
          }
          T18 = T10 - T17;
          T42 = T3t - T3w;
          T43 = T3m - T3p;
          T1n = T1f - T1m;
          T2D = T2B - T2C;
          T53 = T4F - T4G;
          T52 = T4C - T4D;
          T2A = T2y - T2z;
          T1H = TK - TL;
          T4R = T4P - T4Q;
          T4O = T4M - T4N;
          T1G = TN - TO;
          T2O = Te - Tl;
          T3I = T3E + T3H;
          T2P = Tt - TA;
          T3P = T3L + T3O;
          T2I = T2y + T2z;
          T2J = T2B + T2C;
          T2K = T2I + T2J;
          T1A = T1f + T1m;
          T1B = T10 + T17;
          T1C = T1A + T1B;
          {
            E Tm, TB, TM, TP;
            Tm = Te + Tl;
            TB = Tt + TA;
            TC = Tm + TB;
            T2w = Tm - TB;
            {
              E T3W, T3X, T4E, T4H;
              T3W = T3L - T3O;
              T3X = T3E - T3H;
              T3Y = T3W + T3X;
              T40 = T3W - T3X;
              T4E = T4C + T4D;
              T4H = T4F + T4G;
              T4I = T4E + T4H;
              T4K = T4E - T4H;
            }
            TM = TK + TL;
            TP = TN + TO;
            TQ = TM + TP;
            TS = TM - TP;
            {
              E T3q, T3x, T4W, T4X;
              T3q = T3m + T3p;
              T3x = T3t + T3w;
              T3y = T3q + T3x;
              T3A = T3q - T3x;
              T4W = T4M + T4N;
              T4X = T4P + T4Q;
              T4Y = T4W + T4X;
              T50 = T4W - T4X;
            }
          }
        }
        cr[0] = T7 + TC;
        ci[0] = T2H + T2K;
        {
          E T2t, T2q, T2u, T2p;
          T2t = T1z + T1C;
          T2p = TJ + TQ;
          T2q = T2o * T2p;
          T2u = T2s * T2p;
          cr[WS(rs, 10)] = FNMS(T2s, T2t, T2q);
          ci[WS(rs, 10)] = FMA(T2o, T2t, T2u);
        }
        {
          E T5t, T5u, T5v, T5w;
          T5t = T4B + T4I;
          T5u = T2c * T5t;
          T5v = T4V + T4Y;
          T5w = T2c * T5v;
          cr[WS(rs, 5)] = FNMS(T2f, T5v, T5u);
          ci[WS(rs, 5)] = FMA(T2f, T5t, T5w);
        }
        {
          E T4v, T4w, T4z, T4A;
          T4v = T3j + T3y;
          T4w = T4u * T4v;
          T4z = T3V + T3Y;
          T4A = T4u * T4z;
          cr[WS(rs, 15)] = FNMS(T4y, T4z, T4w);
          ci[WS(rs, 15)] = FMA(T4y, T4v, T4A);
        }
        {
          E T3R, T4p, T49, T4i, T45, T4r, T4d, T4n;
          {
            E T3Q, T4h, T3B, T4g, T3z;
            T3Q = FNMS(KP618033988, T3P, T3I);
            T4h = FMA(KP618033988, T3I, T3P);
            T3z = FNMS(KP250000000, T3y, T3j);
            T3B = FNMS(KP559016994, T3A, T3z);
            T4g = FMA(KP559016994, T3A, T3z);
            T3R = FNMS(KP951056516, T3Q, T3B);
            T4p = FMA(KP951056516, T4h, T4g);
            T49 = FMA(KP951056516, T3Q, T3B);
            T4i = FNMS(KP951056516, T4h, T4g);
          }
          {
            E T44, T4m, T41, T4l, T3Z;
            T44 = FNMS(KP618033988, T43, T42);
            T4m = FMA(KP618033988, T42, T43);
            T3Z = FNMS(KP250000000, T3Y, T3V);
            T41 = FNMS(KP559016994, T40, T3Z);
            T4l = FMA(KP559016994, T40, T3Z);
            T45 = FMA(KP951056516, T44, T41);
            T4r = FNMS(KP951056516, T4m, T4l);
            T4d = FNMS(KP951056516, T44, T41);
            T4n = FMA(KP951056516, T4m, T4l);
          }
          {
            E T3S, T46, T4a, T4e;
            T3S = TE * T3R;
            cr[WS(rs, 3)] = FNMS(TH, T45, T3S);
            T46 = TE * T45;
            ci[WS(rs, 3)] = FMA(TH, T3R, T46);
            T4a = T48 * T49;
            cr[WS(rs, 7)] = FNMS(T4c, T4d, T4a);
            T4e = T48 * T4d;
            ci[WS(rs, 7)] = FMA(T4c, T49, T4e);
          }
          {
            E T4j, T4o, T4q, T4s;
            T4j = T4f * T4i;
            cr[WS(rs, 11)] = FNMS(T4k, T4n, T4j);
            T4o = T4f * T4n;
            ci[WS(rs, 11)] = FMA(T4k, T4i, T4o);
            T4q = T1L * T4p;
            cr[WS(rs, 19)] = FNMS(T1N, T4r, T4q);
            T4s = T1L * T4r;
            ci[WS(rs, 19)] = FMA(T1N, T4p, T4s);
          }
        }
        {
          E T4T, T5n, T57, T5e, T55, T5r, T59, T5j;
          {
            E T4S, T5d, T4L, T5c, T4J;
            T4S = FMA(KP618033988, T4R, T4O);
            T5d = FNMS(KP618033988, T4O, T4R);
            T4J = FNMS(KP250000000, T4I, T4B);
            T4L = FMA(KP559016994, T4K, T4J);
            T5c = FNMS(KP559016994, T4K, T4J);
            T4T = FNMS(KP951056516, T4S, T4L);
            T5n = FMA(KP951056516, T5d, T5c);
            T57 = FMA(KP951056516, T4S, T4L);
            T5e = FNMS(KP951056516, T5d, T5c);
          }
          {
            E T54, T5i, T51, T5h, T4Z;
            T54 = FMA(KP618033988, T53, T52);
            T5i = FNMS(KP618033988, T52, T53);
            T4Z = FNMS(KP250000000, T4Y, T4V);
            T51 = FMA(KP559016994, T50, T4Z);
            T5h = FNMS(KP559016994, T50, T4Z);
            T55 = FMA(KP951056516, T54, T51);
            T5r = FNMS(KP951056516, T5i, T5h);
            T59 = FNMS(KP951056516, T54, T51);
            T5j = FMA(KP951056516, T5i, T5h);
          }
          {
            E T4U, T56, T58, T5a;
            T4U = TD * T4T;
            cr[WS(rs, 1)] = FNMS(TG, T55, T4U);
            T56 = TD * T55;
            ci[WS(rs, 1)] = FMA(TG, T4T, T56);
            T58 = T1V * T57;
            cr[WS(rs, 9)] = FNMS(T1X, T59, T58);
            T5a = T1V * T59;
            ci[WS(rs, 9)] = FMA(T1X, T57, T5a);
          }
          {
            E T5f, T5k, T5o, T5s;
            T5f = T5b * T5e;
            cr[WS(rs, 13)] = FNMS(T5g, T5j, T5f);
            T5k = T5b * T5j;
            ci[WS(rs, 13)] = FMA(T5g, T5e, T5k);
            T5o = T5m * T5n;
            cr[WS(rs, 17)] = FNMS(T5q, T5r, T5o);
            T5s = T5m * T5r;
            ci[WS(rs, 17)] = FMA(T5q, T5n, T5s);
          }
        }
        {
          E T2Q, T38, T2N, T37, T2F, T3c, T2V, T34, T2L, T2M;
          T2Q = FMA(KP618033988, T2P, T2O);
          T38 = FNMS(KP618033988, T2O, T2P);
          T2L = FNMS(KP250000000, T2K, T2H);
          T2M = T2I - T2J;
          T2N = FMA(KP559016994, T2M, T2L);
          T37 = FNMS(KP559016994, T2M, T2L);
          {
            E T2E, T33, T2x, T32, T2v;
            T2E = FMA(KP618033988, T2D, T2A);
            T33 = FNMS(KP618033988, T2A, T2D);
            T2v = FNMS(KP250000000, TC, T7);
            T2x = FMA(KP559016994, T2w, T2v);
            T32 = FNMS(KP559016994, T2w, T2v);
            T2F = FMA(KP951056516, T2E, T2x);
            T3c = FMA(KP951056516, T33, T32);
            T2V = FNMS(KP951056516, T2E, T2x);
            T34 = FNMS(KP951056516, T33, T32);
          }
          {
            E T2G, T2S, T2R, T3d, T3g, T3f;
            T2G = T29 * T2F;
            T2S = T2b * T2F;
            T2R = FNMS(KP951056516, T2Q, T2N);
            cr[WS(rs, 4)] = FNMS(T2b, T2R, T2G);
            ci[WS(rs, 4)] = FMA(T29, T2R, T2S);
            T3d = T3b * T3c;
            T3g = T3e * T3c;
            T3f = FNMS(KP951056516, T38, T37);
            cr[WS(rs, 12)] = FNMS(T3e, T3f, T3d);
            ci[WS(rs, 12)] = FMA(T3b, T3f, T3g);
          }
          {
            E T2W, T30, T2Z, T35, T3a, T39;
            T2W = T2U * T2V;
            T30 = T2Y * T2V;
            T2Z = FMA(KP951056516, T2Q, T2N);
            cr[WS(rs, 16)] = FNMS(T2Y, T2Z, T2W);
            ci[WS(rs, 16)] = FMA(T2U, T2Z, T30);
            T35 = T31 * T34;
            T3a = T36 * T34;
            T39 = FMA(KP951056516, T38, T37);
            cr[WS(rs, 8)] = FNMS(T36, T39, T35);
            ci[WS(rs, 8)] = FMA(T31, T39, T3a);
          }
        }
        {
          E T1I, T26, T1F, T25, T1p, T2h, T1P, T21, T1D, T1E;
          T1I = FNMS(KP618033988, T1H, T1G);
          T26 = FMA(KP618033988, T1G, T1H);
          T1D = FNMS(KP250000000, T1C, T1z);
          T1E = T1A - T1B;
          T1F = FNMS(KP559016994, T1E, T1D);
          T25 = FMA(KP559016994, T1E, T1D);
          {
            E T1o, T20, TT, T1Z, TR;
            T1o = FNMS(KP618033988, T1n, T18);
            T20 = FMA(KP618033988, T18, T1n);
            TR = FNMS(KP250000000, TQ, TJ);
            TT = FNMS(KP559016994, TS, TR);
            T1Z = FMA(KP559016994, TS, TR);
            T1p = FMA(KP951056516, T1o, TT);
            T2h = FMA(KP951056516, T20, T1Z);
            T1P = FNMS(KP951056516, T1o, TT);
            T21 = FNMS(KP951056516, T20, T1Z);
          }
          {
            E T1q, T1K, T1J, T2i, T2m, T2l;
            T1q = TI * T1p;
            T1K = T1s * T1p;
            T1J = FNMS(KP951056516, T1I, T1F);
            cr[WS(rs, 2)] = FNMS(T1s, T1J, T1q);
            ci[WS(rs, 2)] = FMA(TI, T1J, T1K);
            T2i = T2g * T2h;
            T2m = T2k * T2h;
            T2l = FNMS(KP951056516, T26, T25);
            cr[WS(rs, 14)] = FNMS(T2k, T2l, T2i);
            ci[WS(rs, 14)] = FMA(T2g, T2l, T2m);
          }
          {
            E T1Q, T1U, T1T, T22, T28, T27;
            T1Q = T1O * T1P;
            T1U = T1S * T1P;
            T1T = FMA(KP951056516, T1I, T1F);
            cr[WS(rs, 18)] = FNMS(T1S, T1T, T1Q);
            ci[WS(rs, 18)] = FMA(T1O, T1T, T1U);
            T22 = T1Y * T21;
            T28 = T24 * T21;
            T27 = FMA(KP951056516, T26, T25);
            cr[WS(rs, 6)] = FNMS(T24, T27, T22);
            ci[WS(rs, 6)] = FMA(T1Y, T27, T28);
          }
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_CEXP, 1, 1},
                                   {TW_CEXP, 1, 3},
                                   {TW_CEXP, 1, 9},
                                   {TW_CEXP, 1, 19},
                                   {TW_NEXT, 1, 0}};

static const hc2hc_desc desc = {
    20, "hb2_20", twinstr, &GENUS, {136, 58, 140, 0}};

void X(codelet_hb2_20)(planner *p) { X(khc2hc_register)(p, hb2_20, &desc); }
#else

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4
 * -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 20 -dif
 * -name hb2_20 -include rdft/scalar/hb.h */

/*
 * This function contains 276 FP additions, 164 FP multiplications,
 * (or, 204 additions, 92 multiplications, 72 fused multiply/add),
 * 137 stack variables, 4 constants, and 80 memory accesses
 */
#include "rdft/scalar/hb.h"

static void hb2_20(R *cr, R *ci, const R *W, stride rs, INT mb, INT me,
                   INT ms) {
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP587785252, +0.587785252292473129168705954639072768597652438);
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, cr = cr + ms,
        ci = ci - ms, W = W + 8, MAKE_VOLATILE_STRIDE(40, rs)) {
      E TD, TG, TE, TH, TJ, T1t, T27, T25, T1T, T1R, T1V, T2j, T2Z, T21, T2X;
      E T2T, T2n, T2P, T3V, T41, T3R, T3X, T29, T2c, T4H, T4L, T1L, T1M, T1N,
          T2d;
      E T4R, T1P, T4P, T49, T2N, T2f, T47, T2L;
      {
        E T1U, T2l, T1Z, T2i, T1S, T2m, T20, T2h;
        {
          E TF, T1s, TI, T1r;
          TD = W[0];
          TG = W[1];
          TE = W[2];
          TH = W[3];
          TF = TD * TE;
          T1s = TG * TE;
          TI = TG * TH;
          T1r = TD * TH;
          TJ = TF + TI;
          T1t = T1r - T1s;
          T27 = T1r + T1s;
          T25 = TF - TI;
          T1T = W[5];
          T1U = TH * T1T;
          T2l = TD * T1T;
          T1Z = TE * T1T;
          T2i = TG * T1T;
          T1R = W[4];
          T1S = TE * T1R;
          T2m = TG * T1R;
          T20 = TH * T1R;
          T2h = TD * T1R;
        }
        T1V = T1S + T1U;
        T2j = T2h - T2i;
        T2Z = T1Z + T20;
        T21 = T1Z - T20;
        T2X = T1S - T1U;
        T2T = T2l - T2m;
        T2n = T2l + T2m;
        T2P = T2h + T2i;
        {
          E T3T, T3U, T3P, T3Q;
          T3T = TJ * T1T;
          T3U = T1t * T1R;
          T3V = T3T - T3U;
          T41 = T3T + T3U;
          T3P = TJ * T1R;
          T3Q = T1t * T1T;
          T3R = T3P + T3Q;
          T3X = T3P - T3Q;
          {
            E T26, T28, T2a, T2b;
            T26 = T25 * T1R;
            T28 = T27 * T1T;
            T29 = T26 + T28;
            T2a = T25 * T1T;
            T2b = T27 * T1R;
            T2c = T2a - T2b;
            T4H = T26 - T28;
            T4L = T2a + T2b;
            T1L = W[6];
            T1M = W[7];
            T1N = FMA(TD, T1L, TG * T1M);
            T2d = FMA(T29, T1L, T2c * T1M);
            T4R = FNMS(T1t, T1L, TJ * T1M);
            T1P = FNMS(TG, T1L, TD * T1M);
            T4P = FMA(TJ, T1L, T1t * T1M);
            T49 = FNMS(T27, T1L, T25 * T1M);
            T2N = FNMS(TH, T1L, TE * T1M);
            T2f = FNMS(T2c, T1L, T29 * T1M);
            T47 = FMA(T25, T1L, T27 * T1M);
            T2L = FMA(TE, T1L, TH * T1M);
          }
        }
      }
      {
        E T7, T4i, T4x, TK, T1D, T3i, T3E, T2D, T19, T3L, T3M, T1o, T2x, T4C,
            T4B;
        E T2u, T1v, T4r, T4o, T1u, T2H, T37, T2I, T3e, T3p, T3w, T3x, Tm, TB,
            TC;
        E T4u, T4v, T4y, T2A, T2B, T2E, T1E, T1F, T1G, T4d, T4g, T4j, T3F, T3G,
            T3H;
        E TN, TQ, TR, T48, T4a;
        {
          E T3, T3g, T1C, T3h, T6, T3D, T1z, T3C;
          {
            E T1, T2, T1A, T1B;
            T1 = cr[0];
            T2 = ci[WS(rs, 9)];
            T3 = T1 + T2;
            T3g = T1 - T2;
            T1A = ci[WS(rs, 14)];
            T1B = cr[WS(rs, 15)];
            T1C = T1A - T1B;
            T3h = T1A + T1B;
          }
          {
            E T4, T5, T1x, T1y;
            T4 = cr[WS(rs, 5)];
            T5 = ci[WS(rs, 4)];
            T6 = T4 + T5;
            T3D = T4 - T5;
            T1x = ci[WS(rs, 19)];
            T1y = cr[WS(rs, 10)];
            T1z = T1x - T1y;
            T3C = T1x + T1y;
          }
          T7 = T3 + T6;
          T4i = T3g - T3h;
          T4x = T3D + T3C;
          TK = T3 - T6;
          T1D = T1z - T1C;
          T3i = T3g + T3h;
          T3E = T3C - T3D;
          T2D = T1z + T1C;
        }
        {
          E Te, T4b, T4m, TL, T11, T33, T3l, T2s, TA, T4f, T4q, TP, T1n, T3d,
              T3v;
          E T2w, Tl, T4c, T4n, TM, T18, T36, T3o, T2t, Tt, T4e, T4p, TO, T1g,
              T3a;
          E T3s, T2v;
          {
            E Ta, T3j, T10, T3k, Td, T32, TX, T31;
            {
              E T8, T9, TY, TZ;
              T8 = cr[WS(rs, 4)];
              T9 = ci[WS(rs, 5)];
              Ta = T8 + T9;
              T3j = T8 - T9;
              TY = ci[WS(rs, 10)];
              TZ = cr[WS(rs, 19)];
              T10 = TY - TZ;
              T3k = TY + TZ;
            }
            {
              E Tb, Tc, TV, TW;
              Tb = cr[WS(rs, 9)];
              Tc = ci[0];
              Td = Tb + Tc;
              T32 = Tb - Tc;
              TV = ci[WS(rs, 15)];
              TW = cr[WS(rs, 14)];
              TX = TV - TW;
              T31 = TV + TW;
            }
            Te = Ta + Td;
            T4b = T3j - T3k;
            T4m = T32 + T31;
            TL = Ta - Td;
            T11 = TX - T10;
            T33 = T31 - T32;
            T3l = T3j + T3k;
            T2s = TX + T10;
          }
          {
            E Tw, T3t, Tz, T3b, T1j, T3c, T1m, T3u;
            {
              E Tu, Tv, Tx, Ty;
              Tu = ci[WS(rs, 7)];
              Tv = cr[WS(rs, 2)];
              Tw = Tu + Tv;
              T3t = Tu - Tv;
              Tx = ci[WS(rs, 2)];
              Ty = cr[WS(rs, 7)];
              Tz = Tx + Ty;
              T3b = Tx - Ty;
            }
            {
              E T1h, T1i, T1k, T1l;
              T1h = ci[WS(rs, 17)];
              T1i = cr[WS(rs, 12)];
              T1j = T1h - T1i;
              T3c = T1h + T1i;
              T1k = ci[WS(rs, 12)];
              T1l = cr[WS(rs, 17)];
              T1m = T1k - T1l;
              T3u = T1k + T1l;
            }
            TA = Tw + Tz;
            T4f = T3t + T3u;
            T4q = T3b - T3c;
            TP = Tw - Tz;
            T1n = T1j - T1m;
            T3d = T3b + T3c;
            T3v = T3t - T3u;
            T2w = T1j + T1m;
          }
          {
            E Th, T3m, T17, T3n, Tk, T34, T14, T35;
            {
              E Tf, Tg, T15, T16;
              Tf = ci[WS(rs, 3)];
              Tg = cr[WS(rs, 6)];
              Th = Tf + Tg;
              T3m = Tf - Tg;
              T15 = ci[WS(rs, 18)];
              T16 = cr[WS(rs, 11)];
              T17 = T15 - T16;
              T3n = T15 + T16;
            }
            {
              E Ti, Tj, T12, T13;
              Ti = cr[WS(rs, 1)];
              Tj = ci[WS(rs, 8)];
              Tk = Ti + Tj;
              T34 = Ti - Tj;
              T12 = ci[WS(rs, 13)];
              T13 = cr[WS(rs, 16)];
              T14 = T12 - T13;
              T35 = T12 + T13;
            }
            Tl = Th + Tk;
            T4c = T3m - T3n;
            T4n = T34 - T35;
            TM = Th - Tk;
            T18 = T14 - T17;
            T36 = T34 + T35;
            T3o = T3m + T3n;
            T2t = T14 + T17;
          }
          {
            E Tp, T3q, T1f, T3r, Ts, T39, T1c, T38;
            {
              E Tn, To, T1d, T1e;
              Tn = cr[WS(rs, 8)];
              To = ci[WS(rs, 1)];
              Tp = Tn + To;
              T3q = Tn - To;
              T1d = ci[WS(rs, 16)];
              T1e = cr[WS(rs, 13)];
              T1f = T1d - T1e;
              T3r = T1d + T1e;
            }
            {
              E Tq, Tr, T1a, T1b;
              Tq = ci[WS(rs, 6)];
              Tr = cr[WS(rs, 3)];
              Ts = Tq + Tr;
              T39 = Tq - Tr;
              T1a = ci[WS(rs, 11)];
              T1b = cr[WS(rs, 18)];
              T1c = T1a - T1b;
              T38 = T1a + T1b;
            }
            Tt = Tp + Ts;
            T4e = T3q + T3r;
            T4p = T39 + T38;
            TO = Tp - Ts;
            T1g = T1c - T1f;
            T3a = T38 - T39;
            T3s = T3q - T3r;
            T2v = T1c + T1f;
          }
          T19 = T11 - T18;
          T3L = T3l - T3o;
          T3M = T3s - T3v;
          T1o = T1g - T1n;
          T2x = T2v - T2w;
          T4C = T4e - T4f;
          T4B = T4b - T4c;
          T2u = T2s - T2t;
          T1v = TO - TP;
          T4r = T4p - T4q;
          T4o = T4m - T4n;
          T1u = TL - TM;
          T2H = Te - Tl;
          T37 = T33 + T36;
          T2I = Tt - TA;
          T3e = T3a + T3d;
          T3p = T3l + T3o;
          T3w = T3s + T3v;
          T3x = T3p + T3w;
          Tm = Te + Tl;
          TB = Tt + TA;
          TC = Tm + TB;
          T4u = T4m + T4n;
          T4v = T4p + T4q;
          T4y = T4u + T4v;
          T2A = T2s + T2t;
          T2B = T2v + T2w;
          T2E = T2A + T2B;
          T1E = T11 + T18;
          T1F = T1g + T1n;
          T1G = T1E + T1F;
          T4d = T4b + T4c;
          T4g = T4e + T4f;
          T4j = T4d + T4g;
          T3F = T33 - T36;
          T3G = T3a - T3d;
          T3H = T3F + T3G;
          TN = TL + TM;
          TQ = TO + TP;
          TR = TN + TQ;
        }
        cr[0] = T7 + TC;
        ci[0] = T2D + T2E;
        {
          E T2k, T2o, T4T, T4U;
          T2k = TK + TR;
          T2o = T1D + T1G;
          cr[WS(rs, 10)] = FNMS(T2n, T2o, T2j * T2k);
          ci[WS(rs, 10)] = FMA(T2n, T2k, T2j * T2o);
          T4T = T4i + T4j;
          T4U = T4x + T4y;
          cr[WS(rs, 5)] = FNMS(T2c, T4U, T29 * T4T);
          ci[WS(rs, 5)] = FMA(T29, T4U, T2c * T4T);
        }
        T48 = T3i + T3x;
        T4a = T3E + T3H;
        cr[WS(rs, 15)] = FNMS(T49, T4a, T47 * T48);
        ci[WS(rs, 15)] = FMA(T47, T4a, T49 * T48);
        {
          E T2y, T2J, T2V, T2R, T2G, T2U, T2r, T2Q;
          T2y = FMA(KP951056516, T2u, KP587785252 * T2x);
          T2J = FMA(KP951056516, T2H, KP587785252 * T2I);
          T2V = FNMS(KP951056516, T2I, KP587785252 * T2H);
          T2R = FNMS(KP951056516, T2x, KP587785252 * T2u);
          {
            E T2C, T2F, T2p, T2q;
            T2C = KP559016994 * (T2A - T2B);
            T2F = FNMS(KP250000000, T2E, T2D);
            T2G = T2C + T2F;
            T2U = T2F - T2C;
            T2p = KP559016994 * (Tm - TB);
            T2q = FNMS(KP250000000, TC, T7);
            T2r = T2p + T2q;
            T2Q = T2q - T2p;
          }
          {
            E T2z, T2K, T2Y, T30;
            T2z = T2r + T2y;
            T2K = T2G - T2J;
            cr[WS(rs, 4)] = FNMS(T27, T2K, T25 * T2z);
            ci[WS(rs, 4)] = FMA(T27, T2z, T25 * T2K);
            T2Y = T2Q - T2R;
            T30 = T2V + T2U;
            cr[WS(rs, 12)] = FNMS(T2Z, T30, T2X * T2Y);
            ci[WS(rs, 12)] = FMA(T2Z, T2Y, T2X * T30);
          }
          {
            E T2M, T2O, T2S, T2W;
            T2M = T2r - T2y;
            T2O = T2J + T2G;
            cr[WS(rs, 16)] = FNMS(T2N, T2O, T2L * T2M);
            ci[WS(rs, 16)] = FMA(T2N, T2M, T2L * T2O);
            T2S = T2Q + T2R;
            T2W = T2U - T2V;
            cr[WS(rs, 8)] = FNMS(T2T, T2W, T2P * T2S);
            ci[WS(rs, 8)] = FMA(T2T, T2S, T2P * T2W);
          }
        }
        {
          E T4s, T4D, T4N, T4I, T4A, T4M, T4l, T4J;
          T4s = FMA(KP951056516, T4o, KP587785252 * T4r);
          T4D = FMA(KP951056516, T4B, KP587785252 * T4C);
          T4N = FNMS(KP951056516, T4C, KP587785252 * T4B);
          T4I = FNMS(KP951056516, T4r, KP587785252 * T4o);
          {
            E T4w, T4z, T4h, T4k;
            T4w = KP559016994 * (T4u - T4v);
            T4z = FNMS(KP250000000, T4y, T4x);
            T4A = T4w + T4z;
            T4M = T4z - T4w;
            T4h = KP559016994 * (T4d - T4g);
            T4k = FNMS(KP250000000, T4j, T4i);
            T4l = T4h + T4k;
            T4J = T4k - T4h;
          }
          {
            E T4t, T4E, T4Q, T4S;
            T4t = T4l - T4s;
            T4E = T4A + T4D;
            cr[WS(rs, 1)] = FNMS(TG, T4E, TD * T4t);
            ci[WS(rs, 1)] = FMA(TD, T4E, TG * T4t);
            T4Q = T4J - T4I;
            T4S = T4M + T4N;
            cr[WS(rs, 17)] = FNMS(T4R, T4S, T4P * T4Q);
            ci[WS(rs, 17)] = FMA(T4P, T4S, T4R * T4Q);
          }
          {
            E T4F, T4G, T4K, T4O;
            T4F = T4s + T4l;
            T4G = T4A - T4D;
            cr[WS(rs, 9)] = FNMS(T1T, T4G, T1R * T4F);
            ci[WS(rs, 9)] = FMA(T1R, T4G, T1T * T4F);
            T4K = T4I + T4J;
            T4O = T4M - T4N;
            cr[WS(rs, 13)] = FNMS(T4L, T4O, T4H * T4K);
            ci[WS(rs, 13)] = FMA(T4H, T4O, T4L * T4K);
          }
        }
        {
          E T1p, T1w, T22, T1X, T1J, T23, TU, T1W;
          T1p = FNMS(KP951056516, T1o, KP587785252 * T19);
          T1w = FNMS(KP951056516, T1v, KP587785252 * T1u);
          T22 = FMA(KP951056516, T1u, KP587785252 * T1v);
          T1X = FMA(KP951056516, T19, KP587785252 * T1o);
          {
            E T1H, T1I, TS, TT;
            T1H = FNMS(KP250000000, T1G, T1D);
            T1I = KP559016994 * (T1E - T1F);
            T1J = T1H - T1I;
            T23 = T1I + T1H;
            TS = FNMS(KP250000000, TR, TK);
            TT = KP559016994 * (TN - TQ);
            TU = TS - TT;
            T1W = TT + TS;
          }
          {
            E T1q, T1K, T2e, T2g;
            T1q = TU - T1p;
            T1K = T1w + T1J;
            cr[WS(rs, 2)] = FNMS(T1t, T1K, TJ * T1q);
            ci[WS(rs, 2)] = FMA(T1t, T1q, TJ * T1K);
            T2e = T1W + T1X;
            T2g = T23 - T22;
            cr[WS(rs, 14)] = FNMS(T2f, T2g, T2d * T2e);
            ci[WS(rs, 14)] = FMA(T2f, T2e, T2d * T2g);
          }
          {
            E T1O, T1Q, T1Y, T24;
            T1O = TU + T1p;
            T1Q = T1J - T1w;
            cr[WS(rs, 18)] = FNMS(T1P, T1Q, T1N * T1O);
            ci[WS(rs, 18)] = FMA(T1P, T1O, T1N * T1Q);
            T1Y = T1W - T1X;
            T24 = T22 + T23;
            cr[WS(rs, 6)] = FNMS(T21, T24, T1V * T1Y);
            ci[WS(rs, 6)] = FMA(T21, T1Y, T1V * T24);
          }
        }
        {
          E T3f, T3N, T43, T3Z, T3K, T42, T3A, T3Y;
          T3f = FNMS(KP951056516, T3e, KP587785252 * T37);
          T3N = FNMS(KP951056516, T3M, KP587785252 * T3L);
          T43 = FMA(KP951056516, T3L, KP587785252 * T3M);
          T3Z = FMA(KP951056516, T37, KP587785252 * T3e);
          {
            E T3I, T3J, T3y, T3z;
            T3I = FNMS(KP250000000, T3H, T3E);
            T3J = KP559016994 * (T3F - T3G);
            T3K = T3I - T3J;
            T42 = T3J + T3I;
            T3y = FNMS(KP250000000, T3x, T3i);
            T3z = KP559016994 * (T3p - T3w);
            T3A = T3y - T3z;
            T3Y = T3z + T3y;
          }
          {
            E T3B, T3O, T45, T46;
            T3B = T3f + T3A;
            T3O = T3K - T3N;
            cr[WS(rs, 3)] = FNMS(TH, T3O, TE * T3B);
            ci[WS(rs, 3)] = FMA(TE, T3O, TH * T3B);
            T45 = T3Z + T3Y;
            T46 = T42 - T43;
            cr[WS(rs, 19)] = FNMS(T1M, T46, T1L * T45);
            ci[WS(rs, 19)] = FMA(T1L, T46, T1M * T45);
          }
          {
            E T3S, T3W, T40, T44;
            T3S = T3A - T3f;
            T3W = T3K + T3N;
            cr[WS(rs, 7)] = FNMS(T3V, T3W, T3R * T3S);
            ci[WS(rs, 7)] = FMA(T3R, T3W, T3V * T3S);
            T40 = T3Y - T3Z;
            T44 = T42 + T43;
            cr[WS(rs, 11)] = FNMS(T41, T44, T3X * T40);
            ci[WS(rs, 11)] = FMA(T3X, T44, T41 * T40);
          }
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_CEXP, 1, 1},
                                   {TW_CEXP, 1, 3},
                                   {TW_CEXP, 1, 9},
                                   {TW_CEXP, 1, 19},
                                   {TW_NEXT, 1, 0}};

static const hc2hc_desc desc = {
    20, "hb2_20", twinstr, &GENUS, {204, 92, 72, 0}};

void X(codelet_hb2_20)(planner *p) { X(khc2hc_register)(p, hb2_20, &desc); }
#endif
