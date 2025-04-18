// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ hw_top__DOT__clk;
    CData/*0:0*/ hw_top__DOT__rst;
    CData/*0:0*/ hw_top__DOT__start;
    CData/*0:0*/ hw_top__DOT__done;
    CData/*0:0*/ hw_top__DOT__busy;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(burst_len,9,0);
    SData/*9:0*/ hw_top__DOT__burst_len;
    SData/*9:0*/ hw_top__DOT__index;
    SData/*15:0*/ hw_top__DOT__a_val;
    SData/*15:0*/ hw_top__DOT__b_val;
    VL_INW(a_in_flat,16383,0,512);
    VL_INW(b_in_flat,16383,0,512);
    VL_OUTW(sum_out_flat,16383,0,512);
    VL_OUTW(product_out_flat,16383,0,512);
    VlWide<512>/*16383:0*/ hw_top__DOT__a_in_flat;
    VlWide<512>/*16383:0*/ hw_top__DOT__b_in_flat;
    VlWide<512>/*16383:0*/ hw_top__DOT__sum_out_flat;
    VlWide<512>/*16383:0*/ hw_top__DOT__product_out_flat;
    IData/*31:0*/ hw_top__DOT__i;
    IData/*31:0*/ hw_top__DOT__full_product;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 1024> hw_top__DOT__sum_reg;
    VlUnpacked<SData/*15:0*/, 1024> hw_top__DOT__product_reg;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ hw_top__DOT__WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ hw_top__DOT__FRAC = 8U;
    static constexpr IData/*31:0*/ hw_top__DOT__MAX_N = 0x00000400U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
