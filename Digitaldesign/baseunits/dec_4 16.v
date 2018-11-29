`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/01 14:12:41
// Design Name: 
// Module Name: dec_6_64
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


module dec_4_16(in,out);
    input [3:0] in;
    output [15:0] out;
    wire [3:0] x,y;
    
    decoder decoder_4_16 (in[1:0],x);
    decoder decoder1_4_16 (in[3:2],y);
    
    assign out[3:0] = x&{4{y[0]}};
    assign out[7:4] = x&{4{y[1]}};
    assign out[11:8] = x&{4{y[2]}};
    assign out[15:12] = x&{4{y[3]}};
    
endmodule
