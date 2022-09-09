#pragma once

#include "basetypes.h"

struct MasterPartitionTableEntry {
	Byte status;	//�״̬ 0=no 0x128=yes
	Byte chs_first;	//��ʼ������
	Byte type;		//����ϵͳ����ָʾ����
	Byte chs_last[3];	//����������
	Dword lba_start;	//�����Ӳ�����ĵ�һ������
	Dword size;			//�����е�������
};

struct MasterBootRecord {
	Byte boot_code[0x1BE];	//���ڴ����������
	MasterPartitionTableEntry partition_table[4];
	Word signatrue;		//����Ϊ0xAA55,	��ʾPC MBR��ʽ
};