#pragma once
//date: 2019/8/6

#include <string>
#include <vector>
using namespace std;

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
    char Name[255];             //字段名称
    FieldType ft;               //类型
    bool bIndex;                //索引标志
}FiledElement,*LPFiledElement;

typedef vector<string> vstring;



#pragma pack()


/*
//删除指定的数据库中的某张表
bool RA_RemoveTabel(
LPCSTR lpFile,          //lpFile: 文件名
LPCSTR lptable);        //lptable; 表名

//修改表名
bool RA_ChangeTableName(
LPCSTR lpFile,      //lpFile: 文件名
LPCSTR lpOldtable,  //lpOldtable: 旧的表名
LPCSTR lpNewtalb    //lpNewtalb: 新的表名
);


//从数据库文件中获取表的名单
VOID RA_GetNumberOfTableFromFile(
LPCSTR lpFile,    //lpFile: 文件名
vstring& vs       //vs: 当前数据库中所有的表名
);

//读取表的字段
//返回值：返回 lpte 数目
int RA_GetDataFieldFromTabel(
LPCSTR lpFile,                      //lpFile: 文件名
LPCSTR lptable,                     //lptable; 表名
__In__Out LPFiledElement lpte       //lpte: 外部传入数据指针,由内部开辟空间，外部释放
);


//读取表的内容
//返回值：返回读取到数目行
int RA_GetDataInforFromTabel(
LPCSTR lpFile,              //lpFile: 文件名
LPCSTR lptable,             //lptable; 表名
__In__Out vstring* lpvs,    //lpvs: 外部传入数据指针,第一列的数据存在 lpvs[0]， 以此类推
int count,                  //count: 字段数目
int maxcount = 1000         //maxcount：当前获取的最大的数目
);
*/