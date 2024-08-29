#include <sstream>

#include <vector>
#include <string.h>
#include "../http.h"

//每行要回车换行但是linux \n就是回车换行 
HP_Request Http::decodeReq(http _hp)
{
    std::stringstream ss(_hp);
    HP_Request result;
    std::vector<std::string> Spair;
    ss>>result.line.method;
    ss>>result.line.url;
    ss>>result.line.prot;

    char buf[1024];
    bzero(buf,1024);
    ss.getline(buf,1024);
    while (ss.getline(buf,1024))
    {
        std::string temp(buf);
    //提取键与值
        auto it =temp.find(':');
        if(it==std::string::npos) break;   
        //利用格式流去掉多余的空格
        std::string temp1(temp.substr(0,it));    
        std::stringstream ss1(temp1);
        std::string temp2;
        ss1>>temp2;

        std::string temp3(temp.substr(it+1));    
        std::stringstream ss2(temp1);
        std::string temp4;
        ss2>>temp4;
        result.head.insert_or_assign(temp2 ,temp4);
    }
    ss.getline(buf,1024);
    result.content=buf;
    return result;
}

//每行要回车换行但是linux \n就是回车换行 
HP_Response Http::decodeRes(http _hp)
{
    std::stringstream ss(_hp);
    HP_Response result;
    std::vector<std::string> Spair;
    ss>>result.line.prot;
    ss>>result.line.status;
    ss>>result.line.dscrp;

    char buf[1024];
    bzero(buf,1024);
    ss.getline(buf,1024);
    while (ss.getline(buf,1024))
    {
        std::string temp(buf);
    //提取键与值
        auto it =temp.find(':');
        if(it==std::string::npos) break;
        //利用格式流去掉多余的空格
        std::string temp1(temp.substr(0,it));    
        std::stringstream ss1(temp1);
        std::string temp2;
        ss1>>temp2;

        std::string temp3(temp.substr(it+1));    
        std::stringstream ss2(temp1);
        std::string temp4;
        ss2>>temp4;
        
        result.head.insert_or_assign(temp2 ,temp4);
    }
    ss.getline(buf,1024);
    result.content=buf;
    return result;
}


http Http::encode(HP_Request _HR)
{
    http Result;
    Result.append(_HR.line.method);
    Result.push_back(' ');
    Result.append(_HR.line.url);
    Result.push_back(' ');
    Result.append(_HR.line.prot);
    Result.push_back('\n');
    for(auto pair : _HR.head)
    {
        Result.append(pair.first);
        Result.push_back(':');
        Result.append(pair.second);
        Result.push_back('\n');
    }
    Result.push_back('\n');
    Result.append(_HR.content);
    return Result;
}

http Http::encode(HP_Response _HS)
{   
    http Result;
    Result.append(_HS.line.prot);
    Result.push_back(' ');
    Result.append(_HS.line.status);
    Result.push_back(' ');
    Result.append(_HS.line.dscrp);
    Result.push_back('\n');
    for(auto pair : _HS.head)
    {
        Result.append(pair.first);
        Result.push_back(':');
        Result.append(pair.second);
        Result.push_back('\n');
    }
    Result.push_back('\n');
    Result.append(_HS.content);
    return Result;
}
