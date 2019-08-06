#pragma once
//date: 2019/8/6

#pragma pack(1)

//数据类型
typedef enum _FieldType{   
    ft_null = 0,
    ft_string,
    ft_int,
    ft_float,
    ft_time,
}FieldType;

//字段单元
typedef struct _FieldElement{
    char Name[100];             //字段名称
    char value[255];            //值
    FieldType ft;               //类型
    bool bIndex;                //索引标志
}FiledElement;

#pragma pack()


/*
//删除指定的数据库中的某张表
bool RA_RemoveTabel(LPCSTR lpFile,LPCSTR lptable);

//修改表名
bool RA_ChangeTableName(LPCSTR lpFile,LPCSTR lpOldtable,LPCSTR lpNewtalb);

bool RA_

*/