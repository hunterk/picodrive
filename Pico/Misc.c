// This is part of Pico Library

// (c) Copyright 2006 notaz, All rights reserved.
// Free for non-commercial use.

// For commercial use, separate licencing terms must be obtained.


#include "PicoInt.h"

// H-counter table for hvcounter reads in 40col mode
// based on Gens code
const unsigned char hcounts_40[] = {
0x07,0x07,0x08,0x08,0x08,0x09,0x09,0x0a,0x0a,0x0b,0x0b,0x0b,0x0c,0x0c,0x0d,0x0d,
0x0e,0x0e,0x0e,0x0f,0x0f,0x10,0x10,0x10,0x11,0x11,0x12,0x12,0x13,0x13,0x13,0x14,
0x14,0x15,0x15,0x15,0x16,0x16,0x17,0x17,0x18,0x18,0x18,0x19,0x19,0x1a,0x1a,0x1b,
0x1b,0x1b,0x1c,0x1c,0x1d,0x1d,0x1d,0x1e,0x1e,0x1f,0x1f,0x20,0x20,0x20,0x21,0x21,
0x22,0x22,0x23,0x23,0x23,0x24,0x24,0x25,0x25,0x25,0x26,0x26,0x27,0x27,0x28,0x28,
0x28,0x29,0x29,0x2a,0x2a,0x2a,0x2b,0x2b,0x2c,0x2c,0x2d,0x2d,0x2d,0x2e,0x2e,0x2f,
0x2f,0x30,0x30,0x30,0x31,0x31,0x32,0x32,0x32,0x33,0x33,0x34,0x34,0x35,0x35,0x35,
0x36,0x36,0x37,0x37,0x38,0x38,0x38,0x39,0x39,0x3a,0x3a,0x3a,0x3b,0x3b,0x3c,0x3c,
0x3d,0x3d,0x3d,0x3e,0x3e,0x3f,0x3f,0x3f,0x40,0x40,0x41,0x41,0x42,0x42,0x42,0x43,
0x43,0x44,0x44,0x45,0x45,0x45,0x46,0x46,0x47,0x47,0x47,0x48,0x48,0x49,0x49,0x4a,
0x4a,0x4a,0x4b,0x4b,0x4c,0x4c,0x4d,0x4d,0x4d,0x4e,0x4e,0x4f,0x4f,0x4f,0x50,0x50,
0x51,0x51,0x52,0x52,0x52,0x53,0x53,0x54,0x54,0x55,0x55,0x55,0x56,0x56,0x57,0x57,
0x57,0x58,0x58,0x59,0x59,0x5a,0x5a,0x5a,0x5b,0x5b,0x5c,0x5c,0x5c,0x5d,0x5d,0x5e,
0x5e,0x5f,0x5f,0x5f,0x60,0x60,0x61,0x61,0x62,0x62,0x62,0x63,0x63,0x64,0x64,0x64,
0x65,0x65,0x66,0x66,0x67,0x67,0x67,0x68,0x68,0x69,0x69,0x6a,0x6a,0x6a,0x6b,0x6b,
0x6c,0x6c,0x6c,0x6d,0x6d,0x6e,0x6e,0x6f,0x6f,0x6f,0x70,0x70,0x71,0x71,0x71,0x72,
0x72,0x73,0x73,0x74,0x74,0x74,0x75,0x75,0x76,0x76,0x77,0x77,0x77,0x78,0x78,0x79,
0x79,0x79,0x7a,0x7a,0x7b,0x7b,0x7c,0x7c,0x7c,0x7d,0x7d,0x7e,0x7e,0x7f,0x7f,0x7f,
0x80,0x80,0x81,0x81,0x81,0x82,0x82,0x83,0x83,0x84,0x84,0x84,0x85,0x85,0x86,0x86,
0x86,0x87,0x87,0x88,0x88,0x89,0x89,0x89,0x8a,0x8a,0x8b,0x8b,0x8c,0x8c,0x8c,0x8d,
0x8d,0x8e,0x8e,0x8e,0x8f,0x8f,0x90,0x90,0x91,0x91,0x91,0x92,0x92,0x93,0x93,0x94,
0x94,0x94,0x95,0x95,0x96,0x96,0x96,0x97,0x97,0x98,0x98,0x99,0x99,0x99,0x9a,0x9a,
0x9b,0x9b,0x9b,0x9c,0x9c,0x9d,0x9d,0x9e,0x9e,0x9e,0x9f,0x9f,0xa0,0xa0,0xa1,0xa1,
0xa1,0xa2,0xa2,0xa3,0xa3,0xa3,0xa4,0xa4,0xa5,0xa5,0xa6,0xa6,0xa6,0xa7,0xa7,0xa8,
0xa8,0xa9,0xa9,0xa9,0xaa,0xaa,0xab,0xab,0xab,0xac,0xac,0xad,0xad,0xae,0xae,0xae,
0xaf,0xaf,0xb0,0xb0,
0xe4,0xe4,0xe4,0xe5,0xe5,0xe6,0xe6,0xe6,0xe7,0xe7,0xe8,0xe8,0xe9,0xe9,0xe9,0xea,
0xea,0xeb,0xeb,0xeb,0xec,0xec,0xed,0xed,0xee,0xee,0xee,0xef,0xef,0xf0,0xf0,0xf1,
0xf1,0xf1,0xf2,0xf2,0xf3,0xf3,0xf3,0xf4,0xf4,0xf5,0xf5,0xf6,0xf6,0xf6,0xf7,0xf7,
0xf8,0xf8,0xf9,0xf9,0xf9,0xfa,0xfa,0xfb,0xfb,0xfb,0xfc,0xfc,0xfd,0xfd,0xfe,0xfe,
0xfe,0xff,0xff,0x00,0x00,0x00,0x01,0x01,0x02,0x02,0x03,0x03,0x03,0x04,0x04,0x05,
0x05,0x06,0x06,0x06,
0x07,0x07,0x08,0x08,0x08,0x09,0x09,0x0a,0x0a,0x0b,0x0b,0x0b,0x0c,0x0c,0x0d,0x0d,
0x0e,0x0e,0x0e,0x0f,0x0f,0x10,0x10,0x10,
};

