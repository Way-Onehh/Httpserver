#pragma 

#include "CodeBegin.h"

//需要的容器
#include <string>
#include <map>

//类型声明
#if true


//类型 这里列出了使用到的类型
//字符类型 这里全部都是字符串类型
using __str = std::string;

//http原文
using http=__str;

//行
using HP_url =__str;
using HP_prot=__str;
using HP_method=__str;
using HP_status=__str;
using HP_description=__str;

//正文
using HP_Requestcontent=__str;
using HP_Responsecontent=__str;

//map类型 请求头里的值 用map处理
using __key=__str;
using __val=__str;
using HP_Requesthead =std::map<__key,__val>;
using HP_Responsehead=std::map<__key,__val>;

#endif

struct HP_Request
{
    struct HP_Requestline
    {
        HP_method method;
        HP_url url;
        HP_prot prot;
    };
    HP_Requestline line;
    HP_Requesthead head;
    HP_Requestcontent content; 
};

struct HP_Response
{
    struct HP_Responseline
    {
        HP_prot prot;
        HP_status status;
        HP_description  dscrp;
    };
    HP_Responseline line;
    HP_Responsehead head;
    HP_Responsecontent content;
};

class Http
{
    public:
    static HP_Request decodeReq(http );
    static HP_Response decodeRes(http );
    static http encode(HP_Request  );
    static http encode(HP_Response );
};