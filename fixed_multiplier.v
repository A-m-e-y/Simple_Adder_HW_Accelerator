module fixed_multiplier #(
    parameter WIDTH = 16,
    parameter FRAC  = 8
) (
    input  [WIDTH-1:0] a,
    input  [WIDTH-1:0] b,
    output [WIDTH-1:0] product
);
    wire [2*WIDTH-1:0] raw_product;
    
    assign raw_product = a * b;
    assign product = raw_product[FRAC +: WIDTH];  // Scaled Qm.n result

endmodule