// H-counter table for hvcounter reads in 32col mode
const unsigned char hcounts_32[] = {
0x05,0x05,0x05,0x06,0x06,0x07,0x07,0x07,0x08,0x08,0x08,0x09,0x09,0x09,0x0a,0x0a,
0x0a,0x0b,0x0b,0x0b,0x0c,0x0c,0x0c,0x0d,0x0d,0x0d,0x0e,0x0e,0x0f,0x0f,0x0f,0x10,
0x10,0x10,0x11,0x11,0x11,0x12,0x12,0x12,0x13,0x13,0x13,0x14,0x14,0x14,0x15,0x15,
0x15,0x16,0x16,0x17,0x17,0x17,0x18,0x18,0x18,0x19,0x19,0x19,0x1a,0x1a,0x1a,0x1b,
0x1b,0x1b,0x1c,0x1c,0x1c,0x1d,0x1d,0x1d,0x1e,0x1e,0x1f,0x1f,0x1f,0x20,0x20,0x20,
0x21,0x21,0x21,0x22,0x22,0x22,0x23,0x23,0x23,0x24,0x24,0x24,0x25,0x25,0x26,0x26,
0x26,0x27,0x27,0x27,0x28,0x28,0x28,0x29,0x29,0x29,0x2a,0x2a,0x2a,0x2b,0x2b,0x2b,
0x2c,0x2c,0x2c,0x2d,0x2d,0x2e,0x2e,0x2e,0x2f,0x2f,0x2f,0x30,0x30,0x30,0x31,0x31,
0x31,0x32,0x32,0x32,0x33,0x33,0x33,0x34,0x34,0x34,0x35,0x35,0x36,0x36,0x36,0x37,
0x37,0x37,0x38,0x38,0x38,0x39,0x39,0x39,0x3a,0x3a,0x3a,0x3b,0x3b,0x3b,0x3c,0x3c,
0x3d,0x3d,0x3d,0x3e,0x3e,0x3e,0x3f,0x3f,0x3f,0x40,0x40,0x40,0x41,0x41,0x41,0x42,
0x42,0x42,0x43,0x43,0x43,0x44,0x44,0x45,0x45,0x45,0x46,0x46,0x46,0x47,0x47,0x47,
0x48,0x48,0x48,0x49,0x49,0x49,0x4a,0x4a,0x4a,0x4b,0x4b,0x4b,0x4c,0x4c,0x4d,0x4d,
0x4d,0x4e,0x4e,0x4e,0x4f,0x4f,0x4f,0x50,0x50,0x50,0x51,0x51,0x51,0x52,0x52,0x52,
0x53,0x53,0x53,0x54,0x54,0x55,0x55,0x55,0x56,0x56,0x56,0x57,0x57,0x57,0x58,0x58,
0x58,0x59,0x59,0x59,0x5a,0x5a,0x5a,0x5b,0x5b,0x5c,0x5c,0x5c,0x5d,0x5d,0x5d,0x5e,
0x5e,0x5e,0x5f,0x5f,0x5f,0x60,0x60,0x60,0x61,0x61,0x61,0x62,0x62,0x62,0x63,0x63,
0x64,0x64,0x64,0x65,0x65,0x65,0x66,0x66,0x66,0x67,0x67,0x67,0x68,0x68,0x68,0x69,
0x69,0x69,0x6a,0x6a,0x6a,0x6b,0x6b,0x6c,0x6c,0x6c,0x6d,0x6d,0x6d,0x6e,0x6e,0x6e,
0x6f,0x6f,0x6f,0x70,0x70,0x70,0x71,0x71,0x71,0x72,0x72,0x72,0x73,0x73,0x74,0x74,
0x74,0x75,0x75,0x75,0x76,0x76,0x76,0x77,0x77,0x77,0x78,0x78,0x78,0x79,0x79,0x79,
0x7a,0x7a,0x7b,0x7b,0x7b,0x7c,0x7c,0x7c,0x7d,0x7d,0x7d,0x7e,0x7e,0x7e,0x7f,0x7f,
0x7f,0x80,0x80,0x80,0x81,0x81,0x81,0x82,0x82,0x83,0x83,0x83,0x84,0x84,0x84,0x85,
0x85,0x85,0x86,0x86,0x86,0x87,0x87,0x87,0x88,0x88,0x88,0x89,0x89,0x89,0x8a,0x8a,
0x8b,0x8b,0x8b,0x8c,0x8c,0x8c,0x8d,0x8d,0x8d,0x8e,0x8e,0x8e,0x8f,0x8f,0x8f,0x90,
0x90,0x90,0x91,0x91,
0xe8,0xe8,0xe8,0xe9,0xe9,0xe9,0xea,0xea,0xea,0xeb,0xeb,0xeb,0xec,0xec,0xec,0xed,
0xed,0xed,0xee,0xee,0xee,0xef,0xef,0xf0,0xf0,0xf0,0xf1,0xf1,0xf1,0xf2,0xf2,0xf2,
0xf3,0xf3,0xf3,0xf4,0xf4,0xf4,0xf5,0xf5,0xf5,0xf6,0xf6,0xf6,0xf7,0xf7,0xf8,0xf8,
0xf8,0xf9,0xf9,0xf9,0xfa,0xfa,0xfa,0xfb,0xfb,0xfb,0xfc,0xfc,0xfc,0xfd,0xfd,0xfd,
0xfe,0xfe,0xfe,0xff,0xff,0x00,0x00,0x00,0x01,0x01,0x01,0x02,0x02,0x02,0x03,0x03,
0x03,0x04,0x04,0x04,
0x05,0x05,0x05,0x06,0x06,0x07,0x07,0x07,0x08,0x08,0x08,0x09,0x09,0x09,0x0a,0x0a,
0x0a,0x0b,0x0b,0x0b,0x0c,0x0c,0x0c,0x0d,
};

