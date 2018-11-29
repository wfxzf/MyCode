`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/31 23:10:16
// Design Name: 
// Module Name: mux
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


module mux(a0,a1,a2,a3,a4,a5,a6,a7,s,out);
parameter k=7;
input [k-1:0] a0,a1,a2,a3,a4,a5,a6,a7;
input [7:0] s;
output [k-1:0] out;
assign out=({k{s[0]}}&a0)|({k{s[1]}}&a1)|({k{s[1]}}&a1)|({k{s[2]}}&a2)|({k{s[3]}}&a3)|({k{s[4]}}&a4)|({k{s[5]}}&a5)|({k{s[6]}}&a6)|({k{s[7]}}&a7);

endmodule
