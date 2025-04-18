module fixed_arith (
    input  logic [15:0] a,   // Q8.8 fixed-point
    input  logic [15:0] b,   // Q8.8 fixed-point
    output logic [15:0] sum, // Q8.8
    output logic [15:0] product // Q8.8
);
    assign sum     = a + b;

    logic [31:0] raw_product;
    assign raw_product = a * b;         // Q8.8 * Q8.8 = Q16.16
    assign product = raw_product[23:8]; // Convert back to Q8.8
endmodule