// vcounter values for PicoFrameSimple
const unsigned short vcounts[] = {
  0,  0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,
  8,  8,  9,  9, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16,
 16, 17, 17, 18, 18, 19, 19, 20, 21, 21, 22, 22, 23, 23, 24, 24,
 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 31, 31, 32, 32, 33,
 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41,
 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49,
 50, 50, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58,
 58, 59, 59, 60, 60, 61, 62, 62, 63, 63, 64, 64, 65, 65, 66, 66,
 67, 67, 68, 68, 69, 69, 70, 70, 71, 71, 72, 73, 73, 74, 74, 75,
 75, 76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 81, 81, 82, 83, 83,
 84, 84, 85, 85, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91,
 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99,100,
100,101,101,102,102,103,104,104,105,105,106,106,107,107,108,108,
109,109,110,110,111,111,112,112,113,114,114,115,115,116,116,117,
117,118,118,119,119,120,120,121,121,122,122,123,124,124,125,125,
126,126,127,127,128,128,129,129,130,130,131,131,132,132,133,133,
134,135,135,136,136,137,137,138,138,139,139,140,140,141,141,142,
142,143,143,144,145,145,146,146,147,147,148,148,149,149,150,150,
151,151,152,152,153,153,154,155,155,156,156,157,157,158,158,159,
159,160,160,161,161,162,162,163,163,164,164,165,166,166,167,167,
168,168,169,169,170,170,171,171,172,172,173,173,174,174,175,176,
176,177,177,178,178,179,179,180,180,181,181,182,182,183,183,184,
184,185,186,186,187,187,188,188,189,189,190,190,191,191,192,192,
193,193,194,194,195,195,196,197,197,198,198,199,199,200,200,201,
201,202,202,203,203,204,204,205,205,206,207,207,208,208,209,209,
210,210,211,211,212,212,213,213,214,214,215,215,216,217,217,218,
218,219,219,220,220,221,221,222,222,223,223,224,224,225,225,226,
226,227,228,228,229,229,230,230,231,231,232,232,233,233,234,234,
235,235,236,236,237,238,238,239,239,240,240,241,241,242,242,243,
243,244,244,245,245,246,246,247,248,248,249,249,250,250,251,251,
252,252,253,253,254,254,255,255,256,256,257,257,258,259,259,260,
260,261,261,262,262,263,263,264,264,265,265,266,266,267,267,268,
269,269,270,270,271,271,272,272,273,273,274,274,275,275,276,276,
277,277,278,279,279,280,280,281,281,282,282,283,283,284,284,285,
285,286,286,287,287,288,288,289,290,290,291,291,292,292,293,293,
294,294,295,295,296,296,297,297,298,298,299,300,300,301,301,302,
302,303,303,304,304,305,305,306,306,307,307,308,308,309,310,310,
311,311,311,311,
};


