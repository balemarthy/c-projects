# code-ayana
Daily dose of porgramming

17-August-2020

Simple GET-SET protocol

The process of communication between devices is a very common operation from small embedded devices to large networks.
The communication is as reliable and robust as the underlying protocols that carry the information between the devices.

The objective of this small code is to create a minimalistic protocol to either SET a value or GET a value during the
communication process.

Common terminology is DCE - Data Communication Equipment ; DTE - Data Terminal Equipment.

The current protocol is agnostic and is designed with the view that the device can be either DCE or DTE at various
points of time.

GET and SET are two operational code. The protocol has no layering and the complete information is present in every
packet that is exchanged between devices.


The packet format is as below
       |SOF| OPCODE| TYPE| LENGTH |VALUE | CHECKSUM |
              
 SOF - Start of Frame, which is a '$' character. If the data also contains '$' then that character is preceded by a '/'

 OPCODE - The opcode can be either a GET or SET
 
 TYPE   - The type of data that is present in the packet. The current values supported as INT, CHAR, STR
 
 LENGTH - The length of the payload
 
 VALUE  - The actual value of the payload
 
 CHECKSUM - It is running summation of all the fields and it's one's complement
