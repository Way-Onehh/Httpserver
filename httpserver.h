class httpserver
{
    bool is_run=0;
    httpserver();
    public:
    //单列模式
    static httpserver get();
    //阻塞直到运行完毕，通过is_run检查
    template <class T,class... args>
    void start(T,args&&...);
    //只会给is_run赋0 
    void stop();
};

template <class T, class... args>
inline void httpserver::start(T, args &&...)
{
}
