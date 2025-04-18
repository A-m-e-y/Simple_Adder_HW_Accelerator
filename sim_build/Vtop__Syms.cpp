// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_hw_top);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_hw_top.configure(this, name(), "hw_top", "hw_top", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_hw_top);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"a_in_flat", &(TOP.a_in_flat), false, VLVT_WDATA,VLVD_IN|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_TOP.varInsert(__Vfinal,"b_in_flat", &(TOP.b_in_flat), false, VLVT_WDATA,VLVD_IN|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_TOP.varInsert(__Vfinal,"burst_len", &(TOP.burst_len), false, VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,1 ,9,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"done", &(TOP.done), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"product_out_flat", &(TOP.product_out_flat), false, VLVT_WDATA,VLVD_OUT|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"start", &(TOP.start), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"sum_out_flat", &(TOP.sum_out_flat), false, VLVT_WDATA,VLVD_OUT|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_hw_top.varInsert(__Vfinal,"FRAC", const_cast<void*>(static_cast<const void*>(&(TOP.hw_top__DOT__FRAC))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_hw_top.varInsert(__Vfinal,"MAX_N", const_cast<void*>(static_cast<const void*>(&(TOP.hw_top__DOT__MAX_N))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_hw_top.varInsert(__Vfinal,"WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.hw_top__DOT__WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_hw_top.varInsert(__Vfinal,"a_in_flat", &(TOP.hw_top__DOT__a_in_flat), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_hw_top.varInsert(__Vfinal,"a_val", &(TOP.hw_top__DOT__a_val), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_hw_top.varInsert(__Vfinal,"b_in_flat", &(TOP.hw_top__DOT__b_in_flat), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_hw_top.varInsert(__Vfinal,"b_val", &(TOP.hw_top__DOT__b_val), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_hw_top.varInsert(__Vfinal,"burst_len", &(TOP.hw_top__DOT__burst_len), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,9,0);
        __Vscope_hw_top.varInsert(__Vfinal,"busy", &(TOP.hw_top__DOT__busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_hw_top.varInsert(__Vfinal,"clk", &(TOP.hw_top__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_hw_top.varInsert(__Vfinal,"done", &(TOP.hw_top__DOT__done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_hw_top.varInsert(__Vfinal,"full_product", &(TOP.hw_top__DOT__full_product), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_hw_top.varInsert(__Vfinal,"i", &(TOP.hw_top__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_hw_top.varInsert(__Vfinal,"index", &(TOP.hw_top__DOT__index), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,9,0);
        __Vscope_hw_top.varInsert(__Vfinal,"product_out_flat", &(TOP.hw_top__DOT__product_out_flat), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_hw_top.varInsert(__Vfinal,"product_reg", &(TOP.hw_top__DOT__product_reg), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,2 ,15,0 ,0,1023);
        __Vscope_hw_top.varInsert(__Vfinal,"rst", &(TOP.hw_top__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_hw_top.varInsert(__Vfinal,"start", &(TOP.hw_top__DOT__start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_hw_top.varInsert(__Vfinal,"sum_out_flat", &(TOP.hw_top__DOT__sum_out_flat), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,1 ,16383,0);
        __Vscope_hw_top.varInsert(__Vfinal,"sum_reg", &(TOP.hw_top__DOT__sum_reg), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,2 ,15,0 ,0,1023);
    }
}
