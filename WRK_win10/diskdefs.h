#pragma once

#include "basetypes.h"

struct MasterPartitionTableEntry {
	Byte status;	//活动状态 0=no 0x128=yes
	Byte chs_first;	//起始扇区号
	Byte type;		//操作系统类型指示代码
	Byte chs_last[3];	//结束扇区号
	Dword lba_start;	//相对于硬盘起点的第一个扇区
	Dword size;			//分区中的扇区数
};

struct MasterBootRecord {
	Byte boot_code[0x1BE];	//用于存放引导代码
	MasterPartitionTableEntry partition_table[4];
	Word signatrue;		//设置为0xAA55,	表示PC MBR格式
};