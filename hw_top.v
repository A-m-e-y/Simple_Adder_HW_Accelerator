module hw_top #(
    parameter WIDTH = 16,
    parameter FRAC  = 8,
    parameter MAX_N = 1024
)(
    input                      clk,
    input                      rst,
    input                      start,
    input  [9:0]              burst_len,  // Runtime burst length
    input  [WIDTH*MAX_N-1:0]   a_in_flat,
    input  [WIDTH*MAX_N-1:0]   b_in_flat,
    output [WIDTH*MAX_N-1:0]   sum_out_flat,
    output [WIDTH*MAX_N-1:0]   product_out_flat,
    output                     done
);

    reg [WIDTH-1:0] sum_reg     [0:MAX_N-1];
    reg [WIDTH-1:0] product_reg [0:MAX_N-1];
    reg [9:0]      index;
    reg             busy;
    integer         i;

    reg [WIDTH-1:0] a_val;
    reg [WIDTH-1:0] b_val;
    reg [2*WIDTH-1:0] full_product;

    assign done = (index == burst_len) && (busy == 0);

    // Flatten outputs
    genvar j;
    generate
        for (j = 0; j < MAX_N; j = j + 1) begin : OUT_MAP
            assign sum_out_flat[WIDTH*j +: WIDTH]     = sum_reg[j];
            assign product_out_flat[WIDTH*j +: WIDTH] = product_reg[j];
        end
    endgenerate

    // Input unpacking using case block
    always @(*) begin
        case (index)
            default: begin
                a_val = a_in_flat[WIDTH*index +: WIDTH];
                b_val = b_in_flat[WIDTH*index +: WIDTH];
            end
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            index <= 0;
            busy <= 0;
            for (i = 0; i < MAX_N; i = i + 1) begin
                sum_reg[i]     = 0;
                product_reg[i] = 0;
            end
        end else if (start) begin
            index <= 0;
            busy <= 1;
        end else if (busy) begin
            sum_reg[index] = a_val + b_val;
            full_product = a_val * b_val;
            product_reg[index] = full_product[FRAC +: WIDTH];
            index <= index + 1;
            if (index == burst_len - 1)
                busy <= 0;
        end
    end

endmodule