// rarely used EEPROM SRAM code
// known games which use this:
// Wonder Boy in Monster World, Megaman - The Wily Wars (X24C01, 128 bytes)
// NFL Quarterback Club*, Frank Thomas Big Hurt Baseball (X24C04?)
// College Slam, Blockbuster World Video Game Championship II, NBA Jam (X24C04?)
// HardBall '95

// the above sports games use addr 0x200000 for SCL line (handled in Memory.c)

unsigned int lastSSRamWrite = 0xffff0000;

// sram_reg: LAtd sela (L=pending SCL, A=pending SDA, t=type(1==uses 0x200000 for SCL and 2K bytes),
//                      d=SRAM was detected (header or by access), s=started, e=save is EEPROM, l=old SCL, a=old SDA)
PICO_INTERNAL void SRAMWriteEEPROM(unsigned int d) // ???? ??la (l=SCL, a=SDA)
{
  unsigned int sreg = Pico.m.sram_reg, saddr = Pico.m.sram_addr, scyc = Pico.m.sram_cycle, ssa = Pico.m.sram_slave;

  //printf("EEPROM write %i\n", d&3);
  sreg |= saddr&0xc000; // we store word count in add reg: dw?a aaaa ...  (d=word count detected, w=words(0==use 2 words, else 1))
  saddr&=0x1fff;

  if(sreg & d & 2) {
    // SCL was and is still high..
    if((sreg & 1) && !(d&1)) {
      // ..and SDA went low, means it's a start command, so clear internal addr reg and clock counter
      //dprintf("-start-");
      if(!(sreg&0x8000) && scyc >= 9) {
        if(scyc != 28) sreg |= 0x4000; // 1 word
        //dprintf("detected word count: %i", scyc==28 ? 2 : 1);
        sreg |= 0x8000;
      }
      //saddr = 0;
      scyc = 0;
      sreg |= 8;
    } else if(!(sreg & 1) && (d&1)) {
      // SDA went high == stop command
      //dprintf("-stop-");
      sreg &= ~8;
    }
  }
  else if((sreg & 8) && !(sreg & 2) && (d&2)) {
    // we are started and SCL went high - next cycle
    scyc++; // pre-increment
    if(sreg & 0x20) {
      // X24C02+
      if((ssa&1) && scyc == 18) {
        scyc = 9;
        saddr++; // next address in read mode
        if(sreg&0x4000) saddr&=0xff; else saddr&=0x1fff; // mask
      }
      else if((sreg&0x4000) && scyc == 27) scyc = 18;
      else if(scyc == 36) scyc = 27;
    } else {
      // X24C01
      if(scyc == 18) {
        scyc = 9;  // wrap
        if(saddr&1) { saddr+=2; saddr&=0xff; } // next addr in read mode
      }
    }
    //dprintf("scyc: %i", scyc);
  }
  else if((sreg & 8) && (sreg & 2) && !(d&2)) {
    // we are started and SCL went low (falling edge)
    if(sreg & 0x20) {
      // X24C02+
      if(scyc == 9 || scyc == 18 || scyc == 27); // ACK cycles
      else if( (!(sreg&0x4000) && scyc > 27) || ((sreg&0x4000) && scyc > 18) ) {
        if(!(ssa&1)) {
          // data write
          unsigned char *pm=SRam.data+saddr;
          *pm <<= 1; *pm |= d&1;
          if(scyc == 26 || scyc == 35) {
            saddr=(saddr&~0xf)|((saddr+1)&0xf); // only 4 (?) lowest bits are incremented
            //dprintf("w done: %02x; addr inc: %x", *pm, saddr);
          }
          SRam.changed = 1;
        }
      } else if(scyc > 9) {
        if(!(ssa&1)) {
          // we latch another addr bit
          saddr<<=1;
          if(sreg&0x4000) saddr&=0xff; else saddr&=0x1fff; // mask
          saddr|=d&1;
          //if(scyc==17||scyc==26) dprintf("addr reg done: %x", saddr);
        }
      } else {
        // slave address
        ssa<<=1; ssa|=d&1;
        //if(scyc==8) dprintf("slave done: %x", ssa);
      }
    } else {
      // X24C01
      if(scyc == 9); // ACK cycle, do nothing
      else if(scyc > 9) {
        if(!(saddr&1)) {
          // data write
          unsigned char *pm=SRam.data+(saddr>>1);
          *pm <<= 1; *pm |= d&1;
          if(scyc == 17) {
            saddr=(saddr&0xf9)|((saddr+2)&6); // only 2 lowest bits are incremented
            //dprintf("addr inc: %x", saddr>>1);
          }
          SRam.changed = 1;
        }
      } else {
        // we latch another addr bit
        saddr<<=1; saddr|=d&1; saddr&=0xff;
        //if(scyc==8) dprintf("addr done: %x", saddr>>1);
      }
    }
  }

  sreg &= ~3; sreg |= d&3; // remember SCL and SDA
  Pico.m.sram_reg  = (unsigned char)  sreg;
  Pico.m.sram_addr = (unsigned short)(saddr|(sreg&0xc000));
  Pico.m.sram_cycle= (unsigned char)  scyc;
  Pico.m.sram_slave= (unsigned char)  ssa;
}

