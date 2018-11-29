`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/01 00:26:40
// Design Name: 
// Module Name: mux_case
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module mux_case(  a0,a1,a2,a3,a4,a5,a6,a7,s,out);
    input [6:0] a0,a1,a2,a3,a4,a5,a6,a7;
       input [7:0] s;
       output [6:0] out;
       reg [6:0] out;
    always@(*) begin
        case(s)
            8'b00000001: out = a0;
            8'b00000010: out = a1;
            8'b00000100: out = a2;
            8'b00001000: out = a3;
            8'b00010000: out = a4;
            8'b00100000: out = a5;
            8'b01000000: out = a6;
            8'b10000000: out = a7;
            default: out = {7{1'bx}};
        endcase
     end        
endmodule
