`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/31 23:52:30
// Design Name: 
// Module Name: encoder
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


module encoder(in,out);
  input [7:0] in;
  output [2:0] out;
  reg [2:0] out;
  always @(in) 
  begin
    case(in)
    8'b00000001:out=3'b000;
    8'b00000010:out=3'b001;
    8'b00000100:out=3'b010;
    8'b00001000:out=3'b011;
    8'b00010000:out=3'b100;
    8'b00100000:out=3'b101;
    8'b01000000:out=3'b110;
    8'b10000000:out=3'b111;
    default:out=3'bxxx;
    endcase
    end
endmodule