PICO_INTERNAL_ASM unsigned int SRAMReadEEPROM(void)
{
  unsigned int shift, d=0;
  unsigned int sreg, saddr, scyc, ssa;

  // flush last pending write
  SRAMWriteEEPROM(Pico.m.sram_reg>>6);

  sreg = Pico.m.sram_reg; saddr = Pico.m.sram_addr&0x1fff; scyc = Pico.m.sram_cycle; ssa = Pico.m.sram_slave;
//  if(!(sreg & 2) && (sreg&0x80)) scyc++; // take care of raising edge now to compensate lag

  if(SekCyclesDoneT()-lastSSRamWrite < 46) {
    // data was just written, there was no time to respond (used by sports games)
    d = (sreg>>6)&1;
  } else if((sreg & 8) && scyc > 9 && scyc != 18 && scyc != 27) {
    // started and first command word received
    shift = 17-scyc;
    if(sreg & 0x20) {
      // X24C02+
      if(ssa&1) {
        //dprintf("read: addr %02x, cycle %i, reg %02x", saddr, scyc, sreg);
        d = (SRam.data[saddr]>>shift)&1;
      }
    } else {
      // X24C01
      if(saddr&1) {
        d = (SRam.data[saddr>>1]>>shift)&1;
      }
    }
  }
  //else dprintf("r ack");

  return d;
}

PICO_INTERNAL void SRAMUpdPending(unsigned int a, unsigned int d)
{
  unsigned int sreg = Pico.m.sram_reg;

  if(!(a&1)) sreg|=0x20;

  if(sreg&0x20) { // address through 0x200000
    if(!(a&1)) {
      sreg&=~0x80;
      sreg|=d<<7;
    } else {
      sreg&=~0x40;
      sreg|=(d<<6)&0x40;
    }
  } else {
    sreg&=~0xc0;
    sreg|=d<<6;
  }

  Pico.m.sram_reg = (unsigned char) sreg;
}


#ifndef _ASM_MISC_C
PICO_INTERNAL_ASM void memcpy16(unsigned short *dest, unsigned short *src, int count)
{
	while (count--)
		*dest++ = *src++;
}


PICO_INTERNAL_ASM void memcpy16bswap(unsigned short *dest, void *src, int count)
{
	unsigned char *src_ = src;

	for (; count; count--, src_ += 2)
		*dest++ = (src_[0] << 8) | src_[1];
}


PICO_INTERNAL_ASM void memcpy32(int *dest, int *src, int count)
{
	while (count--)
		*dest++ = *src++;
}


PICO_INTERNAL_ASM void memset32(int *dest, int c, int count)
{
	while (count--)
		*dest++ = c;
}
#endif

